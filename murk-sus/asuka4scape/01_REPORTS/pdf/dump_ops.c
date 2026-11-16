/* ==== _type4_op_copy @ 183cf1fe8 size=180 ==== */

undefined8 _type4_op_copy(ulong *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar6 = *param_1;
  if (1 < uVar6 + 1) {
    uVar4 = uVar6 - 1;
    *param_1 = uVar4;
    if ((int)param_1[uVar4 * 2 + 2] != 0x101) {
      uVar3 = 2;
      goto LAB_183cf2064;
    }
    uVar1 = (uint)(param_1 + uVar4 * 2 + 2)[1];
    uVar5 = (ulong)uVar1;
    if ((int)uVar1 < 0) {
      uVar3 = 1;
      goto LAB_183cf2064;
    }
    if (uVar1 == 0) {
      return 1;
    }
    if (uVar5 + 1 <= uVar6) {
      if (uVar4 + uVar5 < 0xc9) {
        do {
          uVar6 = param_1[(uVar4 - (long)(int)uVar1) * 2 + 2];
          (param_1 + uVar4 * 2 + 2)[1] = (param_1 + (uVar4 - (long)(int)uVar1) * 2 + 2)[1];
          param_1[uVar4 * 2 + 2] = uVar6;
          uVar4 = uVar4 + 1;
          uVar2 = (int)uVar5 - 1;
          uVar5 = (ulong)uVar2;
        } while (uVar2 != 0);
        *param_1 = uVar4;
        return 1;
      }
      uVar3 = 3;
      goto LAB_183cf2064;
    }
  }
  uVar3 = 4;
LAB_183cf2064:
  *(undefined4 *)(param_1 + 0x192) = uVar3;
  return 0;
}



/* ==== _type4_op_dup @ 183cf209c size=84 ==== */

undefined8 _type4_op_dup(ulong *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong uVar3;
  
  uVar1 = *param_1;
  uVar3 = uVar1 + 1;
  if (uVar3 < 2) {
    uVar2 = 4;
  }
  else {
    if (uVar3 < 0xc9) {
      *param_1 = uVar3;
      uVar3 = param_1[uVar1 * 2];
      (param_1 + uVar1 * 2 + 2)[1] = (param_1 + uVar1 * 2)[1];
      param_1[uVar1 * 2 + 2] = uVar3;
      return 1;
    }
    uVar2 = 3;
  }
  *(undefined4 *)(param_1 + 0x192) = uVar2;
  return 0;
}



/* ==== _type4_op_index @ 183cf2150 size=136 ==== */

undefined8 _type4_op_index(ulong *param_1)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 uVar4;
  ulong uVar5;
  
  uVar3 = *param_1;
  if (1 < uVar3 + 1) {
    uVar5 = uVar3 - 1;
    *param_1 = uVar5;
    puVar1 = param_1 + uVar5 * 2 + 2;
    if ((int)*puVar1 != 0x101) {
      uVar4 = 2;
      goto LAB_183cf21cc;
    }
    uVar2 = (uint)puVar1[1];
    if ((int)uVar2 < 0) {
      uVar4 = 1;
      goto LAB_183cf21cc;
    }
    if ((ulong)uVar2 + 2 <= uVar3) {
      *param_1 = uVar3;
      uVar3 = param_1[(uVar5 + (long)(int)~uVar2) * 2 + 2];
      puVar1[1] = (param_1 + (uVar5 + (long)(int)~uVar2) * 2 + 2)[1];
      *puVar1 = uVar3;
      return 1;
    }
  }
  uVar4 = 4;
LAB_183cf21cc:
  *(undefined4 *)(param_1 + 0x192) = uVar4;
  return 0;
}



/* ==== _type4_op_pop @ 183cf21d8 size=44 ==== */

bool _type4_op_pop(ulong *param_1)

{
  ulong uVar1;
  
  uVar1 = *param_1 - 1;
  if (uVar1 < 0xfffffffffffffffe) {
    *param_1 = uVar1;
  }
  else {
    *(undefined4 *)(param_1 + 0x192) = 4;
  }
  return uVar1 < 0xfffffffffffffffe;
}



