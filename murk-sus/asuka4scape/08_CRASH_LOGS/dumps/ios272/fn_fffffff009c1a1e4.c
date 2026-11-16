// FUN_fffffff009c1a1e4 @ fffffff009c1a1e4 size=24

void FUN_fffffff009c1a1e4(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a1f8);
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48ee0
            (
            "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
            );
}

