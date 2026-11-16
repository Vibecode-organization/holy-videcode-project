// FUN_fffffff00995bbe4 @ fffffff00995bbe4 size=108

undefined8 FUN_fffffff00995bbe4(long param_1)

{
  long *plVar1;
  
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x38));
  if (plVar1 != (long *)0x0) {
    thunk_EXT_FUN_80110000032222a8(plVar1[3]);
    *(undefined1 *)((long)plVar1 + 0x5d) = 1;
    thunk_EXT_FUN_8011000003222de0(plVar1[3]);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return 0;
}

