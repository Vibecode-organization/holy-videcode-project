// FUN_fffffff00a3d6418 @ fffffff00a3d6418 size=3884
// CALLERS:
//   fffffff00afba14e ?
//   fffffff00a3d5134 FUN_fffffff00a3d4f98@fffffff00a3d4f98
// CALLS:
//   fffffff00a342370 FUN_fffffff00a342370
//   fffffff00a3d5b14 FUN_fffffff00a3d5b14
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a73e9bc FUN_fffffff00a73e9bc
//   fffffff00a31f634 FUN_fffffff00a31f634
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a42f200 FUN_fffffff00a42f200
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00a73e538 FUN_fffffff00a73e538
//   fffffff00a31924c FUN_fffffff00a31924c
//   fffffff00a73ed8c FUN_fffffff00a73ed8c
//   fffffff00a31f4ec FUN_fffffff00a31f4ec
//   fffffff00a73e14c FUN_fffffff00a73e14c
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0
//   fffffff00a73e62c FUN_fffffff00a73e62c
//   fffffff00a42fc94 FUN_fffffff00a42fc94
//   fffffff00a31f75c FUN_fffffff00a31f75c
//   fffffff00a3d7344 FUN_fffffff00a3d7344
//   fffffff00a269ce8 FUN_fffffff00a269ce8
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a3d1f10 FUN_fffffff00a3d1f10
//   fffffff00a31f960 FUN_fffffff00a31f960
//   fffffff00a3d5294 FUN_fffffff00a3d5294

