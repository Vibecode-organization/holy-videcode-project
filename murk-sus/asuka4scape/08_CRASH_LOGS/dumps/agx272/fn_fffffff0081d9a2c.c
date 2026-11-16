// FUN_fffffff0081d9a2c @ fffffff0081d9a2c size=124

long FUN_fffffff0081d9a2c(long param_1,long param_2)

{
  long lVar1;
  
  if (param_2 < 3) {
    if (param_2 == 0) {
      return param_1;
    }
    if (param_2 != 1) {
code_r0xfffffff0081d9a74:
      lVar1 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Unsupported protection type\n");
      return lVar1;
    }
    lVar1 = 0x2d8;
  }
  else if (param_2 == 7) {
    lVar1 = 0x2e8;
  }
  else {
    if (param_2 != 3) goto code_r0xfffffff0081d9a74;
    lVar1 = 0x2e0;
  }
  return *(long *)(param_1 + lVar1);
}

