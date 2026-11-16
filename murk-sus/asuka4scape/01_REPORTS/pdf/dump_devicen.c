/* ==== _convert_deviceN @ 183c9f3f8 size=3276 ==== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _convert_deviceN(long param_1,long *param_2,double *param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 *puVar2;
  byte *pbVar3;
  ulong uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  float fVar8;
  bool bVar9;
  long *plVar10;
  double dVar11;
  double dVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  ulong uVar19;
  long lVar20;
  undefined8 uVar21;
  ulong extraout_x1;
  char *pcVar22;
  char *pcVar23;
  int iVar24;
  float fVar25;
  long extraout_x8;
  byte *pbVar26;
  uint uVar27;
  byte *pbVar28;
  byte *pbVar29;
  ulong uVar30;
  ulong uVar31;
  ulong extraout_x12;
  byte *pbVar32;
  double dVar33;
  uint uVar34;
  ulong uVar35;
  long lVar36;
  long lVar37;
  long lVar38;
  double dVar39;
  double dVar40;
  double dVar41;
  float fVar42;
  float fVar43;
  float fVar44;
  float fVar45;
  double dVar46;
  char *local_660 [2];
  undefined8 *******local_650;
  double local_648;
  undefined8 *local_640;
  long local_638;
  double local_630;
  double local_628;
  double *local_620;
  undefined8 local_618;
  long local_610;
  long local_608;
  long local_600;
  long local_5f8;
  long local_5f0;
  double local_5e8;
  uint local_5dc;
  byte *local_5d8;
  ulong local_5d0;
  uint local_5c8;
  uint uStack_5c4;
  uint local_5c0;
  uint local_5bc;
  undefined8 *local_5b8;
  long local_5b0;
  long *local_5a8;
  uint local_59c;
  byte *local_598;
  double dStack_590;
  undefined8 local_588;
  double local_580;
  double local_578;
  byte *local_570;
  undefined8 local_568;
  undefined8 local_560;
  undefined8 uStack_558;
  undefined8 uStack_550;
  undefined8 uStack_548;
  undefined8 local_540;
  undefined8 uStack_538;
  undefined8 local_530;
  undefined8 uStack_528;
  undefined8 local_520;
  undefined8 uStack_518;
  undefined8 local_510;
  undefined8 uStack_508;
  undefined8 local_500;
  undefined8 uStack_4f8;
  undefined8 uStack_4f0;
  undefined8 uStack_4e8;
  undefined8 local_4e0;
  undefined8 uStack_4d8;
  undefined8 uStack_4d0;
  undefined8 uStack_4c8;
  undefined8 local_4c0;
  undefined8 uStack_4b8;
  undefined8 uStack_4b0;
  undefined8 uStack_4a8;
  undefined8 local_4a0;
  ulong uStack_498;
  long local_490;
  undefined8 uStack_488;
  undefined8 uStack_480;
  undefined8 uStack_478;
  undefined8 local_470;
  undefined8 uStack_468;
  undefined8 uStack_460;
  undefined8 uStack_458;
  undefined8 local_450;
  undefined8 uStack_448;
  undefined8 uStack_440;
  undefined8 uStack_438;
  undefined8 local_430;
  undefined8 uStack_428;
  undefined8 uStack_420;
  undefined8 uStack_418;
  undefined8 local_410;
  undefined8 uStack_408;
  undefined8 uStack_400;
  undefined8 uStack_3f8;
  undefined8 local_3f0;
  undefined8 uStack_3e8;
  undefined8 uStack_3e0;
  undefined8 uStack_3d8;
  undefined8 local_3d0;
  undefined8 uStack_3c8;
  undefined8 uStack_3c0;
  undefined8 uStack_3b8;
  undefined8 local_3b0;
  undefined8 uStack_3a8;
  undefined8 uStack_3a0;
  undefined8 uStack_398;
  undefined8 local_390;
  undefined8 uStack_388;
  undefined8 uStack_380;
  undefined8 uStack_378;
  double local_370;
  long lStack_368;
  long local_360;
  double local_358;
  undefined8 local_350;
  undefined8 uStack_348;
  undefined8 uStack_340;
  undefined8 uStack_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined8 uStack_320;
  undefined8 uStack_318;
  undefined8 local_310;
  undefined8 uStack_308;
  undefined8 uStack_300;
  undefined8 uStack_2f8;
  double local_210;
  long lStack_208;
  long local_200;
  long lStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  long local_b0;
  
  local_b0 = *_DAT_1e0186220;
  if (param_1 == 0) {
    pcVar22 = "converter";
    pcVar23 = "converter is NULL";
    local_660[0] = (char *)0x0;
    uVar21 = 0x1224;
    goto LAB_183ca0060;
  }
  lVar38 = *(long *)(param_1 + 0x60);
  local_5b0 = FUN_183ed2f68(lVar38);
  lVar37 = *(long *)(param_1 + 0x20);
  uVar27 = (int)param_2[8] - 1;
  if (uVar27 < 9) {
    local_570 = (byte *)(&DAT_184266e38)[uVar27];
  }
  else {
    local_570 = (byte *)0x0;
  }
  if (lVar37 == 0) {
    local_618 = 0;
  }
  else {
    local_618 = *(undefined8 *)(*(long *)(lVar37 + 0x18) + 0x30);
  }
  local_578 = (double)param_2[7];
  local_610 = param_2[2];
  local_600 = param_2[3];
  local_5d8 = (byte *)*param_2;
  local_5f8 = param_2[1];
  local_628 = param_3[3];
  local_620 = param_3;
  func_0x0001881384d0(&local_210,param_2 + 5,0x130);
  uVar19 = _CGBitmapPixelInfoGetBitsPerPixel(&local_210);
  dVar33 = (double)param_2[6];
  local_5f0 = param_2[2];
  local_5a8 = param_2;
  if (lVar37 == 0) {
LAB_183c9f520:
    local_568 = (ulong)local_568._4_4_ << 0x20;
    if (lVar38 != 0) goto LAB_183c9f528;
LAB_183c9f570:
    uVar27 = 0;
  }
  else {
    lVar20 = func_0x000188140d60(lVar37);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if (lVar20 != DAT_1edf36a20) goto LAB_183c9f520;
    local_568 = CONCAT44(local_568._4_4_,(uint)(*(int *)(*(long *)(lVar37 + 0x18) + 0x18) == 5));
    if (lVar38 == 0) goto LAB_183c9f570;
LAB_183c9f528:
    lVar20 = func_0x000188140d60(lVar38);
    if (DAT_1edf367a0 != -1) {
      func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
    }
    if (lVar20 == DAT_1edf36a20) {
      uVar27 = (uint)(*(int *)(*(long *)(lVar38 + 0x18) + 0x18) == 5);
    }
    else {
      uVar27 = 0;
    }
  }
  plVar10 = local_5a8;
  if (local_5b0 == 0) {
    local_660[0] = "convert_deviceN";
    FUN_183b75268("%s : Unable to complete color conversion");
    uVar21 = 0;
    goto LAB_183c9ffe4;
  }
  uVar7 = *(uint *)(local_5a8 + 5);
  local_660[0] = (char *)(ulong)uVar7;
  local_5dc = uVar27;
  if ((9 < uVar7) || ((1 << (ulong)(uVar7 & 0x1f) & 0x3b6U) == 0)) {
    pcVar22 = 
    "src_component == kCGPixelComponent1BitInteger || src_component == kCGPixelComponent2BitInteger || src_component == kCGPixelComponent4BitInteger || src_component == kCGPixelComponent8BitInteger || src_component == kCGPixelComponent16BitInteger || src_component == kCGPixelComponent16BitFloat || src_component == kCGPixelComponent32BitFloat"
    ;
    pcVar23 = "invalid src component type %u";
    local_660[1] = (char *)0x0;
    uVar21 = 0x1242;
LAB_183ca0060:
                    /* WARNING: Subroutine does not return */
    FUN_183c19214("convert_deviceN",uVar21,
                  "/Library/Caches/com.apple.xbs/418A84E5-A935-45BB-BEF3-31726BD24C5D/TemporaryDirectory.myKecQ/Sources/CoreGraphics/CoreGraphics/Color/CGCMSConverter.c"
                  ,pcVar22,pcVar23);
  }
  uStack_388 = 0;
  local_390 = 0;
  uStack_378 = 0;
  uStack_380 = 0;
  uVar27 = uVar7;
  if (uVar7 - 7 < 3) {
    uVar27 = 1;
  }
  uStack_3a8 = 0;
  local_3b0 = 0;
  uStack_398 = 0;
  uStack_3a0 = 0;
  uStack_3c8 = 0;
  local_3d0 = 0;
  uStack_3b8 = 0;
  uStack_3c0 = 0;
  uStack_3e8 = 0;
  local_3f0 = 0;
  uStack_3d8 = 0;
  uStack_3e0 = 0;
  uStack_408 = 0;
  local_410 = 0;
  uStack_3f8 = 0;
  uStack_400 = 0;
  uStack_428 = 0;
  local_430 = 0;
  uStack_418 = 0;
  uStack_420 = 0;
  uStack_448 = 0;
  local_450 = 0;
  uStack_438 = 0;
  uStack_440 = 0;
  uStack_468 = 0;
  local_470 = 0;
  uStack_458 = 0;
  uStack_460 = 0;
  uStack_488 = 0;
  local_490 = 0;
  uStack_478 = 0;
  uStack_480 = 0;
  uStack_498 = 0;
  local_4a0 = 0;
  uVar21 = _CGPixelComponentGetBitsPerComponent(uVar27);
  if (uVar27 == uVar7) {
    iVar24 = (int)plVar10[8];
    if (iVar24 == 9) {
      iVar24 = 3;
    }
    else if (iVar24 == 8) {
      iVar24 = 1;
    }
  }
  else {
    iVar24 = 0;
  }
  local_660[0] = (char *)plVar10[10];
  local_640 = param_4;
  local_638 = param_1;
  local_580 = dVar33;
  _CGBitmapPixelInfoInitialize
            (&local_4a0,&local_4a0,uVar27,uVar21,local_618,iVar24,
             *(undefined4 *)((long)plVar10 + 0x44),0);
  lVar38 = local_490;
  if ((int)uStack_488 - 1U < 9) {
    lVar36 = (&DAT_184266e38)[(int)uStack_488 - 1U];
    lVar20 = lVar36 + local_490;
  }
  else {
    lVar36 = 0;
    lVar20 = local_490;
  }
  lVar20 = lVar20 * plVar10[1] * (uStack_498 >> 3);
  uVar34 = uVar7 & 0xfffffffe;
  fVar25 = 1.0;
  if (uVar34 != 4) {
    fVar25 = 255.0;
  }
  fVar45 = 65536.0;
  if ((uint)local_568 == 0) {
    fVar45 = 65535.0;
  }
  fVar8 = fVar45;
  if (uVar27 != 2) {
    fVar8 = fVar25;
  }
  lVar1 = lVar20 * local_610 + 1;
  if (0x400 < (ulong)(lVar20 * local_610)) {
    lVar1 = 1;
  }
  (*_DAT_1e1f91910)(lVar1 + 0xfU & 0xfffffffffffffff0);
  dVar33 = (double)((long)&local_650 + -extraout_x8);
  local_630 = dVar33;
  if ((extraout_x12 & 1) == 0) {
    if (extraout_x1 < 0x401) {
      local_588 = (byte *)(CONCAT44(local_588._4_4_,uVar7) & 0xfffffffffffffffe);
      func_0x0001881382e0(dVar33);
      uVar34 = (uint)local_588;
      local_648 = dVar33;
    }
    else {
      local_648 = (double)func_0x000188138460(extraout_x1,1,0x254d75f7);
      if (local_648 == 0.0) goto LAB_183c9f74c;
    }
    fVar25 = 256.0;
    if ((uint)local_568 == 0) {
      fVar25 = 255.0;
    }
    if (uVar27 != 2) {
      fVar45 = 1.0;
    }
    uStack_4b8 = 0;
    local_4c0 = 0;
    uStack_4a8 = 0;
    uStack_4b0 = 0;
    uStack_4d8 = 0;
    local_4e0 = 0;
    uStack_4c8 = 0;
    uStack_4d0 = 0;
    if (uVar27 != 1) {
      fVar25 = fVar45;
    }
    uStack_4f8 = 0;
    local_500 = 0;
    uStack_4e8 = 0;
    uStack_4f0 = 0;
    local_650 = &local_650;
    local_608 = lVar20;
    if ((uint)local_568 != 0) {
      FUN_183c5bf04(&local_500,lVar37);
    }
    local_59c = *(uint *)(local_5a8 + 8);
    bVar17 = local_59c == 2;
    bVar18 = (local_59c & 0xfffffffd) == 4;
    bVar16 = bVar17 || bVar18;
    if (local_5f0 != 0) {
      pbVar3 = local_570 + (long)local_578;
      uVar4 = lVar36 + lVar38;
      uVar5 = local_59c & 0xfffffffb;
      puVar2 = &local_530;
      pbVar32 = pbVar3 + -1;
      uVar35 = uVar4 - 1;
      fVar45 = 100.0;
      if ((uint)local_568 == 0) {
        fVar45 = 1.0;
      }
      local_5bc = 0;
      if (uVar34 == 4) {
        local_5bc = (uint)local_568;
      }
      dVar33 = 0.0;
      if (uVar34 != 4) {
        dVar33 = 0.5;
      }
      local_5c8 = (uint)(local_59c - 3 < 0xfffffffe);
      local_5c0 = local_5c8;
      if (pbVar32 == (byte *)0x0) {
        local_5c0 = 1;
      }
      uStack_5c4 = (uint)local_568 ^ 1;
      if (uVar35 == 0) {
        local_5c8 = 1;
      }
      local_5d0 = 0;
      lVar38 = local_5f8;
      dVar41 = local_648;
      dVar11 = local_648;
      dVar12 = local_648;
      local_5e8 = local_648;
      pbVar13 = local_5d8;
      pbVar14 = local_5d8;
      pbVar15 = local_5d8;
      local_5b8 = puVar2;
      pbVar26 = local_598;
      dVar39 = dStack_590;
      pbVar29 = local_588;
      dVar46 = local_580;
      dVar40 = local_578;
      pbVar28 = local_570;
      lVar37 = local_568;
      if (local_580 != 0.0) {
        local_5d0 = uVar19 / (ulong)local_580;
        lVar38 = local_5f8;
        dVar41 = local_648;
        dVar11 = local_648;
        dVar12 = local_648;
        pbVar13 = local_5d8;
        pbVar14 = local_5d8;
        pbVar15 = local_5d8;
      }
      do {
        while (local_598 = pbVar15, local_570 = pbVar14, local_588 = pbVar13, local_578 = dVar12,
              local_580 = dVar11, dStack_590 = dVar41, local_568 = lVar38, local_568 != 0) {
          uStack_198 = 0;
          local_1a0 = 0;
          uStack_1a8 = 0;
          local_1b0 = 0;
          uStack_1b8 = 0;
          local_1c0 = 0;
          uStack_1c8 = 0;
          local_1d0 = 0;
          uStack_1d8 = 0;
          local_1e0 = 0;
          uStack_1e8 = 0;
          local_1f0 = 0;
          lStack_1f8 = 0;
          local_200 = 0;
          lStack_208 = 0;
          local_210 = 0.0;
          uStack_308 = 0;
          local_310 = 0;
          uStack_2f8 = 0;
          uStack_300 = 0;
          uStack_328 = 0;
          local_330 = 0;
          uStack_318 = 0;
          uStack_320 = 0;
          uStack_348 = 0;
          local_350 = 0;
          uStack_338 = 0;
          uStack_340 = 0;
          lStack_368 = 0;
          local_370 = 0.0;
          local_358 = 0.0;
          local_360 = 0;
          if (pbVar3 == (byte *)0x0) {
            dVar39 = 1.0;
          }
          else {
            pbVar26 = (byte *)0x0;
            uVar30 = 0;
            uVar19 = 0;
            dVar39 = 1.0;
            pbVar29 = local_5d8;
            do {
              uVar34 = (uint)uVar30;
              uStack_528 = uStack_4c8;
              local_530 = uStack_4d0;
              uStack_518 = uStack_4b8;
              local_520 = local_4c0;
              uStack_508 = uStack_4a8;
              local_510 = uStack_4b0;
              fVar42 = 0.0;
              fVar43 = 1.0;
              if (local_5dc != 0) {
                if (pbVar26 == (byte *)0x0) {
                  fVar43 = 100.0;
                }
                else {
                  fVar43 = 1.0;
                  if (pbVar26 < (byte *)0x3) {
                    fVar42 = (float)(double)puVar2[(long)pbVar26 * 2 + -2];
                    fVar43 = (float)(double)puVar2[(long)pbVar26 * 2 + -1];
                  }
                }
              }
              pbVar28 = pbVar29;
              dVar46 = dVar39;
              if ((int)uVar7 < 5) {
                if (uVar7 == 1) {
                  uVar34 = (uint)local_588[(long)pbVar26];
                }
                else {
                  if (uVar7 != 2) {
                    if (uVar7 != 4) goto LAB_183c9fb6c;
                    bVar9 = pbVar26 == (byte *)0x0 && bVar16;
                    fVar44 = *(float *)(local_598 + (long)pbVar26 * 4);
                    goto LAB_183c9fb30;
                  }
                  uVar34 = (uint)*(ushort *)(local_570 + (long)pbVar26 * 2);
                }
                bVar9 = pbVar26 == (byte *)0x0 && bVar16;
                fVar44 = (float)NEON_ucvtf(uVar34);
LAB_183c9fb30:
                dVar46 = (double)(fVar42 + ((fVar43 - fVar42) * fVar44) / fVar8);
LAB_183c9fb44:
                pbVar29 = pbVar28;
                if ((!bVar9) && (uVar5 != 1 || pbVar32 != pbVar26)) {
LAB_183c9fb58:
                  (&local_210)[(long)pbVar26] = dVar46;
                  pbVar29 = pbVar28;
                  dVar46 = dVar39;
                }
              }
              else {
                if ((int)uVar7 < 8) {
                  if (uVar7 == 5) {
                    bVar9 = pbVar26 == (byte *)0x0 && bVar16;
                    fVar44 = (float)*(float2 *)(local_570 + (long)pbVar26 * 2);
                    goto LAB_183c9fb30;
                  }
                  if (uVar7 != 7) goto LAB_183c9fb6c;
                  if (uVar34 == 0) {
                    pbVar28 = pbVar29 + 1;
                    uVar19 = (ulong)*pbVar29 | uVar19 << 8;
                    uVar34 = 8;
                  }
                  uVar30 = (ulong)(uVar34 - 1);
                  if ((uVar19 >> (uVar30 & 0x3f) & 1) == 0) {
                    dVar46 = 0.0;
                  }
                  else {
                    dVar46 = (double)(fVar42 + ((fVar43 - fVar42) * 255.0) / fVar8);
                  }
                  bVar9 = pbVar26 == (byte *)0x0 && bVar16;
                  goto LAB_183c9fb44;
                }
                if (uVar7 == 8) {
                  if (uVar34 < 2) {
                    pbVar28 = pbVar29 + 1;
                    uVar19 = (ulong)*pbVar29 | uVar19 << 8;
                    uVar34 = uVar34 | 8;
                  }
                  uVar30 = (ulong)(uVar34 - 2);
                  uVar31 = uVar19 >> (uVar30 & 0x3f);
                  if ((uVar31 & 3) == 0) {
                    dVar46 = 0.0;
                  }
                  else {
                    dVar46 = (double)(fVar42 + ((fVar43 - fVar42) *
                                               (float)(((uint)uVar31 & 3) * 0x55)) / fVar8);
                  }
                  pbVar29 = pbVar28;
                  if ((pbVar26 == (byte *)0x0 && (bVar17 || bVar18)) ||
                     (uVar5 == 1 && pbVar32 == pbVar26)) goto LAB_183c9fb6c;
                  goto LAB_183c9fb58;
                }
                if (uVar7 == 9) {
                  if (uVar34 < 4) {
                    pbVar28 = pbVar29 + 1;
                    uVar19 = (ulong)*pbVar29 | uVar19 << 8;
                    uVar34 = uVar34 | 8;
                  }
                  uVar30 = (ulong)(uVar34 - 4);
                  uVar31 = uVar19 >> (uVar30 & 0x3f);
                  uVar34 = (uint)uVar31 & 0xf;
                  if ((uVar31 & 0xf) == 0) {
                    dVar46 = 0.0;
                  }
                  else {
                    dVar46 = (double)(fVar42 + ((fVar43 - fVar42) * (float)(uVar34 | uVar34 << 4)) /
                                               fVar8);
                  }
                  pbVar29 = pbVar28;
                  if ((pbVar26 != (byte *)0x0 || !bVar17 && !bVar18) &&
                     (uVar5 != 1 || pbVar32 != pbVar26)) goto LAB_183c9fb58;
                }
              }
LAB_183c9fb6c:
              dVar39 = dVar46;
              pbVar26 = pbVar26 + 1;
              local_560 = local_500;
              uStack_558 = uStack_4f8;
              uStack_550 = uStack_4f0;
              uStack_548 = uStack_4e8;
              local_540 = local_4e0;
              uStack_538 = uStack_4d8;
            } while (pbVar3 != pbVar26);
          }
          if ((local_5c0 & 1) == 0) {
            lVar37 = 0;
            pbVar26 = pbVar32;
            do {
              if (dVar39 == 0.0) {
                (&local_210)[lVar37] = 0.0;
              }
              else if (dVar39 != 1.0) {
                (&local_210)[lVar37] = (&local_210)[lVar37] / dVar39;
              }
              lVar37 = lVar37 + 1;
              pbVar26 = pbVar26 + -1;
            } while (pbVar26 != (byte *)0x0);
          }
          lVar37 = local_5a8[10];
          if (lVar37 != 0) {
            pbVar26 = pbVar32;
            if (((6 < local_59c) || ((1 << (ulong)(local_59c & 0x1f) & 0x54U) == 0)) && (uVar5 != 1)
               ) {
              pbVar26 = pbVar3;
            }
            if (pbVar26 != (byte *)0x0) {
              lVar38 = 0;
              do {
                fVar43 = (float)*(double *)(lVar37 + lVar38 * 0x10);
                dVar40 = ((&local_210)[lVar38] - (double)fVar43) /
                         (double)((float)*(double *)(lVar37 + (lVar38 << 4 | 8U)) - fVar43);
                dVar46 = 1.0;
                if (dVar40 <= 1.0) {
                  dVar46 = (double)(float)(dVar40 + 0.0);
                }
                dVar41 = 0.0;
                if (0.0 <= dVar40) {
                  dVar41 = dVar46;
                }
                (&local_210)[lVar38] = dVar41;
                lVar38 = lVar38 + 1;
                pbVar26 = pbVar26 + -1;
              } while (pbVar26 != (byte *)0x0);
            }
          }
          FUN_183b7ffbc(local_5b0,&local_210,&local_370);
          if ((local_5c8 & 1) == 0) {
            lVar37 = 0;
            uVar19 = uVar35;
            do {
              if (dVar39 == 0.0) {
                (&local_370)[lVar37] = 0.0;
              }
              else if (dVar39 != 1.0) {
                (&local_370)[lVar37] = dVar39 * (&local_370)[lVar37];
              }
              lVar37 = lVar37 + 1;
              uVar19 = uVar19 - 1;
            } while (uVar19 != 0);
          }
          if (uVar4 != 0) {
            uVar19 = 0;
            dVar46 = dVar39 * (double)fVar25 + dVar33;
            fVar43 = fVar8;
            if (dVar46 <= (double)fVar8) {
              fVar43 = (float)dVar46;
            }
            fVar42 = 0.0;
            if (0.0 <= dVar46) {
              fVar42 = fVar43;
            }
            do {
              if (local_5bc == 0) {
                fVar43 = fVar42;
                if ((uVar5 != 1 || uVar35 != uVar19) && (uVar19 != 0 || !bVar17 && !bVar18)) {
                  uStack_538 = uStack_4d8;
                  local_540 = local_4e0;
                  uStack_528 = uStack_4c8;
                  local_530 = uStack_4d0;
                  uStack_518 = uStack_4b8;
                  local_520 = local_4c0;
                  uStack_508 = uStack_4a8;
                  local_510 = uStack_4b0;
                  uVar34 = uStack_5c4;
                  if (uVar19 == 0) {
                    uVar34 = 1;
                  }
                  uStack_558 = uStack_4f8;
                  local_560 = local_500;
                  uStack_548 = uStack_4e8;
                  uStack_550 = uStack_4f0;
                  fVar44 = 0.0;
                  fVar43 = fVar45;
                  if (((uVar34 & 1) == 0) && (fVar43 = 1.0, uVar19 < 3)) {
                    fVar44 = (float)(double)local_5b8[uVar19 * 2 + -2];
                    fVar43 = (float)(double)local_5b8[uVar19 * 2 + -1];
                  }
                  dVar46 = (((&local_370)[uVar19] - (double)fVar44) * (double)fVar25) /
                           (double)(fVar43 - fVar44) + dVar33;
                  fVar44 = fVar8;
                  if (dVar46 <= (double)fVar8) {
                    fVar44 = (float)dVar46;
                  }
                  fVar43 = 0.0;
                  if (0.0 <= dVar46) {
                    fVar43 = fVar44;
                  }
                }
              }
              else {
                fVar43 = (float)dVar39;
                if ((uVar5 != 1 || uVar35 != uVar19) && (uVar19 != 0 || !bVar17 && !bVar18)) {
                  fVar43 = (float)(&local_370)[uVar19];
                }
              }
              if (uVar27 == 1) {
                *(char *)((long)dStack_590 + uVar19) = (char)(int)fVar43;
              }
              else if (uVar27 == 2) {
                *(short *)((long)local_578 + uVar19 * 2) = (short)(int)fVar43;
              }
              else if (uVar27 == 4) {
                *(float *)((long)local_580 + uVar19 * 4) = fVar43;
              }
              else if (uVar27 == 5) {
                *(float2 *)((long)local_578 + uVar19 * 2) = (float2)fVar43;
              }
              uVar19 = uVar19 + 1;
            } while (uVar4 != uVar19);
          }
          puVar2 = local_5b8;
          dVar41 = (double)((long)dStack_590 + uVar4);
          dVar11 = (double)((long)local_580 + uVar4 * 4);
          dVar12 = (double)((long)local_578 + uVar4 * 2);
          pbVar13 = local_588 + local_5d0;
          pbVar14 = local_570 + local_5d0 * 2;
          pbVar15 = local_598 + local_5d0 * 4;
          pbVar26 = local_598;
          dVar39 = dStack_590;
          pbVar29 = local_588;
          dVar46 = local_580;
          dVar40 = local_578;
          pbVar28 = local_570;
          lVar37 = local_568;
          lVar38 = local_568 + -1;
        }
        local_5d8 = local_5d8 + local_600;
        local_5e8 = (double)((long)local_5e8 + local_608);
        local_5f0 = local_5f0 + -1;
        local_598 = pbVar26;
        dStack_590 = dVar39;
        local_588 = pbVar29;
        local_580 = dVar46;
        local_578 = dVar40;
        local_570 = pbVar28;
        local_568 = lVar37;
        lVar38 = local_5f8;
        dVar41 = local_5e8;
        dVar11 = local_5e8;
        dVar12 = local_5e8;
        pbVar13 = local_5d8;
        pbVar14 = local_5d8;
        pbVar15 = local_5d8;
      } while (local_5f0 != 0);
    }
    lVar20 = local_5f8;
    lVar38 = local_610;
    dVar33 = local_648;
    local_1f0 = 0;
    local_350 = 0;
    local_210 = local_648;
    lStack_208 = local_5f8;
    local_200 = local_610;
    lStack_1f8 = local_608;
    func_0x0001881384d0(&uStack_1e8,&local_4a0,0x130);
    lVar37 = local_638;
    local_1c0 = 0;
    uStack_1d8 = local_618;
    uVar6 = *(undefined4 *)(local_638 + 0x54);
    local_370 = *local_620;
    local_1f0 = CONCAT44(local_1f0._4_4_,uVar6);
    lStack_368 = lVar20;
    local_360 = lVar38;
    local_358 = local_628;
    func_0x0001881384d0(&uStack_348,local_620 + 5,0x130);
    local_350 = CONCAT44(local_350._4_4_,uVar6);
    uStack_538 = local_640[5];
    local_540 = local_640[4];
    uStack_528 = local_640[7];
    local_530 = local_640[6];
    uStack_518 = local_640[9];
    local_520 = local_640[8];
    local_510 = local_640[10];
    uStack_558 = local_640[1];
    local_560 = *local_640;
    uStack_548 = local_640[3];
    uStack_550 = local_640[2];
    uVar21 = (**(code **)(lVar37 + 0x68))(lVar37,&local_210,&local_370,&local_560);
    if (dVar33 != local_630) {
      func_0x000188138390(dVar33);
    }
  }
  else {
LAB_183c9f74c:
    *(char **)((long)local_660 + -extraout_x8) = "convert_deviceN";
    FUN_183b75268("%s : Unable to allocate");
    uVar21 = 0;
  }
