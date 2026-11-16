// FUN_fffffff009975b64 @ fffffff009975b64 size=104

bool FUN_fffffff009975b64(long param_1,long param_2)

{
  bool bVar1;
  
  if ((*(byte *)(param_2 + 0x5c8) & 1) == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x2c0));
    bVar1 = (*(uint *)(param_1 + 0x1e0) & 0x80) == 0;
    if ((*(uint *)(param_1 + 0x1e0) >> 7 & 1) == 0) {
      *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x2c0));
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

