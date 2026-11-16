// FUN_fffffff00a2c7710 @ fffffff00a2c7710 size=1444
// CALLERS:
//   fffffff00afb9304 ?
//   fffffff00a2c6f0c FUN_fffffff00a2c6950@fffffff00a2c6950
//   fffffff00a2c92c0 FUN_fffffff00a2c8ec8@fffffff00a2c8ec8
// CALLS:
//   fffffff00a247a70 FUN_fffffff00a247a70
//   fffffff00a3ec1d8 FUN_fffffff00a3ec1d8
//   fffffff00a2c7cb4 FUN_fffffff00a2c7cb4
//   fffffff00a246e7c FUN_fffffff00a246e7c
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a28c5d4 FUN_fffffff00a28c5d4
//   fffffff00a7e0f00 FUN_fffffff00a7e0f00

undefined8
FUN_fffffff00a2c7710
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 *param_7,ulong *param_8,uint param_9,
          undefined4 *param_10,undefined4 **param_11)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  bool bVar8;
  bool bVar9;
  byte bVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  undefined4 **ppuVar15;
  ulong uVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  undefined4 ****ppppuVar20;
  undefined4 *****pppppuVar21;
  undefined8 *puVar22;
  undefined4 in_wzr;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 auVar23 [16];
  
  if (((param_7 != (undefined8 *)0x0) && (param_8 != (ulong *)0x0)) && (DAT_fffffff00ad950f0 == 0))
  {
    bVar8 = false;
    lVar7 = tpidr_el1;
    bVar10 = 1;
    puVar13 = param_10;
    ppuVar15 = param_11;
    do {
      puVar22 = DAT_fffffff00ad44380;
      uVar5 = (ulong)*(uint *)(lVar7 + 0x4e8);
      if (DAT_fffffff00ad8a2e8 != 0) {
        param_1 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar7,(undefined **)0x0);
        puVar22 = DAT_fffffff00ad44380;
        uVar5 = DAT_fffffff00ad8a2e8;
      }
      for (; DAT_fffffff00ad8a2e8 = uVar5, (undefined8 **)puVar22 != &DAT_fffffff00ad44380;
          puVar22 = (undefined8 *)*puVar22) {
        if ((*(byte *)(puVar22 + 8) & 1) != 0) {
          uVar11 = *(uint *)((long)puVar22 + 0x44);
          uVar1 = *(uint *)((long)puVar22 + 0x34);
          if (*(uint *)(puVar22 + 7) < uVar1 && uVar11 < uVar1) {
            do {
              bVar2 = *(byte *)(puVar22[5] + (ulong)(uVar11 >> 3));
              uVar3 = 1 << (ulong)(uVar11 & 7);
              if ((uVar3 & bVar2) == 0) {
                *(byte *)(puVar22[5] + (ulong)(uVar11 >> 3)) = bVar2 | (byte)uVar3;
                pppppuVar21 = (undefined4 *****)(DAT_fffffff00ad44390 * (ulong)uVar11);
                *(int *)(puVar22 + 7) = *(int *)(puVar22 + 7) + 1;
                *(int *)(puVar22 + 9) = *(int *)(puVar22 + 9) + 1;
                *(undefined4 **)(puVar22[10] + (ulong)uVar11 * 8) = param_10;
                uVar11 = *(uint *)((long)puVar22 + 0x3c);
                DAT_fffffff00ad95048 = DAT_fffffff00ad95048 + 1;
                if (DAT_fffffff00ad9504c < DAT_fffffff00ad95048) {
                  DAT_fffffff00ad9504c = DAT_fffffff00ad95048;
                }
                lVar19 = *(long *)(*(long *)(lVar7 + 0x1b8) + 0x58);
                do {
                  lVar18 = lVar19;
                  lVar4 = UnkSytemRegRead(3,4,0xf,10,6);
                  lVar19 = *(long *)(*(long *)(lVar7 + 0x1b8) + 0x58);
                } while (lVar19 != lVar18);
                if ((DAT_fffffff00ad9503c < DAT_fffffff00ad950e8) &&
                   (DAT_fffffff00ad95040 - DAT_fffffff00ad95048 < DAT_fffffff00ad95050)) {
                  uVar16 = (lVar4 + lVar18) - DAT_fffffff00ad44360;
                  uVar17 = (ulong)DAT_fffffff00ad08000;
                  uVar5 = 0;
                  if (uVar17 != 0) {
                    uVar5 = uVar16 / uVar17;
                  }
                  uVar6 = 0;
                  if (uVar17 != 0) {
                    uVar6 = ((uVar16 - uVar5 * uVar17) * 1000000000) / uVar17;
                  }
                  if (DAT_fffffff007bca0c0 < uVar6 + uVar5 * 1000000000 && DAT_fffffff00ad8a2f0 == 0
                     ) {
                    puVar12 = (uint *)(PTR_DAT_fffffff007bc7040 +
                                      (ulong)(DAT_fffffff007bc7048 - 1U & 0x9a825bee) * 0x18);
                    if ((((ulong)PTR_DAT_fffffff007bc7040 ^ (ulong)puVar12) & 0xffc0000000000000) !=
                        0) {
                      puVar12 = (uint *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
                    }
                    ppuVar15 = (undefined4 **)0xffffffff;
                    FUN_fffffff00a28c5d4
                              (param_1,param_2,param_3,param_4,param_5,param_6,puVar12,-0xff52bbce0,
                               0,0,0xffffffff);
                  }
                }
                if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar7 + 0x4e8)) {
                  DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
                }
                else {
                  FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar7,(uint)DAT_fffffff00ad8a2e8);
                }
                *param_8 = (ulong)pppppuVar21 | (ulong)uVar11 << 0x21;
                if (param_11 == (undefined4 **)0x0) {
                  ppppuVar20 = (undefined4 ****)0x0;
                }
                else {
                  *(undefined4 *)(param_11 + 1) = 0;
                  *(uint *)((long)param_11 + 0xc) = param_9;
                  param_11[2] = param_10;
                  param_11[3] = (undefined4 *)puVar22;
                  ppppuVar20 = (undefined4 ****)(param_11 + 5);
                  *(undefined4 *)((long)param_11 + 4) = 0;
                }
                uVar11 = FUN_fffffff00a3ec1d8(puVar22[3]);
                if (uVar11 == 0) {
                  ppuVar15 = (undefined4 **)0x0;
                  uVar11 = FUN_fffffff00a7e0f00
                                     ((undefined8 *)puVar22[3],pppppuVar21,param_7,param_9 >> 0xe,0,
                                      ppppuVar20);
                  if ((uVar11 == 0) && (ppppuVar20 != (undefined4 ****)0x0)) {
                    return 0;
                  }
                  uVar14 = 1;
                  auVar23 = extraout_q0_02;
                }
                else {
                  uVar14 = 0;
                  auVar23 = extraout_q0_01;
                }
                uVar14 = FUN_fffffff00a2c7cb4
                                   (auVar23,param_2,param_3,param_4,param_5,param_6,(long)puVar22,
                                    param_8,(undefined **)(ulong)uVar11,uVar14,ppuVar15);
                return uVar14;
              }
              uVar11 = uVar11 + 1;
            } while (uVar1 != uVar11);
          }
        }
        uVar5 = DAT_fffffff00ad8a2e8;
      }
      lVar19 = *(long *)(*(long *)(lVar7 + 0x1b8) + 0x58);
      do {
        lVar18 = lVar19;
        lVar4 = UnkSytemRegRead(3,4,0xf,10,6);
        lVar19 = *(long *)(*(long *)(lVar7 + 0x1b8) + 0x58);
      } while (lVar19 != lVar18);
      if ((DAT_fffffff00ad9503c < DAT_fffffff00ad950e8) &&
         (DAT_fffffff00ad95040 - DAT_fffffff00ad95048 < DAT_fffffff00ad95050)) {
        uVar16 = (lVar4 + lVar18) - DAT_fffffff00ad44360;
        uVar17 = (ulong)DAT_fffffff00ad08000;
        uVar5 = 0;
        if (uVar17 != 0) {
          uVar5 = uVar16 / uVar17;
        }
        uVar6 = 0;
        if (uVar17 != 0) {
          uVar6 = ((uVar16 - uVar5 * uVar17) * 1000000000) / uVar17;
        }
        if (uVar6 + uVar5 * 1000000000 <= DAT_fffffff007bca0c0) goto LAB_fffffff00a2c7990;
        if (DAT_fffffff00ad8a2f0 == 0) {
          puVar12 = (uint *)(PTR_DAT_fffffff007bc7040 +
                            (ulong)(DAT_fffffff007bc7048 - 1U & 0x9a825bee) * 0x18);
          if ((((ulong)PTR_DAT_fffffff007bc7040 ^ (ulong)puVar12) & 0xffc0000000000000) != 0) {
            puVar12 = (uint *)((ulong)puVar12 & 0xffffffffffff | 0xc8a2000000000000);
          }
          ppuVar15 = (undefined4 **)0xffffffff;
          FUN_fffffff00a28c5d4
                    (param_1,param_2,param_3,param_4,param_5,param_6,puVar12,-0xff52bbce0,0,0,
                     0xffffffff);
        }
        puVar13 = (undefined4 *)0xf4240;
        FUN_fffffff00a246e7c(&DAT_fffffff00ad9503c,1,1000,1000000);
        if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar7 + 0x4e8)) {
          DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
          param_1 = extraout_q0;
        }
        else {
          param_1 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar7,(uint)DAT_fffffff00ad8a2e8);
        }
      }
      else {
LAB_fffffff00a2c7990:
        if (DAT_fffffff00ad443f8 != 0) {
          DAT_fffffff00ad443fc = 1;
        }
        if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar7 + 0x4e8)) {
          DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
        }
        else {
          param_1 = FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar7,(uint)DAT_fffffff00ad8a2e8);
        }
        if (!bVar8) break;
      }
      FUN_fffffff00a247a70
                (param_1,param_2,param_3,param_4,param_5,param_6,0,0,0,(ulong)puVar13,
                 (ulong)ppuVar15);
      bVar9 = (bool)(bVar10 & DAT_fffffff00ad443f8 == 1);
      bVar8 = true;
      bVar10 = 0;
      param_1 = extraout_q0_00;
    } while (bVar9);
    *(long *)(PTR_DAT_fffffff00ad0e3a8 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000) =
         *(long *)(PTR_DAT_fffffff00ad0e3a8 + (ulong)*(ushort *)(lVar7 + 0x1b0) * 0x4000) + 1;
  }
  return 5;
}

