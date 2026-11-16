// FUN_fffffff0081beeb8 @ fffffff0081beeb8 size=128

undefined8 FUN_fffffff0081beeb8(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  uVar3 = 0xe00002c2;
  plVar2 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
  if ((plVar2 != (long *)0x0) && (iVar1 = (**(code **)(*plVar2 + 0xa8))(), 0xfffffff9 < iVar1 - 7U))
  {
    uVar3 = 0;
    *(int *)(*(long *)(param_1 + 0x348) + 0xb8) = iVar1;
  }
  return uVar3;
}

