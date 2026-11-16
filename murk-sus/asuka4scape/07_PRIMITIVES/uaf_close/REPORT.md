# free() против in-flight externalMethod — 27.2 (24B115)

Вопрос: держит ли mach-trap (`io_connect_method`) ссылку на user client, пока выполняется
`externalMethod`? Если нет — `IOServiceClose` из другого потока освобождает объект под работающим
вызовом, и это UAF с контролем данных.

**Ответ: держит, дважды.** (1) MIG-обёртка делает `lookup_connect_ref` = retain и отпускает
объект только после возврата воркера. (2) Ядро ведёт счётчик in-flight вызовов `uc+0x9c` и при
последнем выходе откладывает финализацию через `scheduleFinalize`. `free()` — деструктор
(`release` при rc=0), под живым trap-ref он не выполняется ни для одного из трёх классов.

---

## 1. Итог по классам

| класс | trap-ref на время вызова | `isInactive`/`fTerminating` в `externalMethod` | что рвётся при close | вердикт |
|---|---|---|---|---|
| `IOSurfaceRootUserClient` | да (`0xa34bbcc` +1, `0xa34eef4` release) | нет (только выбор таблицы по `uc+0x127`) | ничего: `clientClose 0x9c3ab48` = 3 инструкции, `free 0x9c3a678` — деструктор | **безопасно (trap держит ref)** |
| `IOMobileFramebufferUserClient` | да | нет (только `fb->vt[0x5c0]` pre-gate) | `stop 0x9aa17b8`: дренаж `+0xfc`, `removeUserClient`, release 12 записей `uc+0x110` | **объект жив, но гонка по членам возможна — нужен порядок двух потоков** |
| `IOGPUDeviceUserClient` | да | да: `uc+0x100` bit0 → `0xe00002d8` | не разобрано | **объект безопасен; member-гонка не подтверждена** |

---

## 2. Слой 1 — MIG держит +1 на весь вызов

### 2.1 `iokit_lookup_connect_ref` = `0xfffffff00a34bbcc`

Порт из сообщения → kobject `[port+0x50]` (autda key `0x7d`) → виртуальный retain
(vtable `+0x20`, `OSObject::retain`):

```
fffffff00a34bc0c: mov  x17, x20
fffffff00a34bc10: ldr  x16, [x17, #0x50]!      ; ipc_port->kobject
fffffff00a34bc14: movk x17, #0x7d, lsl #48
fffffff00a34bc18: autda x16, x17
fffffff00a34bc20: mov  x19, x16
fffffff00a34bc24: ldr  x16, [x16]
fffffff00a34bc2c: movk x17, #0xcda1, lsl #48
fffffff00a34bc30: autda x16, x17
fffffff00a34bc34: ldr  x8, [x16, #0x20]!       ; vtable+0x20 = retain
fffffff00a34bc38: mov  x0, x19
fffffff00a34bc40: blraa x8, x16
```

### 2.2 `_Xio_connect_method` = `0xfffffff00a34ed50` (MIG num 2865)

```
fffffff00a34ee5c: ldr  x0, [x0, #8]            ; ipc_port из тела сообщения
fffffff00a34ee68: bl   0xa34bbcc               ; lookup_connect_ref → +1
fffffff00a34ee6c: mov  x19, x0
...
fffffff00a34eed8: bl   0xa9ae990               ; is_io_connect_method: весь вызов
fffffff00a34eedc: stur w0, [x24, #-4]          ; kr в reply
fffffff00a34eee0: cbz  x19, 0xa34ef08
fffffff00a34eee4: ldr  x16, [x19]
fffffff00a34eeec: movk x17, #0xcda1, lsl #48
fffffff00a34eef4: ldr  x9, [x16, #0x28]!       ; vtable+0x28 = release, ПОСЛЕ воркера
fffffff00a34eef8: mov  x0, x19
fffffff00a34ef00: blraa x9, x16
```

Между `0xa34ee68` и `0xa34eef4` других release нет: +1 живёт ровно на время `externalMethod`.

