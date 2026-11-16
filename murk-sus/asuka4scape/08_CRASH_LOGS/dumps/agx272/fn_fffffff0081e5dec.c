// FUN_fffffff0081e5dec @ fffffff0081e5dec size=124

void FUN_fffffff0081e5dec(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  *(undefined8 *)(param_1 + 0x70) = 0;
  plVar2 = *(long **)(param_1 + 0x58);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *(undefined8 *)(param_1 + 0x58) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e5e5c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e5e64. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6180 + 0x80))();
  return;
}

