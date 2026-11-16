// FUN_fffffff009c96e4c @ fffffff009c96e4c

void FUN_fffffff009c96e4c(long *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)(**(code **)(*param_1 + 0x118))(param_1,"ConfigurationType");
  plVar2 = thunk_FUN_fffffff00a894f30(plVar2,*(long *)PTR_PTR_fffffff00807fab0);
  if (plVar2 == (long *)0x0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c96ed4);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c96edc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0xb8))(plVar2,"ncmAuxOnly_fallback",(undefined8 *)(*plVar2 + 0xb8));
  return;
}

