// FUN_fffffff009945c50 @ fffffff009945c50 size=148

void FUN_fffffff009945c50
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009952228(param_1 + 0xe4,1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009945cd8);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009945ce0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27f0 + 0x138))
            (param_1,param_2,param_3,param_4,param_5,param_6,PTR_DAT_fffffff007ff27f0 + 0x138);
  return;
}

