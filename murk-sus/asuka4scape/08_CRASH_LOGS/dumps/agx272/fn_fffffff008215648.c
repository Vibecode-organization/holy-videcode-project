// FUN_fffffff008215648 @ fffffff008215648 size=8

void FUN_fffffff008215648(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215650);
  (*pcVar1)();
}

