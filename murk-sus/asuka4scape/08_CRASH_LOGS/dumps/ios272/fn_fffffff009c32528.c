// FUN_fffffff009c32528 @ fffffff009c32528 size=136

ulong FUN_fffffff009c32528(long param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  ulong uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  uVar1 = FUN_fffffff009c3692c
                    (param_1 + 0x130,param_2,8,*(undefined4 *)(param_1 + 0x1a8),param_3,param_4);
  if ((uVar1 & 1) == 0) {
    thunk_EXT_FUN_80110000038fe9a0("IOSurfaceSharedRO alloc failed");
  }
  else {
    *(undefined8 *)*param_4 = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
  return uVar1;
}

