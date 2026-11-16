# MIG reply-буфер и zeroing — проверка по бинарю (27.2 / 24B115)

**Бинарь:** `/home/femboychik/Рабочий стол/дипсик 1/kc/27.2_24B115_kernelcache`
**База:** `0xfffffff007004000`, offset = `va - base` (плоская раскладка; `__TEXT_EXEC` off = `va-base`, `__DATA_CONST` = `0xbb4000 + (va - 0xfffffff007bb8000)`)
**Скрипты:** `verify_zero/macho.py`, `kdis.py`, `ldis.py`, `scan_ref.py` (ADRP imm маскируется `& 0xFFFFFFFFFFFFFFFF`)

---

## Вердикт

**Zeroing reply-буфера подтверждён по бинарю** — не ссылкой на исходники, а инструкциями:

1. `ipc_kobject_server` (`0xfffffff00a21722c`) вызывает `ipc_kmsg_alloc` **до** вызова серверного метода
   (`bl 0xfffffff00a1e6b4c` @`0xa2174f4`, серверный routine — `blraa x8` @`0xa217908`), с флагами
   `w3 = 0xB = IPC_KMSG_ALLOC_KERNEL(0x1) | IPC_KMSG_ALLOC_ZERO(0x2) | IPC_KMSG_ALLOC_NOFAIL(0x8)`.
2. Внутри `ipc_kmsg_alloc` (`0xfffffff00a1e6b4c`) бит ZERO транслируется в `Z_ZERO = 0x4`
   (`lsr w8,w3,#1` + `bfi w21,w8,#2,#1` @`0xa1e6c70..0xa1e6c7c`) и передаётся **и** в аллокацию payload
   (`bl 0xfffffff00a220c30` @`0xa1e6ca0`), **и** в аллокацию kdata (@`0xa1e6d10`); сам `ipc_kmsg`
   берётся из зоны с `0x8004 = Z_ZERO|Z_NOFAIL` (@`0xa1e6d30`).
3. Контрольная сверка констант: обёртка `ipc_kmsg_alloc_uext_reply` в бинаре передаёт `w3 = 0x1B`
   (@`0xa1e6e48`) = KERNEL|ZERO|NOFAIL|LINEAR — ровно как в исходнике xnu. Раскладка флагов верна.

`inband_output` (то, куда пишет IOSurface-обработчик через `args->structureOutput +0x58`) лежит внутри
этого самого payload-буфера (`ikm_udata`) → незаполненные байты = нули.

**OOL не обходит zeroing:** при `io_connect_method` `args->structureOutput` **всегда** указывает на
inband reply-буфер, даже если передан `structureOutputDescriptor` (`+0x68`) — дескриптор живёт отдельным
полем и оборачивает user-VA вызывающего (`IOMemoryDescriptor::withAddressRange(..., current_task())`).
IOSurface sel 28 `0x9c3d838` и sel 34 `0x9c3b7b0` поле `+0x68` не читают вообще (обёртки забирают только
`+0x58`/`+0x60`), поэтому писать в OOL-буфер они не могут.

**Итог: infoleak нет.** Уровень — «нет утечки через sel 28/34/13»; дыры (28 / 3164 / 5 байт) закрыты
zeroing'ом на уровне MIG/kmsg, а не логикой IOSurface. OOL-путь утечку не создаёт и не расширяет.

**Не подтверждено:** конкретная инструкция `memset`/`bzero` внутри generic-аллокатора (`Z_ZERO → KMA_ZERO`)
не локализована; последний шаг опирается на контракт `Z_ZERO` («returned memory has been zeroed out»)
и на совпадение всех констант. Динамическая проверка (sel 28: байты `0x84..0x9F` == 0) не проводилась.

---

## 1. Якоря

| что | как найден | VA |
|---|---|---|
| `ipc_kobject_server` | паника `"ipc_kobject_server: strange destination rights"` (строка `0xfffffff007046133`) → `adrp/add` @`0xa217ad0/0xa217ad4`, cold-блок той же функции | `0xfffffff00a21722c` |
| `ipc_kmsg_alloc` | паники `"size too large for the fast kmsg zone"` (`0x7043fd5` → `0xa1e6e18`) и `"non-zero aux size for kmsg type IKM_TYPE_KDATA_OOL"` (`0x7044012` → `0xa1e6e34`) — обе в хвосте функции | `0xfffffff00a1e6b4c` |
| `is_io_connect_method` (MIG 2865) | `mig_kern_subsystem` миграция: `_Xio_connect_method num=2865` @`0xa34ed50` (код, `pacibsp`) | `0xfffffff00a34ed50` |
| подготовка `IOExternalMethodArguments` | вызов из MIG-рутины | `0xfffffff00a9ae990` |
| `IOUserClient2022::dispatchExternalMethod` | auth-стаб `0x9c498f4` → GOT `0x806c6e0` → PAC-strip | `0xfffffff00a9b0888` |
| sel 28 wrapper / core | таблица A entry `0x8068ff0` | `0x9c39660` → `0x9c3d838` |
| sel 34 wrapper / core | таблица A | `0x9c397d8` → `0x9c3b7b0` |

