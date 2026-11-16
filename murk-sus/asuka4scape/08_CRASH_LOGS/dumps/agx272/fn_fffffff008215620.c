// FUN_fffffff008215620 @ fffffff008215620 size=8

void FUN_fffffff008215620(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215628);
  (*pcVar1)();
}

