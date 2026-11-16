// FUN_fffffff008215640 @ fffffff008215640 size=8

void FUN_fffffff008215640(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215648);
  (*pcVar1)();
}

