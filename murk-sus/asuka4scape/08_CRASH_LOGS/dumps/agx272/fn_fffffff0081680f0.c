// FUN_fffffff0081680f0 @ fffffff0081680f0 size=200

void FUN_fffffff0081680f0(long *param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)(**(code **)(*param_1 + 0x148))(param_1,"CoreConfig");
  if (plVar2 == (long *)0x0) {
    return;
  }
  (**(code **)(*param_1 + 200))(param_1,"GPUConfigurationVariable",plVar2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081681a0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081681a8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
  return;
}

