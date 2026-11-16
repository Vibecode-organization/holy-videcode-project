// FUN_fffffff0081ffcf4 @ fffffff0081ffcf4 size=204

long * FUN_fffffff0081ffcf4(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  code *pcVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong unaff_x30;
  
  if (param_4 == 2) {
    uVar4 = *(undefined8 *)(param_1 + 0x48);
    plVar2 = (long *)(**(code **)(DAT_fffffff00ae22130 + 0x68))();
    uVar3 = thunk_EXT_FUN_801100000294de3c(plVar2,uVar4,param_2,param_3,0x1001);
    if (((uVar3 & 1) == 0) && (plVar2 != (long *)0x0)) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
    return plVar2;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081ffdb4);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081ffdbc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  plVar2 = (long *)(**(code **)(PTR_DAT_fffffff007ca60d0 + 0xb8))();
  return plVar2;
}

