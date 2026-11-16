// FUN_fffffff009c3d16c @ fffffff009c3d16c size=252

/* WARNING: Removing unreachable block (ram,0xfffffff009c3d1c0) */

undefined8 FUN_fffffff009c3d16c(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  long lVar2;
  long *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = (long *)0x0;
  lVar2 = *(long *)(param_1 + 0xf8);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  uVar1 = thunk_EXT_FUN_80110000039a3bc0(lVar2,param_2,&local_30);
  if ((int)uVar1 == 0) {
    lVar2 = thunk_EXT_FUN_8011000003890f30(local_30,DAT_fffffff0080668c8);
    if (lVar2 == 0) {
      uVar1 = 0xe00002c2;
    }
    else {
      uVar1 = FUN_fffffff009c16750();
      FUN_fffffff009c16ef8(uVar1,param_3);
      uVar1 = 0;
    }
  }
  if (local_30 != (long *)0x0) {
    (**(code **)(*local_30 + 0x28))();
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

