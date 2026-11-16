// FUN_fffffff00817d70c @ fffffff00817d70c size=136

void FUN_fffffff00817d70c(long *param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817d788);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00817d790. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x148))(param_1,uVar2,(undefined8 *)(*param_1 + 0x148));
  return;
}

