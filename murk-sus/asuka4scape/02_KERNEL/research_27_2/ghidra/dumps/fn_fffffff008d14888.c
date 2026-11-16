// FUN_fffffff008d14888 @ fffffff008d14888 size=916
// CALLERS:
//   fffffff00afb8d45 no-fn
//   fffffff008d14870 FUN_fffffff008d14810@fffffff008d14810
//   fffffff008d14cb0 FUN_fffffff008d14c84@fffffff008d14c84
// CALLEES:
//   fffffff008cd5990 FUN_fffffff008cd5990
//   fffffff008dffd70 thunk_EXT_FUN_80110000032222a8
//   fffffff008d5104c FUN_fffffff008d5104c
//   fffffff008de6694 FUN_fffffff008de6694
//   fffffff008de66d4 FUN_fffffff008de66d4
//   fffffff008dc6bcc FUN_fffffff008dc6bcc
//   fffffff008dffda0 thunk_EXT_FUN_8011000003222de0
//   fffffff008d13dec FUN_fffffff008d13dec
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008dffd20 thunk_EXT_FUN_80110000038fe6b0
//   fffffff008d665e4 FUN_fffffff008d665e4
//   fffffff008de670c FUN_fffffff008de670c
//   fffffff008d06098 FUN_fffffff008d06098

undefined8 FUN_fffffff008d14888(long param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 in_x7;
  long *plVar11;
  double dVar12;
  double dVar13;
  
  if (param_2 == (int *)0x0) {
    uVar9 = 0xe00002c2;
    iVar6 = FUN_fffffff008cd5954(1,4);
    if (iVar6 != 0) {
      FUN_fffffff008de670c();
    }
  }
  else {
    lVar8 = FUN_fffffff008d5104c(*(undefined8 *)(param_1 + 0x100),8);
    plVar11 = *(long **)(lVar8 + 0xc0);
    iVar3 = (**(code **)(*plVar11 + 0xe8))(plVar11,0);
    iVar4 = (**(code **)(*plVar11 + 0xf0))(plVar11,0);
    iVar5 = (**(code **)(*plVar11 + 0xe8))(plVar11,1);
    iVar6 = (**(code **)(*plVar11 + 0xf0))(plVar11,1);
    lVar8 = FUN_fffffff008d5104c(*(undefined8 *)(param_1 + 0x100),8);
    bVar1 = 0x16 < *(int *)(lVar8 + 0x4c);
    if (bVar1 && DAT_fffffff00ae6f288 == 0) {
      iVar6 = 0x20;
    }
    if (bVar1 && DAT_fffffff00ae6f288 == 0) {
      iVar4 = 0x20;
      iVar3 = 9;
      iVar5 = 9;
    }
    if ((((param_2[1] == iVar3) && (param_2[2] == iVar4)) && (param_2[4] == iVar5)) &&
       (param_2[5] == iVar6)) {
      if ((*param_2 == 0) || (param_2[3] == 0)) {
        uVar9 = 0xe00002c2;
        iVar6 = FUN_fffffff008cd5954(1,4);
        if (iVar6 != 0) {
          FUN_fffffff008de66d4();
        }
      }
      else {
        uVar2 = (iVar5 * iVar6 + iVar3 * iVar4) * 2;
        lVar8 = FUN_fffffff008d13dec(param_1,*(undefined8 *)(param_2 + 6),(ulong)uVar2);
        if (lVar8 == 0) {
          uVar9 = 0;
        }
        else {
          dVar12 = (double)FUN_fffffff008d06098(param_2[3],0x11,0xf,0);
          dVar13 = (double)FUN_fffffff008d06098(*param_2,0x11,0xf,0);
          uVar9 = FUN_fffffff008d665e4(1.0 / dVar12,plVar11,0,1,1);
          uVar10 = FUN_fffffff008d665e4(1.0 / dVar13,plVar11,0,0,1);
          iVar6 = FUN_fffffff008cd5954(4,4);
          if (iVar6 != 0) {
            FUN_fffffff008cd5990
                      (4,4,0xff,"setCustomFilter",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                       ,0x391,
                       "updateWithAllCoefficientsCopy: client=%d (%p) %s: raw hDstToSrcRatio=0x%x vDstToSrcRatio=0x%x (diff=%d) -> hSrcToDstRatioIndex=%d vSrcToDstRatioIndex=%d\n"
                       ,in_x7,*(undefined4 *)(param_1 + 0xe4),param_1,
                       *(undefined8 *)(param_1 + 0xe8),param_2[3],*param_2,param_2[3] - *param_2,
                       uVar9,uVar10);
          }
          if (*(long *)(param_1 + 0x108) != 0) {
            thunk_EXT_FUN_80110000032222a8();
          }
          uVar9 = FUN_fffffff008dc6bcc(*(undefined8 *)(param_1 + 0x118),uVar10,uVar9,lVar8,1);
          if (*(long *)(param_1 + 0x108) != 0) {
            thunk_EXT_FUN_8011000003222de0();
          }
          if (((int)uVar9 != 0) && (iVar6 = FUN_fffffff008cd5954(1,4), iVar6 != 0)) {
            FUN_fffffff008de6694(uVar9);
          }
          if (uVar2 != 0) {
            thunk_EXT_FUN_80110000038fe6b0(lVar8,(ulong)uVar2 << 2);
          }
        }
      }
    }
    else {
      uVar9 = 0xe00002c2;
      iVar7 = FUN_fffffff008cd5954(1,4);
      if (iVar7 != 0) {
        FUN_fffffff008cd5990
                  (1,4,0xff,"setCustomFilter",
                   "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                   ,0x369,
                   "inconsistent sizes given: given(expected): vTaps: %d(%d), vPhases: %d(%d), hTaps: %d(%d), hPhases: %d(%d)\n"
                   ,in_x7,param_2[1],iVar3,param_2[2],iVar4,param_2[4],iVar5,param_2[5],iVar6);
      }
    }
  }
  return uVar9;
}

