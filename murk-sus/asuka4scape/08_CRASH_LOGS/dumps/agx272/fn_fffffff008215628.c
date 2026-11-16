// FUN_fffffff008215628 @ fffffff008215628 size=8

void FUN_fffffff008215628(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215630);
  (*pcVar1)();
}

