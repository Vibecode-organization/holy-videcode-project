/* ==== __blt_shade_initialize @ 183b8057c size=1248 ==== */

undefined8 __blt_shade_initialize(long param_1,uint *param_2,undefined8 *param_3,float *param_4)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  double dVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined4 uVar11;
  float *pfVar12;
  uint uVar13;
  int iVar14;
  undefined1 uVar15;
  undefined1 uVar16;
  undefined1 uVar17;
  undefined1 uVar18;
  char cVar19;
  undefined1 uVar20;
  char cVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  ushort uVar24;
  float fVar25;
  int iVar26;
  int iVar30;
  int iVar31;
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  float fVar32;
  float fVar33;
  int iVar34;
  int iVar35;
  double dVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  float fVar42;
  ulong uVar43;
  ulong uVar44;
  float fVar45;
  float fVar46;
  float fVar47;
  float fVar48;
  double dVar49;
  double dVar50;
  float fVar51;
  undefined1 auVar52 [16];
  float fVar53;
  
  pfVar12 = *(float **)(param_2 + 10);
  fVar46 = *pfVar12;
  fVar32 = pfVar12[1];
  fVar47 = pfVar12[2];
  fVar48 = pfVar12[3];
  dVar36 = -(double)fVar47 * (double)fVar32 + (double)fVar46 * (double)fVar48;
  if (dVar36 == 0.0) {
    return 0xffffffff;
  }
  dVar36 = 1.0 / dVar36;
  param_3[0x24] = __blt_shade_constants;
  auVar27._0_8_ = (double)fVar47 * dVar36;
  auVar27._8_8_ = (double)fVar48 * dVar36;
  dVar4 = (double)fVar46 * dVar36;
  dVar36 = (double)fVar32 * dVar36;
  uVar15 = (undefined1)((ulong)dVar36 >> 8);
  uVar16 = (undefined1)((ulong)dVar36 >> 0x10);
  uVar17 = (undefined1)((ulong)dVar36 >> 0x18);
  uVar18 = (undefined1)((ulong)dVar36 >> 0x20);
  uVar20 = (undefined1)((ulong)dVar36 >> 0x28);
  uVar22 = (undefined1)((ulong)dVar36 >> 0x30);
  uVar23 = (undefined1)((ulong)dVar36 >> 0x38);
  auVar29[8] = SUB81(dVar36,0);
  auVar29._0_8_ = dVar4;
  auVar29[9] = uVar15;
  auVar29[10] = uVar16;
  auVar29[0xb] = uVar17;
  auVar29[0xc] = uVar18;
  auVar29[0xd] = uVar20;
  auVar29[0xe] = uVar22;
  auVar29[0xf] = uVar23;
  fVar32 = (float)dVar4;
  fVar46 = -(float)auVar29._8_8_;
  fVar47 = -(float)auVar27._0_8_;
  fVar48 = -(float)auVar27._8_8_;
  uVar43 = CONCAT44((float)auVar29._8_8_,fVar32) & 0x7fffffff7fffffff;
  uVar44 = CONCAT44((float)auVar27._8_8_,(float)auVar27._0_8_) & 0x7fffffff7fffffff;
  dVar49 = (double)(float)*(undefined8 *)(pfVar12 + 4);
  dVar50 = (double)(float)((ulong)*(undefined8 *)(pfVar12 + 4) >> 0x20);
  auVar52[8] = SUB81(dVar36,0);
  auVar52._0_8_ = dVar4;
  auVar52[9] = uVar15;
  auVar52[10] = uVar16;
  auVar52[0xb] = uVar17;
  auVar52[0xc] = uVar18;
  auVar52[0xd] = uVar20;
  auVar52[0xe] = uVar22;
  auVar52[0xf] = uVar23;
  auVar52 = NEON_ext(auVar52,auVar27,8,1);
  auVar28._0_8_ = -dVar49;
  auVar28._8_8_ = -dVar50;
  auVar29 = NEON_ext(auVar28,auVar28,8,1);
  dVar36 = dVar4 * auVar29._0_8_ + dVar49 * auVar52._0_8_;
  dVar4 = auVar27._8_8_ * auVar29._8_8_ + dVar50 * auVar52._8_8_;
  *(float *)(param_3 + 0x25) = (float)auVar27._8_8_;
  auVar9._4_4_ = fVar46;
  auVar9._0_4_ = -fVar32;
  auVar9._8_4_ = fVar47;
  auVar9._12_4_ = fVar48;
  auVar10._4_4_ = fVar46;
  auVar10._0_4_ = -fVar32;
  auVar10._8_4_ = fVar47;
  auVar10._12_4_ = fVar48;
  auVar29 = NEON_ext(auVar9,auVar10,4,1);
  auVar2[8] = SUB81(dVar4,0);
  auVar2._0_8_ = dVar36;
  auVar2[9] = (char)((ulong)dVar4 >> 8);
  auVar2[10] = (char)((ulong)dVar4 >> 0x10);
  auVar2[0xb] = (char)((ulong)dVar4 >> 0x18);
  auVar2[0xc] = (char)((ulong)dVar4 >> 0x20);
  auVar2[0xd] = (char)((ulong)dVar4 >> 0x28);
  auVar2[0xe] = (char)((ulong)dVar4 >> 0x30);
  auVar2[0xf] = (char)((ulong)dVar4 >> 0x38);
  fVar46 = (float)dVar36;
  *(long *)((long)param_3 + 300) = auVar29._0_8_;
  *(ulong *)((long)param_3 + 0x134) = CONCAT44((float)auVar2._8_8_,fVar32);
  *(float *)((long)param_3 + 0x13c) = fVar46;
  uVar24 = NEON_umaxv(CONCAT26(-(ushort)(0x7f7fffff < (uint)(uVar44 >> 0x20)),
                               CONCAT24(-(ushort)(0x7f7fffff < (uint)uVar44),
                                        CONCAT22(-(ushort)(0x7f7fffff < (uint)(uVar43 >> 0x20)),
                                                 -(ushort)(0x7f7fffff < (uint)uVar43)))),2);
  if ((uVar24 & 1) != 0) {
    return 0xffffffff;
  }
  if (0x7f7fffff < (int)ABS((float)auVar2._8_8_)) {
    return 0xffffffff;
  }
  if (0x7f7fffff < (int)ABS(fVar46)) {
    return 0xffffffff;
  }
  pfVar12 = *(float **)(param_2 + 8);
  if (pfVar12 == (float *)0x0) {
    *(undefined4 *)(param_3 + 0x29) = 0;
    param_3[0x28] = 0x3f80000000000000;
    fVar46 = 0.0;
    uVar15 = 0;
    uVar16 = 0;
    uVar17 = 0x80;
    uVar18 = 0x3f;
    fVar32 = 1.0;
  }
  else {
    fVar46 = *pfVar12;
    *(float *)(param_3 + 0x28) = fVar46;
    fVar32 = pfVar12[1];
    uVar15 = SUB41(fVar32,0);
    uVar16 = (undefined1)((uint)fVar32 >> 8);
    uVar17 = (undefined1)((uint)fVar32 >> 0x10);
    uVar18 = (undefined1)((uint)fVar32 >> 0x18);
    *(float *)((long)param_3 + 0x144) = fVar32;
    *(float *)(param_3 + 0x29) = pfVar12[2];
    fVar32 = pfVar12[3];
  }
  *(float *)((long)param_3 + 0x14c) = fVar32;
  param_3[0x2f] = 0;
  uVar1 = param_2[0xc];
  dVar36 = (double)NEON_ucvtf((ulong)param_2[0xd]);
  pfVar12 = *(float **)(param_2 + 0xe);
  if (pfVar12 == (float *)0x0) {
    *(undefined4 *)((long)param_3 + 0x16c) = 0;
    fVar32 = (float)((double)uVar1 + -0.00390625);
    *(float *)(param_3 + 0x2d) = fVar32;
    param_3[0x2c] = 0x3f80000000000000;
    *(float *)((long)param_3 + 0x174) = (float)(dVar36 + -0.00390625);
    fVar48 = 1.0;
    fVar47 = 0.0;
  }
  else {
    fVar32 = (float)(((double)uVar1 + -0.00390625) / (double)(pfVar12[1] - *pfVar12));
    *(float *)(param_3 + 0x2d) = fVar32;
    fVar47 = *pfVar12;
    *(float *)(param_3 + 0x2c) = fVar47;
    *(float *)((long)param_3 + 0x164) = pfVar12[1];
    *(float *)((long)param_3 + 0x174) =
         (float)((dVar36 + -0.00390625) / (double)(pfVar12[3] - pfVar12[2]));
    *(float *)((long)param_3 + 0x16c) = pfVar12[2];
    fVar48 = pfVar12[3];
  }
  *(float *)(param_3 + 0x2e) = fVar48;
  param_3[0x2b] = 0xffffffffffffffff;
  if ((*(byte *)((long)param_2 + 3) >> 4 & 1) == 0) {
    iVar14 = -1;
LAB_183b8078c:
    *(int *)(param_3 + 0x2a) = iVar14;
  }
  else {
    uVar13 = (uint)(fVar32 * (fVar46 - fVar47));
    *(uint *)(param_3 + 0x2a) = uVar13;
    if ((int)uVar13 < 0) {
      *(undefined4 *)(param_3 + 0x2a) = 0;
    }
    else if (uVar1 <= uVar13) {
      iVar14 = uVar1 - 1;
      goto LAB_183b8078c;
    }
  }
  if ((*(byte *)((long)param_2 + 3) >> 5 & 1) == 0) {
    iVar14 = -1;
LAB_183b807c0:
    *(int *)((long)param_3 + 0x154) = iVar14;
  }
  else {
    uVar13 = (uint)(fVar32 * ((float)CONCAT13(uVar18,CONCAT12(uVar17,CONCAT11(uVar16,uVar15))) -
                             fVar47));
    *(uint *)((long)param_3 + 0x154) = uVar13;
    if ((int)uVar13 < 0) {
      *(undefined4 *)((long)param_3 + 0x154) = 0;
    }
    else if (uVar1 <= uVar13) {
      iVar14 = uVar1 - 1;
      goto LAB_183b807c0;
    }
  }
  uVar5 = *(undefined8 *)(param_2 + 0x10);
  param_3[0x33] = *(undefined8 *)(param_2 + 0x12);
  param_3[0x32] = uVar5;
  param_3[0x31] = 0;
  if (*(float **)(param_2 + 4) == (float *)0x0) {
    param_4 = (float *)0x0;
  }
  else {
    fVar46 = **(float **)(param_2 + 4);
    *param_4 = fVar46;
    fVar25 = *(float *)(*(long *)(param_2 + 4) + 8);
    param_4[1] = fVar25;
    fVar33 = *(float *)(*(long *)(param_2 + 4) + 4);
    param_4[2] = fVar33;
    fVar32 = fVar25 - fVar46;
    fVar48 = -(fVar32 * fVar32) + fVar33 * fVar33;
    fVar47 = fVar46 * -2.0 * fVar32;
    param_4[5] = fVar48;
    param_4[6] = fVar47;
    fVar45 = fVar46 * fVar46;
    fVar42 = 0.0;
    if (fVar48 != 0.0) {
      fVar42 = 1.0 / (fVar48 + fVar48);
    }
    param_4[7] = fVar45;
    param_4[8] = fVar42;
    if (*param_2 >> 0x1c == 0) {
      param_4[3] = 0.0;
      param_4[4] = 1.0;
    }
    else {
      fVar53 = 3.4028235e+38;
      if (fVar25 < fVar46) {
        fVar53 = 1.0 - fVar25 / fVar32;
      }
      fVar51 = -3.4028235e+38;
      if (fVar46 < fVar25) {
        fVar53 = 3.4028235e+38;
        fVar51 = -fVar46 / fVar32;
      }
      fVar32 = 0.0;
      if ((*param_2 & 0x10000000) != 0) {
        fVar32 = fVar51;
      }
      param_4[3] = fVar32;
      fVar51 = 1.0;
      if ((*param_2 & 0x20000000) != 0) {
        fVar51 = fVar53;
      }
      param_4[4] = fVar51;
      fVar47 = ABS(fVar47);
      iVar34 = -(uint)(INFINITY < ABS(fVar46));
      iVar37 = -(uint)(INFINITY < ABS(fVar25));
      iVar39 = -(uint)(INFINITY < ABS(fVar33));
      iVar41 = -(uint)(INFINITY < ABS(fVar32));
      iVar14 = -(uint)(ABS(fVar46) < INFINITY);
      iVar6 = -(uint)(ABS(fVar25) < INFINITY);
      iVar7 = -(uint)(ABS(fVar33) < INFINITY);
      iVar8 = -(uint)(ABS(fVar32) < INFINITY);
      iVar35 = -(uint)(INFINITY < ABS(fVar51));
      iVar38 = -(uint)(INFINITY < ABS(fVar48));
      iVar40 = -(uint)(INFINITY < fVar47);
      iVar26 = -(uint)(ABS(fVar51) < INFINITY);
      iVar30 = -(uint)(ABS(fVar48) < INFINITY);
      iVar31 = -(uint)(fVar47 < INFINITY);
      auVar3[1] = ~((byte)((uint)iVar14 >> 8) | (byte)((uint)iVar34 >> 8));
      auVar3[0] = ~((byte)iVar14 | (byte)iVar34);
      auVar3[2] = ~((byte)iVar6 | (byte)iVar37);
      auVar3[3] = ~((byte)((uint)iVar6 >> 8) | (byte)((uint)iVar37 >> 8));
      auVar3[4] = ~((byte)iVar7 | (byte)iVar39);
      auVar3[5] = ~((byte)((uint)iVar7 >> 8) | (byte)((uint)iVar39 >> 8));
      auVar3[6] = ~((byte)iVar8 | (byte)iVar41);
      auVar3[7] = ~((byte)((uint)iVar8 >> 8) | (byte)((uint)iVar41 >> 8));
      auVar3[8] = ~((byte)iVar26 | (byte)iVar35);
      auVar3[9] = ~((byte)((uint)iVar26 >> 8) | (byte)((uint)iVar35 >> 8));
      auVar3[10] = ~((byte)iVar30 | (byte)iVar38);
      auVar3[0xb] = ~((byte)((uint)iVar30 >> 8) | (byte)((uint)iVar38 >> 8));
      auVar3[0xc] = ~((byte)iVar31 | (byte)iVar40);
      auVar3[0xd] = ~((byte)((uint)iVar31 >> 8) | (byte)((uint)iVar40 >> 8));
      auVar3[0xe] = ~((byte)-(uint)(fVar45 < INFINITY) | (byte)-(uint)(INFINITY < fVar45));
      auVar3[0xf] = ~((byte)(-(uint)(fVar45 < INFINITY) >> 8) |
                     (byte)(-(uint)(INFINITY < fVar45) >> 8));
      uVar24 = NEON_umaxv(auVar3,2);
      if ((uVar24 & 1) != 0) {
        return 0xffffffff;
      }
      if (0x7f7fffff < (uint)ABS(fVar42)) {
        return 0xffffffff;
      }
    }
  }
  param_3[0x2f] = 0;
  param_3[0x30] = 0;
  *(undefined2 *)((long)param_3 + 0x16) = 0x808;
  iVar14 = (int)*(undefined8 *)(param_1 + 0x38);
  iVar6 = (int)((ulong)*(undefined8 *)(param_1 + 0x38) >> 0x20);
  cVar19 = (char)(iVar14 >> 0x1f);
  cVar21 = (char)(iVar6 >> 0x1f);
  param_3[0xd] = (ulong)CONCAT16(cVar21,CONCAT15(cVar21,(int5)iVar6)) << 8 | 0x80;
  param_3[0xc] = (ulong)CONCAT16(cVar19,CONCAT15(cVar19,(int5)iVar14)) << 8 | 0x80;
  param_3[0x1b] = 0x100;
  param_3[0x1a] = 0x40000000000000;
  param_3[0x1d] = 0x40000000000000;
  param_3[0x1c] = 0x80;
  param_3[0xf] = 0;
  param_3[0x10] = 0;
  param_3[0x19] = 0x80;
  param_3[0x18] = 0x100;
  iVar14 = (int)*(undefined8 *)(param_1 + 0x40);
  iVar6 = (int)((ulong)*(undefined8 *)(param_1 + 0x40) >> 0x20);
  cVar19 = (char)(iVar14 >> 0x1f);
  cVar21 = (char)(iVar6 >> 0x1f);
  param_3[0x34] = param_4;
  param_3[0x11] = 0x100;
  param_3[0xe] = 0x100;
  param_3[9] = 0x80;
  param_3[8] = 0x80;
  param_3[0xb] = (ulong)CONCAT16(cVar21,CONCAT15(cVar21,(int5)iVar6)) * 0x100 + -0x80;
  param_3[10] = (ulong)CONCAT16(cVar19,CONCAT15(cVar19,(int5)iVar14)) * 0x100 + -0x80;
  uVar11 = 0x3fffffff;
  if (*(char *)((long)param_2 + 2) != '\0') {
    uVar11 = 0;
  }
  *(undefined4 *)((long)param_3 + 0xbc) = uVar11;
  *(undefined4 *)((long)param_3 + 0x14) = 0x8080000;
  uVar43 = *(ulong *)(param_2 + 0xc);
  param_3[3] = *(undefined8 *)(param_1 + 0x4c);
  uVar5 = *(undefined8 *)(param_1 + 0x58);
  param_3[5] = *(undefined8 *)(param_1 + 0x60);
  param_3[4] = uVar5;
  param_3[7] = uVar43 >> 0x20;
  param_3[6] = uVar43 & 0xffffffff;
  fVar46 = (float)param_2[1];
  *(float *)(param_3 + 0x17) = fVar46;
  if (fVar46 < 0.0) {
    uVar15 = 0;
    uVar16 = 0;
  }
  else {
    uVar15 = 0x80;
    uVar16 = 0x3f;
    if (fVar46 <= 1.0) goto LAB_183b80934;
  }
  *(uint *)(param_3 + 0x17) = (uint)CONCAT11(uVar16,uVar15) << 0x10;
