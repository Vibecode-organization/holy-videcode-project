// FUN_fffffff0082140d8 @ fffffff0082140d8 size=240

void FUN_fffffff0082140d8(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x1a8);
  if ((*(byte *)(lVar2 + 0x1ac44) >> 3 & 1) != 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930ca9,0,0,0,0,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x1ac48));
  }
  (**(code **)(PTR_DAT_fffffff007ca6100 + 0x88))(param_1);
  FUN_fffffff00816b2a8(*(undefined8 *)(param_1 + 0x1a8));
  lVar2 = *(long *)(param_1 + 0x1a8);
  if ((*(byte *)(lVar2 + 0x1ac44) >> 3 & 1) == 0) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(0x85930caa,0,0,0,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0082141c4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x1ac48));
  return;
}