То же в остальных входах:

| вход | lookup | release |
|---|---|---|
| `io_connect_method` `0xa34ed50` | `0xa34ee68` | `0xa34eef4` |
| `io_connect_method_var_output` `0xa34dff8` | `0xa34e128` | `0xa34e19c`-ветка / `0xa34e1dc` |
| `io_connect_async_method` `0xa34ea58` | `0xa34ebd8` | `0xa34ec9c`–`0xa34ecb8` (сразу после воркера) |
| `io_service_close` `0xa352d64` | `0xa352d94` | `0xa352da8`–`0xa352dc4` |

Важно для async: ref снимается сразу после `bl 0xa9aed20` (`0xa34ec9c ldr x16,[x19]`),
то есть на время самой асинхронной доставки trap-ref **не** держится — кто живёт дольше,
тот обязан брать свой retain.

### 2.3 `io_service_close` = `0xfffffff00a352d64`

```
fffffff00a352d90: ldr  x0, [x0, #8]
fffffff00a352d94: bl   0xa34bbcc              ; +1
fffffff00a352d9c: bl   0xa9ad368              ; is_io_service_close
fffffff00a352da8: ldr  x16, [x20]
fffffff00a352db8: ldr  x8, [x16, #0x28]!      ; release
fffffff00a352dc4: blraa x8, x16
```

---

## 3. Слой 2 — счётчик in-flight и отложенный finalize

### 3.1 Обёртка `externalMethod` = `0xfffffff00a9ae888`

Вызывается из `is_io_connect_method 0xa9ae990` (`0xa9aebfc`, `0xa9aefac`).
Берёт лок `uc+0xb0` (если класс включил `IOUserClientDefaultLocking`, флаги `uc+0x9b` биты 2/3),
всегда инкрементит счётчик и вызывает классовый `externalMethod` через vtable:

```
fffffff00a9ae8f8: add   x8, x19, #0x9c
fffffff00a9ae8fc: ldadd w20, w8, [x8]          ; ++in-flight (w20=1), безусловно
fffffff00a9ae914: tbnz  w8, #1, 0xa9ae940      ; бит1 uc+0x9b → слот +0x5d0
fffffff00a9ae918: ldr   x9, [x16, #0x540]      ; иначе +0x540
fffffff00a9ae938: blraa x9, x16                ; externalMethod(sel,args,0,0,0)
fffffff00a9ae978: bl    0xa9a5808              ; unlock + gate
```

### 3.2 Выход = `0xfffffff00a9a5808`

```
fffffff00a9a5824: add   x8, x0, #0x9c
fffffff00a9a582c: ldadd w9, w8, [x8]           ; w9=-1; w8 = old
fffffff00a9a5830: cmp   w8, #1
fffffff00a9a5834: b.ne  0xa9a58f8              ; не последний → только unlock
fffffff00a9a5848: ldr   x8, [x16, #0x298]      ; «пора финализировать?»
fffffff00a9a585c: blraa x8, x16
fffffff00a9a5860: tbz   w0, #0, 0xa9a58f8
fffffff00a9a5888: ldrb  w9, [x20, #0x9a]       ; terminate-pending
fffffff00a9a5890: strb  wzr, [x20, #0x9a]
fffffff00a9a58b0: mov   x0, x20
fffffff00a9a58b4: mov   w1, #1
fffffff00a9a58b8: bl    0xa9172f8              ; scheduleFinalize
```

`0xfffffff00a9172f8` — `scheduleFinalize` (строка `"%s[0x%qx]::scheduleFinalize\n"` @ `0xa917380`).
То есть последний выходящий вызов не освобождает объект, а **планирует** финализацию.

### 3.3 Close = `0xfffffff00a9ad368`

