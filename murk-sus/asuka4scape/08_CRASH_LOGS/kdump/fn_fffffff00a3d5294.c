// FUN_fffffff00a3d5294 @ fffffff00a3d5294 size=2176
// CALLERS:
//   fffffff00afba148 ?
//   fffffff00a3d519c FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d51d8 FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d524c FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d5270 FUN_fffffff00a3d4f98@fffffff00a3d4f98
//   fffffff00a3d72a0 FUN_fffffff00a3d6418@fffffff00a3d6418
// CALLS:
//   fffffff00a3d7f48 FUN_fffffff00a3d7f48
//   fffffff00a786a78 FUN_fffffff00a786a78
//   fffffff00a342370 FUN_fffffff00a342370
//   fffffff00a3d934c FUN_fffffff00a3d934c
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a3d1f10 FUN_fffffff00a3d1f10
//   fffffff00a31924c FUN_fffffff00a31924c
//   fffffff00a3d90f8 FUN_fffffff00a3d90f8
//   fffffff00a3d1c38 FUN_fffffff00a3d1c38
//   fffffff00a3d8fc4 FUN_fffffff00a3d8fc4
//   fffffff00a342c94 FUN_fffffff00a342c94
//   fffffff00a7868c4 FUN_fffffff00a7868c4

/* WARNING: Removing unreachable block (ram,0xfffffff00a3d57d4) */
/* WARNING: Type propagation algorithm not settling */

ulong FUN_fffffff00a3d5294
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,uint *param_7,
                undefined **param_8,uint param_9,long param_10,undefined *param_11,
                undefined *param_12,long param_13,uint param_14,undefined8 param_15,long param_16)

