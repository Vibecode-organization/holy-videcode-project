// FUN_fffffff008197670 @ fffffff008197670 size=8612

/* WARNING: Removing unreachable block (ram,0xfffffff008199040) */
/* WARNING: Removing unreachable block (ram,0xfffffff00819884c) */
/* WARNING: Removing unreachable block (ram,0xfffffff008198d68) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081990b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff008198218) */

undefined8
FUN_fffffff008197670
          (long *param_1,long param_2,long param_3,long param_4,long param_5,int *param_6,
          long *param_7,long *param_8,long param_9,undefined8 param_10,long *param_11,long *param_12
          ,long param_13)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  bool bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  long *plVar9;
  undefined *puVar10;
  long *plVar11;
  byte bVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  undefined8 *puVar16;
  ulong uVar17;
  ulong uVar18;
  long *plVar19;
  undefined8 uVar20;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;
  undefined8 *puVar24;
  long lVar25;
  ulong uVar26;
  long lVar27;
  long lVar28;
  ulong uVar29;
  undefined8 *puVar30;
  ulong uVar31;
  undefined8 *puVar32;
  undefined *local_380;
  long lStack_378;
  long lStack_370;
  undefined8 local_368;
  undefined8 local_360;
  undefined8 uStack_358;
  undefined8 uStack_350;
  undefined8 uStack_348;
  undefined8 local_340;
  undefined8 uStack_338;
  undefined8 uStack_330;
  undefined8 uStack_328;
  undefined8 local_320;
  undefined8 uStack_318;
  undefined8 local_310;
  byte local_301;
  long local_300;
  long lStack_2f8;
  long lStack_2f0;
  long local_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 uStack_2d0;
  undefined8 uStack_2c8;
  undefined8 local_2c0;
  undefined8 uStack_2b8;
  undefined8 uStack_2b0;
  undefined8 uStack_2a8;
  undefined8 local_2a0;
  undefined8 uStack_298;
  undefined8 local_290;
  undefined8 local_280;
  undefined8 uStack_278;
  undefined8 uStack_270;
  undefined8 uStack_268;
  undefined8 local_260;
  undefined8 uStack_258;
  undefined8 uStack_250;
  undefined8 uStack_248;
  ulong local_240;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 uStack_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 uStack_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  code *local_a0;
  undefined *local_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  
  if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
  if ((*(byte *)(param_3 + 0x130) & 1) == 0) {
    bVar6 = (*(byte *)(param_1[0xa6] + 0x5ca) & 0x20) == 0;
  }
  else {
    bVar6 = true;
  }
  *(byte *)((long)param_7 + 0xf41) = *(byte *)(param_3 + 0x130) & 1;
  lVar27 = param_7[0x191];
  lVar25 = param_7[0x20];
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_188 = 0;
  local_190 = 0;
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  uStack_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  uStack_1c0 = 0;
  uStack_1e8 = 0;
  local_1f0 = 0;
  uStack_1d8 = 0;
  uStack_1e0 = 0;
  uStack_208 = 0;
  local_210 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_228 = 0;
  local_230 = 0;
  uStack_218 = 0;
  uStack_220 = 0;
  thunk_EXT_FUN_8011000002946f14(&local_130);
  thunk_EXT_FUN_8011000002946f14(&local_170);
  lVar14 = param_1[0xa6];
  if ((*(byte *)(lVar14 + 0x11164) & 1) == 0) {
    puVar24 = (undefined8 *)0x0;
    puVar30 = (undefined8 *)0x0;
  }
  else {
    puVar30 = &local_1f0;
    thunk_EXT_FUN_8011000002946f14(&local_1f0);
    puVar24 = &local_230;
    thunk_EXT_FUN_8011000002946f14(&local_230);
    lVar14 = param_1[0xa6];
  }
  bVar12 = 1 < *(uint *)(lVar14 + 0x414) & (bVar6 ^ 1U);
  uStack_258 = 0;
  local_260 = 0;
  uStack_248 = 0;
  uStack_250 = 0;
  uStack_278 = 0;
  local_280 = 0;
  uStack_268 = 0;
  uStack_270 = 0;
  local_240 = (ulong)bVar12;
  if (bVar12 == 1) {
    thunk_EXT_FUN_8011000002946f14(&local_280);
  }
  lVar14 = param_1[0xc2];
  if ((*(byte *)(param_1[0x123] + 0x24) & 1) == 0) {
    lVar15 = *(long *)(*(long *)(lVar14 + 0x28) + 0x228);
    uVar13 = *(int *)(lVar15 + 0x2c) + 1;
    uVar2 = *(uint *)(lVar15 + 0x50);
    uVar4 = 0;
    if (uVar2 != 0) {
      uVar4 = uVar13 / uVar2;
    }
    *(uint *)(lVar15 + 0x2c) = uVar13 - uVar4 * uVar2;
  }
  FUN_fffffff00818ac24
            (*(undefined8 *)(lVar14 + 0xa8),*(undefined4 *)(param_2 + 0xb4),
             *(undefined4 *)(param_2 + 0xb8));
  FUN_fffffff00818add4
            (*(undefined8 *)(param_1[0xc2] + 0xa8),*(undefined4 *)(param_2 + 0xc4),&local_130,0,
             lVar27);
  FUN_fffffff00818add4
            (*(undefined8 *)(param_1[0xc2] + 0xa8),*(undefined4 *)(param_2 + 200),&local_170,puVar30
             ,lVar25);
  lVar14 = param_1[0xa6];
  if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x80b,param_1 + 0x9b,lVar27);
    lVar14 = param_1[0xa6];
  }
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),param_1 + 0x9b,&local_130);
  lVar14 = param_1[0xa6];
  if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x80b,param_1 + 0x9b,lVar25);
    lVar14 = param_1[0xa6];
  }
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),param_1 + 0x9b,&local_170);
  if (puVar30 != (undefined8 *)0x0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x9b,puVar30);
  }
  FUN_fffffff00818c0d0(param_1,param_2,0,&local_130,0,lVar27);
  FUN_fffffff00818c0d0(param_1,param_2,1,&local_170,puVar30,lVar25);
  if ((local_240 & 1) != 0) {
    thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),&local_130,&local_280);
  }
  uStack_2d8 = 0;
  local_2e0 = 0;
  uStack_2c8 = 0;
  uStack_2d0 = 0;
  lStack_2f8 = 0;
  local_300 = 0;
  local_2e8 = 0;
  lStack_2f0 = 0;
  uStack_358 = 0;
  local_360 = 0;
  uStack_348 = 0;
  uStack_350 = 0;
  lStack_378 = 0;
  local_380 = (undefined *)0x0;
  local_368 = 0;
  lStack_370 = 0;
  uVar31 = *(ulong *)(param_1[0xa6] + 0x5c8);
  uVar17 = param_1[0xa9];
  thunk_EXT_FUN_8011000002946f14(&local_300);
  lVar14 = *(long *)(param_9 + 0x18);
  uVar26 = *(ulong *)(lVar14 + 0x20);
  if (uVar26 == 0) {
    uVar29 = 0;
    uVar21 = 0xffffffffffffffff;
  }
  else {
    uVar29 = 0;
    uVar21 = 0xffffffffffffffff;
    uVar23 = 0;
    uVar18 = 1;
    do {
      lVar15 = *(long *)(*(long *)(lVar14 + 0x18) + uVar23 * 8);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),*(undefined8 *)(lVar15 + 0x18),&local_300);
      uVar22 = (ulong)*(uint *)(lVar15 + 0x14);
      uVar23 = uVar22;
      if ((*(byte *)(lVar15 + 0xc2) & 1) != 0) {
        uVar23 = 0xffffffffffffffff;
      }
      if ((uVar31 >> 0x32 & 1) != 0) {
        if ((uVar22 & ~uVar17) != 0) {
          FUN_fffffff0081963b0(lVar15,uVar22,uVar17,"TA Read");
        }
        if (((uVar17 & (uVar22 ^ 0xffffffffffffffff)) != 0) && ((*(byte *)(lVar15 + 0xc2) & 1) == 0)
           ) {
          FUN_fffffff0081963b0(lVar15,uVar22,uVar17,"TA Write");
        }
      }
      uVar29 = uVar29 | uVar22;
      uVar21 = uVar23 & uVar21;
      Hint_Prefetch(*(long *)(lVar15 + 0x18) + 0x40,2,0,1);
      bVar1 = uVar18 < uVar26;
      uVar23 = uVar18;
      uVar18 = (ulong)((int)uVar18 + 1);
    } while (bVar1);
  }
  lVar14 = *(long *)(param_9 + 0x68);
  uVar26 = *(ulong *)(lVar14 + 0x20);
  if (uVar26 != 0) {
    uVar23 = 0;
    uVar18 = 1;
    do {
      lVar15 = *(long *)(*(long *)(lVar14 + 0x18) + uVar23 * 8);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),*(undefined8 *)(lVar15 + 0x18),&local_300);
      uVar22 = (ulong)*(uint *)(lVar15 + 0x14);
      uVar23 = uVar22;
      if ((*(byte *)(lVar15 + 0xc2) & 1) != 0) {
        uVar23 = 0xffffffffffffffff;
      }
      if ((uVar31 >> 0x32 & 1) != 0) {
        if ((uVar22 & ~uVar17) != 0) {
          FUN_fffffff0081963b0(lVar15,uVar22,uVar17,"TA Read");
        }
        if (((uVar17 & (uVar22 ^ 0xffffffffffffffff)) != 0) && ((*(byte *)(lVar15 + 0xc2) & 1) == 0)
           ) {
          FUN_fffffff0081963b0(lVar15,uVar22,uVar17,"TA Write");
        }
      }
      uVar29 = uVar29 | uVar22;
      uVar21 = uVar23 & uVar21;
      Hint_Prefetch(*(long *)(lVar15 + 0x18) + 0x40,2,0,1);
      bVar1 = uVar18 < uVar26;
      uVar23 = uVar18;
      uVar18 = (ulong)((int)uVar18 + 1);
    } while (bVar1);
  }
  lVar14 = *(long *)(param_9 + 0x58);
  uVar26 = *(ulong *)(lVar14 + 0x20);
  if (uVar26 != 0) {
    uVar23 = 0;
    uVar18 = 1;
    do {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),
                 *(undefined8 *)(*(long *)(*(long *)(lVar14 + 0x18) + uVar23 * 8) + 0x18),&local_300
                );
      bVar1 = uVar18 < uVar26;
      uVar23 = uVar18;
      uVar18 = (ulong)((int)uVar18 + 1);
    } while (bVar1);
  }
  lVar14 = *(long *)(param_9 + 0x10);
  uVar26 = *(ulong *)(lVar14 + 0x20);
  if (uVar26 != 0) {
    uVar23 = 0;
    uVar18 = 1;
    do {
      lVar28 = *(long *)(*(long *)(lVar14 + 0x18) + uVar23 * 8);
      lVar15 = thunk_EXT_FUN_801100000295198c(lVar28);
      if (*(char *)(lVar15 + 0x11) < '\0') {
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(param_1[0xa6] + 0x148),*(long *)(lVar28 + 0x18) + 0x40,&local_300
                  );
      }
      uVar23 = (ulong)*(uint *)(lVar28 + 0x14);
      if (((uVar31 >> 0x32 & 1) != 0) && ((uVar23 & ~uVar17) != 0)) {
        FUN_fffffff0081963b0(lVar28,uVar23,uVar17,"TA Read");
      }
      uVar29 = uVar29 | uVar23;
      Hint_Prefetch(*(undefined8 *)(lVar28 + 0x18),2,0,1);
      bVar1 = uVar18 < uVar26;
      uVar23 = uVar18;
      uVar18 = (ulong)((int)uVar18 + 1);
    } while (bVar1);
  }
  lVar14 = *(long *)(param_9 + 0x60);
  uVar26 = *(ulong *)(lVar14 + 0x20);
  if (uVar26 != 0) {
    uVar23 = 0;
    uVar18 = 1;
    do {
      lVar28 = *(long *)(*(long *)(lVar14 + 0x18) + uVar23 * 8);
      lVar15 = thunk_EXT_FUN_801100000295198c(lVar28);
      if (*(char *)(lVar15 + 0x11) < '\0') {
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(param_1[0xa6] + 0x148),*(long *)(lVar28 + 0x18) + 0x40,&local_300
                  );
      }
      uVar23 = (ulong)*(uint *)(lVar28 + 0x14);
      if (((uVar31 >> 0x32 & 1) != 0) && ((uVar23 & ~uVar17) != 0)) {
        FUN_fffffff0081963b0(lVar28,uVar23,uVar17,"TA Read");
      }
      uVar29 = uVar29 | uVar23;
      Hint_Prefetch(*(undefined8 *)(lVar28 + 0x18),2,0,1);
      bVar1 = uVar18 < uVar26;
      uVar23 = uVar18;
      uVar18 = (ulong)((int)uVar18 + 1);
    } while (bVar1);
  }
  if ((local_240 & 1) != 0) {
    lVar14 = *(long *)(param_9 + 0x40);
    uVar17 = *(ulong *)(lVar14 + 0x20);
    if (uVar17 != 0) {
      uVar26 = 0;
      uVar31 = 1;
      do {
        lVar28 = *(long *)(*(long *)(lVar14 + 0x18) + uVar26 * 8);
        lVar15 = thunk_EXT_FUN_801100000295198c(lVar28);
        if (*(char *)(lVar15 + 0x11) < '\0') {
          thunk_EXT_FUN_80110000029486ac
                    (*(undefined8 *)(param_1[0xa6] + 0x148),*(long *)(lVar28 + 0x18) + 0x40,
                     &local_280);
        }
        bVar1 = uVar31 < uVar17;
        uVar26 = uVar31;
        uVar31 = (ulong)((int)uVar31 + 1);
      } while (bVar1);
    }
  }
  FUN_fffffff00818dc84(param_1,&local_300,&local_380);
  thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),&local_380,&local_130);
  if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
    FUN_fffffff0081a0304(*(undefined8 *)(param_1[0xa6] + 0x148),0x801,&local_380,lVar27);
  }
  if ((*(byte *)(param_1 + 0x121) & 1) == 0) {
    if (((uVar29 & (param_1[0xa9] ^ 0xffffffffffffffffU)) == 0) &&
       (((param_1[0xa9] | uVar29) & (uVar21 ^ 0xffffffffffffffff)) == 0)) goto LAB_fffffff008197de0;
    if ((*(byte *)(param_1[0xa6] + 0x1ff) & 1) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ca61a8,0x11,
                 "protection violation: %016llx -> %016llx -> %016llx");
    }
    (**(code **)(*param_1 + 0xf0))(param_1,0x10);
  }
  else {
LAB_fffffff008197de0:
    uVar17 = FUN_fffffff008197128(param_1,param_9,&local_170,puVar30,lVar25);
    if ((uVar17 & 1) != 0) {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0xba,&local_130);
      lVar14 = param_1[0xa6];
      if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x81b,param_1 + 0xba,lVar27);
        lVar14 = param_1[0xa6];
      }
      thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),param_1 + 0xba,&local_170);
      if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304(*(undefined8 *)(param_1[0xa6] + 0x148),0x81b,param_1 + 0xba,lVar25);
      }
      if (puVar30 != (undefined8 *)0x0) {
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0xba);
      }
      FUN_fffffff0081953d4(param_1,param_6,0,&local_130,0,lVar27);
      if ((*(byte *)(param_1[0x123] + 0x24) & 1) == 0) {
        lVar15 = *(long *)(*(long *)(param_1[0xc2] + 0x28) + 0x228);
        lVar14 = *(long *)(lVar15 + 0x10);
        if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
          lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
          uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
          if (lVar28 - (int)lVar28 != 0) {
            uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
          }
          FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x802,uVar17,lVar27);
          lVar14 = *(long *)(lVar15 + 0x10);
        }
        lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
        uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
        if (lVar28 - (int)lVar28 != 0) {
          uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
        }
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),uVar17,&local_130);
        lVar15 = *(long *)(*(long *)(param_1[0xc2] + 0x28) + 0x228);
        lVar14 = *(long *)(lVar15 + 0x10);
        if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
          lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
          uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
          if (lVar28 - (int)lVar28 != 0) {
            uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
          }
          FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x802,uVar17,lVar25);
          lVar14 = *(long *)(lVar15 + 0x10);
        }
        lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
        uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
        if (lVar28 - (int)lVar28 != 0) {
          uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
        }
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),uVar17,&local_170);
      }
      thunk_EXT_FUN_8011000002969c30(param_7,param_1[0xa3]);
      (**(code **)(*param_7 + 0xd8))(param_7,*(undefined8 *)(param_1[0xc2] + 0xa8));
      thunk_EXT_FUN_801100000294849c(*(undefined8 *)(param_1[0xa6] + 0x148),&local_130,&local_1b0);
      thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),&local_170,&local_1b0);
      if (puVar30 != (undefined8 *)0x0) {
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0xa6] + 0x148),puVar30,&local_1b0);
      }
      lVar14 = FUN_fffffff00818c3bc(param_1,&local_1b0,0);
      param_1[0x103] = lVar14;
      if (lVar14 == 0) {
LAB_fffffff008198ec0:
        (**(code **)(*param_7 + 0x28))(param_7);
      }
      else {
        lVar15 = *(long *)(lVar14 + 0x218);
        param_1[0x101] = *(long *)(lVar14 + 0x220);
        param_1[0x100] = lVar15;
        plVar9 = *(long **)(lVar14 + 0x228);
        param_1[0x105] = (long)plVar9;
        if ((*(byte *)(param_1[0x123] + 0x24) & 1) != 0) {
          uVar13 = *(int *)((long)plVar9 + 0x2c) + 1;
          uVar2 = *(uint *)(plVar9 + 10);
          uVar4 = 0;
          if (uVar2 != 0) {
            uVar4 = uVar13 / uVar2;
          }
          uVar13 = uVar13 - uVar4 * uVar2;
          uVar17 = (ulong)uVar13;
          *(uint *)((long)plVar9 + 0x2c) = uVar13;
          lVar14 = plVar9[2];
          if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
            lVar15 = uVar17 * 0x40;
            uVar17 = plVar9[0x18] + (long)(int)lVar15;
            if (lVar15 != (int)lVar15) {
              uVar17 = plVar9[0x18] + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
            }
            FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x802,uVar17,param_7[0x191]);
            lVar14 = plVar9[2];
            uVar17 = (ulong)*(uint *)((long)plVar9 + 0x2c);
          }
          lVar15 = uVar17 * 0x40;
          uVar17 = plVar9[0x18] + (long)(int)lVar15;
          if (lVar15 != (int)lVar15) {
            uVar17 = plVar9[0x18] + lVar15 & 0xffffffffffffU | 0x2bad000000000000;
          }
          thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),uVar17,&local_130);
          lVar15 = param_1[0x105];
          lVar14 = *(long *)(lVar15 + 0x10);
          if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
            lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
            uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
            if (lVar28 - (int)lVar28 != 0) {
              uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
            }
            FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x802,uVar17,param_7[0x20]);
            lVar14 = *(long *)(lVar15 + 0x10);
          }
          lVar28 = (ulong)*(uint *)(lVar15 + 0x2c) * 0x40;
          uVar17 = *(long *)(lVar15 + 0xc0) + (long)(int)lVar28;
          if (lVar28 - (int)lVar28 != 0) {
            uVar17 = *(long *)(lVar15 + 0xc0) + lVar28 & 0xffffffffffffU | 0x2bad000000000000;
          }
          thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),uVar17,&local_170);
          plVar9 = (long *)param_1[0x105];
        }
        param_7[0x17d] = (long)plVar9;
        (**(code **)(*plVar9 + 0x20))();
        if (param_1[0x10a] != 0) {
          param_7[0x2c] = param_1[0x10a];
        }
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        (**(code **)(**(long **)(param_1[0x103] + 0x230) + 0xa8))
                  (*(long **)(param_1[0x103] + 0x230),*(undefined1 *)(param_3 + 0x148));
        uStack_2d8 = 0;
        local_2e0 = 0;
        uStack_2c8 = 0;
        uStack_2d0 = 0;
        lStack_2f8 = 0;
        local_300 = 0;
        local_2e8 = 0;
        lStack_2f0 = 0;
        thunk_EXT_FUN_8011000002946f14(&local_300);
        puVar10 = (undefined *)
                  (**(code **)(*(long *)param_1[0xa6] + 0xc08))(*(long *)param_1[0xa6] + 0xc08);
        local_380 = (undefined *)0x0;
        local_b0 = (undefined *)0x0;
        if (((*(byte *)(param_3 + 8) & 1) == 0) ||
           ((**(code **)(**(long **)(param_1[0x103] + 0x230) + 0x98))
                      (*(long **)(param_1[0x103] + 0x230),bVar6,puVar10,param_3 + 0x150,&local_380,
                       &local_b0), (*(byte *)(param_3 + 8) & 1) == 0)) goto LAB_fffffff008199638;
        lVar14 = 0x1c;
        if ((*(byte *)(param_3 + 0x128) & 1) == 0) {
          lVar14 = 0x14;
        }
        if (*(uint *)(param_1[0x123] + lVar14) < (uint)((ulong)(local_b0 + 0x1ffff) >> 0x11)) {
          bVar6 = true;
          local_380 = puVar10;
          local_b0 = puVar10;
        }
        lVar14 = (**(code **)(**(long **)(param_1[0x103] + 0x230) + 0x88))
                           (*(long **)(param_1[0x103] + 0x230),param_3 + 0x150,
                            *(undefined4 *)(param_3 + 300),*(undefined4 *)(param_1[0x123] + 0xc),
                            &local_300,local_380,bVar6);
        *param_12 = lVar14;
        if (lVar14 == 0) {
          uVar8 = 0x10d;
LAB_fffffff0081987a8:
          (**(code **)(*param_7 + 0x28))(param_7);
          *(undefined4 *)(param_1 + 0xa4) = uVar8;
          return 0;
        }
        *(int *)(param_7 + 0x172) = (int)local_b0;
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        param_7[0x174] = *(long *)(param_3 + 0x150);
        plVar9 = *(long **)(param_1[0x103] + 0x230);
        param_7[0x173] = (long)plVar9;
        lVar14 = (**(code **)(*plVar9 + 0x90))();
        *param_11 = lVar14;
        if (lVar14 == 0) {
          uVar8 = 0x114;
          goto LAB_fffffff0081987a8;
        }
        lVar14 = param_1[0xa6];
        if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x800,&local_300,param_7[0x191]);
          lVar14 = param_1[0xa6];
        }
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),&local_300,&local_130);
        lVar14 = param_1[0xa6];
        if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
          FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x800,*param_12,param_7[0x20]);
          lVar14 = param_1[0xa6];
        }
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar14 + 0x148),*param_12,&local_170);
        if ((char)param_1[0xfd] == '\0') {
          thunk_EXT_FUN_801100000294849c
                    (*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0xe5,param_1 + 0xcd);
          thunk_EXT_FUN_8011000002946f14(param_1 + 0xe5);
        }
        if (*(char *)((long)param_1 + 0x7e9) == '\0') {
          thunk_EXT_FUN_801100000294849c
                    (*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0xed,param_1 + 0xd5);
          thunk_EXT_FUN_8011000002946f14(param_1 + 0xed);
        }
        lVar14 = param_1[0xa6];
        if ((*(byte *)(lVar14 + 0x11180) & 1) != 0) {
          uVar13 = 1 << (ulong)(*(uint *)(param_1[0x103] + 0xe8) & 0x1f);
          if ((uVar13 & *(byte *)(param_1 + 0xfd)) == 0) {
            if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
              FUN_fffffff0081a0304
                        (*(undefined8 *)(lVar14 + 0x148),0x80c,param_1 + 0xcd,param_7[0x191]);
              lVar14 = param_1[0xa6];
            }
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(lVar14 + 0x148),param_1 + 0xcd,&local_130);
            lVar14 = param_1[0xa6];
            if ((*(byte *)(lVar14 + 0x11180) & 1) == 0) goto LAB_fffffff008198430;
            uVar13 = 1 << (ulong)(*(uint *)(param_1[0x103] + 0xe8) & 0x1f);
          }
          if ((uVar13 & *(byte *)((long)param_1 + 0x7e9)) == 0) {
            if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
              FUN_fffffff0081a0304
                        (*(undefined8 *)(lVar14 + 0x148),0x80c,param_1 + 0xd5,param_7[0x20]);
              lVar14 = param_1[0xa6];
            }
            thunk_EXT_FUN_80110000029486ac
                      (*(undefined8 *)(lVar14 + 0x148),param_1 + 0xd5,&local_170);
          }
        }
