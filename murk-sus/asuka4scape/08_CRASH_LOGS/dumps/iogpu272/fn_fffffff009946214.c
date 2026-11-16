// FUN_fffffff009946214 @ fffffff009946214 size=140

void FUN_fffffff009946214
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  FUN_fffffff009952228(param_1 + 0x70,1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009946294);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00994629c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(PTR_DAT_fffffff007ff27e8 + 0x138))
            (param_1,param_2,param_3,param_4,param_5,PTR_DAT_fffffff007ff27e8 + 0x138);
  return;
}

