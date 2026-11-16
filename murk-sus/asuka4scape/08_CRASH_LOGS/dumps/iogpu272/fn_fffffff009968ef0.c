// FUN_fffffff009968ef0 @ fffffff009968ef0 size=5416

/* WARNING: Removing unreachable block (ram,0xfffffff009969f10) */
/* WARNING: Removing unreachable block (ram,0xfffffff009969860) */
/* WARNING: Removing unreachable block (ram,0xfffffff00996a7f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009969ab0) */

undefined8 FUN_fffffff009968ef0(long *param_1,long param_2,uint param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  long *plVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  byte bVar9;
  long lVar10;
  long lVar11;
  bool bVar12;
  bool bVar13;
  int iVar14;
  ulong uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  long *plVar18;
  long *plVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  long lVar24;
  ulong uVar25;
  int *piVar26;
  long lVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  ulong uVar31;
  long lVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  undefined8 uVar37;
  ulong uVar38;
  long lVar39;
  long *plVar40;
  ulong uVar41;
  undefined1 auVar42 [12];
  undefined8 local_68;
  
  FUN_fffffff009942d70();
  uVar33 = param_3 + *(uint *)(param_1 + 0x17);
  if (CARRY4(param_3,*(uint *)(param_1 + 0x17))) {
    thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Overflow\n");
  }
  else {
    if (!CARRY4(uVar33,uVar33 >> 2)) {
      if ((*(uint *)(param_1 + 0x15) < uVar33 + (uVar33 >> 2)) &&
         (uVar15 = FUN_fffffff00996a418(param_1 + 0x10), (uVar15 & 1) == 0)) {
        uVar37 = 0xe00002bd;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Failed to rehash\n");
        goto LAB_fffffff009968fa4;
      }
      uVar33 = *(uint *)((long)param_1 + 0x24);
      if ((uVar33 >> 1 & 1) != 0) {
        *(int *)((long)param_1 + 0x24) = *(int *)((long)param_1 + 0x24) + 4;
        lVar24 = 0xf;
        if (param_1[5] != 0) {
          lVar24 = param_1[5];
        }
        if (param_3 != 0) goto LAB_fffffff009969038;
        goto LAB_fffffff00996a3d8;
      }
      lVar24 = 0xf;
      if (param_1[5] != 0) {
        lVar24 = param_1[5];
      }
      if (param_3 != 0) {
LAB_fffffff009969038:
        uVar15 = 0;
        uVar29 = 0;
        bVar9 = 1;
LAB_fffffff009969060:
        plVar40 = *(long **)(*(long *)(param_2 + uVar15 * 8) + 0x28);
        if (plVar40 == (long *)0x0) {
LAB_fffffff00996a414:
          auVar42 = FUN_fffffff009983d04();
          plVar40 = auVar42._0_8_;
          uVar29 = *(uint *)(plVar40 + 5);
          uVar33 = uVar29 << 1;
          if (auVar42._8_4_ != 0) {
            uVar33 = auVar42._8_4_;
          }
          do {
            uVar22 = uVar29;
            uVar29 = uVar22 << 1;
          } while (uVar22 < uVar33);
LAB_fffffff00996a470:
          plVar18 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0968);
          plVar18[4] = 0;
          plVar18[5] = 0;
          plVar18[1] = 0;
          *plVar18 = 0;
          plVar18[3] = 0;
          plVar18[2] = 0;
          plVar18[6] = 0;
          plVar18[7] = 0;
          plVar18[9] = 0;
          *(undefined4 *)(plVar18 + 8) = 0;
          *(undefined2 *)(plVar18 + 10) = 0x100;
          uVar37 = FUN_fffffff009968c04
                             (plVar18,uVar22,(int)plVar40[8],*(byte *)((long)plVar40 + 0x51) & 1);
          if ((int)uVar37 != 0) {
            uVar15 = 0;
            do {
              uVar25 = *(ulong *)(plVar40[3] + uVar15 * 8);
              if (uVar25 != 0) {
                do {
                  uVar33 = 0;
                  uVar41 = (uVar25 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar25 & 0x5555555555555555) << 1;
                  uVar41 = (uVar41 & 0xcccccccccccccccc) >> 2 | (uVar41 & 0x3333333333333333) << 2;
                  uVar41 = (uVar41 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar41 & 0xf0f0f0f0f0f0f0f) << 4;
                  uVar41 = (uVar41 & 0xff00ff00ff00ff00) >> 8 | (uVar41 & 0xff00ff00ff00ff) << 8;
                  uVar41 = (uVar41 & 0xffff0000ffff0000) >> 0x10 | (uVar41 & 0xffff0000ffff) << 0x10
                  ;
                  uVar41 = LZCOUNT(uVar41 >> 0x20 | uVar41 << 0x20);
                  uVar25 = uVar25 & (1L << (uVar41 & 0x3f) ^ 0xffffffffffffffffU);
                  uVar41 = uVar41 | (uint)((int)uVar15 << 6);
                  lVar24 = uVar41 * 8;
                  plVar19 = (long *)(*plVar40 + (long)(int)lVar24);
                  if (lVar24 - (int)lVar24 != 0) {
                    plVar19 = (long *)(*plVar40 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  plVar19 = (long *)*plVar19;
                  lVar24 = uVar41 * 4;
                  puVar2 = (undefined4 *)(plVar40[1] + (long)(int)lVar24);
                  if (lVar24 - (int)lVar24 != 0) {
                    puVar2 = (undefined4 *)
                             (plVar40[1] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  uVar6 = *puVar2;
                  uVar28 = (int)plVar18[5] - 1;
                  uVar29 = *(uint *)(plVar18 + 6);
                  uVar41 = (ulong)((long)plVar19 * -0x61c8864680b583eb) >>
                           ((ulong)(uint)-*(int *)((long)plVar18 + 0x34) & 0x3f);
                  uVar31 = uVar41 >> 6 & 0x3ffffff;
                  lVar24 = plVar18[3];
                  uVar34 = (uint)uVar41;
                  uVar38 = *(ulong *)(lVar24 + uVar31 * 8) |
                           -1L << (uVar41 & 0x3f) ^ 0xffffffffffffffffU;
                  iVar30 = 0x40 - (uVar34 & 0x3f);
                  uVar35 = (uint)uVar31;
                  iVar14 = uVar35 << 6;
                  while (uVar35 = uVar35 + 1, uVar38 == 0xffffffffffffffff) {
                    lVar32 = (ulong)(uVar35 & uVar29) * 8;
                    puVar4 = (ulong *)(lVar24 + (int)lVar32);
                    if (lVar32 != (int)lVar32) {
                      puVar4 = (ulong *)(lVar24 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    uVar33 = iVar30 + uVar33;
                    uVar38 = *puVar4;
                    iVar14 = iVar14 + 0x40;
                    iVar30 = 0x40;
                    if (0x7f < uVar33) goto LAB_fffffff00996a838;
                  }
                  uVar31 = (~uVar38 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar38 & 0x5555555555555555) << 1
                  ;
                  uVar31 = (uVar31 & 0xcccccccccccccccc) >> 2 | (uVar31 & 0x3333333333333333) << 2;
                  uVar31 = (uVar31 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar31 & 0xf0f0f0f0f0f0f0f) << 4;
                  uVar31 = (uVar31 & 0xff00ff00ff00ff00) >> 8 | (uVar31 & 0xff00ff00ff00ff) << 8;
                  uVar31 = (uVar31 & 0xffff0000ffff0000) >> 0x10 | (uVar31 & 0xffff0000ffff) << 0x10
                  ;
                  uVar33 = (int)LZCOUNT(uVar31 >> 0x20 | uVar31 << 0x20) + iVar14;
                  uVar31 = (ulong)uVar33;
                  if (0x7f < uVar33 - uVar34) {
LAB_fffffff00996a838:
                    FUN_fffffff009968820(plVar18);
                    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff09a8,plVar18);
                    uVar22 = uVar22 << 1;
                    goto LAB_fffffff00996a470;
                  }
                  while( true ) {
                    uVar33 = (uint)uVar31;
                    if (uVar33 - uVar34 < 0x20) break;
                    uVar35 = uVar33 - 0x1f;
                    if (0x1e < uVar33) {
                      lVar32 = plVar18[2];
                      uVar23 = 0xffffffe1;
                      while( true ) {
                        uVar35 = uVar33 + uVar23;
                        lVar27 = (ulong)(uVar35 & uVar28) * 4;
                        puVar1 = (uint *)(lVar32 + (int)lVar27);
                        if (lVar27 != (int)lVar27) {
                          puVar1 = (uint *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
                        }
                        uVar7 = *puVar1;
                        uVar36 = (uVar7 & 0xaaaaaaaa) >> 1 | (uVar7 & 0x55555555) << 1;
                        uVar36 = (uVar36 & 0xcccccccc) >> 2 | (uVar36 & 0x33333333) << 2;
                        uVar36 = (uVar36 & 0xf0f0f0f0) >> 4 | (uVar36 & 0xf0f0f0f) << 4;
                        uVar36 = (uVar36 & 0xff00ff00) >> 8 | (uVar36 & 0xff00ff) << 8;
                        uVar21 = (uint)LZCOUNT(uVar36 >> 0x10 | uVar36 << 0x10);
                        uVar36 = uVar35 + uVar21;
                        if (uVar7 != 0 && uVar36 < uVar33) break;
                        uVar23 = uVar23 + 1;
                        if (!CARRY4(uVar33,uVar23)) goto LAB_fffffff00996a838;
                      }
                      lVar27 = (ulong)(uVar35 & uVar28) * 4;
                      puVar1 = (uint *)(lVar32 + (int)lVar27);
                      if (lVar27 - (int)lVar27 != 0) {
                        puVar1 = (uint *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      lVar39 = (ulong)(uVar36 & uVar28) * 8;
                      lVar32 = *plVar18;
                      lVar27 = plVar18[1];
                      iVar14 = (int)lVar39;
                      puVar3 = (undefined8 *)(lVar32 + iVar14);
                      if (lVar39 != iVar14) {
                        puVar3 = (undefined8 *)
                                 (lVar32 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      uVar16 = *puVar3;
                      lVar11 = (ulong)(uVar36 & uVar28) * 4;
                      puVar2 = (undefined4 *)(lVar27 + (int)lVar11);
                      if (lVar11 != (int)lVar11) {
                        puVar2 = (undefined4 *)
                                 (lVar27 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      uVar8 = *puVar2;
                      *puVar1 = uVar7 & (1 << (ulong)(uVar21 & 0x1f) ^ 0xffffffffU) |
                                1 << (ulong)(-uVar23 & 0x1f);
                      uVar23 = uVar29 & uVar33 >> 6;
                      *(ulong *)(lVar24 + (ulong)uVar23 * 8) =
                           *(ulong *)(lVar24 + (ulong)uVar23 * 8) | 1L << (uVar31 & 0x3f);
                      lVar24 = (ulong)(uVar33 & uVar28) * 8;
                      puVar3 = (undefined8 *)(lVar32 + (int)lVar24);
                      if (lVar24 != (int)lVar24) {
                        puVar3 = (undefined8 *)
                                 (lVar32 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      *puVar3 = uVar16;
                      lVar24 = (ulong)(uVar33 & uVar28) * 4;
                      puVar2 = (undefined4 *)(lVar27 + (int)lVar24);
                      if (lVar24 != (int)lVar24) {
                        puVar2 = (undefined4 *)
                                 (lVar27 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      *puVar2 = uVar8;
                      puVar3 = (undefined8 *)(*plVar18 + (long)iVar14);
                      if (lVar39 != iVar14) {
                        puVar3 = (undefined8 *)
                                 (*plVar18 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
                      }
                      *puVar3 = 0;
                      lVar24 = plVar18[3];
                      uVar23 = uVar29 & uVar36 >> 6;
                      *(ulong *)(lVar24 + (ulong)uVar23 * 8) =
                           *(ulong *)(lVar24 + (ulong)uVar23 * 8) &
                           (1L << ((ulong)uVar36 & 0x3f) ^ 0xffffffffffffffffU);
                      uVar31 = (ulong)uVar36;
                    }
                    if (uVar35 == uVar33) goto LAB_fffffff00996a838;
                  }
                  lVar32 = (ulong)(uVar33 & uVar28) * 8;
                  lVar24 = plVar18[1];
                  plVar5 = (long *)(*plVar18 + (long)(int)lVar32);
                  if (lVar32 != (int)lVar32) {
                    plVar5 = (long *)(*plVar18 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  *plVar5 = (long)plVar19;
                  lVar32 = (ulong)(uVar33 & uVar28) * 4;
                  puVar2 = (undefined4 *)(lVar24 + (int)lVar32);
                  if (lVar32 != (int)lVar32) {
                    puVar2 = (undefined4 *)(lVar24 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  *puVar2 = uVar6;
                  lVar32 = (uVar41 & 0xffffffff) * 4;
                  lVar24 = plVar18[3];
                  puVar1 = (uint *)(plVar18[2] + (long)(int)lVar32);
                  if (lVar32 != (int)lVar32) {
                    puVar1 = (uint *)(plVar18[2] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                  }
                  *puVar1 = *puVar1 | 1 << (ulong)(uVar33 - uVar34 & 0x1f);
                  uVar29 = uVar29 & uVar33 >> 6;
                  *(ulong *)(lVar24 + (ulong)uVar29 * 8) =
                       *(ulong *)(lVar24 + (ulong)uVar29 * 8) | 1L << (uVar31 & 0x3f);
                  lVar24 = (**(code **)(*plVar19 + 0x108))(*plVar19 + 0x108);
                  plVar18[9] = plVar18[9] + lVar24;
                  *(int *)(plVar18 + 7) = (int)plVar18[7] + 1;
                } while (uVar25 != 0);
              }
              uVar33 = (int)uVar15 + 1;
              uVar15 = (ulong)uVar33;
            } while (uVar33 <= *(uint *)(plVar40 + 6));
            lVar24 = *plVar18;
            lVar27 = plVar40[1];
            lVar32 = *plVar40;
            plVar40[1] = plVar18[1];
            *plVar40 = lVar24;
            plVar18[1] = lVar27;
            *plVar18 = lVar32;
            lVar24 = plVar18[2];
            lVar27 = plVar40[3];
            lVar32 = plVar40[2];
            plVar40[3] = plVar18[3];
            plVar40[2] = lVar24;
            plVar18[3] = lVar27;
            plVar18[2] = lVar32;
            lVar24 = plVar40[4];
            plVar40[4] = plVar18[4];
            plVar18[4] = lVar24;
            lVar24 = plVar40[5];
            *(int *)(plVar40 + 5) = (int)plVar18[5];
            *(int *)(plVar18 + 5) = (int)lVar24;
            lVar24 = plVar40[8];
            *(int *)(plVar40 + 8) = (int)plVar18[8];
            *(int *)(plVar18 + 8) = (int)lVar24;
            uVar6 = *(undefined4 *)((long)plVar40 + 0x2c);
            *(undefined4 *)((long)plVar40 + 0x2c) = *(undefined4 *)((long)plVar18 + 0x2c);
            *(undefined4 *)((long)plVar18 + 0x2c) = uVar6;
            lVar24 = plVar40[6];
            *(int *)(plVar40 + 6) = (int)plVar18[6];
            *(int *)(plVar18 + 6) = (int)lVar24;
            uVar6 = *(undefined4 *)((long)plVar40 + 0x34);
            *(undefined4 *)((long)plVar40 + 0x34) = *(undefined4 *)((long)plVar18 + 0x34);
            *(undefined4 *)((long)plVar18 + 0x34) = uVar6;
            lVar24 = plVar40[7];
            *(int *)(plVar40 + 7) = (int)plVar18[7];
            *(int *)(plVar18 + 7) = (int)lVar24;
            uVar6 = *(undefined4 *)((long)plVar40 + 0x3c);
            *(undefined4 *)((long)plVar40 + 0x3c) = *(undefined4 *)((long)plVar18 + 0x3c);
            *(undefined4 *)((long)plVar18 + 0x3c) = uVar6;
            lVar24 = plVar40[9];
            plVar40[9] = plVar18[9];
            plVar18[9] = lVar24;
            bVar9 = *(byte *)((long)plVar40 + 0x51);
            *(byte *)((long)plVar40 + 0x51) = *(byte *)((long)plVar18 + 0x51) & 1;
            *(byte *)((long)plVar18 + 0x51) = bVar9 & 1;
            FUN_fffffff009968820(plVar18);
            thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff09a8,plVar18);
          }
          return uVar37;
        }
        if (DAT_fffffff00af227e8 != 0) {
          uVar37 = (**(code **)(*plVar40 + 0xe0))(plVar40);
          local_68 = 0;
          thunk_EXT_FUN_80110000032db760(uVar37,&local_68);
          uVar37 = local_68;
          uVar16 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
          uVar17 = (**(code **)(*param_1 + 0xe0))(param_1);
          local_68 = 0;
          thunk_EXT_FUN_80110000032db760(uVar17,&local_68);
          thunk_EXT_FUN_80110000036da494
                    (0x8518018c,uVar37,uVar16,local_68,(long)*(int *)((long)param_1 + 0x24),0);
        }
        uVar22 = (int)param_1[0x15] - 1;
        uVar41 = (long)plVar40 * -0x61c8864680b583eb;
        uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
        lVar32 = (uVar25 & 0xffffffff) * 4;
        puVar1 = (uint *)(param_1[0x12] + (long)(int)lVar32);
        if (lVar32 != (int)lVar32) {
          puVar1 = (uint *)(param_1[0x12] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar34 = *puVar1;
        uVar28 = uVar34;
        do {
          iVar14 = (int)uVar25;
          if (uVar28 == 0) {
            bVar12 = false;
            goto LAB_fffffff0099691c4;
          }
          uVar35 = (uVar28 & 0xaaaaaaaa) >> 1 | (uVar28 & 0x55555555) << 1;
          uVar35 = (uVar35 & 0xcccccccc) >> 2 | (uVar35 & 0x33333333) << 2;
          uVar35 = (uVar35 & 0xf0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f) << 4;
          uVar35 = (uVar35 & 0xff00ff00) >> 8 | (uVar35 & 0xff00ff) << 8;
          uVar35 = (uint)LZCOUNT(uVar35 >> 0x10 | uVar35 << 0x10);
          uVar28 = uVar28 & (1 << (ulong)(uVar35 & 0x1f) ^ 0xffffffffU);
          uVar31 = (ulong)(uVar35 + iVar14 & uVar22);
          lVar32 = uVar31 * 8;
          plVar18 = (long *)(param_1[0x10] + (long)(int)lVar32);
          if (lVar32 != (int)lVar32) {
            plVar18 = (long *)(param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while ((long *)*plVar18 != plVar40);
        lVar32 = uVar31 * 4;
        piVar26 = (int *)(param_1[0x11] + (long)(int)lVar32);
        if (lVar32 - (int)lVar32 != 0) {
          piVar26 = (int *)(param_1[0x11] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        bVar12 = *piVar26 != 0;
LAB_fffffff0099691c4:
        uVar28 = (int)param_1[0x20] - 1;
        uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
        lVar32 = (uVar25 & 0xffffffff) * 4;
        puVar1 = (uint *)(param_1[0x1d] + (long)(int)lVar32);
        if (lVar32 != (int)lVar32) {
          puVar1 = (uint *)(param_1[0x1d] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar23 = *puVar1;
        uVar35 = uVar23;
        do {
          iVar30 = (int)uVar25;
          if (uVar35 == 0) {
            bVar13 = true;
            goto LAB_fffffff009969270;
          }
          uVar36 = (uVar35 & 0xaaaaaaaa) >> 1 | (uVar35 & 0x55555555) << 1;
          uVar36 = (uVar36 & 0xcccccccc) >> 2 | (uVar36 & 0x33333333) << 2;
          uVar36 = (uVar36 & 0xf0f0f0f0) >> 4 | (uVar36 & 0xf0f0f0f) << 4;
          uVar36 = (uVar36 & 0xff00ff00) >> 8 | (uVar36 & 0xff00ff) << 8;
          uVar36 = (uint)LZCOUNT(uVar36 >> 0x10 | uVar36 << 0x10);
          uVar35 = uVar35 & (1 << (ulong)(uVar36 & 0x1f) ^ 0xffffffffU);
          uVar31 = (ulong)(uVar36 + iVar30 & uVar28);
          lVar32 = uVar31 * 8;
          puVar3 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
          if (lVar32 != (int)lVar32) {
            puVar3 = (undefined8 *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while ((long *)*puVar3 != plVar40);
        lVar32 = uVar31 * 4;
        piVar26 = (int *)(param_1[0x1c] + (long)(int)lVar32);
        if (lVar32 - (int)lVar32 != 0) {
          piVar26 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        bVar13 = *piVar26 == 0;
LAB_fffffff009969270:
        if (!bVar12 && !(bool)(bVar9 & bVar13)) {
          do {
            if (uVar23 == 0) goto LAB_fffffff009969700;
            uVar22 = (uVar23 & 0xaaaaaaaa) >> 1 | (uVar23 & 0x55555555) << 1;
            uVar22 = (uVar22 & 0xcccccccc) >> 2 | (uVar22 & 0x33333333) << 2;
            uVar22 = (uVar22 & 0xf0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f) << 4;
            uVar22 = (uVar22 & 0xff00ff00) >> 8 | (uVar22 & 0xff00ff) << 8;
            uVar22 = (uint)LZCOUNT(uVar22 >> 0x10 | uVar22 << 0x10);
            uVar23 = uVar23 & (1 << (ulong)(uVar22 & 0x1f) ^ 0xffffffffU);
            uVar25 = (ulong)(uVar22 + iVar30 & uVar28);
            lVar32 = uVar25 * 8;
            plVar18 = (long *)(param_1[0x1b] + (long)(int)lVar32);
            if (lVar32 != (int)lVar32) {
              plVar18 = (long *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
            }
          } while ((long *)*plVar18 != plVar40);
          lVar32 = uVar25 * 4;
          piVar26 = (int *)(param_1[0x1c] + (long)(int)lVar32);
          if (lVar32 - (int)lVar32 != 0) {
            piVar26 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
          }
          goto LAB_fffffff009969354;
        }
        do {
          if (uVar34 == 0) goto LAB_fffffff0099694d8;
          uVar28 = (uVar34 & 0xaaaaaaaa) >> 1 | (uVar34 & 0x55555555) << 1;
          uVar28 = (uVar28 & 0xcccccccc) >> 2 | (uVar28 & 0x33333333) << 2;
          uVar28 = (uVar28 & 0xf0f0f0f0) >> 4 | (uVar28 & 0xf0f0f0f) << 4;
          uVar28 = (uVar28 & 0xff00ff00) >> 8 | (uVar28 & 0xff00ff) << 8;
          uVar28 = (uint)LZCOUNT(uVar28 >> 0x10 | uVar28 << 0x10);
          uVar34 = uVar34 & (1 << (ulong)(uVar28 & 0x1f) ^ 0xffffffffU);
          uVar25 = (ulong)(uVar28 + iVar14 & uVar22);
          lVar32 = uVar25 * 8;
          plVar18 = (long *)(param_1[0x10] + (long)(int)lVar32);
          if (lVar32 != (int)lVar32) {
            plVar18 = (long *)(param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
          }
        } while ((long *)*plVar18 != plVar40);
        lVar32 = uVar25 * 4;
        piVar26 = (int *)(param_1[0x11] + (long)(int)lVar32);
        if (lVar32 - (int)lVar32 != 0) {
          piVar26 = (int *)(param_1[0x11] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *piVar26 = *piVar26 + 1;
LAB_fffffff0099692ec:
        uVar29 = uVar29 + 1;
        goto LAB_fffffff009969b04;
      }
      goto LAB_fffffff00996900c;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Overflow when adding excess capacity\n");
  }
  uVar37 = 0xe00002c2;
  goto LAB_fffffff009968fa4;
LAB_fffffff009969700:
  uVar22 = 0;
  uVar35 = (int)param_1[0x20] - 1;
  uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
  uVar23 = (uint)uVar25;
  uVar34 = uVar23 >> 6;
  lVar32 = param_1[0x1e];
  uVar28 = *(uint *)(param_1 + 0x21);
  uVar31 = *(ulong *)(lVar32 + (ulong)uVar34 * 8) | -1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU;
  iVar30 = 0x40 - (uVar23 & 0x3f);
  iVar14 = uVar34 << 6;
  do {
    uVar34 = uVar34 + 1;
    if (uVar31 != 0xffffffffffffffff) {
      uVar31 = (~uVar31 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar31 & 0x5555555555555555) << 1;
      uVar31 = (uVar31 & 0xcccccccccccccccc) >> 2 | (uVar31 & 0x3333333333333333) << 2;
      uVar31 = (uVar31 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar31 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar31 = (uVar31 & 0xff00ff00ff00ff00) >> 8 | (uVar31 & 0xff00ff00ff00ff) << 8;
      uVar31 = (uVar31 & 0xffff0000ffff0000) >> 0x10 | (uVar31 & 0xffff0000ffff) << 0x10;
      uVar22 = (int)LZCOUNT(uVar31 >> 0x20 | uVar31 << 0x20) + iVar14;
      uVar31 = (ulong)uVar22;
      if (uVar22 - uVar23 < 0x80) goto LAB_fffffff00996958c;
      break;
    }
    lVar27 = (ulong)(uVar34 & uVar28) * 8;
    puVar4 = (ulong *)(lVar32 + (int)lVar27);
    if (lVar27 != (int)lVar27) {
      puVar4 = (ulong *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar22 = iVar30 + uVar22;
    uVar31 = *puVar4;
    iVar14 = iVar14 + 0x40;
    iVar30 = 0x40;
  } while (uVar22 < 0x80);
  goto LAB_fffffff0099697a4;
  while( true ) {
    uVar34 = uVar22 - 0x1f;
    if (0x1e < uVar22) {
      lVar27 = param_1[0x1d];
      uVar36 = 0xffffffe1;
      while( true ) {
        uVar34 = uVar22 + uVar36;
        lVar39 = (ulong)(uVar34 & uVar35) * 4;
        puVar1 = (uint *)(lVar27 + (int)lVar39);
        if (lVar39 != (int)lVar39) {
          puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar21 = *puVar1;
        uVar7 = (uVar21 & 0xaaaaaaaa) >> 1 | (uVar21 & 0x55555555) << 1;
        uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
        uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
        uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
        uVar20 = (uint)LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
        uVar7 = uVar34 + uVar20;
        if (uVar21 != 0 && uVar7 < uVar22) break;
        uVar36 = uVar36 + 1;
        if (!CARRY4(uVar22,uVar36)) goto LAB_fffffff0099697a4;
      }
      lVar39 = (ulong)(uVar34 & uVar35) * 4;
      puVar1 = (uint *)(lVar27 + (int)lVar39);
      if (lVar39 - (int)lVar39 != 0) {
        puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar11 = (ulong)(uVar7 & uVar35) * 8;
      lVar27 = param_1[0x1b];
      lVar39 = param_1[0x1c];
      iVar14 = (int)lVar11;
      puVar3 = (undefined8 *)(lVar27 + iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(lVar27 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar37 = *puVar3;
      lVar10 = (ulong)(uVar7 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar2 = (undefined4 *)(lVar39 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar6 = *puVar2;
      *puVar1 = uVar21 & (1 << (ulong)(uVar20 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar36 & 0x1f);
      uVar36 = uVar28 & uVar22 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(lVar27 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(lVar27 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = uVar37;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(lVar39 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = uVar6;
      puVar3 = (undefined8 *)(param_1[0x1b] + (long)iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(param_1[0x1b] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 0;
      lVar32 = param_1[0x1e];
      uVar36 = uVar28 & uVar7 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) &
           (1L << ((ulong)uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      uVar31 = (ulong)uVar7;
    }
    if (uVar34 == uVar22) break;
LAB_fffffff00996958c:
    uVar22 = (uint)uVar31;
    if (uVar22 - uVar23 < 0x20) {
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = plVar40;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(param_1[0x1c] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = 1;
      lVar32 = (uVar25 & 0xffffffff) * 4;
      puVar1 = (uint *)(param_1[0x1d] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar1 = (uint *)(param_1[0x1d] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 | 1 << (ulong)(uVar22 - uVar23 & 0x1f);
      uVar28 = uVar28 & uVar22 >> 6;
      *(ulong *)(param_1[0x1e] + (ulong)uVar28 * 8) =
           *(ulong *)(param_1[0x1e] + (ulong)uVar28 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (**(code **)(*plVar40 + 0x108))(*plVar40 + 0x108,plVar40);
      param_1[0x24] = param_1[0x24] + lVar32;
      *(int *)(param_1 + 0x22) = (int)param_1[0x22] + 1;
      (**(code **)(*plVar40 + 0x20))(plVar40);
      goto LAB_fffffff009969b04;
    }
  }
LAB_fffffff0099697a4:
  uVar25 = FUN_fffffff00996a418(param_1 + 0x1b,0);
  if ((uVar25 & 1) == 0) goto LAB_fffffff009969f64;
  goto LAB_fffffff009969700;
LAB_fffffff0099694d8:
  uVar22 = 0;
  uVar35 = (int)param_1[0x15] - 1;
  uVar28 = *(uint *)(param_1 + 0x16);
  uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
  uVar23 = (uint)uVar25;
  uVar34 = uVar23 >> 6;
  lVar32 = param_1[0x13];
  uVar31 = *(ulong *)(lVar32 + (ulong)uVar34 * 8) | -1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU;
  iVar30 = 0x40 - (uVar23 & 0x3f);
  iVar14 = uVar34 << 6;
  do {
    uVar34 = uVar34 + 1;
    if (uVar31 != 0xffffffffffffffff) {
      uVar31 = (~uVar31 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar31 & 0x5555555555555555) << 1;
      uVar31 = (uVar31 & 0xcccccccccccccccc) >> 2 | (uVar31 & 0x3333333333333333) << 2;
      uVar31 = (uVar31 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar31 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar31 = (uVar31 & 0xff00ff00ff00ff00) >> 8 | (uVar31 & 0xff00ff00ff00ff) << 8;
      uVar31 = (uVar31 & 0xffff0000ffff0000) >> 0x10 | (uVar31 & 0xffff0000ffff) << 0x10;
      uVar22 = (int)LZCOUNT(uVar31 >> 0x20 | uVar31 << 0x20) + iVar14;
      uVar31 = (ulong)uVar22;
      if (uVar22 - uVar23 < 0x80) goto LAB_fffffff009969364;
      break;
    }
    lVar27 = (ulong)(uVar34 & uVar28) * 8;
    puVar4 = (ulong *)(lVar32 + (int)lVar27);
    if (lVar27 != (int)lVar27) {
      puVar4 = (ulong *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar22 = iVar30 + uVar22;
    uVar31 = *puVar4;
    iVar14 = iVar14 + 0x40;
    iVar30 = 0x40;
  } while (uVar22 < 0x80);
  goto LAB_fffffff009969578;
  while( true ) {
    uVar34 = uVar22 - 0x1f;
    if (0x1e < uVar22) {
      lVar27 = param_1[0x12];
      uVar36 = 0xffffffe1;
      while( true ) {
        uVar34 = uVar22 + uVar36;
        lVar39 = (ulong)(uVar34 & uVar35) * 4;
        puVar1 = (uint *)(lVar27 + (int)lVar39);
        if (lVar39 != (int)lVar39) {
          puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar21 = *puVar1;
        uVar7 = (uVar21 & 0xaaaaaaaa) >> 1 | (uVar21 & 0x55555555) << 1;
        uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
        uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
        uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
        uVar20 = (uint)LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
        uVar7 = uVar34 + uVar20;
        if (uVar21 != 0 && uVar7 < uVar22) break;
        uVar36 = uVar36 + 1;
        if (!CARRY4(uVar22,uVar36)) goto LAB_fffffff009969578;
      }
      lVar39 = (ulong)(uVar34 & uVar35) * 4;
      puVar1 = (uint *)(lVar27 + (int)lVar39);
      if (lVar39 - (int)lVar39 != 0) {
        puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar11 = (ulong)(uVar7 & uVar35) * 8;
      lVar27 = param_1[0x10];
      lVar39 = param_1[0x11];
      iVar14 = (int)lVar11;
      puVar3 = (undefined8 *)(lVar27 + iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(lVar27 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar37 = *puVar3;
      lVar10 = (ulong)(uVar7 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar2 = (undefined4 *)(lVar39 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar6 = *puVar2;
      *puVar1 = uVar21 & (1 << (ulong)(uVar20 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar36 & 0x1f);
      uVar36 = uVar28 & uVar22 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(lVar27 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(lVar27 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = uVar37;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(lVar39 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = uVar6;
      puVar3 = (undefined8 *)(param_1[0x10] + (long)iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(param_1[0x10] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 0;
      lVar32 = param_1[0x13];
      uVar36 = uVar28 & uVar7 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) &
           (1L << ((ulong)uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      uVar31 = (ulong)uVar7;
    }
    if (uVar34 == uVar22) break;
LAB_fffffff009969364:
    uVar22 = (uint)uVar31;
    if (uVar22 - uVar23 < 0x20) {
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(param_1[0x10] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = plVar40;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(param_1[0x11] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(param_1[0x11] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = 1;
      lVar32 = (uVar25 & 0xffffffff) * 4;
      puVar1 = (uint *)(param_1[0x12] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar1 = (uint *)(param_1[0x12] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 | 1 << (ulong)(uVar22 - uVar23 & 0x1f);
      uVar28 = uVar28 & uVar22 >> 6;
      *(ulong *)(param_1[0x13] + (ulong)uVar28 * 8) =
           *(ulong *)(param_1[0x13] + (ulong)uVar28 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (**(code **)(*plVar40 + 0x108))(*plVar40 + 0x108,plVar40);
      param_1[0x19] = param_1[0x19] + lVar32;
      *(int *)(param_1 + 0x17) = (int)param_1[0x17] + 1;
      (**(code **)(*plVar40 + 0x20))(plVar40);
      if (((uVar33 >> 1 & 1) == 0) || (iVar14 = FUN_fffffff0099436e4(plVar40,lVar24), iVar14 == 0))
      goto LAB_fffffff0099692ec;
      uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
      lVar32 = (uVar25 & 0xffffffff) * 4;
      iVar14 = (int)lVar32;
      puVar1 = (uint *)(param_1[0x12] + (long)iVar14);
      if (lVar32 - iVar14 != 0) {
        puVar1 = (uint *)(param_1[0x12] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar22 = *puVar1;
      goto LAB_fffffff009969918;
    }
  }
LAB_fffffff009969578:
  uVar25 = FUN_fffffff00996a418(param_1 + 0x10,0);
  if ((uVar25 & 1) == 0) goto LAB_fffffff009969f64;
  goto LAB_fffffff0099694d8;
  while( true ) {
    uVar28 = (uVar22 & 0xaaaaaaaa) >> 1 | (uVar22 & 0x55555555) << 1;
    uVar28 = (uVar28 & 0xcccccccc) >> 2 | (uVar28 & 0x33333333) << 2;
    uVar28 = (uVar28 & 0xf0f0f0f0) >> 4 | (uVar28 & 0xf0f0f0f) << 4;
    uVar28 = (uVar28 & 0xff00ff00) >> 8 | (uVar28 & 0xff00ff) << 8;
    uVar28 = (uint)LZCOUNT(uVar28 >> 0x10 | uVar28 << 0x10);
    uVar34 = 1 << (ulong)(uVar28 & 0x1f);
    uVar22 = uVar22 & (uVar34 ^ 0xffffffff);
    uVar28 = uVar28 + (int)uVar25;
    uVar31 = (ulong)(uVar28 & (int)param_1[0x15] - 1U);
    lVar39 = param_1[0x10];
    lVar27 = uVar31 * 8;
    plVar18 = (long *)(lVar39 + (int)lVar27);
    if (lVar27 != (int)lVar27) {
      plVar18 = (long *)(lVar39 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar18 = (long *)*plVar18;
    if (plVar18 == plVar40) break;
LAB_fffffff009969918:
    if (uVar22 == 0) goto LAB_fffffff00996a410;
  }
  lVar27 = uVar31 * 4;
  piVar26 = (int *)(param_1[0x11] + (long)(int)lVar27);
  if (lVar27 - (int)lVar27 != 0) {
    piVar26 = (int *)(param_1[0x11] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
  }
  iVar30 = *piVar26;
  *piVar26 = iVar30 + -1;
  if (iVar30 + -1 == 0) {
    bVar9 = *(byte *)((long)param_1 + 0xd1);
    lVar27 = (**(code **)(*plVar18 + 0x108))();
    param_1[0x19] = param_1[0x19] - lVar27;
    lVar27 = uVar31 * 8;
    puVar3 = (undefined8 *)(lVar39 + (int)lVar27);
    if (lVar27 - (int)lVar27 != 0) {
      puVar3 = (undefined8 *)(lVar39 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar18 = (long *)*puVar3;
    if ((bVar9 & 1) == 0) {
      (**(code **)(*plVar18 + 0x28))();
      *puVar3 = 0;
    }
    else {
      *puVar3 = 0;
      (**(code **)(*plVar18 + 0x28))();
    }
    puVar1 = (uint *)(param_1[0x12] + (long)iVar14);
    if (lVar32 != iVar14) {
      puVar1 = (uint *)(param_1[0x12] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = *puVar1 & ~uVar34;
    uVar22 = *(uint *)(param_1 + 0x16) & uVar28 >> 6;
    *(ulong *)(param_1[0x13] + (ulong)uVar22 * 8) =
         *(ulong *)(param_1[0x13] + (ulong)uVar22 * 8) &
         (1L << ((ulong)uVar28 & 0x3f) ^ 0xffffffffffffffffU);
    *(int *)(param_1 + 0x17) = (int)param_1[0x17] + -1;
  }
  uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
  lVar32 = (uVar25 & 0xffffffff) * 4;
  puVar1 = (uint *)(param_1[0x1d] + (long)(int)lVar32);
  if (lVar32 != (int)lVar32) {
    puVar1 = (uint *)(param_1[0x1d] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar22 = *puVar1;
  do {
    if (uVar22 == 0) goto LAB_fffffff009969db0;
    uVar28 = (uVar22 & 0xaaaaaaaa) >> 1 | (uVar22 & 0x55555555) << 1;
    uVar28 = (uVar28 & 0xcccccccc) >> 2 | (uVar28 & 0x33333333) << 2;
    uVar28 = (uVar28 & 0xf0f0f0f0) >> 4 | (uVar28 & 0xf0f0f0f) << 4;
    uVar28 = (uVar28 & 0xff00ff00) >> 8 | (uVar28 & 0xff00ff) << 8;
    uVar28 = (uint)LZCOUNT(uVar28 >> 0x10 | uVar28 << 0x10);
    uVar22 = uVar22 & (1 << (ulong)(uVar28 & 0x1f) ^ 0xffffffffU);
    uVar31 = (ulong)(uVar28 + (int)uVar25 & (int)param_1[0x20] - 1U);
    lVar32 = uVar31 * 8;
    plVar18 = (long *)(param_1[0x1b] + (long)(int)lVar32);
    if (lVar32 != (int)lVar32) {
      plVar18 = (long *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
  } while ((long *)*plVar18 != plVar40);
  bVar9 = 0;
  lVar32 = uVar31 * 4;
  piVar26 = (int *)(param_1[0x1c] + (long)(int)lVar32);
  if (lVar32 - (int)lVar32 != 0) {
    piVar26 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
  }
LAB_fffffff009969354:
  *piVar26 = *piVar26 + 1;
LAB_fffffff009969b04:
  uVar15 = uVar15 + 1;
  if (uVar15 == param_3) goto LAB_fffffff00996a3c8;
  goto LAB_fffffff009969060;
LAB_fffffff009969db0:
  uVar22 = 0;
  uVar35 = (int)param_1[0x20] - 1;
  uVar25 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
  uVar23 = (uint)uVar25;
  uVar34 = uVar23 >> 6;
  lVar32 = param_1[0x1e];
  uVar28 = *(uint *)(param_1 + 0x21);
  uVar31 = *(ulong *)(lVar32 + (ulong)uVar34 * 8) | -1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU;
  iVar30 = 0x40 - (uVar23 & 0x3f);
  iVar14 = uVar34 << 6;
  do {
    uVar34 = uVar34 + 1;
    if (uVar31 != 0xffffffffffffffff) {
      uVar31 = (~uVar31 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar31 & 0x5555555555555555) << 1;
      uVar31 = (uVar31 & 0xcccccccccccccccc) >> 2 | (uVar31 & 0x3333333333333333) << 2;
      uVar31 = (uVar31 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar31 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar31 = (uVar31 & 0xff00ff00ff00ff00) >> 8 | (uVar31 & 0xff00ff00ff00ff) << 8;
      uVar31 = (uVar31 & 0xffff0000ffff0000) >> 0x10 | (uVar31 & 0xffff0000ffff) << 0x10;
      uVar22 = (int)LZCOUNT(uVar31 >> 0x20 | uVar31 << 0x20) + iVar14;
      uVar31 = (ulong)uVar22;
      if (uVar22 - uVar23 < 0x80) goto LAB_fffffff009969c3c;
      break;
    }
    lVar27 = (ulong)(uVar34 & uVar28) * 8;
    puVar4 = (ulong *)(lVar32 + (int)lVar27);
    if (lVar27 != (int)lVar27) {
      puVar4 = (ulong *)(lVar32 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar22 = iVar30 + uVar22;
    uVar31 = *puVar4;
    iVar14 = iVar14 + 0x40;
    iVar30 = 0x40;
  } while (uVar22 < 0x80);
  goto LAB_fffffff009969e54;
  while( true ) {
    uVar34 = uVar22 - 0x1f;
    if (0x1e < uVar22) {
      lVar27 = param_1[0x1d];
      uVar36 = 0xffffffe1;
      while( true ) {
        uVar34 = uVar22 + uVar36;
        lVar39 = (ulong)(uVar34 & uVar35) * 4;
        puVar1 = (uint *)(lVar27 + (int)lVar39);
        if (lVar39 != (int)lVar39) {
          puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar21 = *puVar1;
        uVar7 = (uVar21 & 0xaaaaaaaa) >> 1 | (uVar21 & 0x55555555) << 1;
        uVar7 = (uVar7 & 0xcccccccc) >> 2 | (uVar7 & 0x33333333) << 2;
        uVar7 = (uVar7 & 0xf0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f) << 4;
        uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
        uVar20 = (uint)LZCOUNT(uVar7 >> 0x10 | uVar7 << 0x10);
        uVar7 = uVar34 + uVar20;
        if (uVar21 != 0 && uVar7 < uVar22) break;
        uVar36 = uVar36 + 1;
        if (!CARRY4(uVar22,uVar36)) goto LAB_fffffff009969e54;
      }
      lVar39 = (ulong)(uVar34 & uVar35) * 4;
      puVar1 = (uint *)(lVar27 + (int)lVar39);
      if (lVar39 - (int)lVar39 != 0) {
        puVar1 = (uint *)(lVar27 + lVar39 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar11 = (ulong)(uVar7 & uVar35) * 8;
      lVar27 = param_1[0x1b];
      lVar39 = param_1[0x1c];
      iVar14 = (int)lVar11;
      puVar3 = (undefined8 *)(lVar27 + iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(lVar27 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar37 = *puVar3;
      lVar10 = (ulong)(uVar7 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar10);
      if (lVar10 != (int)lVar10) {
        puVar2 = (undefined4 *)(lVar39 + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar6 = *puVar2;
      *puVar1 = uVar21 & (1 << (ulong)(uVar20 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar36 & 0x1f);
      uVar36 = uVar28 & uVar22 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(lVar27 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(lVar27 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = uVar37;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(lVar39 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(lVar39 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = uVar6;
      puVar3 = (undefined8 *)(param_1[0x1b] + (long)iVar14);
      if (lVar11 != iVar14) {
        puVar3 = (undefined8 *)(param_1[0x1b] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = 0;
      lVar32 = param_1[0x1e];
      uVar36 = uVar28 & uVar7 >> 6;
      *(ulong *)(lVar32 + (ulong)uVar36 * 8) =
           *(ulong *)(lVar32 + (ulong)uVar36 * 8) &
           (1L << ((ulong)uVar7 & 0x3f) ^ 0xffffffffffffffffU);
      uVar31 = (ulong)uVar7;
    }
    if (uVar34 == uVar22) break;
LAB_fffffff009969c3c:
    uVar22 = (uint)uVar31;
    if (uVar22 - uVar23 < 0x20) {
      lVar32 = (ulong)(uVar22 & uVar35) * 8;
      puVar3 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar3 = (undefined8 *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar3 = plVar40;
      lVar32 = (ulong)(uVar22 & uVar35) * 4;
      puVar2 = (undefined4 *)(param_1[0x1c] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar2 = (undefined4 *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar2 = 1;
      lVar32 = (uVar25 & 0xffffffff) * 4;
      puVar1 = (uint *)(param_1[0x1d] + (long)(int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar1 = (uint *)(param_1[0x1d] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 | 1 << (ulong)(uVar22 - uVar23 & 0x1f);
      uVar28 = uVar28 & uVar22 >> 6;
      *(ulong *)(param_1[0x1e] + (ulong)uVar28 * 8) =
           *(ulong *)(param_1[0x1e] + (ulong)uVar28 * 8) | 1L << (uVar31 & 0x3f);
      lVar32 = (**(code **)(*plVar40 + 0x108))(*plVar40 + 0x108,plVar40);
      param_1[0x24] = param_1[0x24] + lVar32;
      *(int *)(param_1 + 0x22) = (int)param_1[0x22] + 1;
      (**(code **)(*plVar40 + 0x20))(plVar40);
      bVar9 = 0;
      goto LAB_fffffff009969b04;
    }
  }
LAB_fffffff009969e54:
  uVar25 = FUN_fffffff00996a418(param_1 + 0x1b,0);
  if ((uVar25 & 1) == 0) goto LAB_fffffff009969f64;
  goto LAB_fffffff009969db0;
LAB_fffffff009969f64:
  if ((uVar15 & 0xffffffff) == 0) goto LAB_fffffff00996a37c;
  uVar25 = 0;
  goto LAB_fffffff009969f78;
LAB_fffffff00996a3c8:
  if ((uVar33 >> 1 & 1) == 0) {
LAB_fffffff00996900c:
    uVar37 = 0;
    goto LAB_fffffff009968fa4;
  }
  if (uVar29 == param_3) {
LAB_fffffff00996a3d8:
    uVar37 = 0;
    *(uint *)((long)param_1 + 0x24) = *(uint *)((long)param_1 + 0x24) | 1;
    LORelease();
  }
  else {
    uVar37 = 0;
    *(uint *)((long)param_1 + 0x24) = *(uint *)((long)param_1 + 0x24) & 0xfffffffe;
    LORelease();
  }
  goto LAB_fffffff00996a3e8;
  while( true ) {
    uVar22 = (uVar29 & 0xaaaaaaaa) >> 1 | (uVar29 & 0x55555555) << 1;
    uVar22 = (uVar22 & 0xcccccccc) >> 2 | (uVar22 & 0x33333333) << 2;
    uVar22 = (uVar22 & 0xf0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f) << 4;
    uVar22 = (uVar22 & 0xff00ff00) >> 8 | (uVar22 & 0xff00ff) << 8;
    uVar22 = (uint)LZCOUNT(uVar22 >> 0x10 | uVar22 << 0x10);
    uVar28 = 1 << (ulong)(uVar22 & 0x1f);
    uVar29 = uVar29 & (uVar28 ^ 0xffffffff);
    uVar22 = uVar22 + (int)uVar41;
    uVar31 = (ulong)(uVar22 & (int)param_1[0x20] - 1U);
    lVar27 = param_1[0x1b];
    lVar32 = uVar31 * 8;
    plVar18 = (long *)(lVar27 + (int)lVar32);
    if (lVar32 != (int)lVar32) {
      plVar18 = (long *)(lVar27 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar18 = (long *)*plVar18;
    if (plVar18 == plVar40) break;
LAB_fffffff00996a0f8:
    if (uVar29 == 0) {
      FUN_fffffff009983cd4();
LAB_fffffff00996a410:
      FUN_fffffff009983ca4();
      goto LAB_fffffff00996a414;
    }
  }
  lVar32 = uVar31 * 4;
  piVar26 = (int *)(param_1[0x1c] + (long)(int)lVar32);
  if (lVar32 - (int)lVar32 != 0) {
    piVar26 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
  }
  iVar30 = *piVar26;
  *piVar26 = iVar30 + -1;
  if (iVar30 + -1 == 0) {
    bVar9 = *(byte *)((long)param_1 + 0x129);
    lVar32 = (**(code **)(*plVar18 + 0x108))();
    param_1[0x24] = param_1[0x24] - lVar32;
    lVar32 = uVar31 * 8;
    puVar3 = (undefined8 *)(lVar27 + (int)lVar32);
    if (lVar32 - (int)lVar32 != 0) {
      puVar3 = (undefined8 *)(lVar27 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar40 = (long *)*puVar3;
    if ((bVar9 & 1) == 0) {
      (**(code **)(*plVar40 + 0x28))();
      *puVar3 = 0;
    }
    else {
      *puVar3 = 0;
      (**(code **)(*plVar40 + 0x28))();
    }
    puVar1 = (uint *)(param_1[0x1d] + (long)iVar14);
    if (lVar24 - iVar14 != 0) {
      puVar1 = (uint *)(param_1[0x1d] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = *puVar1 & ~uVar28;
    uVar29 = *(uint *)(param_1 + 0x21) & uVar22 >> 6;
    *(ulong *)(param_1[0x1e] + (ulong)uVar29 * 8) =
         *(ulong *)(param_1[0x1e] + (ulong)uVar29 * 8) &
         (1L << ((ulong)uVar22 & 0x3f) ^ 0xffffffffffffffffU);
    *(int *)(param_1 + 0x22) = (int)param_1[0x22] + -1;
  }
  while (uVar25 = uVar25 + 1, uVar25 != (uVar15 & 0xffffffff)) {
LAB_fffffff009969f78:
    plVar40 = *(long **)(*(long *)(param_2 + uVar25 * 8) + 0x28);
    uVar41 = (long)plVar40 * -0x61c8864680b583eb;
    uVar31 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
    lVar24 = param_1[0x12];
    lVar32 = (uVar31 & 0xffffffff) * 4;
    iVar14 = (int)lVar32;
    puVar1 = (uint *)(lVar24 + iVar14);
    if (lVar32 - iVar14 != 0) {
      puVar1 = (uint *)(lVar24 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar29 = *puVar1;
    do {
      if (uVar29 == 0) {
        uVar41 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0x10c) & 0x3f);
        lVar24 = (uVar41 & 0xffffffff) * 4;
        iVar14 = (int)lVar24;
        puVar1 = (uint *)(param_1[0x1d] + (long)iVar14);
        if (lVar24 - iVar14 != 0) {
          puVar1 = (uint *)(param_1[0x1d] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar29 = *puVar1;
        goto LAB_fffffff00996a0f8;
      }
      uVar22 = (uVar29 & 0xaaaaaaaa) >> 1 | (uVar29 & 0x55555555) << 1;
      uVar22 = (uVar22 & 0xcccccccc) >> 2 | (uVar22 & 0x33333333) << 2;
      uVar22 = (uVar22 & 0xf0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f) << 4;
      uVar22 = (uVar22 & 0xff00ff00) >> 8 | (uVar22 & 0xff00ff) << 8;
      uVar22 = (uint)LZCOUNT(uVar22 >> 0x10 | uVar22 << 0x10);
      uVar28 = 1 << (ulong)(uVar22 & 0x1f);
      uVar29 = uVar29 & (uVar28 ^ 0xffffffff);
      uVar22 = uVar22 + (int)uVar31;
      uVar38 = (ulong)(uVar22 & (int)param_1[0x15] - 1U);
      lVar39 = param_1[0x10];
      lVar27 = uVar38 * 8;
      plVar18 = (long *)(lVar39 + (int)lVar27);
      if (lVar27 != (int)lVar27) {
        plVar18 = (long *)(lVar39 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
      }
      plVar18 = (long *)*plVar18;
    } while (plVar18 != plVar40);
    lVar27 = uVar38 * 4;
    piVar26 = (int *)(param_1[0x11] + (long)(int)lVar27);
    if (lVar27 - (int)lVar27 != 0) {
      piVar26 = (int *)(param_1[0x11] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
    }
    iVar30 = *piVar26;
    *piVar26 = iVar30 + -1;
    if (iVar30 + -1 == 0) {
      bVar9 = *(byte *)((long)param_1 + 0xd1);
      lVar24 = (**(code **)(*plVar18 + 0x108))();
      param_1[0x19] = param_1[0x19] - lVar24;
      lVar24 = uVar38 * 8;
      puVar3 = (undefined8 *)(lVar39 + (int)lVar24);
      if (lVar24 - (int)lVar24 != 0) {
        puVar3 = (undefined8 *)(lVar39 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      plVar18 = (long *)*puVar3;
      if ((bVar9 & 1) == 0) {
        (**(code **)(*plVar18 + 0x28))();
        *puVar3 = 0;
      }
      else {
        *puVar3 = 0;
        (**(code **)(*plVar18 + 0x28))();
      }
      lVar24 = param_1[0x12];
      puVar1 = (uint *)(lVar24 + iVar14);
      if (lVar32 - iVar14 != 0) {
        puVar1 = (uint *)(lVar24 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = *puVar1 & ~uVar28;
      uVar29 = *(uint *)(param_1 + 0x16) & uVar22 >> 6;
      *(ulong *)(param_1[0x13] + (ulong)uVar29 * 8) =
           *(ulong *)(param_1[0x13] + (ulong)uVar29 * 8) &
           (1L << ((ulong)uVar22 & 0x3f) ^ 0xffffffffffffffffU);
      *(int *)(param_1 + 0x17) = (int)param_1[0x17] + -1;
    }
    if ((uVar33 >> 1 & 1) != 0) {
      uVar41 = uVar41 >> ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
      lVar32 = (uVar41 & 0xffffffff) * 4;
      puVar1 = (uint *)(lVar24 + (int)lVar32);
      if (lVar32 != (int)lVar32) {
        puVar1 = (uint *)(lVar24 + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar29 = *puVar1;
      do {
        if (uVar29 == 0) goto LAB_fffffff00996a364;
        uVar22 = (uVar29 & 0xaaaaaaaa) >> 1 | (uVar29 & 0x55555555) << 1;
        uVar22 = (uVar22 & 0xcccccccc) >> 2 | (uVar22 & 0x33333333) << 2;
        uVar22 = (uVar22 & 0xf0f0f0f0) >> 4 | (uVar22 & 0xf0f0f0f) << 4;
        uVar22 = (uVar22 & 0xff00ff00) >> 8 | (uVar22 & 0xff00ff) << 8;
        uVar22 = (uint)LZCOUNT(uVar22 >> 0x10 | uVar22 << 0x10);
        uVar29 = uVar29 & (1 << (ulong)(uVar22 & 0x1f) ^ 0xffffffffU);
        uVar31 = (ulong)(uVar22 + (int)uVar41 & (int)param_1[0x15] - 1U);
        lVar24 = uVar31 * 8;
        plVar18 = (long *)(param_1[0x10] + (long)(int)lVar24);
        if (lVar24 != (int)lVar24) {
          plVar18 = (long *)(param_1[0x10] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
        }
      } while ((long *)*plVar18 != plVar40);
      lVar24 = uVar31 * 4;
      piVar26 = (int *)(param_1[0x11] + (long)(int)lVar24);
      if (lVar24 - (int)lVar24 != 0) {
        piVar26 = (int *)(param_1[0x11] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
      }
      if (*piVar26 == 0) {
LAB_fffffff00996a364:
        FUN_fffffff0099437a0(plVar40);
      }
    }
  }
LAB_fffffff00996a37c:
  uVar37 = 0xe00002bd;
  if ((uVar33 >> 1 & 1) == 0) goto LAB_fffffff009968fa4;
LAB_fffffff00996a3e8:
  *(int *)((long)param_1 + 0x24) = *(int *)((long)param_1 + 0x24) + -4;
LAB_fffffff009968fa4:
  FUN_fffffff009942d7c(param_1);
  return uVar37;
}

