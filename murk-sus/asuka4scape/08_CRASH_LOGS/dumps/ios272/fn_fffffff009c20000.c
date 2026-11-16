// FUN_fffffff009c20000 @ fffffff009c20000 size=56

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
  thunk_EXT_FUN_8011000003890f30(uVar2,*(undefined8 *)PTR_DAT_fffffff00806c9f0);
  return;
}

