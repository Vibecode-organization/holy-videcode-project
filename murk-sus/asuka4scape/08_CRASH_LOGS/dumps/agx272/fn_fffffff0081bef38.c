// FUN_fffffff0081bef38 @ fffffff0081bef38 size=132

undefined8 FUN_fffffff0081bef38(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (plVar2 == (long *)0x0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar1 = (**(code **)(*plVar2 + 0xa8))();
    uVar3 = 0;
    if (99 < uVar1) {
      uVar1 = 100;
    }
    *(uint *)(*(long *)(param_1 + 0x348) + 0xb4) = uVar1;
  }
  return uVar3;
}

