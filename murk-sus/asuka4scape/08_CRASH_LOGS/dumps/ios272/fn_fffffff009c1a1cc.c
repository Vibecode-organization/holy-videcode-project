// FUN_fffffff009c1a1cc @ fffffff009c1a1cc size=24

void FUN_fffffff009c1a1cc(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a1e0);
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48ee0
            (
            "bounded_ptr<T>::operator+=(n): Adding the specified number of bytes to the offset representing the current position would overflow."
            );
}

