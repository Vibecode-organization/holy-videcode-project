/* ==== _type4_release @ 183cdf12c size=100 ==== */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Possible PIC construction at 0x000183cdf148: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x000183cdf14c) */
/* WARNING: Removing unreachable block (ram,0x000183cdf188) */
/* WARNING: Removing unreachable block (ram,0x000183cdf184) */

void _type4_release(long param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* ==== _evaluate @ 183cdf2a8 size=464 ==== */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _evaluate(long *param_1,long param_2,long param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  long local_d20 [2];
  double local_d10 [400];
  undefined4 local_90;
  long local_78;
  
  local_78 = *_DAT_1e0186220;
  local_90 = 0;
  local_d20[1] = 0;
  local_d20[0] = 0;
  local_d10[1] = 0.0;
  local_d10[0] = 0.0;
  local_d10[3] = 0.0;
  local_d10[2] = 0.0;
  local_d10[5] = 0.0;
  local_d10[4] = 0.0;
  local_d10[7] = 0.0;
  local_d10[6] = 0.0;
  local_d10[9] = 0.0;
  local_d10[8] = 0.0;
  local_d10[0xb] = 0.0;
  local_d10[10] = 0.0;
  local_d10[0xd] = 0.0;
  local_d10[0xc] = 0.0;
  local_d10[0xf] = 0.0;
  local_d10[0xe] = 0.0;
  local_d10[0x11] = 0.0;
  local_d10[0x10] = 0.0;
  local_d10[0x13] = 0.0;
  local_d10[0x12] = 0.0;
  local_d10[0x15] = 0.0;
  local_d10[0x14] = 0.0;
  local_d10[0x17] = 0.0;
  local_d10[0x16] = 0.0;
  local_d10[0x19] = 0.0;
  local_d10[0x18] = 0.0;
  local_d10[0x1b] = 0.0;
  local_d10[0x1a] = 0.0;
  local_d10[0x1d] = 0.0;
  local_d10[0x1c] = 0.0;
  local_d10[0x1f] = 0.0;
  local_d10[0x1e] = 0.0;
  local_d10[0x21] = 0.0;
  local_d10[0x20] = 0.0;
  local_d10[0x23] = 0.0;
  local_d10[0x22] = 0.0;
  local_d10[0x25] = 0.0;
  local_d10[0x24] = 0.0;
  local_d10[0x27] = 0.0;
  local_d10[0x26] = 0.0;
  local_d10[0x29] = 0.0;
  local_d10[0x28] = 0.0;
  local_d10[0x2b] = 0.0;
  local_d10[0x2a] = 0.0;
  local_d10[0x2d] = 0.0;
  local_d10[0x2c] = 0.0;
  local_d10[0x2f] = 0.0;
  local_d10[0x2e] = 0.0;
  local_d10[0x31] = 0.0;
  local_d10[0x30] = 0.0;
  local_d10[0x33] = 0.0;
  local_d10[0x32] = 0.0;
  local_d10[0x35] = 0.0;
  local_d10[0x34] = 0.0;
  local_d10[0x37] = 0.0;
  local_d10[0x36] = 0.0;
  local_d10[0x39] = 0.0;
  local_d10[0x38] = 0.0;
  local_d10[0x3b] = 0.0;
  local_d10[0x3a] = 0.0;
  local_d10[0x3d] = 0.0;
  local_d10[0x3c] = 0.0;
  lVar1 = *param_1;
  if (lVar1 == 0) {
    dVar8 = 0.0;
  }
  else {
    local_d20[0] = 0;
    lVar3 = 0;
    lVar4 = 0;
    do {
      dVar8 = *(double *)(param_2 + lVar3 * 8);
      if (lVar4 == 200) {
        local_90 = 3;
      }
      else {
        local_d20[0] = lVar4 + 1;
        local_d10[lVar4 * 2] = 1.27468936627042e-321;
        local_d10[lVar4 * 2U + 1] = dVar8;
        lVar4 = local_d20[0];
      }
      lVar3 = lVar3 + 1;
      lVar1 = lVar1 + -1;
    } while (lVar1 != 0);
  }
  _type4_program_execute(param_1[4],local_d20);
  uVar2 = param_1[2];
  if (uVar2 != 0) {
    uVar5 = 0;
    iVar6 = 0x102;
    lVar1 = -1;
    do {
      if (local_d20[0] == 0) {
        local_90 = 4;
      }
      else {
        local_d20[0] = local_d20[0] + -1;
        iVar6 = *(int *)(local_d10 + local_d20[0] * 2);
        dVar8 = local_d10[local_d20[0] * 2U + 1];
      }
      dVar7 = dVar8;
      if (iVar6 != 0x102) {
        if (iVar6 == 0x101) {
          dVar7 = (double)SUB84(dVar8,0);
        }
        else {
          _pdf_error("error evaluating Type 4 function: typecheck.");
          uVar2 = param_1[2];
          dVar7 = 0.0;
        }
      }
      *(double *)(param_3 + (uVar2 + lVar1) * 8) = dVar7;
      uVar5 = uVar5 + 1;
      lVar1 = lVar1 + -1;
    } while (uVar5 < uVar2);
  }
  if (*_DAT_1e0186220 != local_78) {
    func_0x000188138130();
    return;
  }
  return;
}



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



/* ==== _type4_op_abs @ 183cf09b0 size=184 ==== */

undefined8 _type4_op_abs(long *param_1)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  long lVar6;
  double dVar7;
  
  lVar6 = *param_1;
  if (lVar6 + 1U < 2) {
    uVar5 = 4;
LAB_183cf0a3c:
    uVar4 = 0;
    *(undefined4 *)(param_1 + 0x192) = uVar5;
  }
  else {
    *param_1 = lVar6 + -1;
    plVar1 = param_1 + (lVar6 + -1) * 2 + 2;
    if ((int)*plVar1 == 0x102) {
      dVar7 = (double)plVar1[1];
      *param_1 = lVar6;
      *(int *)plVar1 = 0x102;
      plVar1[1] = (long)ABS(dVar7);
    }
    else {
      if ((int)*plVar1 != 0x101) {
        uVar5 = 2;
        goto LAB_183cf0a3c;
      }
      iVar3 = (int)plVar1[1];
      if (iVar3 == -0x80000000) {
        *param_1 = lVar6;
        *(int *)plVar1 = 0x102;
        plVar1[1] = 0x41e0000000000000;
      }
      else {
        iVar2 = -iVar3;
        if (-1 < iVar3) {
          iVar2 = iVar3;
        }
        *param_1 = lVar6;
        *(int *)plVar1 = 0x101;
        *(int *)(plVar1 + 1) = iVar2;
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}



/* ==== _type4_op_add @ 183cf0a68 size=116 ==== */

undefined8 _type4_op_add(long *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *param_1;
  if (lVar3 + 1U < 3) {
    uVar2 = 4;
  }
  else {
    *param_1 = lVar3 + -1;
    uVar1 = _type4_value_add(param_1 + lVar3 * 2 + -2,param_1 + lVar3 * 2 + -2,
                             param_1 + (lVar3 + -1) * 2 + 2);
    if ((uVar1 & 1) != 0) {
      return 1;
    }
    uVar2 = 2;
  }
  *(undefined4 *)(param_1 + 0x192) = uVar2;
  return 0;
}



/* ==== _type4_op_atan @ 183cf0adc size=280 ==== */

undefined8 _type4_op_atan(long *param_1)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  double dVar5;
  double dVar6;
  
  lVar3 = *param_1;
  if (lVar3 + 1U < 3) {
    uVar2 = 4;
    goto LAB_183cf0b98;
  }
  lVar4 = lVar3 + -1;
  *param_1 = lVar4;
  plVar1 = param_1 + lVar4 * 2 + 2;
  if ((int)*plVar1 == 0x102) {
    dVar6 = (double)plVar1[1];
LAB_183cf0b44:
    *param_1 = lVar3 + -2;
    plVar1 = param_1 + (lVar3 + -2) * 2 + 2;
    if ((int)*plVar1 == 0x102) {
      dVar5 = (double)plVar1[1];
    }
    else {
      if ((int)*plVar1 != 0x101) goto LAB_183cf0b70;
      dVar5 = (double)(int)plVar1[1];
    }
    if ((dVar6 != 0.0) || (dVar5 != 0.0)) {
      dVar6 = (double)func_0x00018814d290();
      dVar5 = (dVar6 * 180.0) / 3.141592653589793;
      dVar6 = dVar5 + 360.0;
      if (0.0 <= dVar5) {
        dVar6 = dVar5;
      }
      *param_1 = lVar4;
      *(int *)plVar1 = 0x102;
      plVar1[1] = (long)dVar6;
      return 1;
    }
    uVar2 = 5;
  }
  else {
    if ((int)*plVar1 == 0x101) {
      dVar6 = (double)(int)plVar1[1];
      goto LAB_183cf0b44;
    }
LAB_183cf0b70:
    uVar2 = 2;
  }
LAB_183cf0b98:
  *(undefined4 *)(param_1 + 0x192) = uVar2;
  return 0;
}



/* ==== _type4_op_ceiling @ 183cf0bf4 size=132 ==== */

undefined8 _type4_op_ceiling(long *param_1)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  double dVar5;
  
  lVar2 = *param_1;
  if (lVar2 + 1U < 2) {
    uVar4 = 4;
LAB_183cf0c6c:
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x192) = uVar4;
  }
  else {
    *param_1 = lVar2 + -1;
    plVar1 = param_1 + (lVar2 + -1) * 2 + 2;
    if ((int)*plVar1 == 0x102) {
      dVar5 = (double)plVar1[1];
      *param_1 = lVar2;
      *(int *)plVar1 = 0x102;
      plVar1[1] = (long)dVar5;
    }
    else {
      if ((int)*plVar1 != 0x101) {
        uVar4 = 2;
        goto LAB_183cf0c6c;
      }
      *param_1 = lVar2;
      *(int *)plVar1 = 0x101;
    }
    uVar3 = 1;
  }
  return uVar3;
}



