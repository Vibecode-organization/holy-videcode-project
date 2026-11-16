// FUN_fffffff00997d844 @ fffffff00997d844 size=76

void FUN_fffffff00997d844(undefined8 *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 2) = 0x400;
  uVar1 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1bd8,0x4000);
  param_1[1] = uVar1;
  uVar1 = thunk_EXT_FUN_80110000038ff010();
  param_1[5] = uVar1;
  return;
}

