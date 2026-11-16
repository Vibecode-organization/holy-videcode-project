// FUN_fffffff009976ba0 @ fffffff009976ba0 size=208

undefined8 FUN_fffffff009976ba0(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0xe00002bd;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x458));
  if (**(long **)(param_1 + 0x430) == 0) {
    lVar1 = FUN_fffffff00994e6a4(param_2);
    *(long *)(param_1 + 0x428) = lVar1;
    if (lVar1 != 0) {
      **(undefined8 **)(param_1 + 0x430) = param_2;
      (**(code **)(*param_2 + 0x20))(param_2);
      uVar2 = 0;
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: attempted to reset notification queue\n");
    uVar2 = 0xe00002c9;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x458));
  return uVar2;
}

