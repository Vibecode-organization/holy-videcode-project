// FUN_fffffff009c4616c @ fffffff009c4616c size=136

/* WARNING: Removing unreachable block (ram,0xfffffff009c46260) */

void FUN_fffffff009c4616c(long *param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  ulong unaff_x30;
  
  if (param_3 != 1) {
    plVar3 = (long *)FUN_fffffff009c49400();
    iVar2 = FUN_fffffff009c46ff8(plVar3 + 4,3,2);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c4626c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar3 + 0x78))(plVar3,(undefined8 *)(*plVar3 + 0x78));
      return;
    }
    return;
  }
  iVar2 = FUN_fffffff009c46ff8(param_1 + 4,3,2);
  if (iVar2 == 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c461ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x78))(param_1,(undefined8 *)(*param_1 + 0x78));
      return;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c461e4);
    (*pcVar1)();
  }
  return;
}

