// FUN_fffffff009c20000 @ fffffff009c20000 size=56
// CALLERS:
//   fffffff009c1b1ec FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e3b8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c2b198 FUN_fffffff009c2b164@fffffff009c2b164

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff009c20000(void)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar2 = FUN_fffffff009c2b130();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c20034);
    (*pcVar1)();
  }
  FUN_fffffff009c498d4(uVar2,*_DAT_fffffff00806c9f0);
  return;
}

