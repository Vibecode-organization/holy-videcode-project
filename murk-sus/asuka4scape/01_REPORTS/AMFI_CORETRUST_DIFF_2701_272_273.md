# AMFI / CoreTrust — diff 27.0.1 → 27.2 → 27.3

Дата: 2026-11-11  
Устройство/таргет: iPhone14,7 (D27AP, A15/T8110)  
Kernelcache:
- 27.0.1 — `10_ARTIFACTS/kernelcache/kc_27.0.1_iphone14b.decompressed`
- 27.2 — `02_KERNEL/kc/27.2_24B115_kernelcache`
- 27.3 beta 1 — `02_KERNEL/kc273/24C5037i__iPhone14,7/kernelcache.macho`

Метод:
1. `ipsw kernel extract <kc> <kext>` для `com.apple.driver.AppleMobileFileIntegrity` и `com.apple.kext.CoreTrust`.
2. Function-shape diff (capstone, нормализация операндов; скрипт `kext_shape_diff.py`).
3. Ручная декомпиляция Ghidra изменённых функций.

---

## 1. Сводка

| Kext | Build | Размер | Функций | Совпало | Изменено |
|---|---|---:|---:|---:|---:|
| AMFI | 27.0.1 | 298 480 | 916 | 913 (99.67%) | 3 |
| AMFI | 27.2 | 298 480 | 916 | — | — |
| AMFI | 27.3b1 | 298 480 | 917 | 914 (99.73%) | 3 |
| CoreTrust | 27.0.1 | 147 992 | 138 | 136 (98.55%) | 2 |
| CoreTrust | 27.2 | 147 992 | 138 | — | — |
| CoreTrust | 27.3b1 | 147 992 | 138 | 138 (100%) | 0 |

Вывод: **CoreTrust в 27.3 не менялся вообще.** Все изменения CoreTrust — между 27.0.1 и 27.2.  
AMFI между 27.2 и 27.3 менялся мало, и это не новая проверка безопасности, а ABI/feature-правка launch constraints.

---

## 2. AMFI

### 2.1. 27.0.1 → 27.2 — главное: добавлена проверка DER entitlements

| 27.0.1 | 27.2 | Размер |
|---|---|---|
| `FUN_fffffff008e8b5ac` | `FUN_fffffff008ec35ac` | 140 → 240 (+100) |

27.0.1 проверял только обычные entitlements:

```c
iVar1 = extract_entitlements(param_1, &len, &ptr);
if (iVar1 == 0) {
    if (len == 0 && ptr == 0) return 1;
    log("AMFI: Entitlements present in no entitlement check.");
}
```

27.2 добавил второй вызов — извлечение **DER entitlements**:

```c
if (len == 0 && ptr == 0) {
    iVar1 = extract_der_entitlements(param_1, &der_len, &der_ptr);
    if (iVar1 == 0) {
        if (der_len == 0 && der_ptr == 0) return 1;
        log("AMFI: DER entitlements present in no entitlement check.");
    } else {
        log("AMFI: DER entitlement extraction failure in no entitlement check.");
    }
}
```

Смысл: на 27.0.1 бинарь с **только DER-entitlements** мог пройти проверку «no entitlements»; на 27.2 он отклоняется. Это hardening, а не дыра в 27.2.

Два других изменения 27.0.1→27.2 — только другие адреса глобалов/хелперов, логика та же:

| 27.0.1 | 27.2 | Размер | Что |
|---|---|---|---|
| `FUN_fffffff008e9e168` | `FUN_fffffff008ed61cc` | 168 | проверка entitlement-политики, логика идентична |
| `FUN_fffffff008e9e258` | `FUN_fffffff008ed62bc` | 172 | то же, флаг 1 |

### 2.2. 27.2 → 27.3 — launch constraints, не security check

| 27.2 | 27.3 | Размер |
|---|---|---|
| `FUN_fffffff008ec4cf4` | `FUN_fffffff008f88c74` | 1376 → 1376 |
| — | `FUN_fffffff008f904fc` | новый, 40 |
| `FUN_fffffff008ecffcc` | `FUN_fffffff008f93f74` | 164 → 168 |

В `FUN_...8ec4cf4` → `FUN_...f88c74` изменился вызов vtable+0x10: в 27.3 добавлен аргумент `param_1+0x28`:

