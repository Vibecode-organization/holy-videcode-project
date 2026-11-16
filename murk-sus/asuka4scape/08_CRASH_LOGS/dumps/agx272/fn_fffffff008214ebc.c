// FUN_fffffff008214ebc @ fffffff008214ebc size=8

void FUN_fffffff008214ebc(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008214ec4);
  (*pcVar1)();
}

