// FUN_fffffff00816ab48 @ fffffff00816ab48 size=28

void FUN_fffffff00816ab48(void)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  if (*(int *)PTR_DAT_fffffff007ca6198 == 0) {
    return;
  }
  uVar2 = thunk_EXT_FUN_801100000390ebc0();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816ab9c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000036da494(0x85180019,uVar2,0,0,0,0);
  return;
}

