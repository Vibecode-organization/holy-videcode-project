// FUN_fffffff008215630 @ fffffff008215630 size=8

void FUN_fffffff008215630(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215638);
  (*pcVar1)();
}

