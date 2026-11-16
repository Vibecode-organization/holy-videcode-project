// FUN_fffffff008e9a684 @ fffffff008e9a684 size=3096
// CALLERS:
//   fffffff00afb845e no-fn
//   fffffff008e9a4d4 FUN_fffffff008e9a458@fffffff008e9a458
// CALLEES:
//   fffffff008eb93f0 thunk_EXT_FUN_8011000002c24af0
//   fffffff008eb9420 thunk_EXT_FUN_8011000002c24de8
//   fffffff008eb93e0 thunk_EXT_FUN_8011000002c1eb48
//   fffffff008eb9330 thunk_EXT_FUN_8011000002c1e5b4
//   fffffff008eb9350 thunk_EXT_FUN_8011000002c1e3bc
//   fffffff008eb9360 thunk_EXT_FUN_8011000002c1e680
//   fffffff008eb88a0 thunk_EXT_FUN_80110000038fe9a0
//   fffffff008eb9400 thunk_EXT_FUN_8011000002c1ea7c
//   fffffff008eb9370 thunk_EXT_FUN_8011000002c1e350
//   fffffff008eb93a0 thunk_EXT_FUN_8011000002c1e9b0
//   fffffff008eb9430 thunk_EXT_FUN_8011000002c25568
//   fffffff008eb93d0 thunk_EXT_FUN_8011000002c24c68
//   fffffff008e98eac FUN_fffffff008e98eac
//   fffffff008eb93b0 thunk_EXT_FUN_8011000002c24ba8
//   fffffff008eb9450 thunk_EXT_FUN_8011000002c25028
//   fffffff008e9b680 FUN_fffffff008e9b680
//   fffffff008eb9390 thunk_EXT_FUN_8011000002c1e4e8
//   fffffff008eb9440 thunk_EXT_FUN_8011000002c251a8
//   fffffff008eb9410 thunk_EXT_FUN_8011000002c254a8
//   fffffff008eb9380 thunk_EXT_FUN_8011000002c1e74c
//   fffffff008eb9460 thunk_EXT_FUN_8011000002c25268

