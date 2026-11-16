// FUN_fffffff00a31b1b8 @ fffffff00a31b1b8 size=2992
// CALLERS:
//   fffffff00afb9660 ?
//   fffffff00a31b960 FUN_fffffff00a31b1b8@fffffff00a31b1b8
//   fffffff00a7e0f80 FUN_fffffff00a7e0f00@fffffff00a7e0f00
//   fffffff00a3d5c50 FUN_fffffff00a3d5b14@fffffff00a3d5b14
//   fffffff00a3d5f94 FUN_fffffff00a3d5d28@fffffff00a3d5d28
//   fffffff00a3d6a64 FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3d6afc FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3d6bbc FUN_fffffff00a3d6418@fffffff00a3d6418
//   fffffff00a3db918 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3db9f4 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3dbac8 FUN_fffffff00a3db070@fffffff00a3db070
//   fffffff00a3dc624 FUN_fffffff00a3dc38c@fffffff00a3dc38c
//   fffffff00a97627c FUN_fffffff00a975c00@fffffff00a975c00
// CALLS:
//   fffffff00a2defc4 FUN_fffffff00a2defc4
//   fffffff00a22aeac FUN_fffffff00a22aeac
//   fffffff00aa65cc0 FUN_fffffff00aa65cc0
//   fffffff00a34ab40 FUN_fffffff00a34ab40
//   fffffff00a303950 FUN_fffffff00a303950
//   fffffff00a2df260 FUN_fffffff00a2df260
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a3061bc FUN_fffffff00a3061bc
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0
//   fffffff00a2ebe80 FUN_fffffff00a2ebe80
//   fffffff00a6db8c0 FUN_fffffff00a6db8c0
//   fffffff00a306ebc FUN_fffffff00a306ebc
//   fffffff00a30d23c FUN_fffffff00a30d23c
//   fffffff00a2dcc04 FUN_fffffff00a2dcc04
//   fffffff00a347f10 FUN_fffffff00a347f10
//   fffffff00a34b408 FUN_fffffff00a34b408
//   fffffff00a34a078 FUN_fffffff00a34a078
//   fffffff00a2299cc FUN_fffffff00a2299cc
//   fffffff00a346730 FUN_fffffff00a346730
//   fffffff00a31bd68 FUN_fffffff00a31bd68

ulong FUN_fffffff00a31b1b8
                (ulong param_1,undefined8 *param_2,undefined **param_3,undefined **param_4,
                uint *param_5,uint *param_6,ulong *param_7,uint param_8)

