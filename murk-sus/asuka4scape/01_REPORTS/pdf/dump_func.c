/* ==== _function_evaluate @ 183b83708 size=696 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _function_evaluate(long param_1,long param_2,long param_3,float *param_4)

{
  undefined8 uVar1;
  long lVar2;
  long extraout_x8;
  long extraout_x8_00;
  long lVar3;
  long lVar4;
  ulong extraout_x12;
  ulong extraout_x12_00;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined1 *puVar9;
  ulong uVar10;
  undefined1 local_90 [16];
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [8];
  long local_68;
  
  local_68 = *_DAT_1e0186220;
  if (param_1 == 0) {
    (*_DAT_1e1f91910)();
    puVar5 = auStack_80;
    uVar1 = (*_DAT_1e1f91910)();
    puVar6 = local_90;
    FUN_183b7ffbc(uVar1,puVar5,puVar6);
    if (param_4 == (float *)0x0) goto LAB_183b83838;
    lVar2 = -1;
    puVar7 = puVar5;
    puVar9 = puVar6;
LAB_183b837ec:
    lVar3 = 0;
    lVar4 = lVar2;
    do {
      *(float *)(param_3 + lVar3 * 4) = (float)*(double *)(puVar6 + lVar3 * 8);
      lVar3 = lVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
LAB_183b8380c:
    *param_4 = (float)*(double *)(puVar6 + lVar2 * 8);
  }
  else {
    uVar10 = *(ulong *)(param_1 + 0x20);
    uVar8 = *(ulong *)(param_1 + 0x30);
    if (uVar10 >> 0x3d == 0) {
      lVar2 = 1;
      if (uVar10 < 0x11) {
        lVar2 = uVar10 * 8 + 1;
      }
      uVar1 = (*_DAT_1e1f91910)(lVar2 + 0xfU & 0xfffffffffffffff0);
      puVar7 = auStack_70 + -extraout_x8;
      puVar5 = (undefined1 *)0x0;
      if (uVar10 != 0x1fffffffffffffff) {
        puVar5 = puVar7;
      }
      if (extraout_x12 <= uVar10 + 0xe000000000000001) {
        puVar5 = (undefined1 *)func_0x000188138470(uVar1,0xfa81f361);
      }
    }
    else {
      (*_DAT_1e1f91910)();
      puVar7 = auStack_80;
      puVar5 = (undefined1 *)0x0;
    }
    if (uVar8 >> 0x3d == 0) {
      lVar2 = 1;
      if (uVar8 < 0x11) {
        lVar2 = uVar8 * 8 + 1;
      }
      uVar1 = (*_DAT_1e1f91910)(lVar2 + 0xfU & 0xfffffffffffffff0);
      puVar9 = puVar7 + -extraout_x8_00;
      puVar6 = (undefined1 *)0x0;
      if (uVar8 != 0x1fffffffffffffff) {
        puVar6 = puVar9;
      }
      if (extraout_x12_00 <= uVar8 + 0xe000000000000001) {
        puVar6 = (undefined1 *)func_0x000188138470(uVar1,0xff38ec47);
      }
    }
    else {
      (*_DAT_1e1f91910)();
      puVar9 = puVar7 + -0x10;
      puVar6 = (undefined1 *)0x0;
    }
    if (uVar10 != 0) {
      lVar2 = 0;
      do {
        *(double *)(puVar5 + lVar2 * 8) = (double)*(float *)(param_2 + lVar2 * 4);
        lVar2 = lVar2 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    FUN_183b7ffbc(param_1,puVar5,puVar6);
    if (param_4 != (float *)0x0) {
      lVar2 = uVar8 - 1;
      if (lVar2 != 0) goto LAB_183b837ec;
      goto LAB_183b8380c;
    }
    if (uVar8 != 0) {
      lVar2 = 0;
      do {
        *(float *)(param_3 + lVar2 * 4) = (float)*(double *)(puVar6 + lVar2 * 8);
        lVar2 = lVar2 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  if (puVar6 != puVar9) {
    func_0x000188138390(puVar6);
  }
  if (puVar5 != puVar7) {
    func_0x000188138390(puVar5);
  }
LAB_183b83838:
  if (*_DAT_1e0186220 != local_68) {
    func_0x000188138130();
    return;
  }
  return;
}



/* ==== _evaluated_function_evaluate @ 183d78b24 size=192 ==== */

