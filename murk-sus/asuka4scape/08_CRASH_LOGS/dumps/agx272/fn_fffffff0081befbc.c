// FUN_fffffff0081befbc @ fffffff0081befbc size=140

undefined8 FUN_fffffff0081befbc(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (plVar2 == (long *)0x0) {
    uVar3 = 0xe00002c2;
  }
  else {
    uVar1 = (**(code **)(*plVar2 + 0xa8))();
    uVar3 = 0;
    lVar4 = *(long *)(param_1 + 0x348);
    *(undefined1 *)(lVar4 + 0xbc) = 1;
    if (99 < uVar1) {
      uVar1 = 100;
    }
    *(uint *)(lVar4 + 0xb0) = uVar1;
  }
  return uVar3;
}

