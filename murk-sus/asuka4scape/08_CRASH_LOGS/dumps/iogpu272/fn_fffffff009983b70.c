// FUN_fffffff009983b70 @ fffffff009983b70 size=8

void FUN_fffffff009983b70(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff009983b78);
  (*pcVar1)();
}

