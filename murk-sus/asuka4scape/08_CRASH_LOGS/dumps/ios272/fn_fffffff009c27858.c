// FUN_fffffff009c27858 @ fffffff009c27858 size=232

void FUN_fffffff009c27858(long param_1)

{
  undefined *puVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  puVar1 = PTR_DAT_fffffff00806ca48;
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff00806ca48,2,"IOSurface fence debug: surface: %p id: %d\n");
  thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,puVar1,2,"Current Fences:\n");
  lVar3 = *(long *)(param_1 + 0x240);
  while (lVar3 != 0) {
    lVar3 = *(long *)(lVar3 + 0x58);
    FUN_fffffff009c27be8();
  }
  thunk_EXT_FUN_80110000038db19c(&MACH_HEADER,PTR_DAT_fffffff00806ca48,2,"Waiting Fences:\n");
  lVar3 = *(long *)(param_1 + 0x250);
  while (lVar3 != 0) {
    lVar3 = *(long *)(lVar3 + 0x58);
    FUN_fffffff009c27be8();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    return;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c2793c);
  (*pcVar2)();
}

