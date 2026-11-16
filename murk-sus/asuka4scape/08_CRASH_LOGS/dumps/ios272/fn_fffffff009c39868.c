// FUN_fffffff009c39868 @ fffffff009c39868 size=4

void FUN_fffffff009c39868(undefined8 param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  ulong uStack_38;
  uint uStack_2c;
  long lStack_28;
  
  lStack_28 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_2c = 0;
  uStack_38 = 0;
  FUN_fffffff009c3dad4(param_1,**(undefined8 **)(param_3 + 0x20),&uStack_2c,&uStack_38);
  puVar1 = *(ulong **)(param_3 + 0x48);
  *puVar1 = (ulong)uStack_2c;
  puVar1[1] = uStack_38;
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