/* ==== _type4_op_roll @ 183cf2204 size=524 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _type4_op_roll(ulong *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  ulong *puVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong local_ce0 [401];
  long local_58;
  
  local_58 = *_DAT_1e0186220;
  uVar14 = *param_1;
  if (uVar14 + 1 < 3) {
LAB_183cf2248:
    uVar6 = 4;
  }
  else {
    uVar11 = uVar14 - 1;
    *param_1 = uVar11;
    if ((int)param_1[uVar11 * 2 + 2] == 0x101) {
      iVar8 = (int)(param_1 + uVar11 * 2 + 2)[1];
      uVar9 = uVar14 - 2;
      *param_1 = uVar9;
      if ((int)param_1[uVar9 * 2 + 2] == 0x101) {
        uVar2 = (uint)(param_1 + uVar9 * 2 + 2)[1];
        uVar13 = (ulong)uVar2;
        if ((int)uVar2 < 1) {
          uVar6 = 1;
          goto LAB_183cf2340;
        }
        if (uVar11 < uVar13 + 1) goto LAB_183cf2248;
        if (uVar2 != 1) {
          iVar10 = 0;
          if (uVar2 != 0) {
            iVar10 = iVar8 / (int)uVar2;
          }
          if ((iVar8 + uVar2 == 0 || (int)(iVar8 + uVar2) < 0 != SCARRY4(iVar8,uVar2)) ||
              (int)uVar2 <= iVar8) {
            iVar8 = iVar8 - iVar10 * uVar2;
          }
          uVar1 = (uVar2 & iVar8 >> 0x1f) + iVar8;
          uVar11 = (ulong)uVar1;
          if (uVar1 != 0) {
            puVar12 = param_1 + (uVar9 - uVar13) * 2 + 2;
            if ((int)(uVar2 >> 1) < (int)uVar1) {
              uVar2 = uVar2 - uVar1;
              if (0 < (int)uVar2) {
                func_0x0001881384d0(local_ce0,puVar12,(ulong)uVar2 << 4);
              }
              lVar7 = 0;
              uVar9 = uVar11;
              do {
                uVar15 = puVar12[(lVar7 + (int)uVar2) * 2];
                (puVar12 + lVar7 * 2)[1] = (puVar12 + (lVar7 + (int)uVar2) * 2)[1];
                puVar12[lVar7 * 2] = uVar15;
                lVar7 = lVar7 + 1;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
              if (0 < (int)uVar2) {
                puVar12 = param_1 + uVar13 * -2 + (uVar14 + uVar11) * 2 + -2;
                uVar11 = (ulong)uVar2;
LAB_183cf23f4:
                func_0x0001881384d0(puVar12,local_ce0,uVar11 << 4);
              }
            }
            else {
              uVar3 = uVar2 - uVar1;
              if (0 < (int)uVar1) {
                lVar7 = 0;
                uVar9 = (ulong)uVar3;
                uVar14 = uVar11;
                do {
                  uVar13 = puVar12[(long)(int)uVar9 * 2];
                  local_ce0[lVar7 * 2 + 1] = (puVar12 + (long)(int)uVar9 * 2)[1];
                  local_ce0[lVar7 * 2] = uVar13;
                  lVar7 = lVar7 + 1;
                  uVar9 = (ulong)((int)uVar9 + 1);
                  uVar14 = uVar14 - 1;
                } while (uVar14 != 0);
              }
              if (0 < (int)uVar3) {
                lVar7 = -(ulong)uVar3;
                iVar8 = uVar2 - 1;
                iVar10 = iVar8 - uVar1;
                do {
                  uVar14 = puVar12[(long)iVar10 * 2];
                  (puVar12 + (long)iVar8 * 2)[1] = (puVar12 + (long)iVar10 * 2)[1];
                  puVar12[(long)iVar8 * 2] = uVar14;
                  iVar10 = iVar10 + -1;
                  iVar8 = iVar8 + -1;
                  bVar4 = lVar7 != -1;
                  lVar7 = lVar7 + 1;
                } while (bVar4);
              }
              if (0 < (int)uVar1) goto LAB_183cf23f4;
            }
          }
        }
        uVar5 = 1;
        goto LAB_183cf2344;
      }
    }
    uVar6 = 2;
  }
LAB_183cf2340:
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0x192) = uVar6;
LAB_183cf2344:
  if (*_DAT_1e0186220 == local_58) {
    return;
  }
  func_0x000188138130(uVar5);
  return;
}



/* ==== _type4_program_execute @ 183e12488 size=192 ==== */

undefined8 _type4_program_execute(ulong *param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  
  if (*param_1 == 0) {
    return 1;
  }
  uVar4 = 0;
  uVar5 = param_1[2];
  do {
    plVar1 = (long *)(uVar5 + uVar4 * 0x10);
    if ((int)*plVar1 == 0x104) {
      uVar2 = (*(code *)plVar1[1])(param_2);
      if ((uVar2 & 1) == 0) {
        return 0;
      }
    }
    else {
      lVar3 = *param_2;
      if (lVar3 == 200) {
        *(undefined4 *)(param_2 + 0x192) = 3;
        return 0;
      }
      *param_2 = lVar3 + 1;
      lVar6 = *plVar1;
      (param_2 + lVar3 * 2 + 2)[1] = plVar1[1];
      param_2[lVar3 * 2 + 2] = lVar6;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < *param_1);
  return 1;
}



