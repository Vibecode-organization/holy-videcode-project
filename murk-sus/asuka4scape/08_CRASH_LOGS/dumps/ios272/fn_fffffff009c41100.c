// FUN_fffffff009c41100 @ fffffff009c41100 size=124

void FUN_fffffff009c41100(long *param_1)

{
  code *pcVar1;
  int iVar2;
  ulong unaff_x30;
  
  iVar2 = FUN_fffffff009c46ff8((long)param_1 + 0xc,3,2);
  if (iVar2 != 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c41170);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c41178. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x78))(param_1,(undefined8 *)(*param_1 + 0x78));
  return;
}

