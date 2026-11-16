// FUN_fffffff00a9e3e40 @ fffffff00a9e3e40 size=536
// CALLERS:
//   fffffff00afbfaf4 no-fn
//   fffffff007c66ad8 no-fn
// CALLEES:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00aa65b10 FUN_fffffff00aa65b10
//   fffffff00a22170c FUN_fffffff00a22170c

undefined8 * FUN_fffffff00a9e3e40(undefined8 *param_1)

{
  uint uVar1;
  undefined8 *puVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long *plVar7;
  uint in_wzr;
  
  *param_1 = &PTR_FUN_fffffff007c24f30;
  plVar7 = *(long **)(param_1[1] + 8);
  lVar3 = tpidr_el1;
  if (*(ulong *)(DAT_fffffff00ad95bb8 + 8) == 0) {
    *(ulong *)(DAT_fffffff00ad95bb8 + 8) = (ulong)*(uint *)(lVar3 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(DAT_fffffff00ad95bb8,lVar3,(undefined **)0x0);
  }
  if (DAT_fffffff00add6e48 == (long *)0x0) {
    uVar1 = *(uint *)(DAT_fffffff00ad95bb8 + 8);
    if (uVar1 == *(uint *)(lVar3 + 0x4e8)) {
      *(uint *)(DAT_fffffff00ad95bb8 + 8) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(DAT_fffffff00ad95bb8,lVar3,uVar1);
    }
    if (plVar7 == (long *)0x0) goto LAB_fffffff00a9e3fa0;
  }
  else {
    lVar6 = *DAT_fffffff00add6e48;
    if (plVar7 == (long *)0x0) {
      (**(code **)(lVar6 + 0x118))(lVar6 + 0x118,DAT_fffffff00add6e48,param_1[3]);
      uVar1 = *(uint *)(DAT_fffffff00ad95bb8 + 8);
      if (uVar1 == *(uint *)(lVar3 + 0x4e8)) {
        *(uint *)(DAT_fffffff00ad95bb8 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(DAT_fffffff00ad95bb8,lVar3,uVar1);
      }
      goto LAB_fffffff00a9e3fa0;
    }
    (**(code **)(lVar6 + 0x108))(lVar6 + 0x108);
    uVar1 = *(uint *)(DAT_fffffff00ad95bb8 + 8);
    if (uVar1 == *(uint *)(lVar3 + 0x4e8)) {
      *(uint *)(DAT_fffffff00ad95bb8 + 8) = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(DAT_fffffff00ad95bb8,lVar3,uVar1);
    }
  }
  (**(code **)(*plVar7 + 0x168))(plVar7,param_1);
  (**(code **)(*(long *)param_1[3] + 0x28))();
LAB_fffffff00a9e3fa0:
  if (DAT_fffffff00add6e40 != 0) {
    uVar1 = *(uint *)(DAT_fffffff00add6e40 + 0x10);
    if (uVar1 != 0) {
      uVar5 = 0;
      lVar3 = *(long *)(DAT_fffffff00add6e40 + 0x18);
      do {
        if (param_1 == *(undefined8 **)(lVar3 + uVar5 * 8)) {
          uVar1 = uVar1 - 1;
          *(uint *)(DAT_fffffff00add6e40 + 0x10) = uVar1;
          uVar4 = (uint)uVar5;
          if (uVar4 <= uVar1 && uVar1 - uVar4 != 0) {
            FUN_fffffff00aa65b10
                      ((undefined8 *)(lVar3 + (uVar5 & 0xffffffff) * 8),
                       (undefined8 *)(lVar3 + (ulong)(uVar4 + 1) * 8),(ulong)(uVar1 - uVar4) << 3);
          }
          break;
        }
        uVar5 = uVar5 + 1;
      } while (uVar1 != uVar5);
    }
  }
  puVar2 = (undefined8 *)param_1[1];
  param_1[1] = 0;
  FUN_fffffff00a22170c((long *)&DAT_fffffff007c7bb10,puVar2);
  *param_1 = 0xffffffffffffffff;
  return param_1;
}

