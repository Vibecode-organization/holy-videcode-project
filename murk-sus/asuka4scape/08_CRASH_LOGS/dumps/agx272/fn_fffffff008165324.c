// FUN_fffffff008165324 @ fffffff008165324 size=36

undefined8 FUN_fffffff008165324(void)

{
  undefined8 uVar1;
  
  if (DAT_fffffff00ae21828 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff00816533c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_fffffff00ae21828)();
    return uVar1;
  }
  return 0;
}

