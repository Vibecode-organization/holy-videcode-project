// FUN_fffffff0081fd1f8 @ fffffff0081fd1f8 size=108

undefined8 FUN_fffffff0081fd1f8(long *param_1)

{
  undefined8 uVar1;
  
  if ((*(byte *)(param_1 + 0x59) & 1) != 0) {
    return 1;
  }
  uVar1 = (**(code **)(*param_1 + 0x98))(param_1,2,0x1300000000,0x100000000);
  if ((int)uVar1 != 0) {
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0x59) = 1;
  }
  return uVar1;
}

