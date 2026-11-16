// FUN_fffffff009c2d778 @ fffffff009c2d778 size=308

void FUN_fffffff009c2d778(long *param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  ulong unaff_x30;
  
  plVar3 = (long *)param_1[2];
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x20))(plVar3);
  }
  FUN_fffffff009c2a738(plVar3);
  if (((((*(byte *)((long)param_1 + 0x5a) & 1) == 0) || ((*(byte *)((long)param_1 + 0x59) & 1) != 0)
       ) || (iVar2 = FUN_fffffff009c23440(plVar3), iVar2 == 0)) ||
     (iVar2 = (**(code **)(*param_1 + 0x18))(param_1), iVar2 != 1)) {
    (**(code **)(PTR_DAT_fffffff00806ca30 + 0x38))(param_1);
  }
  else {
    FUN_fffffff009c1feb4(param_1[2],param_1);
    (**(code **)(*(long *)param_1[2] + 0x28))();
  }
  FUN_fffffff009c2a744(plVar3);
  if (plVar3 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2d894);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c2d89c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
    return;
  }
  return;
}

