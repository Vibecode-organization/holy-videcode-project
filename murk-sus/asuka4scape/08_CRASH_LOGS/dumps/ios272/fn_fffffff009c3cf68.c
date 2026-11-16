// FUN_fffffff009c3cf68 @ fffffff009c3cf68 size=208

undefined8
FUN_fffffff009c3cf68(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  undefined4 local_3c;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    local_3c = 0xaaaaaaaa;
    uVar2 = FUN_fffffff009c20f04(plVar1,param_3,&local_3c);
    if ((int)uVar2 == 0) {
      uVar2 = thunk_EXT_FUN_8011000003386690(&local_3c,param_4,4);
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar2;
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