LAB_183b80934:
  *param_3 = 0;
  param_3[1] = 0;
  *(undefined4 *)(param_3 + 2) = 0;
  param_3[0x13] = 0;
  param_3[0x12] = 0;
  param_3[0x15] = 0;
  param_3[0x14] = 0;
  param_3[0x16] = 0;
  param_3[0x1e] = 0;
  param_3[0x1f] = 0;
  return 1;
}



/* ==== _CGShadingCreateEmpty @ 183b814fc size=352 ==== */

long _CGShadingCreateEmpty(int param_1,long param_2,long param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (param_1 - 1U < 4) {
    uVar6 = *(undefined8 *)(&DAT_184266cc0 + (ulong)(param_1 - 1U) * 8);
  }
  else {
    uVar6 = 0x70;
  }
  if (DAT_1eb05da78 != -1) {
    func_0x00018813aad0(&DAT_1eb05da78,&DAT_1e223ee48);
  }
  lVar3 = FUN_183b18540(DAT_1edf35c98,uVar6);
  if (lVar3 == 0) {
    return 0;
  }
  iVar1 = DAT_1edf35ca0 + 1;
  DAT_1edf35ca0 = DAT_1edf35ca0 + 1;
  *(int *)(lVar3 + 0x10) = iVar1;
  if (param_2 == 0) {
    lVar5 = 0;
    *(undefined8 *)(lVar3 + 0x18) = 0;
    *(int *)(lVar3 + 0x14) = param_1;
    if (param_3 == 0) goto LAB_183b815e4;
  }
  else {
    func_0x000188141250(param_2);
    *(long *)(lVar3 + 0x18) = param_2;
    *(int *)(lVar3 + 0x14) = param_1;
    if (param_3 == 0) goto LAB_183b815e4;
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x30);
  }
  lVar7 = lVar5 + 1;
  lVar4 = func_0x000188138470(lVar7 * 8,0x100004000313f17);
  if (lVar5 != -1) {
    lVar5 = 0;
    do {
      *(undefined8 *)(lVar4 + lVar5 * 8) = *(undefined8 *)(param_3 + lVar5 * 8);
      lVar5 = lVar5 + 1;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
  }
  *(long *)(lVar3 + 0x20) = lVar4;
LAB_183b815e4:
  puVar2 = param_4;
  if (param_4 == (undefined8 *)0x0) {
    puVar2 = &DAT_1841d77d8;
  }
  *(bool *)(lVar3 + 0x28) = param_4 != (undefined8 *)0x0;
  uVar6 = *puVar2;
  uVar10 = puVar2[3];
  uVar9 = puVar2[2];
  *(undefined8 *)(lVar3 + 0x38) = puVar2[1];
  *(undefined8 *)(lVar3 + 0x30) = uVar6;
  *(undefined8 *)(lVar3 + 0x48) = uVar10;
  *(undefined8 *)(lVar3 + 0x40) = uVar9;
  *(undefined8 *)(lVar3 + 0x58) = 0;
  uVar8 = FUN_183b4c138(param_2,0);
  *(undefined4 *)(lVar3 + 0x60) = uVar8;
  return lVar3;
}



