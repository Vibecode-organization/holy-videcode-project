// FUN_fffffff00a9e3470 @ fffffff00a9e3470 size=416
// CALLERS:
//   fffffff00afbfae0 no-fn
//   fffffff007c66a80 no-fn
// CALLEES:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0

undefined8
FUN_fffffff00a9e3470
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,long param_9)

{
  ulong *puVar1;
  uint *puVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  undefined8 *puVar8;
  long lVar9;
  uint in_wzr;
  
  uVar5 = *(ulong *)(*(long *)(param_7 + 0x10) + 0x60);
  lVar3 = tpidr_el1;
  puVar1 = (ulong *)(uVar5 + 8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar3 + 0x4e8);
    *(long *)(param_7 + 0x68) = param_9;
  }
  else {
    param_1 = FUN_fffffff00a2262d4(uVar5,lVar3,(undefined **)0x0);
    *(long *)(param_7 + 0x68) = param_9;
  }
  if ((((param_9 != 0) && (*(long *)(param_9 + 0x28) != 0)) &&
      (plVar7 = *(long **)(*(long *)(param_9 + 0x28) + 0x28), plVar7 != (long *)0x0)) &&
     ((*plVar7 != 0 && (puVar8 = *(undefined8 **)(lVar3 + 0x288), puVar8 != (undefined8 *)0x0)))) {
    if ((*(uint *)(param_7 + 0x40) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4d114
                (param_1,param_2,param_3,param_4,param_5,param_6,
                 (byte *)"driverState has already been initialized @%s:%d");
    }
    *(uint *)(param_7 + 0x40) = *(uint *)(param_7 + 0x40) | 1;
    *(undefined8 *)(param_7 + 0x48) = *puVar8;
    *(undefined8 **)(param_7 + 0x50) = puVar8 + 0x60;
    *(undefined8 **)(param_7 + 0x38) = puVar8;
    puVar2 = (uint *)(puVar8 + 5);
    uVar4 = *puVar2;
    *puVar2 = uVar4 + 1;
    if (uVar4 + 0xf0000001 < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa61ed0(puVar2);
    }
  }
  lVar9 = *(long *)(param_7 + 0x10);
  if (*(ulong *)(lVar9 + 8) < 3) {
    if (*(ulong *)(lVar9 + 8) == 0) {
      (**(code **)(**(long **)(lVar9 + 0x68) + 0xf0))(*(long **)(lVar9 + 0x68),param_7);
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)(lVar9 + 0x10))(param_9);
    }
  }
  else {
    uVar6 = (**(code **)(lVar9 + 0x48))(param_8,param_9,param_7 + 0x40);
  }
  uVar5 = *(ulong *)(*(long *)(param_7 + 0x10) + 0x60);
  puVar2 = (uint *)(uVar5 + 8);
  uVar4 = *puVar2;
  if (uVar4 == *(uint *)(lVar3 + 0x4e8)) {
    *puVar2 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(uVar5,lVar3,uVar4);
  }
  return uVar6;
}

