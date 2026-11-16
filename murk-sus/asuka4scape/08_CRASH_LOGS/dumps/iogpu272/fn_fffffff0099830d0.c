// FUN_fffffff0099830d0 @ fffffff0099830d0 size=184

undefined8 FUN_fffffff0099830d0(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x28));
  if (*(long *)(param_1 + 0x20) == 0) {
    (**(code **)(**(long **)(param_1 + 0x10) + 0x98))(*(long **)(param_1 + 0x10),param_2);
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0x20) = param_2;
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: attempted to reset notification port!\n");
    uVar1 = 0xe00002c9;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x28));
  return uVar1;
}

