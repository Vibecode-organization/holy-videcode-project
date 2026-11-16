// FUN_fffffff00a201c58 @ fffffff00a201c58 size=1452
// CALLERS:
//   fffffff00afb83c0 no-fn
//   fffffff00a2a611c FUN_fffffff00a2a60a8@fffffff00a2a60a8
// CALLEES:
//   fffffff00a1f1060 FUN_fffffff00a1f1060
//   fffffff00a1f036c FUN_fffffff00a1f036c
//   fffffff00a2ed330 FUN_fffffff00a2ed330
//   fffffff00a2defc4 FUN_fffffff00a2defc4
//   fffffff00a22b850 FUN_fffffff00a22b850
//   fffffff00a22b5a8 FUN_fffffff00a22b5a8
//   fffffff00a2dcc04 FUN_fffffff00a2dcc04
//   fffffff00a22b804 FUN_fffffff00a22b804
//   fffffff00aa65cc0 FUN_fffffff00aa65cc0
//   fffffff00a2eb688 FUN_fffffff00a2eb688
//   fffffff00aa4cc7c FUN_fffffff00aa4cc7c

undefined8
FUN_fffffff00a201c58
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long param_7,undefined8 *param_8,undefined4 *param_9
          ,undefined8 *param_10,undefined4 *param_11)

{
  ulong *puVar1;
  uint uVar2;
  undefined **ppuVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong *puVar15;
  undefined **ppuVar16;
  undefined **ppuVar17;
  undefined **ppuVar18;
  ulong *puVar19;
  ulong uVar20;
  ulong uVar21;
  undefined1 auVar22 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined8 local_70;
  undefined8 local_68;
  
  if (param_7 == 0) {
    return 0x10;
  }
  ppuVar18 = (undefined **)0x0;
  ppuVar17 = (undefined **)0x0;
  puVar1 = (ulong *)(param_7 + 0x48);
  lVar4 = tpidr_el1;
  puVar15 = (ulong *)0x0;
  do {
    *(int *)(lVar4 + 0x1c0) = *(int *)(lVar4 + 0x1c0) + 1;
    LOAcquire();
    uVar8 = *(uint *)(param_7 + 8);
    *(uint *)(param_7 + 8) = uVar8 + 0x1000000;
    if ((uVar8 >> 0x10 & 0xff) == uVar8 >> 0x18) {
      *(undefined4 *)(param_7 + 0xc) = *(undefined4 *)(lVar4 + 0x4e8);
      uVar13 = *puVar1;
      lVar5 = DAT_fffffff00ad9a0f8;
    }
    else {
      FUN_fffffff00a22b5a8(param_7,(ulong)(uVar8 >> 0x18),lVar4);
      uVar13 = *puVar1;
      lVar5 = DAT_fffffff00ad9a0f8;
    }
    DAT_fffffff00ad9a0f8 = lVar5;
    if ((uVar13 == 0) || (uVar13 == 0)) {
      auVar22 = FUN_fffffff00a22b850(param_7);
      if (puVar15 != (ulong *)0x0) {
        FUN_fffffff00a2defc4
                  (auVar22,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                   ppuVar18,(ulong)puVar15,0,(undefined **)0x0);
        FUN_fffffff00a2defc4
                  (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,
                   (uint *)DAT_fffffff007bc72a8,ppuVar17,(ulong)puVar15,0,(undefined **)0x0);
        return 0x10;
      }
      return 0x10;
    }
    uVar13 = *puVar1;
    if (uVar13 == 0) {
      uVar11 = 0;
      if (DAT_fffffff007bc72a8 != (ulong *)0x0) goto LAB_fffffff00a201d30;
LAB_fffffff00a201d4c:
      uVar12 = 0xe;
      uVar8 = 0x3fff;
    }
    else {
      uVar11 = 0;
      if (uVar13 != 0) {
        uVar11 = (uVar13 & 0x3fff) << 0xe;
      }
      if ((uVar13 & 0x4000000000) != 0) {
        uVar11 = (uVar13 & 0x10 | 0x20) << (uVar13 & 0xf);
      }
      if (DAT_fffffff007bc72a8 == (ulong *)0x0) goto LAB_fffffff00a201d4c;
LAB_fffffff00a201d30:
      uVar12 = (uint)*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c);
      uVar8 = ~(-1 << (ulong)(*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c) & 0x1f));
    }
    puVar19 = (ulong *)(ulong)(-1 << (ulong)(uVar12 & 0x1f) &
                              uVar8 + (int)((uVar11 & 0xffffffff) * 0xaaaaaab >> 0x20) * 4);
    if (puVar19 <= puVar15) {
      DAT_fffffff00ad9a0f8 = lVar5 + 1;
      uVar13 = *puVar1;
      if (uVar13 != 0) {
        local_70 = 0;
        local_68 = 0;
        if ((uVar13 >> 0x26 & 1) == 0) {
          if (uVar13 == 0) goto LAB_fffffff00a201ec4;
          uVar11 = (uVar13 & 0x3fff) << 0xe;
          uVar13 = uVar13 & 0xffffffffffffc000 | 0x4000000000;
        }
        else {
          uVar11 = (uVar13 & 0x10 | 0x20) << (uVar13 & 0xf);
          uVar13 = uVar13 & 0xffffffffffffffe0;
        }
        if (0x2f < uVar11) {
          uVar20 = 0;
          uVar21 = 1;
          break;
        }
      }
LAB_fffffff00a201ec4:
      auVar22 = FUN_fffffff00a22b850(param_7);
      goto LAB_fffffff00a201ecc;
    }
    auVar22 = FUN_fffffff00a22b850(param_7);
    if (puVar15 != (ulong *)0x0) {
      FUN_fffffff00a2defc4
                (auVar22,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                 ppuVar18,(ulong)puVar15,0,(undefined **)0x0);
      FUN_fffffff00a2defc4
                (extraout_q0,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                 ppuVar17,(ulong)puVar15,0,(undefined **)0x0);
    }
    auVar22 = FUN_fffffff00a2dcc04
                        ((long *)DAT_fffffff007bc72a8,puVar19,(undefined ********)0x0,
                         (undefined ********)0x8000,(undefined ********)0x7,0);
    ppuVar18 = auVar22._8_8_;
    if (auVar22._0_4_ != 0) {
      return 6;
    }
    auVar22 = FUN_fffffff00a2dcc04
                        ((long *)DAT_fffffff007bc72a8,puVar19,(undefined ********)0x0,
                         (undefined ********)0x8000,(undefined ********)0x7,0);
    ppuVar17 = auVar22._8_8_;
    puVar15 = puVar19;
    if (auVar22._0_4_ != 0) {
      FUN_fffffff00a2defc4
                (extraout_q0_00,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007bc72a8
                 ,ppuVar18,(ulong)puVar19,0,(undefined **)0x0);
      return 6;
    }
  } while( true );