/* ==== _type4_op_cos @ 183cf0c78 size=184 ==== */

undefined8 _type4_op_cos(long *param_1)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  long lVar4;
  double dVar5;
  long lVar6;
  
  lVar4 = *param_1;
  if (lVar4 + 1U < 2) {
    uVar3 = 4;
LAB_183cf0d1c:
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0x192) = uVar3;
  }
  else {
    *param_1 = lVar4 + -1;
    plVar1 = param_1 + (lVar4 + -1) * 2 + 2;
    if ((int)*plVar1 == 0x102) {
      dVar5 = (double)plVar1[1];
    }
    else {
      if ((int)*plVar1 != 0x101) {
        uVar3 = 2;
        goto LAB_183cf0d1c;
      }
      dVar5 = (double)(int)plVar1[1];
    }
    lVar6 = func_0x000188145d30((dVar5 * 3.141592653589793) / 180.0);
    *param_1 = lVar4;
    *(int *)plVar1 = 0x102;
    plVar1[1] = lVar6;
    uVar2 = 1;
  }
  return uVar2;
}



/* ==== _type4_op_cvi @ 183cf0d30 size=236 ==== */

undefined8 _type4_op_cvi(long *param_1)

{
  long *plVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  double local_28;
  
  lVar5 = *param_1;
  if (lVar5 + 1U < 2) {
    uVar3 = 4;
  }
  else {
    *param_1 = lVar5 + -1;
    plVar1 = param_1 + (lVar5 + -1) * 2 + 2;
    lVar2 = *plVar1;
    iVar4 = *(int *)((long)plVar1 + 4);
    lVar6 = plVar1[1];
    *param_1 = lVar5;
    if ((int)lVar2 == 0x102) {
      func_0x00018813b210(&local_28);
      if (-2147483648.0 <= local_28) {
        if (local_28 <= 2147483647.0) {
          *(int *)plVar1 = 0x101;
          *(int *)(plVar1 + 1) = (int)local_28;
          return 1;
        }
        iVar4 = 0x7fffffff;
      }
      else {
        iVar4 = -0x80000000;
      }
      *(int *)plVar1 = 0x101;
      *(int *)(plVar1 + 1) = iVar4;
      uVar3 = 1;
    }
    else {
      if ((int)lVar2 == 0x101) {
        *(int *)plVar1 = 0x101;
        *(int *)((long)plVar1 + 4) = iVar4;
        plVar1[1] = lVar6;
        return 1;
      }
      uVar3 = 2;
    }
  }
  *(undefined4 *)(param_1 + 0x192) = uVar3;
  return 0;
}



