# IOGPUDeviceUserClient — полная карта селекторов (24B115, iPhone14,7)

## Где
- kext `com.apple.iokit.IOGPUFamily`, `__TEXT_EXEC` va `0xfffffff0099407d0`, fileoff `0x293c7d0`, size `0x4481c`.
- `IOGPUDeviceUserClient::deviceUserClientStart` @ `0xfffffff009949dbc` (строка `virtual bool IOGPUDeviceUserClient::deviceUserClientStart()` @ `0xfffffff00782b17c`).
- `externalMethod`/`getTargetAndMethodForIndex` @ `0xfffffff00994a1e0`:
  - `cmp w1,#0x37` → 56 селекторов;
  - `index*0x18` + таблица;
  - `ldrb w8,[x0,#0x103]; tst w8,#1` → таблица A или B.
- Таблица A: `0xfffffff007fea200` (fileoff dc+0x1600? см. iogpu_dc.bin, база 0xfffffff007fe8c10).
- Таблица B: `0xfffffff007fea740`.

## Условие таблицы B
`[client+0x103] = 0xfffffff0099658e8([client+0x120])`:
- проверяет `com.apple.private.gpu-restricted` (@ `0xfffffff00782debf`) → 1;
- иначе `com.apple.developer.gpu-restricted` (@ `0xfffffff00782dee0`).
Т.е. клиент **с** restricted-энтитлментом получает таблицу B, где селекторы 21..54 подменены на
`0xfffffff009949520` = `return 0xE00002E2`. Обычный клиент получает полную таблицу A.

## Таблица A (56)
```
[00] 0x99947330 out 0x40
[01] 0x99947444 out 0x40
[02] 0x99947478 out 0x218
[03] 0x99947548 out 0x08
[04] 0x9994757c out 0x20
[05] 0x99947658 out 0x10
[06] 0x999476bc out 0x10
[07] 0x999479c0 in1
[08] 0x99947a54
[09] 0x99947bdc in1
[10] 0x99947bf0 in2
[11] 0x99947c08 in2 out1
[12] 0x99947c28 in2 out 0x10
[13] 0x99947c50 in1
[14] 0x99947c64 in2 out 0x10
[15] 0x99947c84 in1
[16] 0x99947c98 out 0x08
[17] 0x99947ca8 out 0x04
[18] 0x99947cb8 in1
[19] 0x99947ccc in1 out 0x18
[20] 0x99947ce4 in1
[21] 0x99947cf8 out 0x30
[22] 0x99947d08
[23] 0x99947d18 out1
[24] 0x99947d28 in2
[25] 0x99947de4 in4 out1
[26] 0x99948074 in1 stIn0xc
[27] 0x9994811c in1 stIn0x4
[28] 0x999481c0 out2
[29] 0x999481f4 in1
[30] 0x9994822c in2
[31] 0x999482fc in1 out2
[32] 0x999483d4 in2
[33] 0x99948410 in2
[34] 0x9994844c in1 out1
[35] 0x999484b4 in2
[36] 0x999484cc in3 out1
[37] 0x99948568 in1
[38] 0x9994857c stIn0x18
[39] 0x9994858c stIn0x18 out1
[40] 0x999485dc in1 out2
[41] 0x99948710 in1
[42] 0x9994873c in2 out2
[43] 0x99948920 in1
[44] 0x999489a4 in2
[45] 0x99948af4 in1 stInany
[46] 0x99948d60 in1 out2
[47] 0x99948e1c in2
[48] 0x99948ed8 in2
[49] 0x99948f94 in1
[50] 0x9994903c in1
[51] 0x999490e0 in3
[52] 0x999491a0 in2 stInany
[53] 0x99949330 in2 stInany
[54] 0x999494c0 in2 out1
[55] 0x99949514
```

