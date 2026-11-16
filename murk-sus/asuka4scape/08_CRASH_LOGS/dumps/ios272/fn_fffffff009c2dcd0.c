// FUN_fffffff009c2dcd0 @ fffffff009c2dcd0 size=88

void FUN_fffffff009c2dcd0(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009c2085c(*(undefined8 *)(param_1 + 0x10),param_2,0);
  if ((int)param_2 == 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2dd18);
    (*pcVar1)();
  }
  FUN_fffffff009c20588(*(undefined8 *)(param_1 + 0x10));
  return;
}