/* ==== _type4_op_cvr @ 183cf0e1c size=136 ==== */

undefined8 _type4_op_cvr(long *param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long lVar7;
  
  lVar7 = *param_1;
  if (lVar7 + 1U < 2) {
    uVar6 = 4;
LAB_183cf0e94:
    uVar5 = 0;
    *(undefined4 *)(param_1 + 0x192) = uVar6;
  }
  else {
    *param_1 = lVar7 + -1;
    plVar1 = param_1 + (lVar7 + -1) * 2 + 2;
    lVar3 = *plVar1;
    uVar5 = *(undefined8 *)((long)plVar1 + 4);
    lVar4 = plVar1[1];
    iVar2 = *(int *)((long)plVar1 + 0xc);
    *param_1 = lVar7;
    if ((int)lVar3 == 0x102) {
      *(int *)plVar1 = 0x102;
      *(undefined8 *)((long)plVar1 + 4) = uVar5;
      *(int *)((long)plVar1 + 0xc) = iVar2;
    }
    else {
      if ((int)lVar3 != 0x101) {
        uVar6 = 2;
        goto LAB_183cf0e94;
      }
      *(int *)plVar1 = 0x102;
      plVar1[1] = (long)(double)(int)lVar4;
    }
    uVar5 = 1;
  }
  return uVar5;
}



