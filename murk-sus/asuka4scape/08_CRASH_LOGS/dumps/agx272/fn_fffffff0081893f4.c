// FUN_fffffff0081893f4 @ fffffff0081893f4 size=204

void FUN_fffffff0081893f4(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x30);
  if (lVar2 != 0) {
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
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
  }
  lVar2 = *(long *)(param_1 + 0x278);
  if (lVar2 != 0) {
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
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081894b0);
      (*pcVar1)();
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x40));
    return;
  }
  return;
}

