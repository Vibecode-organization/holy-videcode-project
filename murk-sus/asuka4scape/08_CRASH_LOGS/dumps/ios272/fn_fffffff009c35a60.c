// FUN_fffffff009c35a60 @ fffffff009c35a60 size=116

void FUN_fffffff009c35a60(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x150));
  for (plVar2 = *(long **)(param_1 + 0x188); plVar2 != (long *)0x0; plVar2 = (long *)*plVar2) {
    FUN_fffffff009c3f6c0(plVar2[0xb],plVar2,param_2,*(undefined4 *)(param_3 + 0x10));
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x150));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c35ad0);
  (*pcVar1)();
}

