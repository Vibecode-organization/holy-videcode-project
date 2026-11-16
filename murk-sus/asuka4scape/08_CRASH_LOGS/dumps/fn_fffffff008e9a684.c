// FUN_fffffff008e9a684 @ fffffff008e9a684 size=3096
// CALLERS:
//   fffffff00afd580e no-fn
//   fffffff008e9a4d4 FUN_fffffff008e9a458@fffffff008e9a458
// CALLEES:
//   fffffff008eb9460 thunk_FUN_fffffff009c29268
//   fffffff008eb9350 thunk_FUN_fffffff009c223bc
//   fffffff008eb93f0 thunk_FUN_fffffff009c28af0
//   fffffff008eb93b0 thunk_FUN_fffffff009c28ba8
//   fffffff008eb9420 thunk_FUN_fffffff009c28de8
//   fffffff008eb9400 thunk_FUN_fffffff009c22a7c
//   fffffff008e98eac FUN_fffffff008e98eac
//   fffffff008eb9390 thunk_FUN_fffffff009c224e8
//   fffffff008eb9450 thunk_FUN_fffffff009c29028
//   fffffff008eb9430 thunk_FUN_fffffff009c29568
//   fffffff008eb9410 thunk_FUN_fffffff009c294a8
//   fffffff008eb9370 thunk_FUN_fffffff009c22350
//   fffffff008eb9380 thunk_FUN_fffffff009c2274c
//   fffffff008eb93e0 thunk_FUN_fffffff009c22b48
//   fffffff008e9b680 FUN_fffffff008e9b680
//   fffffff008eb93d0 thunk_FUN_fffffff009c28c68
//   fffffff008eb9360 thunk_FUN_fffffff009c22680
//   fffffff008eb9440 thunk_FUN_fffffff009c291a8
//   fffffff008eb9330 thunk_FUN_fffffff009c225b4
//   fffffff008eb93a0 thunk_FUN_fffffff009c229b0
//   fffffff008eb88a0 thunk_FUN_fffffff00a9029a0