## Ключевые обработчики
### sel 0 @ 0xfffffff009947330 (out 0x40)
```
user[0]  = w8 = (dev[0x1f0] & 0xffff) | ((dev[0x1f0] >> 9) & 0x1000)
user[4]  = dev[0x1f8] (u32)
user[8]  = dev vtable+0x540 (== 0x999760c0: ldr x0,[x0,#0x208]; ret)
user[0x10] = [dev+0x208]          <-- 64-bit kernel pointer
user[0x18] = dev[0x100] (u32)
user[0x20] = 0x999749b8(dev,0)    <-- размер: таблица*0x100000, clamp [dev+0x2c8]
user[0x28] = dev vtable+0x680(...)
user[0x30] = [dev+0x258]
user[0x38] = dev[0x260] (u16), user[0x3c] = dev[0x262] (u16)
```
`dev+0x208` пишется в `0x9995f464`: `str x0,[x19,#0x208]` после `bl 0x9998433c`
(GOT `0x7ff20e8` → `0xfffffff00a9033d8`, IOKit-аллокатор), обнуляется в `0x9995fdb8`.
Значит это указатель на объект ядра (heap), например IOCommandPool-подобный.

### sel 4 @ 0xfffffff00994757c (out 0x20)
```
user[0]  = [client+0xe8]   <-- объект из 0x999843dc(1, site 0xaf22c0) (GOT 0x7ff2138 -> 0xa8945f0)
user[8]  = vtable+0x78([client+0xd8][8])
user[0x18] = vtable+0x88(...) (u32)
user[0x10] = [sp+8] после 0x99964430
```
`[client+0xe8]` создаётся при старте клиента (`0x99949ea0: bl 0x999843dc`, args `w0=1, x1=site`),
скорее всего IOLock/IORecursiveLock → heap-указатель.

### sel 2 @ 0xfffffff009947478 (out 0x218)
```
x21 = args->structureOutput
x0  = [client+0x110]                ; IOCommand из пула (0x998477c -> 0xa970b64)
vtable+0x78 -> 0xa97146c: ldr x0,[x0,#0x28]; ret
user[0] = x0 + u32[client+0x118]
```
`+0x28` инициализируется в `0xa970b64` из 3-го аргумента, а deviceUserClientStart передаёт `x2=0`
(`0x99949e34: mov x2,#0`), поэтому на старте там 0 → user[0] = queue id, не указатель.

### sel 1 @ 0xfffffff009947444 (out 0x40)
```
x1 = [dev+0x1e8]; x0 = user out; w2 = 0x40; bl 0x9984e4c   ; memcpy 0x40 байт
```
`dev+0x1e8` в тексте IOGPU напрямую не пишется (возможно, вычисляемый адрес/другой класс) — не классифицировано.

### sel 5 @ 0xfffffff009947658 (out 0x10)
Цикл по глобалу `0xfffffff00af220c0`: `x20=[g]; x21=x20+0x1000000; bl 0x999843fc(x20,x21,&g)` пока не успех;
`user[0]=x20, user[8]=x21`. Похоже на выдачу 16-МБ GPU VA-диапазона, не ядро.

## Вывод
- IOGPU отдаёт в user **указатели на объекты ядра (heap)**: sel 0 ([dev+0x208]) и sel 4 ([client+0xe8]).
- Текстового/дата-указателя (slide) в разобранных селекторах нет.
- sel 2 (structOut 0x218) — не утечка, как предполагалось в отчёте id 6.
- Гейт: только энтитлменты `com.apple.private.gpu-restricted` / `com.apple.developer.gpu-restricted`,
  причём их наличие **отключает** половину селекторов (таблица B).

## Дальше
1. Классифицировать `[dev+0x208]` (0x9998433c → 0xa9033d8) и `[client+0xe8]` (0xa8945f0) по именам IOKit.
2. Проверить, зависит ли адрес heap-объекта от kernel slide (нужен дамп с известным slide).
3. Искать статический указатель: sel 0 user[0x30]=[dev+0x258], vtable+0x680; sel 1 memcpy [dev+0x1e8].
4. Проверить на устройстве доступность IOGPU user client из sandbox и фактические значения sel 0/4.
