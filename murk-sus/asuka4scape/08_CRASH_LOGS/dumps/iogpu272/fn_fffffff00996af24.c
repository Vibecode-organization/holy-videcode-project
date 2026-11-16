// FUN_fffffff00996af24 @ fffffff00996af24 size=3152

/* WARNING: Removing unreachable block (ram,0xfffffff00996b52c) */

long FUN_fffffff00996af24(long *param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  ulong *puVar2;
  int *piVar3;
  undefined8 *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  bool bVar13;
  int iVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  long *plVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  ulong uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  ulong uVar28;
  uint uVar29;
  int iVar30;
  long *plVar31;
  long lVar32;
  long lVar33;
  long lVar34;
  ulong uVar35;
  long lVar36;
  ulong uVar37;
  int iVar38;
  ulong uVar39;
  uint local_74;
  undefined8 local_68;
  
  if (DAT_fffffff00af227e8 != 0) {
    lVar32 = param_1[0x19];
    lVar34 = param_1[0x24];
    uVar15 = (**(code **)(*param_1 + 0xe0))(param_1);
    local_68 = 0;
    thunk_EXT_FUN_80110000032db760(uVar15,&local_68);
    uVar15 = local_68;
    uVar16 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
    thunk_EXT_FUN_80110000036da494(0x85180185,lVar34 + lVar32,uVar15,uVar16,0,0);
  }
  uVar21 = *(uint *)(param_1 + 0x22);
  if ((*(byte *)((long)param_1 + 0x24) >> 1 & 1) == 0) {
    if (uVar21 != 0) {
LAB_fffffff00996bb20:
      lVar32 = thunk_EXT_FUN_8011000003a49114
                         ("\"Non-resident group memory has %u pending memory objects\" @%s:%d");
      return lVar32;
    }
    if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
LAB_fffffff00996b744:
      lVar32 = 0xe00002bd;
      if (DAT_fffffff00af227e8 == 0) {
        return 0xe00002bd;
      }
      uVar15 = 0;
      goto LAB_fffffff00996bac4;
    }
    uVar25 = 0;
    uVar20 = 0;
    uVar37 = 0;
    uVar27 = *(uint *)(param_1 + 0x17);
    do {
      uVar39 = *(ulong *)(param_1[0x13] + uVar37 * 8);
      if (uVar39 != 0) {
LAB_fffffff00996affc:
        uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
        uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
        uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
        uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10;
        uVar35 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
        if (uVar27 <= uVar20) goto LAB_fffffff00996b044;
        lVar32 = (uVar35 | (uint)((int)uVar37 << 6)) * 8;
        puVar4 = (undefined8 *)(param_1[0x10] + (long)(int)lVar32);
        if (lVar32 - (int)lVar32 != 0) {
          puVar4 = (undefined8 *)(param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        iVar14 = FUN_fffffff0099436e4(*puVar4,param_2);
        if (iVar14 == 0) {
          uVar20 = uVar25 + 1;
          uVar25 = uVar20;
          goto LAB_fffffff00996b044;
        }
        if (uVar25 != 0) {
          if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
            uVar21 = 0;
          }
          else {
            uVar21 = 0;
            uVar20 = 0;
            uVar37 = 0;
            do {
              uVar39 = *(ulong *)(param_1[0x13] + uVar37 * 8);
              if (uVar39 != 0) {
                do {
                  uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
                  uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
                  uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
                  uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
                  uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10
                  ;
                  uVar35 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
                  if (uVar20 < uVar25) {
                    lVar32 = (uVar35 | (uint)((int)uVar37 << 6)) * 8;
                    puVar4 = (undefined8 *)(param_1[0x10] + (long)(int)lVar32);
                    if (lVar32 - (int)lVar32 != 0) {
                      puVar4 = (undefined8 *)
                               (param_1[0x10] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                    }
                    FUN_fffffff0099437a0(*puVar4);
                    uVar20 = uVar21 + 1;
                    uVar21 = uVar20;
                  }
                  uVar39 = uVar39 & (1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU);
                } while (uVar39 != 0);
              }
              uVar27 = (int)uVar37 + 1;
              uVar37 = (ulong)uVar27;
            } while (uVar27 <= *(uint *)(param_1 + 0x16));
          }
          if (uVar21 != uVar25) {
            FUN_fffffff009983d64();
LAB_fffffff00996bb44:
            FUN_fffffff009983d94();
            goto LAB_fffffff00996bb48;
          }
        }
        goto LAB_fffffff00996b744;
      }
LAB_fffffff00996b050:
      uVar23 = (int)uVar37 + 1;
      uVar37 = (ulong)uVar23;
    } while (uVar23 <= *(uint *)(param_1 + 0x16));
  }
  if (uVar21 != 0) {
    lVar32 = 0xe00002bd;
    if ((*(byte *)(param_1 + 0x25) & 1) == 0) {
      uVar15 = 0;
      goto LAB_fffffff00996babc;
    }
    uVar25 = 0;
    uVar20 = 0;
    uVar37 = 0;
    uVar27 = *(uint *)(param_1 + 0x22);
    do {
      uVar39 = *(ulong *)(param_1[0x1e] + uVar37 * 8);
      if (uVar39 != 0) {
        do {
          uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
          uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
          uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
          uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10;
          uVar35 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
          if (uVar20 < uVar27) {
            lVar32 = (uVar35 | (uint)((int)uVar37 << 6)) * 8;
            puVar4 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
            if (lVar32 - (int)lVar32 != 0) {
              puVar4 = (undefined8 *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000)
              ;
            }
            iVar14 = FUN_fffffff0099436e4(*puVar4,param_2);
            if (iVar14 != 0) {
              if ((uVar25 != 0) && ((*(byte *)(param_1 + 0x25) & 1) != 0)) {
                uVar20 = 0;
                uVar21 = 0;
                uVar37 = 0;
                do {
                  uVar39 = *(ulong *)(param_1[0x1e] + uVar37 * 8);
                  if (uVar39 != 0) {
                    do {
                      uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 |
                               (uVar39 & 0x5555555555555555) << 1;
                      uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 |
                               (uVar35 & 0x3333333333333333) << 2;
                      uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 |
                               (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
                      uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8
                      ;
                      uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 |
                               (uVar35 & 0xffff0000ffff) << 0x10;
                      uVar35 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
                      if (uVar21 < uVar25) {
                        lVar32 = (uVar35 | (uint)((int)uVar37 << 6)) * 8;
                        puVar4 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
                        if (lVar32 - (int)lVar32 != 0) {
                          puVar4 = (undefined8 *)
                                   (param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
                        }
                        FUN_fffffff0099437a0(*puVar4);
                        uVar21 = uVar20 + 1;
                        uVar20 = uVar21;
                      }
                      uVar39 = uVar39 & (1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU);
                    } while (uVar39 != 0);
                  }
                  uVar27 = (int)uVar37 + 1;
                  uVar37 = (ulong)uVar27;
                } while (uVar27 <= *(uint *)(param_1 + 0x21));
              }
              goto LAB_fffffff00996baa8;
            }
            uVar20 = uVar25 + 1;
            uVar25 = uVar20;
          }
          uVar39 = uVar39 & (1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU);
        } while (uVar39 != 0);
      }
      uVar23 = (int)uVar37 + 1;
      uVar37 = (ulong)uVar23;
      uVar26 = *(uint *)(param_1 + 0x21);
    } while (uVar23 <= uVar26);
    if (uVar21 != uVar25) {
LAB_fffffff00996bb48:
      lVar32 = thunk_EXT_FUN_8011000003a49114
                         ("\"Unexpected number of pending objects prepared: %d != %d\" @%s:%d");
      return lVar32;
    }
    if ((*(byte *)(param_1 + 0x25) & 1) == 0) goto LAB_fffffff00996ba9c;
    local_74 = 0;
    uVar20 = 0;
    uVar37 = 0;
    do {
      uVar39 = *(ulong *)(param_1[0x1e] + uVar37 * 8);
      if (uVar39 != 0) {
        do {
          uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
          uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
          uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
          uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10;
          uVar28 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
          uVar35 = uVar28 | (uint)((int)uVar37 << 6);
          lVar32 = uVar35 * 4;
          piVar3 = (int *)(param_1[0x1c] + (long)(int)lVar32);
          if (lVar32 - (int)lVar32 != 0) {
            piVar3 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
          }
          iVar14 = *piVar3;
          uVar27 = uVar20;
          if (iVar14 != 0) {
            iVar38 = 0;
            bVar13 = uVar20 == 0xffffffff;
            uVar27 = uVar20 + iVar14;
            lVar32 = uVar35 * 8;
            do {
              if (bVar13) goto LAB_fffffff00996b5d4;
              puVar4 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
              if (lVar32 != (int)lVar32) {
                puVar4 = (undefined8 *)
                         (param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
              }
              plVar31 = (long *)*puVar4;
              uVar35 = (ulong)((long)plVar31 * -0x61c8864680b583eb) >>
                       ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
              lVar34 = (uVar35 & 0xffffffff) * 4;
              puVar5 = (uint *)(param_1[0x12] + (long)(int)lVar34);
              if (lVar34 != (int)lVar34) {
                puVar5 = (uint *)(param_1[0x12] + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar25 = *puVar5;
              do {
                if (uVar25 == 0) goto LAB_fffffff00996b3d8;
                uVar23 = (uVar25 & 0xaaaaaaaa) >> 1 | (uVar25 & 0x55555555) << 1;
                uVar23 = (uVar23 & 0xcccccccc) >> 2 | (uVar23 & 0x33333333) << 2;
                uVar23 = (uVar23 & 0xf0f0f0f0) >> 4 | (uVar23 & 0xf0f0f0f) << 4;
                uVar23 = (uVar23 & 0xff00ff00) >> 8 | (uVar23 & 0xff00ff) << 8;
                uVar23 = (uint)LZCOUNT(uVar23 >> 0x10 | uVar23 << 0x10);
                uVar25 = uVar25 & (1 << (ulong)(uVar23 & 0x1f) ^ 0xffffffffU);
                uVar24 = (ulong)(uVar23 + (int)uVar35 & (int)param_1[0x15] - 1U);
                lVar34 = uVar24 * 8;
                plVar17 = (long *)(param_1[0x10] + (long)(int)lVar34);
                if (lVar34 != (int)lVar34) {
                  plVar17 = (long *)(param_1[0x10] + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
                }
              } while ((long *)*plVar17 != plVar31);
              lVar34 = uVar24 * 4;
              piVar3 = (int *)(param_1[0x11] + (long)(int)lVar34);
              if (lVar34 - (int)lVar34 != 0) {
                piVar3 = (int *)(param_1[0x11] + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *piVar3 = *piVar3 + 1;
              if (iVar38 == 0) goto LAB_fffffff00996bb44;
LAB_fffffff00996b590:
              uVar20 = uVar20 + 1;
              if (uVar20 == 0xffffffff) goto LAB_fffffff00996b5d4;
              bVar13 = false;
              iVar38 = iVar38 + 1;
            } while (iVar38 != iVar14);
          }
          uVar20 = uVar27;
          uVar39 = uVar39 & (1L << (uVar28 & 0x3f) ^ 0xffffffffffffffffU);
        } while (uVar39 != 0);
        uVar26 = *(uint *)(param_1 + 0x21);
      }
      uVar27 = (int)uVar37 + 1;
      uVar37 = (ulong)uVar27;
    } while (uVar27 <= uVar26);
LAB_fffffff00996b5d4:
    if (local_74 != uVar21) goto LAB_fffffff00996bb70;
    FUN_fffffff009968d64(param_1 + 0x1b);
  }
  if ((*(byte *)((long)param_1 + 0x34) & 1) == 0) {
    FUN_fffffff00997d900(*(long *)(param_1[2] + 0x160) + 0x1b8,param_1);
  }
  lVar32 = 0;
  uVar15 = 1;
LAB_fffffff00996babc:
  if (DAT_fffffff00af227e8 == 0) {
    return lVar32;
  }
LAB_fffffff00996bac4:
  lVar34 = param_1[0x19];
  lVar33 = param_1[0x24];
  uVar16 = thunk_EXT_FUN_801100000390ebc0(param_1[2]);
  thunk_EXT_FUN_80110000036da494(0x85180186,lVar33 + lVar34,uVar15,uVar16,0,0);
  return lVar32;
LAB_fffffff00996b044:
  uVar39 = uVar39 & (1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU);
  if (uVar39 == 0) goto LAB_fffffff00996b050;
  goto LAB_fffffff00996affc;
LAB_fffffff00996b3d8:
  uVar25 = 0;
  uVar10 = (int)param_1[0x15] - 1;
  uVar23 = *(uint *)(param_1 + 0x16);
  uVar35 = (ulong)((long)plVar31 * -0x61c8864680b583eb) >>
           ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
  uVar22 = (uint)uVar35;
  uVar26 = uVar22 >> 6;
  lVar34 = param_1[0x13];
  uVar24 = *(ulong *)(lVar34 + (ulong)uVar26 * 8) | -1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU;
  iVar30 = 0x40 - (uVar22 & 0x3f);
  iVar19 = uVar26 << 6;
  do {
    uVar26 = uVar26 + 1;
    if (uVar24 != 0xffffffffffffffff) {
      uVar24 = (~uVar24 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar24 & 0x5555555555555555) << 1;
      uVar24 = (uVar24 & 0xcccccccccccccccc) >> 2 | (uVar24 & 0x3333333333333333) << 2;
      uVar24 = (uVar24 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar24 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar24 = (uVar24 & 0xff00ff00ff00ff00) >> 8 | (uVar24 & 0xff00ff00ff00ff) << 8;
      uVar24 = (uVar24 & 0xffff0000ffff0000) >> 0x10 | (uVar24 & 0xffff0000ffff) << 0x10;
      uVar25 = (int)LZCOUNT(uVar24 >> 0x20 | uVar24 << 0x20) + iVar19;
      uVar24 = (ulong)uVar25;
      if (uVar25 - uVar22 < 0x80) goto LAB_fffffff00996b264;
      break;
    }
    lVar33 = (ulong)(uVar26 & uVar23) * 8;
    puVar2 = (ulong *)(lVar34 + (int)lVar33);
    if (lVar33 != (int)lVar33) {
      puVar2 = (ulong *)(lVar34 + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar25 = iVar30 + uVar25;
    uVar24 = *puVar2;
    iVar19 = iVar19 + 0x40;
    iVar30 = 0x40;
  } while (uVar25 < 0x80);
  goto LAB_fffffff00996b478;
  while( true ) {
    uVar26 = uVar25 - 0x1f;
    if (0x1e < uVar25) {
      lVar33 = param_1[0x12];
      uVar29 = 0xffffffe1;
      while( true ) {
        uVar26 = uVar25 + uVar29;
        lVar36 = (ulong)(uVar26 & uVar10) * 4;
        puVar5 = (uint *)(lVar33 + (int)lVar36);
        if (lVar36 != (int)lVar36) {
          puVar5 = (uint *)(lVar33 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
        }
        uVar6 = *puVar5;
        uVar9 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
        uVar9 = (uVar9 & 0xcccccccc) >> 2 | (uVar9 & 0x33333333) << 2;
        uVar9 = (uVar9 & 0xf0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f) << 4;
        uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
        uVar18 = (uint)LZCOUNT(uVar9 >> 0x10 | uVar9 << 0x10);
        uVar9 = uVar26 + uVar18;
        if (uVar6 != 0 && uVar9 < uVar25) break;
        uVar29 = uVar29 + 1;
        if (!CARRY4(uVar25,uVar29)) goto LAB_fffffff00996b478;
      }
      lVar36 = (ulong)(uVar26 & uVar10) * 4;
      puVar5 = (uint *)(lVar33 + (int)lVar36);
      if (lVar36 - (int)lVar36 != 0) {
        puVar5 = (uint *)(lVar33 + lVar36 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar11 = (ulong)(uVar9 & uVar10) * 8;
      lVar33 = param_1[0x10];
      lVar36 = param_1[0x11];
      iVar19 = (int)lVar11;
      puVar4 = (undefined8 *)(lVar33 + iVar19);
      if (lVar11 != iVar19) {
        puVar4 = (undefined8 *)(lVar33 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar15 = *puVar4;
      lVar12 = (ulong)(uVar9 & uVar10) * 4;
      puVar1 = (undefined4 *)(lVar36 + (int)lVar12);
      if (lVar12 != (int)lVar12) {
        puVar1 = (undefined4 *)(lVar36 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar7 = *puVar1;
      *puVar5 = uVar6 & (1 << (ulong)(uVar18 & 0x1f) ^ 0xffffffffU) | 1 << (ulong)(-uVar29 & 0x1f);
      uVar29 = uVar23 & uVar25 >> 6;
      *(ulong *)(lVar34 + (ulong)uVar29 * 8) =
           *(ulong *)(lVar34 + (ulong)uVar29 * 8) | 1L << (uVar24 & 0x3f);
      lVar34 = (ulong)(uVar25 & uVar10) * 8;
      puVar4 = (undefined8 *)(lVar33 + (int)lVar34);
      if (lVar34 != (int)lVar34) {
        puVar4 = (undefined8 *)(lVar33 + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = uVar15;
      lVar34 = (ulong)(uVar25 & uVar10) * 4;
      puVar1 = (undefined4 *)(lVar36 + (int)lVar34);
      if (lVar34 != (int)lVar34) {
        puVar1 = (undefined4 *)(lVar36 + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = uVar7;
      puVar4 = (undefined8 *)(param_1[0x10] + (long)iVar19);
      if (lVar11 != iVar19) {
        puVar4 = (undefined8 *)(param_1[0x10] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = 0;
      lVar34 = param_1[0x13];
      uVar29 = uVar23 & uVar9 >> 6;
      *(ulong *)(lVar34 + (ulong)uVar29 * 8) =
           *(ulong *)(lVar34 + (ulong)uVar29 * 8) &
           (1L << ((ulong)uVar9 & 0x3f) ^ 0xffffffffffffffffU);
      uVar24 = (ulong)uVar9;
    }
    if (uVar26 == uVar25) break;
LAB_fffffff00996b264:
    uVar25 = (uint)uVar24;
    if (uVar25 - uVar22 < 0x20) {
      lVar33 = (ulong)(uVar25 & uVar10) * 8;
      lVar34 = param_1[0x11];
      puVar4 = (undefined8 *)(param_1[0x10] + (long)(int)lVar33);
      if (lVar33 != (int)lVar33) {
        puVar4 = (undefined8 *)(param_1[0x10] + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar4 = plVar31;
      lVar33 = (ulong)(uVar25 & uVar10) * 4;
      puVar1 = (undefined4 *)(lVar34 + (int)lVar33);
      if (lVar33 != (int)lVar33) {
        puVar1 = (undefined4 *)(lVar34 + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 1;
      lVar33 = (uVar35 & 0xffffffff) * 4;
      lVar34 = param_1[0x13];
      puVar5 = (uint *)(param_1[0x12] + (long)(int)lVar33);
      if (lVar33 != (int)lVar33) {
        puVar5 = (uint *)(param_1[0x12] + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar5 = *puVar5 | 1 << (ulong)(uVar25 - uVar22 & 0x1f);
      uVar23 = uVar23 & uVar25 >> 6;
      *(ulong *)(lVar34 + (ulong)uVar23 * 8) =
           *(ulong *)(lVar34 + (ulong)uVar23 * 8) | 1L << (uVar24 & 0x3f);
      lVar34 = (**(code **)(*plVar31 + 0x108))(*plVar31 + 0x108,plVar31);
      param_1[0x19] = param_1[0x19] + lVar34;
      *(int *)(param_1 + 0x17) = (int)param_1[0x17] + 1;
      (**(code **)(*plVar31 + 0x20))(plVar31);
      if (iVar38 != 0) goto LAB_fffffff00996bb44;
      local_74 = local_74 + 1;
      goto LAB_fffffff00996b590;
    }
  }
LAB_fffffff00996b478:
  uVar35 = FUN_fffffff00996a418(param_1 + 0x10,0);
  if ((uVar35 & 1) == 0) {
    bVar8 = *(byte *)(param_1 + 0x25);
    if (uVar20 == 0) goto LAB_fffffff00996ba18;
    uVar27 = 0;
    if ((bVar8 & 1) == 0) goto LAB_fffffff00996ba0c;
    uVar23 = 0;
    uVar25 = 0;
    uVar37 = 0;
    goto LAB_fffffff00996b788;
  }
  goto LAB_fffffff00996b3d8;
LAB_fffffff00996b788:
  do {
    uVar39 = *(ulong *)(param_1[0x1e] + uVar37 * 8);
    if (uVar39 != 0) {
      do {
        uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
        uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
        uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
        uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10;
        uVar28 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
        uVar35 = uVar28 | (uint)((int)uVar37 << 6);
        lVar32 = uVar35 * 4;
        piVar3 = (int *)(param_1[0x1c] + (long)(int)lVar32);
        if (lVar32 - (int)lVar32 != 0) {
          piVar3 = (int *)(param_1[0x1c] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
        }
        iVar14 = *piVar3;
        if (iVar14 != 0) {
          iVar38 = 0;
          lVar32 = uVar35 * 8;
          do {
            bVar13 = uVar25 < uVar20;
            uVar25 = uVar23;
            if (bVar13) {
              plVar31 = (long *)(param_1[0x1b] + (long)(int)lVar32);
              if (lVar32 != (int)lVar32) {
                plVar31 = (long *)(param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar35 = (ulong)(*plVar31 * -0x61c8864680b583eb) >>
                       ((ulong)(uint)-*(int *)((long)param_1 + 0xb4) & 0x3f);
              lVar34 = (uVar35 & 0xffffffff) * 4;
              iVar19 = (int)lVar34;
              puVar5 = (uint *)(param_1[0x12] + (long)iVar19);
              if (lVar34 - iVar19 != 0) {
                puVar5 = (uint *)(param_1[0x12] + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar25 = *puVar5;
              do {
                if (uVar25 == 0) {
                  FUN_fffffff009983dc4();
                  goto LAB_fffffff00996bb20;
                }
                uVar23 = (uVar25 & 0xaaaaaaaa) >> 1 | (uVar25 & 0x55555555) << 1;
                uVar23 = (uVar23 & 0xcccccccc) >> 2 | (uVar23 & 0x33333333) << 2;
                uVar23 = (uVar23 & 0xf0f0f0f0) >> 4 | (uVar23 & 0xf0f0f0f) << 4;
                uVar23 = (uVar23 & 0xff00ff00) >> 8 | (uVar23 & 0xff00ff) << 8;
                uVar23 = (uint)LZCOUNT(uVar23 >> 0x10 | uVar23 << 0x10);
                uVar26 = 1 << (ulong)(uVar23 & 0x1f);
                uVar25 = uVar25 & (uVar26 ^ 0xffffffff);
                uVar23 = uVar23 + (int)uVar35;
                uVar24 = (ulong)(uVar23 & (int)param_1[0x15] - 1U);
                lVar36 = param_1[0x10];
                lVar33 = uVar24 * 8;
                plVar17 = (long *)(lVar36 + (int)lVar33);
                if (lVar33 != (int)lVar33) {
                  plVar17 = (long *)(lVar36 + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
                }
                plVar17 = (long *)*plVar17;
              } while (plVar17 != (long *)*plVar31);
              lVar33 = uVar24 * 4;
              piVar3 = (int *)(param_1[0x11] + (long)(int)lVar33);
              if (lVar33 - (int)lVar33 != 0) {
                piVar3 = (int *)(param_1[0x11] + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
              }
              iVar30 = *piVar3;
              *piVar3 = iVar30 + -1;
              if (iVar30 + -1 == 0) {
                bVar8 = *(byte *)((long)param_1 + 0xd1);
                lVar33 = (**(code **)(*plVar17 + 0x108))();
                param_1[0x19] = param_1[0x19] - lVar33;
                lVar33 = uVar24 * 8;
                puVar4 = (undefined8 *)(lVar36 + (int)lVar33);
                if (lVar33 - (int)lVar33 != 0) {
                  puVar4 = (undefined8 *)(lVar36 + lVar33 & 0xffffffffffffU | 0x2bad000000000000);
                }
                plVar31 = (long *)*puVar4;
                if ((bVar8 & 1) == 0) {
                  (**(code **)(*plVar31 + 0x28))();
                  *puVar4 = 0;
                }
                else {
                  *puVar4 = 0;
                  (**(code **)(*plVar31 + 0x28))();
                }
                lVar33 = param_1[0x13];
                puVar5 = (uint *)(param_1[0x12] + (long)iVar19);
                if (lVar34 - iVar19 != 0) {
                  puVar5 = (uint *)(param_1[0x12] + lVar34 & 0xffffffffffffU | 0x2bad000000000000);
                }
                *puVar5 = *puVar5 & ~uVar26;
                uVar25 = *(uint *)(param_1 + 0x16) & uVar23 >> 6;
                *(ulong *)(lVar33 + (ulong)uVar25 * 8) =
                     *(ulong *)(lVar33 + (ulong)uVar25 * 8) &
                     (1L << ((ulong)uVar23 & 0x3f) ^ 0xffffffffffffffffU);
                *(int *)(param_1 + 0x17) = (int)param_1[0x17] + -1;
              }
              uVar25 = uVar27 + 1;
              uVar27 = uVar25;
            }
            if (uVar20 <= uVar25) goto LAB_fffffff00996ba0c;
            iVar38 = iVar38 + 1;
            uVar23 = uVar25;
          } while (iVar38 != iVar14);
        }
        uVar39 = uVar39 & (1L << (uVar28 & 0x3f) ^ 0xffffffffffffffffU);
      } while (uVar39 != 0);
    }
    uVar26 = (int)uVar37 + 1;
    uVar37 = (ulong)uVar26;
  } while (uVar26 <= *(uint *)(param_1 + 0x21));
LAB_fffffff00996ba0c:
  if (uVar20 == uVar27) {
    bVar8 = *(byte *)(param_1 + 0x25);
LAB_fffffff00996ba18:
    if ((bVar8 & 1) == 0) {
LAB_fffffff00996ba9c:
      uVar20 = 0;
    }
    else {
      uVar20 = 0;
      uVar27 = 0;
      uVar37 = 0;
      do {
        uVar39 = *(ulong *)(param_1[0x1e] + uVar37 * 8);
        if (uVar39 != 0) {
          do {
            uVar35 = (uVar39 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar39 & 0x5555555555555555) << 1;
            uVar35 = (uVar35 & 0xcccccccccccccccc) >> 2 | (uVar35 & 0x3333333333333333) << 2;
            uVar35 = (uVar35 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar35 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar35 = (uVar35 & 0xff00ff00ff00ff00) >> 8 | (uVar35 & 0xff00ff00ff00ff) << 8;
            uVar35 = (uVar35 & 0xffff0000ffff0000) >> 0x10 | (uVar35 & 0xffff0000ffff) << 0x10;
            uVar35 = LZCOUNT(uVar35 >> 0x20 | uVar35 << 0x20);
            if (uVar27 < uVar21) {
              lVar32 = (uVar35 | (uint)((int)uVar37 << 6)) * 8;
              puVar4 = (undefined8 *)(param_1[0x1b] + (long)(int)lVar32);
              if (lVar32 - (int)lVar32 != 0) {
                puVar4 = (undefined8 *)
                         (param_1[0x1b] + lVar32 & 0xffffffffffffU | 0x2bad000000000000);
              }
              FUN_fffffff0099437a0(*puVar4);
              uVar27 = uVar20 + 1;
              uVar20 = uVar27;
            }
            uVar39 = uVar39 & (1L << (uVar35 & 0x3f) ^ 0xffffffffffffffffU);
          } while (uVar39 != 0);
        }
        uVar25 = (int)uVar37 + 1;
        uVar37 = (ulong)uVar25;
      } while (uVar25 <= *(uint *)(param_1 + 0x21));
    }
    if (uVar20 == uVar21) {
LAB_fffffff00996baa8:
      uVar15 = 0;
      lVar32 = 0xe00002bd;
      goto LAB_fffffff00996babc;
    }
    FUN_fffffff009983e24();
  }
  FUN_fffffff009983df4();
LAB_fffffff00996bb70:
  lVar32 = FUN_fffffff009983e54();
  return *(long *)(lVar32 + 0x120) + *(long *)(lVar32 + 200);
}