void _evaluated_function_evaluate(ulong *param_1,double *param_2,long param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  double dVar7;
  double dVar8;
  
  dVar7 = (double)param_1[2];
  dVar8 = 0.0;
  if (dVar7 < (double)param_1[3]) {
    dVar8 = (*param_2 - dVar7) / ((double)param_1[3] - dVar7);
  }
  dVar7 = 1.0;
  if (dVar8 <= 1.0) {
    dVar7 = dVar8;
  }
  dVar8 = 0.0;
  if (0.0 <= dVar7) {
    dVar8 = dVar7;
  }
  uVar2 = param_1[1];
  dVar8 = dVar8 * (double)(*param_1 - 1);
  lVar5 = (long)dVar8;
  uVar3 = param_1[4];
  lVar1 = uVar3 + uVar2 * lVar5 * 8;
  if (lVar5 + 1U < *param_1) {
    lVar6 = (lVar5 + 1U) * uVar2;
    if (uVar2 != 0) {
      lVar4 = 0;
      do {
        dVar7 = *(double *)(lVar1 + lVar4 * 8);
        *(double *)(param_3 + lVar4 * 8) =
             dVar7 + (*(double *)(uVar3 + lVar6 * 8 + lVar4 * 8) - dVar7) * (dVar8 - (double)lVar5);
        lVar4 = lVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
  }
  else if (uVar2 != 0) {
    lVar5 = 0;
    do {
      *(undefined8 *)(param_3 + lVar5 * 8) = *(undefined8 *)(lVar1 + lVar5 * 8);
      lVar5 = lVar5 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



/* ==== _function_evaluate_float @ 183dc33e4 size=360 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _function_evaluate_float(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  ulong extraout_x8;
  long lVar4;
  long extraout_x12;
  long lVar5;
  long lVar6;
  undefined1 auStack_60 [8];
  long local_58;
  
  local_58 = *_DAT_1e0186220;
  if (param_1 == 0) {
    lVar6 = 0;
    lVar5 = 0;
  }
  else {
    lVar6 = *(long *)(param_1 + 0x20);
    lVar5 = *(long *)(param_1 + 0x30);
  }
  uVar2 = (*_DAT_1e1f91910)((lVar5 + lVar6) * 8);
  puVar3 = (undefined1 *)0x0;
  if (extraout_x8 < 0x1fffffffffffffff) {
    puVar3 = auStack_60 + -extraout_x12;
  }
  if (0xe000000000000011 < extraout_x8 + 0xe000000000000001) {
    puVar3 = (undefined1 *)func_0x000188138470(uVar2,0x4d5b39ac);
  }
  lVar1 = lVar6 * 8;
  if (lVar6 != 0) {
    lVar4 = 0;
    do {
      *(double *)(puVar3 + lVar4 * 8) = (double)*(float *)(param_2 + lVar4 * 4);
      lVar4 = lVar4 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  FUN_183b7ffbc(param_1,puVar3,puVar3 + lVar1);
  if (lVar5 != 0) {
    lVar6 = 0;
    do {
      *(float *)(param_3 + lVar6 * 4) = (float)*(double *)(puVar3 + lVar1 + lVar6 * 8);
      lVar6 = lVar6 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  if (puVar3 != auStack_60 + -extraout_x12) {
    func_0x000188138390(puVar3);
  }
  if (*_DAT_1e0186220 == local_58) {
    return;
  }
  func_0x000188138130();
  return;
}



/* ==== _shading_function_array_evaluate @ 183e7f3c8 size=108 ==== */

void _shading_function_array_evaluate(ulong *param_1,undefined8 param_2,long param_3)

{
  ulong uVar1;
  
  if (*param_1 != 0) {
    uVar1 = 0;
    do {
      FUN_183b7ffbc(param_1[uVar1 + 1],param_2,param_3 + uVar1 * 8);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *param_1);
  }
  return;
}



/* ==== FUN_183f98b4c @ 183f98b4c size=192 ==== */

undefined4 * FUN_183f98b4c(long param_1,long param_2)

{
  undefined4 *puVar1;
  long lVar2;
  
  puVar1 = (undefined4 *)func_0x000188138470(0x58,0x10a004092955682);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 1;
  if (param_1 == 0) {
    *(undefined8 *)(puVar1 + 4) = 0;
    if (param_2 == 0) {
      lVar2 = 0;
      *(undefined8 *)(puVar1 + 6) = 0;
      goto LAB_183f98bc4;
    }
  }
  else {
    func_0x000188141250(param_1);
    *(long *)(puVar1 + 4) = param_1;
    if (param_2 == 0) {
      *(undefined8 *)(puVar1 + 6) = 0;
      lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x30);
      goto LAB_183f98bc4;
    }
  }
  func_0x000188141250(param_2);
  *(long *)(puVar1 + 6) = param_2;
  lVar2 = 1;
LAB_183f98bc4:
  *(long *)(puVar1 + 2) = lVar2;
  *(long *)(puVar1 + 8) = lVar2 * 8 + 0x10;
  *(undefined8 *)(puVar1 + 0xc) = 0;
  *(undefined8 *)(puVar1 + 10) = 0;
  *(undefined8 *)(puVar1 + 0x10) = 0;
  *(undefined8 *)(puVar1 + 0xe) = 0;
  *(undefined8 *)(puVar1 + 0x14) = 0;
  *(undefined8 *)(puVar1 + 0x12) = 0;
  return puVar1;
}