undefined8
FUN_fffffff008e9a684(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  undefined8 uVar13;
  uint *puVar14;
  long lVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  long lVar19;
  uint uVar20;
  undefined *puVar21;
  ulong uVar22;
  
  iVar3 = thunk_EXT_FUN_8011000002c1e3bc();
  if (iVar3 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = thunk_EXT_FUN_8011000002c1e3bc(param_1);
    if (uVar4 == 0) {
      return 1;
    }
  }
  uVar22 = 0;
  do {
    iVar3 = thunk_EXT_FUN_8011000002c1eb48(param_1,uVar22);
    if (iVar3 < 2) {
      if (iVar3 != 0) {
        if (iVar3 != 1) {
          return 0;
        }
        if ((param_1 == 0) || (iVar3 = thunk_EXT_FUN_8011000002c254a8(param_1,uVar22), iVar3 != 1))
        {
          thunk_EXT_FUN_80110000038fe9a0("HTPC Compressed surface not okay!\n");
          return 0;
        }
        iVar3 = thunk_EXT_FUN_8011000002c1ea7c(param_1,uVar22);
        piVar12 = (int *)thunk_EXT_FUN_8011000002c24af0(param_1,uVar22);
        if (piVar12 == (int *)0x0) {
          return 0;
        }
        *(int *)(param_6 + uVar22 * 4) = piVar12[7];
        *(int *)(param_2 + uVar22 * 4) = piVar12[3];
        *(int *)(param_4 + uVar22 * 4) = piVar12[2];
        *(int *)(param_3 + uVar22 * 4) =
             piVar12[3] + *piVar12 * iVar3 * piVar12[1] * piVar12[5] * piVar12[6] + -1;
        iVar3 = piVar12[2] +
                ((uint)piVar12[6] >> (ulong)(*(byte *)((long)piVar12 + 0x22) & 0x1f)) * piVar12[7] +
                -1;
LAB_fffffff008e9abb4:
        *(int *)(param_5 + uVar22 * 4) = iVar3;
        goto LAB_fffffff008e9b254;
      }
LAB_fffffff008e9b214:
      iVar3 = thunk_EXT_FUN_8011000002c1e4e8(param_1,uVar22);
      *(int *)(param_2 + uVar22 * 4) = iVar3;
      iVar7 = thunk_EXT_FUN_8011000002c1e5b4(param_1,uVar22);
      *(int *)(param_3 + uVar22 * 4) = iVar7 + iVar3;
      *(undefined4 *)(param_4 + uVar22 * 4) = 0;
      *(undefined4 *)(param_5 + uVar22 * 4) = 0;
      uVar10 = thunk_EXT_FUN_8011000002c1e9b0(param_1,uVar22);
      *(undefined4 *)(param_6 + uVar22 * 4) = uVar10;
    }
    else {
      if (1 < iVar3 - 2U) {
        if (iVar3 != 5) {
          return 0;
        }
        uVar13 = FUN_fffffff008e9b680(param_1,uVar22);
        if ((int)uVar13 == 0) {
          return uVar13;
        }
        if (param_1 == 0) {
          bVar2 = false;
        }
        else {
          iVar3 = thunk_EXT_FUN_8011000002c254a8(param_1,uVar22);
          bVar2 = iVar3 - 3U < 2;
        }
        thunk_EXT_FUN_8011000002c24ba8(param_1,uVar22);
        thunk_EXT_FUN_8011000002c24c68(param_1,uVar22);
        uVar10 = thunk_EXT_FUN_8011000002c25028(param_1,uVar22);
        *(undefined4 *)(param_6 + uVar22 * 4) = uVar10;
        iVar3 = thunk_EXT_FUN_8011000002c1e680(param_1,uVar22);
        iVar7 = thunk_EXT_FUN_8011000002c1e74c(param_1,uVar22);
        uVar6 = thunk_EXT_FUN_8011000002c24ba8(param_1,uVar22);
        uVar11 = thunk_EXT_FUN_8011000002c24c68(param_1,uVar22);
        thunk_EXT_FUN_8011000002c1e350(param_1);
        puVar14 = (uint *)FUN_fffffff008e98eac();
        uVar5 = *puVar14;
        if ((int)uVar5 < 0x73347630) {
          if ((int)uVar5 < 0x62336138) {
            if (0x34323075 < (int)uVar5) {
              if ((int)uVar5 < 0x34343466) {
                if ((uVar5 != 0x34323076) && (uVar5 != 0x34323266)) {
                  uVar18 = 0x3276;
                  goto LAB_fffffff008e9afec;
                }
              }
              else {
                if (0x42475240 < (int)uVar5) {
                  if (uVar5 != 0x42475241) {
                    lVar19 = 0x1b;
                    if (uVar5 != 0x52476841) goto LAB_fffffff008e9b0a8;
                    goto LAB_fffffff008e9b078;
                  }
                  goto LAB_fffffff008e9b098;
                }
                if (uVar5 != 0x34343466) {
                  uVar18 = 0x34343476;
                  goto LAB_fffffff008e9aff0;
                }
              }
LAB_fffffff008e9aff8:
              lVar19 = 8;
              if (uVar22 != 1) {
                lVar19 = 0x1b;
              }
              if (uVar22 == 0) {
                lVar19 = 1;
              }
              goto LAB_fffffff008e9b0a8;
            }
            if ((int)uVar5 < 0x26663338) {
              if (uVar5 == 0x26424741) {
LAB_fffffff008e9b098:
                lVar15 = 0x1b;
                lVar19 = 0x15;
                goto LAB_fffffff008e9b0a4;
              }
              if (uVar5 == 0x26526841) {
LAB_fffffff008e9b078:
                lVar15 = 0x1b;
                lVar19 = 0x18;
                goto LAB_fffffff008e9b0a4;
              }
              lVar19 = 0x1b;
              if (uVar5 != 0x26623338) goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9af0c;
            }
            if (0x26773460 < (int)uVar5) {
              if (uVar5 == 0x26773461) goto LAB_fffffff008e9b088;
              uVar18 = 0x3066;
LAB_fffffff008e9afec:
              uVar18 = uVar18 | 0x34320000;
LAB_fffffff008e9aff0:
              lVar19 = 0x1b;
              if (uVar5 != uVar18) goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9aff8;
            }
            if (uVar5 == 0x26663338) goto LAB_fffffff008e9af0c;
            uVar18 = 0x26773372;
LAB_fffffff008e9af9c:
            lVar19 = 0x1b;
            if (uVar5 != uVar18) goto LAB_fffffff008e9b0a8;
            lVar15 = 0x1b;
          }
          else {
            if (0x70343433 < (int)uVar5) {
              if ((int)uVar5 < 0x70663434) {
                if ((uVar5 != 0x70343434) && (uVar5 != 0x70663230)) {
                  uVar18 = 0x3232;
                  goto LAB_fffffff008e9af78;
                }
              }
              else {
                if ((uVar5 + 0x8ccb99d0 < 5) &&
                   ((1 << (ulong)(uVar5 + 0x8ccb99d0 & 0x1f) & 0x15U) != 0)) {
LAB_fffffff008e9ad38:
                  lVar15 = 0x11;
                  if (uVar22 != 1) {
                    lVar15 = 0x1b;
                  }
                  lVar19 = 7;
                  goto LAB_fffffff008e9b0a4;
                }
                uVar18 = 0x3434;
LAB_fffffff008e9af78:
                uVar18 = uVar18 | 0x70660000;
LAB_fffffff008e9b030:
                lVar19 = 0x1b;
                if (uVar5 != uVar18) goto LAB_fffffff008e9b0a8;
              }
LAB_fffffff008e9b038:
              lVar15 = 10;
              if (uVar22 != 1) {
                lVar15 = 0x1b;
              }
              lVar19 = 3;
              goto LAB_fffffff008e9b0a4;
            }
            if ((int)uVar5 < 0x66336138) {
              if (uVar5 != 0x62336138) {
                if (uVar5 == 0x66306138) goto LAB_fffffff008e9afb4;
                uVar18 = 0x66326138;
LAB_fffffff008e9af00:
                lVar19 = 0x1b;
                if (uVar5 == uVar18) goto LAB_fffffff008e9afb4;
                goto LAB_fffffff008e9b0a8;
              }
            }
            else {
              if (0x7034322f < (int)uVar5) {
                if (uVar5 == 0x70343230) goto LAB_fffffff008e9b038;
                uVar18 = 0x70343232;
                goto LAB_fffffff008e9b030;
              }
              if (uVar5 != 0x66336138) {
                uVar18 = 0x66346138;
                goto LAB_fffffff008e9af00;
              }
            }
LAB_fffffff008e9af0c:
            lVar15 = 0;
            if (uVar22 != 1) {
              lVar15 = 0x1b;
            }
          }
          lVar19 = 0x13;
LAB_fffffff008e9b0a4:
          if (uVar22 != 0) {
            lVar19 = lVar15;
          }
        }
        else {
          if (0x77343060 < (int)uVar5) {
            if ((int)uVar5 < 0x78663434) {
              if (0x78343433 < (int)uVar5) {
                if ((uVar5 != 0x78343434) && (uVar5 != 0x78663230)) {
                  uVar18 = 0x3232;
                  goto LAB_fffffff008e9ae70;
                }
                goto LAB_fffffff008e9ae7c;
              }
              if (uVar5 != 0x77343061) {
                if (uVar5 == 0x78343230) goto LAB_fffffff008e9ae7c;
                uVar18 = 0x78343232;
                goto LAB_fffffff008e9ae74;
              }
LAB_fffffff008e9b088:
              lVar15 = 0x1b;
              lVar19 = 0x19;
            }
            else if (((uVar5 + 0x868f99d0 < 5) &&
                     ((1 << (ulong)(uVar5 + 0x868f99d0 & 0x1f) & 0x15U) != 0)) ||
                    ((uVar5 + 0x868f89d0 < 5 &&
                     ((1 << (ulong)(uVar5 + 0x868f89d0 & 0x1f) & 0x15U) != 0)))) {
              lVar15 = 0xc;
              if (uVar22 != 1) {
                lVar15 = 0x1b;
              }
              lVar19 = 5;
            }
            else {
              uVar18 = 0x3434;
LAB_fffffff008e9ae70:
              uVar18 = uVar18 | 0x78660000;
LAB_fffffff008e9ae74:
              lVar19 = 0x1b;
              if (uVar5 != uVar18) goto LAB_fffffff008e9b0a8;
LAB_fffffff008e9ae7c:
              lVar15 = 9;
              if (uVar22 != 1) {
                lVar15 = 0x1b;
              }
              lVar19 = 2;
            }
            goto LAB_fffffff008e9b0a4;
          }
          if ((int)uVar5 < 0x74763230) {
            if (0x7466322f < (int)uVar5) {
              if ((uVar5 != 0x74663230) && (uVar5 != 0x74663232)) {
                uVar18 = 0x74663434;
                goto LAB_fffffff008e9ae24;
              }
              goto LAB_fffffff008e9ae2c;
            }
            if (uVar5 + 0x8ccb89d0 < 5) {
              lVar19 = 0x1b;
              if ((1 << (ulong)(uVar5 + 0x8ccb89d0 & 0x1f) & 0x15U) == 0) goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9ad38;
            }
          }
          else {
            if ((int)uVar5 < 0x76306138) {
              if ((uVar5 != 0x74763230) && (uVar5 != 0x74763232)) {
                uVar18 = 0x74763434;
LAB_fffffff008e9ae24:
                lVar19 = 0x1b;
                if (uVar5 != uVar18) goto LAB_fffffff008e9b0a8;
              }
LAB_fffffff008e9ae2c:
              lVar15 = 0xb;
              if (uVar22 != 1) {
                lVar15 = 0x1b;
              }
              lVar19 = 4;
              goto LAB_fffffff008e9b0a4;
            }
            if ((int)uVar5 < 0x76346138) {
              if (uVar5 != 0x76306138) {
                uVar18 = 0x76326138;
                goto LAB_fffffff008e9af00;
              }
            }
            else if (uVar5 != 0x76346138) {
              uVar18 = 0x77333072;
              goto LAB_fffffff008e9af9c;
            }
LAB_fffffff008e9afb4:
            if (uVar22 < 3) {
              lVar19 = (&DAT_fffffff007634100)[uVar22];
              goto LAB_fffffff008e9b0a8;
            }
          }
          lVar19 = 0x1b;
        }
LAB_fffffff008e9b0a8:
        iVar8 = thunk_EXT_FUN_8011000002c254a8(param_1,uVar22);
        if (iVar8 == 4) {
          uVar16 = thunk_EXT_FUN_8011000002c25568(param_1,uVar22);
          uVar16 = uVar16 & 0xffffffff;
        }
        else {
          uVar16 = 0;
        }
        puVar21 = &UNK_fffffff007633bc0 + lVar19 * 0x30;
        if ((((ulong)puVar21 ^ 0xfffffff007633bc0) & 0xffc0000000000000) != 0) {
          puVar21 = (undefined *)((ulong)puVar21 & 0xffffffffffff | 0xc8a2000000000000);
        }
        iVar8 = *(int *)(puVar21 + uVar16 * 4 + 0x10);
        uVar5 = 0;
        if ((uVar6 & 0xff) != 0) {
          uVar5 = ((iVar3 + (uVar6 & 0xff)) - 1) / (uVar6 & 0xff);
        }
        uVar6 = 0;
        if ((uVar11 & 0xff) != 0) {
          uVar6 = ((iVar7 + (uVar11 & 0xff)) - 1) / (uVar11 & 0xff);
        }
        iVar3 = thunk_EXT_FUN_8011000002c251a8(param_1,uVar22);
        *(int *)(param_2 + uVar22 * 4) = iVar3;
        *(uint *)(param_3 + uVar22 * 4) = iVar3 + uVar5 * iVar8 * uVar6 + -1;
        *(undefined4 *)(param_4 + uVar22 * 4) = 0;
        *(undefined4 *)(param_5 + uVar22 * 4) = 0;
        if (bVar2) {
          uVar6 = thunk_EXT_FUN_8011000002c24ba8(param_1,uVar22);
          uVar11 = thunk_EXT_FUN_8011000002c24c68(param_1,uVar22);
          iVar3 = thunk_EXT_FUN_8011000002c1e680(param_1,uVar22);
          iVar7 = thunk_EXT_FUN_8011000002c1e74c(param_1,uVar22);
          uVar5 = 0;
          if ((uVar6 & 0xff) != 0) {
            uVar5 = ((iVar3 + (uVar6 & 0xff)) - 1) / (uVar6 & 0xff);
          }
          uVar6 = 0;
          if ((uVar11 & 0xff) != 0) {
            uVar6 = ((iVar7 + (uVar11 & 0xff)) - 1) / (uVar11 & 0xff);
          }
          uVar11 = thunk_EXT_FUN_8011000002c24de8(param_1,uVar22);
          iVar3 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar5) & 0x1f) < uVar5) {
            iVar3 = 0;
          }
          iVar7 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar6) & 0x1f) < uVar6) {
            iVar7 = 0;
          }
          iVar8 = thunk_EXT_FUN_8011000002c25268(param_1,uVar22);
          *(int *)(param_4 + uVar22 * 4) = iVar8;
          *(uint *)(param_5 + uVar22 * 4) =
               iVar8 + ((1 << (ulong)(iVar3 - (uint)LZCOUNT(uVar5) & 0x1f)) <<
                       (ulong)(iVar7 - (uint)LZCOUNT(uVar6) & 0x1f)) * (uVar11 & 0xffff) + -1;
        }
        goto LAB_fffffff008e9b214;
      }
      uVar5 = thunk_EXT_FUN_8011000002c1eb48(param_1,uVar22);
      if ((uVar5 & 0xfe) != 2) {
        return 0;
      }
      uVar5 = thunk_EXT_FUN_8011000002c1e74c(param_1,uVar22);
      iVar3 = thunk_EXT_FUN_8011000002c1e680(param_1,uVar22);
      uVar6 = thunk_EXT_FUN_8011000002c1ea7c(param_1,uVar22);
      iVar7 = thunk_EXT_FUN_8011000002c1e9b0(param_1,uVar22);
      iVar8 = thunk_EXT_FUN_8011000002c1eb48(param_1,uVar22);
      *(int *)(param_6 + uVar22 * 4) = iVar7;
      if ((param_1 == 0) || (iVar9 = thunk_EXT_FUN_8011000002c254a8(param_1,uVar22), iVar9 != 2)) {
        if (iVar8 == 3) {
          uVar5 = 0;
          if (uVar6 != 0) {
            uVar5 = 0x4000 / uVar6;
          }
          iVar3 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar5) & 0x1f) < uVar5) {
            iVar3 = 0x20;
          }
          *(int *)(param_6 + uVar22 * 4) =
               iVar7 << (ulong)((iVar3 - (uint)LZCOUNT(uVar5)) + 1 >> 1 & 0x1f);
        }
        iVar7 = -1;
        iVar3 = -1;
      }
      else {
        if ((int)uVar6 < 8) {
          if (1 < uVar6 - 1) {
            uVar17 = 0xaaaaaaaa;
            uVar20 = 0xaaaaaaaa;
            if (uVar6 != 4) goto LAB_fffffff008e9aa78;
          }
          uVar17 = 0x10;
          uVar20 = 0x10;
        }
        else {
          uVar11 = 0xaaaaaaaa;
          uVar17 = 8;
          uVar18 = uVar11;
          if (uVar6 == 8) {
            uVar11 = 0x10;
            uVar18 = uVar17;
          }
          uVar20 = uVar17;
          if (uVar6 != 0x10) {
            uVar17 = uVar18;
            uVar20 = uVar11;
          }
        }
LAB_fffffff008e9aa78:
        uVar11 = 0;
        if (uVar17 != 0) {
          uVar11 = ((iVar3 + uVar17) - 1) / uVar17;
        }
        iVar9 = 0x1f;
        if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar11) & 0x1f) < uVar11) {
          iVar9 = 0;
        }
        uVar18 = 0;
        if (uVar20 != 0) {
          uVar18 = ((uVar5 + uVar20) - 1) / uVar20;
        }
        iVar3 = 0x1f;
        iVar1 = iVar3;
        if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar18) & 0x1f) < uVar18) {
          iVar1 = 0;
        }
        if (iVar8 == 3) {
          uVar17 = 0;
          if (uVar6 != 0) {
            uVar17 = 0x4000 / uVar6;
          }
          iVar3 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar17) & 0x1f) < uVar17) {
            iVar3 = 0x20;
          }
          uVar6 = (iVar3 - (uint)LZCOUNT(uVar17)) + 1 >> 1;
          iVar3 = 1 << (ulong)(uVar6 & 0x1f);
          uVar5 = (iVar3 + uVar5) - 1 & -iVar3;
          *(int *)(param_6 + uVar22 * 4) = iVar7 << (ulong)(uVar6 & 0x1f);
        }
        else {
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar5) & 0x1f) < uVar5) {
            iVar3 = 0;
          }
          uVar5 = 1 << (ulong)(iVar3 - (uint)LZCOUNT(uVar5) & 0x1f);
        }
        iVar3 = uVar5 * iVar7 + -1;
        iVar7 = ((2 << (ulong)(iVar9 - (uint)LZCOUNT(uVar11) & 0x1f)) <<
                (ulong)(iVar1 - (uint)LZCOUNT(uVar18) & 0x1f)) + -1;
      }
      iVar8 = thunk_EXT_FUN_8011000002c1e4e8(param_1,uVar22);
      *(int *)(param_2 + uVar22 * 4) = iVar8;
      iVar9 = thunk_EXT_FUN_8011000002c1e5b4(param_1,uVar22);
      *(int *)(param_3 + uVar22 * 4) = iVar9 + iVar8;
      *(undefined4 *)(param_4 + uVar22 * 4) = 0;
      *(undefined4 *)(param_5 + uVar22 * 4) = 0;
      if ((param_1 != 0) && (iVar8 = thunk_EXT_FUN_8011000002c254a8(param_1,uVar22), iVar8 != 0)) {
        lVar15 = thunk_EXT_FUN_8011000002c24af0(param_1,uVar22);
        if (lVar15 == 0) {
          return 0;
        }
        iVar8 = *(int *)(lVar15 + 0xc);
        *(int *)(param_2 + uVar22 * 4) = iVar8;
        *(int *)(param_3 + uVar22 * 4) = iVar8 + iVar3;
        iVar3 = *(int *)(lVar15 + 8);
        *(int *)(param_4 + uVar22 * 4) = iVar3;
        iVar3 = iVar3 + iVar7;
        goto LAB_fffffff008e9abb4;
      }
    }
LAB_fffffff008e9b254:
    uVar22 = uVar22 + 1;
    if (uVar4 == uVar22) {
      return 1;
    }
  } while( true );
}

