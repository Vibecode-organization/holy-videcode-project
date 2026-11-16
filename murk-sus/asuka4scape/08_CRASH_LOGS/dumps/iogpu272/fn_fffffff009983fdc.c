// FUN_fffffff009983fdc @ fffffff009983fdc size=8

void FUN_fffffff009983fdc(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff009983fe4);
  (*pcVar1)();
}

