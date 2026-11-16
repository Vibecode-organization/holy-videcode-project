// FUN_fffffff00a97b5ec @ fffffff00a97b5ec size=644
// CALLERS:
//   fffffff00afbf1b0 no-fn
//   fffffff00a97b9f0 FUN_fffffff00a97b900@fffffff00a97b900
//   fffffff00a97baa4 FUN_fffffff00a97ba94@fffffff00a97ba94
// CALLEES:
//   fffffff00a2211ec FUN_fffffff00a2211ec
//   fffffff00a22170c FUN_fffffff00a22170c
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2262d4 FUN_fffffff00a2262d4

void FUN_fffffff00a97b5ec(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 *puVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  uint in_wzr;
  
  lVar8 = *(long *)(param_1 + 0x10);
  if (param_3 != 0 || lVar8 != 0) {
    if (lVar8 == 0) {
      uVar6 = 0x8004;
      if ((DAT_fffffff007c7dc78 & 0x10) != 0) {
        uVar6 = 4;
      }
      puVar2 = (undefined8 *)FUN_fffffff00a2211ec((long *)&DAT_fffffff007c7dc50,uVar6);
      if (*(long *)(param_1 + 0x10) == 0) {
        *(long *)(param_1 + 0x10) = (long)puVar2;
      }
      else {
        FUN_fffffff00a22170c((long *)&DAT_fffffff007c7dc90,puVar2);
      }
      lVar8 = *(long *)(param_1 + 0x10);
      if (lVar8 == 0) {
        return;
      }
    }
    uVar4 = DAT_fffffff00add7578;
    lVar1 = tpidr_el1;
    if (*(long *)(DAT_fffffff00add7578 + 0x18) == lVar1) {
      iVar7 = *(int *)(DAT_fffffff00add7578 + 0x20) + 1;
    }
    else {
      if (*(ulong *)(DAT_fffffff00add7578 + 8) == 0) {
        *(ulong *)(DAT_fffffff00add7578 + 8) = (ulong)*(uint *)(lVar1 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(DAT_fffffff00add7578,lVar1,(undefined **)0x0);
      }
      *(long *)(uVar4 + 0x18) = lVar1;
      iVar7 = 1;
    }
    *(int *)(uVar4 + 0x20) = iVar7;
    plVar3 = *(long **)(lVar8 + 0x58);
    if (plVar3 == (long *)0x0) {
      plVar3 = (long *)(**(code **)(DAT_fffffff00ad95c70 + 0x68))();
      if ((plVar3 != (long *)0x0) &&
         (uVar4 = (**(code **)(*plVar3 + 0xd0))(plVar3,2), (uVar4 & 1) == 0)) {
        (**(code **)(*plVar3 + 0x28))(plVar3);
        plVar3 = (long *)0x0;
      }
      plVar5 = *(long **)(lVar8 + 0x58);
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x28))(plVar5,param_2);
      }
      *(long **)(lVar8 + 0x58) = plVar3;
    }
    lVar8 = *plVar3;
    if (param_3 == 0) {
      (**(code **)(lVar8 + 0x108))(lVar8 + 0x108,plVar3,param_2);
    }
    else {
      (**(code **)(lVar8 + 0xf0))();
    }
    uVar4 = DAT_fffffff00add7578;
    iVar7 = *(int *)(DAT_fffffff00add7578 + 0x20) + -1;
    *(int *)(DAT_fffffff00add7578 + 0x20) = iVar7;
    if (iVar7 == 0) {
      *(undefined8 *)(uVar4 + 0x18) = 0;
      uVar6 = *(uint *)(uVar4 + 8);
      if (uVar6 != *(uint *)(lVar1 + 0x4e8)) {
        FUN_fffffff00a226e08(uVar4,lVar1,uVar6);
        return;
      }
      *(uint *)(uVar4 + 8) = in_wzr;
    }
  }
  return;
}

