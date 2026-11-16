// FUN_fffffff0099569fc @ fffffff0099569fc size=608

ulong FUN_fffffff0099569fc(long param_1,long param_2,ulong param_3)

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
  long lVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  long lVar24;
  int iVar25;
  ulong uVar26;
  long *plVar27;
  long *plVar28;
  ulong uVar29;
  long lVar30;
  undefined8 uVar31;
  undefined8 uVar32;
  undefined1 auVar33 [16];
  uint uStack_904;
  long alStack_8f0 [256];
  long lStack_f0;
  
  if (*(char *)(param_1 + 0x10) != '\x03') {
    return 0xe00002c7;
  }
  uVar29 = param_3;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x60));
  plVar27 = *(long **)(param_1 + 0x30);
  lVar11 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fed428);
  if (lVar11 != 0) {
    FUN_fffffff009942d70();
    if ((int)param_3 == 0) {
      uVar26 = 0;
    }
    else {
      uVar29 = 0;
      uVar26 = 0;
      lVar15 = plVar27[2];
      do {
        lVar17 = *(long *)(param_2 + uVar29 * 8);
        uVar19 = (ulong)(lVar17 * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar27 + 0x2c) & 0x3f);
        lVar30 = (uVar19 & 0xffffffff) * 4;
        iVar14 = (int)lVar30;
        puVar5 = (uint *)(lVar15 + iVar14);
        if (lVar30 - iVar14 != 0) {
          puVar5 = (uint *)(lVar15 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar20 = *puVar5;
        do {
          if (uVar20 == 0) {
            uVar26 = 0xe00002c2;
            goto LAB_fffffff009956bec;
          }
          uVar18 = (uVar20 & 0xaaaaaaaa) >> 1 | (uVar20 & 0x55555555) << 1;
          uVar18 = (uVar18 & 0xcccccccc) >> 2 | (uVar18 & 0x33333333) << 2;
          uVar18 = (uVar18 & 0xf0f0f0f0) >> 4 | (uVar18 & 0xf0f0f0f) << 4;
          uVar18 = (uVar18 & 0xff00ff00) >> 8 | (uVar18 & 0xff00ff) << 8;
          uVar18 = (uint)LZCOUNT(uVar18 >> 0x10 | uVar18 << 0x10);
          uVar21 = 1 << (ulong)(uVar18 & 0x1f);
          uVar20 = uVar20 & (uVar21 ^ 0xffffffff);
          uVar18 = uVar18 + (int)uVar19;
          uVar22 = (ulong)(uVar18 & (int)plVar27[4] - 1U);
          lVar24 = uVar22 * 8;
          plVar28 = (long *)(*plVar27 + (long)(int)lVar24);
          if (lVar24 != (int)lVar24) {
            plVar28 = (long *)(*plVar27 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar28 != lVar17);
        lVar17 = uVar22 * 0x10;
        puVar1 = (undefined8 *)(plVar27[1] + (long)(int)lVar17);
        if (lVar17 - (int)lVar17 != 0) {
          puVar1 = (undefined8 *)(plVar27[1] + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar17 = puVar1[1];
        puVar1[1] = lVar17 + -1;
        if (lVar17 + -1 == 0) {
          FUN_fffffff00996ae10(lVar11,*puVar1,*(uint *)(param_1 + 0x10) >> 0x17 & 1);
          (**(code **)(*(long *)*puVar1 + 0x28))();
          *puVar1 = 0;
          lVar15 = plVar27[2];
          lVar17 = plVar27[3];
          puVar5 = (uint *)(lVar15 + iVar14);
          if (lVar30 - iVar14 != 0) {
            puVar5 = (uint *)(lVar15 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar5 = *puVar5 & ~uVar21;
          uVar20 = *(uint *)(plVar27 + 5) & uVar18 >> 6;
          *(ulong *)(lVar17 + (ulong)uVar20 * 8) =
               *(ulong *)(lVar17 + (ulong)uVar20 * 8) &
               (1L << ((ulong)uVar18 & 0x3f) ^ 0xffffffffffffffffU);
          *(int *)(plVar27 + 6) = (int)plVar27[6] + -1;
        }
LAB_fffffff009956bec:
        uVar29 = uVar29 + 1;
      } while (uVar29 != (param_3 & 0xffffffff));
    }
    FUN_fffffff009942d7c(lVar11);
    uVar12 = FUN_fffffff00996bb74(lVar11);
    **(undefined8 **)(param_1 + 0x18) = uVar12;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x60));
    return uVar26;
  }
  auVar33 = FUN_fffffff00998398c();
  lVar11 = auVar33._0_8_;
  lStack_f0 = *(long *)PTR_DAT_fffffff007ff2800;
  if (0x100 < (uint)uVar29) goto LAB_fffffff00995743c;
  if (*(char *)(lVar11 + 0x10) == '\x03') {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x60));
    plVar27 = *(long **)(lVar11 + 0x30);
    if ((uint)uVar29 == 0) {
      uStack_904 = 0;
    }
    else {
      uVar26 = 0;
      uStack_904 = 0;
      do {
        plVar28 = *(long **)(auVar33._8_8_ + uVar26 * 8);
        if ((plVar28 == (long *)0x0) || ((char)plVar28[2] == '\x03')) goto LAB_fffffff009957438;
        lVar17 = plVar28[0xe];
        uVar19 = (ulong)(lVar17 * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar27 + 0x2c) & 0x3f);
        lVar15 = (uVar19 & 0xffffffff) * 4;
        puVar5 = (uint *)(plVar27[2] + (long)(int)lVar15);
        if (lVar15 != (int)lVar15) {
          puVar5 = (uint *)(plVar27[2] + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
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
          uVar22 = (ulong)(uVar18 + (int)uVar19 & (int)plVar27[4] - 1U);
          lVar15 = uVar22 * 8;
          plVar4 = (long *)(*plVar27 + (long)(int)lVar15);
          if (lVar15 != (int)lVar15) {
            plVar4 = (long *)(*plVar27 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar4 != lVar17);
        uVar19 = uVar22 << 4 | 8;
        plVar28 = (long *)(plVar27[1] + (long)(int)uVar19);
        if (uVar19 != (long)(int)uVar19) {
          plVar28 = (long *)(plVar27[1] + uVar19 & 0xffffffffffff | 0x2bad000000000000);
        }
        *plVar28 = *plVar28 + 1;
LAB_fffffff0099570c4:
        uVar26 = uVar26 + 1;
      } while (uVar26 != (uVar29 & 0xffffffff));
    }
    lVar15 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(lVar11 + 0x28),DAT_fffffff007fed428);
    if (lVar15 == 0) {
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
    uVar29 = FUN_fffffff009968ef0(lVar15,alStack_8f0,uStack_904);
    if ((int)uVar29 == 0) {
      uVar12 = FUN_fffffff00996bb74(lVar15);
      **(undefined8 **)(lVar11 + 0x18) = uVar12;
    }
    else if (uStack_904 != 0) {
      uVar26 = 0;
      lVar15 = plVar27[2];
      do {
        uVar19 = (ulong)(*(long *)(alStack_8f0[uVar26] + 0x70) * -0x61c8864680b583eb) >>
                 ((ulong)(uint)-*(int *)((long)plVar27 + 0x2c) & 0x3f);
        lVar17 = (uVar19 & 0xffffffff) * 4;
        iVar14 = (int)lVar17;
        puVar5 = (uint *)(lVar15 + iVar14);
        if (lVar17 - iVar14 != 0) {
          puVar5 = (uint *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
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
          uVar22 = (ulong)(uVar18 & (int)plVar27[4] - 1U);
          lVar30 = uVar22 * 8;
          plVar28 = (long *)(*plVar27 + (long)(int)lVar30);
          if (lVar30 != (int)lVar30) {
            plVar28 = (long *)(*plVar27 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while (*plVar28 != *(long *)(alStack_8f0[uVar26] + 0x70));
        lVar30 = uVar22 * 0x10;
        puVar1 = (undefined8 *)(plVar27[1] + (long)(int)lVar30);
        if (lVar30 - (int)lVar30 != 0) {
          puVar1 = (undefined8 *)(plVar27[1] + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar30 = puVar1[1];
        puVar1[1] = lVar30 + -1;
        if (lVar30 + -1 == 0) {
          (**(code **)(*(long *)*puVar1 + 0x28))();
          *puVar1 = 0;
          lVar15 = plVar27[2];
          lVar30 = plVar27[3];
          puVar5 = (uint *)(lVar15 + iVar14);
          if (lVar17 - iVar14 != 0) {
            puVar5 = (uint *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar5 = *puVar5 & ~uVar21;
          uVar20 = *(uint *)(plVar27 + 5) & uVar18 >> 6;
          *(ulong *)(lVar30 + (ulong)uVar20 * 8) =
               *(ulong *)(lVar30 + (ulong)uVar20 * 8) &
               (1L << ((ulong)uVar18 & 0x3f) ^ 0xffffffffffffffffU);
          *(int *)(plVar27 + 6) = (int)plVar27[6] + -1;
        }
        uVar26 = uVar26 + 1;
      } while (uVar26 != uStack_904);
      uVar29 = uVar29 & 0xffffffff;
    }
    goto LAB_fffffff0099573ec;
  }
  uVar29 = 0xe00002c7;
  goto LAB_fffffff0099573f4;
LAB_fffffff009956f58:
  uVar20 = 0;
  uVar8 = (int)plVar27[4] - 1;
  uVar18 = *(uint *)(plVar27 + 5);
  uVar19 = (ulong)(lVar17 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)plVar27 + 0x2c) & 0x3f);
  uVar16 = (uint)uVar19;
  uVar21 = uVar16 >> 6;
  lVar15 = plVar27[3];
  uVar22 = *(ulong *)(lVar15 + (ulong)uVar21 * 8) | -1L << (uVar19 & 0x3f) ^ 0xffffffffffffffffU;
  iVar25 = 0x40 - (uVar16 & 0x3f);
  iVar14 = uVar21 << 6;
  do {
    uVar21 = uVar21 + 1;
    if (uVar22 != 0xffffffffffffffff) {
      uVar22 = (~uVar22 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar22 & 0x5555555555555555) << 1;
      uVar22 = (uVar22 & 0xcccccccccccccccc) >> 2 | (uVar22 & 0x3333333333333333) << 2;
      uVar22 = (uVar22 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar22 = (uVar22 & 0xff00ff00ff00ff00) >> 8 | (uVar22 & 0xff00ff00ff00ff) << 8;
      uVar22 = (uVar22 & 0xffff0000ffff0000) >> 0x10 | (uVar22 & 0xffff0000ffff) << 0x10;
      uVar20 = (int)LZCOUNT(uVar22 >> 0x20 | uVar22 << 0x20) + iVar14;
      uVar22 = (ulong)uVar20;
      if (uVar20 - uVar16 < 0x80) goto LAB_fffffff009956dc4;
      break;
    }
    lVar30 = (ulong)(uVar21 & uVar18) * 8;
    puVar3 = (ulong *)(lVar15 + (int)lVar30);
    if (lVar30 != (int)lVar30) {
      puVar3 = (ulong *)(lVar15 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar20 = iVar25 + uVar20;
    uVar22 = *puVar3;
    iVar14 = iVar14 + 0x40;
    iVar25 = 0x40;
  } while (uVar20 < 0x80);
  goto LAB_fffffff009956ff4;
  while( true ) {
    uVar21 = uVar20 - 0x1f;
    if (0x1e < uVar20) {
      lVar30 = plVar27[2];
      uVar23 = 0xffffffe1;
      while( true ) {
        uVar21 = uVar20 + uVar23;
        lVar24 = (ulong)(uVar21 & uVar8) * 4;
        puVar5 = (uint *)(lVar30 + (int)lVar24);
        if (lVar24 != (int)lVar24) {
          puVar5 = (uint *)(lVar30 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
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
      puVar5 = (uint *)(lVar30 + (int)lVar24);
      if (lVar24 - (int)lVar24 != 0) {
        puVar5 = (uint *)(lVar30 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar9 = (ulong)(uVar7 & uVar8) * 8;
      lVar30 = *plVar27;
      lVar24 = plVar27[1];
      iVar14 = (int)lVar9;
      puVar1 = (undefined8 *)(lVar30 + iVar14);
      if (lVar9 != iVar14) {
        puVar1 = (undefined8 *)(lVar30 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar10 = (ulong)(uVar7 & uVar8) * 0x10;
      iVar25 = (int)lVar10;
      puVar2 = (undefined8 *)(lVar24 + iVar25);
      if (lVar10 != iVar25) {
        puVar2 = (undefined8 *)(lVar24 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar12 = *puVar1;
      uVar32 = puVar2[1];
      uVar31 = *puVar2;
      *puVar5 = uVar6 & (1 << (ulong)(uVar13 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar23 & 0x1f);
      uVar23 = uVar18 & uVar20 >> 6;
      *(ulong *)(lVar15 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar15 + (ulong)uVar23 * 8) | 1L << (uVar22 & 0x3f);
      lVar15 = (ulong)(uVar20 & uVar8) * 8;
      puVar1 = (undefined8 *)(lVar30 + (int)lVar15);
      if (lVar15 != (int)lVar15) {
        puVar1 = (undefined8 *)(lVar30 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = uVar12;
      lVar15 = (ulong)(uVar20 & uVar8) * 0x10;
      puVar1 = (undefined8 *)(lVar24 + (int)lVar15);
      if (lVar15 != (int)lVar15) {
        puVar1 = (undefined8 *)(lVar24 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar1[1] = uVar32;
      *puVar1 = uVar31;
      puVar1 = (undefined8 *)(*plVar27 + (long)iVar14);
      if (lVar9 != iVar14) {
        puVar1 = (undefined8 *)(*plVar27 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      puVar2 = (undefined8 *)(plVar27[1] + (long)iVar25);
      if (lVar10 != iVar25) {
        puVar2 = (undefined8 *)(plVar27[1] + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 0;
      *puVar2 = 0;
      lVar15 = plVar27[3];
      uVar23 = uVar18 & uVar7 >> 6;
      *(ulong *)(lVar15 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar15 + (ulong)uVar23 * 8) &
           (1L << ((ulong)uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      uVar22 = (ulong)uVar7;
    }
    if (uVar21 == uVar20) break;
LAB_fffffff009956dc4:
    uVar20 = (uint)uVar22;
    if (uVar20 - uVar16 < 0x20) {
      lVar24 = (ulong)(uVar20 & uVar8) * 8;
      lVar30 = plVar27[1];
      plVar4 = (long *)(*plVar27 + (long)(int)lVar24);
      if (lVar24 != (int)lVar24) {
        plVar4 = (long *)(*plVar27 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar4 = lVar17;
      lVar17 = (ulong)(uVar20 & uVar8) * 0x10;
      puVar1 = (undefined8 *)(lVar30 + (int)lVar17);
      if (lVar17 != (int)lVar17) {
        puVar1 = (undefined8 *)(lVar30 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = plVar28;
      puVar1[1] = 1;
      lVar17 = (uVar19 & 0xffffffff) * 4;
      puVar5 = (uint *)(plVar27[2] + (long)(int)lVar17);
      if (lVar17 != (int)lVar17) {
        puVar5 = (uint *)(plVar27[2] + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar5 = *puVar5 | 1 << (ulong)(uVar20 - uVar16 & 0x1f);
      uVar18 = uVar18 & uVar20 >> 6;
      *(ulong *)(lVar15 + (ulong)uVar18 * 8) =
           *(ulong *)(lVar15 + (ulong)uVar18 * 8) | 1L << (uVar22 & 0x3f);
      *(int *)(plVar27 + 6) = (int)plVar27[6] + 1;
      (**(code **)(*plVar28 + 0x20))(plVar28);
      alStack_8f0[uStack_904] = (long)plVar28;
      uStack_904 = uStack_904 + 1;
      goto LAB_fffffff0099570c4;
    }
  }
LAB_fffffff009956ff4:
  uVar19 = FUN_fffffff0099582a4(plVar27);
  if ((uVar19 & 1) == 0) {
    if (uStack_904 == 0) goto LAB_fffffff00995722c;
    uVar29 = 0;
    lVar15 = plVar27[2];
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
    uVar26 = (ulong)(*(long *)(alStack_8f0[uVar29] + 0x70) * -0x61c8864680b583eb) >>
             ((ulong)(uint)-*(int *)((long)plVar27 + 0x2c) & 0x3f);
    lVar17 = (uVar26 & 0xffffffff) * 4;
    iVar14 = (int)lVar17;
    puVar5 = (uint *)(lVar15 + iVar14);
    if (lVar17 - iVar14 != 0) {
      puVar5 = (uint *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
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
      uVar18 = uVar18 + (int)uVar26;
      uVar19 = (ulong)(uVar18 & (int)plVar27[4] - 1U);
      lVar30 = uVar19 * 8;
      plVar28 = (long *)(*plVar27 + (long)(int)lVar30);
      if (lVar30 != (int)lVar30) {
        plVar28 = (long *)(*plVar27 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
      }
    } while (*plVar28 != *(long *)(alStack_8f0[uVar29] + 0x70));
    lVar30 = uVar19 * 0x10;
    puVar1 = (undefined8 *)(plVar27[1] + (long)(int)lVar30);
    if (lVar30 - (int)lVar30 != 0) {
      puVar1 = (undefined8 *)(plVar27[1] + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar30 = puVar1[1];
    puVar1[1] = lVar30 + -1;
    if (lVar30 + -1 == 0) {
      (**(code **)(*(long *)*puVar1 + 0x28))();
      *puVar1 = 0;
      lVar15 = plVar27[2];
      lVar30 = plVar27[3];
      puVar5 = (uint *)(lVar15 + iVar14);
      if (lVar17 - iVar14 != 0) {
        puVar5 = (uint *)(lVar15 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar5 = *puVar5 & ~uVar21;
      uVar20 = *(uint *)(plVar27 + 5) & uVar18 >> 6;
      *(ulong *)(lVar30 + (ulong)uVar20 * 8) =
           *(ulong *)(lVar30 + (ulong)uVar20 * 8) &
           (1L << ((ulong)uVar18 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(plVar27 + 6) = (int)plVar27[6] + -1;
    }
    uVar29 = uVar29 + 1;
  } while (uVar29 != uStack_904);
LAB_fffffff00995722c:
  uVar29 = 0xe00002bd;
LAB_fffffff0099573ec:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x60));
LAB_fffffff0099573f4:
  if (*(long *)PTR_DAT_fffffff007ff2800 == lStack_f0) {
    return uVar29;
  }
LAB_fffffff009957440:
  uVar29 = thunk_EXT_FUN_8011000003a48590();
  return uVar29;
}

