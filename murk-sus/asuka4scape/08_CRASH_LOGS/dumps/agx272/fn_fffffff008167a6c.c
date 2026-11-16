// FUN_fffffff008167a6c @ fffffff008167a6c size=60

void FUN_fffffff008167a6c(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x90))();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008167aa4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000039788dc();
  return;
}