LAB_183c9ffe4:
  if (*_DAT_1e0186220 == local_b0) {
    return uVar21;
  }
  uVar21 = func_0x000188138130();
  return uVar21;
}



/* ==== _deviceN_converter_info @ 183ca00c8 size=472 ==== */

void _deviceN_converter_info(long *param_1,long param_2,undefined8 *param_3,undefined8 param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  undefined1 auStack_310 [344];
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  long local_1a0;
  undefined8 local_198;
  int local_190;
  undefined4 local_18c;
  ulong local_188;
  long lStack_180;
  int local_178;
  undefined4 local_174;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  
  local_198 = 0;
  iVar2 = *(int *)(param_3 + 5);
  if (*(long *)(param_2 + 0x20) == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(long *)(*(long *)(*(long *)(param_2 + 0x20) + 0x18) + 0x30);
  }
  iVar1 = iVar2;
  if (iVar2 - 7U < 3) {
    iVar1 = 1;
  }
  local_188 = _CGPixelComponentGetBitsPerComponent(iVar1);
  if (iVar1 != iVar2) {
    local_178 = 0;
    lVar5 = 0;
    local_174 = *(undefined4 *)((long)param_3 + 0x44);
    lVar3 = param_3[1];
    goto LAB_183ca0180;
  }
  local_178 = *(int *)(param_3 + 8);
  if (local_178 == 9) {
    local_178 = 3;
LAB_183ca0168:
    local_174 = *(undefined4 *)((long)param_3 + 0x44);
    lVar3 = param_3[1];
    uVar4 = local_178 - 1;
  }
  else {
    if (local_178 == 8) {
      local_178 = 1;
      goto LAB_183ca0168;
    }
    local_174 = *(undefined4 *)((long)param_3 + 0x44);
    lVar3 = param_3[1];
    uVar4 = local_178 - 1;
    if (8 < uVar4) {
      lVar5 = 0;
      goto LAB_183ca0180;
    }
  }
  lVar5 = (&DAT_184266e38)[uVar4];
LAB_183ca0180:
  uStack_1a8 = param_3[2];
  local_1b0 = param_3[1];
  local_1b8 = *param_3;
  local_1a0 = (lVar5 + lVar6) * lVar3 * (local_188 >> 3);
  local_18c = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_68 = 0;
  local_70 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  local_198 = CONCAT44(local_198._4_4_,*(undefined4 *)(param_2 + 0x54));
  param_1[2] = 0;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  local_190 = iVar1;
  lStack_180 = lVar6;
  lVar6 = _CGCMSConverterCreateCachedCGvImageConverter(param_2,&local_1b8,param_4);
  *param_1 = lVar6;
  if (lVar6 != 0) {
    func_0x0001881384d0(auStack_310,param_4,0x158);
    lVar6 = _CGvImageConverterGetBufferSize(lVar6,&local_1b8,auStack_310);
    param_1[2] = lVar6;
  }
  return;
}



