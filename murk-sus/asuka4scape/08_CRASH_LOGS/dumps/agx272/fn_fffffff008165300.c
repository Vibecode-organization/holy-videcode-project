// FUN_fffffff008165300 @ fffffff008165300 size=36

undefined8 FUN_fffffff008165300(void)

{
  undefined8 uVar1;
  
  if (DAT_fffffff00ae21820 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008165318. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_fffffff00ae21820)();
    return uVar1;
  }
  return 0;
}

