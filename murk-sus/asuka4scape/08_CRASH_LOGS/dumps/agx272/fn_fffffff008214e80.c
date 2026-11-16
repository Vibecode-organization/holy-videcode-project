// FUN_fffffff008214e80 @ fffffff008214e80 size=4

void FUN_fffffff008214e80(void)

{
  code *pcVar1;
  
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! not implemented!\n");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0xfffffff008214ec4);
  (*pcVar1)();
}

