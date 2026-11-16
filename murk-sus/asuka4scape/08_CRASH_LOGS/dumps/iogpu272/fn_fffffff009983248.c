// FUN_fffffff009983248 @ fffffff009983248 size=36

undefined8 FUN_fffffff009983248(void)

{
  undefined8 uVar1;
  
  if (DAT_fffffff00af220d0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009983260. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_fffffff00af220d0)();
    return uVar1;
  }
  return 0;
}

