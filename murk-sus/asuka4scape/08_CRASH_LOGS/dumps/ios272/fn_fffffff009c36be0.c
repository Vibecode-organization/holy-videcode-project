// FUN_fffffff009c36be0 @ fffffff009c36be0 size=140

ulong FUN_fffffff009c36be0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  ulong uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  uVar1 = FUN_fffffff009c3692c
                    (param_1 + 0x138,param_2,0x20,*(undefined4 *)(param_1 + 0x1a8),param_3,param_4);
  if ((uVar1 & 1) == 0) {
    thunk_EXT_FUN_80110000038fe9a0("IOSurfaceAgentMask alloc failed");
  }
  else {
    param_4 = (undefined8 *)*param_4;
    param_4[1] = 0;
    *param_4 = 0;
    param_4[3] = 0;
    param_4[2] = 0;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
  return uVar1;
}

