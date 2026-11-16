// FUN_fffffff0099561c4 @ fffffff0099561c4 size=2104

ulong FUN_fffffff0099561c4(undefined8 *param_1,undefined8 *param_2,uint *param_3)

{
  undefined8 *puVar1;
  long *plVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  long lVar26;
  int iVar27;
  ulong uVar28;
  ulong uVar29;
  long *plVar30;
  undefined8 unaff_x24;
  long *plVar31;
  ulong unaff_x25;
  undefined8 *puVar32;
  undefined8 *unaff_x28;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  uint uStack_994;
  long alStack_980 [256];
  long lStack_180;
  undefined8 *puStack_170;
  undefined8 *puStack_168;
  long lStack_160;
  ulong uStack_158;
  long *plStack_150;
  uint *puStack_148;
  long lStack_140;
  ulong uStack_138;
  ulong uStack_130;
  long lStack_128;
  undefined1 **ppuStack_120;
  code *pcStack_118;
  long lStack_108;
  long lStack_100;
  uint uStack_f4;
  undefined8 *puStack_f0;
  undefined8 *puStack_e8;
  uint *puStack_e0;
  ulong uStack_d8;
  undefined8 uStack_d0;
  long *plStack_c8;
  long lStack_c0;
  ulong uStack_b8;
  ulong uStack_b0;
  undefined8 *puStack_a8;
  undefined1 *puStack_a0;
  code *pcStack_98;
  ulong local_90;
  undefined8 *local_88;
  undefined8 *local_80;
  uint *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  
  uVar28 = 0xe00002bd;
  if (*(char *)(param_1 + 2) != '\x03') {
    return 0xe00002c7;
  }
  puVar14 = param_3;
  thunk_EXT_FUN_80110000032222a8(param_1[0xc]);
  plVar30 = (long *)param_1[6];
  uVar29 = ((ulong)param_3 & 0xffffffff) << 3;
  lVar10 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1318,uVar29);
  if (lVar10 == 0) goto LAB_fffffff0099569c0;
  local_90 = uVar29;
  local_80 = param_1;
  if ((int)param_3 == 0) {
    local_78 = (uint *)0x0;
  }
  else {
    unaff_x28 = (undefined8 *)0x0;
    local_78 = (uint *)0x0;
    uVar29 = 0xffffffffffffffff;
    unaff_x24 = 0x40;
    unaff_x25 = 1;
    local_88 = (undefined8 *)((ulong)param_3 & 0xffffffff);
    do {
      param_3 = (uint *)param_2[(long)unaff_x28];
      puVar32 = param_2;
      if ((param_3 == (uint *)0x0) || ((char)param_3[4] == '\x03')) goto LAB_fffffff0099569f4;
      puVar32 = *(undefined8 **)(param_3 + 0x1c);
      uVar28 = (long)puVar32 * -0x61c8864680b583eb;
      uVar18 = uVar28 >> ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
      lVar11 = (uVar18 & 0xffffffff) * 4;
      puVar15 = (uint *)(plVar30[2] + (long)(int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar15 = (uint *)(plVar30[2] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar23 = *puVar15;
      do {
        if (uVar23 == 0) goto LAB_fffffff0099564c8;
        uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
        uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
        uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
        uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
        uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
        uVar23 = uVar23 & (1 << (ulong)(uVar21 & 0x1f) ^ 0xffffffffU);
        uVar22 = (ulong)(uVar21 + (int)uVar18 & (int)plVar30[4] - 1U);
        lVar11 = uVar22 * 8;
        puVar3 = (undefined8 *)(*plVar30 + (long)(int)lVar11);
        if (lVar11 != (int)lVar11) {
          puVar3 = (undefined8 *)(*plVar30 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
        }
      } while ((undefined8 *)*puVar3 != puVar32);
      uVar18 = uVar22 << 4 | 8;
      plVar31 = (long *)(plVar30[1] + (long)(int)uVar18);
      if (uVar18 != (long)(int)uVar18) {
        plVar31 = (long *)(plVar30[1] + uVar18 & 0xffffffffffff | 0x2bad000000000000);
      }
      *plVar31 = *plVar31 + 1;
LAB_fffffff00995664c:
      unaff_x28 = (undefined8 *)((long)unaff_x28 + 1);
      param_1 = param_2;
    } while (unaff_x28 != local_88);
  }
  param_1 = local_80;
  lVar11 = thunk_EXT_FUN_8011000003890f30(local_80[5],DAT_fffffff007fed428);
  puVar15 = local_78;
  puVar32 = param_2;
  if (lVar11 == 0) goto LAB_fffffff0099569f8;
  puVar14 = local_78;
  uVar28 = FUN_fffffff009968ef0(lVar11,lVar10);
  if ((int)uVar28 == 0) {
    uVar12 = FUN_fffffff00996bb74(lVar11);
    *(undefined8 *)param_1[3] = uVar12;
  }
  else if ((int)puVar15 != 0) {
    local_88 = (undefined8 *)CONCAT44(local_88._4_4_,(int)uVar28);
    uVar28 = 0;
    uVar29 = 0x9e3779b97f4a7c15;
    lVar11 = plVar30[2];
    unaff_x25 = (ulong)puVar15 & 0xffffffff;
    do {
      lVar19 = uVar28 * 8;
      plVar31 = (long *)(lVar10 + (int)lVar19);
      if (lVar19 - (int)lVar19 != 0) {
        plVar31 = (long *)(lVar10 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar18 = (ulong)(*(long *)(*plVar31 + 0x70) * -0x61c8864680b583eb) >>
               ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
      param_3 = (uint *)((uVar18 & 0xffffffff) * 4);
      iVar16 = (int)param_3;
      puVar15 = (uint *)(lVar11 + iVar16);
      if ((long)param_3 - (long)iVar16 != 0) {
        puVar15 = (uint *)(lVar11 + (long)param_3 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar23 = *puVar15;
      puVar32 = param_2;
      do {
        if (uVar23 == 0) goto LAB_fffffff0099569f0;
        uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
        uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
        uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
        uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
        uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
        uVar24 = 1 << (ulong)(uVar21 & 0x1f);
        uVar23 = uVar23 & (uVar24 ^ 0xffffffff);
        uVar21 = uVar21 + (int)uVar18;
        param_2 = (undefined8 *)(ulong)uVar21;
        uVar22 = (ulong)(uVar21 & (int)plVar30[4] - 1U);
        lVar19 = uVar22 * 8;
        plVar2 = (long *)(*plVar30 + (long)(int)lVar19);
        if (lVar19 != (int)lVar19) {
          plVar2 = (long *)(*plVar30 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar32 = param_2;
      } while (*plVar2 != *(long *)(*plVar31 + 0x70));
      lVar19 = uVar22 * 0x10;
      unaff_x28 = (undefined8 *)(plVar30[1] + (long)(int)lVar19);
      if (lVar19 - (int)lVar19 != 0) {
        unaff_x28 = (undefined8 *)(plVar30[1] + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar19 = unaff_x28[1];
      unaff_x28[1] = lVar19 + -1;
      if (lVar19 + -1 == 0) {
        uVar24 = ~uVar24;
        param_1 = (undefined8 *)(ulong)uVar24;
        (**(code **)(*(long *)*unaff_x28 + 0x28))();
        *unaff_x28 = 0;
        lVar11 = plVar30[2];
        lVar19 = plVar30[3];
        puVar15 = (uint *)(lVar11 + iVar16);
        if ((long)param_3 - (long)iVar16 != 0) {
          puVar15 = (uint *)(lVar11 + (long)param_3 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar15 = *puVar15 & uVar24;
        uVar23 = *(uint *)(plVar30 + 5) & uVar21 >> 6;
        *(ulong *)(lVar19 + (ulong)uVar23 * 8) =
             *(ulong *)(lVar19 + (ulong)uVar23 * 8) &
             (1L << ((ulong)param_2 & 0x3f) ^ 0xffffffffffffffffU);
        *(int *)(plVar30 + 6) = (int)plVar30[6] + -1;
      }
      uVar28 = uVar28 + 1;
    } while (uVar28 != unaff_x25);
    uVar28 = (ulong)local_88 & 0xffffffff;
    param_1 = local_80;
  }
  goto LAB_fffffff0099569ac;
LAB_fffffff0099564c8:
  uVar23 = 0;
  uVar7 = (int)plVar30[4] - 1;
  uVar21 = *(uint *)(plVar30 + 5);
  uVar18 = uVar28 >> ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
  uVar17 = (uint)uVar18;
  uVar24 = uVar17 >> 6;
  lVar11 = plVar30[3];
  uVar22 = *(ulong *)(lVar11 + (ulong)uVar24 * 8) | -1L << (uVar18 & 0x3f) ^ 0xffffffffffffffffU;
  iVar27 = 0x40 - (uVar17 & 0x3f);
  iVar16 = uVar24 << 6;
  do {
    uVar24 = uVar24 + 1;
    if (uVar22 != 0xffffffffffffffff) {
      uVar22 = (~uVar22 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar22 & 0x5555555555555555) << 1;
      uVar22 = (uVar22 & 0xcccccccccccccccc) >> 2 | (uVar22 & 0x3333333333333333) << 2;
      uVar22 = (uVar22 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar22 = (uVar22 & 0xff00ff00ff00ff00) >> 8 | (uVar22 & 0xff00ff00ff00ff) << 8;
      uVar22 = (uVar22 & 0xffff0000ffff0000) >> 0x10 | (uVar22 & 0xffff0000ffff) << 0x10;
      uVar23 = (int)LZCOUNT(uVar22 >> 0x20 | uVar22 << 0x20) + iVar16;
      uVar22 = (ulong)uVar23;
      if (uVar23 - uVar17 < 0x80) goto LAB_fffffff009956334;
      break;
    }
    lVar19 = (ulong)(uVar24 & uVar21) * 8;
    puVar4 = (ulong *)(lVar11 + (int)lVar19);
    if (lVar19 != (int)lVar19) {
      puVar4 = (ulong *)(lVar11 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar23 = iVar27 + uVar23;
    uVar22 = *puVar4;
    iVar16 = iVar16 + 0x40;
    iVar27 = 0x40;
  } while (uVar23 < 0x80);
  goto LAB_fffffff009956564;
  while( true ) {
    uVar24 = uVar23 - 0x1f;
    if (0x1e < uVar23) {
      lVar19 = plVar30[2];
      uVar25 = 0xffffffe1;
      while( true ) {
        uVar24 = uVar23 + uVar25;
        puVar14 = (uint *)(ulong)(uVar24 & uVar7);
        lVar20 = (long)puVar14 * 4;
        puVar15 = (uint *)(lVar19 + (int)lVar20);
        if (lVar20 != (int)lVar20) {
          puVar15 = (uint *)(lVar19 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar5 = *puVar15;
        uVar6 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
        uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
        uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
        uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
        uVar13 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
        uVar6 = uVar24 + uVar13;
        if (uVar5 != 0 && uVar6 < uVar23) break;
        uVar25 = uVar25 + 1;
        if (!CARRY4(uVar23,uVar25)) goto LAB_fffffff009956564;
      }
      lVar20 = (long)puVar14 * 4;
      puVar14 = (uint *)(lVar19 + (int)lVar20);
      if (lVar20 - (int)lVar20 != 0) {
        puVar14 = (uint *)(lVar19 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar26 = (ulong)(uVar6 & uVar7) * 8;
      lVar19 = *plVar30;
      lVar20 = plVar30[1];
      iVar16 = (int)lVar26;
      puVar3 = (undefined8 *)(lVar19 + iVar16);
      if (lVar26 != iVar16) {
        puVar3 = (undefined8 *)(lVar19 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar8 = (ulong)(uVar6 & uVar7) * 0x10;
      iVar27 = (int)lVar8;
      puVar1 = (undefined8 *)(lVar20 + iVar27);
      if (lVar8 != iVar27) {
        puVar1 = (undefined8 *)(lVar20 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar12 = *puVar3;
      uStack_68 = puVar1[1];
      local_70 = *puVar1;
      *puVar14 = uVar5 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar25 & 0x1f);
      uVar25 = uVar21 & uVar23 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar25 * 8) | 1L << (uVar22 & 0x3f);
      lVar11 = (ulong)(uVar23 & uVar7) * 8;
      puVar3 = (undefined8 *)(lVar19 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar3 = (undefined8 *)(lVar19 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = uVar12;
      lVar11 = (ulong)(uVar23 & uVar7) * 0x10;
      puVar3 = (undefined8 *)(lVar20 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar3 = (undefined8 *)(lVar20 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar3[1] = uStack_68;
      *puVar3 = local_70;
      puVar3 = (undefined8 *)(*plVar30 + (long)iVar16);
      if (lVar26 != iVar16) {
        puVar3 = (undefined8 *)(*plVar30 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar1 = (undefined8 *)(plVar30[1] + (long)iVar27);
      if (lVar8 != iVar27) {
        puVar1 = (undefined8 *)(plVar30[1] + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 0;
      *puVar1 = 0;
      lVar11 = plVar30[3];
      uVar25 = uVar21 & uVar6 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar25 * 8) &
           (1L << ((ulong)uVar6 & 0x3f) ^ 0xffffffffffffffffU);
      uVar22 = (ulong)uVar6;
    }
    if (uVar24 == uVar23) break;
LAB_fffffff009956334:
    uVar23 = (uint)uVar22;
    if (uVar23 - uVar17 < 0x20) {
      lVar20 = (ulong)(uVar23 & uVar7) * 8;
      lVar19 = plVar30[1];
      puVar3 = (undefined8 *)(*plVar30 + (long)(int)lVar20);
      if (lVar20 != (int)lVar20) {
        puVar3 = (undefined8 *)(*plVar30 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = puVar32;
      lVar20 = (ulong)(uVar23 & uVar7) * 0x10;
      puVar32 = (undefined8 *)(lVar19 + (int)lVar20);
      if (lVar20 != (int)lVar20) {
        puVar32 = (undefined8 *)(lVar19 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar32 = param_3;
      puVar32[1] = 1;
      lVar19 = (uVar18 & 0xffffffff) * 4;
      puVar15 = (uint *)(plVar30[2] + (long)(int)lVar19);
      if (lVar19 != (int)lVar19) {
        puVar15 = (uint *)(plVar30[2] + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar15 = *puVar15 | 1 << (ulong)(uVar23 - uVar17 & 0x1f);
      uVar21 = uVar21 & uVar23 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar21 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar21 * 8) | 1L << (uVar22 & 0x3f);
      *(int *)(plVar30 + 6) = (int)plVar30[6] + 1;
      (**(code **)(*(long *)param_3 + 0x20))(param_3);
      lVar11 = ((ulong)local_78 & 0xffffffff) * 8;
      local_78 = (uint *)(ulong)((int)local_78 + 1);
      puVar32 = (undefined8 *)(lVar10 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar32 = (undefined8 *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar32 = param_3;
      goto LAB_fffffff00995664c;
    }
  }
LAB_fffffff009956564:
  uVar18 = FUN_fffffff0099582a4(plVar30);
  if ((uVar18 & 1) == 0) {
    if ((int)local_78 == 0) goto LAB_fffffff0099567d8;
    uVar28 = 0;
    uVar29 = (ulong)local_78 & 0xffffffff;
    lVar11 = plVar30[2];
    param_1 = (undefined8 *)0x9e3779b97f4a7c15;
    goto LAB_fffffff009956694;
  }
  goto LAB_fffffff0099564c8;
LAB_fffffff009956f58:
  uVar23 = 0;
  uVar7 = (int)plVar30[4] - 1;
  uVar21 = *(uint *)(plVar30 + 5);
  uVar29 = (ulong)(lVar11 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
  uVar17 = (uint)uVar29;
  uVar24 = uVar17 >> 6;
  lVar10 = plVar30[3];
  uVar18 = *(ulong *)(lVar10 + (ulong)uVar24 * 8) | -1L << (uVar29 & 0x3f) ^ 0xffffffffffffffffU;
  iVar27 = 0x40 - (uVar17 & 0x3f);
  iVar16 = uVar24 << 6;
  do {
    uVar24 = uVar24 + 1;
    if (uVar18 != 0xffffffffffffffff) {
      uVar18 = (~uVar18 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar18 & 0x5555555555555555) << 1;
      uVar18 = (uVar18 & 0xcccccccccccccccc) >> 2 | (uVar18 & 0x3333333333333333) << 2;
      uVar18 = (uVar18 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar18 = (uVar18 & 0xff00ff00ff00ff00) >> 8 | (uVar18 & 0xff00ff00ff00ff) << 8;
      uVar18 = (uVar18 & 0xffff0000ffff0000) >> 0x10 | (uVar18 & 0xffff0000ffff) << 0x10;
      uVar23 = (int)LZCOUNT(uVar18 >> 0x20 | uVar18 << 0x20) + iVar16;
      uVar18 = (ulong)uVar23;
      if (uVar23 - uVar17 < 0x80) goto LAB_fffffff009956dc4;
      break;
    }
    lVar20 = (ulong)(uVar24 & uVar21) * 8;
    puVar4 = (ulong *)(lVar10 + (int)lVar20);
    if (lVar20 != (int)lVar20) {
      puVar4 = (ulong *)(lVar10 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar23 = iVar27 + uVar23;
    uVar18 = *puVar4;
    iVar16 = iVar16 + 0x40;
    iVar27 = 0x40;
  } while (uVar23 < 0x80);
  goto LAB_fffffff009956ff4;
  while( true ) {
    uVar24 = uVar23 - 0x1f;
    if (0x1e < uVar23) {
      lVar20 = plVar30[2];
      uVar25 = 0xffffffe1;
      while( true ) {
        uVar24 = uVar23 + uVar25;
        lVar26 = (ulong)(uVar24 & uVar7) * 4;
        puVar14 = (uint *)(lVar20 + (int)lVar26);
        if (lVar26 != (int)lVar26) {
          puVar14 = (uint *)(lVar20 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar5 = *puVar14;
        uVar6 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
        uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
        uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
        uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
        uVar13 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
        uVar6 = uVar24 + uVar13;
        if (uVar5 != 0 && uVar6 < uVar23) break;
        uVar25 = uVar25 + 1;
        if (!CARRY4(uVar23,uVar25)) goto LAB_fffffff009956ff4;
      }
      lVar26 = (ulong)(uVar24 & uVar7) * 4;
      puVar14 = (uint *)(lVar20 + (int)lVar26);
      if (lVar26 - (int)lVar26 != 0) {
        puVar14 = (uint *)(lVar20 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar8 = (ulong)(uVar6 & uVar7) * 8;
      lVar20 = *plVar30;
      lVar26 = plVar30[1];
      iVar16 = (int)lVar8;
      puVar32 = (undefined8 *)(lVar20 + iVar16);
      if (lVar8 != iVar16) {
        puVar32 = (undefined8 *)(lVar20 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar9 = (ulong)(uVar6 & uVar7) * 0x10;
      iVar27 = (int)lVar9;
      puVar3 = (undefined8 *)(lVar26 + iVar27);
      if (lVar9 != iVar27) {
        puVar3 = (undefined8 *)(lVar26 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar12 = *puVar32;
      uVar34 = puVar3[1];
      uVar33 = *puVar3;
      *puVar14 = uVar5 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar25 & 0x1f);
      uVar25 = uVar21 & uVar23 >> 6;
      *(ulong *)(lVar10 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar10 + (ulong)uVar25 * 8) | 1L << (uVar18 & 0x3f);
      lVar10 = (ulong)(uVar23 & uVar7) * 8;
      puVar32 = (undefined8 *)(lVar20 + (int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar32 = (undefined8 *)(lVar20 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar32 = uVar12;
      lVar10 = (ulong)(uVar23 & uVar7) * 0x10;
      puVar32 = (undefined8 *)(lVar26 + (int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar32 = (undefined8 *)(lVar26 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar32[1] = uVar34;
      *puVar32 = uVar33;
      puVar32 = (undefined8 *)(*plVar30 + (long)iVar16);
      if (lVar8 != iVar16) {
        puVar32 = (undefined8 *)(*plVar30 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar3 = (undefined8 *)(plVar30[1] + (long)iVar27);
      if (lVar9 != iVar27) {
        puVar3 = (undefined8 *)(plVar30[1] + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar32 = 0;
      *puVar3 = 0;
      lVar10 = plVar30[3];
      uVar25 = uVar21 & uVar6 >> 6;
      *(ulong *)(lVar10 + (ulong)uVar25 * 8) =
           *(ulong *)(lVar10 + (ulong)uVar25 * 8) &
           (1L << ((ulong)uVar6 & 0x3f) ^ 0xffffffffffffffffU);
      uVar18 = (ulong)uVar6;
    }
    if (uVar24 == uVar23) break;
LAB_fffffff009956dc4:
    uVar23 = (uint)uVar18;
    if (uVar23 - uVar17 < 0x20) {
      lVar26 = (ulong)(uVar23 & uVar7) * 8;
      lVar20 = plVar30[1];
      plVar2 = (long *)(*plVar30 + (long)(int)lVar26);
      if (lVar26 != (int)lVar26) {
        plVar2 = (long *)(*plVar30 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar2 = lVar11;
      lVar11 = (ulong)(uVar23 & uVar7) * 0x10;
      puVar32 = (undefined8 *)(lVar20 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar32 = (undefined8 *)(lVar20 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar32 = plVar31;
      puVar32[1] = 1;
      lVar11 = (uVar29 & 0xffffffff) * 4;
      puVar14 = (uint *)(plVar30[2] + (long)(int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar14 = (uint *)(plVar30[2] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar14 = *puVar14 | 1 << (ulong)(uVar23 - uVar17 & 0x1f);
      uVar21 = uVar21 & uVar23 >> 6;
      *(ulong *)(lVar10 + (ulong)uVar21 * 8) =
           *(ulong *)(lVar10 + (ulong)uVar21 * 8) | 1L << (uVar18 & 0x3f);
      *(int *)(plVar30 + 6) = (int)plVar30[6] + 1;
      (**(code **)(*plVar31 + 0x20))(plVar31);
      alStack_980[uStack_994] = (long)plVar31;
      uStack_994 = uStack_994 + 1;
      goto LAB_fffffff0099570c4;
    }
  }
LAB_fffffff009956ff4:
  uVar29 = FUN_fffffff0099582a4(plVar30);
  if ((uVar29 & 1) == 0) {
    if (uStack_994 == 0) goto LAB_fffffff00995722c;
    uVar28 = 0;
    lVar10 = plVar30[2];
    goto LAB_fffffff009957100;
  }
  goto LAB_fffffff009956f58;
LAB_fffffff009957100:
  do {
    uVar29 = (ulong)(*(long *)(alStack_980[uVar28] + 0x70) * -0x61c8864680b583eb) >>
             ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
    lVar11 = (uVar29 & 0xffffffff) * 4;
    iVar16 = (int)lVar11;
    puVar14 = (uint *)(lVar10 + iVar16);
    if (lVar11 - iVar16 != 0) {
      puVar14 = (uint *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar23 = *puVar14;
    do {
      if (uVar23 == 0) {
        FUN_fffffff0099839b0();
        goto LAB_fffffff009957434;
      }
      uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
      uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
      uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
      uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
      uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
      uVar24 = 1 << (ulong)(uVar21 & 0x1f);
      uVar23 = uVar23 & (uVar24 ^ 0xffffffff);
      uVar21 = uVar21 + (int)uVar29;
      uVar18 = (ulong)(uVar21 & (int)plVar30[4] - 1U);
      lVar20 = uVar18 * 8;
      plVar31 = (long *)(*plVar30 + (long)(int)lVar20);
      if (lVar20 != (int)lVar20) {
        plVar31 = (long *)(*plVar30 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
      }
    } while (*plVar31 != *(long *)(alStack_980[uVar28] + 0x70));
    lVar20 = uVar18 * 0x10;
    puVar32 = (undefined8 *)(plVar30[1] + (long)(int)lVar20);
    if (lVar20 - (int)lVar20 != 0) {
      puVar32 = (undefined8 *)(plVar30[1] + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar20 = puVar32[1];
    puVar32[1] = lVar20 + -1;
    if (lVar20 + -1 == 0) {
      (**(code **)(*(long *)*puVar32 + 0x28))();
      *puVar32 = 0;
      lVar10 = plVar30[2];
      lVar20 = plVar30[3];
      puVar14 = (uint *)(lVar10 + iVar16);
      if (lVar11 - iVar16 != 0) {
        puVar14 = (uint *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar14 = *puVar14 & ~uVar24;
      uVar23 = *(uint *)(plVar30 + 5) & uVar21 >> 6;
      *(ulong *)(lVar20 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar20 + (ulong)uVar23 * 8) &
           (1L << ((ulong)uVar21 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(plVar30 + 6) = (int)plVar30[6] + -1;
    }
    uVar28 = uVar28 + 1;
  } while (uVar28 != uStack_994);
LAB_fffffff00995722c:
  uVar28 = 0xe00002bd;
LAB_fffffff0099573ec:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x60));
  auVar35._8_8_ = lStack_160;
  auVar35._0_8_ = lStack_128;
  goto LAB_fffffff0099573f4;
LAB_fffffff009957434:
  FUN_fffffff009983a10();
LAB_fffffff009957438:
  FUN_fffffff0099839e0();
  auVar35._8_8_ = lStack_160;
  auVar35._0_8_ = lStack_128;
LAB_fffffff00995743c:
  lStack_160 = auVar35._8_8_;
  lStack_128 = auVar35._0_8_;
  FUN_fffffff009983a64();
  auVar35._8_8_ = lStack_160;
  auVar35._0_8_ = lStack_128;
  goto LAB_fffffff009957440;
LAB_fffffff0099569f0:
  unaff_x24 = 1;
  FUN_fffffff009983938();
LAB_fffffff0099569f4:
  FUN_fffffff009983908();
LAB_fffffff0099569f8:
  auVar35 = FUN_fffffff009983968();
  lVar11 = auVar35._0_8_;
  pcStack_98 = FUN_fffffff0099569fc;
  if (*(char *)(lVar11 + 0x10) != '\x03') {
    return 0xe00002c7;
  }
  puVar15 = puVar14;
  puStack_f0 = unaff_x28;
  puStack_e8 = puVar32;
  puStack_e0 = param_3;
  uStack_d8 = unaff_x25;
  uStack_d0 = unaff_x24;
  plStack_c8 = plVar30;
  lStack_c0 = lVar10;
  uStack_b8 = uVar29;
  uStack_b0 = uVar28;
  puStack_a8 = param_1;
  puStack_a0 = &stack0xfffffffffffffff0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x60));
  plVar30 = *(long **)(lVar11 + 0x30);
  lStack_108 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar11 + 0x28),DAT_fffffff007fed428);
  if (lStack_108 != 0) {
    lStack_100 = lVar11;
    FUN_fffffff009942d70();
    if ((int)puVar14 == 0) {
      uVar29 = 0;
    }
    else {
      uVar28 = 0;
      uVar29 = 0;
      lVar10 = plVar30[2];
      do {
        lVar11 = *(long *)(auVar35._8_8_ + uVar28 * 8);
        uVar18 = (ulong)(lVar11 * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
        lVar19 = (uVar18 & 0xffffffff) * 4;
        iVar16 = (int)lVar19;
        puVar15 = (uint *)(lVar10 + iVar16);
        if (lVar19 - iVar16 != 0) {
          puVar15 = (uint *)(lVar10 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar23 = *puVar15;
        do {
          if (uVar23 == 0) {
            uVar29 = 0xe00002c2;
            goto LAB_fffffff009956bec;
          }
          uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
          uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
          uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
          uVar24 = 1 << (ulong)(uVar21 & 0x1f);
          uVar23 = uVar23 & (uVar24 ^ 0xffffffff);
          uVar21 = uVar21 + (int)uVar18;
          uVar22 = (ulong)(uVar21 & (int)plVar30[4] - 1U);
          lVar20 = uVar22 * 8;
          plVar31 = (long *)(*plVar30 + (long)(int)lVar20);
          if (lVar20 != (int)lVar20) {
            plVar31 = (long *)(*plVar30 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar31 != lVar11);
        lVar11 = uVar22 * 0x10;
        puVar32 = (undefined8 *)(plVar30[1] + (long)(int)lVar11);
        if (lVar11 - (int)lVar11 != 0) {
          puVar32 = (undefined8 *)(plVar30[1] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar11 = puVar32[1];
        puVar32[1] = lVar11 + -1;
        if (lVar11 + -1 == 0) {
          uStack_f4 = ~uVar24;
          FUN_fffffff00996ae10(lStack_108,*puVar32,*(uint *)(lStack_100 + 0x10) >> 0x17 & 1);
          (**(code **)(*(long *)*puVar32 + 0x28))();
          *puVar32 = 0;
          lVar10 = plVar30[2];
          lVar11 = plVar30[3];
          puVar15 = (uint *)(lVar10 + iVar16);
          if (lVar19 - iVar16 != 0) {
            puVar15 = (uint *)(lVar10 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar15 = *puVar15 & uStack_f4;
          uVar23 = *(uint *)(plVar30 + 5) & uVar21 >> 6;
          *(ulong *)(lVar11 + (ulong)uVar23 * 8) =
               *(ulong *)(lVar11 + (ulong)uVar23 * 8) &
               (1L << ((ulong)uVar21 & 0x3f) ^ 0xffffffffffffffffU);
          *(int *)(plVar30 + 6) = (int)plVar30[6] + -1;
        }
LAB_fffffff009956bec:
        uVar28 = uVar28 + 1;
      } while (uVar28 != ((ulong)puVar14 & 0xffffffff));
    }
    lVar10 = lStack_108;
    FUN_fffffff009942d7c(lStack_108);
    uVar12 = FUN_fffffff00996bb74(lVar10);
    **(undefined8 **)(lStack_100 + 0x18) = uVar12;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lStack_100 + 0x60));
    return uVar29;
  }
  auVar36 = FUN_fffffff00998398c();
  lVar19 = auVar36._0_8_;
  pcStack_118 = FUN_fffffff009956c5c;
  lStack_180 = *(long *)PTR_DAT_fffffff007ff2800;
  puStack_170 = unaff_x28;
  puStack_168 = puVar32;
  uStack_158 = unaff_x25;
  plStack_150 = plVar30;
  puStack_148 = puVar14;
  lStack_140 = lVar10;
  uStack_138 = uVar29;
  uStack_130 = uVar28;
  ppuStack_120 = &puStack_a0;
  if (0x100 < (uint)puVar15) goto LAB_fffffff00995743c;
  if (*(char *)(lVar19 + 0x10) == '\x03') {
    lStack_160 = auVar35._8_8_;
    lStack_128 = lVar11;
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar19 + 0x60));
    plVar30 = *(long **)(lVar19 + 0x30);
    if ((uint)puVar15 == 0) {
      uStack_994 = 0;
    }
    else {
      uVar28 = 0;
      uStack_994 = 0;
      do {
        plVar31 = *(long **)(auVar36._8_8_ + uVar28 * 8);
        if ((plVar31 == (long *)0x0) || ((char)plVar31[2] == '\x03')) goto LAB_fffffff009957438;
        lVar11 = plVar31[0xe];
        uVar29 = (ulong)(lVar11 * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
        lVar10 = (uVar29 & 0xffffffff) * 4;
        puVar14 = (uint *)(plVar30[2] + (long)(int)lVar10);
        if (lVar10 != (int)lVar10) {
          puVar14 = (uint *)(plVar30[2] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar23 = *puVar14;
        do {
          if (uVar23 == 0) goto LAB_fffffff009956f58;
          uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
          uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
          uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
          uVar23 = uVar23 & (1 << (ulong)(uVar21 & 0x1f) ^ 0xffffffffU);
          uVar18 = (ulong)(uVar21 + (int)uVar29 & (int)plVar30[4] - 1U);
          lVar10 = uVar18 * 8;
          plVar2 = (long *)(*plVar30 + (long)(int)lVar10);
          if (lVar10 != (int)lVar10) {
            plVar2 = (long *)(*plVar30 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar2 != lVar11);
        uVar29 = uVar18 << 4 | 8;
        plVar31 = (long *)(plVar30[1] + (long)(int)uVar29);
        if (uVar29 != (long)(int)uVar29) {
          plVar31 = (long *)(plVar30[1] + uVar29 & 0xffffffffffff | 0x2bad000000000000);
        }
        *plVar31 = *plVar31 + 1;
LAB_fffffff0099570c4:
        uVar28 = uVar28 + 1;
      } while (uVar28 != ((ulong)puVar15 & 0xffffffff));
    }
    lVar10 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar19 + 0x28),DAT_fffffff007fed428);
    if (lVar10 == 0) {
      lVar10 = FUN_fffffff009983a40();
      uVar28 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar10 + 0x28),DAT_fffffff007fefaf0);
      if (uVar28 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: memory is not a sysmemory\n");
        uVar28 = 0;
      }
      else if (((*(uint *)(lVar10 + 0x10) & 0x2000ff) != 0x80) || (*(long *)(lVar10 + 0x30) != 0)) {
        uVar28 = 0;
      }
      return uVar28;
    }
    uVar28 = FUN_fffffff009968ef0(lVar10,alStack_980,uStack_994);
    if ((int)uVar28 == 0) {
      uVar12 = FUN_fffffff00996bb74(lVar10);
      **(undefined8 **)(lVar19 + 0x18) = uVar12;
    }
    else if (uStack_994 != 0) {
      uVar29 = 0;
      lVar10 = plVar30[2];
      do {
        uVar18 = (ulong)(*(long *)(alStack_980[uVar29] + 0x70) * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
        lVar11 = (uVar18 & 0xffffffff) * 4;
        iVar16 = (int)lVar11;
        puVar14 = (uint *)(lVar10 + iVar16);
        if (lVar11 - iVar16 != 0) {
          puVar14 = (uint *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar23 = *puVar14;
        do {
          if (uVar23 == 0) goto LAB_fffffff009957434;
          uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
          uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
          uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
          uVar24 = 1 << (ulong)(uVar21 & 0x1f);
          uVar23 = uVar23 & (uVar24 ^ 0xffffffff);
          uVar21 = uVar21 + (int)uVar18;
          uVar22 = (ulong)(uVar21 & (int)plVar30[4] - 1U);
          lVar20 = uVar22 * 8;
          plVar31 = (long *)(*plVar30 + (long)(int)lVar20);
          if (lVar20 != (int)lVar20) {
            plVar31 = (long *)(*plVar30 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar31 != *(long *)(alStack_980[uVar29] + 0x70));
        lVar20 = uVar22 * 0x10;
        puVar32 = (undefined8 *)(plVar30[1] + (long)(int)lVar20);
        if (lVar20 - (int)lVar20 != 0) {
          puVar32 = (undefined8 *)(plVar30[1] + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar20 = puVar32[1];
        puVar32[1] = lVar20 + -1;
        if (lVar20 + -1 == 0) {
          (**(code **)(*(long *)*puVar32 + 0x28))();
          *puVar32 = 0;
          lVar10 = plVar30[2];
          lVar20 = plVar30[3];
          puVar14 = (uint *)(lVar10 + iVar16);
          if (lVar11 - iVar16 != 0) {
            puVar14 = (uint *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar14 = *puVar14 & ~uVar24;
          uVar23 = *(uint *)(plVar30 + 5) & uVar21 >> 6;
          *(ulong *)(lVar20 + (ulong)uVar23 * 8) =
               *(ulong *)(lVar20 + (ulong)uVar23 * 8) &
               (1L << ((ulong)uVar21 & 0x3f) ^ 0xffffffffffffffffU);
          *(int *)(plVar30 + 6) = (int)plVar30[6] + -1;
        }
        uVar29 = uVar29 + 1;
      } while (uVar29 != uStack_994);
      uVar28 = uVar28 & 0xffffffff;
    }
    goto LAB_fffffff0099573ec;
  }
  uVar28 = 0xe00002c7;
LAB_fffffff0099573f4:
  if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_180) {
    return uVar28;
  }
LAB_fffffff009957440:
  lStack_160 = auVar35._8_8_;
  lStack_128 = auVar35._0_8_;
  uVar28 = thunk_EXT_FUN_8011000003a48590();
  return uVar28;
LAB_fffffff009956694:
  do {
    lVar19 = uVar28 * 8;
    plVar31 = (long *)(lVar10 + (int)lVar19);
    if (lVar19 - (int)lVar19 != 0) {
      plVar31 = (long *)(lVar10 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar18 = (ulong)(*(long *)(*plVar31 + 0x70) * -0x61c8864680b583eb) >>
             ((ulong)(uint)-*(int *)((long)plVar30 + 0x2c) & 0x3f);
    unaff_x25 = (uVar18 & 0xffffffff) * 4;
    iVar16 = (int)unaff_x25;
    puVar15 = (uint *)(lVar11 + iVar16);
    if (unaff_x25 - (long)iVar16 != 0) {
      puVar15 = (uint *)(lVar11 + unaff_x25 & 0xffffffffffff | 0x2bad000000000000);
    }
    uVar23 = *puVar15;
    do {
      if (uVar23 == 0) {
        FUN_fffffff0099838d8();
        goto LAB_fffffff0099569f0;
      }
      uVar21 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
      uVar21 = (uVar21 & 0xcccccccc) >> 2 | (uVar21 & 0x33333333) << 2;
      uVar21 = (uVar21 & 0xf0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f) << 4;
      uVar21 = (uVar21 & 0xff00ff00) >> 8 | (uVar21 & 0xff00ff) << 8;
      uVar21 = (uint)LZCOUNT(uVar21 >> 0x10 | uVar21 << 0x10);
      uVar24 = 1 << (ulong)(uVar21 & 0x1f);
      uVar23 = uVar23 & (uVar24 ^ 0xffffffff);
      uVar21 = uVar21 + (int)uVar18;
      param_3 = (uint *)(ulong)uVar21;
      uVar22 = (ulong)(uVar21 & (int)plVar30[4] - 1U);
      lVar19 = uVar22 * 8;
      plVar2 = (long *)(*plVar30 + (long)(int)lVar19);
      if (lVar19 != (int)lVar19) {
        plVar2 = (long *)(*plVar30 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
    } while (*plVar2 != *(long *)(*plVar31 + 0x70));
    lVar19 = uVar22 * 0x10;
    puVar32 = (undefined8 *)(plVar30[1] + (long)(int)lVar19);
    if (lVar19 - (int)lVar19 != 0) {
      puVar32 = (undefined8 *)(plVar30[1] + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar19 = puVar32[1];
    puVar32[1] = lVar19 + -1;
    if (lVar19 + -1 == 0) {
      uVar24 = ~uVar24;
      unaff_x28 = (undefined8 *)(ulong)uVar24;
      (**(code **)(*(long *)*puVar32 + 0x28))();
      *puVar32 = 0;
      lVar11 = plVar30[2];
      lVar19 = plVar30[3];
      puVar15 = (uint *)(lVar11 + iVar16);
      if (unaff_x25 - (long)iVar16 != 0) {
        puVar15 = (uint *)(lVar11 + unaff_x25 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar15 = *puVar15 & uVar24;
      uVar23 = *(uint *)(plVar30 + 5) & uVar21 >> 6;
      *(ulong *)(lVar19 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar19 + (ulong)uVar23 * 8) &
           (1L << ((ulong)param_3 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(plVar30 + 6) = (int)plVar30[6] + -1;
    }
    uVar28 = uVar28 + 1;
  } while (uVar28 != uVar29);
LAB_fffffff0099567d8:
  uVar28 = 0xe00002bd;
  param_1 = local_80;
LAB_fffffff0099569ac:
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1368,lVar10,local_90);
LAB_fffffff0099569c0:
  thunk_EXT_FUN_8011000003222de0(param_1[0xc]);
  return uVar28;
}

