// FUN_fffffff0099443e4 @ fffffff0099443e4 size=64

undefined8 FUN_fffffff0099443e4(long param_1)

{
  undefined8 uVar1;
  
  FUN_fffffff009944424();
  **(undefined8 **)(param_1 + 0x18) = 1;
  uVar1 = thunk_EXT_FUN_80110000038ff134();
  *(undefined8 *)(param_1 + 0x20) = uVar1;
  return 1;
}

