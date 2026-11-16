// FUN_fffffff009c1a1fc @ fffffff009c1a1fc size=24

void FUN_fffffff009c1a1fc(void)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1a210);
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48ee0
            (
            "This bounded_ptr is pointing to memory outside of what can be represented by a native pointer."
            );
}

