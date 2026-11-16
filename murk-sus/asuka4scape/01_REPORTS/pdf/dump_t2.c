/* ==== _type3_create_shading @ 183c92ba8 size=252 ==== */

void _type3_create_shading(long param_1,undefined8 *param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_60 = dVar9;
  dStack_58 = dVar10;
  local_50 = dVar12;
  dStack_48 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_60;
  }
  _CGShadingCreateRadialInternal
            (*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],uVar8,uVar7,pdVar1,
             param_2 + 6,param_2[8],*(char *)(param_2 + 9) != '\0',
             *(char *)((long)param_2 + 0x49) != '\0');
  return;
}



/* ==== FUN_183e18cc4 @ 183e18cc4 size=196 ==== */

long FUN_183e18cc4(long param_1,undefined8 param_2,undefined8 param_3,long param_4,
                  undefined8 *param_5,long param_6)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  lVar2 = 0;
  if ((param_1 != 0) && (param_6 != 0)) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x30);
    if (*(long *)(param_6 + 0x30) == lVar2 || *(long *)(param_6 + 0x30) == lVar2 + 1) {
      lVar3 = 4;
      lVar2 = _CGShadingCreateEmpty(4,param_1,param_2,param_3);
      func_0x000188141250(param_6);
      lVar1 = 0;
      *(long *)(lVar2 + 0xa0) = param_6;
      uVar7 = param_5[3];
      uVar6 = param_5[2];
      uVar5 = param_5[5];
      uVar4 = param_5[4];
      uVar8 = *param_5;
      *(undefined8 *)(lVar2 + 0xb0) = param_5[1];
      *(undefined8 *)(lVar2 + 0xa8) = uVar8;
      *(undefined8 *)(lVar2 + 0xc0) = uVar7;
      *(undefined8 *)(lVar2 + 0xb8) = uVar6;
      *(undefined8 *)(lVar2 + 0xd0) = uVar5;
      *(undefined8 *)(lVar2 + 200) = uVar4;
      do {
        *(undefined8 *)(lVar2 + 0x80 + lVar1 * 8) = *(undefined8 *)(param_4 + lVar1 * 8);
        lVar1 = lVar1 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}



/* ==== _type2_create_shading @ 183f927d0 size=248 ==== */

void _type2_create_shading(long param_1,undefined8 *param_2)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  double *pdVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_60;
  double dStack_58;
  double local_50;
  double dStack_48;
  
  pdVar1 = (double *)&DAT_1841d77f0;
  pdVar2 = (double *)&DAT_1841d77d8;
  pdVar3 = (double *)&DAT_1841d77e0;
  pdVar4 = (double *)&DAT_1841d77e8;
  if (param_1 != 0) {
    pdVar1 = (double *)(param_1 + 0x58);
    pdVar2 = (double *)(param_1 + 0x40);
    pdVar3 = (double *)(param_1 + 0x48);
    pdVar4 = (double *)(param_1 + 0x50);
  }
  dVar11 = *pdVar1;
  dVar9 = *pdVar2;
  dVar10 = *pdVar3;
  dVar12 = *pdVar4;
  if (param_1 == 0) {
    uVar8 = 0;
    uVar7 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x28);
    uVar7 = *(undefined8 *)(param_1 + 0x30);
  }
  local_60 = dVar9;
  dStack_58 = dVar10;
  local_50 = dVar12;
  dStack_48 = dVar11;
  uVar7 = FUN_183b343f4(uVar7);
  bVar5 = false;
  if ((dVar11 == 1.79769313486232e+308) && (bVar5 = false, !NAN(dVar12))) {
    bVar5 = dVar12 == 1.79769313486232e+308;
  }
  bVar6 = false;
  if ((bVar5) && (bVar6 = false, !NAN(dVar10))) {
    bVar6 = dVar10 == -8.988465674311579e+307;
  }
  bVar5 = false;
  if ((bVar6) && (bVar5 = false, !NAN(dVar9))) {
    bVar5 = dVar9 == -8.988465674311579e+307;
  }
  pdVar1 = (double *)(undefined1 *)0x0;
  if (!bVar5) {
    pdVar1 = &local_60;
  }
  _CGShadingCreateAxialInternal
            (*param_2,param_2[1],param_2[2],param_2[3],uVar8,uVar7,pdVar1,param_2 + 4,param_2[6],
             *(char *)(param_2 + 7) != '\0',*(char *)((long)param_2 + 0x39) != '\0');
  return;
}