```
fffffff00a9ad3e4: adrp x8, #0xfffffff00ad98000 ; safeMetaCast(uc, IOUserClient)
fffffff00a9ad3f0: b.eq 0xa9ad400
fffffff00a9ad400: ldrb  w8, [x19, #0x98]
fffffff00a9ad410: casalb w8, w10, [x9]          ; [uc+0x99]: 0→1, одноразово
fffffff00a9ad414: cbnz  w8, 0xa9ad474           ; уже закрыт → "ignored is_io_service_close" (0x70b57f9)
fffffff00a9ad41c: bl    0xa227a00               ; lck_mtx_lock(uc+0xb0)
fffffff00a9ad428: ldadd w9, w8, [x8]            ; ++in-flight
fffffff00a9ad43c: ldr   x8, [x16, #0x560]       ; clientClose
fffffff00a9ad448: blraa x8, x16
fffffff00a9ad454: bl    0xa9a5808               ; unlock+gate, mode 2
```

Close **не** освобождает объект: он берёт тот же лок и тот же счётчик, ставит флаг «закрыт»
и вызывает `clientClose`. Двойной close отсекается CAS-ом и пишет лог.

---

## 4. По классам

### 4.1 `IOSurfaceRootUserClient`

* `externalMethod` = `0xfffffff009c3ee10` (vtable `0x8068520` + `0x5d0`):

```
fffffff009c3ee10: bti   c
fffffff009c3ee14: adrp  x8, #0xfffffff008068000
fffffff009c3ee18: add   x8, x8, #0xb90        ; таблица 0x8068b90, 60 записей
fffffff009c3ee1c: ldrb  w9, [x0, #0x127]      ; выбор таблицы, НЕ isInactive
fffffff009c3ee2c: csel  x3, x10, x8, ne
fffffff009c3ee30: mov   w4, #0x3c
fffffff009c3ee38: mov   x6, #0
fffffff009c3ee3c: b     0x9c498f4            ; общий диспетчер
```

  Ни проверки inactive, ни лока. Но:
* `free` = `0x9c3a678` (vtable + `0x70`). Прямых `bl`/`b` на него нет ни одного во всём
  `__TEXT_EXEC` (скан 10.7 млн инструкций, обе кодировки) → только из `OSObject::release` при rc=0.
* `clientClose` = `0x9c3ab48` — три инструкции: `vt[0x2f0](this, 0)`, `return 0`.
  Членов не рвёт.

**Вердикт: безопасно.** Под работающим `externalMethod` rc ≥ 1 (trap-ref), `free` не достижим;
close не освобождает ни таблицу `[uc+0x108]`, ни лок `[uc+0xd8]`. Гипотеза «free гоняется с
in-flight вызовом» для этого класса **опровергнута**.

### 4.2 `IOMobileFramebufferUserClient`

* `externalMethod` = `0xfffffff009aa33b8`:

```
fffffff009aa33d0: mov  x20, x2                ; args
fffffff009aa33d4: mov  x21, x1                ; selector
fffffff009aa33dc: ldr  x0, [x0, #0xd8]        ; fb
fffffff009aa33f0: mov  x17, #0x5c0
fffffff009aa33f8: ldr  x8, [x16]
fffffff009aa3400: blraa x8, x16               ; fb->vt[0x5c0] pre-gate
fffffff009aa3404: cbz  w0, 0xa9aa3418
fffffff009aa3418: adrp x3, #0xfffffff008023000
fffffff009aa341c: add  x3, x3, #0xad0         ; таблица 0x8023ad0, 0x65 записей
fffffff009aa3444: ... b 0x9abd40c             ; GOT-трамплин → 0xa9b0888
```

  `uc+0xe0` не читается, `isInactive` не проверяется, лок не берётся.
* `stop` = `0x9aa17b8` (vtable + `0x390`), прямых `bl`/`b` нет → только из terminate:

```
fffffff009aa17e4: ldrb w8, [x0, #0xe0]
fffffff009aa17e8: tbz  w8, #0, 0xa9aa19b8     ; выключен — выходим
fffffff009aa17f0: bl   0x9abd1fc              ; dec/read [uc+0xfc]
fffffff009aa17f8: b.lt 0xa9aa1844
fffffff009aa1830: blraa x8, x16               ; fb->vt[0x780](fb,0xb,&zero,1)
...
                : fb->vt[0x620](fb,uc)        ; removeUserClient
                : release 12 записей uc+0x110
```

