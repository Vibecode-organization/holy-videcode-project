// FUN_fffffff009983324 @ fffffff009983324 size=8

void FUN_fffffff009983324(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff00998332c);
  (*pcVar1)();
}