{
  uint uVar1;
  uint uVar2;
  undefined4 *****pppppuVar3;
  undefined4 **********ppppppppppuVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long extraout_x1_02;
  undefined **ppuVar8;
  byte bVar9;
  undefined4 ***********pppppppppppuVar10;
  undefined4 *****pppppuVar11;
  uint *puVar12;
  undefined **ppuVar13;
  int *piVar14;
  uint uVar15;
  undefined *puVar16;
  undefined **ppuVar17;
  undefined **ppuVar18;
  undefined *puVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  undefined **ppuVar24;
  ulong uVar25;
  ulong uVar26;
  undefined4 ***********pppppppppppuVar27;
  ulong uVar28;
  undefined4 ***********pppppppppppuVar29;
  ulong uVar30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar31 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  int local_114;
  undefined *local_110;
  uint local_c0;
  uint local_bc;
  uint local_9c;
  ulong local_98;
  ulong local_90;
  int local_88;
  uint local_84;
  undefined4 *****local_80;
  undefined4 **********local_78;
  undefined4 **********local_6c;
  
  local_78 = (undefined4 **********)0x0;
  local_88 = 0;
  local_c0 = 0;
  if (param_8 != (undefined **)0x0) {
    local_c0 = param_9;
  }
  uVar20 = *(uint *)(*(long *)(param_7 + 0x36) + 0x90c);
  uVar2 = *(uint *)(*(long *)(param_7 + 0x36) + 0x904);
  if (0xfff < uVar20) {
    uVar20 = 0x1000;
  }
  uVar1 = uVar20 << 0xe;
  if (uVar2 <= uVar20 << 0xe) {
    uVar1 = uVar2;
  }
  if (uVar1 < 0x100001) {
    uVar1 = 0x100000;
  }
  uVar20 = param_14;
  if ((param_14 >> 7 & 1) == 0) {
    if (param_8 == (undefined **)0x0) {
      uVar25 = 0;
      param_12 = (undefined *)0x0;
      goto joined_r0xfffffff00a3d53c0;
    }
    puVar16 = param_8[3];
    uVar2 = param_14;
    uVar26 = 0;
    if (param_10 <= (long)((ulong)puVar16 & 0xffffffffffffc000)) {
      uVar2 = param_14 | 0x80;
      uVar26 = (ulong)puVar16 & 0x3fff;
    }
    uVar25 = 0;
    if (param_10 < (long)puVar16) {
      uVar20 = uVar2;
      uVar25 = uVar26;
    }
    param_12 = (undefined *)0x0;
    if (param_10 < (long)puVar16) {
      param_12 = (undefined *)((ulong)puVar16 & 0xffffffffffffc000);
    }
    if ((uVar20 >> 6 & 1) == 0) goto LAB_fffffff00a3d53c4;
LAB_fffffff00a3d5354:
    if (param_8 == (undefined **)0x0) {
      if (uVar25 == 0) {
        return 0;
      }
      local_114 = 0;
      uVar26 = 0;
      puVar16 = (undefined *)0x0;
      local_110 = (undefined *)0x0;
      goto LAB_fffffff00a3d5454;
    }
    local_110 = param_8[3];
    puVar16 = local_110 + param_9;
    uVar26 = param_13 - (long)puVar16;
    if (uVar26 == 0 || param_13 < (long)puVar16) {
      uVar26 = 0;
    }
  }
  else {
    if (param_8 == (undefined **)0x0) {
      uVar25 = (long)param_11 - (long)param_12;
      puVar16 = param_11;
    }
    else {
      uVar25 = (long)param_8[3] - (long)param_12;
      puVar16 = param_8[3];
    }
    if (uVar25 == 0 || (long)uVar25 < 0 != SBORROW8((long)puVar16,(long)param_12)) {
      uVar25 = 0;
      param_12 = (undefined *)0x0;
    }
joined_r0xfffffff00a3d53c0:
    if ((param_14 >> 6 & 1) != 0) goto LAB_fffffff00a3d5354;
LAB_fffffff00a3d53c4:
    if ((param_8 == (undefined **)0x0) || ((long)param_11 <= param_10)) {
      if ((param_8 == (undefined **)0x0) && (uVar25 == 0)) {
        return 0;
      }
      uVar26 = 0;
      puVar16 = (undefined *)0x0;
      if (param_8 == (undefined **)0x0) {
        local_110 = (undefined *)0x0;
        local_114 = 0;
        goto LAB_fffffff00a3d5454;
      }
      local_110 = param_8[3];
    }
    else {
      local_110 = param_8[3];
      if (local_110 + param_9 == param_11) {
        puVar16 = param_11;
        if (((ulong)param_11 & 0x3fff) == 0) {
          uVar26 = 0;
        }
        else {
          uVar26 = 0x4000 - ((ulong)param_11 & 0x3fff);
          uVar20 = uVar20 | 0x40;
        }
      }
      else {
        uVar26 = 0;
        puVar16 = local_110 + param_9;
      }
    }
  }
  local_114 = *(int *)(param_8 + 5);
  local_88 = 1;
LAB_fffffff00a3d5454:
  ppuVar24 = (undefined **)(uVar25 + (long)(int)local_c0 + uVar26);
  if (ppuVar24 == (undefined **)0x0) {
    return 0;
  }
  uVar2 = param_14 >> 1 & 0x2000 | (param_14 >> 0xb & 1) << 0x12 | param_14 >> 6 & 0x10000;
  ppuVar13 = (undefined **)(ulong)(uVar1 & 0x7ffc000);
  do {
    puVar19 = param_12;
    if ((uVar25 == 0) && (puVar19 = puVar16, local_c0 != 0)) {
      puVar19 = param_8[3];
    }
    uVar6 = (uint)puVar19 & 0x3fff;
    if ((long)ppuVar13 <= (long)ppuVar24) {
      ppuVar24 = ppuVar13;
    }
    local_98 = (ulong)puVar19 >> 0xe;
    if ((uVar20 & 0xc4) == 0 && param_8 != (undefined **)0x0) {
      uVar6 = (uVar1 & 0x7ffc000) - uVar6;
      if ((long)(((ulong)puVar19 & 0x3fff) + (long)ppuVar24) <= (long)ppuVar13) {
        uVar6 = (uint)ppuVar24;
      }
      local_84 = uVar6;
      uVar28 = FUN_fffffff00a3d8fc4
                         (param_1,param_2,param_3,param_4,param_5,param_6,(long)param_7,param_8,
                          &local_84,1,1);
      if ((int)uVar28 != 0) {
        return uVar28;
      }
      ppuVar24 = (undefined **)(long)(int)local_84;
      local_c0 = (local_84 - uVar6) + local_c0;
      puVar19 = param_8[3];
      uVar6 = (uint)puVar19 & 0x3fff;
      pppppppppppuVar27 = (undefined4 ***********)((ulong)puVar19 & 0xffffffffffffc000);
      if (local_84 != 0) goto LAB_fffffff00a3d5554;
      ppuVar17 = (undefined **)0x0;
      if (((ulong)puVar19 & 0x3fff) != 0) {
        pppppppppppuVar27 = pppppppppppuVar27 + 0x800;
      }
    }
    else {
      pppppppppppuVar27 = (undefined4 ***********)((ulong)puVar19 & 0xffffffffffffc000);
LAB_fffffff00a3d5554:
      ppuVar17 = (undefined **)((long)ppuVar24 + (ulong)uVar6 + 0x3fff & 0xffffffffffffc000);
      if (ppuVar13 <= ppuVar17) {
        ppuVar17 = ppuVar13;
      }
      ppuVar18 = (undefined **)(long)(int)((int)ppuVar17 - uVar6);
      if ((long)ppuVar18 <= (long)ppuVar24) {
        ppuVar24 = ppuVar18;
      }
      uVar5 = 0x800400;
      if ((param_8 != (undefined **)0x0) && (uVar5 = 0x800400, ((ulong)param_8[6] & 4) != 0)) {
        uVar5 = 0x400;
      }
      pppppppppppuVar10 = &local_78;
      uVar7 = FUN_fffffff00a7868c4
                        ((long)param_7,(undefined **)pppppppppppuVar27,ppuVar17,
                         (undefined **)&local_80,(long *)pppppppppppuVar10,uVar5,0x14);
      pppppuVar3 = local_80;
      if ((int)uVar7 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114
                  (extraout_q0,param_2,param_3,param_4,param_5,param_6,
                   (byte *)"cluster_write_copy: failed to get pagelist @%s:%d");
      }
      auVar31 = extraout_q0;
      if (((uVar6 != 0) && ((long)pppppppppppuVar27 < param_10)) &&
         ((*(int *)local_78 == 0 || ((*(byte *)((long)local_78 + 4) >> 1 & 1) != 0)))) {
        uVar5 = (int)param_10 - (int)pppppppppppuVar27;
        if ((long)(pppppppppppuVar27 + 0x800) <= param_10) {
          uVar5 = 0x4000;
        }
        pppppppppppuVar10 = (undefined4 ***********)(ulong)uVar5;
        uVar5 = FUN_fffffff00a3d1f10
                          (param_7,local_80,(undefined4 ***********)0x0,pppppppppppuVar27,
                           pppppppppppuVar10,(ulong)(uVar2 | 1),(undefined4 ***********)0x0,0,
                           param_15,param_16);
        auVar31 = extraout_q0_00;
        if (uVar5 != 0) {
          puVar12 = (uint *)&local_6c;
          uVar7 = 0x4000;
          ppuVar24 = (undefined **)&DAT_00000018;
          FUN_fffffff00a342370
                    ((undefined4 *)pppppuVar3,0,(undefined **)0x4000,(undefined **)&DAT_00000018,
                     puVar12);
          if ((uint)local_6c != 0) {
            FUN_fffffff00a31924c((undefined4 *)pppppuVar3,extraout_x1_01,uVar7,ppuVar24,puVar12);
          }
          goto joined_r0xfffffff00a3d5a94;
        }
      }
      pppppuVar3 = local_80;
      uVar15 = (uint)ppuVar24;
      if ((((uVar6 == 0) || ((undefined **)0x4000 < ppuVar17)) && ((uVar6 + uVar15 & 0x3fff) != 0))
         && ((long)(((ulong)pppppppppppuVar27 | (ulong)uVar6) + (long)(int)uVar15) < param_10)) {
        pppppppppppuVar29 = (undefined4 ***********)(ppuVar17 + -0x800);
        piVar14 = (int *)((long)local_78 + ((long)pppppppppppuVar29 >> 0xb));
        if ((((ulong)local_78 ^ (ulong)piVar14) & 0xffc0000000000000) != 0) {
          piVar14 = (int *)((ulong)piVar14 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if ((*piVar14 == 0) || ((*(byte *)(piVar14 + 1) >> 1 & 1) != 0)) {
          uVar5 = (int)param_10 -
                  (int)(undefined4 ***********)((long)pppppppppppuVar29 + (long)pppppppppppuVar27);
          if ((long)ppuVar17 + (long)pppppppppppuVar27 <= param_10) {
            uVar5 = 0x4000;
          }
          pppppppppppuVar10 = (undefined4 ***********)(ulong)uVar5;
          uVar5 = FUN_fffffff00a3d1f10
                            (param_7,local_80,pppppppppppuVar29,
                             (undefined4 ***********)
                             ((long)pppppppppppuVar29 + (long)pppppppppppuVar27),pppppppppppuVar10,
                             (ulong)(uVar2 | 1),(undefined4 ***********)0x0,0,param_15,param_16);
          auVar31 = extraout_q0_01;
          if (uVar5 != 0) {
            FUN_fffffff00a786a78
                      ((undefined4 *)pppppuVar3,(uint)pppppppppppuVar29,(undefined **)0x4000,
                       (undefined **)&DAT_00000018);
joined_r0xfffffff00a3d5a94:
            uVar25 = (ulong)uVar5;
            if (ppuVar17 < (undefined **)0x4001) {
              return uVar25;
            }
            puVar12 = (uint *)&local_6c;
            ppuVar24 = (undefined **)&DAT_00000008;
            FUN_fffffff00a342370
                      ((undefined4 *)pppppuVar3,0,ppuVar17,(undefined **)&DAT_00000008,puVar12);
            if ((uint)local_6c != 0) {
              FUN_fffffff00a31924c
                        ((undefined4 *)pppppuVar3,extraout_x1_02,ppuVar17,ppuVar24,puVar12);
              return uVar25;
            }
            return uVar25;
          }
        }
      }
      ppppppppppuVar4 = local_78;
      pppppuVar3 = local_80;
      if ((uVar25 == 0) || (uVar15 == 0)) {
        uVar28 = (ulong)uVar6;
        uVar5 = uVar15;
      }
      else {
        uVar28 = (ulong)uVar6;
        do {
          iVar21 = (int)ppuVar24;
          uVar30 = uVar25;
          if ((long)iVar21 <= (long)uVar25) {
            uVar30 = (long)iVar21;
          }
          if ((uVar20 & 0x300) == 0) {
LAB_fffffff00a3d572c:
            auVar31 = FUN_fffffff00a3d1c38((long)pppppuVar3,uVar28,uVar30,0,(byte)pppppppppppuVar10)
            ;
          }
          else {
            uVar22 = 0x4000 - ((uint)param_12 & 0x3fff);
            uVar5 = (uint)uVar30;
            if (uVar22 <= (uint)uVar30) {
              uVar5 = uVar22;
            }
            uVar30 = (ulong)uVar5;
            if ((*(int *)(ppppppppppuVar4 +
                         (int)((ulong)((long)param_12 - (long)pppppppppppuVar27) >> 0xe)) == 0) ||
               ((*(byte *)((long)(ppppppppppuVar4 +
                                 (int)((ulong)((long)param_12 - (long)pppppppppppuVar27) >> 0xe)) +
                          4) >> 1 & 1) != 0)) goto LAB_fffffff00a3d572c;
          }
          iVar23 = (int)uVar30;
          uVar5 = iVar21 - iVar23;
          ppuVar24 = (undefined **)(ulong)uVar5;
          uVar25 = uVar25 - (long)iVar23;
          param_12 = param_12 + iVar23;
          uVar28 = (ulong)(uint)(iVar23 + (int)uVar28);
        } while (uVar25 != 0 && uVar5 != 0);
      }
      pppppuVar3 = local_80;
      uVar22 = (uint)ppuVar24;
      if (uVar5 == 0 || local_c0 == 0) {
        local_bc = 0;
LAB_fffffff00a3d5868:
        ppppppppppuVar4 = local_78;
        pppppuVar3 = local_80;
        bVar9 = (byte)pppppppppppuVar10;
        uVar5 = (uint)ppuVar24;
        if ((uVar5 != 0) && (uVar26 != 0)) {
          do {
            iVar21 = (int)ppuVar24;
            uVar30 = uVar26;
            if ((long)iVar21 <= (long)uVar26) {
              uVar30 = (long)iVar21;
            }
            if ((uVar20 & 0x300) == 0) {
LAB_fffffff00a3d587c:
              FUN_fffffff00a3d1c38((long)pppppuVar3,uVar28,uVar30,0,(byte)pppppppppppuVar10);
            }
            else {
              uVar22 = 0x4000 - ((uint)puVar16 & 0x3fff);
              uVar5 = (uint)uVar30;
              if (uVar22 <= (uint)uVar30) {
                uVar5 = uVar22;
              }
              uVar30 = (ulong)uVar5;
              if ((*(int *)(ppppppppppuVar4 +
                           (int)((ulong)((long)puVar16 - (long)pppppppppppuVar27) >> 0xe)) == 0) ||
                 ((*(byte *)((long)(ppppppppppuVar4 +
                                   (int)((ulong)((long)puVar16 - (long)pppppppppppuVar27) >> 0xe)) +
                            4) >> 1 & 1) != 0)) goto LAB_fffffff00a3d587c;
            }
            bVar9 = (byte)pppppppppppuVar10;
            iVar23 = (int)uVar30;
            uVar5 = iVar21 - iVar23;
            ppuVar24 = (undefined **)(ulong)uVar5;
            uVar26 = uVar26 - (long)iVar23;
            puVar16 = puVar16 + iVar23;
            uVar28 = (ulong)(uint)(iVar23 + (int)uVar28);
          } while (uVar5 != 0 && uVar26 != 0);
        }
      }
      else {
        uVar5 = local_c0;
        if (uVar22 <= local_c0) {
          uVar5 = uVar22;
        }
        local_9c = uVar5;
        uVar7 = FUN_fffffff00a3d90f8
                          (auVar31,param_2,param_3,param_4,param_5,param_6,(long *)param_8,
                           (long)local_80,(uint)uVar28,(ulong *)&local_9c,(byte)pppppppppppuVar10);
        local_bc = (uint)uVar7;
        if (local_bc == 0) {
          local_c0 = local_c0 - uVar5;
          ppuVar24 = (undefined **)(ulong)(uVar22 - uVar5);
          uVar28 = (ulong)(uVar5 + (uint)uVar28);
        }
        else {
          pppppppppppuVar10 = &local_6c;
          ppuVar8 = (undefined **)&DAT_00000008;
          ppuVar18 = ppuVar17;
          FUN_fffffff00a342370
                    ((undefined4 *)pppppuVar3,0,ppuVar17,(undefined **)&DAT_00000008,
                     (uint *)pppppppppppuVar10);
          if ((uint)local_6c != 0) {
            FUN_fffffff00a31924c
                      ((undefined4 *)pppppuVar3,extraout_x1,ppuVar18,ppuVar8,pppppppppppuVar10);
          }
        }
        bVar9 = (byte)pppppppppppuVar10;
        uVar5 = (uint)ppuVar24;
        if (local_bc == 0) goto LAB_fffffff00a3d5868;
      }
      pppppuVar3 = local_80;
      if (local_bc != 0) {
        return (ulong)local_bc;
      }
      local_84 = uVar5;
      if ((param_10 <= (long)param_11) || (*(short *)((long)param_7 + 0x72) != 0x19)) {
        uVar6 = uVar6 + uVar15;
        if (((long)param_11 <= (long)pppppppppppuVar27 + (long)(int)uVar6) &&
           ((undefined **)(ulong)uVar6 < ppuVar17)) {
          FUN_fffffff00a3d1c38((long)local_80,(ulong)uVar6,(ulong)((int)ppuVar17 - uVar6),0,bVar9);
        }
      }
      if (pppppuVar3[8] == (undefined4 ****)0x0) {
        pppppuVar11 = pppppuVar3 + 0x12;
      }
      else {
        pppppuVar11 = (undefined4 *****)pppppuVar3[8][4];
      }
      ppuVar18 = (undefined **)0xd;
      ppuVar24 = ppuVar17;
      FUN_fffffff00a342c94
                ((undefined4 *)pppppuVar3,0,ppuVar17,(undefined **)0xd,(undefined4 *)pppppuVar11,
                 0x1000,(uint *)&local_6c);
      if ((uint)local_6c != 0) {
        FUN_fffffff00a31924c((undefined4 *)pppppuVar3,extraout_x1_00,ppuVar24,ppuVar18,pppppuVar11);
      }
    }
    local_90 = (ulong)((long)pppppppppppuVar27 + (long)ppuVar17) >> 0xe;
    if ((uVar20 >> 2 & 1) == 0) {
      FUN_fffffff00a3d934c
                (param_7,(long *)&local_98,uVar20,
                 *(uint *)(*(long *)(param_7 + 0x36) + 0x70) >> 0x19 & 1,&local_88,(long)local_110,
                 local_114,(long)param_11,param_15,param_16,0);
      uVar28 = 0;
      param_1 = extraout_q0_02;
    }
    else {
      uVar6 = FUN_fffffff00a3d7f48
                        (param_7,local_98,(int)local_90,(long)param_11,uVar20,param_15,param_16,0);
      uVar28 = (ulong)uVar6;
      param_1 = extraout_q0_03;
    }
    ppuVar24 = (undefined **)(uVar25 + (long)(int)local_c0 + uVar26);
    if (ppuVar24 == (undefined **)0x0) {
      return uVar28;
    }
    if ((int)uVar28 != 0) {
      return uVar28;
    }
  } while( true );
}

