// FUN_fffffff009c1a750 @ fffffff009c1a750 size=40

void FUN_fffffff009c1a750(void)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = FUN_fffffff009c1a53c();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a774);
    (*pcVar1)();
  }
  FUN_fffffff009c1a778(uVar2,0x3e0);
  return;
}