/* ==== _deviceN_finalize @ 183ed3070 size=412 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183ed309c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x000183ed3174: Changing call to branch */

void _deviceN_finalize(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x28) == 0) {
    plVar4 = *(long **)(param_1 + 0x60);
    if (plVar4 == (long *)0x0) {
      return;
    }
    lVar3 = plVar4[1];
    if (lVar3 != 0) {
      lVar2 = func_0x000188140d60(lVar3);
      if (DAT_1edf367a0 != -1) {
        func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
      }
      if (lVar2 == DAT_1edf36a20) {
        func_0x000188141240(lVar3);
      }
    }
    if (plVar4[2] != 0) {
      func_0x000188141240();
    }
    if (plVar4[3] == 0) {
      if (*plVar4 == 0) {
        return;
      }
      if (*(long *)(param_1 + 0x30) != 0) {
        uVar5 = 0;
        do {
          func_0x000188138390(*(undefined8 *)(*plVar4 + uVar5 * 8));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(ulong *)(param_1 + 0x30));
      }
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0x183ed31d4);
        (*pcVar1)();
      }
    }
    else if (*(long *)(param_1 + 0x30) != 0) {
      uVar5 = 0;
      do {
        lVar3 = *(long *)(plVar4[3] + uVar5 * 8);
        if (lVar3 != 0) {
          lVar2 = func_0x000188140d60(lVar3);
          if (DAT_1edf367a0 != -1) {
            func_0x00018813aad0(&DAT_1edf367a0,&DAT_1e22309c8);
          }
          if (lVar2 == DAT_1edf36a20) {
            func_0x000188141240(lVar3);
          }
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(ulong *)(param_1 + 0x30));
    }
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* ==== _deviceN_get_descriptor @ 183ed320c size=8 ==== */

undefined8 _deviceN_get_descriptor(long param_1)

{
  return *(undefined8 *)(param_1 + 0x60);
}



