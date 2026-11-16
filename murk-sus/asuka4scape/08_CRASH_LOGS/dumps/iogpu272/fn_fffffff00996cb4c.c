// FUN_fffffff00996cb4c @ fffffff00996cb4c size=188

void FUN_fffffff00996cb4c(undefined8 param_1,long *param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x20);
  if (plVar2 == (long *)0x0) {
    return;
  }
  (**(code **)(*param_2 + 0x100))(param_2,param_4,plVar2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996cbec);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00996cbf4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
  return;
}

