// FUN_fffffff009c21550 @ fffffff009c21550 size=116

undefined8
FUN_fffffff009c21550(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (*(long *)(param_1 + 0x30) == 0) {
    uVar1 = 0xe00002c2;
  }
  else {
    uVar1 = thunk_EXT_FUN_8011000003977b2c(*(long *)(param_1 + 0x30),param_2,param_3,param_4);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return uVar1;
}

