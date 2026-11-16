// FUN_fffffff009c399a0 @ fffffff009c399a0 size=196

undefined8 FUN_fffffff009c399a0(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  long local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar3 = 0xe00002c2;
  iVar1 = *(int *)(*(long *)(param_3 + 0x20) + 8);
  local_40 = 0;
  if ((iVar1 - 1U < 0xfffffffe) &&
     (iVar1 = thunk_EXT_FUN_801100000329a6d4(iVar1,&local_40), iVar1 == 0)) {
    if (local_40 == 0) {
      uVar3 = 0xe00002c7;
    }
    else {
      puVar2 = *(undefined4 **)(param_3 + 0x20);
      uVar3 = FUN_fffffff009c3d408(param_1,*puVar2,local_40,puVar2[4],puVar2[6]);
      thunk_EXT_FUN_801100000326c730(local_40);
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_38) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

