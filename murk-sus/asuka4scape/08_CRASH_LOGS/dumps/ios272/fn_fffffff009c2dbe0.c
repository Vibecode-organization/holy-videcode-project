// FUN_fffffff009c2dbe0 @ fffffff009c2dbe0 size=164

void FUN_fffffff009c2dbe0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  undefined4 local_1c;
  long local_18;
  
  local_18 = *(long *)PTR_DAT_fffffff00806ca40;
  local_20 = 0xe00002c7;
  local_38 = param_2;
  local_30 = param_4;
  uStack_28 = param_3;
  if (((*(long *)(param_1 + 0x18) != 0) && (*(code **)(param_1 + 0x28) != (code *)0x0)) &&
     (*(long *)(param_1 + 0x20) != 0)) {
    local_1c = 0xaaaaaaaa;
    (**(code **)(param_1 + 0x28))(*(long *)(param_1 + 0x18),param_1,9,&local_38,0);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_18) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(local_20);
  return;
}

