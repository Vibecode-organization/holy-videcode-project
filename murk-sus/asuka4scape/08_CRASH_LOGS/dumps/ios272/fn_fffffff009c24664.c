// FUN_fffffff009c24664 @ fffffff009c24664 size=188

void FUN_fffffff009c24664(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = (long *)thunk_EXT_FUN_801100000389a264(param_3,param_4);
  if (plVar2 == (long *)0x0) {
    return;
  }
  (**(code **)(*param_1 + 0x100))(param_1,param_2,plVar2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c24704);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2470c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
  return;
}