`ipc_kobject_server_internal` в этой сборке **инлайнен** в `ipc_kobject_server`: в одной функции лежат
и hash-lookup `mig_buckets` (магия `MAX_MIG_ENTRIES = 1031`), и `ipc_kmsg_alloc`, и `blraa` kroutine,
и `panic("ipc_kobject_server: strange destination rights")` (`0xa217ad4`).

---

## 2. Дизасм: выделение → вызов серверного метода

```
; ipc_kobject_server, 0xfffffff00a21722c (pacibsp @0xa21722c)
; —— найден mig_hash entry: x24 = &mig_buckets[…], x8 = kroutine ——
0xa2174e0  ldp   w0, w25, [x24, #0x10]   ; w0 = kreply_size, w25 = kreply_desc_cnt
0xa2174e4  str   w0, [sp, #0x1c]
0xa2174e8  mov   w1, #0                  ; qos = 0
0xa2174ec  mov   x2, x25                 ; desc_count
0xa2174f0  mov   w3, #0xb                ; KERNEL|ZERO|NOFAIL
0xa2174f4  bl    0xfffffff00a1e6b4c     ; ipc_kmsg_alloc(size, 0, descs, flags)
0xa2174f8  mov   x21, x0                 ; reply
...
; —— MACF-фильтр, затем вызов kroutine; reply уже выделен и обнулён ——
0xa2178ec  ldr   x8, [x24, #8]           ; kroutine
0xa2178f0  mov   x0, x22                 ; req_hdr
0xa2178f4  mov   x1, x26                 ; req_data
0xa2178f8  mov   x2, x27                 ; req_trailer
0xa2178fc  ldr   x3, [sp, #0x20]         ; reply_hdr
0xa217900  mov   x4, x25                 ; reply_data (ikm_udata == inband_output)
0xa217904  mov   x17, #0x3a83
0xa217908  blraa x8, x17                ; (*kroutine)(...)
```

Порядок однозначен: `bl ipc_kmsg_alloc` @`0xa2174f4` < `blraa` @`0xa217908`.
Cold-блок паники (та же функция):

```
0xa217ac0  adrp  x8, #0x7046000
0xa217ac4  add   x8, x8, #0x62           ; "ipc_kobject.c"
0xa217ac8  mov   w9, #0x2bb              ; __LINE__
0xa217acc  stp   x8, x9, [sp]
0xa217ad0  adrp  x0, #0x7046000
0xa217ad4  add   x0, x0, #0x133          ; "ipc_kobject_server: strange destination rights"
0xa217ad8  bl    0xfffffff00aa4d114      ; panic
```

---

## 3. Дизасм: трансляция флагов и аллокации в `ipc_kmsg_alloc`

```
; ipc_kmsg_alloc, 0xfffffff00a1e6b4c
; w0 = msg_size, w1 = aux_size, x2 = desc_count, w3 = flags
0xa1e6c70  lsr   w8, w3, #1              ; IPC_KMSG_ALLOC_ZERO (0x2) -> bit0
0xa1e6c74  and   w25, w3, #8             ; IPC_KMSG_ALLOC_NOFAIL (0x8)
0xa1e6c78  lsl   w21, w25, #0xc          ; -> 0x8000 (Z_NOFAIL)
0xa1e6c7c  bfi   w21, w8, #2, #1         ; -> | 0x4  (Z_ZERO)   [alloc_flags]
...
; payload (ikm_udata): kalloc_type_var_impl(view, size, flags, 0)
0xa1e6c8c  mov   w1, w23                 ; max_udata_size
0xa1e6c90  adrp  x0, #0x7c6a000
0xa1e6c94  add   x0, x0, #0xfb0           ; kalloc_type_view
0xa1e6c98  mov   x2, x21                 ; ZERO|NOFAIL
0xa1e6c9c  mov   x3, #0
0xa1e6ca0  bl    0xfffffff00a220c30      ; kalloc_type_var_impl
...
; kdata (header+descriptors), если layout ALL_OOL/KDATA_OOL
0xa1e6d08  mov   x2, x21                 ; ZERO|NOFAIL
0xa1e6d0c  mov   x3, #0
0xa1e6d10  bl    0xfffffff00a220c30
...
; сам struct ipc_kmsg — всегда Z_ZERO|Z_NOFAIL
0xa1e6d28  ldp   x0, x1, [x8]            ; zone/descriptor
0xa1e6d2c  mov   w2, #0x8004             ; Z_ZERO(0x4) | Z_NOFAIL(0x8000)
0xa1e6d30  bl    0xfffffff00a292e20
```

