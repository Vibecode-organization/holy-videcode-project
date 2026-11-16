// FUN_fffffff008171ec8 @ fffffff008171ec8 size=196

void FUN_fffffff008171ec8
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  undefined *puVar1;
  long lVar2;
  code *UNRECOVERED_JUMPTABLE;
  ulong unaff_x30;
  
  UNRECOVERED_JUMPTABLE = *(code **)(PTR_DAT_fffffff007ca6170 + 0x5e8);
  puVar1 = PTR_DAT_fffffff007ca6170 + 0x5e8;
  lVar2 = (*UNRECOVERED_JUMPTABLE)();
  if (lVar2 != 0) {
    return;
  }
  FUN_fffffff00816b2a8(param_1);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff008171f88);
    (*UNRECOVERED_JUMPTABLE)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008171f88. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (param_1,param_2,param_3,param_4,param_5,
             (ulong)puVar1 & 0xffffffffffff | 0x41d3000000000000);
  return;
}

