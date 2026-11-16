// FUN_fffffff009c287a4 @ fffffff009c287a4 size=196

void FUN_fffffff009c287a4(undefined8 param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if (param_2 == 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c28854);
      (*pcVar1)();
    }
    FUN_fffffff009c250a8(param_1,0,param_3);
    return;
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038d0088(param_2);
  FUN_fffffff009c250a8(param_1,plVar2,param_3);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c28824);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2882c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  return;
}

