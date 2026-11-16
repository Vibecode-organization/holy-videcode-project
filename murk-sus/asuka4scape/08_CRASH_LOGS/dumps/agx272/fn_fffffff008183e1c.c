// FUN_fffffff008183e1c @ fffffff008183e1c size=3944

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff008183e1c
          (long *param_1,long param_2,long param_3,undefined4 param_4,uint param_5,long param_6,
          uint param_7)

{
  ulong *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined8 uVar12;
  undefined8 uVar13;
  int iVar14;
  undefined8 uVar15;
  long lVar16;
  long *plVar17;
  long *plVar18;
  undefined8 *puVar19;
  long lVar20;
  ulong uVar21;
  int *piVar22;
  code *pcVar23;
  uint uVar24;
  ulong uVar25;
  long lVar26;
  long lVar27;
  ulong uVar28;
  ulong uVar29;
  undefined *puVar30;
  ulong uVar31;
  uint uVar32;
  long lVar33;
  long lVar34;
  long lVar35;
  long lVar36;
  
  uVar15 = (**(code **)(PTR_DAT_fffffff007ca60e8 + 0x88))
                     (param_1,*(undefined8 *)(param_2 + 0x530),0x80);
  if ((int)uVar15 == 0) {
    return uVar15;
  }
  lVar20 = *(long *)(*(long *)(param_2 + 0x488) + 0x1f0);
  lVar16 = 0;
  if (lVar20 != 0) {
    lVar16 = *(long *)(lVar20 + 0x13a0);
  }
  param_1[10] = lVar16;
  uVar5 = *(undefined4 *)(param_2 + 0x490);
  param_1[0x18] = 0;
  *(undefined4 *)(param_1 + 7) = param_4;
  *(undefined1 *)((long)param_1 + 0x3c) = 0;
  param_1[0x22] = *(long *)(*(long *)(param_2 + 0x610) + 0xe0);
  *(undefined4 *)(param_1 + 0x2f) = *(undefined4 *)(param_2 + 0x44c);
  param_1[0x30] = param_2;
  param_1[8] = -1;
  *(undefined4 *)(param_1 + 9) = 0xffffffff;
  *(undefined4 *)((long)param_1 + 0x4c) = uVar5;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x2b] = 0;
  if (2 < param_7) {
    return 0;
  }
  *(uint *)(param_1 + 0x1c) = param_7;
  param_1[0x2d] = param_3;
  lVar16 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x2e] = lVar16;
  if (lVar16 == 0) {
    return 0;
  }
  lVar16 = (ulong)param_5 << 3;
  if (0x7fffffff < param_5) {
    lVar16 = -0x8000000000000000;
  }
  lVar20 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2e88,lVar16);
  param_1[0x1d] = lVar20;
  if (lVar20 == 0) goto LAB_fffffff008184984;
  *(uint *)(param_1 + 0xb) = param_5;
  if ((*(byte *)(param_1[2] + 0x5cc) >> 6 & 1) == 0) {
LAB_fffffff0081842e0:
    param_1[0x16] = param_6;
    uVar24 = param_5;
    if (0x7f < param_5) {
      uVar24 = 0x80;
    }
    *(uint *)((long)param_1 + 0x5c) = uVar24 * 0x10;
    uVar24 = 1 << (ulong)(-(int)LZCOUNT(uVar24 * 0x10 + -1) & 0x1f);
    if (param_5 == 0) {
      uVar24 = 1;
    }
    *(uint *)(param_1 + 0x20) = uVar24;
    lVar20 = thunk_EXT_FUN_80110000038fe580((ulong)uVar24 << 3);
    param_1[0x1f] = lVar20;
    if (lVar20 != 0) {
      lVar20 = *(long *)(param_1[2] + 0x4b0);
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0xcc0));
      if (*(long *)(lVar20 + 0xc98) == 0) {
LAB_fffffff0081843a8:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xcc0));
        *(undefined4 *)(param_1 + 8) = 0xffffffff;
      }
      else {
        puVar1 = (ulong *)(lVar20 + 0xd18);
        uVar25 = *(ulong *)(lVar20 + 0xd18);
        if (uVar25 == 0) {
          iVar14 = FUN_fffffff0081b58c8(lVar20 + 0xc88);
          if (iVar14 == 0) goto LAB_fffffff0081843a8;
          uVar25 = *puVar1;
        }
        uVar21 = (uVar25 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar25 & 0x5555555555555555) << 1;
        uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
        uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
        uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
        uVar24 = (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
        if (uVar25 == 0) {
          uVar24 = 0xffffffff;
        }
        uVar25 = (ulong)uVar24;
        lVar33 = uVar25 * 0x20;
        puVar4 = (ulong *)(*(long *)(lVar20 + 0xd20) + (long)(int)lVar33);
        if (lVar33 != (int)lVar33) {
          puVar4 = (ulong *)(*(long *)(lVar20 + 0xd20) + lVar33 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        uVar21 = *puVar4;
        if (uVar21 == 0) {
          uVar21 = puVar4[1];
          if (uVar21 != 0) {
            uVar32 = 0x40;
            goto LAB_fffffff0081843d8;
          }
          uVar21 = puVar4[2];
          if (uVar21 != 0) {
            uVar32 = 0x80;
            goto LAB_fffffff0081843d8;
          }
          uVar21 = puVar4[3];
          if (uVar21 != 0) {
            uVar32 = 0xc0;
            goto LAB_fffffff0081843d8;
          }
          uVar32 = 0xffffffff;
        }
        else {
          uVar32 = 0;
LAB_fffffff0081843d8:
          uVar21 = (uVar21 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar21 & 0x5555555555555555) << 1;
          uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
          uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
          uVar32 = uVar32 | (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
        }
        uVar2 = uVar32 + uVar24 * 0x100;
        uVar6 = *(uint *)(lVar20 + 0xcd0);
        uVar7 = 0;
        if (uVar6 != 0) {
          uVar7 = uVar2 / uVar6;
        }
        lVar26 = *(long *)(lVar20 + 0xcc8) * (ulong)(uVar2 - uVar7 * uVar6);
        lVar33 = (ulong)uVar7 * 8;
        iVar14 = (int)lVar33;
        plVar17 = (long *)(*(long *)(lVar20 + 0xd00) + (long)iVar14);
        if (lVar33 != iVar14) {
          plVar17 = (long *)(*(long *)(lVar20 + 0xd00) + lVar33 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        plVar17 = *(long **)(*plVar17 + 8);
        param_1[0x19] = (long)plVar17;
        (**(code **)(*plVar17 + 0x20))();
        puVar19 = (undefined8 *)(*(long *)(lVar20 + 0xd00) + (long)iVar14);
        if (lVar33 != iVar14) {
          puVar19 = (undefined8 *)
                    (*(long *)(lVar20 + 0xd00) + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
        }
        piVar22 = (int *)*puVar19;
        *piVar22 = *piVar22 + 1;
        lVar27 = (**(code **)(**(long **)(*(long *)(piVar22 + 2) + 0x50) + 0x98))();
        param_1[0x13] = lVar27 + lVar26;
        plVar17 = (long *)(*(long *)(lVar20 + 0xd00) + (long)iVar14);
        if (lVar33 != iVar14) {
          plVar17 = (long *)(*(long *)(lVar20 + 0xd00) + lVar33 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        uVar28 = (**(code **)(**(long **)(*(long *)(*plVar17 + 8) + 0x60) + 0x78))();
        uVar21 = uVar28 + lVar26;
        if (((uVar28 ^ uVar21) & 0xffc0000000000000) != 0) {
          uVar21 = uVar21 & 0xffffffffffff | 0xc8a2000000000000;
        }
        param_1[0xc] = uVar21;
        lVar33 = uVar25 * 0x20;
        plVar17 = (long *)(*(long *)(lVar20 + 0xd20) + (long)(int)lVar33);
        if (lVar33 - (int)lVar33 != 0) {
          plVar17 = (long *)(*(long *)(lVar20 + 0xd20) + lVar33 & 0xffffffffffffU |
                            0x2bad000000000000);
        }
        uVar21 = (ulong)(uVar32 >> 3) & 0x1ffffff8;
        puVar4 = (ulong *)((long)plVar17 + (long)(int)uVar21);
        if (uVar21 != (long)(int)uVar21) {
          puVar4 = (ulong *)((long)plVar17 + uVar21 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar4 = *puVar4 & (1L << ((ulong)uVar32 & 0x3f) ^ 0xffffffffffffffffU);
        lVar33 = -(ulong)(plVar17[2] == 0);
        lVar26 = -(ulong)(plVar17[3] == 0);
        lVar27 = -(ulong)(*plVar17 == 0);
        lVar35 = -(ulong)(plVar17[1] == 0);
        auVar9[1] = ~(byte)((ulong)lVar27 >> 8);
        auVar9[0] = ~(byte)lVar27;
        auVar9[2] = ~(byte)((ulong)lVar27 >> 0x10);
        auVar9[3] = ~(byte)((ulong)lVar27 >> 0x18);
        auVar9[4] = ~(byte)lVar35;
        auVar9[5] = ~(byte)((ulong)lVar35 >> 8);
        auVar9[6] = ~(byte)((ulong)lVar35 >> 0x10);
        auVar9[7] = ~(byte)((ulong)lVar35 >> 0x18);
        auVar9[8] = ~(byte)lVar33;
        auVar9[9] = ~(byte)((ulong)lVar33 >> 8);
        auVar9[10] = ~(byte)((ulong)lVar33 >> 0x10);
        auVar9[0xb] = ~(byte)((ulong)lVar33 >> 0x18);
        auVar9[0xc] = ~(byte)lVar26;
        auVar9[0xd] = ~(byte)((ulong)lVar26 >> 8);
        auVar9[0xe] = ~(byte)((ulong)lVar26 >> 0x10);
        auVar9[0xf] = ~(byte)((ulong)lVar26 >> 0x18);
        uVar32 = NEON_umaxv(auVar9,4);
        if ((uVar32 & 1) == 0) {
          uVar21 = (ulong)(uVar24 >> 3) & 0x1ffffff8;
          *(ulong *)((long)puVar1 + uVar21) =
               *(ulong *)((long)puVar1 + uVar21) & (1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU);
        }
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xcc0));
        *(uint *)(param_1 + 8) = uVar2;
        param_1[0x11] = param_1[0xc] + 0x4200;
        param_1[0x12] = param_1[0x13] + 0x90;
        lVar20 = *(long *)(param_1[2] + 0x4b0);
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0xe30));
        if (*(long *)(lVar20 + 0xe08) == 0) {
LAB_fffffff008184620:
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xe30));
        }
        else {
          puVar1 = (ulong *)(lVar20 + 0xe88);
          uVar25 = *(ulong *)(lVar20 + 0xe88);
          if (uVar25 == 0) {
            iVar14 = FUN_fffffff0081b2c78(lVar20 + 0xdf8);
            if (iVar14 == 0) goto LAB_fffffff008184620;
            uVar25 = *puVar1;
          }
          uVar21 = (uVar25 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar25 & 0x5555555555555555) << 1;
          uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
          uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
          uVar24 = (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
          if (uVar25 == 0) {
            uVar24 = 0xffffffff;
          }
          uVar25 = (ulong)uVar24;
          lVar33 = uVar25 * 0x20;
          puVar4 = (ulong *)(*(long *)(lVar20 + 0xe90) + (long)(int)lVar33);
          if (lVar33 != (int)lVar33) {
            puVar4 = (ulong *)(*(long *)(lVar20 + 0xe90) + lVar33 & 0xffffffffffffU |
                              0x2bad000000000000);
          }
          uVar21 = *puVar4;
          if (uVar21 == 0) {
            uVar21 = puVar4[1];
            if (uVar21 != 0) {
              uVar32 = 0x40;
              goto LAB_fffffff008184648;
            }
            uVar21 = puVar4[2];
            if (uVar21 != 0) {
              uVar32 = 0x80;
              goto LAB_fffffff008184648;
            }
            uVar21 = puVar4[3];
            if (uVar21 != 0) {
              uVar32 = 0xc0;
              goto LAB_fffffff008184648;
            }
            uVar32 = 0xffffffff;
          }
          else {
            uVar32 = 0;
LAB_fffffff008184648:
            uVar21 = (uVar21 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar21 & 0x5555555555555555) << 1;
            uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
            uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
            uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
            uVar32 = uVar32 | (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
          }
          uVar2 = uVar32 + uVar24 * 0x100;
          uVar6 = *(uint *)(lVar20 + 0xe40);
          uVar7 = 0;
          if (uVar6 != 0) {
            uVar7 = uVar2 / uVar6;
          }
          lVar26 = *(long *)(lVar20 + 0xe38) * (ulong)(uVar2 - uVar7 * uVar6);
          lVar33 = (ulong)uVar7 * 8;
          iVar14 = (int)lVar33;
          plVar17 = (long *)(*(long *)(lVar20 + 0xe70) + (long)iVar14);
          if (lVar33 != iVar14) {
            plVar17 = (long *)(*(long *)(lVar20 + 0xe70) + lVar33 & 0xffffffffffffU |
                              0x2bad000000000000);
          }
          plVar17 = *(long **)(*plVar17 + 8);
          param_1[0x1a] = (long)plVar17;
          (**(code **)(*plVar17 + 0x20))();
          puVar19 = (undefined8 *)(*(long *)(lVar20 + 0xe70) + (long)iVar14);
          if (lVar33 != iVar14) {
            puVar19 = (undefined8 *)
                      (*(long *)(lVar20 + 0xe70) + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
          }
          piVar22 = (int *)*puVar19;
          *piVar22 = *piVar22 + 1;
          lVar27 = (**(code **)(**(long **)(*(long *)(piVar22 + 2) + 0x50) + 0x98))();
          plVar17 = (long *)(*(long *)(lVar20 + 0xe70) + (long)iVar14);
          if (lVar33 != iVar14) {
            plVar17 = (long *)(*(long *)(lVar20 + 0xe70) + lVar33 & 0xffffffffffffU |
                              0x2bad000000000000);
          }
          uVar28 = (**(code **)(**(long **)(*(long *)(*plVar17 + 8) + 0x60) + 0x78))();
          uVar21 = uVar28 + lVar26;
          if (((uVar28 ^ uVar21) & 0xffc0000000000000) != 0) {
            uVar21 = uVar21 & 0xffffffffffff | 0xc8a2000000000000;
          }
          lVar33 = uVar25 * 0x20;
          plVar17 = (long *)(*(long *)(lVar20 + 0xe90) + (long)(int)lVar33);
          if (lVar33 - (int)lVar33 != 0) {
            plVar17 = (long *)(*(long *)(lVar20 + 0xe90) + lVar33 & 0xffffffffffffU |
                              0x2bad000000000000);
          }
          uVar28 = (ulong)(uVar32 >> 3) & 0x1ffffff8;
          puVar4 = (ulong *)((long)plVar17 + (long)(int)uVar28);
          if (uVar28 != (long)(int)uVar28) {
            puVar4 = (ulong *)((long)plVar17 + uVar28 & 0xffffffffffff | 0x2bad000000000000);
          }
          *puVar4 = *puVar4 & (1L << ((ulong)uVar32 & 0x3f) ^ 0xffffffffffffffffU);
          lVar33 = -(ulong)(plVar17[2] == 0);
          lVar35 = -(ulong)(plVar17[3] == 0);
          lVar34 = -(ulong)(*plVar17 == 0);
          lVar36 = -(ulong)(plVar17[1] == 0);
          auVar10[1] = ~(byte)((ulong)lVar34 >> 8);
          auVar10[0] = ~(byte)lVar34;
          auVar10[2] = ~(byte)((ulong)lVar34 >> 0x10);
          auVar10[3] = ~(byte)((ulong)lVar34 >> 0x18);
          auVar10[4] = ~(byte)lVar36;
          auVar10[5] = ~(byte)((ulong)lVar36 >> 8);
          auVar10[6] = ~(byte)((ulong)lVar36 >> 0x10);
          auVar10[7] = ~(byte)((ulong)lVar36 >> 0x18);
          auVar10[8] = ~(byte)lVar33;
          auVar10[9] = ~(byte)((ulong)lVar33 >> 8);
          auVar10[10] = ~(byte)((ulong)lVar33 >> 0x10);
          auVar10[0xb] = ~(byte)((ulong)lVar33 >> 0x18);
          auVar10[0xc] = ~(byte)lVar35;
          auVar10[0xd] = ~(byte)((ulong)lVar35 >> 8);
          auVar10[0xe] = ~(byte)((ulong)lVar35 >> 0x10);
          auVar10[0xf] = ~(byte)((ulong)lVar35 >> 0x18);
          uVar32 = NEON_umaxv(auVar10,4);
          if ((uVar32 & 1) == 0) {
            uVar28 = (ulong)(uVar24 >> 3) & 0x1ffffff8;
            *(ulong *)((long)puVar1 + uVar28) =
                 *(ulong *)((long)puVar1 + uVar28) & (1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU);
          }
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xe30));
          *(uint *)((long)param_1 + 0x44) = uVar2;
          param_1[0xd] = uVar21;
          param_1[0x14] = lVar27 + lVar26;
          lVar20 = *(long *)(param_1[2] + 0x4b0);
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0xee8));
          if (*(long *)(lVar20 + 0xec0) != 0) {
            puVar1 = (ulong *)(lVar20 + 0xf40);
            uVar25 = *(ulong *)(lVar20 + 0xf40);
            if (uVar25 == 0) {
              iVar14 = FUN_fffffff0081b1650(lVar20 + 0xeb0);
              if (iVar14 == 0) goto LAB_fffffff008184878;
              uVar25 = *puVar1;
            }
            uVar21 = (uVar25 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar25 & 0x5555555555555555) << 1;
            uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
            uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
            uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
            uVar24 = (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
            if (uVar25 == 0) {
              uVar24 = 0xffffffff;
            }
            uVar25 = (ulong)uVar24;
            lVar16 = uVar25 * 0x20;
            puVar4 = (ulong *)(*(long *)(lVar20 + 0xf48) + (long)(int)lVar16);
            if (lVar16 != (int)lVar16) {
              puVar4 = (ulong *)(*(long *)(lVar20 + 0xf48) + lVar16 & 0xffffffffffffU |
                                0x2bad000000000000);
            }
            uVar21 = *puVar4;
            if (uVar21 == 0) {
              uVar21 = puVar4[1];
              if (uVar21 != 0) {
                uVar32 = 0x40;
                goto LAB_fffffff0081849d0;
              }
              uVar21 = puVar4[2];
              if (uVar21 != 0) {
                uVar32 = 0x80;
                goto LAB_fffffff0081849d0;
              }
              uVar21 = puVar4[3];
              if (uVar21 != 0) {
                uVar32 = 0xc0;
                goto LAB_fffffff0081849d0;
              }
              uVar32 = 0xffffffff;
            }
            else {
              uVar32 = 0;
LAB_fffffff0081849d0:
              uVar21 = (uVar21 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar21 & 0x5555555555555555) << 1;
              uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
              uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
              uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
              uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
              uVar32 = uVar32 | (uint)LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
            }
            uVar2 = uVar32 + uVar24 * 0x100;
            uVar6 = *(uint *)(lVar20 + 0xef8);
            uVar7 = 0;
            if (uVar6 != 0) {
              uVar7 = uVar2 / uVar6;
            }
            lVar33 = *(long *)(lVar20 + 0xef0) * (ulong)(uVar2 - uVar7 * uVar6);
            lVar16 = (ulong)uVar7 * 8;
            iVar14 = (int)lVar16;
            plVar17 = (long *)(*(long *)(lVar20 + 0xf28) + (long)iVar14);
            if (lVar16 != iVar14) {
              plVar17 = (long *)(*(long *)(lVar20 + 0xf28) + lVar16 & 0xffffffffffffU |
                                0x2bad000000000000);
            }
            plVar17 = *(long **)(*plVar17 + 8);
            param_1[0x1b] = (long)plVar17;
            (**(code **)(*plVar17 + 0x20))();
            puVar19 = (undefined8 *)(*(long *)(lVar20 + 0xf28) + (long)iVar14);
            if (lVar16 != iVar14) {
              puVar19 = (undefined8 *)
                        (*(long *)(lVar20 + 0xf28) + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
            }
            piVar22 = (int *)*puVar19;
            *piVar22 = *piVar22 + 1;
            lVar26 = (**(code **)(**(long **)(*(long *)(piVar22 + 2) + 0x50) + 0x98))();
            plVar17 = (long *)(*(long *)(lVar20 + 0xf28) + (long)iVar14);
            if (lVar16 != iVar14) {
              plVar17 = (long *)(*(long *)(lVar20 + 0xf28) + lVar16 & 0xffffffffffffU |
                                0x2bad000000000000);
            }
            uVar28 = (**(code **)(**(long **)(*(long *)(*plVar17 + 8) + 0x60) + 0x78))();
            uVar21 = uVar28 + lVar33;
            if (((uVar28 ^ uVar21) & 0xffc0000000000000) != 0) {
              uVar21 = uVar21 & 0xffffffffffff | 0xc8a2000000000000;
            }
            lVar16 = uVar25 * 0x20;
            plVar17 = (long *)(*(long *)(lVar20 + 0xf48) + (long)(int)lVar16);
            if (lVar16 - (int)lVar16 != 0) {
              plVar17 = (long *)(*(long *)(lVar20 + 0xf48) + lVar16 & 0xffffffffffffU |
                                0x2bad000000000000);
            }
            uVar28 = (ulong)(uVar32 >> 3) & 0x1ffffff8;
            puVar4 = (ulong *)((long)plVar17 + (long)(int)uVar28);
            if (uVar28 != (long)(int)uVar28) {
              puVar4 = (ulong *)((long)plVar17 + uVar28 & 0xffffffffffff | 0x2bad000000000000);
            }
            *puVar4 = *puVar4 & (1L << ((ulong)uVar32 & 0x3f) ^ 0xffffffffffffffffU);
            lVar16 = -(ulong)(plVar17[2] == 0);
            lVar27 = -(ulong)(plVar17[3] == 0);
            lVar35 = -(ulong)(*plVar17 == 0);
            lVar34 = -(ulong)(plVar17[1] == 0);
            auVar11[1] = ~(byte)((ulong)lVar35 >> 8);
            auVar11[0] = ~(byte)lVar35;
            auVar11[2] = ~(byte)((ulong)lVar35 >> 0x10);
            auVar11[3] = ~(byte)((ulong)lVar35 >> 0x18);
            auVar11[4] = ~(byte)lVar34;
            auVar11[5] = ~(byte)((ulong)lVar34 >> 8);
            auVar11[6] = ~(byte)((ulong)lVar34 >> 0x10);
            auVar11[7] = ~(byte)((ulong)lVar34 >> 0x18);
            auVar11[8] = ~(byte)lVar16;
            auVar11[9] = ~(byte)((ulong)lVar16 >> 8);
            auVar11[10] = ~(byte)((ulong)lVar16 >> 0x10);
            auVar11[0xb] = ~(byte)((ulong)lVar16 >> 0x18);
            auVar11[0xc] = ~(byte)lVar27;
            auVar11[0xd] = ~(byte)((ulong)lVar27 >> 8);
            auVar11[0xe] = ~(byte)((ulong)lVar27 >> 0x10);
            auVar11[0xf] = ~(byte)((ulong)lVar27 >> 0x18);
            uVar32 = NEON_umaxv(auVar11,4);
            if ((uVar32 & 1) == 0) {
              uVar28 = (ulong)(uVar24 >> 3) & 0x1ffffff8;
              *(ulong *)((long)puVar1 + uVar28) =
                   *(ulong *)((long)puVar1 + uVar28) & (1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU)
              ;
            }
            thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xee8));
            *(uint *)(param_1 + 9) = uVar2;
            param_1[0xe] = uVar21;
            param_1[0x15] = lVar26 + lVar33;
            lVar20 = param_1[2];
            uVar15 = *(undefined8 *)(param_2 + 0x488);
            lVar16 = (**(code **)(*param_1 + 0xc0))(param_1);
            if (lVar16 == 0) {
LAB_fffffff008184cc8:
              uVar15 = (**(code **)(*param_1 + 0xf8))(param_1);
              if ((int)uVar15 == 0) {
                return uVar15;
              }
              (**(code **)(*param_1 + 0x118))(param_1);
              return 1;
            }
            plVar17 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
            if (plVar17 == (long *)0x0) {
              return 0;
            }
            uVar24 = *(uint *)(lVar20 + 0x18b70);
            plVar17[2] = *(long *)PTR_DAT_fffffff007ca61d0;
            iVar14 = FUN_fffffff0081e07cc(plVar17,lVar20,lVar16,uVar24 | 99);
            if (iVar14 != 0) {
              lVar16 = thunk_EXT_FUN_80110000029636a8(uVar15);
              plVar18 = (long *)plVar17[0xb];
              if (plVar18 == (long *)0x0) {
                plVar18 = (long *)(**(code **)(*(long *)plVar17[9] + 0x90))
                                            ((long *)plVar17[9],lVar16,0x1100000087);
                if (plVar18 == (long *)0x0) goto LAB_fffffff008184d34;
                (**(code **)(*plVar18 + 0x20))();
                (**(code **)(*plVar18 + 0x28))(plVar18);
                plVar17[0xb] = (long)plVar18;
              }
              if (plVar18[4] != lVar16) {
                uVar15 = thunk_EXT_FUN_8011000003a49114
                                   (
                                   "AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n"
                                   );
                return uVar15;
              }
              lVar16 = (**(code **)(*plVar18 + 0x98))();
              if (lVar16 != 0) {
                param_1[0x2c] = (long)plVar17;
                goto LAB_fffffff008184cc8;
              }
            }
LAB_fffffff008184d34:
            (**(code **)(*plVar17 + 0x28))(plVar17);
            return 0;
          }
LAB_fffffff008184878:
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0xee8));
          *(undefined4 *)(param_1 + 9) = 0xffffffff;
          if ((long *)param_1[0x1a] != (long *)0x0) {
            (**(code **)(*(long *)param_1[0x1a] + 0x28))();
          }
          param_1[0x1a] = 0;
          FUN_fffffff0081b7190
                    (*(undefined8 *)(param_1[2] + 0x4b0),*(undefined4 *)((long)param_1 + 0x44));
          param_1[0xd] = 0;
          param_1[0x14] = 0;
        }
        *(undefined4 *)((long)param_1 + 0x44) = 0xffffffff;
        if ((long *)param_1[0x19] != (long *)0x0) {
          (**(code **)(*(long *)param_1[0x19] + 0x28))();
        }
        param_1[0x19] = 0;
        FUN_fffffff0081b6df8(*(undefined8 *)(param_1[2] + 0x4b0),(int)param_1[8]);
        param_1[0xc] = 0;
        param_1[0x13] = 0;
        *(undefined4 *)(param_1 + 8) = 0xffffffff;
      }
      lVar20 = param_1[0x1f];
      param_1[0x1f] = 0;
      thunk_EXT_FUN_80110000038fe6b0(lVar20,(ulong)*(uint *)(param_1 + 0x20) << 3);
      param_1[0x1f] = 0;
    }
    if ((*(byte *)(param_1[2] + 0x5cc) >> 6 & 1) != 0) {
      FUN_fffffff00817ec08(param_1[2],param_1[0x10]);
      plVar17 = (long *)param_1[0x10];
      if (plVar17 != (long *)0x0) {
        pcVar23 = *(code **)(*plVar17 + 0x28);
        goto LAB_fffffff00818495c;
      }
      goto LAB_fffffff008184964;
    }
  }
  else {
    lVar20 = *(long *)(param_2 + 0x488);
    lVar33 = *(long *)(param_3 + 0x100);
    plVar17 = (long *)(**(code **)(*(long *)param_1[2] + 0x8a8))();
    if (plVar17 != (long *)0x0) {
      plVar17[5] = *(long *)(lVar20 + 0x48);
      plVar18 = (long *)thunk_EXT_FUN_80110000029636a8(lVar20);
      plVar17[6] = (long)plVar18;
      (**(code **)(*plVar18 + 0x20))();
      plVar17[8] = 0x4000;
      *(undefined4 *)(plVar17 + 9) = 0x3f000000;
      *(undefined1 *)((long)plVar17 + 0x4c) = 0;
      plVar17[0xc] = lVar33;
      plVar18 = (long *)(**(code **)(DAT_fffffff00ae22730 + 0x68))();
      if (plVar18 != (long *)0x0) {
        lVar20 = plVar17[0xc];
        iVar14 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
        if (iVar14 != 0) {
          lVar33 = thunk_EXT_FUN_80110000038ff134();
          plVar18[2] = lVar33;
          if (lVar33 != 0) {
            plVar18[5] = 0xb;
            puVar19 = (undefined8 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3f18,0x160);
            plVar18[3] = (long)puVar19;
            uVar13 = _DAT_fffffff007c9f3b8;
            uVar12 = DAT_fffffff007c9f3b0;
            uVar15 = _DAT_fffffff007c9f3a0;
            if (puVar19 != (undefined8 *)0x0) {
              uVar25 = plVar18[5];
              if (0 < (long)uVar25) {
                puVar19[1] = DAT_fffffff007c9f3a8;
                *puVar19 = uVar15;
                puVar19[3] = uVar13;
                puVar19[2] = uVar12;
                uVar25 = plVar18[5];
                if (1 < (long)uVar25) {
                  lVar33 = 1;
                  do {
                    puVar19 = (undefined8 *)(&DAT_fffffff007c9f3a0 + lVar33 * 0x20);
                    if ((((ulong)puVar19 ^ 0xfffffff007c9f3a0) & 0xffc0000000000000) != 0) {
                      puVar19 = (undefined8 *)((ulong)puVar19 & 0xffffffffffff | 0xc8a2000000000000)
                      ;
                    }
                    uVar25 = puVar19[1];
                    uVar21 = puVar19[2];
                    uVar28 = 0;
                    if (uVar21 != 0) {
                      uVar28 = uVar25 / uVar21;
                    }
                    if (uVar25 != uVar28 * uVar21) goto LAB_fffffff008184154;
                    lVar26 = lVar33 * 0x20;
                    puVar30 = &UNK_fffffff007c9f380 + lVar26;
                    if ((((ulong)puVar30 ^ 0xfffffff007c9f3a0) & 0xffc0000000000000) != 0) {
                      puVar30 = (undefined *)((ulong)puVar30 & 0xffffffffffff | 0xc8a2000000000000);
                    }
                    uVar28 = *(ulong *)(puVar30 + 8);
                    if (uVar25 <= uVar28) goto LAB_fffffff008184154;
                    uVar31 = *(ulong *)(puVar30 + 0x10);
                    uVar29 = 0;
                    if (uVar31 != 0) {
                      uVar29 = uVar21 / uVar31;
                    }
                    if ((uVar21 != uVar29 * uVar31) ||
                       (*(uint *)(puVar19 + 3) < *(uint *)(puVar30 + 0x18)))
                    goto LAB_fffffff008184154;
                    uVar21 = 0;
                    if (uVar28 != 0) {
                      uVar21 = uVar25 / uVar28;
                    }
                    if (uVar25 != uVar21 * uVar28) goto LAB_fffffff008184154;
                    puVar3 = (undefined8 *)(plVar18[3] + (long)(int)lVar26);
                    if (lVar26 - (int)lVar26 != 0) {
                      puVar3 = (undefined8 *)
                               (plVar18[3] + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    uVar15 = *puVar19;
                    puVar3[1] = puVar19[1];
                    *puVar3 = uVar15;
                    uVar15 = puVar19[2];
                    puVar3[3] = puVar19[3];
                    puVar3[2] = uVar15;
                    lVar33 = lVar33 + 1;
                    uVar25 = plVar18[5];
                  } while (lVar33 < (long)uVar25);
                }
              }
              auVar8._8_8_ = 0;
              auVar8._0_8_ = uVar25;
              lVar33 = -0x8000000000000000;
              if (SUB168(auVar8 * ZEXT816(0x18),8) == 0 && -1 < (long)(uVar25 * 0x18)) {
                lVar33 = uVar25 * 0x18;
              }
              lVar33 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca3f68,lVar33);
              plVar18[4] = lVar33;
              if (lVar33 != 0) {
                uVar25 = plVar18[5];
                if (0 < (long)uVar25) {
                  if (uVar25 == 1) {
                    uVar28 = 0;
                  }
                  else {
                    uVar21 = 0;
                    uVar28 = uVar25 & 0x7ffffffffffffffe;
                    uVar29 = uVar28;
                    do {
                      lVar26 = uVar21 * 0x18 + 8;
                      puVar19 = (undefined8 *)(lVar33 + (int)lVar26);
                      if (lVar26 != (int)lVar26) {
                        puVar19 = (undefined8 *)
                                  (lVar33 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      lVar26 = (uVar21 | 1) * 0x18 + 8;
                      puVar3 = (undefined8 *)(lVar33 + (int)lVar26);
                      if (lVar26 != (int)lVar26) {
                        puVar3 = (undefined8 *)
                                 (lVar33 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      *puVar19 = 0;
                      puVar19[1] = puVar19;
                      *puVar3 = 0;
                      puVar3[1] = puVar3;
                      uVar21 = uVar21 + 2;
                      uVar29 = uVar29 - 2;
                    } while (uVar29 != 0);
                    if (uVar25 == uVar28) goto LAB_fffffff008184228;
                  }
                  lVar26 = uVar25 - uVar28;
                  do {
                    lVar27 = uVar28 * 0x18 + 8;
                    puVar19 = (undefined8 *)(lVar33 + (int)lVar27);
                    if (lVar27 != (int)lVar27) {
                      puVar19 = (undefined8 *)
                                (lVar33 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    *puVar19 = 0;
                    puVar19[1] = puVar19;
                    uVar28 = uVar28 + 1;
                    lVar26 = lVar26 + -1;
                  } while (lVar26 != 0);
                }
LAB_fffffff008184228:
                plVar18[6] = 0;
                plVar18[7] = 0;
                plVar18[8] = 0;
                *(undefined4 *)(plVar18 + 9) = 1;
                plVar18[10] = 0x400000;
                *(undefined4 *)(plVar18 + 0xb) = 0x3f800000;
                plVar18[0xc] = lVar20;
                plVar17[10] = (long)plVar18;
                plVar17[7] = 0;
                plVar17[0xe] = 0;
                *(undefined4 *)(plVar17 + 4) = 0;
                lVar20 = thunk_EXT_FUN_80110000038ff010();
                plVar17[0x10] = lVar20;
                plVar17[0xb] = 0;
                if (*(long **)(plVar17[6] + 0x1e0) != (long *)0x0) {
                  (**(code **)(**(long **)(plVar17[6] + 0x1e0) + 0x40))();
                }
                param_1[0x10] = (long)plVar17;
                lVar20 = param_1[2];
                thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x358));
                (**(code **)(*plVar17 + 0x20))(plVar17);
                plVar17[2] = 0;
                plVar18 = *(long **)(lVar20 + 0x368);
                plVar17[3] = (long)plVar18;
                *plVar18 = (long)plVar17;
                *(long **)(lVar20 + 0x368) = plVar17 + 2;
                thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x358));
                goto LAB_fffffff0081842e0;
              }
            }
          }
        }
LAB_fffffff008184154:
        (**(code **)(*plVar18 + 0x28))(plVar18);
      }
      pcVar23 = *(code **)(*plVar17 + 0x28);
LAB_fffffff00818495c:
      (*pcVar23)(plVar17);
    }
LAB_fffffff008184964:
    param_1[0x10] = 0;
  }
  lVar20 = param_1[0x1d];
  param_1[0x1d] = 0;
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2ed8,lVar20,lVar16);
  param_1[0x1d] = 0;
LAB_fffffff008184984:
  thunk_EXT_FUN_80110000038ff020(param_1[0x2e]);
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  return 0;
}