LAB_fffffff008198430:
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        plVar9 = (long *)param_1[0x100];
        uStack_2b8 = *(undefined8 *)(param_3 + 0x68);
        local_2c0 = *(undefined8 *)(param_3 + 0x60);
        uStack_2a8 = *(undefined8 *)(param_3 + 0x78);
        uStack_2b0 = *(undefined8 *)(param_3 + 0x70);
        uStack_298 = *(undefined8 *)(param_3 + 0x88);
        local_2a0 = *(undefined8 *)(param_3 + 0x80);
        local_290 = *(undefined8 *)(param_3 + 0x90);
        lStack_2f8 = *(long *)(param_3 + 0x28);
        local_300 = *(long *)(param_3 + 0x20);
        local_2e8 = *(long *)(param_3 + 0x38);
        lStack_2f0 = *(long *)(param_3 + 0x30);
        uStack_2d8 = *(undefined8 *)(param_3 + 0x48);
        local_2e0 = *(undefined8 *)(param_3 + 0x40);
        uStack_2c8 = *(undefined8 *)(param_3 + 0x58);
        uStack_2d0 = *(undefined8 *)(param_3 + 0x50);
        local_301 = 0;
        uVar17 = FUN_fffffff0081854b4(plVar9,param_7,&local_300,0,&local_301);
        if ((uVar17 & 1) == 0) {
          (**(code **)(*param_7 + 0x28))(param_7);
          uVar13 = local_301 & 0xfc | 0x200;
          goto LAB_fffffff008197dbc;
        }
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        plVar19 = (long *)param_1[0x101];
        uStack_338 = *(undefined8 *)(param_3 + 0xe0);
        local_340 = *(undefined8 *)(param_3 + 0xd8);
        uStack_328 = *(undefined8 *)(param_3 + 0xf0);
        uStack_330 = *(undefined8 *)(param_3 + 0xe8);
        uStack_318 = *(undefined8 *)(param_3 + 0x100);
        local_320 = *(undefined8 *)(param_3 + 0xf8);
        local_310 = *(undefined8 *)(param_3 + 0x108);
        lStack_378 = *(long *)(param_3 + 0xa0);
        local_380 = *(undefined **)(param_3 + 0x98);
        local_368 = *(undefined8 *)(param_3 + 0xb0);
        lStack_370 = *(long *)(param_3 + 0xa8);
        uStack_358 = *(undefined8 *)(param_3 + 0xc0);
        local_360 = *(undefined8 *)(param_3 + 0xb8);
        uStack_348 = *(undefined8 *)(param_3 + 0xd0);
        uStack_350 = *(undefined8 *)(param_3 + 200);
        uVar17 = FUN_fffffff0081854b4(plVar19,param_7,&local_380,0,&local_301);
        if ((uVar17 & 1) == 0) {
          (**(code **)(*param_7 + 0x28))(param_7);
          uVar13 = local_301 & 0xfc | 0x201;
          goto LAB_fffffff008197dbc;
        }
        lVar14 = plVar9[0x10];
        if (lVar14 != 0) {
          uVar20 = *(undefined8 *)(lVar14 + 0x38);
          lVar14 = *(long *)(lVar14 + 0x50);
          local_b0 = PTR_DAT_fffffff007ca5f90;
          uStack_a8 = DAT_fffffff007113e50;
          local_a0 = FUN_fffffff0081d4434;
          local_90 = &local_130;
          local_98 = &DAT_fffffff007c97620;
          thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar14 + 0x10));
          FUN_fffffff0081d40e8(lVar14,&local_b0,uVar20);
          thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar14 + 0x10));
        }
        lVar14 = plVar19[0x10];
        if (lVar14 != 0) {
          uVar20 = *(undefined8 *)(lVar14 + 0x38);
          lVar14 = *(long *)(lVar14 + 0x50);
          local_b0 = PTR_DAT_fffffff007ca5f90;
          uStack_a8 = DAT_fffffff007113e50;
          local_a0 = FUN_fffffff0081d4434;
          local_90 = &local_170;
          local_98 = &DAT_fffffff007c97620;
          thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(lVar14 + 0x10));
          FUN_fffffff0081d40e8(lVar14,&local_b0,uVar20);
          thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(lVar14 + 0x10));
        }
        if (((*(byte *)((long)param_1 + 0x7f6) & 1) == 0) && (*(int *)(param_9 + 0x8c) != 0)) {
          plVar11 = (long *)thunk_EXT_FUN_8011000002c150fc(param_1[0xa6]);
          if (*(int *)(param_9 + 0x8c) != 0) {
            uVar17 = 0;
            do {
              puVar16 = (undefined8 *)(*(ulong *)(param_9 + 0x80) + uVar17 * 0x10);
              if (((*(ulong *)(param_9 + 0x80) ^ (ulong)puVar16) & 0xffc0000000000000) != 0) {
                puVar16 = (undefined8 *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
              }
              uVar26 = thunk_EXT_FUN_8011000002969b54
                                 (param_7,*puVar16,*(undefined4 *)(puVar16 + 1),plVar11);
              if ((uVar26 & 1) == 0) {
                (**(code **)(*param_7 + 0x28))(param_7);
                *(undefined4 *)(param_1 + 0xa4) = 0x110;
                if (plVar11 != (long *)0x0) {
                  (**(code **)(*plVar11 + 0x28))(plVar11);
                }
                return 0;
              }
              uVar17 = uVar17 + 1;
            } while (uVar17 < *(uint *)(param_9 + 0x8c));
          }
          if (plVar11 != (long *)0x0) {
            (**(code **)(*plVar11 + 0x28))(plVar11);
          }
        }
        if ((*(byte *)(param_1[0xa6] + 0x5cd) >> 6 & 1) != 0) {
          lVar14 = param_1[0x91];
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar14 + 0x1b0));
          uVar17 = *(ulong *)(lVar14 + 0x1a0);
          uVar26 = *(ulong *)(lVar14 + 0x1a8);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar14 + 0x1b0));
          lVar14 = param_7[0x191];
          uStack_88 = 0;
          local_90 = (undefined8 *)0x0;
          uStack_78 = 0;
          uStack_80 = 0;
          uStack_a8 = 0;
          local_b0 = (undefined *)0x0;
          local_98 = (undefined *)0x0;
          local_a0 = (code *)0x0;
          uStack_c8 = 0;
          local_d0 = 0;
          uStack_b8 = 0;
          uStack_c0 = 0;
          uStack_e8 = 0;
          local_f0 = 0;
          uStack_d8 = 0;
          uStack_e0 = 0;
          puVar16 = &local_b0;
          thunk_EXT_FUN_8011000002946f14(&local_b0);
          thunk_EXT_FUN_8011000002946f14(&local_f0);
          thunk_EXT_FUN_801100000294849c
                    (*(undefined8 *)(param_1[0xa6] + 0x148),&local_170,&local_b0);
          puVar32 = &local_f0;
          if (uVar17 != 0) {
            puVar5 = &local_f0;
            do {
              puVar32 = puVar16;
              puVar16 = puVar5;
              uVar31 = (uVar17 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar17 & 0x5555555555555555) << 1;
              uVar31 = (uVar31 & 0xcccccccccccccccc) >> 2 | (uVar31 & 0x3333333333333333) << 2;
              uVar31 = (uVar31 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar31 & 0xf0f0f0f0f0f0f0f) << 4;
              uVar31 = (uVar31 & 0xff00ff00ff00ff00) >> 8 | (uVar31 & 0xff00ff00ff00ff) << 8;
              uVar31 = (uVar31 & 0xffff0000ffff0000) >> 0x10 | (uVar31 & 0xffff0000ffff) << 0x10;
              uVar31 = LZCOUNT(uVar31 >> 0x20 | uVar31 << 0x20);
              thunk_EXT_FUN_8011000002948860
                        (*(undefined8 *)(param_1[0xa6] + 0x148),puVar32,puVar16,uVar31);
              thunk_EXT_FUN_8011000002946f14(puVar32);
              uVar17 = uVar17 & (1L << (uVar31 & 0x3f) ^ 0xffffffffffffffffU);
              puVar5 = puVar32;
            } while (uVar17 != 0);
          }
          for (; puVar5 = puVar32, uVar26 != 0;
              uVar26 = uVar26 & (1L << (uVar17 & 0x3f) ^ 0xffffffffffffffffU)) {
            uVar17 = (uVar26 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar26 & 0x5555555555555555) << 1;
            uVar17 = (uVar17 & 0xcccccccccccccccc) >> 2 | (uVar17 & 0x3333333333333333) << 2;
            uVar17 = (uVar17 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar17 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar17 = (uVar17 & 0xff00ff00ff00ff00) >> 8 | (uVar17 & 0xff00ff00ff00ff) << 8;
            uVar17 = (uVar17 & 0xffff0000ffff0000) >> 0x10 | (uVar17 & 0xffff0000ffff) << 0x10;
            uVar17 = LZCOUNT(uVar17 >> 0x20 | uVar17 << 0x20);
            thunk_EXT_FUN_8011000002948860
                      (*(undefined8 *)(param_1[0xa6] + 0x148),puVar16,puVar5,(uint)uVar17 | 0x40);
            thunk_EXT_FUN_8011000002946f14(puVar16);
            puVar32 = puVar16;
            puVar16 = puVar5;
          }
          lVar15 = param_1[0xa6];
          if ((*(byte *)(lVar15 + 0x1ac45) & 1) != 0) {
            FUN_fffffff0081a0304(*(undefined8 *)(lVar15 + 0x148),0x80e,puVar16,lVar14);
            lVar15 = param_1[0xa6];
          }
          thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(lVar15 + 0x148),puVar16,&local_130);
        }
        thunk_EXT_FUN_801100000294166c(param_1[0x100],param_1[0x91]);
        uVar8 = (**(code **)(*plVar9 + 0x128))(*plVar9 + 0x128,plVar9);
        *(undefined4 *)(param_7 + 0x195) = uVar8;
        param_7[0x192] = (long)plVar9;
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        plVar11 = (long *)param_1[0x100];
        *(byte *)(param_7 + 0x24a) = *(byte *)(param_3 + 0x1c2) & 1;
        (**(code **)(*plVar11 + 0x180))(plVar11,param_7);
        if ((*(byte *)(param_1 + 0xfd) >> (ulong)(*(uint *)(param_1[0x103] + 0xe8) & 0x1f) & 1) == 0
           ) {
          param_7[0x104] = param_4;
        }
        else {
          param_7[0x104] = 0;
          param_8[0x104] = 0;
        }
        param_7[0x105] = param_5;
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        if ((*(byte *)(param_3 + 0x10) & 1) != 0) {
          uVar20 = thunk_EXT_FUN_8011000003a49114
                             ("AGXk: %s:%d:%s: !!! Assertion failed: %s: invalid state!\n");
          return uVar20;
        }
        *(undefined1 *)(param_3 + 0x10) = 1;
        plVar11 = *(long **)(param_3 + 0x18);
        lVar14 = *plVar11;
        param_7[0x1c1] = plVar11[1];
        param_7[0x1c0] = lVar14;
        param_7[0x1c2] = plVar11[2];
        param_7[0x1c3] = plVar11[3];
        param_7[0x1ce] = plVar11[6];
        param_7[0x1cf] = plVar11[7];
        param_7[0x1d0] = plVar11[8];
        param_7[0x1d1] = plVar11[9];
        param_7[0x1d2] = plVar11[10];
        param_7[0x1d3] = plVar11[0xb];
        lVar14 = plVar11[0xc];
        param_7[0x1d5] = plVar11[0xd];
        param_7[0x1d4] = lVar14;
        lVar14 = plVar11[4];
        param_7[0x1c5] = plVar11[5];
        param_7[0x1c4] = lVar14;
        lVar14 = plVar11[0x3e];
        param_7[0x1c7] = plVar11[0x3f];
        param_7[0x1c6] = lVar14;
        lVar14 = plVar11[0x40];
        param_7[0x1c9] = plVar11[0x41];
        param_7[0x1c8] = lVar14;
        param_7[0x1ca] = plVar11[0x42];
        lVar14 = plVar11[0x44];
        param_7[0x1cc] = plVar11[0x45];
        param_7[0x1cb] = lVar14;
        *(int *)(param_7 + 0x1cd) = (int)plVar11[0x46];
        param_7[0x1dc] = plVar11[0x17];
        *(int *)(param_7 + 0x1dd) = (int)plVar11[0x18];
        param_7[0x1d6] = plVar11[0xe];
        param_7[0x1d7] = plVar11[0xf];
        param_7[0x1d8] = plVar11[0x10];
        param_7[0x1d9] = plVar11[0x11];
        param_7[0x1da] = plVar11[0x12];
        param_7[0x1db] = plVar11[0x13];
        *(undefined4 *)(param_7 + 0x1e0) = *(undefined4 *)((long)plVar11 + 0x1e4);
        *(int *)((long)param_7 + 0xf04) = (int)plVar11[0x3d];
        *(undefined4 *)(param_7 + 0x1e1) = *(undefined4 *)((long)plVar11 + 0x1ec);
        *(uint *)(param_7 + 0x1e4) = *(byte *)((long)plVar11 + 0x246) & 1;
        param_7[0x1e5] = plVar11[0x14];
        *(byte *)((long)param_7 + 0xf39) = *(byte *)((long)plVar11 + 0x23d) & 1;
        *(byte *)(param_7 + 0x1e8) = *(byte *)((long)plVar11 + 0x243) & 1;
        *(byte *)((long)param_7 + 0xf3a) = *(byte *)((long)plVar11 + 0x23e) & 1;
        *(byte *)((long)param_7 + 0xf3b) = *(byte *)((long)plVar11 + 0x23f) & 1;
        *(byte *)((long)param_7 + 0xf3d) = *(byte *)((long)plVar11 + 0x241) & 1;
        *(byte *)((long)param_7 + 0xf3f) = *(byte *)((long)plVar11 + 0x242) & 1;
        *(byte *)((long)param_7 + 0xf42) = *(byte *)((long)plVar11 + 0x249) & 1;
        *(byte *)((long)param_7 + 0x1064) = *(byte *)((long)plVar11 + 0x244) & 1;
        *(byte *)((long)param_7 + 0x1065) = *(byte *)((long)plVar11 + 0x245) & 1;
        *(int *)(param_7 + 0x232) = (int)plVar11[0x47];
        *(byte *)((long)param_7 + 0x1239) = *(byte *)((long)plVar11 + 0x24b) & 1;
        *(int *)(param_7 + 0x1b7) = (int)plVar11[0x4b];
        lVar14 = plVar11[0x4c];
        param_7[0x23e] = plVar11[0x4d];
        param_7[0x23d] = lVar14;
        lVar14 = plVar11[0x4e];
        param_7[0x240] = plVar11[0x4f];
        param_7[0x23f] = lVar14;
        lVar14 = plVar11[0x50];
        param_7[0x242] = plVar11[0x51];
        param_7[0x241] = lVar14;
        lVar14 = plVar11[0x52];
        param_7[0x244] = plVar11[0x53];
        param_7[0x243] = lVar14;
        param_7[0x245] = plVar11[0x54];
        *(int *)(param_7 + 0x246) = (int)plVar11[0x55];
        *(byte *)(param_7 + 0x24c) = *(byte *)((long)plVar11 + 0x24a) & 1;
        *(int *)(param_7 + 0x237) = (int)plVar11[0x15];
        param_7[0x238] = plVar11[0x16];
        lVar14 = *(long *)(param_3 + 0x18);
        bVar12 = *(byte *)(lVar14 + 0x7f8) & 1;
        *(byte *)((long)param_7 + 0xf3e) = bVar12;
        *(undefined4 *)((long)param_7 + 0x814) = *(undefined4 *)(lVar14 + 0x7e8);
        *(byte *)(param_7 + 0x102) = *(byte *)(lVar14 + 0x7ec) & 1;
        param_7[0x103] = *(long *)(lVar14 + 0x7f0);
        *(byte *)((long)param_7 + 0x835) = bVar12;
        *(undefined1 *)((long)param_7 + 0x8f1) = *(undefined1 *)(lVar14 + 0x7fa);
        param_7[0x11c] = *(long *)(lVar14 + 0x808);
        param_7[0x11d] = *(long *)(lVar14 + 0x810);
        FUN_fffffff0081dfb54(param_7,lVar14 + 0x2b0);
        lVar14 = *(long *)(param_3 + 0x18);
        param_7[0x97] = *(long *)(lVar14 + 0x698);
        lVar15 = *(long *)(lVar14 + 0x6a0);
        param_7[0xc3] = *(long *)(lVar14 + 0x6a8);
        param_7[0xc2] = lVar15;
        lVar15 = *(long *)(lVar14 + 0x6b0);
        param_7[0xc5] = *(long *)(lVar14 + 0x6b8);
        param_7[0xc4] = lVar15;
        lVar15 = *(long *)(lVar14 + 0x6c0);
        param_7[199] = *(long *)(lVar14 + 0x6c8);
        param_7[0xc6] = lVar15;
        param_7[0xac] = *(long *)(lVar14 + 0x700);
        param_7[0xad] = *(long *)(lVar14 + 0x708);
        param_7[0xae] = *(long *)(lVar14 + 0x710);
        param_7[0xaf] = *(long *)(lVar14 + 0x718);
        param_7[0xb0] = *(long *)(lVar14 + 0x720);
        param_7[0xb1] = *(long *)(lVar14 + 0x728);
        param_7[0xb2] = *(long *)(lVar14 + 0x730);
        param_7[0xb3] = *(long *)(lVar14 + 0x738);
        param_7[0xb4] = *(long *)(lVar14 + 0x740);
        param_7[0xb5] = *(long *)(lVar14 + 0x748);
        param_7[0xb6] = *(long *)(lVar14 + 0x750);
        param_7[0xb7] = *(long *)(lVar14 + 0x758);
        param_7[0xb8] = *(long *)(lVar14 + 0x760);
        param_7[0xb9] = *(long *)(lVar14 + 0x768);
        param_7[0xba] = *(long *)(lVar14 + 0x770);
        param_7[0xbb] = *(long *)(lVar14 + 0x778);
        param_7[0xce] = *(long *)(lVar14 + 0x780);
        param_7[0xde] = *(long *)(lVar14 + 0x788);
        param_7[0xd1] = *(long *)(lVar14 + 0x790);
        param_7[0xe3] = *(long *)(lVar14 + 0x798);
        param_7[0xd4] = *(long *)(lVar14 + 0x7a0);
        param_7[0xd7] = *(long *)(lVar14 + 0x7a8);
        *(undefined8 *)((long)param_7 + 0x794) = *(undefined8 *)(lVar14 + 0x6d0);
        *(undefined4 *)((long)param_7 + 0x79c) = *(undefined4 *)(lVar14 + 0x6d8);
        lVar15 = *(long *)(lVar14 + 0x6e0);
        param_7[0xf0] = *(long *)(lVar14 + 0x6e8);
        param_7[0xef] = lVar15;
        lVar15 = *(long *)(lVar14 + 0x7c0);
        param_7[0x99] = *(long *)(lVar14 + 0x7c8);
        param_7[0x98] = lVar15;
        param_7[0x9a] = *(long *)(lVar14 + 2000);
        uVar8 = *(undefined4 *)(lVar14 + 0x7b0);
        uVar17 = (ulong)CONCAT52((int5)(CONCAT16((char)((uint)uVar8 >> 0x18),
                                                 (uint6)(byte)((uint)uVar8 >> 0x10) << 0x20) >> 0x10
                                       ),(ushort)(byte)uVar8) & 0xffffffffffffff01;
        uVar26 = CONCAT44((int)(uVar17 >> 0x20),
                          (uint)CONCAT12((char)((uint)uVar8 >> 8),(short)uVar17)) &
                 0xffffffffff01ffff;
        uVar17 = CONCAT26((short)(uVar26 >> 0x30),CONCAT24((short)(uVar17 >> 0x20),(int)uVar26)) &
                 0xff01ff01ffffffff;
        *(uint *)((long)param_7 + 0x836) =
             CONCAT13((char)(uVar17 >> 0x30),
                      CONCAT12((char)(uVar17 >> 0x20),CONCAT11((char)(uVar17 >> 0x10),(char)uVar26))
                     );
        *(byte *)((long)param_7 + 0x83a) = *(byte *)(lVar14 + 0x7b4) & 1;
        *(byte *)((long)param_7 + 0x842) = *(byte *)(lVar14 + 0x7b5) & 1;
        *(byte *)((long)param_7 + 0x843) = *(byte *)(lVar14 + 0x7b6) & 1;
        *(undefined4 *)(param_7 + 0x145) = *(undefined4 *)(lVar14 + 0x7e0);
        *(byte *)(param_7 + 0xfe) = *(byte *)(lVar14 + 0x7e4) & 1;
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        param_7[0x93] = *(long *)(param_3 + 0x19c);
        *(undefined4 *)(param_7 + 0x94) = *(undefined4 *)(param_3 + 0x1a4);
        param_7[0x1de] = local_300;
        param_7[0x1df] = local_2e8;
        *(undefined4 *)((long)param_7 + 0xf0c) = local_2e0._4_4_;
        param_7[0x1e3] = lStack_2f0;
        param_7[0x1e2] = lStack_2f8;
        *(byte *)((long)param_7 + 0xf3c) = *(byte *)(param_3 + 0x128) & 1;
        *(byte *)(param_7 + 0x1e7) = *(byte *)(param_3 + 0x1c0) & 1;
        param_7[0xf7] = (long)local_380;
        *(undefined8 *)((long)param_7 + 0x7c4) = local_368;
        *(undefined4 *)((long)param_7 + 0x7cc) = local_360._4_4_;
        param_7[0xfb] = lStack_370;
        param_7[0xfa] = lStack_378;
        *(byte *)((long)param_7 + 0x83f) = *(byte *)(param_3 + 0x128) & 1;
        *(byte *)((long)param_7 + 0x83b) = *(byte *)(param_3 + 0x1c1) & 1;
        *(undefined1 *)(param_7 + 0x11e) = *(undefined1 *)(param_3 + 0x148);
        if ((*(byte *)(param_3 + 0x1c3) & 1) == 0) {
          bVar12 = *(byte *)(param_7[2] + 0x109b1) & 1;
        }
        else {
          bVar12 = 1;
        }
        *(byte *)((long)param_7 + 0xac9) = bVar12;
        (**(code **)(*param_7 + 0xf8))(param_7,*(undefined8 *)(param_1[0x103] + 0x230));
        (**(code **)(*param_7 + 0x100))(*param_7 + 0x100,param_7,param_1[0x105]);
        lVar14 = param_1[0xa6];
        *(undefined4 *)(param_7 + 0x1e6) = *(undefined4 *)(lVar14 + 0x11120);
        param_8[0x14e] = 0;
        param_8[0x14d] = 0;
        if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
        uVar17 = FUN_fffffff0081e8ff0
                           (*(undefined8 *)(lVar14 + 0x111e8),param_1[0x91],
                            *(undefined8 *)(param_9 + 0x50),param_3 + 0x110,param_7 + 0x233,
                            param_7 + 0x234,param_7);
        if ((uVar17 & 1) != 0) {
          if ((*(byte *)(param_2 + 8) & 1) == 0) goto LAB_fffffff008199638;
          if (*(int *)(param_2 + 0xa4) != 0) {
            if ((*(int *)(param_2 + 0x150) != 0 || *(int *)(param_2 + 0x154) != 0) &&
               (uVar17 = FUN_fffffff008195510
                                   (param_1,param_9,param_7,param_7 + 0x235,
                                    *(int *)(param_2 + 0x150),*(int *)(param_2 + 0x154),
                                    *(undefined8 *)(param_2 + 0x160)), (uVar17 & 1) == 0))
            goto LAB_fffffff008198ed8;
          }
          if ((*(byte *)(param_3 + 8) & 1) == 0) goto LAB_fffffff008199638;
          uVar17 = FUN_fffffff0081e8ff0
                             (*(undefined8 *)(param_1[0xa6] + 0x111e8),param_1[0x91],
                              *(undefined8 *)(param_9 + 0x50),param_3 + 0x11c,param_8 + 0x146,
                              param_8 + 0x147,param_8);
          if ((uVar17 & 1) != 0) {
            if ((*(byte *)(param_2 + 8) & 1) == 0) goto LAB_fffffff008199638;
            if (*(int *)(param_2 + 0xa4) != 0) {
              if ((*(int *)(param_2 + 0x158) != 0 || *(int *)(param_2 + 0x15c) != 0) &&
                 (uVar17 = FUN_fffffff008195510
                                     (param_1,param_9,param_8,param_8 + 0x148,
                                      *(int *)(param_2 + 0x158),*(int *)(param_2 + 0x15c),
                                      *(undefined8 *)(param_2 + 0x168)), (uVar17 & 1) == 0))
              goto LAB_fffffff008198ed8;
            }
            if (*(int *)(*(long *)(param_1[0xc2] + 200) + 0x28) == 0) {
              if ((*(byte *)(param_2 + 8) & 1) != 0) {
                (**(code **)(*(long *)param_1[0x100] + 0xa0))();
                *(long *)(param_1[0x100] + 0x28) = param_1[0x82];
                if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
                  uStack_88 = 0;
                  local_90 = (undefined8 *)0x0;
                  uStack_78 = 0;
                  uStack_80 = 0;
                  uStack_a8 = 0;
                  local_b0 = (undefined *)0x0;
                  local_98 = (undefined *)0x0;
                  local_a0 = (code *)0x0;
                  thunk_EXT_FUN_8011000002946f14(&local_b0);
                  (**(code **)(*(long *)param_1[0x100] + 0x98))((long *)param_1[0x100],&local_b0);
                  FUN_fffffff0081a05d0
                            (*(undefined8 *)(*(long *)(param_1[0xa6] + 0x148) + 0x10),0x807,
                             local_b0._4_4_,*(undefined4 *)(param_1[0x103] + 0xe8),param_7[0x191]);
                }
                if ((*(byte *)(param_2 + 8) & 1) != 0) {
                  plVar11 = (long *)param_1[0x100];
                  if (*(int *)(param_2 + 0xa0) != 0) {
                    FUN_fffffff008195bb8(param_1,param_2,plVar11,2,param_7 + 0x20d);
                    plVar11 = (long *)param_1[0x100];
                  }
                  (**(code **)(*plVar11 + 0xa8))(plVar11,0,(long)param_7 + 0xacc);
                  FUN_fffffff00820d7f4(param_7,*(undefined4 *)(param_1[0x100] + 0x18));
                  uVar7 = FUN_fffffff008199814(param_1,&local_280,param_1[0x100]);
                  *(undefined1 *)((long)param_7 + 0x1194) = uVar7;
                  thunk_EXT_FUN_801100000294166c(param_1[0x101],param_1[0x91]);
                  uVar8 = (**(code **)(*plVar19 + 0x128))(*plVar19 + 0x128,plVar19);
                  *(undefined4 *)((long)param_8 + 0x34c) = uVar8;
                  param_8[0x3f] = (long)plVar19;
                  if ((*(byte *)(param_2 + 8) & 1) != 0) {
                    (**(code **)(*(long *)param_1[0x101] + 0xa0))();
                    plVar11 = (long *)param_1[0x101];
                    plVar11[5] = param_1[0x82];
                    uVar20 = (**(code **)(*param_8 + 0x108))(*param_8 + 0x108,param_8);
                    (**(code **)(*plVar11 + 0xa8))(plVar11,0,uVar20);
                    *(undefined4 *)((long)param_8 + 0x8f4) = *(undefined4 *)(param_1[0x101] + 0x18);
                    thunk_EXT_FUN_801100000296a27c(param_8);
                    if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
                      uStack_88 = 0;
                      local_90 = (undefined8 *)0x0;
                      uStack_78 = 0;
                      uStack_80 = 0;
                      uStack_a8 = 0;
                      local_b0 = (undefined *)0x0;
                      local_98 = (undefined *)0x0;
                      local_a0 = (code *)0x0;
                      thunk_EXT_FUN_8011000002946f14(&local_b0);
                      (**(code **)(*(long *)param_1[0x101] + 0x98))
                                ((long *)param_1[0x101],&local_b0);
                      FUN_fffffff0081a05d0
                                (*(undefined8 *)(*(long *)(param_1[0xa6] + 0x148) + 0x10),0x808,
                                 local_b0._4_4_,*(undefined4 *)(param_1[0x103] + 0xe8),param_8[0x20]
                                );
                    }
                    if ((*(byte *)(param_2 + 8) & 1) != 0) {
                      if (*(int *)(param_2 + 0xa0) != 0) {
                        FUN_fffffff008195bb8(param_1,param_2,param_1[0x101],8,param_8 + 0x120);
                      }
                      if ((param_6 != (int *)0x0) && (*param_6 == 3)) {
                        lVar14 = *(long *)(param_6 + 2);
                        param_8[0x39] = *(long *)(param_6 + 4);
                        param_8[0x38] = lVar14;
                        param_8[0x3a] = *(long *)(param_6 + 6);
                        if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
                          uStack_88 = 0;
                          local_90 = (undefined8 *)0x0;
                          uStack_78 = 0;
                          uStack_80 = 0;
                          uStack_a8 = 0;
                          local_b0 = (undefined *)0x0;
                          local_98 = (undefined *)0x0;
                          local_a0 = (code *)0x0;
                          thunk_EXT_FUN_8011000002946f14(&local_b0);
                          (**(code **)(*(long *)param_1[0x101] + 0x98))
                                    ((long *)param_1[0x101],&local_b0);
                          FUN_fffffff0081a05d0
                                    (*(undefined8 *)(*(long *)(param_1[0xa6] + 0x148) + 0x10),0x812,
                                     local_b0._4_4_,*(undefined4 *)(param_1[0x103] + 0xe8),
                                     param_7[0x20]);
                        }
                      }
                      if (puVar30 != (undefined8 *)0x0) {
                        thunk_EXT_FUN_80110000029486ac
                                  (*(undefined8 *)(plVar19[2] + 0x148),plVar19 + 0x23,puVar30);
                        lVar14 = param_1[0xa6];
                        if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
                          FUN_fffffff0081a0304(*(undefined8 *)(lVar14 + 0x148),0x804,puVar30,lVar27)
                          ;
                          lVar14 = param_1[0xa6];
                        }
                        thunk_EXT_FUN_80110000029486ac
                                  (*(undefined8 *)(lVar14 + 0x148),puVar30,&local_130);
                      }
                      thunk_EXT_FUN_801100000296a2e0(param_7,&local_130);
                      thunk_EXT_FUN_801100000296a2e0(param_7,&local_170);
                      (**(code **)(*(long *)param_1[0x100] + 0x98))
                                ((long *)param_1[0x100],&local_170);
                      thunk_EXT_FUN_801100000294849c
                                (*(undefined8 *)(param_1[0xa6] + 0x148),&local_130,param_7 + 0x175);
                      lVar14 = param_1[0xa6];
                      if ((*(byte *)(lVar14 + 0x1ac45) & 1) != 0) {
                        FUN_fffffff0081a0304
                                  (*(undefined8 *)(lVar14 + 0x148),0x806,&local_130,lVar27);
                        lVar14 = param_1[0xa6];
                      }
                      thunk_EXT_FUN_801100000294849c
                                (*(undefined8 *)(lVar14 + 0x148),&local_170,param_10);
                      thunk_EXT_FUN_801100000294849c
                                (*(undefined8 *)(param_1[0xa6] + 0x148),&local_170,param_8 + 0x49);
                      if ((*(byte *)(param_1[0xa6] + 0x1ac45) & 1) != 0) {
                        FUN_fffffff0081a0304
                                  (*(undefined8 *)(param_1[0xa6] + 0x148),0x806,&local_170,lVar25);
                      }
                      if (puVar24 != (undefined8 *)0x0) {
                        (**(code **)(*(long *)param_1[0x100] + 0x98))
                                  ((long *)param_1[0x100],puVar24);
                      }
                      thunk_EXT_FUN_8011000002969708(param_7,*(undefined8 *)(param_9 + 0x70));
                      FUN_fffffff0081998f8(param_1,param_7,param_9);
                      FUN_fffffff008199dec(param_7,*(undefined8 *)(param_9 + 0x48),0);
                      FUN_fffffff008187004(plVar9);
                      thunk_EXT_FUN_8011000002969708(param_8,*(undefined8 *)(param_9 + 0x70));
                      FUN_fffffff008199eb0(param_1,param_8,param_9,puVar24,param_13);
                      FUN_fffffff008199dec(param_8,*(undefined8 *)(param_9 + 0x48),param_13);
                      if (*(long *)(param_13 + 0x20) != 0) {
                        uVar17 = 0;
                        do {
                          thunk_EXT_FUN_8011000002969884
                                    (param_8,*(undefined8 *)
                                              (*(long *)(*(long *)(param_13 + 0x18) + uVar17 * 8) +
                                              0x28));
                          uVar17 = uVar17 + 1;
                        } while (uVar17 < *(ulong *)(param_13 + 0x20));
                      }
                      FUN_fffffff008187004(plVar19);
                      FUN_fffffff00818af98
                                (*(undefined8 *)(param_1[0xc2] + 0xa8),
                                 *(undefined4 *)(param_2 + 0xc4),param_7 + 0x188,puVar24,lVar27);
                      FUN_fffffff00818af98
                                (*(undefined8 *)(param_1[0xc2] + 0xa8),
                                 *(undefined4 *)(param_2 + 200),param_8 + 0x10,puVar24,lVar25);
                      FUN_fffffff00818ac24
                                (*(undefined8 *)(param_1[0xc2] + 0xa8),
                                 *(undefined4 *)(param_2 + 0xbc),*(undefined4 *)(param_2 + 0xc0));
                      FUN_fffffff00818d240(param_1,param_2,2,param_7 + 0x188,puVar24);
                      FUN_fffffff00818d240(param_1,param_2,3,param_8 + 0x10,puVar24);
                      (**(code **)(*(long *)param_1[0x100] + 0x98))
                                ((long *)param_1[0x100],*param_12);
                      (**(code **)(*(long *)param_1[0x101] + 0x98))
                                ((long *)param_1[0x101],*param_12);
                      (**(code **)(*(long *)param_1[0x100] + 0x98))
                                ((long *)param_1[0x100],*param_11);
                      if (puVar24 != (undefined8 *)0x0) {
                        thunk_EXT_FUN_80110000029486ac
                                  (*(undefined8 *)(plVar19[2] + 0x148),puVar24,plVar19 + 0x23);
                      }
                      lVar14 = param_1[0x108];
                      *(int *)(param_8 + 0x3b) = (int)lVar14;
                      *(int *)(param_1 + 0x108) = (int)lVar14 + 1;
                      iVar3 = *(int *)((long)param_1 + 0x83c);
                      *(int *)(param_7 + 0x20a) = iVar3;
                      *(int *)((long)param_1 + 0x83c) = iVar3 + 1;
                      if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
                        uVar8 = *(undefined4 *)((long)param_7 + 0x814);
                        lVar14 = param_8[0x20];
                        lVar25 = param_1[0x82];
                        FUN_fffffff00817dc48
                                  (param_1[0xa6],0x30c,0,uVar8,lVar25,param_7[0x191],
                                   *(undefined8 *)(param_1[0x100] + 0x30),0);
                        if ((*(byte *)(param_1[0xa6] + 0x1ac44) >> 3 & 1) != 0) {
                          FUN_fffffff00817dc48
                                    (param_1[0xa6],0x30b,0,uVar8,lVar25,lVar14,
                                     *(undefined8 *)(param_1[0x101] + 0x30),0);
                        }
                      }
                      return 1;
                    }
                  }
                }
              }
LAB_fffffff008199638:
              uVar20 = thunk_EXT_FUN_8011000003a49114
                                 (
                                 "AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n"
                                 );
              return uVar20;
            }
            (**(code **)(*param_7 + 0x88))(param_7);
            goto LAB_fffffff008198ec0;
          }
        }
      }
LAB_fffffff008198ed8:
      uVar13 = 8;
      goto LAB_fffffff008197dbc;
    }
  }
  (**(code **)(*param_7 + 0x28))();
  uVar13 = 0x10;
LAB_fffffff008197dbc:
  *(uint *)(param_1 + 0xa4) = uVar13;
  return 0;
}

