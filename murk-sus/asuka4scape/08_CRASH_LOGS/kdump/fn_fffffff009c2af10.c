// FUN_fffffff009c2af10 @ fffffff009c2af10 size=500
// CALLERS:
//   fffffff00afebe35 ?
//   fffffff009c3b4dc FUN_fffffff009c3b3ac@fffffff009c3b3ac
//   fffffff009c3cad8 FUN_fffffff009c3caa8@fffffff009c3caa8
//   fffffff009c3ceb0 FUN_fffffff009c3cd9c@fffffff009c3cd9c
// CALLS:
//   fffffff009c48cfc FUN_fffffff009c48cfc
//   fffffff009c48d14 FUN_fffffff009c48d14
//   fffffff009c49a54 thunk_FUN_fffffff00a89a1f4
//   fffffff009c49ba4 thunk_FUN_fffffff00a208ed8
//   fffffff009c172ec FUN_fffffff009c172ec
//   fffffff009c49b64 thunk_FUN_fffffff00aa4c590
//   fffffff009c48d20 FUN_fffffff009c48d20
//   fffffff009c495d4 thunk_FUN_fffffff00a226de0
//   fffffff009c2adb0 FUN_fffffff009c2adb0
//   fffffff009c495b4 thunk_FUN_fffffff00a2262a8

void FUN_fffffff009c2af10
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               int param_8,undefined8 param_9,ulong param_10,ulong param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  byte bVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  uint *puVar8;
  undefined8 uVar9;
  int iVar10;
  undefined1 auVar11 [16];
  undefined1 extraout_q0 [16];
  undefined4 uVar12;
  undefined1 auVar13 [12];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  undefined1 *local_60;
  long local_58;
  
  uVar14 = param_4._0_4_;
  auVar15 = param_4._4_12_;
  uVar12 = param_3._0_4_;
  auVar13 = param_3._4_12_;
  local_58 = *(long *)PTR_DAT_fffffff00806ca40;
  auVar11 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
  auVar1._4_12_ = auVar13;
  auVar1._0_4_ = uVar12;
  auVar2._4_12_ = auVar15;
  auVar2._0_4_ = uVar14;
  FUN_fffffff009c2adb0(auVar11,param_2,auVar1,auVar2,param_5,param_6,param_7);
  uVar5 = (**(code **)(**(long **)(param_7 + 0x3c8) + 0x90))();
  plVar6 = thunk_FUN_fffffff00a89a1f4(uVar5 >> 1 & 0x7fffffff);
  if ((int)uVar5 != 0) {
    iVar4 = 0;
    do {
      lVar7 = (**(code **)(**(long **)(param_7 + 0x3c8) + 0x118))(*(long **)(param_7 + 0x3c8),iVar4)
      ;
      if ((param_8 == 0) || (bVar3 = FUN_fffffff009c48d20(lVar7), bVar3 != 0)) {
        (**(code **)(*plVar6 + 0xe8))(plVar6,lVar7);
      }
      iVar4 = iVar4 + 1;
    } while ((int)uVar5 != iVar4);
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
  iVar4 = (**(code **)(*plVar6 + 0x90))(plVar6);
  if (iVar4 != 0) {
    iVar10 = 0;
    do {
      lVar7 = (**(code **)(*plVar6 + 0x118))(plVar6,iVar10);
      puVar8 = (uint *)FUN_fffffff009c48cfc(lVar7);
      do {
        local_60 = &DAT_aaaaaaaaaaaaaaaa;
        thunk_FUN_fffffff00a208ed8(5,1000000000,(long *)&local_60);
        uVar5 = FUN_fffffff009c48d14(lVar7);
        uVar9 = FUN_fffffff009c172ec
                          (extraout_q0,param_2,uVar12,uVar14,param_5,param_6,puVar8,uVar5,
                           (ulong)local_60,param_10,param_11);
      } while ((int)uVar9 == 0);
      iVar10 = iVar10 + 1;
    } while (iVar10 != iVar4);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_58) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

