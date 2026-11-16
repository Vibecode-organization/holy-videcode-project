// FUN_fffffff00820e760 @ fffffff00820e760 size=844

undefined8 FUN_fffffff00820e760(long *param_1,long param_2)

{
  ulong *puVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  int iVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  int *piVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  uint uVar19;
  long lVar20;
  long lVar21;
  
  uVar9 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar9 == 0) {
    return uVar9;
  }
  param_1[2] = param_2;
  *(undefined4 *)(param_1 + 3) = 0xffffffff;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined4 *)(param_1 + 7) = 0;
  lVar18 = *(long *)(param_2 + 0x4b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar18 + 0xd78));
  if (*(long *)(lVar18 + 0xd50) == 0) {
LAB_fffffff00820e834:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0xd78));
    *(undefined4 *)(param_1 + 3) = 0xffffffff;
    return 0;
  }
  puVar1 = (ulong *)(lVar18 + 0xdd0);
  uVar13 = *(ulong *)(lVar18 + 0xdd0);
  if (uVar13 == 0) {
    iVar8 = FUN_fffffff0081b42a0(lVar18 + 0xd40);
    if (iVar8 == 0) goto LAB_fffffff00820e834;
    uVar13 = *puVar1;
  }
  uVar14 = (uVar13 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar13 & 0x5555555555555555) << 1;
  uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 | (uVar14 & 0x3333333333333333) << 2;
  uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 | (uVar14 & 0xff00ff00ff00ff) << 8;
  uVar14 = (uVar14 & 0xffff0000ffff0000) >> 0x10 | (uVar14 & 0xffff0000ffff) << 0x10;
  uVar16 = (uint)LZCOUNT(uVar14 >> 0x20 | uVar14 << 0x20);
  if (uVar13 == 0) {
    uVar16 = 0xffffffff;
  }
  uVar13 = (ulong)uVar16;
  lVar17 = uVar13 * 0x20;
  puVar4 = (ulong *)(*(long *)(lVar18 + 0xdd8) + (long)(int)lVar17);
  if (lVar17 != (int)lVar17) {
    puVar4 = (ulong *)(*(long *)(lVar18 + 0xdd8) + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar14 = *puVar4;
  if (uVar14 == 0) {
    uVar14 = puVar4[1];
    if (uVar14 == 0) {
      uVar14 = puVar4[2];
      if (uVar14 == 0) {
        uVar14 = puVar4[3];
        if (uVar14 == 0) {
          uVar19 = 0xffffffff;
          goto LAB_fffffff00820e870;
        }
        uVar19 = 0xc0;
      }
      else {
        uVar19 = 0x80;
      }
    }
    else {
      uVar19 = 0x40;
    }
  }
  else {
    uVar19 = 0;
  }
  uVar14 = (uVar14 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar14 & 0x5555555555555555) << 1;
  uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 | (uVar14 & 0x3333333333333333) << 2;
  uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 | (uVar14 & 0xff00ff00ff00ff) << 8;
  uVar14 = (uVar14 & 0xffff0000ffff0000) >> 0x10 | (uVar14 & 0xffff0000ffff) << 0x10;
  uVar19 = uVar19 | (uint)LZCOUNT(uVar14 >> 0x20 | uVar14 << 0x20);
LAB_fffffff00820e870:
  uVar2 = uVar19 + uVar16 * 0x100;
  uVar5 = *(uint *)(lVar18 + 0xd88);
  uVar6 = 0;
  if (uVar5 != 0) {
    uVar6 = uVar2 / uVar5;
  }
  lVar20 = *(long *)(lVar18 + 0xd80) * (ulong)(uVar2 - uVar6 * uVar5);
  lVar17 = (ulong)uVar6 * 8;
  iVar8 = (int)lVar17;
  plVar10 = (long *)(*(long *)(lVar18 + 0xdb8) + (long)iVar8);
  if (lVar17 != iVar8) {
    plVar10 = (long *)(*(long *)(lVar18 + 0xdb8) + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar10 = *(long **)(*plVar10 + 8);
  param_1[6] = (long)plVar10;
  (**(code **)(*plVar10 + 0x20))();
  puVar3 = (undefined8 *)(*(long *)(lVar18 + 0xdb8) + (long)iVar8);
  if (lVar17 != iVar8) {
    puVar3 = (undefined8 *)
             (*(long *)(lVar18 + 0xdb8) + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  piVar15 = (int *)*puVar3;
  *piVar15 = *piVar15 + 1;
  lVar11 = (**(code **)(**(long **)(*(long *)(piVar15 + 2) + 0x50) + 0x98))();
  param_1[5] = lVar11 + lVar20;
  plVar10 = (long *)(*(long *)(lVar18 + 0xdb8) + (long)iVar8);
  if (lVar17 != iVar8) {
    plVar10 = (long *)(*(long *)(lVar18 + 0xdb8) + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar12 = (**(code **)(**(long **)(*(long *)(*plVar10 + 8) + 0x60) + 0x78))();
  uVar14 = uVar12 + lVar20;
  if (((uVar12 ^ uVar14) & 0xffc0000000000000) != 0) {
    uVar14 = uVar14 & 0xffffffffffff | 0xc8a2000000000000;
  }
  param_1[4] = uVar14;
  lVar17 = uVar13 * 0x20;
  plVar10 = (long *)(*(long *)(lVar18 + 0xdd8) + (long)(int)lVar17);
  if (lVar17 - (int)lVar17 != 0) {
    plVar10 = (long *)(*(long *)(lVar18 + 0xdd8) + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar14 = (ulong)(uVar19 >> 3) & 0x1ffffff8;
  puVar4 = (ulong *)((long)plVar10 + (long)(int)uVar14);
  if (uVar14 != (long)(int)uVar14) {
    puVar4 = (ulong *)((long)plVar10 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar4 = *puVar4 & (1L << ((ulong)uVar19 & 0x3f) ^ 0xffffffffffffffffU);
  lVar17 = -(ulong)(plVar10[2] == 0);
  lVar20 = -(ulong)(plVar10[3] == 0);
  lVar11 = -(ulong)(*plVar10 == 0);
  lVar21 = -(ulong)(plVar10[1] == 0);
  auVar7[1] = ~(byte)((ulong)lVar11 >> 8);
  auVar7[0] = ~(byte)lVar11;
  auVar7[2] = ~(byte)((ulong)lVar11 >> 0x10);
  auVar7[3] = ~(byte)((ulong)lVar11 >> 0x18);
  auVar7[4] = ~(byte)lVar21;
  auVar7[5] = ~(byte)((ulong)lVar21 >> 8);
  auVar7[6] = ~(byte)((ulong)lVar21 >> 0x10);
  auVar7[7] = ~(byte)((ulong)lVar21 >> 0x18);
  auVar7[8] = ~(byte)lVar17;
  auVar7[9] = ~(byte)((ulong)lVar17 >> 8);
  auVar7[10] = ~(byte)((ulong)lVar17 >> 0x10);
  auVar7[0xb] = ~(byte)((ulong)lVar17 >> 0x18);
  auVar7[0xc] = ~(byte)lVar20;
  auVar7[0xd] = ~(byte)((ulong)lVar20 >> 8);
  auVar7[0xe] = ~(byte)((ulong)lVar20 >> 0x10);
  auVar7[0xf] = ~(byte)((ulong)lVar20 >> 0x18);
  uVar19 = NEON_umaxv(auVar7,4);
  if ((uVar19 & 1) == 0) {
    uVar14 = (ulong)(uVar16 >> 3) & 0x1ffffff8;
    *(ulong *)((long)puVar1 + uVar14) =
         *(ulong *)((long)puVar1 + uVar14) & (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0xd78));
  *(uint *)(param_1 + 3) = uVar2;
  iVar8 = FUN_fffffff0081e0b20(param_1[6]);
  if (iVar8 == 0) {
    (**(code **)(*param_1 + 0x88))(param_1);
    uVar9 = 1;
  }
  else {
    if ((long *)param_1[6] != (long *)0x0) {
      (**(code **)(*(long *)param_1[6] + 0x28))();
    }
    param_1[6] = 0;
    FUN_fffffff0081b6fc4(*(undefined8 *)(param_1[2] + 0x4b0),(int)param_1[3]);
    uVar9 = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    *(undefined4 *)(param_1 + 3) = 0xffffffff;
  }
  return uVar9;
}