{
  undefined4 *puVar1;
  long lVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined **ppuVar7;
  long extraout_x1;
  uint *extraout_x1_00;
  uint *extraout_x1_01;
  uint *extraout_x1_02;
  uint *extraout_x1_03;
  uint *puVar8;
  long extraout_x1_04;
  undefined **ppuVar9;
  undefined **ppuVar10;
  undefined **ppuVar11;
  undefined8 uVar12;
  undefined1 *puVar13;
  uint uVar14;
  ulong *puVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  undefined *puVar19;
  undefined **ppuVar20;
  ulong uVar21;
  ulong *puVar22;
  ulong uVar23;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar24;
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar25 [16];
  ulong local_e0;
  ulong uStack_d8;
  long local_d0;
  uint *puStack_c8;
  undefined **local_c0;
  uint local_b8;
  ushort local_b4;
  undefined2 uStack_b2;
  undefined8 uStack_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  uint local_6c [3];
  
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_90 = 0;
  uStack_8c = 0;
  local_78 = 0;
  uStack_74 = 0;
  local_80 = 0;
  uStack_7c = 0;
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_b0._0_4_ = 0;
  uStack_b0._4_4_ = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  uStack_a0 = 0;
  uStack_9c = 0;
  puStack_c8 = (uint *)0x0;
  local_d0 = 0;
  local_b8 = 0;
  local_b4 = 0;
  uStack_b2 = 0;
  local_c0 = (undefined **)0x0;
  uStack_d8 = 0;
  local_e0 = 0;
  uVar21 = *param_7;
  if (uVar21 >> 0x29 == 0) {
    local_6c[0] = 0;
    uVar16 = (long)param_2 + (ulong)*(uint *)param_3;
    uVar5 = (uint)uVar21;
    if ((uVar5 >> 7 & 1) == 0) {
      uVar18 = uVar5 & 0x8000;
      local_c0 = &PTR_DAT_fffffff007bca630;
      uVar5 = uVar5 & 1;
LAB_fffffff00a31b2a0:
      if (param_1 == 0) {
        uVar14 = 0xe;
        uVar23 = 0xffffffffffffc000;
        uVar17 = 0x3fff;
      }
      else {
        uVar14 = (uint)*(byte *)(param_1 + 0x2c);
        uVar23 = -1L << ((ulong)*(byte *)(param_1 + 0x2c) & 0x3f);
        uVar17 = (ulong)~(uint)uVar23;
      }
      FUN_fffffff00a2299cc(param_1 + 0x30);
      ppuVar9 = (undefined **)(uVar23 & (ulong)param_2);
      ppuVar11 = (undefined **)(uVar17 + uVar16 & (long)(-1 << (ulong)(uVar14 & 0x1f)));
      puVar13 = (undefined *)0x40055;
      uVar17 = FUN_fffffff00a347f10
                         (&local_e0,param_1,(ulong)ppuVar9,(ulong)ppuVar11,(undefined *)0x40055);
      if ((int)uVar17 != 0) {
        lVar6 = tpidr_el1;
        goto LAB_fffffff00a31bd58;
      }
      local_6c[0] = 0;
      uVar17 = FUN_fffffff00a34a078(&local_e0,(int *)local_6c,ppuVar9,ppuVar11,puVar13);
      if (local_6c[0] != 0) {
        lVar6 = tpidr_el1;
        *(undefined8 *)(lVar6 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40((long)&local_e0);
        }
        else if ((puStack_c8 != (uint *)0x0) &&
                (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
          FUN_fffffff00a346730(uVar17,puStack_c8);
          return (ulong)local_6c[0];
        }
        return (ulong)local_6c[0];
      }
      ppuVar10 = (undefined **)(*(ulong *)(uVar17 + 0x28) & 0xfffffffffffffffc);
      if ((*(ulong *)(uVar17 + 0x28) & 3) != 0) {
        ppuVar10 = (undefined **)&DAT_fffffff00adbb300;
      }
      if (ppuVar10 == (undefined **)0x0) {
        lVar6 = tpidr_el1;
        *(undefined8 *)(lVar6 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) goto LAB_fffffff00a31bd04;
        if (puStack_c8 == (uint *)0x0) {
          return 2;
        }
        if ((~puStack_c8[10] & 3) != 0) goto LAB_fffffff00a31bd34;
        uVar5 = puStack_c8[9];
joined_r0xfffffff00a31bbb4:
        if ((uVar5 & 1) != 0) {
          return 2;
        }
LAB_fffffff00a31bd34:
        FUN_fffffff00a346730(uVar17,puStack_c8);
        return 2;
      }
      uVar23 = *(ulong *)(puStack_c8 + 6);
      if (uStack_d8 <= *(ulong *)(puStack_c8 + 6)) {
        uVar23 = uStack_d8;
      }
      if (uVar23 < uVar16) {
        *(int *)param_3 = (int)uVar23 - (int)param_2;
      }
      if ((-1 < *(char *)((long)ppuVar10 + 0x76)) && (0x4000000 < *(uint *)param_3)) {
        *(undefined4 *)param_3 = 0x4000000;
      }
      if ((uVar21 & 1) == 0) {
        if ((*(uint *)(uVar17 + 0x38) >> 5 & 1) != 0) {
          if ((*(uint *)(uVar17 + 0x38) & 0x800040) == 0) goto LAB_fffffff00a31b3e0;
          FUN_fffffff00a2ebe80(local_d0,param_2,0xc);
          lVar6 = tpidr_el1;
          if (lVar6 == 0) {
            lVar6 = 0;
          }
          else {
            lVar6 = *(long *)(lVar6 + 0x4e0);
          }
          uVar17 = FUN_fffffff00a6db8c0(lVar6,0x10000ec,param_2);
        }
        lVar6 = tpidr_el1;
        *(undefined8 *)(lVar6 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
LAB_fffffff00a31bd04:
          FUN_fffffff00a34ab40((long)&local_e0);
          return 2;
        }
        if (puStack_c8 == (uint *)0x0) {
          return 2;
        }
        if ((~puStack_c8[10] & 3) != 0) goto LAB_fffffff00a31bd34;
        uVar5 = puStack_c8[9];
        goto joined_r0xfffffff00a31bbb4;
      }
      if (((*(undefined8 **)(local_d0 + 0x58) == (undefined8 *)0x0) ||
          (*(undefined8 **)(local_d0 + 0x58) != &DAT_fffffff00ad6cc50)) &&
         (((*(uint *)(uVar17 + 0x38) & 0x60) == 0x40 || ((*(uint *)(uVar17 + 0x38) & 0x800040) != 0)
          ))) {
        lVar6 = tpidr_el1;
        *(undefined8 *)(lVar6 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40((long)&local_e0);
        }
        else if ((puStack_c8 != (uint *)0x0) &&
                (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
          FUN_fffffff00a346730(uVar17,puStack_c8);
        }
        puVar15 = (ulong *)CONCAT44(uStack_84,uStack_88);
        local_d0 = 0;
        puStack_c8 = (uint *)0x0;
        uStack_b0._4_4_ = 0;
        uStack_a8 = 0;
        local_b4 = 0;
        uStack_b2 = 0;
        uStack_b0._0_4_ = 0;
        uStack_9c = 0;
        uStack_98 = 0;
        uStack_a4 = 0;
        uStack_a0 = 0;
        uStack_8c = 0;
        uStack_88 = 0;
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_7c = 0;
        local_78 = 0;
        uStack_84 = 0;
        local_80 = 0;
        uStack_74 = 0;
        puVar22 = (ulong *)((ulong)*(uint *)param_3 + 0x3fff & 0x1ffffc000);
        auVar25 = FUN_fffffff00a2dcc04
                            ((long *)DAT_fffffff007c678d8,puVar22,(undefined ********)0x0,
                             (undefined ********)0x8040,(undefined ********)(ulong)param_8,0);
        ppuVar9 = auVar25._8_8_;
        uVar21 = auVar25._0_8_;
        uVar12 = extraout_d0;
        uVar24 = extraout_var;
        if (auVar25._0_4_ == 0) {
          bVar3 = FUN_fffffff00a2df260
                            (puVar15,param_2,ppuVar9,(undefined **)(ulong)*(uint *)param_3,1);
          uVar21 = (ulong)bVar3;
          uVar12 = extraout_d0_00;
          uVar24 = extraout_var_00;
          if (!bVar3) {
            puVar15 = (ulong *)(ulong)*(uint *)param_3;
            if (puVar15 <= puVar22 && (long)puVar22 - (long)puVar15 != 0) {
              FUN_fffffff00aa65cc0
                        ((undefined8 *)((long)ppuVar9 + (long)puVar15),(long)puVar22 - (long)puVar15
                        );
            }
            uVar21 = FUN_fffffff00a31b1b8
                               ((ulong)DAT_fffffff007c678d8,ppuVar9,param_3,param_4,param_5,param_6,
                                param_7,param_8);
            uVar12 = extraout_d0_01;
            uVar24 = extraout_var_01;
          }
        }
        if (ppuVar9 != (undefined **)0x0) {
          auVar25._8_8_ = uVar24;
          auVar25._0_8_ = uVar12;
          FUN_fffffff00a2defc4
                    (auVar25,in_q1,in_s2,in_s3,in_s4,in_s5,DAT_fffffff007c678d8,ppuVar9,
                     (ulong)puVar22,0,(undefined **)0x0);
          return uVar21;
        }
        return uVar21;
      }
LAB_fffffff00a31b3e0:
      uVar23 = *(ulong *)(uVar17 + 0x28);
      if (uVar5 == 0) {
        ppuVar10 = (undefined **)(uVar23 & 0xfffffffffffffffc);
        if ((uVar23 & 3) != 0) {
          ppuVar10 = (undefined **)&DAT_fffffff00adbb300;
        }
        if ((ppuVar10[9] == (undefined *)0x0) && (ppuVar10[7] == (undefined *)0x0))
        goto LAB_fffffff00a31b414;
        lVar6 = *(long *)(uVar17 + 0x10);
        uVar17 = *(ulong *)(uVar17 + 0x30);
        FUN_fffffff00a306ebc((long)ppuVar10);
        ppuVar20 = (undefined **)ppuVar10[9];
        if (ppuVar20 == (undefined **)0x0) {
          bVar3 = false;
        }
        else {
          puVar19 = ppuVar10[7];
          FUN_fffffff00a306ebc((long)ppuVar20);
          ppuVar7 = ppuVar20 + 5;
          iVar4 = *(int *)ppuVar7;
          *(int *)ppuVar7 = iVar4 + 1;
          if (iVar4 + 0xf0000001U < 0xf0000002) goto LAB_fffffff00a31bd4c;
          bVar3 = puVar19 != (undefined *)0x0;
          FUN_fffffff00a22aeac((ulong)(ppuVar20 + 1));
        }
        puVar19 = ppuVar10[0xb];
        ppuVar7 = ppuVar10 + 5;
        iVar4 = *(int *)ppuVar7;
        *(int *)ppuVar7 = iVar4 + 1;
        if (iVar4 + 0xf0000001U < 0xf0000002) goto LAB_fffffff00a31bd4c;
        uVar12 = FUN_fffffff00a22aeac((ulong)(ppuVar10 + 1));
        lVar2 = tpidr_el1;
        *(undefined8 *)(lVar2 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40((long)&local_e0);
          puVar8 = extraout_x1_00;
        }
        else {
          puVar8 = puStack_c8;
          if ((puStack_c8 != (uint *)0x0) &&
             (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
            FUN_fffffff00a346730(uVar12,puStack_c8);
            puVar8 = extraout_x1_01;
          }
        }
        param_1 = CONCAT44(uStack_84,uStack_88);
        local_d0 = 0;
        puStack_c8 = (uint *)0x0;
        uStack_b0._4_4_ = 0;
        uStack_a8 = 0;
        local_b4 = 0;
        uStack_b2 = 0;
        uStack_b0._0_4_ = 0;
        uStack_9c = 0;
        uStack_98 = 0;
        uStack_a4 = 0;
        uStack_a0 = 0;
        uStack_8c = 0;
        uStack_88 = 0;
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_7c = 0;
        local_78 = 0;
        uStack_84 = 0;
        local_80 = 0;
        uStack_74 = 0;
        if (bVar3) {
          ppuVar9 = (undefined **)(ulong)*(uint *)param_3;
          ppuVar11 = (undefined **)0x0;
          puVar13 = &DAT_00000010;
          FUN_fffffff00a30d23c
                    (ppuVar20,(ulong)(puVar19 +
                                     (long)param_2 + ((uVar17 & 0xfffffffffffff000) - lVar6)),
                     ppuVar9,0,0x10,(undefined **)0x1000000);
          puVar8 = extraout_x1_02;
        }
        if (ppuVar20 != (undefined **)0x0) {
          FUN_fffffff00a303950(ppuVar20,(long)puVar8,ppuVar9,ppuVar11,puVar13);
          puVar8 = extraout_x1_03;
        }
        FUN_fffffff00a303950(ppuVar10,(long)puVar8,ppuVar9,ppuVar11,puVar13);
        uVar5 = 1;
        goto LAB_fffffff00a31b2a0;
      }
LAB_fffffff00a31b414:
      ppuVar9 = (undefined **)(uVar23 & 0xfffffffffffffffc);
      if ((uVar23 & 3) != 0) {
        ppuVar9 = (undefined **)&DAT_fffffff00adbb300;
      }
      if (uVar18 != 0) {
        lVar6 = *(long *)(uVar17 + 0x10);
        uVar23 = *(ulong *)(uVar17 + 0x30);
        if (ppuVar9 != (undefined **)0x0) {
          FUN_fffffff00a306ebc((long)ppuVar9);
          ppuVar7 = ppuVar9 + 5;
          iVar4 = *(int *)ppuVar7;
          *(int *)ppuVar7 = iVar4 + 1;
          if (iVar4 + 0xf0000001U < 0xf0000002) {
LAB_fffffff00a31bd4c:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff00aa61ed0((uint *)ppuVar7);
          }
          uVar17 = FUN_fffffff00a22aeac((ulong)(ppuVar9 + 1));
        }
        lVar2 = tpidr_el1;
        *(undefined8 *)(lVar2 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40((long)&local_e0);
        }
        else if ((puStack_c8 != (uint *)0x0) &&
                (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
          FUN_fffffff00a346730(uVar17,puStack_c8);
        }
        param_1 = CONCAT44(uStack_84,uStack_88);
        local_d0 = 0;
        puStack_c8 = (uint *)0x0;
        uStack_b0._4_4_ = 0;
        uStack_a8 = 0;
        local_b4 = 0;
        uStack_b2 = 0;
        uStack_b0._0_4_ = 0;
        uStack_9c = 0;
        uStack_98 = 0;
        uStack_a4 = 0;
        uStack_a0 = 0;
        uStack_8c = 0;
        uStack_88 = 0;
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_7c = 0;
        local_78 = 0;
        uStack_84 = 0;
        local_80 = 0;
        uStack_74 = 0;
        ppuVar11 = (undefined **)(ulong)*(uint *)param_3;
        ppuVar10 = (undefined **)0x0;
        uVar12 = 0x10;
        FUN_fffffff00a30d23c
                  (ppuVar9,(long)param_2 + ((uVar23 & 0xfffffffffffff000) - lVar6),ppuVar11,0,0x10,
                   (undefined **)0x1000000);
        FUN_fffffff00a303950(ppuVar9,extraout_x1,ppuVar11,ppuVar10,uVar12);
        uVar18 = 0;
        goto LAB_fffffff00a31b2a0;
      }
      uVar23 = (ulong)(*(uint *)((long)ppuVar9 + 0x74) >> 0xd) & 1;
      *param_7 = uVar23;
      uVar16 = *(ulong *)(uVar17 + 0x28) & 3;
      ppuVar11 = (undefined **)(*(ulong *)(uVar17 + 0x28) & 0xfffffffffffffffc);
      ppuVar9 = ppuVar11;
      if (uVar16 != 0) {
        ppuVar9 = (undefined **)&DAT_fffffff00adbb300;
      }
      if (*(char *)((long)ppuVar9 + 0x76) < '\0') {
        *param_7 = uVar23 | 2;
        uVar16 = *(ulong *)(uVar17 + 0x28) & 3;
        ppuVar11 = (undefined **)(*(ulong *)(uVar17 + 0x28) & 0xfffffffffffffffc);
      }
      if (uVar16 != 0) {
        ppuVar11 = (undefined **)&DAT_fffffff00adbb300;
      }
      if ((*(byte *)(uVar17 + 0x38) >> 6 & 1) != 0) {
        DAT_fffffff00ad947dc = DAT_fffffff00ad947dc + 1;
      }
      uVar16 = *(ulong *)(uVar17 + 0x30);
      lVar6 = *(long *)(uVar17 + 0x10);
      FUN_fffffff00a3061bc((long)ppuVar11);
      if (((ppuVar11 != (undefined **)&DAT_fffffff00adbb300) &&
          (ppuVar11 != (undefined **)&DAT_fffffff00adbb400)) &&
         ((*(uint *)((long)ppuVar11 + 0x74) >> 0x17 & 1) == 0)) {
        *(uint *)((long)ppuVar11 + 0x74) = *(uint *)((long)ppuVar11 + 0x74) | 0x200000;
      }
      if (*(int *)(ppuVar11 + 5) + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa61ed0((uint *)(ppuVar11 + 5));
      }
      *(int *)(ppuVar11 + 5) = *(int *)(ppuVar11 + 5) + 1;
      uVar12 = FUN_fffffff00a22aeac((ulong)(ppuVar11 + 1));
      lVar2 = tpidr_el1;
      *(undefined8 *)(lVar2 + 0x228) = 0;
      if ((local_b4 & 0xc) == 8) {
        if (((byte)local_b8 >> 2 & 1) == 0) {
          local_e0 = CONCAT44(uStack_94,uStack_98);
        }
        else {
          uStack_b0 = CONCAT44(uStack_7c,local_80) + CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0)
          ;
          local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
        }
        puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
        local_d0 = CONCAT44(uStack_84,uStack_88);
        uStack_d8 = CONCAT44(uStack_8c,uStack_90);
        local_b4 = local_b4 & 0xfff3;
        local_80 = 0;
        uStack_7c = 0;
        local_78 = 0;
        uStack_74 = 0;
      }
      if ((local_b8 >> 2 & 1) == 0) {
        FUN_fffffff00a34ab40((long)&local_e0);
      }
      else if ((puStack_c8 != (uint *)0x0) &&
              (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
        FUN_fffffff00a346730(uVar12,puStack_c8);
      }
      local_d0 = 0;
      puStack_c8 = (uint *)0x0;
      uStack_b0._4_4_ = 0;
      uStack_a8 = 0;
      local_b4 = 0;
      uStack_b2 = 0;
      uStack_b0._0_4_ = 0;
      uStack_9c = 0;
      uStack_98 = 0;
      uStack_a4 = 0;
      uStack_a0 = 0;
      uStack_8c = 0;
      uStack_88 = 0;
      uStack_94 = 0;
      uStack_90 = 0;
      uStack_7c = 0;
      local_78 = 0;
      uStack_84 = 0;
      local_80 = 0;
      uStack_74 = 0;
      ppuVar9 = (undefined **)(ulong)*(uint *)param_3;
      uVar5 = FUN_fffffff00a31bd68
                        (ppuVar11,(long)param_2 + ((uVar16 & 0xfffffffffffff000) - lVar6),ppuVar9,
                         param_4,param_5,param_6,uVar21,param_8);
      uVar17 = (ulong)uVar5;
      FUN_fffffff00a303950(ppuVar11,extraout_x1_04,ppuVar9,param_4,param_5);
    }
    else {
      FUN_fffffff00a34b408(4,0,param_3);
      *param_7 = 0;
      if (param_1 == 0) {
        uVar5 = 0xe;
        uVar21 = 0xffffffffffffc000;
        uVar17 = 0x3fff;
      }
      else {
        uVar5 = (uint)*(byte *)(param_1 + 0x2c);
        uVar21 = -1L << ((ulong)*(byte *)(param_1 + 0x2c) & 0x3f);
        uVar17 = (ulong)~(uint)uVar21;
      }
      FUN_fffffff00a2299cc(param_1 + 0x30);
      uVar21 = uVar21 & (ulong)param_2;
      uVar16 = uVar17 + uVar16 & (long)(-1 << (ulong)(uVar5 & 0x1f));
      puVar19 = (undefined *)0x40015;
      uVar17 = FUN_fffffff00a347f10(&local_e0,param_1,uVar21,uVar16,(undefined *)0x40015);
      if ((int)uVar17 == 0) {
        local_6c[0] = 0;
        uVar21 = FUN_fffffff00a34a078(&local_e0,(int *)0x0,uVar21,uVar16,puVar19);
        puVar1 = (undefined4 *)(*(ulong *)(uVar21 + 0x28) & 0xfffffffffffffffc);
        if ((*(ulong *)(uVar21 + 0x28) & 3) != 0) {
          puVar1 = &DAT_fffffff00adbb300;
        }
        if (puVar1 != (undefined4 *)0x0) {
          uVar5 = puVar1[0x1d];
          if ((uVar5 >> 0xd & 1) != 0) {
            *param_7 = 1;
            uVar5 = puVar1[0x1d];
          }
          if ((uVar5 >> 0x17 & 1) != 0) {
            *param_7 = *param_7 | 2;
          }
        }
        lVar6 = tpidr_el1;
        *(undefined8 *)(lVar6 + 0x228) = 0;
        if ((local_b4 & 0xc) == 8) {
          if (((byte)local_b8 >> 2 & 1) == 0) {
            local_e0 = CONCAT44(uStack_94,uStack_98);
          }
          else {
            uStack_b0 = CONCAT44(uStack_7c,local_80) +
                        CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
            local_e0 = local_e0 + CONCAT44(uStack_7c,local_80);
          }
          puStack_c8 = (uint *)CONCAT44(uStack_74,local_78);
          local_d0 = CONCAT44(uStack_84,uStack_88);
          uStack_d8 = CONCAT44(uStack_8c,uStack_90);
          local_b4 = local_b4 & 0xfff3;
          local_80 = 0;
          uStack_7c = 0;
          local_78 = 0;
          uStack_74 = 0;
        }
        if ((local_b8 >> 2 & 1) == 0) {
          FUN_fffffff00a34ab40((long)&local_e0);
          uVar17 = 0;
        }
        else {
          if ((puStack_c8 != (uint *)0x0) &&
             (((~puStack_c8[10] & 3) != 0 || ((puStack_c8[9] & 1) == 0)))) {
            FUN_fffffff00a346730(uVar21,puStack_c8);
          }
          uVar17 = 0;
        }
      }
      else {
        lVar6 = tpidr_el1;
LAB_fffffff00a31bd58:
        *(undefined8 *)(lVar6 + 0x228) = 0;
      }
    }
  }
  else {
    uVar17 = 0x12;
  }
  return uVar17;
}

