// FUN_fffffff00995bc50 @ fffffff00995bc50 size=64

void FUN_fffffff00995bc50(long param_1)

{
  long lVar1;
  
  LOAcquire();
  lVar1 = *(long *)(param_1 + 0x40);
  *(long *)(param_1 + 0x40) = lVar1 + 1;
  LORelease();
  if ((lVar1 + 1 == *(long *)(param_1 + 0x48)) && ((*(byte *)(param_1 + 0x50) & 1) != 0)) {
    thunk_EXT_FUN_8011000003246024(param_1,0,0);
    return;
  }
  return;
}

