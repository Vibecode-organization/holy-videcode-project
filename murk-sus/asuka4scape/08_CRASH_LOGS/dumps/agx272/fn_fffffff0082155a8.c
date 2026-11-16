// FUN_fffffff0082155a8 @ fffffff0082155a8 size=4

void FUN_fffffff0082155a8(void)

{
  code *pcVar1;
  
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! not implemented!\n");
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Asking to update mappings, should never happen\n");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008215628);
  (*pcVar1)();
}

