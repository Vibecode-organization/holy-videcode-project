// FUN_fffffff00995b2ec @ fffffff00995b2ec size=120

undefined8 FUN_fffffff00995b2ec(long param_1,long *param_2)

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  if (*(long *)(param_1 + 0x28) == 0) {
    *(long **)(param_1 + 0x28) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xe00002c9;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
  return uVar1;
}

