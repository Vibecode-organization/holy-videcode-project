// FUN_fffffff009983224 @ fffffff009983224 size=36

undefined8 FUN_fffffff009983224(void)

{
  undefined8 uVar1;
  
  if (DAT_fffffff00af220c8 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00998323c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_fffffff00af220c8)();
    return uVar1;
  }
  return 0;
}