LAB_fffffff00a201f98:
  puVar1 = (ulong *)(uVar13 + uVar21 * 0x18);
  uVar12 = (uint)puVar1[1];
  uVar8 = uVar12 & 0x1f0000;
  if ((uVar12 & 0x1f0000) != 0) {
    uVar9 = *(uint *)((long)puVar1 + 0xc);
    if ((uVar12 >> 0x11 & 1) == 0) {
      if ((uVar12 & 0x50000) == 0) {
        uVar9 = 0;
      }
      else {
        uVar14 = *puVar1;
        if (uVar14 == 0) {
          uVar14 = 0;
        }
        FUN_fffffff00a1f036c(uVar14);
        if (uVar9 != 0) {
          uVar9 = FUN_fffffff00a1f1060(uVar14,extraout_x1,uVar9);
        }
        if ((*(byte *)(uVar14 + 1) & 7) == 0) {
          bVar7 = ((int)lVar5 - *(int *)(uVar14 + 0x48) & 0x80000000U) != 0;
          uVar2 = 0;
          if (bVar7) {
            uVar2 = uVar9;
          }
          uVar8 = 0x100000;
          uVar9 = uVar2;
          if (bVar7) {
            uVar8 = uVar12 & 0x1d0000;
          }
        }
LAB_fffffff00a202078:
        if ((*(byte *)(uVar14 + 2) & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0xbffc,0xfffffff00a2021fc);
          (*pcVar6)();
        }
        FUN_fffffff00a22b804(uVar14 + 0x14);
      }
    }
    else if (uVar9 != 0) {
      uVar14 = *puVar1;
      if (uVar14 == 0) {
        uVar14 = 0;
      }
      FUN_fffffff00a1f036c(uVar14);
      if ((*(byte *)(uVar14 + 1) & 7) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4cc7c();
      }
      uVar9 = FUN_fffffff00a1f1060(uVar14,extraout_x1_00,uVar9);
      goto LAB_fffffff00a202078;
    }
    *(uint *)((long)ppuVar18 + uVar20 * 4) = (uint)((uVar21 << 0x20) >> 0x18) | uVar12 >> 0x18 | 3;
    *(uint *)((long)ppuVar17 + uVar20 * 4) = uVar8 | uVar9;
    uVar20 = (ulong)((int)uVar20 + 1);
  }
  uVar21 = uVar21 + 1;
  if ((uVar11 & 0xffffffff) * 0xaaaaaab >> 0x20 == uVar21) {
    auVar22 = FUN_fffffff00a22b850(param_7);
    if ((int)uVar20 == 0) {
LAB_fffffff00a201ecc:
      local_70 = 0;
      local_68 = 0;
      if (puVar15 == (ulong *)0x0) {
        uVar20 = 0;
      }
      else {
        FUN_fffffff00a2defc4
                  (auVar22,param_2,param_3,param_4,param_5,param_6,(uint *)DAT_fffffff007bc72a8,
                   ppuVar18,(ulong)puVar15,0,(undefined **)0x0);
        FUN_fffffff00a2defc4
                  (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,
                   (uint *)DAT_fffffff007bc72a8,ppuVar17,(ulong)puVar15,0,(undefined **)0x0);
        uVar20 = 0;
      }
    }
    else {
      ppuVar3 = (undefined **)(uVar20 * 4);
      if (DAT_fffffff007bc72a8 == (ulong *)0x0) {
        uVar8 = 0xe;
        uVar13 = 0x3fff;
      }
      else {
        uVar8 = (uint)*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c);
        uVar13 = (ulong)(uint)~(-1 << (ulong)(*(byte *)((long)DAT_fffffff007bc72a8 + 0x2c) & 0x1f));
      }
      ppuVar16 = (undefined **)(uVar13 + (long)ppuVar3 & (long)(-1 << (ulong)(uVar8 & 0x1f)));
      uVar13 = (long)ppuVar16 + uVar20 * -4;
      if (ppuVar3 <= ppuVar16 && uVar13 != 0) {
        puVar10 = (undefined8 *)((long)ppuVar18 + (long)ppuVar3);
        if ((((ulong)ppuVar18 ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
          puVar10 = (undefined8 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
        }
        FUN_fffffff00aa65cc0(puVar10,uVar13);
        puVar10 = (undefined8 *)((long)ppuVar17 + (long)ppuVar3);
        if ((((ulong)ppuVar17 ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
          puVar10 = (undefined8 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
        }
        FUN_fffffff00aa65cc0(puVar10,uVar13);
      }
      FUN_fffffff00a2eb688
                ((long)DAT_fffffff007bc72a8,(ulong)ppuVar18,(long)ppuVar16 + (long)ppuVar18,0,
                 -0xff8434738);
      FUN_fffffff00a2eb688
                ((long)DAT_fffffff007bc72a8,(ulong)ppuVar17,(long)ppuVar16 + (long)ppuVar17,0,
                 -0xff8434738);
      FUN_fffffff00a2ed330(DAT_fffffff007bc72a8,ppuVar18,ppuVar3,(undefined **)0x1,&local_68);
      FUN_fffffff00a2ed330(DAT_fffffff007bc72a8,ppuVar17,ppuVar3,(undefined **)0x1,&local_70);
      uVar13 = (long)puVar15 - (long)ppuVar16;
      if (uVar13 != 0) {
        FUN_fffffff00a2defc4
                  (extraout_q0_03,param_2,param_3,param_4,param_5,param_6,
                   (uint *)DAT_fffffff007bc72a8,(undefined **)((long)ppuVar16 + (long)ppuVar18),
                   uVar13,0,(undefined **)0x0);
        FUN_fffffff00a2defc4
                  (extraout_q0_04,param_2,param_3,param_4,param_5,param_6,
                   (uint *)DAT_fffffff007bc72a8,(undefined **)((long)ppuVar16 + (long)ppuVar17),
                   uVar13,0,(undefined **)0x0);
      }
    }
    *param_8 = local_68;
    *param_9 = (int)uVar20;
    *param_10 = local_70;
    *param_11 = (int)uVar20;
    return 0;
  }
  goto LAB_fffffff00a201f98;
}

