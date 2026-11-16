// FUN_fffffff0082155e8 @ fffffff0082155e8 size=56

void FUN_fffffff0082155e8(void)

{
  code *pcVar1;
  
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Asking to update mappings, should never happen\n");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215628);
  (*pcVar1)();
}

