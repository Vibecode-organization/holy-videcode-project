// FUN_fffffff009c3999c @ fffffff009c3999c size=4

undefined8 FUN_fffffff009c3999c(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  long lStack_40;
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar3 = 0xe00002c2;
  iVar1 = *(int *)(*(long *)(param_3 + 0x20) + 8);
  lStack_40 = 0;
  if ((iVar1 - 1U < 0xfffffffe) &&
     (iVar1 = thunk_EXT_FUN_801100000329a6d4(iVar1,&lStack_40), iVar1 == 0)) {
    if (lStack_40 == 0) {
      uVar3 = 0xe00002c7;
    }
    else {
      puVar2 = *(undefined4 **)(param_3 + 0x20);
      uVar3 = FUN_fffffff009c3d408(param_1,*puVar2,lStack_40,puVar2[4],puVar2[6]);
      thunk_EXT_FUN_801100000326c730(lStack_40);
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_38) {
    return uVar3;
  }
  uVar3 = thunk_EXT_FUN_8011000003a48590();
  return uVar3;
}

