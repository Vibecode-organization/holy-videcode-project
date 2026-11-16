/* ==== __Z41CGGlyphBitmapsInfillWithPathAndDilation_8NSt3__14spanIK27CGGlyphIdentifierPathBitmapLm18446744073709551615EEEP6CGFontj6CGSizePK17CGAffineTransform @ 183c0348c size=1488 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __Z41CGGlyphBitmapsInfillWithPathAndDilation_8NSt3__14spanIK27CGGlyphIdentifierPathBitmapLm18446744073709551615EEEP6CGFontj6CGSizePK17CGAffineTransform
               (undefined8 param_1,undefined8 param_2,double param_3,double param_4,uint *param_5,
               uint *param_6,long param_7,undefined8 param_8,ulong param_9)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  long lVar11;
  uint *puVar12;
  undefined1 **ppuVar13;
  undefined1 **ppuVar14;
  long lVar15;
  long lVar16;
  uint *puVar17;
  undefined1 **ppuVar18;
  ulong local_220 [4];
  undefined1 *apuStack_200 [4];
  uint local_1dc;
  uint *local_1d8;
  uint *puStack_1d0;
  ulong local_1c8;
  long local_1c0;
  undefined1 **local_1b8;
  undefined1 *local_1b0;
  undefined1 *puStack_1a8;
  undefined1 *local_1a0;
  undefined1 *puStack_198;
  undefined1 *local_190;
  undefined1 *puStack_188;
  undefined1 *puStack_180;
  undefined1 *puStack_178;
  uint **local_168;
  undefined1 *local_160;
  undefined1 **local_158;
  ulong local_150;
  int local_148;
  undefined8 local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  ulong local_120;
  byte local_118;
  uint *local_110;
  uint *local_108;
  undefined1 auStack_b8 [64];
  long local_78;
  
  local_78 = *_DAT_1e0186220;
  local_110 = param_5;
  local_108 = param_6;
  uVar6 = FUN_183b65c8c(param_7);
  iVar4 = (int)uVar6;
  if (iVar4 < 1) {
    puVar17 = param_5 + (long)param_6 * 6;
    if (param_6 != (uint *)0x0) {
      do {
        param_9 = param_9 & 0xffffffff00000000 | (ulong)*param_5;
        uVar7 = FUN_183b59bd0(param_9,param_8,0,0,0,0,0,0);
        **(undefined8 **)(param_5 + 4) = uVar7;
        param_5 = param_5 + 6;
      } while (param_5 != puVar17);
    }
    goto LAB_183c03a18;
  }
  if (*(int *)(param_7 + 0x68) < 0) {
    iVar5 = (**(code **)(*(long *)(param_7 + 0x10) + 0x90))(*(undefined8 *)(param_7 + 0x70));
    *(int *)(param_7 + 0x68) = iVar5;
    if (iVar5 != 0) goto LAB_183c0350c;
LAB_183c03588:
    uVar7 = 0;
  }
  else {
    if (*(int *)(param_7 + 0x68) == 0) goto LAB_183c03588;
LAB_183c0350c:
    uVar7 = _CGFontGetAutohinter(param_7);
  }
  uVar8 = func_0x00018813a530("CoreGraphics","GlyphNormalization");
  if ((uVar8 & 1) == 0) {
    puVar17 = param_5 + (long)param_6 * 6;
    if (param_6 != (uint *)0x0) {
      do {
        param_6 = (uint *)((ulong)param_6 & 0xffffffff00000000 | (ulong)*param_5);
        uVar10 = __ZL40CGGlyphBitmapCreateWithPathAndDilation_8PK6CGPath17CGGlyphIdentifieriP16CGFontAutohinterj6CGSizePK17CGAffineTransformP8CGRunnerNSt3__14spanI9clipper_tLm18446744073709551615EEENSB_8optionalImEE
                           (param_1,param_2,*(undefined8 *)(param_5 + 2),param_6,uVar6,uVar7,param_8
                            ,param_9,0);
        **(undefined8 **)(param_5 + 4) = uVar10;
        param_5 = param_5 + 6;
      } while (param_5 != puVar17);
    }
  }
  else {
    (**(code **)(*(long *)(param_7 + 0x10) + 0x78))(*(undefined8 *)(param_7 + 0x70));
    FUN_183b1f840();
    puVar17 = (uint *)(long)((param_4 * *(double *)(param_9 + 0x18) +
                             param_3 * *(double *)(param_9 + 8)) /
                            (double)((uVar6 & 0xffffffff) << 4));
    func_0x00018814d370(auStack_b8);
    func_0x00018814d390(auStack_b8,1,1);
    local_1c0 = func_0x00018814d380(auStack_b8,1,0);
    local_1dc = (uint)(puVar17 < param_6);
    local_1c0 = local_1c0 << 10;
    apuStack_200[3] = (undefined1 *)apuStack_200;
    local_1d8 = puVar17;
    puStack_1d0 = param_6;
    uVar6 = (*_DAT_1e1f91910)();
    ppuVar18 = apuStack_200 + uVar6 * -0x80;
    local_1c8 = uVar6;
    local_1b8 = ppuVar18;
    if (uVar6 != 0) {
      ppuVar13 = (undefined1 **)((long)ppuVar18 + local_1c0);
      puStack_188 = (undefined1 *)0x8000000000000000;
      local_190 = (undefined1 *)0x8000000000000000;
      puStack_178 = (undefined1 *)0x7ff8000000000000;
      puStack_180 = (undefined1 *)0x7ff8000000000000;
      puStack_198 = (undefined1 *)0x7fffffffffffffff;
      local_1a0 = (undefined1 *)0x8000000000000000;
      puStack_1a8 = (undefined1 *)0x8000000000000000;
      local_1b0 = (undefined1 *)0x7fffffffffffffff;
      do {
        ppuVar18[0xb] = (undefined1 *)0x0;
        ppuVar18[10] = (undefined1 *)0x0;
        ppuVar18[0xd] = (undefined1 *)0x0;
        ppuVar18[0xc] = (undefined1 *)0x0;
        ppuVar18[7] = (undefined1 *)0x0;
        ppuVar18[6] = (undefined1 *)0x0;
        ppuVar18[9] = (undefined1 *)0x0;
        ppuVar18[8] = (undefined1 *)0x0;
        ppuVar18[3] = (undefined1 *)0x0;
        ppuVar18[2] = (undefined1 *)0x0;
        ppuVar18[5] = (undefined1 *)0x0;
        ppuVar18[4] = (undefined1 *)0x0;
        ppuVar18[1] = (undefined1 *)0x0;
        *ppuVar18 = (undefined1 *)0x0;
        puVar9 = (undefined1 *)func_0x00018814cf90();
        ppuVar18[0xe] = (undefined1 *)(_DAT_1e0181fe0 + 0x10);
        ppuVar18[0x12] = (undefined1 *)0x0;
        ppuVar18[0x13] = puVar9;
        ppuVar18[0x10] = (undefined1 *)0x0;
        ppuVar18[0xf] = (undefined1 *)0x0;
        ppuVar18[0x11] = (undefined1 *)0x400;
        ppuVar18[0x15] = (undefined1 *)0x0;
        ppuVar18[0x14] = (undefined1 *)0x0;
        ppuVar18[0x17] = (undefined1 *)0x0;
        ppuVar18[0x16] = (undefined1 *)0x0;
        ppuVar18[0x19] = (undefined1 *)0x0;
        ppuVar18[0x18] = (undefined1 *)0x0;
        ppuVar18[0x1b] = (undefined1 *)0x0;
        ppuVar18[0x1a] = (undefined1 *)0x0;
        ppuVar18[0x1d] = (undefined1 *)0x0;
        ppuVar18[0x1c] = (undefined1 *)0x0;
        ppuVar18[0x1f] = (undefined1 *)0x0;
        ppuVar18[0x1e] = (undefined1 *)0x0;
        ppuVar18[0x21] = (undefined1 *)0x0;
        ppuVar18[0x20] = (undefined1 *)0x0;
        ppuVar18[0x23] = (undefined1 *)0x0;
        ppuVar18[0x22] = (undefined1 *)0x0;
        ppuVar18[0x25] = (undefined1 *)0x0;
        ppuVar18[0x24] = (undefined1 *)0x0;
        ppuVar18[0x27] = (undefined1 *)0x0;
        ppuVar18[0x26] = (undefined1 *)0x0;
        ppuVar18[0x29] = (undefined1 *)0x0;
        ppuVar18[0x28] = (undefined1 *)0x0;
        ppuVar18[0x2b] = (undefined1 *)0x0;
        ppuVar18[0x2a] = (undefined1 *)0x0;
        ppuVar18[0x2d] = (undefined1 *)0x0;
        ppuVar18[0x2c] = (undefined1 *)0x0;
        ppuVar18[0x2f] = (undefined1 *)0x0;
        ppuVar18[0x2e] = (undefined1 *)0x0;
        ppuVar18[0x31] = (undefined1 *)0x0;
        ppuVar18[0x30] = (undefined1 *)0x0;
        ppuVar18[1] = puStack_178;
        *ppuVar18 = puStack_180;
        ppuVar18[3] = puStack_188;
        ppuVar18[2] = local_190;
        ppuVar18[5] = puStack_178;
        ppuVar18[4] = puStack_180;
        ppuVar18[7] = puStack_198;
        ppuVar18[6] = local_1a0;
        ppuVar18[9] = puStack_188;
        ppuVar18[8] = local_190;
        ppuVar18[0xb] = puStack_1a8;
        ppuVar18[10] = local_1b0;
        ppuVar18[0xd] = (undefined1 *)0x0;
        ppuVar18[0xc] = (undefined1 *)0x0;
        ppuVar18[0x35] = (undefined1 *)0x0;
        ppuVar18[0x34] = (undefined1 *)0x0;
        ppuVar18[0x37] = (undefined1 *)0x0;
        ppuVar18[0x36] = (undefined1 *)0x0;
        ppuVar18[0x39] = (undefined1 *)0x0;
        ppuVar18[0x38] = (undefined1 *)0x0;
        ppuVar18[0x3b] = (undefined1 *)0x0;
        ppuVar18[0x3a] = (undefined1 *)0x0;
        ppuVar18[0x3d] = (undefined1 *)0x0;
        ppuVar18[0x3c] = (undefined1 *)0x0;
        ppuVar18[0x3f] = (undefined1 *)0x0;
        ppuVar18[0x3e] = (undefined1 *)0x0;
        ppuVar18[0x41] = (undefined1 *)0x0;
        ppuVar18[0x40] = (undefined1 *)0x0;
        ppuVar18[0x43] = (undefined1 *)0x0;
        ppuVar18[0x42] = (undefined1 *)0x0;
        ppuVar18[0x45] = (undefined1 *)0x0;
        ppuVar18[0x44] = (undefined1 *)0x0;
        ppuVar18[0x47] = (undefined1 *)0x0;
        ppuVar18[0x46] = (undefined1 *)0x0;
        ppuVar18[0x49] = (undefined1 *)0x0;
        ppuVar18[0x48] = (undefined1 *)0x0;
        ppuVar18[0x4b] = (undefined1 *)0x0;
        ppuVar18[0x4a] = (undefined1 *)0x0;
        ppuVar18[0x4d] = (undefined1 *)0x0;
        ppuVar18[0x4c] = (undefined1 *)0x0;
        ppuVar18[0x4f] = (undefined1 *)0x0;
        ppuVar18[0x4e] = (undefined1 *)0x0;
        ppuVar18[0x51] = (undefined1 *)0x0;
        ppuVar18[0x50] = (undefined1 *)0x0;
        ppuVar18[0x53] = (undefined1 *)0x0;
        ppuVar18[0x52] = (undefined1 *)0x0;
        ppuVar18[0x55] = (undefined1 *)0x0;
        ppuVar18[0x54] = (undefined1 *)0x0;
        ppuVar18[0x57] = (undefined1 *)0x0;
        ppuVar18[0x56] = (undefined1 *)0x0;
        ppuVar18[0x59] = (undefined1 *)0x0;
        ppuVar18[0x58] = (undefined1 *)0x0;
        ppuVar18[0x5b] = (undefined1 *)0x0;
        ppuVar18[0x5a] = (undefined1 *)0x0;
        ppuVar18[0x5d] = (undefined1 *)0x0;
        ppuVar18[0x5c] = (undefined1 *)0x0;
        ppuVar18[0x5f] = (undefined1 *)0x0;
        ppuVar18[0x5e] = (undefined1 *)0x0;
        ppuVar18[0x61] = (undefined1 *)0x0;
        ppuVar18[0x60] = (undefined1 *)0x0;
        ppuVar18[0x62] = (undefined1 *)0x0;
        ppuVar18[0x32] = &DAT_1e22334c0;
        ppuVar18[0x33] = (undefined1 *)0x0;
        *(undefined4 *)(ppuVar18 + 0x34) = 2;
        ppuVar18[0x38] = (undefined1 *)0x0;
        ppuVar18[0x37] = (undefined1 *)0x0;
        puVar9 = (undefined1 *)func_0x00018814cf90();
        ppuVar18[0x39] = (undefined1 *)(_DAT_1e0181fe0 + 0x10);
        ppuVar18[0x3d] = (undefined1 *)0x0;
        ppuVar18[0x3e] = puVar9;
        ppuVar18[0x3b] = (undefined1 *)0x0;
        ppuVar18[0x3a] = (undefined1 *)0x0;
        ppuVar18[0x3c] = (undefined1 *)0x400;
        ppuVar18[0x40] = (undefined1 *)0x0;
        ppuVar18[0x3f] = (undefined1 *)0x0;
        ppuVar18[0x42] = (undefined1 *)0x0;
        ppuVar18[0x41] = (undefined1 *)0x0;
        ppuVar18[0x44] = (undefined1 *)0x0;
        ppuVar18[0x43] = (undefined1 *)0x0;
        ppuVar18[0x47] = (undefined1 *)0x0;
        ppuVar18[0x46] = (undefined1 *)0x0;
        ppuVar18[0x49] = (undefined1 *)0x0;
        ppuVar18[0x48] = (undefined1 *)0x0;
        ppuVar18[0x4b] = (undefined1 *)0x0;
        ppuVar18[0x4a] = (undefined1 *)0x0;
        ppuVar18[0x4d] = (undefined1 *)0x0;
        ppuVar18[0x4c] = (undefined1 *)0x0;
        ppuVar18[0x4f] = (undefined1 *)0x0;
        ppuVar18[0x4e] = (undefined1 *)0x0;
        ppuVar18[0x51] = (undefined1 *)0x0;
        ppuVar18[0x50] = (undefined1 *)0x0;
        ppuVar18[0x53] = (undefined1 *)0x0;
        ppuVar18[0x52] = (undefined1 *)0x0;
        ppuVar18[0x54] = (undefined1 *)0x0;
        *(undefined2 *)(ppuVar18 + 0x55) = 1;
        *(undefined4 *)((long)ppuVar18 + 0x2ac) = 0;
        *(undefined2 *)(ppuVar18 + 0x56) = 0x100;
        ppuVar18[0x5a] = (undefined1 *)0x0;
        ppuVar18[0x59] = (undefined1 *)0x0;
        ppuVar18[0x5c] = (undefined1 *)0x0;
        ppuVar18[0x5b] = (undefined1 *)0x0;
        ppuVar18[0x58] = (undefined1 *)0x0;
        ppuVar18[0x57] = (undefined1 *)0x0;
        puVar9 = (undefined1 *)func_0x00018814cf90();
        ppuVar18[0x5d] = (undefined1 *)(_DAT_1e0181fe0 + 0x10);
        ppuVar18[0x62] = puVar9;
        ppuVar18[0x5f] = (undefined1 *)0x0;
        ppuVar18[0x5e] = (undefined1 *)0x0;
        ppuVar18[0x60] = (undefined1 *)0x400;
        ppuVar18[0x61] = (undefined1 *)0x0;
        ppuVar18[0x32] = &DAT_1e22334a0;
        ppuVar18 = ppuVar18 + 0x80;
      } while (ppuVar18 != ppuVar13);
    }
    puVar17 = local_108;
    ppuVar18 = local_1b8;
    uVar8 = local_1c8;
    local_168 = &local_110;
    local_160 = auStack_b8;
    local_158 = local_1b8;
    local_150 = local_1c8;
    local_138 = (undefined4)param_8;
    local_118 = (byte)local_1dc;
    local_148 = iVar4;
    local_140 = uVar7;
    local_130 = param_1;
    uStack_128 = param_2;
    local_120 = param_9;
    if (local_1d8 < puStack_1d0) {
      func_0x00018814d3a0(local_108,auStack_b8,&local_168,
                          __ZZN8CGRunner3runIZ41CGGlyphBitmapsInfillWithPathAndDilation_8NSt3__14spanIK27CGGlyphIdentifierPathBitmapLm18446744073709551615EEEP6CGFontj6CGSizePK17CGAffineTransformE3__0EEvmNS1_8optionalImEEOT_ENUlPvmmE_8__invokeESH_mm
                         );
    }
    else if (local_108 != (uint *)0x0) {
      puVar12 = (uint *)0x0;
      do {
        if (local_168[1] <= puVar12) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x183c03a58);
          (*pcVar3)();
        }
        puVar1 = *local_168 + (long)puVar12 * 6;
        uVar7 = *(undefined8 *)(puVar1 + 2);
        uVar2 = *puVar1;
        local_220[uVar6 * -0x80 + 2] = 0;
        local_220[uVar6 * -0x80 + 3] = (ulong)local_118;
        local_220[uVar6 * -0x80] = (ulong)local_158;
        local_220[uVar6 * -0x80 + 1] = local_150;
        uVar7 = __ZL40CGGlyphBitmapCreateWithPathAndDilation_8PK6CGPath17CGGlyphIdentifieriP16CGFontAutohinterj6CGSizePK17CGAffineTransformP8CGRunnerNSt3__14spanI9clipper_tLm18446744073709551615EEENSB_8optionalImEE
                          (local_130,uStack_128,uVar7,uVar2,local_148,local_140,local_138,local_120,
                           local_160);
        **(undefined8 **)(puVar1 + 4) = uVar7;
        puVar12 = (uint *)((long)puVar12 + 1);
      } while (puVar17 != puVar12);
    }
    if (uVar8 != 0) {
      ppuVar13 = (undefined1 **)((long)ppuVar18 + local_1c0);
      do {
        __ZN11Clipper2Lib11ClipperBaseD2Ev(ppuVar13 + -0x4e);
        if (ppuVar13[-0x51] != (undefined1 *)0x0) {
          ppuVar13[-0x50] = ppuVar13[-0x51];
          func_0x00018814d0d0();
        }
        ppuVar14 = ppuVar13 + -0x80;
        lVar15 = -0xc0;
        lVar16 = 0x178;
        do {
          lVar16 = lVar16 + -0x18;
          lVar11 = *(long *)((long)ppuVar14 + lVar16);
          if (lVar11 != 0) {
            ((long *)((long)ppuVar14 + lVar16))[1] = lVar11;
            func_0x00018814d0d0();
          }
          lVar15 = lVar15 + 0x18;
        } while (lVar15 != 0);
        if (ppuVar13[-0x6c] != (undefined1 *)0x0) {
          ppuVar13[-0x6b] = ppuVar13[-0x6c];
          func_0x00018814d0d0();
        }
        __ZNSt3__13pmr25monotonic_buffer_resourceD2Ev(ppuVar13 + -0x72);
        ppuVar13 = ppuVar14;
      } while (ppuVar14 != ppuVar18);
    }
    func_0x00018814d360(auStack_b8);
  }
LAB_183c03a18:
  if (*_DAT_1e0186220 != local_78) {
    func_0x000188138130();
    return;
  }
  return;
}



/* ==== __ZL40CGGlyphBitmapCreateWithPathAndDilation_8PK6CGPath17CGGlyphIdentifieriP16CGFontAutohinterj6CGSizePK17CGAffineTransformP8CGRunnerNSt3__14spanI9clipper_tLm18446744073709551615EEENSB_8optionalImEE @ 183c03b24 size=1564 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __ZL40CGGlyphBitmapCreateWithPathAndDilation_8PK6CGPath17CGGlyphIdentifieriP16CGFontAutohinterj6CGSizePK17CGAffineTransformP8CGRunnerNSt3__14spanI9clipper_tLm18446744073709551615EEENSB_8optionalImEE
               (undefined1 param_1 [16],undefined1 param_2 [16],long param_3,uint param_4,
               int param_5,long param_6,ulong param_7,undefined8 *param_8,long param_9,
               undefined8 param_10,long param_11,long param_12,long param_13,long param_14)

{
  ulong uVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 extraout_d0;
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined8 extraout_var;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined8 uVar17;
  undefined8 local_4d0;
  undefined8 uStack_4c8;
  undefined8 uStack_4c0;
  undefined8 uStack_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 uStack_4a0;
  undefined8 uStack_498;
  int *local_490;
  long *local_488;
  undefined8 local_480;
  undefined8 uStack_478;
  code *local_470;
  undefined *puStack_468;
  code *local_460;
  undefined8 *puStack_458;
  long local_80;
  
  uVar17 = param_2._8_8_;
  uVar8 = param_2._0_8_;
  uVar7 = param_1._8_8_;
  auVar14._0_8_ = param_1._0_8_;
  local_80 = *_DAT_1e0186220;
  if ((param_3 != 0) && ((DAT_1edf36408 & 1) == 0)) {
    func_0x000188140d60(param_3);
    FUN_183b3a228();
  }
  auVar13._0_8_ = (long)(param_5 * -100);
  auVar13._8_8_ = (long)(param_5 * 100);
  auVar13 = NEON_scvtf(auVar13,8);
  uStack_4c8 = auVar13._8_8_;
  local_4d0 = auVar13._0_8_;
  uStack_4b8 = 0;
  uStack_4c0 = 0x3ff0000000000000;
  uStack_4a8 = 0x3ff0000000000000;
  local_4b0 = 0;
  uStack_498 = DAT_184158820._8_8_;
  uStack_4a0 = DAT_184158820;
  local_490 = (int *)0x0;
  if (param_9 == 0) {
    local_488 = (long *)_aa_create();
  }
  else {
    local_488 = (long *)__ZN11_aa_state_tnwEmm(0x150,0);
    *(undefined8 *)((long)local_488 + 0xbc) = 0;
    local_488[2] = -0x3ffff0003ffff001;
    local_488[1] = 0x3ffff0013ffff001;
    local_488[0xe] = 0x3fe47ae147ae147c;
    local_488[0xd] = 0x3fe47ae147ae147c;
    local_488[0x10] = 0x3fb23456789abcdf;
    local_488[0xf] = 0x3fb23456789abcdf;
    local_488[0x12] = 0x40b0000000000000;
    local_488[0x11] = 0x40b0000000000000;
    *(undefined4 *)((long)local_488 + 0xc4) = 0;
    local_488[0x14] = 0x3f30000000000000;
    local_488[0x13] = 0x3f30000000000000;
    local_488[0x16] = 0;
    local_488[0x15] = 0x3fe0000000000000;
    local_488[0xc] = 0x410ffff800000000;
    local_488[0xb] = 0x410ffff800000000;
    local_488[10] = -0x3ef0000800000000;
    local_488[9] = -0x3ef0000800000000;
    local_488[6] = 0;
    local_488[5] = 0;
    local_488[8] = 0;
    local_488[7] = 0;
    *(uint *)(local_488 + 0x17) = *(uint *)(local_488 + 0x17) & 0xfc000000;
    local_488[3] = 0;
    local_488[4] = 0;
    local_488[0x1b] = 0;
    local_488[0x1a] = 0;
    local_488[0x1d] = 0;
    local_488[0x1c] = 0;
    *(undefined4 *)(local_488 + 0x1e) = 0;
    *local_488 = (long)&DAT_1e2234290;
    local_488[0x1f] = param_9;
    local_488[0x20] = param_11;
    local_488[0x21] = param_12;
    local_488[0x22] = param_13;
    local_488[0x23] = param_14;
    local_488[0x25] = 0;
    local_488[0x24] = 0;
    local_488[0x27] = 0;
    local_488[0x26] = 0;
    local_488[0x29] = 0;
    local_488[0x28] = 0;
    local_488[0x19] = 0;
  }
  __ZL13aa_free_edgesP11_aa_state_t();
  if (((uint)param_7 & 0xd80) == 0x400) {
    puVar5 = (undefined4 *)func_0x00018814d110(0x38,0x10a0c40cd2b339f);
    *(undefined8 **)(puVar5 + 2) = &local_4d0;
    *(undefined8 *)(puVar5 + 6) = 0x8040000003ed1924;
    *(undefined8 *)(puVar5 + 4) = 0x8010000003ed1908;
    *(undefined8 *)(puVar5 + 10) = 0;
    *(undefined8 *)(puVar5 + 8) = 0;
    *(undefined8 *)(puVar5 + 0xc) = 0;
    *puVar5 = 1;
    local_480 = *param_8;
    uStack_478 = param_8[1];
    puStack_468 = (undefined *)param_8[3];
    local_470 = (code *)param_8[2];
    local_460 = (code *)param_8[4];
    puStack_458 = (undefined8 *)param_8[5];
    auVar14._8_8_ = uVar7;
    FUN_183e198fc(auVar14,uVar8,&local_480,param_7);
    uVar7 = extraout_var;
    if (((param_6 != 0) && ((param_4 & 0xff000000) == 0)) &&
       (auVar15._8_8_ = uVar17, auVar15._0_8_ = uVar8,
       puVar6 = (undefined4 *)_CGFontAutohinterIteratorCreate(auVar15,param_6,param_8,puVar5),
       puVar6 != (undefined4 *)0x0)) {
      __ZN13path_iterator7releaseEv(puVar5);
      puVar5 = puVar6;
    }
    auVar16._8_8_ = uVar7;
    auVar16._0_8_ = extraout_d0;
    uVar7 = _path_iterator_dilator_create(auVar16,uVar8,puVar5);
    __ZN13path_iterator7releaseEv(puVar5);
    uVar8 = _path_iterator_orientation_create(uVar7);
    __ZN13path_iterator7releaseEv(uVar7);
    if (DAT_1eb057fa9 == '\x01') {
      func_0x00018813adf0("\n\nPath BEFORE dilation:\n",0x18,1,*_DAT_1e0186228);
      FUN_183f20160(param_3,0);
      func_0x0001881382e0(&local_480,0x400);
      DAT_1eb058160 = DAT_1eb058160 + 1;
      func_0x00018814d590(&local_480,"*/path_before_dilation.%03d.tiff");
      _CGPathSaveAsImage(param_3,&local_480);
    }
    iVar4 = _path_is_valid(param_3);
    if (iVar4 != 0) {
      __ZNK2CG4Path14apply_iteratorEP13path_iterator(param_3 + 0x10,uVar8);
    }
    __ZN13path_iterator7releaseEv(uVar8);
    if (DAT_1eb057fa9 == '\x01') {
      func_0x00018813adf0("\n\nPath AFTER dilation:\n",0x17,1,*_DAT_1e0186228);
      FUN_183f20160(param_3,0);
      func_0x0001881382e0(&local_480,0x400);
      DAT_1eb058164 = DAT_1eb058164 + 1;
      func_0x00018814d590(&local_480,"*/path_after_dilation.%03d.tiff");
      _CGPathSaveAsImage(param_3,&local_480);
    }
  }
  else {
    if ((param_6 != 0) && ((param_4 & 0xff000000) == 0)) {
      local_490 = (int *)_CGFontAutohinterCreateAutohintTransform(ZEXT816(0),param_6,param_8,0);
    }
    if (param_3 != 0) {
      if ((DAT_1edf36408 & 1) == 0) {
        lVar10 = func_0x000188140d60(param_3);
        lVar11 = FUN_183b3a228();
        if (lVar10 != lVar11) goto LAB_183c03f78;
      }
      local_480 = _DAT_1e0186208;
      uStack_478 = 0x40000000;
      local_470 = ___CGPathApply_block_invoke;
      puStack_468 = &DAT_1e05d9b90;
      puStack_458 = &local_4d0;
      local_460 = __ZL20process_path_elementPvPK13CGPathElement;
      __ZNK2CG4Path5applyEU13block_pointerFv17CGPathElementTypePK7CGPointPbE
                (param_3 + 0x10,&local_480);
    }
  }