Сверка констант с `osfmk/kern/zalloc.h` (main): `Z_ZERO = 0x0004`, `Z_NOFAIL = 0x8000` — совпадает
с `0x8004` и с `bfi → 0x4`. Сверка `ipc_kmsg_alloc_flags_t`: `KERNEL=0x1, ZERO=0x2, ALL_INLINE=0x4,
NOFAIL=0x8, LINEAR=0x10`. Кросс-проверка: обёртка `ipc_kmsg_alloc_uext_reply` передаёт `0x1B`
(`0xa1e6e40..0xa1e6e48`: `mov w1,#0; mov w2,#0; mov w3,#0x1b; b 0xa1e6b4c`) = KERNEL|ZERO|NOFAIL|LINEAR,
что дословно совпадает с исходником. Значит и `0xB` в `ipc_kobject_server` — это ровно ZERO-путь.

**Вывод:** payload reply-сообщения (включая `inband_output`) выделяется с `Z_ZERO`; явного `memset` в
`ipc_kobject_server`/`ipc_kmsg_alloc` нет — обнуление делегировано аллокатору флагом. Это и есть
механизм `IPC_KMSG_ALLOC_ZERO` в 27.2.

---

## 4. OOL-путь: куда смотрит `structureOutput`

MIG-рутина `0xa34ed50` строит аргументы и зовёт prep-функцию `0xa9ae990`. Там:

```
; args = sp+0x30;  +0x50 scalarOutput, +0x58 structureOutput, +0x60 size,
;                  +0x68 structureOutputDescriptor, +0x70 descriptorSize
0xa9aeb3c  str   x8, [sp, #0x88]         ; args+0x58 = inband_output (из MIG-аргумента)
0xa9aeb40  ldr   w24, [x19]
0xa9aeb44  str   w24, [sp, #0x90]        ; args+0x60 = *inband_outputCnt
0xa9aeb30  lsl   x1, x25, #3
0xa9aeb34  bl    0xfffffff00aa65cc0      ; bzero(scalar_output, cnt*8)
...
; OOL output: дескриптор поверх user-VA текущей задачи
0xa9aeb60  mov   x0, x22                 ; ool_output (user VA)
0xa9aeb64  mov   x1, x20                 ; *ool_output_size
0xa9aeb68  mov   w2, #1                  ; kIODirectionIn
0xa9aeb6c  bl    0xfffffff00a97ae84      ; IOMemoryDescriptor::withAddressRange
0xa9aeb74  str   x0, [sp, #0x98]         ; args+0x68 = descriptor (отдельное поле)
0xa9aeb88  ldr   w26, [x27]
0xa9aeb8c  str   w26, [sp, #0xa0]        ; args+0x70 = descriptorSize
0xa9aebf4  add   x2, sp, #0x30
0xa9aebfc  bl    0xfffffff00a9ae888      ; callExternalMethod(selector, args)
```

`structureOutput` **не перезаписывается** указателем на OOL-буфер: дескриптор остаётся в `+0x68`.
`dispatchExternalMethod` (`0xa9b0888`) для OOL лишь сверяет длину:

```
0xa9b0994  ldr   x8, [x2, #0x68]         ; structureOutputDescriptor
0xa9b0998  cbz   x8, 0xa9b09ec           ; нет -> сравнить args+0x60
0xa9b09ac  ldr   x9, [x16, #0xb0]!       ; vtable getLength()
0xa9b09c4  blraa x9, x16
0xa9b09e0  cmp   x8, x19                 ; length == checkStructureOutputSize ?
0xa9b09e4  b.ne  0xa9b0950               ; иначе 0xE00002C2
```

Обработчик получает `args` как есть; OOL-страница в `+0x68` ему доступна, но IOSurface её не трогает:

```
; sel 28 wrapper 0x9c39660
0x9c39664  ldr   x8, [x2, #0x20]         ; scalarInput
0x9c39668  ldr   w1, [x8]                ; surface_id
0x9c3966c  ldr   x8, [x2, #0x58]         ; structureOutput (inband!)
0x9c39670  add   x3, x2, #0x60           ; &structureOutputSize
0x9c39674  mov   x2, x8
0x9c39678  b     0x9c3d838

; sel 34 wrapper 0x9c397d8
0x9c397e4  ldr   x2, [x2, #0x58]         ; structureOutput (inband!)
0x9c397e8  b     0x9c3b7b0
```

