/* ==== _add_triangle @ 183f98d90 size=136 ==== */

long _add_triangle(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x48);
  if (lVar2 == *(long *)(param_1 + 0x40)) {
    lVar2 = lVar2 * 2 + 6;
    lVar1 = func_0x000188138490(*(undefined8 *)(param_1 + 0x50),lVar2 * 0x18,0x1000040504ffac1);
    if (lVar1 == 0) {
      return 0;
    }
    *(long *)(param_1 + 0x50) = lVar1;
    *(long *)(param_1 + 0x40) = lVar2;
    lVar2 = *(long *)(param_1 + 0x48);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x50);
  }
  *(long *)(param_1 + 0x48) = lVar2 + 1;
  return lVar1 + lVar2 * 0x18;
}



/* ==== _add_point @ 183f98e18 size=248 ==== */

long _add_point(double param_1,double param_2,long param_3,double *param_4,long param_5)

{
  double *pdVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  
  if (param_5 == 0) {
    return -1;
  }
  lVar2 = *(long *)(param_3 + 0x28);
  if (lVar2 == *(long *)(param_3 + 0x30)) {
    lVar2 = lVar2 * 2 + 0x12;
    lVar3 = func_0x000188138490(*(undefined8 *)(param_3 + 0x38),*(long *)(param_3 + 0x20) * lVar2,
                                0x5fbcb7f9);
    if (lVar3 == 0) {
      return -1;
    }
    *(long *)(param_3 + 0x30) = lVar2;
    *(long *)(param_3 + 0x38) = lVar3;
    lVar2 = *(long *)(param_3 + 0x28);
  }
  else {
    lVar3 = *(long *)(param_3 + 0x38);
  }
  *(long *)(param_3 + 0x28) = lVar2 + 1;
  pdVar1 = (double *)(lVar3 + *(long *)(param_3 + 0x20) * lVar2);
  if (param_4 != (double *)0x0) {
    dVar5 = param_4[1] * param_1;
    param_1 = param_4[4] + param_4[2] * param_2 + *param_4 * param_1;
    param_2 = param_4[5] + param_4[3] * param_2 + dVar5;
  }
  pdVar1[1] = param_2;
  *pdVar1 = param_1;
  lVar3 = *(long *)(param_3 + 8);
  if (lVar3 != 0) {
    lVar4 = 0;
    do {
      pdVar1[lVar4 + 2] = *(double *)(param_5 + lVar4 * 8);
      lVar4 = lVar4 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  return lVar2;
}



