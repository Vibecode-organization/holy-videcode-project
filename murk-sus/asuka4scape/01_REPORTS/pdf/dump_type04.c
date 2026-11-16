/* ==== _type4_evaluate @ 183cdf478 size=404 ==== */

void _type4_evaluate(long *param_1,long param_2,long param_3)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  int in_wzr;
  
  if (param_1 == (long *)0x0) {
    return;
  }
  lVar2 = *param_1;
  if (lVar2 != 0) {
    lVar4 = 0;
    do {
      if (*(double *)(param_2 + lVar4 * 8) != 0.0) {
        piVar3 = (int *)param_1[6];
        iVar1 = *piVar3;
        if (iVar1 == 0) {
          *piVar3 = 1;
        }
        if (piVar3 == (int *)0x0 || iVar1 != 0) goto LAB_183cdf574;
        lVar2 = *param_1;
        if (lVar2 == 0) goto LAB_183cdf53c;
        lVar4 = 0;
        goto LAB_183cdf520;
      }
      lVar4 = lVar4 + 1;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  lVar2 = param_1[2];
  if (lVar2 == 0) {
    return;
  }
  lVar4 = 0;
  lVar5 = *(long *)(param_1[5] + 0x10);
  do {
    *(undefined8 *)(param_3 + lVar4 * 8) = *(undefined8 *)(lVar5 + lVar4 * 8);
    lVar4 = lVar4 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
LAB_183cdf520:
  if (*(double *)(param_2 + lVar4 * 8) == *(double *)(*(long *)(piVar3 + 2) + lVar4 * 8))
  goto code_r0x000183cdf530;
  if (*piVar3 == 1) {
    *piVar3 = in_wzr;
LAB_183cdf574:
    _evaluate(param_1,param_2,param_3);
    piVar3 = (int *)param_1[6];
    iVar1 = *piVar3;
    if (iVar1 == 0) {
      *piVar3 = 1;
    }
    if (piVar3 == (int *)0x0) {
      return;
    }
    if (iVar1 != 0) {
      return;
    }
    lVar2 = *param_1;
    if (lVar2 != 0) {
      lVar4 = 0;
      lVar5 = *(long *)(piVar3 + 2);
      do {
        *(undefined8 *)(lVar5 + lVar4 * 8) = *(undefined8 *)(param_2 + lVar4 * 8);
        lVar4 = lVar4 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
    lVar2 = param_1[2];
    if (lVar2 != 0) {
      lVar4 = 0;
      lVar5 = *(long *)(piVar3 + 4);
      do {
        *(undefined8 *)(lVar5 + lVar4 * 8) = *(undefined8 *)(param_3 + lVar4 * 8);
        lVar4 = lVar4 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
    goto LAB_183cdf5e8;
  }
  goto LAB_183cdf608;
code_r0x000183cdf530:
  lVar4 = lVar4 + 1;
  lVar2 = lVar2 + -1;
  if (lVar2 == 0) {
LAB_183cdf53c:
    lVar2 = param_1[2];
    if (lVar2 != 0) {
      lVar4 = 0;
      lVar5 = *(long *)(piVar3 + 4);
      do {
        *(undefined8 *)(param_3 + lVar4 * 8) = *(undefined8 *)(lVar5 + lVar4 * 8);
        lVar4 = lVar4 + 1;
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
    }
LAB_183cdf5e8:
    if (*piVar3 == 1) {
      *piVar3 = in_wzr;
      return;
    }
LAB_183cdf608:
    func_0x000188138260();
    return;
  }
  goto LAB_183cdf520;
}



/* ==== _type0_evaluate @ 183f93078 size=740 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _type0_evaluate(long *param_1,long param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  double *pdVar5;
  double *pdVar6;
  long extraout_x8;
  long extraout_x8_00;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  double *pdVar12;
  double *pdVar13;
  double dVar14;
  double dVar15;
  double *local_90 [2];
  ulong local_80;
  long local_78;
  
  local_78 = *_DAT_1e0186220;
  if (param_1 == (long *)0x0) goto LAB_183f9330c;
  lVar7 = 1;
  if ((ulong)(*param_1 * 8) < 0x101) {
    lVar7 = *param_1 * 8 + 1;
  }
  uVar4 = (*_DAT_1e1f91910)(lVar7 + 0xfU & 0xfffffffffffffff0);
  pdVar13 = (double *)((long)local_90 - extraout_x8);
  pdVar5 = pdVar13;
  if ((0x100 < uVar4) &&
     (pdVar5 = (double *)func_0x000188138470(uVar4,0x9f6ffed4), pdVar5 == (double *)0x0))
  goto LAB_183f9330c;
  lVar7 = 1;
  if ((ulong)(param_1[2] * 8) < 0x101) {
    lVar7 = param_1[2] * 8 + 1;
  }
  uVar4 = (*_DAT_1e1f91910)(lVar7 + 0xfU & 0xfffffffffffffff0);
  pdVar12 = (double *)((long)pdVar13 - extraout_x8_00);
  pdVar6 = pdVar12;
  if ((uVar4 < 0x101) ||
     (pdVar6 = (double *)func_0x000188138470(uVar4,0x6baf8fb3), pdVar6 != (double *)0x0)) {
    lVar7 = *param_1;
    if (lVar7 == 0) {
LAB_183f9327c:
      _multilinear_interpolate(param_1,pdVar5,pdVar6);
      lVar7 = param_1[2];
    }
    else {
      lVar8 = 0;
      lVar10 = param_1[1];
      lVar1 = param_1[5];
      lVar9 = param_1[6];
      lVar11 = lVar7;
      do {
        dVar14 = *(double *)(lVar10 + lVar8 * 0x10);
        uVar4 = lVar8 << 4 | 8;
        dVar15 = *(double *)(lVar1 + lVar8 * 0x10);
        dVar15 = dVar15 + ((*(double *)(param_2 + lVar8 * 8) - dVar14) *
                          (*(double *)(lVar1 + uVar4) - dVar15)) /
                          (*(double *)(lVar10 + uVar4) - dVar14);
        if (dVar15 <= 0.0) {
          dVar15 = 0.0;
        }
        dVar15 = (double)NEON_fminnm(dVar15,(double)(*(long *)(lVar9 + lVar8 * 8) + -1));
        pdVar5[lVar8] = dVar15;
        lVar8 = lVar8 + 1;
        lVar11 = lVar11 + -1;
      } while (lVar11 != 0);
      if (lVar7 != 1) goto LAB_183f9327c;
      local_90[0] = pdVar12;
      local_90[1] = (double *)local_90;
      lVar7 = param_1[2];
      pdVar12 = local_90[0];
      if (lVar7 != 0) {
        lVar8 = 0;
        uVar4 = (ulong)(int)*pdVar5;
        dVar15 = *pdVar5 - (double)uVar4;
        do {
          local_80 = uVar4;
          uVar2 = _lookup(param_1,lVar8,&local_80);
          local_80 = uVar4 + 1;
          uVar3 = _lookup(param_1,lVar8,&local_80);
          pdVar6[lVar8] = dVar15 * (double)uVar3 + (double)uVar2 * (1.0 - dVar15);
          lVar8 = lVar8 + 1;
          pdVar12 = local_90[0];
        } while (lVar7 != lVar8);
      }
    }
    if (lVar7 != 0) {
      lVar8 = 0;
      lVar1 = param_1[7];
      lVar9 = param_1[4];
      do {
        dVar15 = *(double *)(lVar9 + lVar8 * 0x10);
        *(double *)(param_3 + lVar8 * 8) =
             dVar15 + (pdVar6[lVar8] * (*(double *)(lVar9 + (lVar8 << 4 | 8U)) - dVar15)) /
                      (double)(0xffffffff >> (ulong)(-(int)lVar1 & 0x1f));
        lVar8 = lVar8 + 1;
        lVar7 = lVar7 + -1;
      } while (lVar7 != 0);
    }
    if (pdVar5 != pdVar13) {
      func_0x000188138390(pdVar5);
    }
    pdVar5 = pdVar6;
    if (pdVar6 == pdVar12) goto LAB_183f9330c;
  }
  else if (pdVar5 == pdVar13) goto LAB_183f9330c;
  func_0x000188138390(pdVar5);
LAB_183f9330c:
  if (*_DAT_1e0186220 != local_78) {
    func_0x000188138130();
    return;
  }
  return;
}



/* ==== _evaluate_range @ 183fea234 size=312 ==== */

void _evaluate_range(long param_1,long param_2,ulong *param_3,long param_4)

{
  double *pdVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar8 = *(double *)(param_3[3] + param_2 * 0x10);
  uVar2 = *param_3;
  dVar9 = (*(double *)(param_3[3] + (param_2 << 4 | 8U)) - dVar8) / (double)(uVar2 - 1);
  if (param_2 == 0) {
    if (uVar2 != 0) {
      uVar2 = 0;
      do {
        pdVar1 = (double *)param_3[6];
        uVar3 = param_3[7];
        *pdVar1 = dVar8 + dVar9 * (double)uVar2;
        FUN_183b7ffbc(*(undefined8 *)(param_1 + 0x10),pdVar1,uVar3);
        uVar3 = param_3[4];
        if (uVar3 != 0) {
          lVar4 = 0;
          uVar5 = param_3[7];
          do {
            dVar7 = *(double *)(uVar5 + lVar4 * 8);
            if (dVar7 < *(double *)(param_4 + lVar4 * 0x10)) {
              *(double *)(param_4 + lVar4 * 0x10) = dVar7;
              dVar7 = *(double *)(uVar5 + lVar4 * 8);
            }
            uVar6 = lVar4 << 1 | 1;
            if (*(double *)(param_4 + uVar6 * 8) < dVar7) {
              *(double *)(param_4 + uVar6 * 8) = dVar7;
            }
            lVar4 = lVar4 + 1;
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *param_3);
    }
  }
  else if (uVar2 != 0) {
    uVar2 = 0;
    do {
      *(double *)(param_3[6] + param_2 * 8) = dVar8 + dVar9 * (double)uVar2;
      _evaluate_range(param_1,param_2 + -1,param_3,param_4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_3);
  }
  return;
}