/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff00a3d6418
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,uint *param_7,
                undefined **param_8,undefined *param_9,undefined *param_10,int *param_11,
                uint *param_12,uint param_13,long param_14,long param_15,uint param_16)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  byte bVar11;
  undefined4 *****pppppuVar12;
  undefined4 ***********pppppppppppuVar13;
  int iVar14;
  uint uVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long extraout_x1_02;
  long extraout_x1_03;
  long extraout_x1_04;
  long extraout_x1_05;
  long extraout_x1_06;
  long extraout_x1_07;
  long extraout_x1_08;
  long extraout_x1_09;
  long extraout_x1_10;
  long extraout_x1_11;
  long extraout_x1_12;
  long extraout_x1_13;
  long extraout_x1_14;
  long extraout_x1_15;
  undefined **ppuVar19;
  undefined4 ******ppppppuVar20;
  undefined4 ***********pppppppppppuVar21;
  undefined4 ***********pppppppppppuVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  ulong uVar26;
  undefined *puVar27;
  int *piVar28;
  undefined4 *****pppppuVar29;
  uint uVar30;
  long lVar31;
  long lVar32;
  undefined4 ***********pppppppppppuVar33;
  uint *puVar34;
  uint uVar35;
  undefined4 ***********pppppppppppuVar36;
  uint in_wzr;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined1 auVar37 [16];
  ulong *local_170;
  uint local_13c;
  undefined4 ***********local_130;
  uint local_104;
  undefined4 *****local_f0;
  undefined4 ***********local_e0;
  undefined *local_d8;
  uint local_b4;
  int local_a4;
  uint local_a0;
  undefined4 uStack_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 local_80 [8];
  undefined4 *****local_78;
  undefined4 **********local_70 [2];
  
  local_80 = (undefined1  [8])0x0;
  local_78 = (undefined4 *****)0x0;
  iVar7 = *(int *)((long)param_8 + 0x14);
  puVar34 = param_7 + 0x36;
  lVar31 = *(long *)puVar34;
  uVar23 = *(uint *)(lVar31 + 0x90c);
  if (0xfff < uVar23) {
    uVar23 = 0x1000;
  }
  uVar5 = uVar23 << 0xe;
  if (*(uint *)(lVar31 + 0x904) <= uVar23 << 0xe) {
    uVar5 = *(uint *)(lVar31 + 0x904);
  }
  if (uVar5 < 0x100001) {
    uVar5 = 0x100000;
  }
  uVar23 = 0x160c;
  if ((param_13 & 0x4000) != 0) {
    uVar23 = 0x360c;
  }
  local_90 = 0;
  local_88 = 0;
  local_a0 = DAT_fffffff00ad22068 & 0xffffff | 0x22000000;
  uStack_9c = 0;
  local_98 = 0;
  DAT_fffffff00ad22074 = DAT_fffffff00ad22074 + 1;
  if (((int)DAT_fffffff00ad22068 < 0) &&
     (iVar14 = DAT_fffffff00ad22064 + 1, uVar2 = DAT_fffffff00ad22064 + 0xf0000001,
     DAT_fffffff00ad22064 = iVar14, uVar2 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0((uint *)&DAT_fffffff00ad22064);
  }
  uVar23 = param_13 >> 6 & 0x10000 | (param_13 >> 0xb & 1) << 0x12 | uVar23;
  uVar8 = *(uint *)(lVar31 + 0x918);
  iVar14 = *(int *)(lVar31 + 0x91c);
  uVar2 = uVar23 | 0x80000;
  if (0x3fff < param_16) {
    uVar2 = uVar23;
  }
  if (iVar7 < 2) {
    local_170 = (ulong *)0x0;
  }
  else {
    local_170 = FUN_fffffff00a73e62c((ulong *)param_8);
    param_1 = extraout_q0;
  }
  local_104 = 0;
  local_b4 = 0;
  local_e0 = (undefined4 ***********)0x0;
  local_130 = (undefined4 ***********)0x0;
  local_a4 = 0;
  local_f0 = (undefined4 *****)0x0;
  uVar24 = iVar14 - 1;
  uVar23 = 0x3fff;
  if (uVar24 != 0) {
    uVar23 = uVar24;
  }
  uVar24 = 2;
  if (param_14 != 0) {
    uVar24 = 6;
  }
  bVar4 = true;
  local_d8 = param_9;
  do {
    uVar35 = *param_12;
    if (*(int *)((long)param_8 + 0x14) < 1) {
      uVar26 = 0;
    }
    else {
      uVar26 = *(ulong *)*param_8;
    }
    if (((param_16 - 1 & *(uint *)(param_8 + 3)) != 0 || (uVar8 & (uint)uVar26) != 0) ||
        (uVar26 & uVar23) != 0) goto LAB_fffffff00a3d707c;
    lVar31 = tpidr_el1;
    lVar16 = FUN_fffffff00a29bafc(lVar31);
    param_1 = FUN_fffffff00a269ce8(lVar16,uVar35 & 0xffffc000,1,(long)param_7);
    if (uVar35 < param_16) {
      uVar26 = 0;
      bVar10 = bVar4;
    }
    else {
      uVar26 = 0;
      puVar27 = param_8[3];
      do {
        bVar10 = bVar4;
        if (((int)uVar26 != 0) || ((long)param_10 <= (long)puVar27)) break;
        if (*(long *)puVar34 == 0) {
          iVar14 = FUN_fffffff00a42f200(uVar26,0);
          param_1 = extraout_q0_02;
          if (iVar14 == 0) goto LAB_fffffff00a3d67d8;
LAB_fffffff00a3d67ac:
          lVar16 = *(long *)puVar34;
          if (lVar16 == 0) {
            lVar32 = 0;
            piVar28 = piRam00000000000009f8;
            if (piRam00000000000009f8 != (int *)0x0) goto LAB_fffffff00a3d67f8;
LAB_fffffff00a3d6808:
            uVar15 = *(uint *)(lVar32 + 0x74) >> 0x17 & 1;
          }
          else {
            piVar28 = *(int **)(lVar16 + 0x9f8);
            lVar32 = lVar16;
            if (*(int **)(lVar16 + 0x9f8) == (int *)0x0) goto LAB_fffffff00a3d6808;
LAB_fffffff00a3d67f8:
            if (*piVar28 == 0) goto LAB_fffffff00a3d6808;
            uVar15 = piVar28[8];
          }
          uVar15 = (*(int *)(lVar16 + 0x924) << (uVar15 != 0)) * DAT_fffffff00ad1045c;
          if (0xfffff < uVar15) {
            uVar15 = 0x100000;
          }
          local_13c = uVar15;
          if (((param_13 >> 0x12 & 1) != 0) && (iVar14 == 2)) {
            param_1 = FUN_fffffff00a42fc94(param_1,param_2,param_3,param_4,param_5,param_6,lVar16);
            uVar15 = 0;
            bVar11 = 1;
            goto joined_r0xfffffff00a3d6fec;
          }
        }
        else {
          iVar14 = FUN_fffffff00a42f200(uVar26,*(long *)puVar34);
          param_1 = extraout_q0_01;
          if (iVar14 != 0) goto LAB_fffffff00a3d67ac;
LAB_fffffff00a3d67d8:
          local_13c = 0x8000000;
          uVar15 = uVar5 & 0x7ffc000;
        }
        if (((bVar4) && (uVar26 = *(ulong *)(*(long *)(param_7 + 0x1e) + 0x38), uVar26 != 0)) &&
           (*(int *)(uVar26 + 0x30) != 0)) {
          puVar1 = (ulong *)(uVar26 + 8);
          if (*puVar1 == 0) {
            *puVar1 = (ulong)*(uint *)(lVar31 + 0x4e8);
          }
          else {
            FUN_fffffff00a2262d4(uVar26,lVar31,(undefined **)0x0);
          }
          FUN_fffffff00a3d7344
                    (uVar26,param_7,(long)param_10,uVar24,0,param_14,param_15,(int *)0x0,0,
                     (long *)0x0);
          if (*(uint *)puVar1 == *(uint *)(lVar31 + 0x4e8)) {
            *(uint *)puVar1 = in_wzr;
            param_1 = extraout_q0_03;
          }
          else {
            param_1 = FUN_fffffff00a226e08(uVar26,lVar31,*(uint *)puVar1);
          }
        }
        if (*(int *)((long)param_8 + 0x14) < 1) {
          uVar26 = 0;
        }
        else {
          uVar26 = *(ulong *)*param_8;
        }
        uVar9 = uVar35 & -param_16;
        if (uVar15 <= (uVar35 & -param_16)) {
          uVar9 = uVar15;
        }
        pppppppppppuVar36 = (undefined4 ***********)(uVar26 & 0x3fff);
        if (1 < iVar7) {
          uVar15 = 0;
          if ((pppppppppppuVar36 == (undefined4 ***********)0x0) || (local_a4 == 0))
          goto LAB_fffffff00a3d69e0;
          FUN_fffffff00a31f75c(param_1,param_2,param_3,param_4,param_5,param_6,(long)local_f0);
          pppppppppppuVar22 = (undefined4 ***********)(ulong)local_b4;
          pppppppppppuVar21 = local_130;
          uVar15 = FUN_fffffff00a3d1f10
                             (param_7,local_f0,local_e0,local_130,pppppppppppuVar22,(ulong)uVar2,
                              (undefined4 ***********)0x0,(ulong)&local_a0,param_14,param_15);
          if (uVar15 != 0x2d) {
            local_104 = 0;
            local_b4 = 0;
            local_e0 = (undefined4 ***********)0x0;
            local_a4 = 0;
            param_1 = extraout_q0_04;
            goto LAB_fffffff00a3d69e0;
          }
          local_a4 = 1;
          lVar16 = extraout_x1_00;
          goto LAB_fffffff00a3d70a4;
        }
        uVar15 = 0;
LAB_fffffff00a3d69e0:
        uVar3 = uVar9 + (int)pppppppppppuVar36 + 0x3fff;
        uVar18 = DAT_fffffff007c678d8;
        if (((1 << (ulong)(*(uint *)(param_8 + 4) & 0x1f) & 0x121U) != 0) &&
           (uVar18 = *(ulong *)(lVar31 + 0x418), *(ulong *)(lVar31 + 0x418) == 0)) {
          local_80 = (undefined1  [8])(((ulong)uVar3 & 0xffffc000) << 0x20);
          goto joined_r0xfffffff00a3d7034;
        }
        local_80 = (undefined1  [8])(((ulong)uVar3 & 0xffffc000) << 0x20);
        if (uVar18 == 0) goto joined_r0xfffffff00a3d7034;
        local_70[0] = (undefined4 **********)0x164d;
        ppuVar19 = (undefined **)(local_80 + 4);
        ppppppuVar20 = &local_78;
        pppppppppppuVar22 = (undefined4 ***********)0x0;
        uVar17 = FUN_fffffff00a31b1b8
                           (uVar18,(undefined8 *)(uVar26 & 0xffffffffffffc000),ppuVar19,
                            (undefined **)ppppppuVar20,(uint *)0x0,(uint *)local_80,
                            (ulong *)local_70,0x14);
        pppppuVar12 = local_78;
        param_1 = extraout_q0_05;
        if ((int)uVar17 != 0) goto joined_r0xfffffff00a3d7034;
        lVar16 = extraout_x1_01;
        if (((uint)local_70[0] >> 1 & 1) != 0) {
LAB_fffffff00a3d6ef4:
          pppppuVar12 = local_78;
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar16 = extraout_x1_09;
          }
          FUN_fffffff00a31924c
                    ((undefined4 *)pppppuVar12,lVar16,ppuVar19,(undefined **)ppppppuVar20,
                     pppppppppppuVar22);
          bVar11 = 0;
          local_78 = (undefined4 *****)0x0;
          uVar15 = 0x16;
          goto LAB_fffffff00a3d71a4;
        }
        if (local_78[8] == (undefined4 ****)0x0) {
          pppppuVar29 = local_78 + 0x12;
        }
        else {
          pppppuVar29 = (undefined4 *****)local_78[8][4];
        }
        local_80._0_4_ = (uint)local_80._4_4_ >> 0xe;
        auVar37 = extraout_q0_05;
        uVar25 = local_80._4_4_;
        if ((uint)local_80._4_4_ < 0x4000) {
          uVar30 = 0;
LAB_fffffff00a3d6aa4:
          if (uVar30 == local_80._0_4_) goto LAB_fffffff00a3d6c2c;
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar16 = extraout_x1_02;
          }
          FUN_fffffff00a31924c
                    ((undefined4 *)pppppuVar12,lVar16,ppuVar19,(undefined **)ppppppuVar20,
                     pppppppppppuVar22);
          local_80 = (undefined1  [8])(((ulong)uVar3 & 0xffffc000) << 0x20);
          local_78 = (undefined4 *****)0x0;
          local_70[0] = (undefined4 **********)0x964d;
          ppuVar19 = (undefined **)(local_80 + 4);
          ppppppuVar20 = &local_78;
          pppppppppppuVar22 = (undefined4 ***********)0x0;
          uVar17 = FUN_fffffff00a31b1b8
                             (uVar18,(undefined8 *)(uVar26 & 0xffffffffffffc000),ppuVar19,
                              (undefined **)ppppppuVar20,(uint *)0x0,(uint *)local_80,
                              (ulong *)local_70,0x14);
          pppppuVar12 = local_78;
          param_1 = extraout_q0_06;
          if ((int)uVar17 != 0) goto joined_r0xfffffff00a3d7034;
          lVar16 = extraout_x1_03;
          if (((uint)local_70[0] >> 1 & 1) != 0) goto LAB_fffffff00a3d6ef4;
          if (local_78[8] == (undefined4 ****)0x0) {
            pppppuVar29 = local_78 + 0x12;
          }
          else {
            pppppuVar29 = (undefined4 *****)local_78[8][4];
          }
          local_80._0_4_ = (uint)local_80._4_4_ >> 0xe;
          auVar37 = extraout_q0_06;
          uVar25 = local_80._4_4_;
          if (0x3fff < (uint)local_80._4_4_) {
            uVar17 = 0;
            do {
              uVar30 = (uint)uVar17;
              if ((*(int *)(pppppuVar29 + uVar17) == 0) ||
                 ((*(byte *)((long)(pppppuVar29 + uVar17) + 4) >> 1 & 1) != 0))
              goto LAB_fffffff00a3d6b64;
              uVar17 = (ulong)(uVar30 + 1);
            } while (local_80._0_4_ != uVar30 + 1);
            goto LAB_fffffff00a3d6c2c;
          }
          uVar30 = 0;
LAB_fffffff00a3d6b64:
          if (uVar30 == local_80._0_4_) goto LAB_fffffff00a3d6c2c;
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar16 = extraout_x1_04;
          }
          FUN_fffffff00a31924c
                    ((undefined4 *)pppppuVar12,lVar16,ppuVar19,(undefined **)ppppppuVar20,
                     pppppppppppuVar22);
          local_80 = (undefined1  [8])(((ulong)uVar3 & 0xffffc000) << 0x20);
          local_78 = (undefined4 *****)0x0;
          local_70[0] = (undefined4 **********)0x964d;
          ppuVar19 = (undefined **)(local_80 + 4);
          ppppppuVar20 = &local_78;
          pppppppppppuVar22 = (undefined4 ***********)0x0;
          uVar18 = FUN_fffffff00a31b1b8
                             (uVar18,(undefined8 *)(uVar26 & 0xffffffffffffc000),ppuVar19,
                              (undefined **)ppppppuVar20,(uint *)0x0,(uint *)local_80,
                              (ulong *)local_70,0x14);
          pppppuVar12 = local_78;
          param_1 = extraout_q0_07;
          if ((int)uVar18 != 0) goto joined_r0xfffffff00a3d7034;
          lVar16 = extraout_x1_05;
          if (((uint)local_70[0] >> 1 & 1) != 0) goto LAB_fffffff00a3d6ef4;
          if (local_78[8] == (undefined4 ****)0x0) {
            pppppuVar29 = local_78 + 0x12;
          }
          else {
            pppppuVar29 = (undefined4 *****)local_78[8][4];
          }
          local_80._0_4_ = (uint)local_80._4_4_ >> 0xe;
          auVar37 = extraout_q0_07;
          uVar25 = local_80._4_4_;
          if (0x3fff < (uint)local_80._4_4_) {
            uVar18 = 0;
            do {
              uVar30 = (uint)uVar18;
              if ((*(int *)(pppppuVar29 + uVar18) == 0) ||
                 ((*(byte *)((long)(pppppuVar29 + uVar18) + 4) >> 1 & 1) != 0))
              goto LAB_fffffff00a3d6c24;
              uVar18 = (ulong)(uVar30 + 1);
            } while (local_80._0_4_ != uVar30 + 1);
            goto LAB_fffffff00a3d6c2c;
          }
          uVar30 = 0;
LAB_fffffff00a3d6c24:
          if (uVar30 == local_80._0_4_) goto LAB_fffffff00a3d6c2c;
          lVar31 = extraout_x1_05;
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar31 = extraout_x1_15;
          }
          param_1 = FUN_fffffff00a31924c
                              ((undefined4 *)pppppuVar12,lVar31,ppuVar19,(undefined **)ppppppuVar20,
                               pppppppppppuVar22);
LAB_fffffff00a3d6fe4:
          bVar11 = 0;
          local_78 = (undefined4 *****)0x0;
          goto joined_r0xfffffff00a3d6fec;
        }
        uVar17 = 0;
        do {
          uVar30 = (uint)uVar17;
          if ((*(int *)(pppppuVar29 + uVar17) == 0) ||
             ((*(byte *)((long)(pppppuVar29 + uVar17) + 4) >> 1 & 1) != 0))
          goto LAB_fffffff00a3d6aa4;
          uVar17 = (ulong)(uVar30 + 1);
        } while (local_80._0_4_ != uVar30 + 1);
