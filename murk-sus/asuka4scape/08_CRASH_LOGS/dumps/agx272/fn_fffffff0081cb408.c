// FUN_fffffff0081cb408 @ fffffff0081cb408 size=208

void FUN_fffffff0081cb408(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000297b408(*(undefined8 *)(param_1 + 0x14a0));
  thunk_EXT_FUN_801100000297b408(*(undefined8 *)(param_1 + 0x1470));
  lVar2 = 0;
  lVar3 = 0x3c;
  do {
    if (*(long *)(param_1 + 0x14f0 + lVar2 * 8) != 0) {
      thunk_EXT_FUN_801100000297b408();
    }
    lVar2 = lVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  if (*(long *)(param_1 + 0x17c0) != 0) {
    thunk_EXT_FUN_801100000297b408();
  }
  lVar2 = *(long *)(param_1 + 0x14a8);
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
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081cb4d4);
    (*pcVar1)();
  }
  FUN_fffffff0081a7a84(param_1);
  return;
}

