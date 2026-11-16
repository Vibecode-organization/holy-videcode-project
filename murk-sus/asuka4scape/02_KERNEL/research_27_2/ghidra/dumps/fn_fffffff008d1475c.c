// FUN_fffffff008d1475c @ fffffff008d1475c size=180
// CALLERS:
//   fffffff00afb8d41 no-fn
// CALLEES:
//   fffffff008d14158 FUN_fffffff008d14158
//   fffffff008cd5954 FUN_fffffff008cd5954
//   fffffff008de6620 FUN_fffffff008de6620
//   fffffff008e00740 thunk_EXT_FUN_80110000036da494
//   fffffff008de6604 FUN_fffffff008de6604

undefined8
FUN_fffffff008d1475c
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  bool bVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  int *piVar12;
  long *plVar13;
  ulong unaff_x30;
  double dVar14;
  double dVar15;
  undefined1 auVar16 [16];
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  
  if (*(int *)(param_1 + 0x164) != 0) {
    auVar16 = FUN_fffffff008de6604();
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    if (*(int *)(auVar16._0_8_ + 0x164) != 0) {
      uVar8 = FUN_fffffff008d1b504
                        (auVar16._8_8_,param_3,param_4,param_5,param_6,param_7,param_8,&uStack_70);
      if ((int)uVar8 == 0) {
        uVar8 = FUN_fffffff008d14888(auVar16._0_8_,&uStack_70);
      }
      return uVar8;
    }
    auVar16 = FUN_fffffff008de6664();
    piVar12 = auVar16._8_8_;
    lVar9 = auVar16._0_8_;
    if (piVar12 == (int *)0x0) {
      uVar8 = 0xe00002c2;
      iVar4 = FUN_fffffff008cd5954(1,4);
      if (iVar4 != 0) {
        FUN_fffffff008de670c();
      }
    }
    else {
      lVar10 = FUN_fffffff008d5104c(*(undefined8 *)(lVar9 + 0x100),8);
      plVar13 = *(long **)(lVar10 + 0xc0);
      iVar5 = (**(code **)(*plVar13 + 0xe8))(plVar13,0);
      iVar6 = (**(code **)(*plVar13 + 0xf0))(plVar13,0);
      iVar7 = (**(code **)(*plVar13 + 0xe8))(plVar13,1);
      iVar4 = (**(code **)(*plVar13 + 0xf0))(plVar13,1);
      lVar10 = FUN_fffffff008d5104c(*(undefined8 *)(lVar9 + 0x100),8);
      bVar1 = 0x16 < *(int *)(lVar10 + 0x4c);
      if (bVar1 && DAT_fffffff00ae6f288 == 0) {
        iVar4 = 0x20;
      }
      if (bVar1 && DAT_fffffff00ae6f288 == 0) {
        iVar6 = 0x20;
        iVar5 = 9;
        iVar7 = 9;
      }
      if ((((piVar12[1] == iVar5) && (piVar12[2] == iVar6)) && (piVar12[4] == iVar7)) &&
         (piVar12[5] == iVar4)) {
        if ((*piVar12 == 0) || (piVar12[3] == 0)) {
          uVar8 = 0xe00002c2;
          iVar4 = FUN_fffffff008cd5954(1,4);
          if (iVar4 != 0) {
            FUN_fffffff008de66d4();
          }
        }
        else {
          uVar2 = (iVar7 * iVar4 + iVar5 * iVar6) * 2;
          lVar10 = FUN_fffffff008d13dec(lVar9,*(undefined8 *)(piVar12 + 6),(ulong)uVar2);
          if (lVar10 == 0) {
            uVar8 = 0;
          }
          else {
            dVar14 = (double)FUN_fffffff008d06098(piVar12[3],0x11,0xf,0);
            dVar15 = (double)FUN_fffffff008d06098(*piVar12,0x11,0xf,0);
            uVar8 = FUN_fffffff008d665e4(1.0 / dVar14,plVar13,0,1,1);
            uVar11 = FUN_fffffff008d665e4(1.0 / dVar15,plVar13,0,0,1);
            iVar4 = FUN_fffffff008cd5954(4,4);
            if (iVar4 != 0) {
              FUN_fffffff008cd5990
                        (4,4,0xff,"setCustomFilter",
                         "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                         ,0x391,
                         "updateWithAllCoefficientsCopy: client=%d (%p) %s: raw hDstToSrcRatio=0x%x vDstToSrcRatio=0x%x (diff=%d) -> hSrcToDstRatioIndex=%d vSrcToDstRatioIndex=%d\n"
                        );
            }
            if (*(long *)(lVar9 + 0x108) != 0) {
              thunk_EXT_FUN_80110000032222a8();
            }
            uVar8 = FUN_fffffff008dc6bcc(*(undefined8 *)(lVar9 + 0x118),uVar11,uVar8,lVar10,1);
            if (*(long *)(lVar9 + 0x108) != 0) {
              thunk_EXT_FUN_8011000003222de0();
            }
            if (((int)uVar8 != 0) && (iVar4 = FUN_fffffff008cd5954(1,4), iVar4 != 0)) {
              FUN_fffffff008de6694(uVar8);
            }
            if (uVar2 != 0) {
              thunk_EXT_FUN_80110000038fe6b0(lVar10,(ulong)uVar2 << 2);
            }
          }
        }
      }
      else {
        uVar8 = 0xe00002c2;
        iVar4 = FUN_fffffff008cd5954(1,4);
        if (iVar4 != 0) {
          FUN_fffffff008cd5990
                    (1,4,0xff,"setCustomFilter",
                     "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                     ,0x369,
                     "inconsistent sizes given: given(expected): vTaps: %d(%d), vPhases: %d(%d), hTaps: %d(%d), hPhases: %d(%d)\n"
                    );
        }
      }
    }
    return uVar8;
  }
  if (param_3 == 0x1b0) {
    thunk_EXT_FUN_80110000036da494(0x31b000d0,*(undefined4 *)(param_1 + 0x168),0,0,0,0);
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008d147d4);
      (*pcVar3)();
    }
    uVar8 = FUN_fffffff008d14158(param_1,param_2);
    return uVar8;
  }
  iVar4 = FUN_fffffff008cd5954(1,4);
  if (iVar4 != 0) {
    FUN_fffffff008de6620(param_3);
  }
  return 0xe00002c2;
}

