// FUN_fffffff0081e16d0 @ fffffff0081e16d0 size=120

void FUN_fffffff0081e16d0(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0xd0);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *(undefined8 *)(param_1 + 0xd0) = 0;
  *(undefined8 *)(param_1 + 0xd8) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e173c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e1744. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6118 + 0x80))();
  return;
}

