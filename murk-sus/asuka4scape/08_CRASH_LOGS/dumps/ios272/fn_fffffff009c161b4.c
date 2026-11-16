// FUN_fffffff009c161b4 @ fffffff009c161b4 size=4

void FUN_fffffff009c161b4(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uStack_38;
  undefined8 uStack_30;
  ulong uStack_28;
  ulong uStack_20;
  long lStack_18;
  
  lStack_18 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_20 = param_2 >> 0x20;
  uStack_38 = param_4;
  uStack_30 = param_3;
  uStack_28 = param_2;
  thunk_EXT_FUN_80110000039a40ec(param_1 + 0x50,0,&uStack_38,4);
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_18) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

