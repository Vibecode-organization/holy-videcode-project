// FUN_fffffff009c17428 @ fffffff009c17428 size=204

long * FUN_fffffff009c17428(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = (long *)0x0;
  iVar1 = thunk_EXT_FUN_80110000039a3bc0(param_1,param_2,&local_30);
  if ((iVar1 == 0) &&
     (lVar2 = thunk_EXT_FUN_8011000003890f30(local_30,&DAT_fffffff00af48170), lVar2 != 0)) {
    plVar3 = *(long **)(lVar2 + 0x10);
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
    }
  }
  else {
    plVar3 = (long *)0x0;
  }
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return plVar3;
  }
  plVar3 = (long *)thunk_EXT_FUN_8011000003a48590();
  return plVar3;
}

