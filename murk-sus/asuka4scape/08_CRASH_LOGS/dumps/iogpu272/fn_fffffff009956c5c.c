// FUN_fffffff009956c5c @ fffffff009956c5c size=2028

ulong FUN_fffffff009956c5c(long param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulong *puVar3;
  long *plVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  long lVar24;
  int iVar25;
  long *plVar26;
  long lVar27;
  long *plVar28;
  ulong uVar29;
  undefined8 uVar30;
  undefined8 uVar31;
  uint local_884;
  long local_870 [256];
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ff2800;
  if (0x100 < param_3) goto LAB_fffffff00995743c;
  if (*(char *)(param_1 + 0x10) == '\x03') {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x60));
    plVar26 = *(long **)(param_1 + 0x30);
    if (param_3 == 0) {
      local_884 = 0;
    }
    else {
      uVar29 = 0;
      local_884 = 0;
      do {
        plVar28 = *(long **)(param_2 + uVar29 * 8);
        if ((plVar28 == (long *)0x0) || ((char)plVar28[2] == '\x03')) goto LAB_fffffff009957438;
        lVar27 = plVar28[0xe];
        uVar16 = (ulong)(lVar27 * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar26 + 0x2c) & 0x3f);
        lVar11 = (uVar16 & 0xffffffff) * 4;
        puVar5 = (uint *)(plVar26[2] + (long)(int)lVar11);
        if (lVar11 != (int)lVar11) {
          puVar5 = (uint *)(plVar26[2] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar20 = *puVar5;
        do {
          if (uVar20 == 0) goto LAB_fffffff009956f58;
          uVar18 = (uVar20 & 0xaaaaaaaa) >> 1 | (uVar20 & 0x55555555) << 1;
          uVar18 = (uVar18 & 0xcccccccc) >> 2 | (uVar18 & 0x33333333) << 2;
          uVar18 = (uVar18 & 0xf0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f) << 4;
          uVar18 = (uVar18 & 0xff00ff00) >> 8 | (uVar18 & 0xff00ff) << 8;
          uVar18 = (uint)LZCOUNT(uVar18 >> 0x10 | uVar18 << 0x10);
          uVar20 = uVar20 & (1 << (ulong)(uVar18 & 0x1f) ^ 0xffffffffU);
          uVar19 = (ulong)(uVar18 + (int)uVar16 & (int)plVar26[4] - 1U);
          lVar11 = uVar19 * 8;
          plVar4 = (long *)(*plVar26 + (long)(int)lVar11);
          if (lVar11 != (int)lVar11) {
            plVar4 = (long *)(*plVar26 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar4 != lVar27);
        uVar16 = uVar19 << 4 | 8;
        plVar28 = (long *)(plVar26[1] + (long)(int)uVar16);
        if (uVar16 != (long)(int)uVar16) {
          plVar28 = (long *)(plVar26[1] + uVar16 & 0xffffffffffff | 0x2bad000000000000);
        }
        *plVar28 = *plVar28 + 1;
LAB_fffffff0099570c4:
        uVar29 = uVar29 + 1;
      } while (uVar29 != param_3);
    }
    lVar11 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fed428);
    if (lVar11 == 0) {
      lVar11 = FUN_fffffff009983a40();
      uVar29 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar11 + 0x28),DAT_fffffff007fefaf0);
      if (uVar29 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: memory is not a sysmemory\n");
        uVar29 = 0;
      }
      else if (((*(uint *)(lVar11 + 0x10) & 0x2000ff) != 0x80) || (*(long *)(lVar11 + 0x30) != 0)) {
        uVar29 = 0;
      }
      return uVar29;
    }
    uVar29 = FUN_fffffff009968ef0(lVar11,local_870,local_884);
    if ((int)uVar29 == 0) {
      uVar12 = FUN_fffffff00996bb74(lVar11);
      **(undefined8 **)(param_1 + 0x18) = uVar12;
    }
    else if (local_884 != 0) {
      uVar16 = 0;
      lVar11 = plVar26[2];
      do {
        uVar19 = (ulong)(*(long *)(local_870[uVar16] + 0x70) * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar26 + 0x2c) & 0x3f);
        lVar27 = (uVar19 & 0xffffffff) * 4;
        iVar14 = (int)lVar27;
        puVar5 = (uint *)(lVar11 + iVar14);
        if (lVar27 - iVar14 != 0) {
          puVar5 = (uint *)(lVar11 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar20 = *puVar5;
        do {
          if (uVar20 == 0) goto LAB_fffffff009957434;
          uVar18 = (uVar20 & 0xaaaaaaaa) >> 1 | (uVar20 & 0x55555555) << 1;
          uVar18 = (uVar18 & 0xcccccccc) >> 2 | (uVar18 & 0x33333333) << 2;
          uVar18 = (uVar18 & 0xf0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f) << 4;
          uVar18 = (uVar18 & 0xff00ff00) >> 8 | (uVar18 & 0xff00ff) << 8;
          uVar18 = (uint)LZCOUNT(uVar18 >> 0x10 | uVar18 << 0x10);
          uVar21 = 1 << (ulong)(uVar18 & 0x1f);
          uVar20 = uVar20 & (uVar21 ^ 0xffffffff);
          uVar18 = uVar18 + (int)uVar19;
          uVar22 = (ulong)(uVar18 & (int)plVar26[4] - 1U);
          lVar17 = uVar22 * 8;
          plVar28 = (long *)(*plVar26 + (long)(int)lVar17);
          if (lVar17 != (int)lVar17) {
            plVar28 = (long *)(*plVar26 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar28 != *(long *)(local_870[uVar16] + 0x70));
        lVar17 = uVar22 * 0x10;
        puVar1 = (undefined8 *)(plVar26[1] + (long)(int)lVar17);
        if (lVar17 - (int)lVar17 != 0) {
          puVar1 = (undefined8 *)(plVar26[1] + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar17 = puVar1[1];
        puVar1[1] = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          (**(code **)(*(long *)*puVar1 + 0x28))();
          *puVar1 = 0;
          lVar11 = plVar26[2];
          lVar17 = plVar26[3];
          puVar5 = (uint *)(lVar11 + iVar14);
          if (lVar27 - iVar14 != 0) {
            puVar5 = (uint *)(lVar11 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar5 = *puVar5 & ~uVar21;
          uVar20 = *(uint *)(plVar26 + 5) & uVar18 >> 6;
          *(ulong *)(lVar17 + (ulong)uVar20 * 8) =
               *(ulong *)(lVar17 + (ulong)uVar20 * 8) &
               (1L << ((ulong)uVar18 & 0x3f) ^ 0xffffffffffffffffU);
          *(int *)(plVar26 + 6) = (int)plVar26[6] + -1;
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 != local_884);
      uVar29 = uVar29 & 0xffffffff;
    }
    goto LAB_fffffff0099573ec;
  }
  uVar29 = 0xe00002c7;
  goto LAB_fffffff0099573f4;
LAB_fffffff009956f58:
  uVar20 = 0;
  uVar8 = (int)plVar26[4] - 1;
  uVar18 = *(uint *)(plVar26 + 5);
  uVar16 = (ulong)(lVar27 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)plVar26 + 0x2c) & 0x3f);
  uVar15 = (uint)uVar16;
  uVar21 = uVar15 >> 6;
  lVar11 = plVar26[3];
  uVar19 = *(ulong *)(lVar11 + (ulong)uVar21 * 8) | -1L << (uVar16 & 0x3f) ^ 0xffffffffffffffffU;
  iVar25 = 0x40 - (uVar15 & 0x3f);
  iVar14 = uVar21 << 6;
  do {
    uVar21 = uVar21 + 1;
    if (uVar19 != 0xffffffffffffffff) {
      uVar19 = (~uVar19 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar19 & 0x5555555555555555) << 1;
      uVar19 = (uVar19 & 0xcccccccccccccccc) >> 2 | (uVar19 & 0x3333333333333333) << 2;
      uVar19 = (uVar19 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar19 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar19 = (uVar19 & 0xff00ff00ff00ff00) >> 8 | (uVar19 & 0xff00ff00ff00ff) << 8;
      uVar19 = (uVar19 & 0xffff0000ffff0000) >> 0x10 | (uVar19 & 0xffff0000ffff) << 0x10;
      uVar20 = (int)LZCOUNT(uVar19 >> 0x20 | uVar19 << 0x20) + iVar14;
      uVar19 = (ulong)uVar20;
      if (uVar20 - uVar15 < 0x80) goto LAB_fffffff009956dc4;
      break;
    }
    lVar17 = (ulong)(uVar21 & uVar18) * 8;
    puVar3 = (ulong *)(lVar11 + (int)lVar17);
    if (lVar17 != (int)lVar17) {
      puVar3 = (ulong *)(lVar11 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar20 = iVar25 + uVar20;
    uVar19 = *puVar3;
    iVar14 = iVar14 + 0x40;
    iVar25 = 0x40;
  } while (uVar20 < 0x80);
  goto LAB_fffffff009956ff4;
  while( true ) {
    uVar21 = uVar20 - 0x1f;
    if (0x1e < uVar20) {
      lVar17 = plVar26[2];
      uVar23 = 0xffffffe1;
      while( true ) {
        uVar21 = uVar20 + uVar23;
        lVar24 = (ulong)(uVar21 & uVar8) * 4;
        puVar5 = (uint *)(lVar17 + (int)lVar24);
        if (lVar24 != (int)lVar24) {
          puVar5 = (uint *)(lVar17 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar6 = *puVar5;
        uVar7 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
        uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
        uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
        uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
        uVar13 = (uint)LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
        uVar7 = uVar21 + uVar13;
        if (uVar6 != 0 && uVar7 < uVar20) break;
        uVar23 = uVar23 + 1;
        if (!CARRY4(uVar20,uVar23)) goto LAB_fffffff009956ff4;
      }
      lVar24 = (ulong)(uVar21 & uVar8) * 4;
      puVar5 = (uint *)(lVar17 + (int)lVar24);
      if (lVar24 - (int)lVar24 != 0) {
        puVar5 = (uint *)(lVar17 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar9 = (ulong)(uVar7 & uVar8) * 8;
      lVar17 = *plVar26;
      lVar24 = plVar26[1];
      iVar14 = (int)lVar9;
      puVar1 = (undefined8 *)(lVar17 + iVar14);
      if (lVar9 != iVar14) {
        puVar1 = (undefined8 *)(lVar17 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar10 = (ulong)(uVar7 & uVar8) * 0x10;
      iVar25 = (int)lVar10;
      puVar2 = (undefined8 *)(lVar24 + iVar25);
      if (lVar10 != iVar25) {
        puVar2 = (undefined8 *)(lVar24 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar12 = *puVar1;
      uVar31 = puVar2[1];
      uVar30 = *puVar2;
      *puVar5 = uVar6 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar23 & 0x1f);
      uVar23 = uVar18 & uVar20 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar23 * 8) | 1L << (uVar19 & 0x3f);
      lVar11 = (ulong)(uVar20 & uVar8) * 8;
      puVar1 = (undefined8 *)(lVar17 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar1 = (undefined8 *)(lVar17 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = uVar12;
      lVar11 = (ulong)(uVar20 & uVar8) * 0x10;
      puVar1 = (undefined8 *)(lVar24 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar1 = (undefined8 *)(lVar24 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar1[1] = uVar31;
      *puVar1 = uVar30;
      puVar1 = (undefined8 *)(*plVar26 + (long)iVar14);
      if (lVar9 != iVar14) {
        puVar1 = (undefined8 *)(*plVar26 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar2 = (undefined8 *)(plVar26[1] + (long)iVar25);
      if (lVar10 != iVar25) {
        puVar2 = (undefined8 *)(plVar26[1] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 0;
      *puVar2 = 0;
      lVar11 = plVar26[3];
      uVar23 = uVar18 & uVar7 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar23 * 8) &
           (1L << ((ulong)uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      uVar19 = (ulong)uVar7;
    }
    if (uVar21 == uVar20) break;
LAB_fffffff009956dc4:
    uVar20 = (uint)uVar19;
    if (uVar20 - uVar15 < 0x20) {
      lVar24 = (ulong)(uVar20 & uVar8) * 8;
      lVar17 = plVar26[1];
      plVar4 = (long *)(*plVar26 + (long)(int)lVar24);
      if (lVar24 != (int)lVar24) {
        plVar4 = (long *)(*plVar26 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar4 = lVar27;
      lVar27 = (ulong)(uVar20 & uVar8) * 0x10;
      puVar1 = (undefined8 *)(lVar17 + (int)lVar27);
      if (lVar27 != (int)lVar27) {
        puVar1 = (undefined8 *)(lVar17 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = plVar28;
      puVar1[1] = 1;
      lVar27 = (uVar16 & 0xffffffff) * 4;
      puVar5 = (uint *)(plVar26[2] + (long)(int)lVar27);
      if (lVar27 != (int)lVar27) {
        puVar5 = (uint *)(plVar26[2] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar5 = *puVar5 | 1 << (ulong)(uVar20 - uVar15 & 0x1f);
      uVar18 = uVar18 & uVar20 >> 6;
      *(ulong *)(lVar11 + (ulong)uVar18 * 8) =
           *(ulong *)(lVar11 + (ulong)uVar18 * 8) | 1L << (uVar19 & 0x3f);
      *(int *)(plVar26 + 6) = (int)plVar26[6] + 1;
      (**(code **)(*plVar28 + 0x20))(plVar28);
      local_870[local_884] = (long)plVar28;
      local_884 = local_884 + 1;
      goto LAB_fffffff0099570c4;
    }
  }
LAB_fffffff009956ff4:
  uVar16 = FUN_fffffff0099582a4(plVar26);
  if ((uVar16 & 1) == 0) {
    if (local_884 == 0) goto LAB_fffffff00995722c;
    uVar29 = 0;
    lVar11 = plVar26[2];
    goto LAB_fffffff009957100;
  }
  goto LAB_fffffff009956f58;
LAB_fffffff009957434:
  FUN_fffffff009983a10();
LAB_fffffff009957438:
  FUN_fffffff0099839e0();
LAB_fffffff00995743c:
  FUN_fffffff009983a64();
  goto LAB_fffffff009957440;
LAB_fffffff009957100:
  do {
    uVar16 = (ulong)(*(long *)(local_870[uVar29] + 0x70) * -0x61c8864680b583eb) >>
             ((ulong)(uint)-*(int *)((long)plVar26 + 0x2c) & 0x3f);
    lVar27 = (uVar16 & 0xffffffff) * 4;
    iVar14 = (int)lVar27;
    puVar5 = (uint *)(lVar11 + iVar14);
    if (lVar27 - iVar14 != 0) {
      puVar5 = (uint *)(lVar11 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar20 = *puVar5;
    do {
      if (uVar20 == 0) {
        FUN_fffffff0099839b0();
        goto LAB_fffffff009957434;
      }
      uVar18 = (uVar20 & 0xaaaaaaaa) >> 1 | (uVar20 & 0x55555555) << 1;
      uVar18 = (uVar18 & 0xcccccccc) >> 2 | (uVar18 & 0x33333333) << 2;
      uVar18 = (uVar18 & 0xf0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f) << 4;
      uVar18 = (uVar18 & 0xff00ff00) >> 8 | (uVar18 & 0xff00ff) << 8;
      uVar18 = (uint)LZCOUNT(uVar18 >> 0x10 | uVar18 << 0x10);
      uVar21 = 1 << (ulong)(uVar18 & 0x1f);
      uVar20 = uVar20 & (uVar21 ^ 0xffffffff);
      uVar18 = uVar18 + (int)uVar16;
      uVar19 = (ulong)(uVar18 & (int)plVar26[4] - 1U);
      lVar17 = uVar19 * 8;
      plVar28 = (long *)(*plVar26 + (long)(int)lVar17);
      if (lVar17 != (int)lVar17) {
        plVar28 = (long *)(*plVar26 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
    } while (*plVar28 != *(long *)(local_870[uVar29] + 0x70));
    lVar17 = uVar19 * 0x10;
    puVar1 = (undefined8 *)(plVar26[1] + (long)(int)lVar17);
    if (lVar17 - (int)lVar17 != 0) {
      puVar1 = (undefined8 *)(plVar26[1] + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar17 = puVar1[1];
    puVar1[1] = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(*(long *)*puVar1 + 0x28))();
      *puVar1 = 0;
      lVar11 = plVar26[2];
      lVar17 = plVar26[3];
      puVar5 = (uint *)(lVar11 + iVar14);
      if (lVar27 - iVar14 != 0) {
        puVar5 = (uint *)(lVar11 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar5 = *puVar5 & ~uVar21;
      uVar20 = *(uint *)(plVar26 + 5) & uVar18 >> 6;
      *(ulong *)(lVar17 + (ulong)uVar20 * 8) =
           *(ulong *)(lVar17 + (ulong)uVar20 * 8) &
           (1L << ((ulong)uVar18 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(plVar26 + 6) = (int)plVar26[6] + -1;
    }
    uVar29 = uVar29 + 1;
  } while (uVar29 != local_884);
LAB_fffffff00995722c:
  uVar29 = 0xe00002bd;
LAB_fffffff0099573ec:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x60));
LAB_fffffff0099573f4:
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_70) {
    return uVar29;
  }
LAB_fffffff009957440:
  uVar29 = thunk_EXT_FUN_8011000003a48590();
  return uVar29;
}