/* ==== _rips_BltShade @ 183ca2620 size=28 ==== */

void _rips_BltShade(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  _RIPLayerBltShade(param_2,param_3,param_4,param_5,param_6,param_8);
  return;
}



/* ==== _type1_create_shading @ 183f0186c size=220 ==== */

void _type1_create_shading(long param_1,long param_2)

{
  bool bVar1;
  bool bVar2;
  undefined8 uVar3;
  double *pdVar4;
  double *pdVar5;
  double *pdVar6;
  double *pdVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  if (param_1 == 0) {
    uVar8 = 0;
    pdVar5 = (double *)&DAT_1841d77d8;
    pdVar4 = (double *)&DAT_1841d77f0;
    pdVar6 = (double *)&DAT_1841d77e0;
    pdVar7 = (double *)&DAT_1841d77e8;
    uVar3 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar3 = *(undefined8 *)(param_1 + 0x30);
    pdVar5 = (double *)(param_1 + 0x40);
    pdVar6 = (double *)(param_1 + 0x48);
    pdVar7 = (double *)(param_1 + 0x50);
    pdVar4 = (double *)(param_1 + 0x58);
  }
  dVar9 = *pdVar4;
  dVar10 = *pdVar5;
  dVar11 = *pdVar6;
  dVar12 = *pdVar7;
  local_60 = dVar10;
  dStack_58 = dVar11;
  local_50 = dVar12;
  dStack_48 = dVar9;
  uVar3 = FUN_183b343f4(uVar3);
  bVar1 = false;
  if ((dVar9 == 1.79769313486232e+308) && (bVar1 = false, !NAN(dVar12))) {
    bVar1 = dVar12 == 1.79769313486232e+308;
  }
  bVar2 = false;
  if ((bVar1) && (bVar2 = false, !NAN(dVar11))) {
    bVar2 = dVar11 == -8.988465674311579e+307;
  }
  bVar1 = false;
  if ((bVar2) && (bVar1 = false, !NAN(dVar10))) {
    bVar1 = dVar10 == -8.988465674311579e+307;
  }
  pdVar5 = (double *)0x0;
  if (!bVar1) {
    pdVar5 = &local_60;
  }
  uStack_88 = *(undefined8 *)(param_2 + 0x28);
  local_90 = *(undefined8 *)(param_2 + 0x20);
  uStack_78 = *(undefined8 *)(param_2 + 0x38);
  uStack_80 = *(undefined8 *)(param_2 + 0x30);
  uStack_68 = *(undefined8 *)(param_2 + 0x48);
  local_70 = *(undefined8 *)(param_2 + 0x40);
  FUN_183e18cc4(uVar8,uVar3,pdVar5,param_2,&local_90,*(undefined8 *)(param_2 + 0x50));
  return;
}



