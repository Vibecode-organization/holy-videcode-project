// FUN_fffffff009c17fe8 @ fffffff009c17fe8 size=136

void FUN_fffffff009c17fe8(long *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong unaff_x30;
  
  if (param_2 != 1) {
    lVar3 = FUN_fffffff009c48e80();
    FUN_fffffff009c46fb8(lVar3 + 0xc);
    return;
  }
  iVar2 = FUN_fffffff009c46ff8((long)param_1 + 0xc,3,2);
  if (iVar2 != 0) {
    return;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c18060);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c18068. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x78))(param_1,(undefined8 *)(*param_1 + 0x78));
  return;
}

