// FUN_fffffff0081c413c @ fffffff0081c413c size=4

void FUN_fffffff0081c413c(long *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x3a8))();
  DataMemoryBarrier(2,3);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1[0x122] + 0x4c00) = 0;
    DataMemoryBarrier(2,3);
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Firmware wasn\'t stopped for post-recovery\n")
  ;
  return;
}

