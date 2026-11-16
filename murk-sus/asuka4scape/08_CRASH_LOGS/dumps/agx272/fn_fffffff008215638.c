// FUN_fffffff008215638 @ fffffff008215638 size=8

void FUN_fffffff008215638(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215640);
  (*pcVar1)();
}

