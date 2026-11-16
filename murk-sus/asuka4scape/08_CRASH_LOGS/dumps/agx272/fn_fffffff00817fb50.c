// FUN_fffffff00817fb50 @ fffffff00817fb50 size=80

void FUN_fffffff00817fb50(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x4b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar3 + 0xbc0));
  uVar1 = *(undefined4 *)(lVar3 + 0xba0);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar3 + 0xbc0));
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817fb9c);
    (*pcVar2)();
  }
  thunk_EXT_FUN_80110000038c6e24(uVar1,0x20);
  return;
}

