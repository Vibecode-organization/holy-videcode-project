// FUN_fffffff00820e668 @ fffffff00820e668 size=148

undefined8 FUN_fffffff00820e668(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,*(undefined8 *)PTR_DAT_fffffff007ca6020);
  *(long **)(param_1 + 0x20) = plVar1;
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002bc;
  }
  else {
    (**(code **)(*plVar1 + 0x20))();
    uVar2 = 0;
    if (*(long **)(param_1 + 0x28) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x28) + 0x78))();
      uVar2 = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  return uVar2;
}

