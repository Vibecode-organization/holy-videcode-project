// FUN_fffffff009c433d0 @ fffffff009c433d0 size=156

void FUN_fffffff009c433d0(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x18);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0xe0))(plVar2,0);
    if (*(long **)(param_1 + 0x18) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
    }
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c43460);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c43468. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
  return;
}

