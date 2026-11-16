// FUN_fffffff0081d6310 @ fffffff0081d6310 size=120

void FUN_fffffff0081d6310(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x115b0);
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x40));
  if (0 < *(long *)(lVar2 + 0x38)) {
    if (*(long *)(lVar2 + 0x50) != 0) {
      thunk_EXT_FUN_801100000297b408();
    }
    if (*(long *)(lVar2 + 0x58) != 0) {
      thunk_EXT_FUN_801100000297b408();
    }
    *(long *)(lVar2 + 0x38) = *(long *)(lVar2 + 0x38) + -1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d6384);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
  return;
}

