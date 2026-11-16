// FUN_fffffff00817fbd0 @ fffffff00817fbd0 size=8

void FUN_fffffff00817fbd0(void)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = thunk_EXT_FUN_801100000338f868();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817fbfc);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038c6e24(uVar2,0x40);
  return;
}

