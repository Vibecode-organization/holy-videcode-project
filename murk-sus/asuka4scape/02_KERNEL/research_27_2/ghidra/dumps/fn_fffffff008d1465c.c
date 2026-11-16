// FUN_fffffff008d1465c @ fffffff008d1465c size=256
// CALLERS:
//   fffffff00afb8d3f no-fn
//   fffffff008d09868 FUN_fffffff008d096c0@fffffff008d096c0
//   fffffff008d09b08 FUN_fffffff008d09994@fffffff008d09994
//   fffffff008d09c74 FUN_fffffff008d09b74@fffffff008d09b74
//   fffffff008d09fec FUN_fffffff008d09f34@fffffff008d09f34
//   fffffff008d0a418 FUN_fffffff008d0a000@fffffff008d0a000
// CALLEES:
//   fffffff008de65d4 FUN_fffffff008de65d4
//   fffffff008d14158 FUN_fffffff008d14158
//   fffffff008d1b5a0 FUN_fffffff008d1b5a0
//   fffffff008d1b580 FUN_fffffff008d1b580

/* WARNING: Removing unreachable block (ram,0xfffffff008d14720) */
/* WARNING: Removing unreachable block (ram,0xfffffff008d147d0) */

undefined8
FUN_fffffff008d1465c
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 *param_6,undefined8 param_7,undefined8 param_8)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  int *piVar11;
  long *plVar12;
  double dVar13;
  double dVar14;
  undefined1 auVar15 [16];
  undefined8 uStack_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 uStack_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 uStack_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  if (*(int *)(param_1 + 0x164) != 0) {
    uStack_58 = 0;
    local_60 = 0;
    uStack_48 = 0;
    uStack_50 = 0;
    uStack_78 = 0;
    local_80 = 0;
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_98 = 0;
    local_a0 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_b8 = 0;
    local_c0 = 0;
    uStack_a8 = 0;
    uStack_b0 = 0;
    uStack_d8 = 0;
    local_e0 = 0;
    uStack_c8 = 0;
    uStack_d0 = 0;
    uStack_f8 = 0;
    local_100 = 0;
    uStack_e8 = 0;
    uStack_f0 = 0;
    uStack_118 = 0;
    local_120 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    uStack_138 = 0;
    local_140 = 0;
    uStack_128 = 0;
    uStack_130 = 0;
    uStack_158 = 0;
    local_160 = 0;
    uStack_148 = 0;
    uStack_150 = 0;
    uStack_178 = 0;
    local_180 = 0;
    uStack_168 = 0;
    uStack_170 = 0;
    uStack_198 = 0;
    local_1a0 = 0;
    uStack_188 = 0;
    uStack_190 = 0;
    uStack_1b8 = 0;
    local_1c0 = 0;
    uStack_1a8 = 0;
    uStack_1b0 = 0;
    uStack_1d8 = 0;
    local_1e0 = 0;
    uStack_1c8 = 0;
    uStack_1d0 = 0;
    uStack_1e8 = 0;
    local_1f0 = 0;
    FUN_fffffff008d1b580(param_5,&local_1f0);
    uVar7 = FUN_fffffff008d1b5a0(param_2,param_3,param_4,0,&local_1f0);
    if ((int)uVar7 == 0) {
      if (param_6 != (undefined8 *)0x0) {
        uStack_1e8 = *param_6;
        uStack_1d8 = param_6[2];
        local_1e0 = param_6[1];
      }
      uVar7 = FUN_fffffff008d14158(param_1,&local_1f0);
    }
    return uVar7;
  }
  auVar15 = FUN_fffffff008de65d4();
  lVar8 = auVar15._0_8_;
  if (*(int *)(lVar8 + 0x164) == 0) {
    if (param_3 != 0x1b0) {
      iVar3 = FUN_fffffff008cd5954(1,4);
      if (iVar3 != 0) {
        FUN_fffffff008de6620(param_3);
      }
      return 0xe00002c2;
    }
    thunk_EXT_FUN_80110000036da494(0x31b000d0,*(undefined4 *)(lVar8 + 0x168),0,0,0,0);
    uVar7 = FUN_fffffff008d14158(lVar8,auVar15._8_8_);
    return uVar7;
  }
  auVar15 = FUN_fffffff008de6604();
  uStack_258 = 0;
  uStack_260 = 0;
  uStack_248 = 0;
  uStack_250 = 0;
  if (*(int *)(auVar15._0_8_ + 0x164) != 0) {
    uVar7 = FUN_fffffff008d1b504
                      (auVar15._8_8_,param_3,param_4,param_5,param_6,param_7,param_8,&uStack_260);
    if ((int)uVar7 == 0) {
      uVar7 = FUN_fffffff008d14888(auVar15._0_8_,&uStack_260);
    }
    return uVar7;
  }
  auVar15 = FUN_fffffff008de6664();
  piVar11 = auVar15._8_8_;
  lVar8 = auVar15._0_8_;
  if (piVar11 == (int *)0x0) {
    uVar7 = 0xe00002c2;
    iVar3 = FUN_fffffff008cd5954(1,4);
    if (iVar3 != 0) {
      FUN_fffffff008de670c();
    }
  }
  else {
    lVar9 = FUN_fffffff008d5104c(*(undefined8 *)(lVar8 + 0x100),8);
    plVar12 = *(long **)(lVar9 + 0xc0);
    iVar4 = (**(code **)(*plVar12 + 0xe8))(plVar12,0);
    iVar5 = (**(code **)(*plVar12 + 0xf0))(plVar12,0);
    iVar6 = (**(code **)(*plVar12 + 0xe8))(plVar12,1);
    iVar3 = (**(code **)(*plVar12 + 0xf0))(plVar12,1);
    lVar9 = FUN_fffffff008d5104c(*(undefined8 *)(lVar8 + 0x100),8);
    bVar1 = 0x16 < *(int *)(lVar9 + 0x4c);
    if (bVar1 && DAT_fffffff00ae6f288 == 0) {
      iVar3 = 0x20;
    }
    if (bVar1 && DAT_fffffff00ae6f288 == 0) {
      iVar5 = 0x20;
      iVar4 = 9;
      iVar6 = 9;
    }
    if ((((piVar11[1] == iVar4) && (piVar11[2] == iVar5)) && (piVar11[4] == iVar6)) &&
       (piVar11[5] == iVar3)) {
      if ((*piVar11 == 0) || (piVar11[3] == 0)) {
        uVar7 = 0xe00002c2;
        iVar3 = FUN_fffffff008cd5954(1,4);
        if (iVar3 != 0) {
          FUN_fffffff008de66d4();
        }
      }
      else {
        uVar2 = (iVar6 * iVar3 + iVar4 * iVar5) * 2;
        lVar9 = FUN_fffffff008d13dec(lVar8,*(undefined8 *)(piVar11 + 6),(ulong)uVar2);
        if (lVar9 == 0) {
          uVar7 = 0;
        }
        else {
          dVar13 = (double)FUN_fffffff008d06098(piVar11[3],0x11,0xf,0);
          dVar14 = (double)FUN_fffffff008d06098(*piVar11,0x11,0xf,0);
          uVar7 = FUN_fffffff008d665e4(1.0 / dVar13,plVar12,0,1,1);
          uVar10 = FUN_fffffff008d665e4(1.0 / dVar14,plVar12,0,0,1);
          iVar3 = FUN_fffffff008cd5954(4,4);
          if (iVar3 != 0) {
            FUN_fffffff008cd5990
                      (4,4,0xff,"setCustomFilter",
                       "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                       ,0x391,
                       "updateWithAllCoefficientsCopy: client=%d (%p) %s: raw hDstToSrcRatio=0x%x vDstToSrcRatio=0x%x (diff=%d) -> hSrcToDstRatioIndex=%d vSrcToDstRatioIndex=%d\n"
                      );
          }
          if (*(long *)(lVar8 + 0x108) != 0) {
            thunk_EXT_FUN_80110000032222a8();
          }
          uVar7 = FUN_fffffff008dc6bcc(*(undefined8 *)(lVar8 + 0x118),uVar10,uVar7,lVar9,1);
          if (*(long *)(lVar8 + 0x108) != 0) {
            thunk_EXT_FUN_8011000003222de0();
          }
          if (((int)uVar7 != 0) && (iVar3 = FUN_fffffff008cd5954(1,4), iVar3 != 0)) {
            FUN_fffffff008de6694(uVar7);
          }
          if (uVar2 != 0) {
            thunk_EXT_FUN_80110000038fe6b0(lVar9,(ulong)uVar2 << 2);
          }
        }
      }
    }
    else {
      uVar7 = 0xe00002c2;
      iVar3 = FUN_fffffff008cd5954(1,4);
      if (iVar3 != 0) {
        FUN_fffffff008cd5990
                  (1,4,0xff,"setCustomFilter",
                   "/Library/Caches/com.apple.xbs/707A499F-C092-4EC7-9870-008113E1647D/TemporaryDirectory.2EJgzU/Sources/IOSurfaceAccelerator_kexts/IOSurfaceAcceleratorClient.cpp"
                   ,0x369,
                   "inconsistent sizes given: given(expected): vTaps: %d(%d), vPhases: %d(%d), hTaps: %d(%d), hPhases: %d(%d)\n"
                  );
      }
    }
  }
  return uVar7;
}

