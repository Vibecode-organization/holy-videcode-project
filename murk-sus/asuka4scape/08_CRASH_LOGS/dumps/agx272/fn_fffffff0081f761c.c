// FUN_fffffff0081f761c @ fffffff0081f761c size=1048

long * FUN_fffffff0081f761c
                 (long *param_1,long *param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,ulong param_6,ulong param_7)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  
  lVar11 = param_2[1];
  lVar9 = *param_2;
  lVar12 = param_2[2];
  lVar17 = param_2[5];
  lVar15 = param_2[4];
  param_1[0xb] = param_2[3];
  param_1[10] = lVar12;
  param_1[0xd] = lVar17;
  param_1[0xc] = lVar15;
  param_1[9] = lVar11;
  param_1[8] = lVar9;
  lVar11 = param_2[7];
  lVar9 = param_2[6];
  lVar15 = param_2[9];
  lVar12 = param_2[8];
  lVar17 = param_2[10];
  lVar19 = param_2[0xd];
  lVar18 = param_2[0xc];
  param_1[0x13] = param_2[0xb];
  param_1[0x12] = lVar17;
  param_1[0x15] = lVar19;
  param_1[0x14] = lVar18;
  param_1[0xf] = lVar11;
  param_1[0xe] = lVar9;
  param_1[0x11] = lVar15;
  param_1[0x10] = lVar12;
  if ((((int)*param_2 == 0) || (*(int *)((long)param_2 + 4) == 0)) || ((int)param_2[1] == 0)) {
    return (long *)0x0;
  }
  iVar3 = (**(code **)(*param_1 + 0xb0))(param_1,param_1 + 8);
  if (iVar3 == 0) {
    plVar4 = (long *)0x0;
  }
  else {
    if ((param_7 & 1) == 0) {
      uVar5 = *(uint *)(param_1[0x24] + 0x414);
    }
    else {
      uVar5 = 1;
    }
    *(uint *)((long)param_1 + 0x3c) = uVar5;
    (**(code **)(*param_1 + 0xa0))(param_1,1 < uVar5,param_4);
    param_1[0x29] = 0;
    param_1[0x28] = 0;
    param_1[0x2b] = 0;
    param_1[0x2a] = 0;
    param_1[0x31] = 0;
    param_1[0x30] = 0;
    param_1[0x33] = 0;
    param_1[0x32] = 0;
    param_1[0x2d] = 0;
    param_1[0x2c] = 0;
    param_1[0x2f] = 0;
    param_1[0x2e] = 0;
    param_1[0x35] = 0;
    param_1[0x34] = 0;
    param_1[0x37] = 0;
    param_1[0x36] = 0;
    (**(code **)(*param_1 + 0xb8))(param_1,param_3,param_6 >> 0xf);
    uVar7 = (ulong)((int)param_1[2] + 0xfff) & 0xfffff000;
    param_1[2] = uVar7;
    uVar7 = uVar7 + param_1[6] + param_1[0x4c];
    if ((ulong)param_1[0x4e] < uVar7 * 0x10) {
      if ((long *)param_1[0x26] != (long *)0x0) {
        (**(code **)(*(long *)param_1[0x26] + 0x28))();
        param_1[0x26] = 0;
        param_1[0x4e] = 0;
      }
      *(undefined8 *)((long)param_1 + 0x284) = 0;
      if ((int)param_1[0x50] != 0) {
        uVar16 = 0;
        do {
          uVar10 = param_1[0x52] + uVar16 * 0x58;
          if (((param_1[0x52] ^ uVar10) & 0xffc0000000000000) != 0) {
            uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
          }
          thunk_EXT_FUN_8011000002946f14(uVar10 + 0x18);
          uVar16 = uVar16 + 1;
        } while (uVar16 < *(uint *)(param_1 + 0x50));
      }
      param_1[0x54] = 0;
      param_1[0x53] = 0;
      uVar16 = (long)(1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f));
      do {
        uVar10 = uVar16;
        uVar16 = uVar10 << 1;
      } while (uVar10 < uVar7 * 0x10);
      param_1[0x4e] = uVar10;
      uVar16 = uVar10 >> 4;
      if ((*(byte *)(param_1 + 0x58) & 1) == 0) {
        uVar16 = 0;
      }
      param_1[0x4d] = uVar16 + uVar10;
      bVar2 = (*(ulong *)(param_1[0x24] + 0x5c8) & 0x200000000000) != 0;
      uVar8 = 0x2000000003;
      if (bVar2) {
        uVar8 = 0x3000000003;
      }
      uVar6 = 5;
      if (bVar2) {
        uVar6 = 1;
      }
      plVar4 = (long *)FUN_fffffff0081f9fc0(param_1[0x24],param_1[0x25],uVar16 + uVar10,uVar8,uVar6)
      ;
      param_1[0x26] = (long)plVar4;
      if (plVar4 == (long *)0x0) {
        param_1[0x4d] = 0;
        param_1[0x4e] = 0;
        return (long *)0x0;
      }
      (**(code **)(*plVar4 + 0x20))();
      (**(code **)(*(long *)param_1[0x26] + 0xb0))((long *)param_1[0x26],param_1[0x25]);
      if (*(uint *)(*(long *)(*(long *)(param_1[0x26] + 0x20) + 0x18) + 0x78) <
          *(uint *)(param_1 + 0x27)) {
        thunk_EXT_FUN_801100000293ff9c();
      }
    }
    uVar16 = param_1[0x54];
    uVar10 = param_1[0x53];
    uVar13 = *(uint *)((long)param_1 + 0x284);
    lVar9 = param_1[0x4e];
    uVar5 = *(uint *)(param_1 + 0x50);
    if (((uVar10 - uVar16) + lVar9 < uVar7) ||
       (uVar14 = *(uint *)(param_1 + 0x51), uVar14 - uVar13 == uVar5)) {
      do {
        uVar14 = 0;
        if (uVar5 != 0) {
          uVar14 = uVar13 / uVar5;
        }
        lVar9 = (ulong)(uVar13 - uVar14 * uVar5) * 0x58;
        plVar4 = (long *)(param_1[0x52] + (long)(int)lVar9);
        if (lVar9 - (int)lVar9 != 0) {
          plVar4 = (long *)(param_1[0x52] + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *(uint *)((long)param_1 + 0x284) = uVar13 + 1;
        param_1[0x53] = plVar4[1] + *plVar4 + plVar4[2] + uVar10;
        thunk_EXT_FUN_80110000029486ac(*(undefined8 *)(param_1[0x24] + 0x148),plVar4 + 3,param_5);
        thunk_EXT_FUN_8011000002946f14(plVar4 + 3);
        uVar10 = param_1[0x53];
        uVar16 = param_1[0x54];
        uVar1 = -uVar10;
        if (uVar16 < uVar10) {
          uVar1 = ~uVar10;
        }
        uVar13 = *(uint *)((long)param_1 + 0x284);
        lVar9 = param_1[0x4e];
        uVar5 = *(uint *)(param_1 + 0x50);
      } while ((lVar9 - (uVar16 + uVar1) < uVar7) ||
              (uVar14 = *(uint *)(param_1 + 0x51), uVar14 - uVar13 == uVar5));
    }
    uVar13 = 0;
    if (uVar5 != 0) {
      uVar13 = uVar14 / uVar5;
    }
    lVar11 = (ulong)(uVar14 - uVar13 * uVar5) * 0x58;
    plVar4 = (long *)(param_1[0x52] + (long)(int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      plVar4 = (long *)(param_1[0x52] + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *(uint *)(param_1 + 0x51) = uVar14 + 1;
    lVar11 = param_1[2];
    lVar12 = param_1[6];
    *plVar4 = lVar11;
    plVar4[1] = lVar12;
    lVar15 = param_1[0x4c];
    plVar4[2] = lVar15;
    plVar4 = plVar4 + 3;
    uVar7 = lVar9 - 1;
    param_1[0x55] = uVar7 & uVar16;
    uVar16 = uVar16 + lVar11;
    param_1[0x56] = uVar7 & uVar16;
    uVar16 = uVar16 + lVar12;
    param_1[0x57] = uVar16 & uVar7;
    param_1[0x54] = uVar16 + lVar15;
  }
  return plVar4;
}

