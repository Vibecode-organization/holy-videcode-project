// FUN_fffffff00a9e2a18 @ fffffff00a9e2a18 size=24
// CALLERS:
//   fffffff00afbfad1 no-fn
//   fffffff007c66ab0 no-fn
// CALLEES:

undefined8 FUN_fffffff00a9e2a18(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uStack_38;
  undefined8 *puStack_30;
  undefined8 uStack_28;
  undefined8 uStack_20;
  long lStack_18;
  
  lVar1 = tpidr_el1;
  puStack_30 = *(undefined8 **)(lVar1 + 0x288);
  if (puStack_30 != (undefined8 *)0x0) {
    uStack_38 = *puStack_30;
    puStack_30 = puStack_30 + 0x60;
    uStack_20 = 0;
    uStack_28 = 0;
    lStack_18 = param_1 + 0x40;
    uVar2 = (**(code **)(*(long *)(param_1 + 0x10) + 0x20))(param_2,&uStack_38);
    return uVar2;
  }
  return 0;
}

