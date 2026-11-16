// FUN_fffffff009c393d0 @ fffffff009c393d0 size=4

void FUN_fffffff009c393d0(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_2c = 0;
  FUN_fffffff009c3d760(param_1,**(undefined4 **)(param_3 + 0x20),&uStack_2c);
  **(ulong **)(param_3 + 0x48) = (ulong)uStack_2c;
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

