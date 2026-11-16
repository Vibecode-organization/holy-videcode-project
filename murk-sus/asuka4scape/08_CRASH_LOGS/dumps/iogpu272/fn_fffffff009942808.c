// FUN_fffffff009942808 @ fffffff009942808 size=160

void FUN_fffffff009942808(long param_1,ulong param_2,undefined1 param_3)

{
  ulong uVar1;
  
  if (*(long *)(param_1 + 200) != 0) {
    uVar1 = (**(code **)(**(long **)(param_1 + 0xb8) + 0xb0))();
    if ((param_2 & 0xffffffff) < uVar1) {
      *(undefined1 *)(*(long *)(param_1 + 200) + (param_2 & 0xffffffff)) = param_3;
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Out of bounds access to residency data\n");
    }
  }
  return;
}

