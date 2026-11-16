// FUN_fffffff00a3dc38c @ fffffff00a3dc38c size=1864
// CALLERS:
//   fffffff00afba16f ?
//   fffffff00a3d9dd0 FUN_fffffff00a3d9c1c@fffffff00a3d9c1c
// CALLS:
//   fffffff00a342370 FUN_fffffff00a342370
//   fffffff00a31b1b8 FUN_fffffff00a31b1b8
//   fffffff00a3d5b14 FUN_fffffff00a3d5b14
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a73ed8c FUN_fffffff00a73ed8c
//   fffffff00a73e538 FUN_fffffff00a73e538
//   fffffff00a31924c FUN_fffffff00a31924c
//   fffffff00aa61ed0 FUN_fffffff00aa61ed0
//   fffffff00aa4c590 FUN_fffffff00aa4c590
//   fffffff00a31fe0c FUN_fffffff00a31fe0c
//   fffffff00a3d7344 FUN_fffffff00a3d7344
//   fffffff00a3d8ddc FUN_fffffff00a3d8ddc
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a3d1f10 FUN_fffffff00a3d1f10

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_fffffff00a3dc38c
              (uint *param_1,long *param_2,long param_3,undefined4 ***********param_4,
              undefined4 ***********param_5,undefined8 param_6,long param_7,ulong param_8)

