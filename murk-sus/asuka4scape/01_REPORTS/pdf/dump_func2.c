/* ==== FUN_183b343f4 @ 183b343f4 size=228 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_183b343f4(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  undefined1 auStack_40 [8];
  long local_38;
  
  local_38 = *_DAT_1e0186220;
  if (param_1 != 0) {
    if (param_1 < 0) {
      lVar1 = _CGTaggedColorGetNumberOfComponents();
      lVar1 = lVar1 * 8;
      (*_DAT_1e1f91910)();
      puVar3 = auStack_40 + -(lVar1 + 0xfU & 0xfffffffffffffff0);
      func_0x0001881382e0(puVar3,lVar1);
      _CGTaggedColorGetComponents(param_1,puVar3);
      uVar2 = func_0x000188140a80(0,puVar3,lVar1);
      param_1 = func_0x000188140aa0();
      func_0x000188140600(uVar2);
    }
    else {
      param_1 = param_1 + 0x48;
    }
  }
  if (*_DAT_1e0186220 == local_38) {
    return;
  }
  func_0x000188138130(param_1);
  return;
}



/* ==== FUN_183f98f10 @ 183f98f10 size=128 ==== */

void FUN_183f98f10(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  
  if (((param_1 != 0) && (param_3 != 0)) && (lVar1 = _add_triangle(), lVar1 != 0)) {
    lVar4 = 0;
    lVar5 = 3;
    do {
      puVar3 = *(undefined8 **)(param_3 + lVar4 * 8);
      uVar2 = _add_point(*puVar3,puVar3[1],param_1,param_2,puVar3 + 2);
      *(undefined8 *)(lVar1 + lVar4 * 8) = uVar2;
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
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