```c
// 27.2
iVar2 = (**(code **)(*plVar3 + 0x10))(plVar3, param_1+0x20,
                                      param_1+8, param_1+0x10, &local_80);
// 27.3
iVar2 = (**(code **)(*plVar3 + 0x10))(plVar3, param_1+0x20, param_1+0x28,
                                      param_1+8, param_1+0x10, &local_80);
```

Остальная логика (launch type, constraint category, spawnattr, parent/self constraints) совпадает. Новый 40-байтный `FUN_...f904fc` — маленький хелпер, вероятно для нового аргумента. Это feature/ABI 27.3, не фикс памяти.

---

## 3. CoreTrust

### 3.1. 27.0.1 → 27.2 — два фикса

| 27.0.1 | 27.2 | Размер |
|---|---|---|
| `FUN_fffffff00948be7c` | `FUN_fffffff0094c5f5c` | 204 → 208 |
| `FUN_fffffff00948e1e8` | `FUN_fffffff0094c82cc` | 492 → 504 |

#### Fix 1 — clamp длины перед `+1`

27.0.1:

```c
if ((*param_3 & 1) == 0) { ... }
if (local_48 > 0xfffffffffffffffe) { brk #0x5500; }  // panic
*param_2 = local_48 + 1;
```

27.2:

```c
if ((*param_3 & 1) == 0) { ... }
puVar1 = local_48;
if (local_48 > 0xe) puVar1 = 0xf;
*param_2 = puVar1 + 1;
```

То есть длина/указатель ограничивается 15 перед `+1`; убран путь с переполнением/паникой. Класс — integer/length overflow в парсере CoreTrust.

#### Fix 2 — лимит глубины обхода chain

27.2 добавил счётчик итераций:

```c
lVar10 = 1;
while (...) {
    ...
    lVar10 = lVar10 + 1;
    if (lVar10 == 0x10) return 0x8000b;
}
```

В 27.0.1 этого счётчика нет — обход цепочки сертификатов мог уходить в глубину/цикл. 27.2 ограничивает 16 узлами (DoS-харденинг).

### 3.2. 27.2 → 27.3

**0 изменений.** CoreTrust 138/138 функций совпали по форме. Код CoreTrust в 27.3 идентичен 27.2.

---

## 4. Что это значит для bypass

- На **27.2** AMFI уже проверяет DER entitlements; трюк «DER-only entitlement» работает только на 27.0.1.
- CoreTrust на 27.2 уже содержит clamp длины и лимит глубины; на 27.3 он не менялся.
- Ни AMFI, ни CoreTrust не дают нового обхода на 27.2. Все найденные изменения — **hardening в 27.2**, а не ослабление в нём.
- Для KRW/SPTM единственный новый фикс, который мы нашли в 27.3, остаётся в **M2Scaler** (`validateCompressedTileBuffers`, +628 байт, новые проверки tile-data offset/extent). Его и надо разрабатывать.

---

## 5. Сырые результаты diff

### AMFI 27.0.1 → 27.2

```
funcs 916 916
identical 913 ratio 0.99672
changed regions 3
== replace A[213:214] B[213:214]
   A 0xfffffff008e8b5ac sz=140
   B 0xfffffff008ec35ac sz=240
== replace A[603:604] B[603:604]
   A 0xfffffff008e9e168 sz=168
   B 0xfffffff008ed61cc sz=168
== replace A[605:606] B[605:606]
   A 0xfffffff008e9e258 sz=172
   B 0xfffffff008ed62bc sz=172
```

### AMFI 27.2 → 27.3

```
funcs 916 917
identical 914 ratio 0.99727
changed regions 3
== replace A[244:245] B[244:245]
   A 0xfffffff008ec4cf4 sz=1376
   B 0xfffffff008f88c74 sz=1376
== insert A[358:358] B[358:359]
   B 0xfffffff008f904fc sz=40
== replace A[463:464] B[464:465]
   A 0xfffffff008ecffcc sz=164
   B 0xfffffff008f93f74 sz=168
```

### CoreTrust 27.0.1 → 27.2

```
funcs 138 138
identical 136 ratio 0.98551
changed regions 2
== replace A[92:93] B[92:93]
   A 0xfffffff00948be7c sz=204
   B 0xfffffff0094c5f5c sz=208
== replace A[115:116] B[115:116]
   A 0xfffffff00948e1e8 sz=492
   B 0xfffffff0094c82cc sz=504
```

### CoreTrust 27.2 → 27.3

```
funcs 138 138
identical 138 ratio 1.0
changed regions 0
```
