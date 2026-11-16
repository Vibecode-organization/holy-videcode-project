// FUN_fffffff009c3760c @ fffffff009c3760c size=268

void FUN_fffffff009c3760c(long param_1,undefined8 param_2)

{
  long *plVar1;
  undefined *local_60;
  undefined8 local_58;
  code *local_50;
  undefined *local_48;
  undefined8 uStack_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x228));
  plVar1 = (long *)thunk_EXT_FUN_8011000003896344(*(undefined8 *)(param_1 + 0x220),0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x228));
  if (plVar1 != (long *)0x0) {
    local_60 = PTR_DAT_fffffff00806c9b8;
    local_58 = DAT_fffffff0078a1280;
    local_50 = FUN_fffffff009c37718;
    local_48 = &DAT_fffffff0080684e0;
    uStack_40 = param_2;
    thunk_EXT_FUN_801100000389794c(&local_48,plVar1,&local_60);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

