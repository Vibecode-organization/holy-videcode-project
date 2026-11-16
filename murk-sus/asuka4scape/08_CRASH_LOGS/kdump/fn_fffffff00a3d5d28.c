// FUN_fffffff00a3d5d28 @ fffffff00a3d5d28 size=1776
// CALLERS:
//   fffffff00afba14c ?
//   fffffff00a3d5200 FUN_fffffff00a3d4f98@fffffff00a3d4f98
// CALLS:
//   fffffff00a31924c FUN_fffffff00a31924c
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0
//   fffffff00a3d1f10 FUN_fffffff00a3d1f10
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a342370 FUN_fffffff00a342370
//   fffffff00a73ed8c FUN_fffffff00a73ed8c
//   fffffff00a3d8ddc FUN_fffffff00a3d8ddc
//   fffffff00a73e538 FUN_fffffff00a73e538
//   fffffff00aa4c590 FUN_fffffff00aa4c590
//   fffffff00a31fe0c FUN_fffffff00a31fe0c
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a3d7344 FUN_fffffff00a3d7344
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a3d5b14 FUN_fffffff00a3d5b14

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_fffffff00a3d5d28
              (uint *param_1,long *param_2,long param_3,undefined4 ***********param_4,
              undefined4 ***********param_5,long param_6,long param_7,uint param_8)

