// FUN_fffffff0099d52e4 @ fffffff0099d52e4 size=484 depth=1
// CALLERS:
//   fffffff00afe6fe2 ?
//   fffffff0099d51c4 FUN_fffffff0099d50f8
//   fffffff0099d2ba0 FUN_fffffff0099d2b74
// CALLS:
//   fffffff009a4884c thunk_FUN_fffffff00aa65cc0
//   fffffff009a487fc thunk_FUN_fffffff00a92d93c
//   fffffff009a483bc thunk_FUN_fffffff00a894f30

undefined8 FUN_fffffff0099d52e4(long *param_1,int param_2,undefined8 *param_3,uint *param_4)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  undefined8 *puVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  undefined8 uVar10;
  ulong uVar11;
  int iVar12;
  
  uVar10 = 0xe00002c2;
  if ((((param_3 != (undefined8 *)0x0) && (param_4 != (uint *)0x0)) && (*param_4 != 0)) &&
     (((*param_4 % 0x60 == 0 && (uVar10 = 0xe00002d9, param_1[0x1b] != 0)) &&
      (uVar2 = thunk_FUN_fffffff00a92d93c(param_1), (uVar2 & 1) == 0)))) {
    if (param_2 == 0) {
      puVar6 = (undefined8 *)(*(long *)(param_1[0x1b] + 200) + 0x28);
    }
    else {
      puVar6 = (undefined8 *)
               (*(long *)(*(long *)(*(long *)(param_1[0x1b] + 200) + 0x58) + 0x10) + 0x18);
    }
    plVar9 = (long *)*puVar6;
    if (plVar9 == (long *)0x0) {
      uVar10 = 0xe00002bc;
    }
    else {
      iVar3 = (**(code **)(*plVar9 + 0x90))(plVar9);
      uVar11 = (ulong)*param_4;
      if (*param_4 != 0) {
        thunk_FUN_fffffff00aa65cc0(param_3,uVar11);
      }
      puVar1 = PTR_DAT_fffffff00800c9a0;
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
        iVar12 = 0;
        do {
          plVar5 = (long *)(**(code **)(*plVar9 + 0x118))(plVar9,iVar12);
          plVar5 = thunk_FUN_fffffff00a894f30(plVar5,(long)puVar1);
          uVar7 = (ulong)(uVar2 + 1) * 0x60;
          if ((plVar5 != (long *)0x0 && uVar2 < 0x2aaaaaa) &&
              (uVar7 < uVar11 || uVar7 - uVar11 == 0)) {
            lVar8 = (ulong)uVar2 * 0x60;
            iVar4 = (int)lVar8;
            uVar7 = (long)param_3 + (long)iVar4;
            if (lVar8 - iVar4 != 0) {
              uVar7 = (ulong)(param_3 + (ulong)uVar2 * 0xc) & 0xffffffffffff | 0x2bad000000000000;
            }
            iVar4 = (**(code **)(*plVar5 + 0x1f0))(plVar5,uVar7);
            uVar2 = uVar2 + iVar4;
          }
          iVar12 = iVar12 + 1;
        } while (iVar3 != iVar12);
        uVar2 = uVar2 * 0x60;
      }
      uVar10 = 0;
      *param_4 = uVar2;
    }
  }
  return uVar10;
}