LAB_fffffff00a3d6c2c:
        pppppuVar12 = local_78;
        uVar30 = uVar25;
        if (pppppppppppuVar36 != (undefined4 ***********)0x0 || uVar25 == 0) {
          uVar30 = 0;
        }
        if ((uVar3 & 0xffffc000) <= uVar25) {
          uVar30 = uVar9;
        }
        pppppppppppuVar33 = (undefined4 ***********)(ulong)uVar30;
        if (uVar30 == 0) {
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar16 = extraout_x1_10;
          }
          param_1 = FUN_fffffff00a31924c
                              ((undefined4 *)pppppuVar12,lVar16,ppuVar19,(undefined **)ppppppuVar20,
                               pppppppppppuVar22);
          goto LAB_fffffff00a3d6fe4;
        }
        uVar9 = *(uint *)(*(long *)puVar34 + 0x92c);
        uVar18 = (ulong)uVar9;
        if (uVar9 == 0) {
          uVar18 = (ulong)(uVar5 & 0x7ffc000) *
                   (ulong)(uint)(*(int *)(*(long *)puVar34 + 0x924) << 1);
          if (((uVar18 & 0xffffffff00000000) != 0) || (DAT_fffffff00ad10458 < (uint)uVar18)) {
            uVar18 = (ulong)DAT_fffffff00ad10458;
          }
        }
        uVar17 = (ulong)*(uint *)(lVar31 + 0x4e8);
        if (local_98 != 0) {
          auVar37 = FUN_fffffff00a2262d4((ulong)&local_a0,lVar31,(undefined **)0x0);
          uVar17 = local_98;
        }
        local_98 = uVar17;
        uVar9 = local_90._4_4_ - (int)local_90;
        uVar17 = local_98;
        while (local_98 = uVar17, (uint)uVar18 < uVar9) {
          local_88 = CONCAT44(1,(uint)local_88);
          ppppppuVar20 = (undefined4 ******)0x0;
          pppppppppppuVar22 = (undefined4 ***********)0x0;
          FUN_fffffff00a73ed8c
                    ((uint *)((long)&local_88 + 4),0x11,"cluster_write_direct",0,0,(ulong)&local_a0)
          ;
          auVar37 = extraout_q0_08;
          uVar17 = local_98;
          uVar9 = local_90._4_4_ - (int)local_90;
        }
        local_98._0_4_ = (uint)uVar17;
        uVar9 = (uint)local_98;
        bVar4 = (uint)local_98 == *(uint *)(lVar31 + 0x4e8);
        if (bVar4) {
          local_98._4_4_ = (undefined4)(uVar17 >> 0x20);
          local_98 = CONCAT44(local_98._4_4_,in_wzr);
        }
        ppuVar19 = (undefined **)(uVar17 & 0xffffffff);
        lVar16 = lVar31;
        if (uVar9 != *(uint *)(lVar31 + 0x4e8)) {
          auVar37 = FUN_fffffff00a226e08((ulong)&local_a0,lVar31,uVar9);
          lVar16 = extraout_x1_08;
        }
        pppppuVar12 = local_78;
        if ((uint)local_88 != 0) {
          if (local_78 != (undefined4 *****)0x0) {
            ppuVar19 = (undefined **)(ulong)*(uint *)(local_78 + 5);
            pppppppppppuVar22 = local_70;
            ppppppuVar20 = (undefined4 ******)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)local_78,0,ppuVar19,(undefined **)0x0,(uint *)pppppppppppuVar22
                      );
            lVar16 = extraout_x1_11;
          }
          param_1 = FUN_fffffff00a31924c
                              ((undefined4 *)pppppuVar12,lVar16,ppuVar19,(undefined **)ppppppuVar20,
                               pppppppppppuVar22);
          goto LAB_fffffff00a3d6fe4;
        }
        if (iVar7 < 2) {
          pppppppppppuVar21 = (undefined4 ***********)param_8[3];
          pppppppppppuVar22 = pppppppppppuVar33;
          uVar15 = FUN_fffffff00a3d1f10
                             (param_7,local_78,pppppppppppuVar36,pppppppppppuVar21,pppppppppppuVar33
                              ,(ulong)uVar2,(undefined4 ***********)0x0,(ulong)&local_a0,param_14,
                              param_15);
          lVar16 = extraout_x1;
          pppppppppppuVar13 = local_e0;
joined_r0xfffffff00a3d6734:
          local_e0 = pppppppppppuVar36;
          if (uVar15 == 0x2d) goto LAB_fffffff00a3d70a4;
        }
        else {
          if (local_a4 == 0) {
            auVar37 = FUN_fffffff00a31f4ec
                                (auVar37,param_2,param_3,param_4,param_5,param_6,pppppppppppuVar36,
                                 (ulong)*(uint *)((long)param_8 + 0x14));
            local_f0 = auVar37._0_8_;
            local_130 = (undefined4 ***********)param_8[3];
            local_e0 = pppppppppppuVar36;
          }
          FUN_fffffff00a31f634((long)local_f0,(long)local_78,local_80._4_4_);
          pppppppppppuVar36 = (undefined4 ***********)(ulong)local_104;
          pppppppppppuVar21 = (undefined4 ***********)(ulong)(uint)local_80._4_4_;
          auVar37 = FUN_fffffff00a31f960
                              (extraout_q0_09,param_2,param_3,param_4,param_5,param_6,(long)local_f0
                               ,(long)local_78,local_104,local_80._4_4_);
          local_a4 = local_a4 + 1;
          local_b4 = uVar30 + local_b4;
          if (((int)uVar26 + uVar30 & 0x3fff) == 0) {
            if ((local_f0 == (undefined4 *****)0x0) ||
               ((*(byte *)((long)local_f0 + 0x19) >> 6 & 1) == 0)) {
              iVar14 = 0;
            }
            else {
              iVar14 = 0;
              if (local_f0[8] != (undefined4 ****)0x0) {
                iVar14 = *(int *)((long)local_f0[8] + 0xc);
              }
            }
            if (local_a4 != iVar14) {
              local_104 = local_80._4_4_ + local_104;
              lVar16 = extraout_x1_06;
              pppppppppppuVar13 = local_e0;
              if (local_104 < local_13c) goto joined_r0xfffffff00a3d6734;
            }
          }
          FUN_fffffff00a31f75c(auVar37,param_2,param_3,param_4,param_5,param_6,(long)local_f0);
          pppppppppppuVar22 = (undefined4 ***********)(ulong)local_b4;
          pppppppppppuVar21 = local_130;
          uVar15 = FUN_fffffff00a3d1f10
                             (param_7,local_f0,local_e0,local_130,pppppppppppuVar22,(ulong)uVar2,
                              (undefined4 ***********)0x0,(ulong)&local_a0,param_14,param_15);
          lVar16 = extraout_x1_07;
          if (uVar15 == 0x2d) {
LAB_fffffff00a3d70a4:
            if (local_170 != (ulong *)0x0) {
              FUN_fffffff00a73e9bc((ulong *)param_8,local_170);
              FUN_fffffff00a73e14c(local_170);
              lVar16 = extraout_x1_12;
            }
            pppppuVar12 = local_78;
            if (local_a4 == 0) {
              if (local_78 != (undefined4 *****)0x0) {
                local_e0 = (undefined4 ***********)(ulong)*(uint *)(local_78 + 5);
                pppppppppppuVar22 = local_70;
                pppppppppppuVar21 = (undefined4 ***********)0x0;
                FUN_fffffff00a342370
                          ((undefined4 *)local_78,0,(undefined **)local_e0,(undefined **)0x0,
                           (uint *)pppppppppppuVar22);
                lVar16 = extraout_x1_14;
              }
              FUN_fffffff00a31924c
                        ((undefined4 *)pppppuVar12,lVar16,local_e0,(undefined **)pppppppppppuVar21,
                         pppppppppppuVar22);
              bVar11 = 0;
              local_170 = (ulong *)0x0;
              local_78 = (undefined4 *****)0x0;
              uVar15 = 0x2d;
            }
            else {
              if (local_f0 != (undefined4 *****)0x0) {
                local_e0 = (undefined4 ***********)(ulong)*(uint *)(local_f0 + 5);
                pppppppppppuVar22 = local_70;
                pppppppppppuVar21 = (undefined4 ***********)0x0;
                FUN_fffffff00a342370
                          ((undefined4 *)local_f0,0,(undefined **)local_e0,(undefined **)0x0,
                           (uint *)pppppppppppuVar22);
                lVar16 = extraout_x1_13;
              }
              FUN_fffffff00a31924c
                        ((undefined4 *)local_f0,lVar16,local_e0,(undefined **)pppppppppppuVar21,
                         pppppppppppuVar22);
              bVar11 = 0;
              local_170 = (ulong *)0x0;
              uVar15 = 0x2d;
            }
            goto LAB_fffffff00a3d71a4;
          }
          local_a4 = 0;
          local_e0 = (undefined4 ***********)0x0;
          local_b4 = 0;
          local_104 = 0;
          pppppppppppuVar13 = local_e0;
        }
        local_e0 = pppppppppppuVar13;
        uVar26 = (ulong)uVar15;
        param_1 = FUN_fffffff00a73e538((long *)param_8,(ulong)pppppppppppuVar33);
        bVar4 = false;
        puVar27 = param_8[3];
        puVar6 = puVar27;
        if ((long)puVar27 <= (long)local_d8) {
          puVar6 = local_d8;
        }
        uVar35 = uVar35 - uVar30;
        bVar10 = false;
        local_d8 = puVar6;
      } while (param_16 <= uVar35);
    }
    uVar15 = (uint)uVar26;
    if ((uVar15 != 0 || uVar35 != 0) || (uint)local_88 != 0) {
      bVar11 = 0;
      goto joined_r0xfffffff00a3d6fec;
    }
    uVar15 = FUN_fffffff00a3d5b14
                       ((long)param_7,(long *)param_8,param_11,(int *)param_12,(ulong)param_16);
    param_1 = extraout_q0_00;
    if (uVar15 != 0) {
      uVar35 = 0;
      goto joined_r0xfffffff00a3d7034;
    }
    bVar4 = bVar10;
  } while (*param_11 == 1);
  uVar35 = 0;
