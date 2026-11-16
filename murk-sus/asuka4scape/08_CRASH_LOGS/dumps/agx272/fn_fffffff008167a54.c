// FUN_fffffff008167a54 @ fffffff008167a54 size=28

void FUN_fffffff008167a54(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x1ac60) == (long *)0x0) {
    return;
  }
  (**(code **)(**(long **)(param_1 + 0x1ac60) + 0x90))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008167aa4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000039788dc();
  return;
}

