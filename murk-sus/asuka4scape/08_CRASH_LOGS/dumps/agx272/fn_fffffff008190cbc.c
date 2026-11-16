// FUN_fffffff008190cbc @ fffffff008190cbc size=168

void FUN_fffffff008190cbc(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  if ((((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a9d) & 1) != 0) &&
      (*(long *)(param_1 + 0x548) != param_2)) && (*(long *)(param_1 + 0x610) != 0)) {
    plVar2 = *(long **)(*(long *)(param_1 + 0x610) + 0xa8);
    (**(code **)(*plVar2 + 0x98))(plVar2,0,0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008190d58);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008190d60. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ca6130 + 200))(param_1,param_2);
  return;
}

