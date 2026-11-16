// FUN_fffffff00a9e2768 @ fffffff00a9e2768 size=688
// CALLERS:
//   fffffff00afbfad0 no-fn
//   fffffff007c66ab8 no-fn
// CALLEES:
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08

undefined8 FUN_fffffff00a9e2768(long param_1,ulong *param_2)

{
  ulong *puVar1;
  uint *puVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  long *plVar8;
  undefined *puVar9;
  long lVar10;
  long *plVar11;
  code *pcVar12;
  uint in_wzr;
  
  uVar5 = *(ulong *)(*(long *)(param_1 + 0x10) + 0x60);
  lVar4 = tpidr_el1;
  puVar1 = (ulong *)(uVar5 + 8);
  if (*puVar1 == 0) {
    *puVar1 = (ulong)*(uint *)(lVar4 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(uVar5,lVar4,(undefined **)0x0);
  }
  if (*(long *)(*(long *)(param_1 + 0x10) + 8) == 0) {
    uVar5 = *param_2;
    *(ulong *)(*(long *)(param_1 + 0x10) + 8) = uVar5;
    if (uVar5 != 0) {
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x10) = param_2[1];
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x18) = param_2[2];
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x20) = param_2[3];
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x28) = param_2[4];
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x30) = param_2[5];
      *(ulong *)(*(long *)(param_1 + 0x10) + 0x38) = param_2[6];
      uVar5 = *param_2;
      if (1 < uVar5) {
        if (param_2[7] != 0) {
          *(ulong *)(*(long *)(param_1 + 0x10) + 0x40) = param_2[7];
          uVar5 = *param_2;
        }
        if (2 < uVar5) {
          *(ulong *)(*(long *)(param_1 + 0x10) + 0x48) = param_2[8];
          *(ulong *)(*(long *)(param_1 + 0x10) + 0x50) = param_2[9];
          if (3 < *param_2) {
            *(ulong *)(*(long *)(param_1 + 0x10) + 0x58) = param_2[10];
          }
        }
      }
    }
    plVar7 = (long *)(**(code **)(**(long **)(*(long *)(param_1 + 0x10) + 0x68) + 0x120))();
    while (uVar6 = 0, plVar7 != (long *)0x0) {
      puVar9 = (undefined *)(**(code **)(*plVar7 + 0x38))(plVar7);
      do {
        if (puVar9 == &DAT_fffffff00ad98460) {
          plVar8 = (long *)plVar7[0xd];
          plVar11 = plVar7;
          if (plVar8 == (long *)0x0) goto LAB_fffffff00a9e2920;
          goto LAB_fffffff00a9e29d0;
        }
        puVar9 = *(undefined **)(puVar9 + 0x10);
      } while (puVar9 != (undefined *)0x0);
      plVar8 = plRam0000000000000068;
      plVar11 = (long *)0x0;
      if (plRam0000000000000068 != (long *)0x0) {
LAB_fffffff00a9e29d0:
        if (*param_2 < 3) {
          if (*param_2 != 0) {
            (*(code *)param_2[1])();
          }
        }
        else {
          pcVar12 = (code *)param_2[8];
          uVar6 = (**(code **)(*plVar8 + 0x370))();
          (*pcVar12)(uVar6,plVar11[0xd],plVar11 + 8);
        }
      }
LAB_fffffff00a9e2920:
      plVar8 = *(long **)(*(long *)(param_1 + 0x10) + 0x68);
      (**(code **)(*plVar8 + 0x108))(plVar8,plVar7);
      lVar10 = **(long **)(*(long *)(param_1 + 0x10) + 0x68);
      plVar7 = (long *)(**(code **)(lVar10 + 0x120))(lVar10 + 0x120);
    }
  }
  else {
    uVar6 = 0xe00002bc;
  }
  uVar5 = *(ulong *)(*(long *)(param_1 + 0x10) + 0x60);
  puVar2 = (uint *)(uVar5 + 8);
  uVar3 = *puVar2;
  if (uVar3 == *(uint *)(lVar4 + 0x4e8)) {
    *puVar2 = in_wzr;
  }
  else {
    FUN_fffffff00a226e08(uVar5,lVar4,uVar3);
  }
  return uVar6;
}

