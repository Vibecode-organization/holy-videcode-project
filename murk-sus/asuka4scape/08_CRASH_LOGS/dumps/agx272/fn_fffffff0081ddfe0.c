// FUN_fffffff0081ddfe0 @ fffffff0081ddfe0 size=152

void FUN_fffffff0081ddfe0(long *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*param_1 + 0x768))();
  param_2[1] = 0x29cc000029cc;
  *param_2 = 0x29cc000029cc;
  param_2[2] = 0x29cc000029cc;
  *(undefined4 *)(param_2 + 3) = 0x29cc;
  param_2[5] = 0x29cc000029cc;
  param_2[4] = 0x29cc000029cc;
  param_2[7] = 0x29cc000029cc;
  param_2[6] = 0x29cc000029cc;
  if (iVar1 == 5) {
    *(undefined4 *)(param_2 + 3) = 0x1194;
    uVar2 = 600;
    uVar3 = 6;
  }
  else {
    uVar2 = 4000;
    uVar3 = 7;
  }
  *(undefined4 *)((long)param_2 + 0x1c) = uVar2;
  *(undefined4 *)(param_2 + 8) = 500;
  *(undefined4 *)((long)param_2 + 0x44) = uVar3;
  param_2[9] = 0x100000001;
  return;
}

