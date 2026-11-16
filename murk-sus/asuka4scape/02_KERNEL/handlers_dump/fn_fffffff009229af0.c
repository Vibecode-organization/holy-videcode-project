// FUN_fffffff009229af0 @ fffffff009229af0 size=32 depth=1
// CALLERS:
//   fffffff00afdc898 ?
//   fffffff009251d9c FUN_fffffff009251d7c
//   fffffff009251e48 FUN_fffffff009251e28
// CALLS:
//   fffffff0092523a0 FUN_fffffff0092523a0

void FUN_fffffff009229af0
               (long *param_1,undefined1 param_2 [16],undefined1 param_3 [16],undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009229b0c);
    (*pcVar1)();
  }
  FUN_fffffff0092523a0(param_2,param_3,param_4,param_5,param_6,param_7,param_1,"admin",0);
  return;
}

