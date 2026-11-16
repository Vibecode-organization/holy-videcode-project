// FUN_fffffff0081b9fcc @ fffffff0081b9fcc size=144

undefined8 FUN_fffffff0081b9fcc(long param_1,undefined8 param_2)

{
  uint uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if (((plVar2 != (long *)0x0) && (uVar1 = (**(code **)(*plVar2 + 0xa8))(), uVar1 != 0)) &&
     (uVar1 <= *(uint *)(param_1 + 0xb70))) {
    uVar3 = 0;
    *(uint *)(param_1 + 0xb74) = uVar1;
    *(uint *)(*(long *)(param_1 + 0x348) + 0x98) = uVar1 * 100;
  }
  return uVar3;
}

