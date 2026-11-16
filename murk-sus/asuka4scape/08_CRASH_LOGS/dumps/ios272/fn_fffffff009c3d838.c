// FUN_fffffff009c3d838 @ fffffff009c3d838 size=208

ulong FUN_fffffff009c3d838
                (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = 0xe00002c2;
  plVar3 = (long *)FUN_fffffff009c3f1d0();
  if (plVar3 == (long *)0x0) {
    *param_4 = 0xa0;
  }
  else {
    local_40 = 0x84;
    FUN_fffffff009c26438(plVar3,param_3,&local_40);
    uVar1 = 0;
    if (local_40 != 0x84) {
      uVar1 = uVar2;
    }
    *param_4 = 0xa0;
    (**(code **)(*plVar3 + 0x28))(plVar3);
    uVar2 = uVar1;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return (ulong)uVar2;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

