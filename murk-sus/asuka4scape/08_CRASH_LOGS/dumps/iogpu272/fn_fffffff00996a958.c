// FUN_fffffff00996a958 @ fffffff00996a958 size=92

void FUN_fffffff00996a958(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009942d70();
  FUN_fffffff00996a9b4(param_1,*(undefined8 *)(param_2 + 0x28),param_3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996a9b0);
    (*pcVar1)();
  }
  FUN_fffffff009942d7c(param_1);
  return;
}

