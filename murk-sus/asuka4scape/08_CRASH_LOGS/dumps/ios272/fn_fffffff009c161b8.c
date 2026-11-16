// FUN_fffffff009c161b8 @ fffffff009c161b8 size=104

void FUN_fffffff009c161b8(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 uStack_30;
  ulong local_28;
  ulong uStack_20;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_20 = param_2 >> 0x20;
  local_38 = param_4;
  uStack_30 = param_3;
  local_28 = param_2;
  thunk_EXT_FUN_80110000039a40ec(param_1 + 0x50,0,&local_38,4);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

