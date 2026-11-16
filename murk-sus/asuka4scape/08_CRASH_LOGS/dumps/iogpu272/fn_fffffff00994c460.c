// FUN_fffffff00994c460 @ fffffff00994c460 size=60

void FUN_fffffff00994c460(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  lVar1 = 0;
  uVar4 = param_2[1];
  uVar3 = *param_2;
  uVar6 = param_2[3];
  uVar5 = param_2[2];
  uVar7 = param_2[4];
  uVar9 = param_2[7];
  uVar8 = param_2[6];
  param_3[5] = param_2[5];
  param_3[4] = uVar7;
  param_3[7] = uVar9;
  param_3[6] = uVar8;
  param_3[1] = uVar4;
  *param_3 = uVar3;
  param_3[3] = uVar6;
  param_3[2] = uVar5;
  *(undefined4 *)param_2 = 0;
  lVar2 = 0xf;
  do {
    *(undefined4 *)((long)param_2 + lVar1 * 4 + 4) = 0xff;
    lVar1 = lVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}