**Вердикт: объект не освобождается (trap-ref), но `stop` рвёт члены синхронно на close-потоке,
пока другой поток сидит в `externalMethod`.** Это гонка member-UAF, не free объекта.
Порядок двух потоков нужен: `inc +0xfc` и `fb->vt[0x780]` могут пройти после дренажа.

### 4.3 `IOGPUDeviceUserClient`

* `externalMethod` = `0xfffffff00994a1e0`:

```
fffffff00994a1e8: ldrb  w9, [x0, #0x100]
fffffff00994a1ec: tbz   w9, #0, 0x994a26c     ; флаг снят → 0xe00002d8
fffffff00994a1f0: cmp   w1, #0x37             ; selector < 56
fffffff00994a1f8: ldr   x9, [x2, #0x10]       ; structureInputDescriptor == NULL
fffffff00994a20c: adrp  x10, #0xfffffff007fea000
fffffff00994a210: add   x10, x10, #0x740      ; таблица 0x7fea740
fffffff00994a250: ... vt[0x550] → общий диспетчер
```

  Проверка `uc+0x100` bit0 сужает окно, но не сериализует с close.

**Вердикт: объект безопасен (trap-ref). Member-гонка не подтверждена** — `free`/`stop` этого
класса в этой сессии не разобраны.

---

## 5. Что это меняет для UAF-гипотезы

1. «`IOServiceClose` освобождает uc под работающим `externalMethod`» — **неверно** для всех трёх:
   +1 от trap не даёт rc дойти до нуля, а `free` — деструктор.
2. Ядро дополнительно страхует: счётчик `uc+0x9c` + `scheduleFinalize` при последнем выходе.
   Штатный путь teardown откладывается до дренажа in-flight.
3. Реальная дыра — не `free`, а `stop()`: он исполняется на close-потоке и не ждёт in-flight.
   Для MFB это подтверждено структурно (дренаж и 12 записей `uc+0x110`).
4. Чтобы получить контроль данных, нужен не double-close, а окно
   `stop` (free members) ↔ handler на освобождённом member. Для SURF такого окна нет:
   close вообще не трогает члены.

---

## 6. Не подтверждено

* Значения флагов `uc+0x9b` (locking mode) в рантайме: Info.plist вычищен из kernelcache,
  `IOUserClientDefaultLocking` есть только как строка кода (`0x70b5680`), не как plist.
  Если класс opt-in — close и externalMethod сериализуются локом `uc+0xb0`, и гонка MFB
  закрывается. Это надо снимать с живой машины.
* Точный слот vtable, через который MIG зовёт `externalMethod` у MFB: обработчик лежит по
  `0x8023300+0x6a8`, а обёртка `0xa9ae888` использует `+0x540`/`+0x5d0`. Расхождение
  объясняется двухуровневой схемой `IOUserClient` / `IOUserClient2022`
  (строка `"externalMethod for IOUserClient2022 @%s:%d"` @ `0x70b5b19`), но точная привязка
  статически не доказана.
* `0xfffffff00a94affc` (слот `+0x560` у MFB, он же base-`clientClose`) отнесён к семейству
  `IOService::terminate` по строкам `%s: %s(%s) on PM thread`, `waitForPMDriverCall`;
  прямой вызов `stop` из него не прослежен.
* Семантика `uc+0x100` у GPU (кто и когда снимает бит).
* Динамики нет: KASAN/два потока не гонялись.

## 7. Артефакты

`kc.py` — хелпер (flat `fileoff = va-0x7004000`, capstone 5.0.7, маска знаковых imm).
Скрипты сканов: `blscan` (все `bl` по `__TEXT_EXEC`), `scan vtable`, `strrefs`.