{
  ulong *puVar1;
  uint uVar2;
  undefined4 ***********pppppppppppuVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long extraout_x1_02;
  undefined **ppuVar9;
  undefined4 ***********pppppppppppuVar10;
  undefined4 ***********pppppppppppuVar11;
  uint uVar12;
  undefined4 *********pppppppppuVar13;
  long lVar14;
  ulong uVar15;
  undefined4 **********ppppppppppuVar16;
  ulong uVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  undefined **ppuVar21;
  undefined4 ***********pppppppppppuVar22;
  undefined4 ***********pppppppppppuVar23;
  uint in_wzr;
  uint local_120;
  undefined4 uStack_11c;
  ulong local_118;
  undefined8 local_110;
  undefined8 local_108;
  uint local_100;
  uint local_fc;
  undefined4 **********local_f8;
  undefined4 **********local_f0 [16];
  long local_70;
  
  local_70 = DAT_fffffff00ad30000;
  local_f0[0xd] = (undefined4 **********)0x0;
  local_f0[0xc] = (undefined4 **********)0x0;
  local_f0[0xf] = (undefined4 **********)0x0;
  local_f0[0xe] = (undefined4 **********)0x0;
  local_f0[9] = (undefined4 **********)0x0;
  local_f0[8] = (undefined4 **********)0x0;
  local_f0[0xb] = (undefined4 **********)0x0;
  local_f0[10] = (undefined4 **********)0x0;
  local_f0[5] = (undefined4 **********)0x0;
  local_f0[4] = (undefined4 **********)0x0;
  local_f0[7] = (undefined4 **********)0x0;
  local_f0[6] = (undefined4 **********)0x0;
  local_f0[1] = (undefined4 **********)0x0;
  local_f0[0] = (undefined4 **********)0x0;
  local_f0[3] = (undefined4 **********)0x0;
  local_f0[2] = (undefined4 **********)0x0;
  uVar20 = *(ulong *)(*(long *)(param_1 + 0x1e) + 0x38);
  pppppppppppuVar10 = param_4;
  pppppppppppuVar11 = param_5;
  if ((uVar20 != 0) && (*(int *)(uVar20 + 0x30) != 0)) {
    lVar14 = tpidr_el1;
    puVar1 = (ulong *)(uVar20 + 8);
    if (*puVar1 == 0) {
      *puVar1 = (ulong)*(uint *)(lVar14 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(uVar20,lVar14,(undefined **)0x0);
    }
    uVar12 = 2;
    if (param_6 != 0) {
      uVar12 = 6;
    }
    pppppppppppuVar10 = (undefined4 ***********)(ulong)uVar12;
    pppppppppppuVar11 = (undefined4 ***********)0x0;
    FUN_fffffff00a3d7344(uVar20,param_1,param_3,uVar12,0,param_6,param_7,(int *)0x0,0,(long *)0x0);
    if (*(uint *)puVar1 == *(uint *)(lVar14 + 0x4e8)) {
      *(uint *)puVar1 = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(uVar20,lVar14,*(uint *)puVar1);
    }
  }
  lVar14 = *(long *)(param_1 + 0x36);
  uVar12 = *(uint *)(lVar14 + 0x91c);
  uVar5 = *(uint *)(lVar14 + 0x918);
  local_110 = 0;
  local_108 = 0;
  local_120 = DAT_fffffff00ad22068 & 0xffffff | 0x22000000;
  uStack_11c = 0;
  local_118 = 0;
  DAT_fffffff00ad22074 = DAT_fffffff00ad22074 + 1;
  if (((int)DAT_fffffff00ad22068 < 0) &&
     (iVar7 = DAT_fffffff00ad22064 + 1, uVar2 = DAT_fffffff00ad22064 + 0xf0000001,
     DAT_fffffff00ad22064 = iVar7, uVar2 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0((uint *)&DAT_fffffff00ad22064);
  }
  ppuVar21 = (undefined **)0x0;
  uVar2 = uVar12 - 1;
  uVar20 = 0;
  do {
    uVar17 = (ulong)*(uint *)param_5;
    if (*(int *)((long)param_2 + 0x14) < 1) {
      uVar19 = 0;
    }
    else {
      uVar19 = *(ulong *)*param_2;
    }
    pppppppppppuVar22 = (undefined4 ***********)(uVar19 & 0x3fff);
    local_fc = (uint)((long)pppppppppppuVar22 + uVar17);
    local_100 = 0;
    if ((1 << (ulong)(*(uint *)(param_2 + 4) & 0x1f) & 0x121U) != 0) {
      lVar14 = tpidr_el1;
      uVar15 = *(ulong *)(lVar14 + 0x418);
      if ((uVar15 != 0) && (uVar15 != 0)) goto LAB_fffffff00a3d5f60;
LAB_fffffff00a3d6244:
      pppppppppppuVar22 = (undefined4 ***********)0x0;
      iVar7 = 0x16;
      uVar15 = uVar20;
      goto LAB_fffffff00a3d624c;
    }
    uVar15 = DAT_fffffff007c678d8;
    if (DAT_fffffff007c678d8 == 0) goto LAB_fffffff00a3d6244;
LAB_fffffff00a3d5f60:
    pppppppppppuVar3 = local_f0 + uVar20;
    local_f8 = (undefined4 **********)0x164d;
    ppuVar9 = (undefined **)&local_fc;
    pppppppppppuVar11 = (undefined4 ***********)0x0;
    pppppppppppuVar10 = pppppppppppuVar3;
    uVar15 = FUN_fffffff00a31b1b8
                       (uVar15,(undefined8 *)
                               (uVar19 & ((ulong)(uint)(-1 << (ulong)(*(byte *)(uVar15 + 0x2c) &
                                                                     0x1f)) | 0xffffffff00000000)),
                        ppuVar9,(undefined **)pppppppppppuVar3,(uint *)0x0,&local_100,
                        (ulong *)&local_f8,0x14);
    if ((int)uVar15 != 0) goto LAB_fffffff00a3d6244;
    uVar15 = uVar20 + 1;
    if ((((uint)local_f8 >> 1 & 1) == 0) || ((ulong)local_fc < (long)pppppppppppuVar22 + uVar17)) {
LAB_fffffff00a3d6234:
      iVar7 = 0x16;
      goto LAB_fffffff00a3d6204;
    }
    pppppppppuVar13 = (*pppppppppppuVar3)[8];
    if (pppppppppuVar13 == (undefined4 *********)0x0) {
      ppppppppppuVar16 = *pppppppppppuVar3 + 0x12;
    }
    else {
      ppppppppppuVar16 = (undefined4 **********)pppppppppuVar13[4];
    }
    uVar8 = FUN_fffffff00a31fe0c
                      ((long)ppppppppppuVar16,0,(int)ppuVar9,(ulong)pppppppppppuVar10,
                       (byte)pppppppppppuVar11);
    ppuVar21 = (undefined **)((ulong)pppppppppppuVar22 | (ulong)uVar8 << 0xe);
    while( true ) {
      uVar8 = (uint)uVar17;
      if ((((param_2[3] & (ulong)uVar2) == 0) && (uVar12 <= uVar8)) || (uVar8 == 0)) break;
      uVar6 = uVar12 - (uVar2 & (uint)param_2[3]);
      if (uVar8 <= uVar6) {
        uVar6 = uVar8;
      }
      pppppppppppuVar23 = (undefined4 ***********)(ulong)uVar6;
      pppppppppppuVar11 = (undefined4 ***********)0x0;
      pppppppppppuVar10 = pppppppppppuVar23;
      iVar7 = FUN_fffffff00a3d8ddc
                        (param_1,param_2,ppuVar21,(ulong)pppppppppppuVar23,0,param_6,param_7);
      if (iVar7 != 0) goto LAB_fffffff00a3d6204;
      pppppppppppuVar22 =
           (undefined4 ***********)((long)pppppppppppuVar22 + (long)pppppppppppuVar23);
      ppuVar21 = (undefined **)((long)ppuVar21 + (long)pppppppppppuVar23);
      uVar17 = (ulong)(uVar8 - uVar6);
      uVar19 = uVar19 + (long)pppppppppppuVar23;
    }
    if ((uVar5 & (uint)uVar19) != 0) goto LAB_fffffff00a3d6234;
    uVar6 = uVar8 & uVar2;
    for (uVar8 = uVar8 - uVar6; uVar8 != 0; uVar8 = uVar8 - uVar4) {
      uVar4 = uVar8;
      if (0x3ffffff < uVar8) {
        uVar4 = 0x4000000;
      }
      pppppppppppuVar23 = (undefined4 ***********)(ulong)uVar4;
      iVar7 = *(int *)(*(long *)(param_1 + 0x36) + 0x924);
      lVar14 = tpidr_el1;
      uVar17 = (ulong)*(uint *)(lVar14 + 0x4e8);
      if (local_118 != 0) {
        FUN_fffffff00a2262d4((ulong)&local_120,lVar14,(undefined **)0x0);
        uVar17 = local_118;
      }
      local_118 = uVar17;
      while( true ) {
        if ((uint)(local_110._4_4_ - (int)local_110) <= (uint)(iVar7 * 0x8000000)) break;
        local_108 = CONCAT44(1,(int)local_108);
        pppppppppppuVar10 = (undefined4 ***********)0x0;
        pppppppppppuVar11 = (undefined4 ***********)0x0;
        FUN_fffffff00a73ed8c
                  ((uint *)((long)&local_108 + 4),0x11,"cluster_write_contig",0,0,(ulong)&local_120)
        ;
      }
      if ((uint)local_118 == *(uint *)(lVar14 + 0x4e8)) {
        local_118 = CONCAT44(local_118._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08((ulong)&local_120,lVar14,(uint)local_118);
      }
      if ((int)local_108 != 0) {
        iVar7 = 0;
        goto LAB_fffffff00a3d6224;
      }
      pppppppppppuVar10 = (undefined4 ***********)param_2[3];
      pppppppppppuVar11 = pppppppppppuVar23;
      iVar7 = FUN_fffffff00a3d1f10
                        (param_1,(undefined4 *****)*pppppppppppuVar3,pppppppppppuVar22,
                         pppppppppppuVar10,pppppppppppuVar23,(ulong)(param_8 | 0x104),
                         (undefined4 ***********)0x0,(ulong)&local_120,param_6,param_7);
      if (iVar7 != 0) goto LAB_fffffff00a3d6220;
      FUN_fffffff00a73e538(param_2,(ulong)pppppppppppuVar23);
      pppppppppppuVar22 =
           (undefined4 ***********)((long)pppppppppppuVar22 + (long)pppppppppppuVar23);
      ppuVar21 = (undefined **)((long)ppuVar21 + (long)pppppppppppuVar23);
    }
    if (uVar6 != 0 || (int)local_108 != 0) {
      iVar7 = 0;
LAB_fffffff00a3d6220:
      *(undefined4 *)param_4 = 0;
LAB_fffffff00a3d6224:
      pppppppppppuVar22 = (undefined4 ***********)(ulong)uVar6;
      goto LAB_fffffff00a3d624c;
    }
    if (0xe < (uint)uVar20) {
      iVar7 = 0;
      goto LAB_fffffff00a3d6220;
    }
    pppppppppppuVar11 = (undefined4 ***********)0x0;
    pppppppppppuVar10 = param_5;
    iVar7 = FUN_fffffff00a3d5b14((long)param_1,param_2,(undefined4 *)param_4,(int *)param_5,0);
    if (iVar7 != 0) goto LAB_fffffff00a3d6204;
    uVar20 = uVar15;
    if (*(int *)param_4 != 2) {
      iVar7 = 0;
LAB_fffffff00a3d6204:
      pppppppppppuVar22 = (undefined4 ***********)0x0;
LAB_fffffff00a3d624c:
      lVar14 = tpidr_el1;
      uVar20 = (ulong)*(uint *)(lVar14 + 0x4e8);
      if (local_118 != 0) {
        FUN_fffffff00a2262d4((ulong)&local_120,lVar14,(undefined **)0x0);
        uVar20 = local_118;
      }
      local_118 = uVar20;
      if (local_110._4_4_ != (int)local_110) {
        do {
          local_108 = CONCAT44(1,(int)local_108);
          pppppppppppuVar10 = (undefined4 ***********)0x0;
          pppppppppppuVar11 = (undefined4 ***********)0x0;
          FUN_fffffff00a73ed8c
                    ((uint *)((long)&local_108 + 4),0x11,"cluster_write_contig",0,0,
                     (ulong)&local_120);
        } while (local_110._4_4_ != (int)local_110);
      }
      uVar20 = local_118;
      uVar12 = (uint)local_118;
      if ((uint)local_118 == *(uint *)(lVar14 + 0x4e8)) {
        local_118 = CONCAT44(local_118._4_4_,in_wzr);
      }
      ppuVar9 = (undefined **)(uVar20 & 0xffffffff);
      if (uVar12 != *(uint *)(lVar14 + 0x4e8)) {
        FUN_fffffff00a226e08((ulong)&local_120,lVar14,uVar12);
      }
      if ((int)local_108 != 0) {
        iVar7 = (int)local_108;
      }
      FUN_fffffff00a2261c0(&local_120,&DAT_fffffff00ad22064);
      lVar14 = extraout_x1;
      if ((iVar7 == 0) && ((int)pppppppppppuVar22 != 0)) {
        pppppppppppuVar11 = (undefined4 ***********)0x0;
        iVar7 = FUN_fffffff00a3d8ddc
                          (param_1,param_2,ppuVar21,(ulong)pppppppppppuVar22,0,param_6,param_7);
        lVar14 = extraout_x1_00;
        ppuVar9 = ppuVar21;
        pppppppppppuVar10 = pppppppppppuVar22;
      }
      if (0 < (int)uVar15) {
        lVar18 = 0;
        uVar15 = uVar15 & 0xffffffff;
        do {
          ppppppppppuVar16 = local_f0[lVar18];
          if (ppppppppppuVar16 != (undefined4 **********)0x0) {
            ppuVar9 = (undefined **)(ulong)*(uint *)(ppppppppppuVar16 + 5);
            pppppppppppuVar11 = &local_f8;
            pppppppppppuVar10 = (undefined4 ***********)0x0;
            FUN_fffffff00a342370
                      ((undefined4 *)ppppppppppuVar16,0,ppuVar9,(undefined **)0x0,
                       (uint *)pppppppppppuVar11);
            lVar14 = extraout_x1_02;
          }
          FUN_fffffff00a31924c
                    ((undefined4 *)ppppppppppuVar16,lVar14,ppuVar9,(undefined **)pppppppppppuVar10,
                     pppppppppppuVar11);
          lVar18 = lVar18 + 1;
          uVar15 = uVar15 - 1;
          lVar14 = extraout_x1_01;
        } while (uVar15 != 0);
      }
      if (DAT_fffffff00ad30000 == local_70) {
        return iVar7;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff00aa4c590();
    }
  } while( true );
}