LAB_183c03f78:
  plVar3 = local_488;
  lVar10 = 0;
  if (0x1e < (int)local_488[2] - (int)local_488[1]) {
    if (0x1e < *(int *)((long)local_488 + 0x14) - *(int *)((long)local_488 + 0xc)) {
      iVar4 = (int)local_488[1] >> 0xc;
      iVar2 = *(int *)((long)local_488 + 0x14) + 0xfff >> 0xc;
      lVar11 = (long)(((int)local_488[2] + 0xfff >> 0xc) - iVar4);
      lVar12 = (long)(iVar2 - (*(int *)((long)local_488 + 0xc) >> 0xc));
      uVar1 = lVar11 + 0xf;
      lVar10 = FUN_183b59bd0(param_4,(uint)param_7 | 1,iVar4,iVar2,lVar11,lVar12,
                             uVar1 & 0xfffffffffffffff0,0);
      if (lVar10 != 0) {
        uVar9 = 0x22;
        if ((param_7 & 1) != 0) {
          uVar9 = 2;
        }
        (**(code **)(*plVar3 + 0x10))(plVar3,uVar9,lVar10 + 0x28,uVar1 & 0xfffffffffffffff0);
        if (DAT_1eb057fa9 == '\x01') {
          func_0x0001881382e0(&local_480,0x400);
          DAT_1eb058168 = DAT_1eb058168 + 1;
          func_0x00018814d590(&local_480,"*/bitmap_image.%03d.tiff");
          _CGGlyph8BitBitmapSaveAsImage
                    (lVar11,lVar12,uVar1 & 0xfffffffffffffff0,lVar10 + 0x28,&local_480);
        }
      }
    }
  }
  plVar3 = local_488;
  if (local_488 != (long *)0x0) {
    __ZL13aa_free_edgesP11_aa_state_t(local_488);
    (**(code **)(*plVar3 + 0x20))(plVar3);
  }
  if (local_490 != (int *)0x0) {
    iVar4 = *local_490;
    *local_490 = iVar4 + -1;
    if (iVar4 == 1) {
      func_0x000188138390();
    }
  }
  if (lVar10 == 0) {
    lVar10 = FUN_183b59bd0(param_4,param_7,0,0,0,0,0,0);
  }
  if (*_DAT_1e0186220 == local_80) {
    return lVar10;
  }
  lVar10 = func_0x000188138130();
  return lVar10;
}