В телах `0x9c3d838..0x9c3d908` (sel 28) и `0x9c3b7b0..0x9c3b9f8` (sel 34) **нет ни одного обращения к
`[x?, #0x68]` или `[x?, #0x70]`** (проверено линейным дизасмом диапазонов). Ядро sel 28 получает только
`(self, id, out, &size)`, ядро sel 34 — `(self, id, out)`; до `args` они не дотягиваются.

---

## 5. Что остаётся в незаполненных байтах

Reply-kmsg выделен с `Z_ZERO` целиком (payload `max_udata_size` и/или kdata + сам `struct ipc_kmsg`).

| sel | объявлено | записано | остаётся |
|---|---|---|---|
| 28 | `0xA0` (`0x9c3d8a4`) | `0x84` (`memcpy` @`0x9c3d890`) | `out+0x84..0x9F` = **28 Б нулей** |
| 34 (already imported) | `0xC68` | 12 Б (`0x9c3b894` out[0]=-1, `0x9c3b8a0` out[0x18]=ID) | `out+0x08..0x17`, `out+0x1C..0xC67` = **3164 Б нулей** |
| 13 | `0x28` | `0x23` | `0x21`, `0x24..0x27` = **5 Б нулей** |

*(размеры sel 28/34 подтверждены здесь по дизасму; sel 13 — по аудиту U, в этой проверке не перепроверялся)*

При OOL-выходе:
- `args->structureOutput` всё равно inband reply-буфер → обработчик пишет туда, хвост — нули;
- user-VA в `structureOutputDescriptor` не получает **ничего**: IOSurface sel 28/34 его не читают,
  IOKit только вызывает `getLength()` для проверки размера;
- стало быть, в OOL-буфере остаётся то, что пользователь сам туда положил — это его память,
  не kernel-данные. Утечки через OOL нет.

---

## 6. Что проверено и что нет

**Проверено по бинарю:** функция `ipc_kobject_server`, факт и аргументы `ipc_kmsg_alloc` с ZERO-флагом,
порядок «alloc → kroutine», трансляция ZERO→`Z_ZERO(0x4)` и передача его в payload/kdata-аллокации,
`Z_ZERO|Z_NOFAIL` для самого kmsg, независимая сверка флагов на `ipc_kmsg_alloc_uext_reply (0x1B)`,
разделение `structureOutput`/`structureOutputDescriptor` в prep-функции, отсутствие доступа к `+0x68`
в sel 28/34.

**Не подтверждено:** инструкция `memset`/`stp xzr` внутри generic-аллокатора (последний хоп
`Z_ZERO → KMA_ZERO`); статически подтверждён только флаг и контракт. Динамика (реальные нули в
`out+0x84..0x9F` на устройстве) не снималась.

---

## 7. Адреса

| что | VA |
|---|---|
| `ipc_kobject_server` (internal инлайнен) | `0xfffffff00a21722c` |
| alloc-site (`mov w3,#0xb; bl ipc_kmsg_alloc`) | `0xfffffff00a2174f0` / `0xfffffff00a2174f4` |
| вызов kroutine (`blraa`) | `0xfffffff00a217908` |
| паника destination rights | `0xfffffff00a217ad4` |
| `ipc_kmsg_alloc` | `0xfffffff00a1e6b4c` |
| ZERO→`Z_ZERO` (`bfi`) | `0xfffffff00a1e6c7c` |
| payload alloc / kdata alloc / kmsg zalloc | `0xa1e6ca0` / `0xa1e6d10` / `0xa1e6d30` |
| `ipc_kmsg_alloc_uext_reply` (flags 0x1B) | `0xfffffff00a1e6e48` |
| `is_io_connect_method` (MIG 2865) | `0xfffffff00a34ed50` |
| prep args / `structureOutput` store | `0xfffffff00a9ae990` / `0xfffffff00a9aeb3c` |
| OOL descriptor (`withAddressRange`) | `0xfffffff00a9aeb6c` (store `0xa9aeb74`) |
| `dispatchExternalMethod` | `0xfffffff00a9b0888` |
| sel 28 wrapper / core / `*size=0xA0` | `0x9c39660` / `0x9c3d838` / `0x9c3d8a4` |
| sel 34 wrapper / core / out-записи | `0x9c397d8` / `0x9c3b7b0` / `0x9c3b894`,`0x9c3b8a0` |
| `bzero` (скаляры) | `0xfffffff00aa65cc0` |
