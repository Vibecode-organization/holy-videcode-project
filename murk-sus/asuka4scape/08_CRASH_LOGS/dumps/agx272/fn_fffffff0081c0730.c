// FUN_fffffff0081c0730 @ fffffff0081c0730 size=252

undefined4 FUN_fffffff0081c0730(long *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x6c8))();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    iVar1 = (**(code **)(*param_1 + 0x6b0))(param_1,1);
    if (param_2 != iVar1) {
      uVar2 = 2;
      iVar1 = (**(code **)(*param_1 + 0x6b0))(param_1,2);
      if (param_2 != iVar1) {
        iVar1 = (**(code **)(*param_1 + 0x6b0))(param_1,3);
        uVar2 = 3;
        if (param_2 != iVar1) {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}

