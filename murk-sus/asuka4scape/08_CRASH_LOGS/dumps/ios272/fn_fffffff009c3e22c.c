// FUN_fffffff009c3e22c @ fffffff009c3e22c size=344

/* WARNING: Removing unreachable block (ram,0xfffffff009c3e2a8) */

undefined8
FUN_fffffff009c3e22c
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar3 = 0xe00002c2;
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 != (long *)0x0) {
    local_50 = (long *)0x0;
    lVar2 = *(long *)(param_1 + 0xf8);
    if (lVar2 == 0) {
      lVar2 = 0;
    }
    uVar3 = thunk_EXT_FUN_80110000039a3bc0(lVar2,param_4,&local_50);
    if ((int)uVar3 == 0) {
      lVar2 = thunk_EXT_FUN_8011000003890f30(local_50,DAT_fffffff0080668c8);
      uVar3 = 0xe00002c2;
      if (lVar2 != 0) {
        uVar3 = FUN_fffffff009c16750();
        uVar3 = FUN_fffffff009c211dc(plVar1,param_3,uVar3,param_5);
      }
    }
    if (local_50 != (long *)0x0) {
      (**(code **)(*local_50 + 0x28))();
    }
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

