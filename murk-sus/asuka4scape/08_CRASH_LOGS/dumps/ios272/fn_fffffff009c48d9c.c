// FUN_fffffff009c48d9c @ fffffff009c48d9c size=36

undefined8 FUN_fffffff009c48d9c(void)

{
  undefined8 uVar1;
  
  if (DAT_fffffff00af48110 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c48db4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*DAT_fffffff00af48110)();
    return uVar1;
  }
  return 0;
}