LAB_fffffff00a3d707c:
  uVar15 = 0;
joined_r0xfffffff00a3d7034:
  bVar11 = 0;
joined_r0xfffffff00a3d6fec:
  if (uVar15 == 0) {
    if ((((uint)local_88 == 0) && (1 < iVar7)) && (local_a4 != 0)) {
      FUN_fffffff00a31f75c(param_1,param_2,param_3,param_4,param_5,param_6,(long)local_f0);
      uVar15 = FUN_fffffff00a3d1f10
                         (param_7,local_f0,local_e0,local_130,
                          (undefined4 ***********)(ulong)local_b4,(ulong)uVar2,
                          (undefined4 ***********)0x0,(ulong)&local_a0,param_14,param_15);
    }
  }
LAB_fffffff00a3d71a4:
  lVar31 = tpidr_el1;
  uVar26 = (ulong)*(uint *)(lVar31 + 0x4e8);
  if (local_98 != 0) {
    FUN_fffffff00a2262d4((ulong)&local_a0,lVar31,(undefined **)0x0);
    uVar26 = local_98;
  }
  local_98 = uVar26;
  if (local_90._4_4_ != (int)local_90) {
    do {
      local_88 = CONCAT44(1,(uint)local_88);
      FUN_fffffff00a73ed8c
                ((uint *)((long)&local_88 + 4),0x11,"cluster_write_direct",0,0,(ulong)&local_a0);
    } while (local_90._4_4_ != (int)local_90);
  }
  if ((uint)local_98 == *(uint *)(lVar31 + 0x4e8)) {
    local_98 = CONCAT44(local_98._4_4_,in_wzr);
  }
  else {
    FUN_fffffff00a226e08((ulong)&local_a0,lVar31,(uint)local_98);
  }
  if ((uint)local_88 != 0) {
    uVar15 = (uint)local_88;
  }
  auVar37 = FUN_fffffff00a2261c0(&local_a0,&DAT_fffffff00ad22064);
  uVar23 = 0x23;
  if (!(bool)(bVar11 & uVar15 == 0)) {
    uVar23 = uVar15;
  }
  uVar26 = (ulong)uVar23;
  if ((uVar35 != 0) && (uVar23 == 0)) {
    puVar27 = param_8[3];
    if ((long)param_8[3] <= (long)local_d8) {
      puVar27 = local_d8;
    }
    uVar26 = FUN_fffffff00a3d5294
                       (auVar37,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar35,
                        (long)puVar27,param_10,(undefined *)0x0,0,param_13,param_14,param_15);
    *param_11 = 0;
  }
  if (local_170 != (ulong *)0x0) {
    FUN_fffffff00a73e14c(local_170);
  }
  return uVar26;
}

