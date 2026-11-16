// FUN_fffffff0081dd99c @ fffffff0081dd99c size=152

void FUN_fffffff0081dd99c(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0xd0))(param_1,"MetalPluginClassName","AGXG14Device");
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081dda28);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081dda30. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd0))
            (param_1,"MetalStatisticsName","AGXMetalStatisticsExternalG14",
             (undefined8 *)(*param_1 + 0xd0));
  return;
}