/* ==== __ZZN8CGRunner3runIZ41CGGlyphBitmapsInfillWithPathAndDilation_8NSt3__14spanIK27CGGlyphIdentifierPathBitmapLm18446744073709551615EEEP6CGFontj6CGSizePK17CGAffineTransformE3$_0EEvmNS1_8optionalImEEOT_ENUlPvmmE_8__invokeESH_mm @ 183c07a5c size=144 ==== */

void __ZZN8CGRunner3runIZ41CGGlyphBitmapsInfillWithPathAndDilation_8NSt3__14spanIK27CGGlyphIdentifierPathBitmapLm18446744073709551615EEEP6CGFontj6CGSizePK17CGAffineTransformE3__0EEvmNS1_8optionalImEEOT_ENUlPvmmE_8__invokeESH_mm
               (long *param_1,ulong param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 in_x7;
  
  if (param_2 < (ulong)((long *)*param_1)[1]) {
    puVar1 = (undefined4 *)(*(long *)*param_1 + param_2 * 0x18);
    if ((char)param_1[10] == '\0') {
      param_3 = 0;
    }
    uVar3 = __ZL40CGGlyphBitmapCreateWithPathAndDilation_8PK6CGPath17CGGlyphIdentifieriP16CGFontAutohinterj6CGSizePK17CGAffineTransformP8CGRunnerNSt3__14spanI9clipper_tLm18446744073709551615EEENSB_8optionalImEE
                      (param_1[7],param_1[8],*(undefined8 *)(puVar1 + 2),*puVar1,(int)param_1[4],
                       param_1[5],(int)param_1[6],param_1[9],param_1[1],in_x7,param_1[2],param_1[3],
                       param_3,(char)param_1[10]);
    **(undefined8 **)(puVar1 + 4) = uVar3;
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x183c07aec);
  (*pcVar2)();
}



