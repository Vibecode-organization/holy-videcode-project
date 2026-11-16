// FUN_fffffff009c47644 @ fffffff009c47644 size=120

void FUN_fffffff009c47644(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x18);
  if (lVar2 != 0) {
    if ((*(byte *)(param_1 + 0x20) & 1) != 0) {
      FUN_fffffff009c2302c(lVar2,0);
      lVar2 = *(long *)(param_1 + 0x18);
    }
    *(undefined8 *)(param_1 + 0x18) = 0;
    FUN_fffffff009c37204(*(undefined8 *)(param_1 + 0x10),lVar2);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c476b0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c476b8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

