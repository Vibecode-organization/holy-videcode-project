// FUN_fffffff008d13c38 @ fffffff008d13c38 size=64
// CALLERS:
//   fffffff00afb8d27 no-fn
// CALLEES:

undefined * FUN_fffffff008d13c38(undefined8 param_1,undefined8 *param_2,uint param_3)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_3 < 0xc) {
    lVar2 = (ulong)param_3 * 0x30;
    *param_2 = param_1;
    puVar1 = &UNK_fffffff007e3b738 + (int)lVar2;
    if (lVar2 - (int)lVar2 != 0) {
      puVar1 = (undefined *)
               ((ulong)(&UNK_fffffff007e3b738 + lVar2) & 0xffffffffffff | 0x2bad000000000000);
    }
    return puVar1;
  }
  return (undefined *)0x0;
}

