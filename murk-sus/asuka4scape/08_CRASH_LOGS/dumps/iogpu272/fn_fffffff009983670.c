// FUN_fffffff009983670 @ fffffff009983670 size=8

void FUN_fffffff009983670(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff009983678);
  (*pcVar1)();
}

