// FUN_fffffff0081e2424 @ fffffff0081e2424 size=1104

/* WARNING: Removing unreachable block (ram,0xfffffff0081e2548) */

undefined8 FUN_fffffff0081e2424(long param_1,long param_2,long *param_3)

{
  uint uVar1;
  ulong *puVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auVar7 [16];
  undefined4 uVar8;
  int iVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long *plVar14;
  long lVar15;
  int *piVar16;
  uint uVar17;
  long lVar18;
  ulong uVar19;
  uint uVar20;
  long lVar21;
  long lVar22;
  
  uVar10 = thunk_EXT_FUN_8011000002946758();
  if ((int)uVar10 == 0) {
    return uVar10;
  }
  *(long *)(param_1 + 0x18) = param_2;
  *(long **)(param_1 + 0x28) = param_3;
  if (param_3 == (long *)0x0) {
    lVar18 = *(long *)(param_2 + 0x4b0);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar18 + 0x1110));
    if (*(long *)(lVar18 + 0x10e8) == 0) {
LAB_fffffff0081e2620:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0x1110));
      *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
      return 0;
    }
    puVar2 = (ulong *)(lVar18 + 0x1168);
    uVar11 = *(ulong *)(lVar18 + 0x1168);
    if (uVar11 == 0) {
      iVar9 = FUN_fffffff0081ad3d8(lVar18 + 0x10d8);
      if (iVar9 == 0) goto LAB_fffffff0081e2620;
      uVar11 = *puVar2;
    }
    uVar12 = (uVar11 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar11 & 0x5555555555555555) << 1;
    uVar12 = (uVar12 & 0xcccccccccccccccc) >> 2 | (uVar12 & 0x3333333333333333) << 2;
    uVar12 = (uVar12 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
    uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
    uVar17 = (uint)LZCOUNT(uVar12 >> 0x20 | uVar12 << 0x20);
    if (uVar11 == 0) {
      uVar17 = 0xffffffff;
    }
    uVar11 = (ulong)uVar17;
    lVar13 = uVar11 * 0x20;
    puVar4 = (ulong *)(*(long *)(lVar18 + 0x1170) + (long)(int)lVar13);
    if (lVar13 != (int)lVar13) {
      puVar4 = (ulong *)(*(long *)(lVar18 + 0x1170) + lVar13 & 0xffffffffffffU | 0x2bad000000000000)
      ;
    }
    uVar12 = *puVar4;
    if (uVar12 == 0) {
      uVar12 = puVar4[1];
      if (uVar12 != 0) {
        uVar20 = 0x40;
        goto LAB_fffffff0081e2654;
      }
      uVar12 = puVar4[2];
      if (uVar12 != 0) {
        uVar20 = 0x80;
        goto LAB_fffffff0081e2654;
      }
      uVar12 = puVar4[3];
      if (uVar12 != 0) {
        uVar20 = 0xc0;
        goto LAB_fffffff0081e2654;
      }
      uVar20 = 0xffffffff;
    }
    else {
      uVar20 = 0;
LAB_fffffff0081e2654:
      uVar12 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1;
      uVar12 = (uVar12 & 0xcccccccccccccccc) >> 2 | (uVar12 & 0x3333333333333333) << 2;
      uVar12 = (uVar12 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
      uVar12 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
      uVar20 = uVar20 | (uint)LZCOUNT(uVar12 >> 0x20 | uVar12 << 0x20);
    }
    uVar1 = uVar20 + uVar17 * 0x100;
    uVar5 = *(uint *)(lVar18 + 0x1120);
    uVar6 = 0;
    if (uVar5 != 0) {
      uVar6 = uVar1 / uVar5;
    }
    lVar21 = *(long *)(lVar18 + 0x1118) * (ulong)(uVar1 - uVar6 * uVar5);
    lVar13 = (ulong)uVar6 * 8;
    iVar9 = (int)lVar13;
    plVar14 = (long *)(*(long *)(lVar18 + 0x1150) + (long)iVar9);
    if (lVar13 != iVar9) {
      plVar14 = (long *)(*(long *)(lVar18 + 0x1150) + lVar13 & 0xffffffffffffU | 0x2bad000000000000)
      ;
    }
    plVar14 = *(long **)(*plVar14 + 8);
    *(long **)(param_1 + 0x60) = plVar14;
    (**(code **)(*plVar14 + 0x20))();
    puVar3 = (undefined8 *)(*(long *)(lVar18 + 0x1150) + (long)iVar9);
    if (lVar13 != iVar9) {
      puVar3 = (undefined8 *)
               (*(long *)(lVar18 + 0x1150) + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    piVar16 = (int *)*puVar3;
    *piVar16 = *piVar16 + 1;
    lVar15 = (**(code **)(**(long **)(*(long *)(piVar16 + 2) + 0x50) + 0x98))();
    *(long *)(param_1 + 0x58) = lVar15 + lVar21;
    plVar14 = (long *)(*(long *)(lVar18 + 0x1150) + (long)iVar9);
    if (lVar13 != iVar9) {
      plVar14 = (long *)(*(long *)(lVar18 + 0x1150) + lVar13 & 0xffffffffffffU | 0x2bad000000000000)
      ;
    }
    uVar19 = (**(code **)(**(long **)(*(long *)(*plVar14 + 8) + 0x60) + 0x78))();
    uVar12 = uVar19 + lVar21;
    if (((uVar19 ^ uVar12) & 0xffc0000000000000) != 0) {
      uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
    }
    lVar13 = uVar11 * 0x20;
    plVar14 = (long *)(*(long *)(lVar18 + 0x1170) + (long)(int)lVar13);
    if (lVar13 - (int)lVar13 != 0) {
      plVar14 = (long *)(*(long *)(lVar18 + 0x1170) + lVar13 & 0xffffffffffffU | 0x2bad000000000000)
      ;
    }
    uVar19 = (ulong)(uVar20 >> 3) & 0x1ffffff8;
    puVar4 = (ulong *)((long)plVar14 + (long)(int)uVar19);
    if (uVar19 != (long)(int)uVar19) {
      puVar4 = (ulong *)((long)plVar14 + uVar19 & 0xffffffffffff | 0x2bad000000000000);
    }
    *puVar4 = *puVar4 & (1L << ((ulong)uVar20 & 0x3f) ^ 0xffffffffffffffffU);
    lVar13 = -(ulong)(plVar14[2] == 0);
    lVar21 = -(ulong)(plVar14[3] == 0);
    lVar15 = -(ulong)(*plVar14 == 0);
    lVar22 = -(ulong)(plVar14[1] == 0);
    auVar7[1] = ~(byte)((ulong)lVar15 >> 8);
    auVar7[0] = ~(byte)lVar15;
    auVar7[2] = ~(byte)((ulong)lVar15 >> 0x10);
    auVar7[3] = ~(byte)((ulong)lVar15 >> 0x18);
    auVar7[4] = ~(byte)lVar22;
    auVar7[5] = ~(byte)((ulong)lVar22 >> 8);
    auVar7[6] = ~(byte)((ulong)lVar22 >> 0x10);
    auVar7[7] = ~(byte)((ulong)lVar22 >> 0x18);
    auVar7[8] = ~(byte)lVar13;
    auVar7[9] = ~(byte)((ulong)lVar13 >> 8);
    auVar7[10] = ~(byte)((ulong)lVar13 >> 0x10);
    auVar7[0xb] = ~(byte)((ulong)lVar13 >> 0x18);
    auVar7[0xc] = ~(byte)lVar21;
    auVar7[0xd] = ~(byte)((ulong)lVar21 >> 8);
    auVar7[0xe] = ~(byte)((ulong)lVar21 >> 0x10);
    auVar7[0xf] = ~(byte)((ulong)lVar21 >> 0x18);
    uVar20 = NEON_umaxv(auVar7,4);
    if ((uVar20 & 1) == 0) {
      uVar19 = (ulong)(uVar17 >> 3) & 0x1ffffff8;
      *(ulong *)((long)puVar2 + uVar19) =
           *(ulong *)((long)puVar2 + uVar19) & (1L << (uVar11 & 0x3f) ^ 0xffffffffffffffffU);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0x1110));
    *(uint *)(param_1 + 0x50) = uVar1;
    *(ulong *)(param_1 + 0x68) = uVar12;
    iVar9 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0x60));
    if (iVar9 != 0) {
      return 0;
    }
    **(undefined8 **)(param_1 + 0x68) = 0;
  }
  else {
    lVar18 = *(long *)(param_2 + 0x11d98);
    (**(code **)(*param_3 + 0x20))(param_3);
    *(undefined8 *)(param_1 + 0x60) = 0;
    uVar8 = thunk_EXT_FUN_8011000002c1353c(param_3);
    *(undefined4 *)(param_1 + 0x50) = uVar8;
    uVar11 = thunk_EXT_FUN_8011000002c13530(param_3);
    uVar11 = uVar11 & 0xffffffff;
    uVar19 = (ulong)*(uint *)(lVar18 + 0x48);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar18 + 0x40));
    uVar12 = FUN_fffffff0081e36b0(lVar18,uVar11);
    if ((uVar12 & 1) == 0) {
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0x40));
      goto LAB_fffffff0081e2830;
    }
    uVar12 = 0;
    if (uVar19 != 0) {
      uVar12 = uVar11 / uVar19;
    }
    lVar13 = uVar12 * 0x18 + 0x10;
    puVar3 = (undefined8 *)(*(long *)(lVar18 + 0x28) + (long)(int)lVar13);
    if (lVar13 != (int)lVar13) {
      puVar3 = (undefined8 *)
               (*(long *)(lVar18 + 0x28) + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar13 = (**(code **)(*(long *)*puVar3 + 0x98))();
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0x40));
    plVar14 = *(long **)(*(long *)(param_1 + 0x18) + 0x4b0);
    lVar18 = *plVar14;
    uVar10 = (**(code **)(lVar18 + 0x208))
                       (lVar18 + 0x208,plVar14,lVar13 + (uVar11 - uVar12 * uVar19) * 8,0);
    *(undefined8 *)(param_1 + 0x58) = uVar10;
    uVar10 = thunk_EXT_FUN_8011000002c13548(param_3);
    *(undefined8 *)(param_1 + 0x68) = uVar10;
  }
  lVar18 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x48) = lVar18;
  if (lVar18 != 0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined8 **)(param_1 + 0x40) = (undefined8 *)(param_1 + 0x38);
    return 1;
  }
LAB_fffffff0081e2830:
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  return 0;
}

