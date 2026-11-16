// FUN_fffffff00997a918 @ fffffff00997a918 size=156

void FUN_fffffff00997a918(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(byte *)((long)param_1 + 0x43a) & 1) == 0) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    FUN_fffffff009976f64(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0xa4) = 4;
  }
  iVar1 = FUN_fffffff009962f24(*(undefined8 *)(param_1[0xa6] + 0x160),param_1);
  if ((int)param_1[0xa8] != iVar1) {
    uVar2 = FUN_fffffff009962ebc(*(undefined8 *)(param_1[0xa6] + 0x160),param_1);
    (**(code **)(*param_1 + 0xe8))(param_1,uVar2);
    *(int *)(param_1 + 0xa8) = iVar1;
  }
  return;
}

