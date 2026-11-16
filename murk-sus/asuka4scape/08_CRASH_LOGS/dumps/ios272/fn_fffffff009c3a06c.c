// FUN_fffffff009c3a06c @ fffffff009c3a06c size=4

void FUN_fffffff009c3a06c(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  uint uStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_2c = 0;
  if (**(long **)(param_3 + 0x20) == 0) {
    uVar1 = 0xe00002c2;
  }
  else {
    uVar1 = FUN_fffffff009c3c8d4(param_1,**(long **)(param_3 + 0x20),&uStack_2c);
    **(ulong **)(param_3 + 0x48) = (ulong)uStack_2c;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar1);
  return;
}

