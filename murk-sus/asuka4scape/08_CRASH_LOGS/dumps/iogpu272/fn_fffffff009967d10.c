// FUN_fffffff009967d10 @ fffffff009967d10 size=276

undefined8 FUN_fffffff009967d10(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  long *plVar1;
  undefined8 uVar2;
  undefined1 auStack_858 [2048];
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff007ff2800;
  if (param_4 < 0x101) {
    uVar2 = 0xe00002c2;
    plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x10));
    if (plVar1 != (long *)0x0) {
      if ((char)plVar1[2] == '\x03') {
        (**(code **)(*plVar1 + 0x20))(plVar1);
        uVar2 = FUN_fffffff009967bc0(param_1,plVar1,auStack_858,param_3,param_4);
      }
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
    if (*(long *)PTR_DAT_fffffff007ff2800 == local_58) {
      return uVar2;
    }
  }
  else {
    FUN_fffffff009983c44();
  }
  uVar2 = thunk_EXT_FUN_8011000003a48590();
  return uVar2;
}