{
  ulong uVar1;
  ulong *puVar2;
  uint uVar3;
  undefined4 ***********pppppppppppuVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  int iVar10;
  uint uVar11;
  long extraout_x1;
  long extraout_x1_00;
  long extraout_x1_01;
  long extraout_x1_02;
  undefined **ppuVar12;
  undefined4 ***********pppppppppppuVar13;
  undefined4 ***********pppppppppppuVar14;
  undefined4 *********pppppppppuVar15;
  long lVar16;
  ulong uVar17;
  undefined4 **********ppppppppppuVar18;
  long lVar19;
  uint uVar20;
  ulong uVar21;
  ulong uVar22;
  undefined **ppuVar23;
  undefined4 ***********pppppppppppuVar24;
  undefined4 ***********pppppppppppuVar25;
  uint in_wzr;
  uint local_120;
  undefined4 uStack_11c;
  undefined8 local_118;
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
  uVar22 = *(ulong *)(*(long *)(param_1 + 0x1e) + 0x38);
  pppppppppppuVar13 = param_4;
  pppppppppppuVar14 = param_5;
  if ((uVar22 != 0) && (*(int *)(uVar22 + 0x30) != 0)) {
    lVar16 = tpidr_el1;
    puVar2 = (ulong *)(uVar22 + 8);
    if (*puVar2 == 0) {
      *puVar2 = (ulong)*(uint *)(lVar16 + 0x4e8);
    }
    else {
      FUN_fffffff00a2262d4(uVar22,lVar16,(undefined **)0x0);
    }
    pppppppppppuVar13 = (undefined4 ***********)0x6;
    pppppppppppuVar14 = (undefined4 ***********)0x0;
    FUN_fffffff00a3d7344(uVar22,param_1,param_3,6,0,param_6,param_7,(int *)0x0,0,(long *)0x0);
    if (*(uint *)puVar2 == *(uint *)(lVar16 + 0x4e8)) {
      *(uint *)puVar2 = in_wzr;
    }
    else {
      FUN_fffffff00a226e08(uVar22,lVar16,*(uint *)puVar2);
    }
  }
  lVar16 = *(long *)(param_1 + 0x36);
  uVar20 = *(uint *)(lVar16 + 0x91c);
  uVar6 = *(uint *)(lVar16 + 0x918);
  local_110 = 0;
  local_108 = 0;
  local_120 = DAT_fffffff00ad22068 & 0xffffff | 0x22000000;
  uStack_11c = 0;
  local_118 = 0;
  DAT_fffffff00ad22074 = DAT_fffffff00ad22074 + 1;
  if (((int)DAT_fffffff00ad22068 < 0) &&
     (iVar10 = DAT_fffffff00ad22064 + 1, uVar3 = DAT_fffffff00ad22064 + 0xf0000001,
     DAT_fffffff00ad22064 = iVar10, uVar3 < 0xf0000002)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0((uint *)&DAT_fffffff00ad22064);
  }
  ppuVar23 = (undefined **)0x0;
  uVar3 = uVar20 - 1;
  lVar16 = 0;
  do {
    uVar22 = param_3 - param_2[3];
    if ((long)(ulong)*(uint *)param_5 <= param_3 - param_2[3]) {
      uVar22 = (ulong)*(uint *)param_5;
    }
    if (*(int *)((long)param_2 + 0x14) < 1) {
      uVar21 = 0;
    }
    else {
      uVar21 = *(ulong *)*param_2;
    }
    pppppppppppuVar24 = (undefined4 ***********)(uVar21 & 0x3fff);
    uVar1 = (long)pppppppppppuVar24 + (uVar22 & 0xffffffff);
    local_fc = (uint)uVar1;
    local_100 = 0;
    if ((1 << (ulong)(*(uint *)(param_2 + 4) & 0x1f) & 0x121U) != 0) {
      lVar19 = tpidr_el1;
      uVar17 = *(ulong *)(lVar19 + 0x418);
      if ((uVar17 != 0) && (uVar17 != 0)) goto LAB_fffffff00a3dc5ec;
LAB_fffffff00a3dca4c:
      pppppppppppuVar24 = (undefined4 ***********)0x0;
      iVar10 = 0x16;
      lVar19 = lVar16;
      goto LAB_fffffff00a3dc8b4;
    }
    uVar17 = DAT_fffffff007c678d8;
    if (DAT_fffffff007c678d8 == 0) goto LAB_fffffff00a3dca4c;
LAB_fffffff00a3dc5ec:
    pppppppppppuVar4 = local_f0 + lVar16;
    local_f8 = (undefined4 **********)0x164c;
    ppuVar12 = (undefined **)&local_fc;
    pppppppppppuVar14 = (undefined4 ***********)0x0;
    pppppppppppuVar13 = pppppppppppuVar4;
    uVar17 = FUN_fffffff00a31b1b8
                       (uVar17,(undefined8 *)
                               (uVar21 & ((ulong)(uint)(-1 << (ulong)(*(byte *)(uVar17 + 0x2c) &
                                                                     0x1f)) | 0xffffffff00000000)),
                        ppuVar12,(undefined **)pppppppppppuVar4,(uint *)0x0,&local_100,
                        (ulong *)&local_f8,0x14);
    if ((int)uVar17 != 0) goto LAB_fffffff00a3dca4c;
    lVar19 = lVar16 + 1;
    if ((((uint)local_f8 >> 1 & 1) == 0) || (local_fc < uVar1)) {
LAB_fffffff00a3dca3c:
      iVar10 = 0x16;
LAB_fffffff00a3dc8b0:
      pppppppppppuVar24 = (undefined4 ***********)0x0;
      goto LAB_fffffff00a3dc8b4;
    }
    pppppppppuVar15 = (*pppppppppppuVar4)[8];
    if (pppppppppuVar15 == (undefined4 *********)0x0) {
      ppppppppppuVar18 = *pppppppppppuVar4 + 0x12;
    }
    else {
      ppppppppppuVar18 = (undefined4 **********)pppppppppuVar15[4];
    }
    uVar11 = FUN_fffffff00a31fe0c
                       ((long)ppppppppppuVar18,0,(int)ppuVar12,(ulong)pppppppppppuVar13,
                        (byte)pppppppppppuVar14);
    ppuVar23 = (undefined **)((ulong)pppppppppppuVar24 | (ulong)uVar11 << 0xe);
    while( true ) {
      uVar11 = (uint)uVar22;
      if ((((param_2[3] & (ulong)uVar3) == 0) && (uVar20 <= uVar11)) || (uVar11 == 0)) break;
      uVar7 = uVar20 - (uVar3 & (uint)param_2[3]);
      if (uVar11 <= uVar7) {
        uVar7 = uVar11;
      }
      pppppppppppuVar25 = (undefined4 ***********)(ulong)uVar7;
      pppppppppppuVar14 = (undefined4 ***********)0x1;
      pppppppppppuVar13 = pppppppppppuVar25;
      iVar10 = FUN_fffffff00a3d8ddc
                         (param_1,param_2,ppuVar23,(ulong)pppppppppppuVar25,1,param_6,param_7);
      if (iVar10 != 0) goto LAB_fffffff00a3dc8b0;
      pppppppppppuVar24 =
           (undefined4 ***********)((long)pppppppppppuVar24 + (long)pppppppppppuVar25);
      ppuVar23 = (undefined **)((long)ppuVar23 + (long)pppppppppppuVar25);
      uVar22 = (ulong)(uVar11 - uVar7);
      uVar21 = uVar21 + (long)pppppppppppuVar25;
    }
    if ((uVar6 & (uint)uVar21) != 0) goto LAB_fffffff00a3dca3c;
    uVar7 = uVar11 & uVar3;
    for (uVar11 = uVar11 - uVar7; uVar11 != 0; uVar11 = uVar11 - uVar5) {
      uVar5 = uVar11;
      if (0x3ffffff < uVar11) {
        uVar5 = 0x4000000;
      }
      pppppppppppuVar25 = (undefined4 ***********)(ulong)uVar5;
      iVar10 = *(int *)(*(long *)(param_1 + 0x36) + 0x924);
      lVar9 = tpidr_el1;
      uVar22 = (ulong)*(uint *)(lVar9 + 0x4e8);
      if (local_118 != 0) {
        FUN_fffffff00a2262d4((ulong)&local_120,lVar9,(undefined **)0x0);
        uVar22 = local_118;
      }
      local_118 = uVar22;
      uVar8 = local_110._4_4_ - (int)local_110;
      while ((uint)(iVar10 * 0x8000000) < uVar8) {
        local_108 = CONCAT44(1,(int)local_108);
        pppppppppppuVar13 = (undefined4 ***********)0x0;
        pppppppppppuVar14 = (undefined4 ***********)0x0;
        FUN_fffffff00a73ed8c
                  ((uint *)((long)&local_108 + 4),0x11,"cluster_read_contig",0,0,(ulong)&local_120);
        uVar8 = local_110._4_4_ - (int)local_110;
      }
      if ((uint)local_118 == *(uint *)(lVar9 + 0x4e8)) {
        local_118._4_4_ = (undefined4)(local_118 >> 0x20);
        local_118 = CONCAT44(local_118._4_4_,in_wzr);
      }
      else {
        FUN_fffffff00a226e08((ulong)&local_120,lVar9,(uint)local_118);
      }
      if ((int)local_108 != 0) {
        iVar10 = 0;
        uVar20 = (uint)lVar19;
        pppppppppppuVar24 = (undefined4 ***********)(ulong)uVar7;
        goto LAB_fffffff00a3dc8b8;
      }
      pppppppppppuVar13 = (undefined4 ***********)param_2[3];
      pppppppppppuVar14 = pppppppppppuVar25;
      iVar10 = FUN_fffffff00a3d1f10
                         (param_1,(undefined4 *****)*pppppppppppuVar4,pppppppppppuVar24,
                          pppppppppppuVar13,pppppppppppuVar25,
                          (ulong)(((uint)param_8 & 0x800) << 7 | (uint)(param_8 >> 1) & 0x2000 |
                                 0x145),(undefined4 ***********)0x0,(ulong)&local_120,param_6,
                          param_7);
      if (iVar10 != 0) goto LAB_fffffff00a3dca28;
      FUN_fffffff00a73e538(param_2,(ulong)pppppppppppuVar25);
      ppuVar23 = (undefined **)((long)ppuVar23 + (long)pppppppppppuVar25);
      pppppppppppuVar24 =
           (undefined4 ***********)((long)pppppppppppuVar24 + (long)pppppppppppuVar25);
    }
    if (uVar7 != 0 || (int)local_108 != 0) {
      iVar10 = 0;
LAB_fffffff00a3dca28:
      pppppppppppuVar24 = (undefined4 ***********)(ulong)uVar7;
      *(undefined4 *)param_4 = 0;
      goto LAB_fffffff00a3dc8b4;
    }
    if ((0xe < (uint)lVar16) || (param_3 <= param_2[3])) {
      iVar10 = 0;
      goto LAB_fffffff00a3dca28;
    }
    pppppppppppuVar14 = (undefined4 ***********)0x0;
    pppppppppppuVar13 = param_5;
    iVar10 = FUN_fffffff00a3d5b14((long)param_1,param_2,(undefined4 *)param_4,(int *)param_5,0);
    if (iVar10 != 0) goto LAB_fffffff00a3dca64;
    lVar16 = lVar19;
  } while (*(int *)param_4 == 2);
  iVar10 = 0;
LAB_fffffff00a3dca64:
  pppppppppppuVar24 = (undefined4 ***********)0x0;
LAB_fffffff00a3dc8b4:
  uVar20 = (uint)lVar19;
LAB_fffffff00a3dc8b8:
  lVar16 = tpidr_el1;
  uVar22 = (ulong)*(uint *)(lVar16 + 0x4e8);
  if (local_118 != 0) {
    FUN_fffffff00a2262d4((ulong)&local_120,lVar16,(undefined **)0x0);
    uVar22 = local_118;
  }
  local_118 = uVar22;
  if (local_110._4_4_ != (int)local_110) {
    do {
      local_108 = CONCAT44(1,(int)local_108);
      pppppppppppuVar13 = (undefined4 ***********)0x0;
      pppppppppppuVar14 = (undefined4 ***********)0x0;
      FUN_fffffff00a73ed8c
                ((uint *)((long)&local_108 + 4),0x11,"cluster_read_contig",0,0,(ulong)&local_120);
    } while (local_110._4_4_ != (int)local_110);
  }
  uVar22 = local_118;
  uVar6 = (uint)local_118;
  if ((uint)local_118 == *(uint *)(lVar16 + 0x4e8)) {
    local_118 = CONCAT44(local_118._4_4_,in_wzr);
  }
  ppuVar12 = (undefined **)(uVar22 & 0xffffffff);
  if (uVar6 != *(uint *)(lVar16 + 0x4e8)) {
    FUN_fffffff00a226e08((ulong)&local_120,lVar16,uVar6);
  }
  if ((int)local_108 != 0) {
    iVar10 = (int)local_108;
  }
  FUN_fffffff00a2261c0(&local_120,&DAT_fffffff00ad22064);
  lVar16 = extraout_x1;
  if ((iVar10 == 0) && ((int)pppppppppppuVar24 != 0)) {
    pppppppppppuVar14 = (undefined4 ***********)0x1;
    iVar10 = FUN_fffffff00a3d8ddc
                       (param_1,param_2,ppuVar23,(ulong)pppppppppppuVar24,1,param_6,param_7);
    lVar16 = extraout_x1_00;
    ppuVar12 = ppuVar23;
    pppppppppppuVar13 = pppppppppppuVar24;
  }
  if (0 < (int)uVar20) {
    lVar19 = 0;
    uVar22 = (ulong)uVar20;
    do {
      ppppppppppuVar18 = local_f0[lVar19];
      if (ppppppppppuVar18 != (undefined4 **********)0x0) {
        ppuVar12 = (undefined **)(ulong)*(uint *)(ppppppppppuVar18 + 5);
        pppppppppppuVar14 = &local_f8;
        pppppppppppuVar13 = (undefined4 ***********)0x0;
        FUN_fffffff00a342370
                  ((undefined4 *)ppppppppppuVar18,0,ppuVar12,(undefined **)0x0,
                   (uint *)pppppppppppuVar14);
        lVar16 = extraout_x1_02;
      }
      FUN_fffffff00a31924c
                ((undefined4 *)ppppppppppuVar18,lVar16,ppuVar12,(undefined **)pppppppppppuVar13,
                 pppppppppppuVar14);
      lVar19 = lVar19 + 1;
      uVar22 = uVar22 - 1;
      lVar16 = extraout_x1_01;
    } while (uVar22 != 0);
  }
  if (DAT_fffffff00ad30000 != local_70) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa4c590();
  }
  return iVar10;
}