undefined8
FUN_fffffff008e9a684
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8,
          long param_9,long param_10,long param_11,long param_12)

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  int *piVar17;
  uint *puVar18;
  long lVar19;
  uint uVar20;
  ulong uVar21;
  long lVar22;
  uint uVar23;
  undefined *puVar24;
  int iVar25;
  ulong uVar26;
  uint uVar27;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined1 extraout_q0_10 [16];
  undefined1 extraout_q0_11 [16];
  undefined1 extraout_q0_12 [16];
  undefined1 extraout_q0_13 [16];
  undefined1 extraout_q0_14 [16];
  undefined1 extraout_q0_15 [16];
  undefined1 extraout_q0_16 [16];
  undefined1 extraout_q0_17 [16];
  undefined1 extraout_q0_18 [16];
  undefined1 extraout_q0_19 [16];
  undefined1 extraout_q0_20 [16];
  undefined1 extraout_q0_21 [16];
  undefined1 extraout_q0_22 [16];
  undefined1 extraout_q0_23 [16];
  undefined1 extraout_q0_24 [16];
  undefined1 extraout_q0_25 [16];
  undefined1 extraout_q0_26 [16];
  undefined1 extraout_q0_27 [16];
  undefined1 extraout_q0_28 [16];
  undefined1 extraout_q0_29 [16];
  undefined1 extraout_q0_30 [16];
  undefined1 extraout_q0_31 [16];
  undefined1 extraout_q0_32 [16];
  undefined1 extraout_q0_33 [16];
  undefined1 auVar28 [16];
  undefined1 extraout_q0_34 [16];
  undefined1 extraout_q0_35 [16];
  undefined1 extraout_q0_36 [16];
  
  iVar6 = thunk_FUN_fffffff009c223bc(param_7);
  if (iVar6 == 0) {
    uVar7 = 1;
    auVar28 = extraout_q0;
  }
  else {
    uVar7 = thunk_FUN_fffffff009c223bc(param_7);
    auVar28 = extraout_q0_00;
    if (uVar7 == 0) {
      return 1;
    }
  }
  uVar26 = 0;
  do {
    uVar20 = (uint)uVar26;
    bVar2 = thunk_FUN_fffffff009c22b48
                      (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
    uVar11 = (uint)bVar2;
    if (bVar2 < 2) {
      auVar28 = extraout_q0_01;
      if (uVar11 != 0) {
        if (uVar11 != 1) {
          return 0;
        }
        if ((param_7 == 0) ||
           (cVar3 = thunk_FUN_fffffff009c294a8
                              (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,param_7,uVar20
                              ), cVar3 != '\x01')) {
          thunk_FUN_fffffff00a9029a0((byte *)"HTPC Compressed surface not okay!\n");
          return 0;
        }
        uVar5 = thunk_FUN_fffffff009c22a7c
                          (extraout_q0_09,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        piVar17 = (int *)thunk_FUN_fffffff009c28af0
                                   (extraout_q0_10,param_2,param_3,param_4,param_5,param_6,param_7,
                                    uVar20);
        if (piVar17 == (int *)0x0) {
          return 0;
        }
        *(int *)(param_12 + uVar26 * 4) = piVar17[7];
        *(int *)(param_8 + uVar26 * 4) = piVar17[3];
        *(int *)(param_10 + uVar26 * 4) = piVar17[2];
        *(uint *)(param_9 + uVar26 * 4) =
             piVar17[3] + *piVar17 * (uint)uVar5 * piVar17[1] * piVar17[5] * piVar17[6] + -1;
        iVar6 = piVar17[2] +
                ((uint)piVar17[6] >> (ulong)(*(byte *)((long)piVar17 + 0x22) & 0x1f)) * piVar17[7] +
                -1;
        auVar28 = extraout_q0_11;
LAB_fffffff008e9abb4:
        *(int *)(param_11 + uVar26 * 4) = iVar6;
        goto LAB_fffffff008e9b254;
      }
LAB_fffffff008e9b214:
      uVar14 = thunk_FUN_fffffff009c224e8
                         (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      *(int *)(param_8 + uVar26 * 4) = (int)uVar14;
      uVar15 = thunk_FUN_fffffff009c225b4
                         (extraout_q0_34,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      *(int *)(param_9 + uVar26 * 4) = (int)uVar15 + (int)uVar14;
      *(undefined4 *)(param_10 + uVar26 * 4) = 0;
      *(undefined4 *)(param_11 + uVar26 * 4) = 0;
      uVar14 = thunk_FUN_fffffff009c229b0
                         (extraout_q0_35,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      *(int *)(param_12 + uVar26 * 4) = (int)uVar14;
      auVar28 = extraout_q0_36;
    }
    else {
      if (1 < uVar11 - 2) {
        if (uVar11 != 5) {
          return 0;
        }
        uVar14 = FUN_fffffff008e9b680
                           (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        if ((int)uVar14 == 0) {
          return uVar14;
        }
        if (param_7 == 0) {
          bVar1 = false;
          auVar28 = extraout_q0_12;
        }
        else {
          bVar2 = thunk_FUN_fffffff009c294a8
                            (extraout_q0_12,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
          bVar1 = bVar2 - 3 < 2;
          auVar28 = extraout_q0_13;
        }
        thunk_FUN_fffffff009c28ba8(auVar28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        thunk_FUN_fffffff009c28c68
                  (extraout_q0_14,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        uVar8 = thunk_FUN_fffffff009c29028
                          (extraout_q0_15,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        *(undefined4 *)(param_12 + uVar26 * 4) = uVar8;
        uVar14 = thunk_FUN_fffffff009c22680
                           (extraout_q0_16,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        uVar15 = thunk_FUN_fffffff009c2274c
                           (extraout_q0_17,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        uVar9 = thunk_FUN_fffffff009c28ba8
                          (extraout_q0_18,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        uVar10 = thunk_FUN_fffffff009c28c68
                           (extraout_q0_19,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        uVar11 = thunk_FUN_fffffff009c22350(param_7);
        puVar18 = FUN_fffffff008e98eac(uVar11);
        uVar11 = *puVar18;
        if ((int)uVar11 < 0x73347630) {
          if ((int)uVar11 < 0x62336138) {
            if (0x34323075 < (int)uVar11) {
              if ((int)uVar11 < 0x34343466) {
                if ((uVar11 != 0x34323076) && (uVar11 != 0x34323266)) {
                  uVar27 = 0x3276;
                  goto LAB_fffffff008e9afec;
                }
              }
              else {
                if (0x42475240 < (int)uVar11) {
                  if (uVar11 != 0x42475241) {
                    lVar22 = 0x1b;
                    if (uVar11 != 0x52476841) goto LAB_fffffff008e9b0a8;
                    goto LAB_fffffff008e9b078;
                  }
                  goto LAB_fffffff008e9b098;
                }
                if (uVar11 != 0x34343466) {
                  uVar27 = 0x34343476;
                  goto LAB_fffffff008e9aff0;
                }
              }
LAB_fffffff008e9aff8:
              lVar22 = 8;
              if (uVar26 != 1) {
                lVar22 = 0x1b;
              }
              if (uVar26 == 0) {
                lVar22 = 1;
              }
              goto LAB_fffffff008e9b0a8;
            }
            if ((int)uVar11 < 0x26663338) {
              if (uVar11 == 0x26424741) {
LAB_fffffff008e9b098:
                lVar19 = 0x1b;
                lVar22 = 0x15;
                goto LAB_fffffff008e9b0a4;
              }
              if (uVar11 == 0x26526841) {
LAB_fffffff008e9b078:
                lVar19 = 0x1b;
                lVar22 = 0x18;
                goto LAB_fffffff008e9b0a4;
              }
              lVar22 = 0x1b;
              if (uVar11 != 0x26623338) goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9af0c;
            }
            if (0x26773460 < (int)uVar11) {
              if (uVar11 == 0x26773461) goto LAB_fffffff008e9b088;
              uVar27 = 0x3066;
LAB_fffffff008e9afec:
              uVar27 = uVar27 | 0x34320000;
LAB_fffffff008e9aff0:
              lVar22 = 0x1b;
              if (uVar11 != uVar27) goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9aff8;
            }
            if (uVar11 == 0x26663338) goto LAB_fffffff008e9af0c;
            uVar27 = 0x26773372;
LAB_fffffff008e9af9c:
            lVar22 = 0x1b;
            if (uVar11 != uVar27) goto LAB_fffffff008e9b0a8;
            lVar19 = 0x1b;
          }
          else {
            if (0x70343433 < (int)uVar11) {
              if ((int)uVar11 < 0x70663434) {
                if ((uVar11 != 0x70343434) && (uVar11 != 0x70663230)) {
                  uVar27 = 0x3232;
                  goto LAB_fffffff008e9af78;
                }
              }
              else {
                if ((uVar11 + 0x8ccb99d0 < 5) &&
                   ((1 << (ulong)(uVar11 + 0x8ccb99d0 & 0x1f) & 0x15U) != 0)) {
LAB_fffffff008e9ad38:
                  lVar19 = 0x11;
                  if (uVar26 != 1) {
                    lVar19 = 0x1b;
                  }
                  lVar22 = 7;
                  goto LAB_fffffff008e9b0a4;
                }
                uVar27 = 0x3434;
LAB_fffffff008e9af78:
                uVar27 = uVar27 | 0x70660000;
LAB_fffffff008e9b030:
                lVar22 = 0x1b;
                if (uVar11 != uVar27) goto LAB_fffffff008e9b0a8;
              }
LAB_fffffff008e9b038:
              lVar19 = 10;
              if (uVar26 != 1) {
                lVar19 = 0x1b;
              }
              lVar22 = 3;
              goto LAB_fffffff008e9b0a4;
            }
            if ((int)uVar11 < 0x66336138) {
              if (uVar11 != 0x62336138) {
                if (uVar11 == 0x66306138) goto LAB_fffffff008e9afb4;
                uVar27 = 0x66326138;
LAB_fffffff008e9af00:
                lVar22 = 0x1b;
                if (uVar11 == uVar27) goto LAB_fffffff008e9afb4;
                goto LAB_fffffff008e9b0a8;
              }
            }
            else {
              if (0x7034322f < (int)uVar11) {
                if (uVar11 == 0x70343230) goto LAB_fffffff008e9b038;
                uVar27 = 0x70343232;
                goto LAB_fffffff008e9b030;
              }
              if (uVar11 != 0x66336138) {
                uVar27 = 0x66346138;
                goto LAB_fffffff008e9af00;
              }
            }
LAB_fffffff008e9af0c:
            lVar19 = 0;
            if (uVar26 != 1) {
              lVar19 = 0x1b;
            }
          }
          lVar22 = 0x13;
LAB_fffffff008e9b0a4:
          if (uVar26 != 0) {
            lVar22 = lVar19;
          }
        }
        else {
          if (0x77343060 < (int)uVar11) {
            if ((int)uVar11 < 0x78663434) {
              if (0x78343433 < (int)uVar11) {
                if ((uVar11 != 0x78343434) && (uVar11 != 0x78663230)) {
                  uVar27 = 0x3232;
                  goto LAB_fffffff008e9ae70;
                }
                goto LAB_fffffff008e9ae7c;
              }
              if (uVar11 != 0x77343061) {
                if (uVar11 == 0x78343230) goto LAB_fffffff008e9ae7c;
                uVar27 = 0x78343232;
                goto LAB_fffffff008e9ae74;
              }
LAB_fffffff008e9b088:
              lVar19 = 0x1b;
              lVar22 = 0x19;
            }
            else if (((uVar11 + 0x868f99d0 < 5) &&
                     ((1 << (ulong)(uVar11 + 0x868f99d0 & 0x1f) & 0x15U) != 0)) ||
                    ((uVar11 + 0x868f89d0 < 5 &&
                     ((1 << (ulong)(uVar11 + 0x868f89d0 & 0x1f) & 0x15U) != 0)))) {
              lVar19 = 0xc;
              if (uVar26 != 1) {
                lVar19 = 0x1b;
              }
              lVar22 = 5;
            }
            else {
              uVar27 = 0x3434;
LAB_fffffff008e9ae70:
              uVar27 = uVar27 | 0x78660000;
LAB_fffffff008e9ae74:
              lVar22 = 0x1b;
              if (uVar11 != uVar27) goto LAB_fffffff008e9b0a8;
LAB_fffffff008e9ae7c:
              lVar19 = 9;
              if (uVar26 != 1) {
                lVar19 = 0x1b;
              }
              lVar22 = 2;
            }
            goto LAB_fffffff008e9b0a4;
          }
          if ((int)uVar11 < 0x74763230) {
            if (0x7466322f < (int)uVar11) {
              if ((uVar11 != 0x74663230) && (uVar11 != 0x74663232)) {
                uVar27 = 0x74663434;
                goto LAB_fffffff008e9ae24;
              }
              goto LAB_fffffff008e9ae2c;
            }
            if (uVar11 + 0x8ccb89d0 < 5) {
              lVar22 = 0x1b;
              if ((1 << (ulong)(uVar11 + 0x8ccb89d0 & 0x1f) & 0x15U) == 0)
              goto LAB_fffffff008e9b0a8;
              goto LAB_fffffff008e9ad38;
            }
          }
          else {
            if ((int)uVar11 < 0x76306138) {
              if ((uVar11 != 0x74763230) && (uVar11 != 0x74763232)) {
                uVar27 = 0x74763434;
LAB_fffffff008e9ae24:
                lVar22 = 0x1b;
                if (uVar11 != uVar27) goto LAB_fffffff008e9b0a8;
              }
LAB_fffffff008e9ae2c:
              lVar19 = 0xb;
              if (uVar26 != 1) {
                lVar19 = 0x1b;
              }
              lVar22 = 4;
              goto LAB_fffffff008e9b0a4;
            }
            if ((int)uVar11 < 0x76346138) {
              if (uVar11 != 0x76306138) {
                uVar27 = 0x76326138;
                goto LAB_fffffff008e9af00;
              }
            }
            else if (uVar11 != 0x76346138) {
              uVar27 = 0x77333072;
              goto LAB_fffffff008e9af9c;
            }
LAB_fffffff008e9afb4:
            if (uVar26 < 3) {
              lVar22 = (&DAT_fffffff007634100)[uVar26];
              goto LAB_fffffff008e9b0a8;
            }
          }
          lVar22 = 0x1b;
        }
LAB_fffffff008e9b0a8:
        cVar3 = thunk_FUN_fffffff009c294a8
                          (extraout_q0_20,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        if (cVar3 == '\x04') {
          bVar2 = thunk_FUN_fffffff009c29568
                            (extraout_q0_25,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
          uVar21 = (ulong)bVar2;
          auVar28 = extraout_q0_26;
        }
        else {
          uVar21 = 0;
          auVar28 = extraout_q0_25;
        }
        puVar24 = &UNK_fffffff007633bc0 + lVar22 * 0x30;
        if ((((ulong)puVar24 ^ 0xfffffff007633bc0) & 0xffc0000000000000) != 0) {
          puVar24 = (undefined *)((ulong)puVar24 & 0xffffffffffff | 0xc8a2000000000000);
        }
        iVar6 = *(int *)(puVar24 + uVar21 * 4 + 0x10);
        uVar11 = 0;
        if ((uVar9 & 0xff) != 0) {
          uVar11 = (((int)uVar14 + (uVar9 & 0xff)) - 1) / (uVar9 & 0xff);
        }
        uVar9 = 0;
        if ((uVar10 & 0xff) != 0) {
          uVar9 = (((int)uVar15 + (uVar10 & 0xff)) - 1) / (uVar10 & 0xff);
        }
        iVar12 = thunk_FUN_fffffff009c291a8
                           (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        *(int *)(param_8 + uVar26 * 4) = iVar12;
        *(uint *)(param_9 + uVar26 * 4) = iVar12 + uVar11 * iVar6 * uVar9 + -1;
        *(undefined4 *)(param_10 + uVar26 * 4) = 0;
        *(undefined4 *)(param_11 + uVar26 * 4) = 0;
        auVar28 = extraout_q0_27;
        if (bVar1) {
          uVar9 = thunk_FUN_fffffff009c28ba8
                            (extraout_q0_27,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
          uVar10 = thunk_FUN_fffffff009c28c68
                             (extraout_q0_28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20)
          ;
          uVar14 = thunk_FUN_fffffff009c22680
                             (extraout_q0_29,param_2,param_3,param_4,param_5,param_6,param_7,uVar20)
          ;
          uVar15 = thunk_FUN_fffffff009c2274c
                             (extraout_q0_30,param_2,param_3,param_4,param_5,param_6,param_7,uVar20)
          ;
          uVar11 = 0;
          if ((uVar9 & 0xff) != 0) {
            uVar11 = (((int)uVar14 + (uVar9 & 0xff)) - 1) / (uVar9 & 0xff);
          }
          uVar9 = 0;
          if ((uVar10 & 0xff) != 0) {
            uVar9 = (((int)uVar15 + (uVar10 & 0xff)) - 1) / (uVar10 & 0xff);
          }
          uVar10 = thunk_FUN_fffffff009c28de8
                             (extraout_q0_31,param_2,param_3,param_4,param_5,param_6,param_7,uVar20)
          ;
          iVar6 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar11) & 0x1f) < uVar11) {
            iVar6 = 0;
          }
          iVar12 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar9) & 0x1f) < uVar9) {
            iVar12 = 0;
          }
          iVar13 = thunk_FUN_fffffff009c29268
                             (extraout_q0_32,param_2,param_3,param_4,param_5,param_6,param_7,uVar20)
          ;
          *(int *)(param_10 + uVar26 * 4) = iVar13;
          *(uint *)(param_11 + uVar26 * 4) =
               iVar13 + ((1 << (ulong)(iVar6 - (uint)LZCOUNT(uVar11) & 0x1f)) <<
                        (ulong)(iVar12 - (uint)LZCOUNT(uVar9) & 0x1f)) * (uVar10 & 0xffff) + -1;
          auVar28 = extraout_q0_33;
        }
        goto LAB_fffffff008e9b214;
      }
      bVar2 = thunk_FUN_fffffff009c22b48
                        (extraout_q0_01,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      if ((bVar2 & 0xfe) != 2) {
        return 0;
      }
      uVar14 = thunk_FUN_fffffff009c2274c
                         (extraout_q0_02,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      uVar15 = thunk_FUN_fffffff009c22680
                         (extraout_q0_03,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      uVar5 = thunk_FUN_fffffff009c22a7c
                        (extraout_q0_04,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      uVar16 = thunk_FUN_fffffff009c229b0
                         (extraout_q0_05,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      cVar3 = thunk_FUN_fffffff009c22b48
                        (extraout_q0_06,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      iVar6 = (int)uVar16;
      *(int *)(param_12 + uVar26 * 4) = iVar6;
      uVar11 = (uint)uVar5;
      auVar28 = extraout_q0_07;
      if ((param_7 == 0) ||
         (cVar4 = thunk_FUN_fffffff009c294a8
                            (extraout_q0_07,param_2,param_3,param_4,param_5,param_6,param_7,uVar20),
         auVar28 = extraout_q0_08, cVar4 != '\x02')) {
        if (cVar3 == '\x03') {
          uVar9 = 0;
          if (uVar11 != 0) {
            uVar9 = 0x4000 / uVar11;
          }
          iVar12 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar9) & 0x1f) < uVar9) {
            iVar12 = 0x20;
          }
          *(int *)(param_12 + uVar26 * 4) =
               iVar6 << (ulong)((iVar12 - (uint)LZCOUNT(uVar9)) + 1 >> 1 & 0x1f);
        }
        iVar12 = -1;
        iVar6 = -1;
      }
      else {
        if (uVar5 < 8) {
          if (1 < uVar11 - 1) {
            uVar27 = 0xaaaaaaaa;
            uVar23 = 0xaaaaaaaa;
            if (uVar11 != 4) goto LAB_fffffff008e9aa78;
          }
          uVar27 = 0x10;
          uVar23 = 0x10;
        }
        else {
          uVar9 = 0xaaaaaaaa;
          uVar27 = 8;
          uVar10 = uVar9;
          if (uVar11 == 8) {
            uVar9 = 0x10;
            uVar10 = uVar27;
          }
          uVar23 = uVar27;
          if (uVar11 != 0x10) {
            uVar27 = uVar10;
            uVar23 = uVar9;
          }
        }
LAB_fffffff008e9aa78:
        uVar9 = 0;
        if (uVar27 != 0) {
          uVar9 = (((int)uVar15 + uVar27) - 1) / uVar27;
        }
        iVar12 = 0x1f;
        if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar9) & 0x1f) < uVar9) {
          iVar12 = 0;
        }
        uVar27 = (uint)uVar14;
        uVar10 = 0;
        if (uVar23 != 0) {
          uVar10 = ((uVar27 + uVar23) - 1) / uVar23;
        }
        iVar25 = 0x1f;
        iVar13 = iVar25;
        if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar10) & 0x1f) < uVar10) {
          iVar13 = 0;
        }
        if (cVar3 == '\x03') {
          uVar23 = 0;
          if (uVar11 != 0) {
            uVar23 = 0x4000 / uVar11;
          }
          iVar25 = 0x1f;
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar23) & 0x1f) < uVar23) {
            iVar25 = 0x20;
          }
          uVar23 = (iVar25 - (uint)LZCOUNT(uVar23)) + 1 >> 1;
          iVar25 = 1 << (ulong)(uVar23 & 0x1f);
          uVar11 = (iVar25 + uVar27) - 1 & -iVar25;
          *(int *)(param_12 + uVar26 * 4) = iVar6 << (ulong)(uVar23 & 0x1f);
        }
        else {
          if (0x80000000U >> (ulong)((uint)LZCOUNT(uVar27) & 0x1f) < uVar27) {
            iVar25 = 0;
          }
          uVar11 = 1 << (ulong)(iVar25 - (uint)LZCOUNT(uVar27) & 0x1f);
        }
        iVar6 = uVar11 * iVar6 + -1;
        iVar12 = ((2 << (ulong)(iVar12 - (uint)LZCOUNT(uVar9) & 0x1f)) <<
                 (ulong)(iVar13 - (uint)LZCOUNT(uVar10) & 0x1f)) + -1;
      }
      uVar14 = thunk_FUN_fffffff009c224e8
                         (auVar28,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      *(int *)(param_8 + uVar26 * 4) = (int)uVar14;
      uVar15 = thunk_FUN_fffffff009c225b4
                         (extraout_q0_21,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
      *(int *)(param_9 + uVar26 * 4) = (int)uVar15 + (int)uVar14;
      *(undefined4 *)(param_10 + uVar26 * 4) = 0;
      *(undefined4 *)(param_11 + uVar26 * 4) = 0;
      auVar28 = extraout_q0_22;
      if ((param_7 != 0) &&
         (cVar3 = thunk_FUN_fffffff009c294a8
                            (extraout_q0_22,param_2,param_3,param_4,param_5,param_6,param_7,uVar20),
         auVar28 = extraout_q0_23, cVar3 != '\0')) {
        lVar19 = thunk_FUN_fffffff009c28af0
                           (extraout_q0_23,param_2,param_3,param_4,param_5,param_6,param_7,uVar20);
        if (lVar19 == 0) {
          return 0;
        }
        iVar13 = *(int *)(lVar19 + 0xc);
        *(int *)(param_8 + uVar26 * 4) = iVar13;
        *(int *)(param_9 + uVar26 * 4) = iVar13 + iVar6;
        iVar6 = *(int *)(lVar19 + 8);
        *(int *)(param_10 + uVar26 * 4) = iVar6;
        iVar6 = iVar6 + iVar12;
        auVar28 = extraout_q0_24;
        goto LAB_fffffff008e9abb4;
      }
    }
LAB_fffffff008e9b254:
    uVar26 = uVar26 + 1;
    if (uVar7 == uVar26) {
      return 1;
    }
  } while( true );
}

