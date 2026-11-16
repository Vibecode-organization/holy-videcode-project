// FUN_fffffff009983668 @ fffffff009983668 size=8

void FUN_fffffff009983668(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff009983670);
  (*pcVar1)();
}

