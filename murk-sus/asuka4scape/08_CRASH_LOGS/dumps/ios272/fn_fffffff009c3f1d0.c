// FUN_fffffff009c3f1d0 @ fffffff009c3f1d0 size=224

/* WARNING: Removing unreachable block (ram,0xfffffff009c3f244) */

long * FUN_fffffff009c3f1d0(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  long local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  local_30 = 0;
  iVar1 = FUN_fffffff009c3f044(param_1,param_2,&local_30);
  if ((iVar1 == 0) || (plVar2 = *(long **)(local_30 + 0x40), plVar2 == (long *)0x0)) {
    plVar2 = (long *)0x0;
  }
  else if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_28) {
    plVar2 = (long *)thunk_EXT_FUN_8011000003a48590();
    return plVar2;
  }
  return plVar2;
}

