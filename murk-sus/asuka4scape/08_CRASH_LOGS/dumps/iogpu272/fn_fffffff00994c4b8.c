// FUN_fffffff00994c4b8 @ fffffff00994c4b8 size=80

void FUN_fffffff00994c4b8(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  uVar4 = param_3[1];
  uVar2 = *param_3;
  uVar8 = param_3[3];
  uVar6 = param_3[2];
  uVar5 = param_3[5];
  uVar3 = param_3[4];
  uVar9 = param_3[7];
  uVar7 = param_3[6];
  uVar1 = FUN_fffffff00994c508();
  if ((uVar1 & 1) == 0) {
    param_3[1] = uVar4;
    *param_3 = uVar2;
    param_3[3] = uVar8;
    param_3[2] = uVar6;
    param_3[5] = uVar5;
    param_3[4] = uVar3;
    param_3[7] = uVar9;
    param_3[6] = uVar7;
  }
  return;
}

