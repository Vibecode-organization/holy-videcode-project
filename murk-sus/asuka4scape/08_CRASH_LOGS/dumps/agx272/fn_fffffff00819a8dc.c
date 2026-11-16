// FUN_fffffff00819a8dc @ fffffff00819a8dc size=2268

/* WARNING: Removing unreachable block (ram,0xfffffff00819ad54) */

undefined8 FUN_fffffff00819a8dc(long param_1,undefined8 param_2,long param_3,int param_4)

{
  ulong *puVar1;
  uint uVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auVar6 [16];
  int iVar7;
  undefined8 uVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  undefined8 *puVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  int *piVar18;
  undefined2 *puVar19;
  uint uVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  uint uVar24;
  
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(long *)(param_1 + 0x18) = param_3;
  *(undefined8 *)(param_1 + 200) = 0;
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  uVar8 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar8 == 0) {
    return uVar8;
  }
  if ((param_4 != 0) &&
     (lVar15 = *(long *)(param_1 + 0x10), (*(byte *)(lVar15 + 0x1ac44) >> 3 & 1) != 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar15 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d89,param_3,0,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 0x1ac48));
  }
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  plVar9 = (long *)(**(code **)(DAT_fffffff00ae22f20 + 0x68))();
  if (plVar9 == (long *)0x0) {
    return 0;
  }
  lVar15 = *(long *)(param_1 + 0x10);
  iVar7 = *(int *)(param_3 + 0x848);
  uVar20 = *(uint *)(lVar15 + 0x18b70);
  plVar9[2] = *(long *)PTR_DAT_fffffff007ca61d0;
  iVar7 = FUN_fffffff0081e07cc(plVar9,lVar15,(long)iVar7 << 4,uVar20 | 99);
  if (iVar7 == 0) {
LAB_fffffff00819b118:
    (**(code **)(*plVar9 + 0x28))(plVar9);
    return 0;
  }
  plVar10 = (long *)plVar9[10];
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))
                                ((long *)plVar9[9],plVar9[3],0x20900000084);
    if (plVar10 == (long *)0x0) goto LAB_fffffff00819b118;
    (**(code **)(*plVar10 + 0x20))();
    (**(code **)(*plVar10 + 0x28))(plVar10);
    plVar9[10] = (long)plVar10;
  }
  lVar15 = (**(code **)(*plVar10 + 0x98))();
  if (lVar15 == 0) goto LAB_fffffff00819b118;
  lVar15 = thunk_EXT_FUN_8011000002971b4c(*(undefined8 *)(param_1 + 0x10));
  plVar10 = (long *)plVar9[0xb];
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)(**(code **)(*(long *)plVar9[9] + 0x90))((long *)plVar9[9],lVar15,0x500000087)
    ;
    if (plVar10 == (long *)0x0) goto LAB_fffffff00819b118;
    (**(code **)(*plVar10 + 0x20))();
    (**(code **)(*plVar10 + 0x28))(plVar10);
    plVar9[0xb] = (long)plVar10;
  }
  if (plVar10[4] != lVar15) {
    uVar8 = thunk_EXT_FUN_8011000003a49114
                      ("AGXk: %s:%d:%s: !!! Attempting to map into multiple GPU Contexts!\n");
    return uVar8;
  }
  lVar15 = (**(code **)(*plVar10 + 0x98))();
  if (lVar15 == 0) goto LAB_fffffff00819b118;
  *(long **)(param_1 + 0xb8) = plVar9;
  lVar11 = (**(code **)(*(long *)plVar9[0xb] + 0x98))();
  lVar15 = (**(code **)(**(long **)(*(long *)(param_1 + 0xb8) + 0x50) + 0x98))();
  if (0 < *(int *)(param_3 + 0x848)) {
    lVar16 = 0;
    lVar23 = *(long *)(param_1 + 0x18);
    lVar21 = *(long *)(lVar23 + 0x8f0);
    lVar22 = *(long *)(lVar23 + 0x8f8);
    lVar23 = *(long *)(lVar23 + 0x900);
    do {
      *(long *)(lVar21 + lVar16 * 8) = lVar11;
      *(long *)(lVar22 + lVar16 * 8) = lVar15;
      *(undefined4 *)(lVar23 + lVar16 * 4) = 0;
      lVar16 = lVar16 + 1;
      lVar15 = lVar15 + 0x10;
      lVar11 = lVar11 + 0x10;
    } while (lVar16 < *(int *)(param_3 + 0x848));
  }
  iVar7 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0xb8));
  if (iVar7 != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to map fFirmwareCachedResource\n")
    ;
    return 0;
  }
  *(undefined4 *)(param_1 + 0xc0) = 1;
  *(undefined4 *)(param_3 + 0x8e8) = 0;
  plVar9 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca0d88,0x17c0);
  puVar12 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar9,&DAT_fffffff00ae21ee0);
  *puVar12 = &DAT_fffffff007c93a78;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae21ee0);
  *(long **)(param_1 + 0xa8) = plVar9;
  uVar13 = (**(code **)(*plVar9 + 0x78))
                     (plVar9,*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_3 + 0x488),
                      param_3);
  if ((uVar13 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init Command Buffer State\n");
    return 0;
  }
  plVar9 = (long *)thunk_EXT_FUN_80110000038943cc(&DAT_fffffff007ca2888,0x40);
  puVar12 = (undefined8 *)thunk_EXT_FUN_80110000038944ec(plVar9,&DAT_fffffff00ae25840);
  *puVar12 = &DAT_fffffff007c9fc48;
  thunk_EXT_FUN_80110000038922a0(&DAT_fffffff00ae25840);
  *(long **)(param_1 + 0xb0) = plVar9;
  uVar13 = (**(code **)(*plVar9 + 0x78))(plVar9,*(undefined8 *)(param_1 + 0x10));
  if ((uVar13 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to init TimeStamp Queue\n");
    return 0;
  }
  (**(code **)(**(long **)(param_1 + 0xb0) + 0x80))
            (*(long **)(param_1 + 0xb0),*(byte *)(param_3 + 0x439) & 1);
  plVar9 = (long *)(**(code **)(**(long **)(param_1 + 0x10) + 0x870))
                             (**(long **)(param_1 + 0x10) + 0x870);
  if (plVar9 == (long *)0x0) {
LAB_fffffff00819ae34:
    *(undefined8 *)(param_1 + 0xa0) = 0;
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x10,"Failed to create Fast Render Target\n");
    return 0;
  }
  uVar13 = (**(code **)(*plVar9 + 0x68))();
  if ((uVar13 & 1) == 0) {
    (**(code **)(*plVar9 + 0x28))(plVar9);
    goto LAB_fffffff00819ae34;
  }
  *(long **)(param_1 + 0xa0) = plVar9;
  *(undefined8 *)(param_1 + 0xf0) = 0;
  *(undefined8 *)(param_1 + 0xe8) = 0;
  lVar15 = *(long *)(*(long *)(param_1 + 0x10) + 0x4b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar15 + 4000));
  if (*(long *)(lVar15 + 0xf78) == 0) {
LAB_fffffff00819ae8c:
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 4000));
    *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
    return 0;
  }
  puVar1 = (ulong *)(lVar15 + 0xff8);
  uVar13 = *(ulong *)(lVar15 + 0xff8);
  if (uVar13 == 0) {
    iVar7 = FUN_fffffff0081b0028(lVar15 + 0xf68);
    if (iVar7 == 0) goto LAB_fffffff00819ae8c;
    uVar13 = *puVar1;
  }
  uVar17 = (uVar13 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar13 & 0x5555555555555555) << 1;
  uVar17 = (uVar17 & 0xcccccccccccccccc) >> 2 | (uVar17 & 0x3333333333333333) << 2;
  uVar17 = (uVar17 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar17 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar17 = (uVar17 & 0xff00ff00ff00ff00) >> 8 | (uVar17 & 0xff00ff00ff00ff) << 8;
  uVar17 = (uVar17 & 0xffff0000ffff0000) >> 0x10 | (uVar17 & 0xffff0000ffff) << 0x10;
  uVar20 = (uint)LZCOUNT(uVar17 >> 0x20 | uVar17 << 0x20);
  if (uVar13 == 0) {
    uVar20 = 0xffffffff;
  }
  uVar13 = (ulong)uVar20;
  lVar11 = uVar13 * 0x20;
  puVar3 = (ulong *)(*(long *)(lVar15 + 0x1000) + (long)(int)lVar11);
  if (lVar11 != (int)lVar11) {
    puVar3 = (ulong *)(*(long *)(lVar15 + 0x1000) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar17 = *puVar3;
  if (uVar17 == 0) {
    uVar17 = puVar3[1];
    if (uVar17 == 0) {
      uVar17 = puVar3[2];
      if (uVar17 == 0) {
        uVar17 = puVar3[3];
        if (uVar17 == 0) {
          uVar24 = 0xffffffff;
          goto LAB_fffffff00819aecc;
        }
        uVar24 = 0xc0;
      }
      else {
        uVar24 = 0x80;
      }
    }
    else {
      uVar24 = 0x40;
    }
  }
  else {
    uVar24 = 0;
  }
  uVar17 = (uVar17 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar17 & 0x5555555555555555) << 1;
  uVar17 = (uVar17 & 0xcccccccccccccccc) >> 2 | (uVar17 & 0x3333333333333333) << 2;
  uVar17 = (uVar17 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar17 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar17 = (uVar17 & 0xff00ff00ff00ff00) >> 8 | (uVar17 & 0xff00ff00ff00ff) << 8;
  uVar17 = (uVar17 & 0xffff0000ffff0000) >> 0x10 | (uVar17 & 0xffff0000ffff) << 0x10;
  uVar24 = uVar24 | (uint)LZCOUNT(uVar17 >> 0x20 | uVar17 << 0x20);
LAB_fffffff00819aecc:
  uVar2 = uVar24 + uVar20 * 0x100;
  uVar4 = *(uint *)(lVar15 + 0xfb0);
  uVar5 = 0;
  if (uVar4 != 0) {
    uVar5 = uVar2 / uVar4;
  }
  lVar16 = *(long *)(lVar15 + 0xfa8) * (ulong)(uVar2 - uVar5 * uVar4);
  lVar11 = (ulong)uVar5 * 8;
  iVar7 = (int)lVar11;
  plVar9 = (long *)(*(long *)(lVar15 + 0xfe0) + (long)iVar7);
  if (lVar11 != iVar7) {
    plVar9 = (long *)(*(long *)(lVar15 + 0xfe0) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar9 = *(long **)(*plVar9 + 8);
  *(long **)(param_1 + 0xd0) = plVar9;
  (**(code **)(*plVar9 + 0x20))();
  puVar12 = (undefined8 *)(*(long *)(lVar15 + 0xfe0) + (long)iVar7);
  if (lVar11 != iVar7) {
    puVar12 = (undefined8 *)
              (*(long *)(lVar15 + 0xfe0) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  piVar18 = (int *)*puVar12;
  *piVar18 = *piVar18 + 1;
  lVar21 = (**(code **)(**(long **)(*(long *)(piVar18 + 2) + 0x50) + 0x98))();
  *(long *)(param_1 + 0xe0) = lVar21 + lVar16;
  plVar9 = (long *)(*(long *)(lVar15 + 0xfe0) + (long)iVar7);
  if (lVar11 != iVar7) {
    plVar9 = (long *)(*(long *)(lVar15 + 0xfe0) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar14 = (**(code **)(**(long **)(*(long *)(*plVar9 + 8) + 0x60) + 0x78))();
  uVar17 = uVar14 + lVar16;
  if (((uVar14 ^ uVar17) & 0xffc0000000000000) != 0) {
    uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
  }
  *(ulong *)(param_1 + 200) = uVar17;
  lVar11 = uVar13 * 0x20;
  plVar9 = (long *)(*(long *)(lVar15 + 0x1000) + (long)(int)lVar11);
  if (lVar11 - (int)lVar11 != 0) {
    plVar9 = (long *)(*(long *)(lVar15 + 0x1000) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar17 = (ulong)(uVar24 >> 3) & 0x1ffffff8;
  puVar3 = (ulong *)((long)plVar9 + (long)(int)uVar17);
  if (uVar17 != (long)(int)uVar17) {
    puVar3 = (ulong *)((long)plVar9 + uVar17 & 0xffffffffffff | 0x2bad000000000000);
  }
  *puVar3 = *puVar3 & (1L << ((ulong)uVar24 & 0x3f) ^ 0xffffffffffffffffU);
  lVar11 = -(ulong)(plVar9[2] == 0);
  lVar16 = -(ulong)(plVar9[3] == 0);
  lVar21 = -(ulong)(*plVar9 == 0);
  lVar22 = -(ulong)(plVar9[1] == 0);
  auVar6[1] = ~(byte)((ulong)lVar21 >> 8);
  auVar6[0] = ~(byte)lVar21;
  auVar6[2] = ~(byte)((ulong)lVar21 >> 0x10);
  auVar6[3] = ~(byte)((ulong)lVar21 >> 0x18);
  auVar6[4] = ~(byte)lVar22;
  auVar6[5] = ~(byte)((ulong)lVar22 >> 8);
  auVar6[6] = ~(byte)((ulong)lVar22 >> 0x10);
  auVar6[7] = ~(byte)((ulong)lVar22 >> 0x18);
  auVar6[8] = ~(byte)lVar11;
  auVar6[9] = ~(byte)((ulong)lVar11 >> 8);
  auVar6[10] = ~(byte)((ulong)lVar11 >> 0x10);
  auVar6[0xb] = ~(byte)((ulong)lVar11 >> 0x18);
  auVar6[0xc] = ~(byte)lVar16;
  auVar6[0xd] = ~(byte)((ulong)lVar16 >> 8);
  auVar6[0xe] = ~(byte)((ulong)lVar16 >> 0x10);
  auVar6[0xf] = ~(byte)((ulong)lVar16 >> 0x18);
  uVar24 = NEON_umaxv(auVar6,4);
  if ((uVar24 & 1) == 0) {
    uVar17 = (ulong)(uVar20 >> 3) & 0x1ffffff8;
    *(ulong *)((long)puVar1 + uVar17) =
         *(ulong *)((long)puVar1 + uVar17) & (1L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 4000));
  *(uint *)(param_1 + 0xd8) = uVar2;
  iVar7 = FUN_fffffff0081e0b20(*(undefined8 *)(param_1 + 0xd0));
  if (iVar7 != 0) {
    return 0;
  }
  puVar12 = *(undefined8 **)(param_1 + 200);
  puVar12[3] = 0;
  puVar12[2] = 0;
  puVar12[5] = 0;
  puVar12[4] = 0;
  puVar12[1] = 0;
  *puVar12 = 0;
  puVar19 = *(undefined2 **)(param_1 + 200);
  *puVar19 = 0xffff;
  *(undefined1 *)((long)puVar19 + 5) = 1;
  *(undefined1 *)((long)puVar19 + 0x27) = 0xff;
  *(undefined4 *)(puVar19 + 0x11) = 0;
  *(undefined1 *)(puVar19 + 0x13) =
       *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x18) + 0x488) + 0x120);
  if (param_4 == 0) {
    return 1;
  }
  lVar15 = *(long *)(param_1 + 0x10);
  if ((*(byte *)(lVar15 + 0x1ac44) >> 3 & 1) == 0) {
    return 1;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar15 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x85930d8a,param_3,0,0,0,0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar15 + 0x1ac48));
  return 1;
}

