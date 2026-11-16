// FUN_fffffff0081e4230 @ fffffff0081e4230 size=848

ulong FUN_fffffff0081e4230
                (ushort *param_1,uint param_2,int *param_3,int *param_4,uint *param_5,uint *param_6)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  bVar8 = (byte)param_1[5];
  uVar18 = 0;
  if (param_2 <= bVar8) {
    uVar18 = bVar8 - param_2;
  }
  uVar15 = (ulong)uVar18;
  bVar5 = *(byte *)((long)param_1 + 0xb);
  uVar21 = 0;
  if (param_2 <= bVar5) {
    uVar21 = bVar5 - param_2;
  }
  uVar14 = (ulong)uVar21;
  uVar13 = param_1[8];
  uVar17 = (uint)(*param_1 >> (ulong)(param_2 & 0x1f));
  uVar11 = (uint)(param_1[1] >> (ulong)(param_2 & 0x1f));
  if ((byte)uVar13 - 1 < 2) {
    bVar6 = (byte)param_1[9];
    uVar16 = 0;
    if (bVar6 != 0) {
      uVar16 = ((bVar6 + uVar17) - 1) / (uint)bVar6;
    }
    if (uVar16 < 2) {
      uVar16 = 1;
    }
    bVar6 = *(byte *)((long)param_1 + 0x13);
    uVar17 = 0;
    if (bVar6 != 0) {
      uVar17 = ((bVar6 + uVar11) - 1) / (uint)bVar6;
    }
    if (uVar17 < 2) {
      uVar17 = 1;
    }
    uVar11 = 1 << (ulong)(uVar18 & 0x1f);
    uVar10 = 1 << (ulong)(uVar21 & 0x1f);
    bVar6 = (byte)param_1[6];
    bVar7 = *(byte *)((long)param_1 + 0xd);
    if (((uint)(1 << (ulong)(bVar7 & 0x1f)) < uVar10) && (uVar11 >> (ulong)(bVar6 & 0x1f) == 0)) {
      uVar20 = 0;
      if (param_2 < bVar8) {
        uVar20 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar11 - 1) & 0x1f)));
      }
      uVar19 = ((uint)bVar7 + (uint)bVar6) - uVar20;
    }
    else {
      uVar19 = (uint)bVar7;
      uVar20 = (uint)bVar6;
      uVar1 = 0;
      if (param_2 < bVar5) {
        uVar1 = (uint)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar10 - 1) & 0x1f))) | 0xffffffe0;
      }
      uVar4 = uVar19;
      uVar12 = uVar20;
      if ((uint)(1 << (ulong)(uVar20 & 0x1f)) < uVar11) {
        uVar4 = -uVar1;
        uVar12 = uVar19 + uVar20 + uVar1;
      }
      if (uVar10 >> (ulong)(uVar19 & 0x1f) == 0) {
        uVar20 = uVar12;
        uVar19 = uVar4;
      }
    }
    goto LAB_fffffff0081e44c4;
  }
  if (uVar17 < 2) {
    uVar17 = 1;
  }
  bVar8 = (byte)param_1[9];
  uVar16 = 0;
  if (bVar8 != 0) {
    uVar16 = ((bVar8 + uVar17) - 1) / (uint)bVar8;
  }
  if (uVar11 < 2) {
    uVar11 = 1;
  }
  bVar8 = *(byte *)((long)param_1 + 0x13);
  bVar5 = *(byte *)((long)param_1 + 0xf);
  uVar18 = 1 << (ulong)(bVar5 & 0x1f);
  uVar17 = 0;
  if (bVar8 != 0) {
    uVar17 = ((bVar8 + uVar11) - 1) / (uint)bVar8;
  }
  uVar11 = -1 << (ulong)(bVar5 & 0x1f);
  uVar21 = uVar17;
  uVar10 = uVar16;
  if (uVar18 <= uVar16 && uVar18 <= uVar17) {
    uVar21 = uVar11 & (uVar11 - uVar17 ^ 0xffffffff);
    uVar10 = uVar11 & (uVar11 - uVar16 ^ 0xffffffff);
  }
  if (bVar5 != 0) {
    uVar17 = uVar21;
    uVar16 = uVar10;
  }
  uVar18 = (uint)(byte)param_1[6];
  uVar19 = (uint)*(byte *)((long)param_1 + 0xd);
  if ((uint)(1 << (ulong)(uVar19 & 0x1f)) < uVar17 && uVar16 >> (ulong)(uVar18 & 0x1f) == 0) {
    if (uVar16 < 2) {
      uVar20 = 0;
    }
    else {
      uVar20 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar16 - 1) & 0x1f)));
    }
    uVar19 = (uVar19 + uVar18) - uVar20;
LAB_fffffff0081e446c:
    if (1 < uVar16) goto LAB_fffffff0081e4474;
    uVar18 = 0;
  }
  else {
    uVar20 = uVar18;
    if (uVar17 >> (ulong)(uVar19 & 0x1f) != 0 || uVar16 <= (uint)(1 << (ulong)(uVar18 & 0x1f)))
    goto LAB_fffffff0081e446c;
    uVar21 = 0;
    if (1 < uVar17) {
      uVar21 = (uint)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar17 - 1) & 0x1f))) | 0xffffffe0;
    }
    uVar20 = uVar19 + uVar18 + uVar21;
    uVar19 = -uVar21;
LAB_fffffff0081e4474:
    uVar18 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar16 - 1) & 0x1f)));
  }
  uVar21 = 0;
  if (1 < uVar17) {
    uVar21 = 0x20 - (int)LZCOUNT(~(-1 << (ulong)(-(int)LZCOUNT(uVar17 - 1) & 0x1f)));
  }
LAB_fffffff0081e44c4:
  iVar2 = 0;
  if (uVar20 <= uVar18) {
    iVar2 = uVar18 - uVar20;
  }
  *param_3 = iVar2;
  iVar2 = 0;
  if (uVar19 <= uVar21) {
    iVar2 = uVar21 - uVar19;
  }
  *param_4 = iVar2;
  *param_5 = uVar16 + ~(-1 << (ulong)(uVar20 & 0x1f)) >> (ulong)(uVar20 & 0x1f);
  *param_6 = uVar17 + ~(-1 << (ulong)(uVar19 & 0x1f)) >> (ulong)(uVar19 & 0x1f);
  cVar9 = *(char *)((long)param_1 + 0x11);
  if (((byte)uVar13 == 2) && (cVar9 == '\0')) {
    return ((1L << (uVar14 & 0x3f)) << (uVar14 & 0x3f)) * (ulong)(byte)param_1[7];
  }
  uVar15 = ((1L << (uVar15 & 0x3f)) << (uVar14 & 0x3f)) * (ulong)(byte)param_1[7];
  uVar14 = uVar15 + 0x7f & 0xffffffffffffff80;
  if (cVar9 == '\x02') {
    uVar15 = uVar14;
  }
  uVar3 = uVar14;
  if (cVar9 != '\x03') {
    uVar3 = uVar15;
  }
  if (cVar9 != '\x04') {
    uVar14 = uVar3;
  }
  return uVar14;
}

