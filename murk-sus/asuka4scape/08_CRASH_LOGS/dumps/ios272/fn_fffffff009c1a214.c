// FUN_fffffff009c1a214 @ fffffff009c1a214 size=24

void FUN_fffffff009c1a214(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a228);
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48ee0
            (
            "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
            );
}

