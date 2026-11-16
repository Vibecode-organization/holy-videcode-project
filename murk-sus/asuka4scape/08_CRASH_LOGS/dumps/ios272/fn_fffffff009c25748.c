// FUN_fffffff009c25748 @ fffffff009c25748 size=96

undefined8 FUN_fffffff009c25748(long param_1)

{
  uint uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if ((*(byte *)(param_1 + 0x3d0) >> 5 & 1) != 0) {
    FUN_fffffff009c206fc(param_1);
    uVar1 = *(uint *)(param_1 + 0x3d0);
    *(uint *)(param_1 + 0x3d0) = uVar1 & 0xffffffdf;
    if ((uVar1 >> 4 & 1) != 0) {
      *(uint *)(param_1 + 0x3d0) = uVar1 & 0xffffffcf;
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return 0;
}

