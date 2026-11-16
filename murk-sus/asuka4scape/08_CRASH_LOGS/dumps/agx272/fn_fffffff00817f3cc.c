// FUN_fffffff00817f3cc @ fffffff00817f3cc size=204

/* WARNING: Removing unreachable block (ram,0xfffffff00817f458) */

void FUN_fffffff00817f3cc(long *param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  (**(code **)(*param_1 + 0x718))(param_1,"",0);
  thunk_EXT_FUN_80110000038ff064(param_1[0x234c],param_2,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00817f494. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x710))(param_1,"",0,*param_1 + 0x710);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817f48c);
  (*pcVar1)();
}

