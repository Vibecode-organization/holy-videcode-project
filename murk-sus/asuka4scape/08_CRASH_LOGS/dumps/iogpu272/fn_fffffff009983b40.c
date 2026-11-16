// FUN_fffffff009983b40 @ fffffff009983b40 size=48

void FUN_fffffff009983b40(void)

{
  code *pcVar1;
  
  thunk_EXT_FUN_8011000003a49114
            ("\"IO Procssing Queue IO list Not Empty on IOGPUIOCommandQueue free\" @%s:%d");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff009983b78);
  (*pcVar1)();
}

