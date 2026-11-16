// FUN_fffffff00995a4ac @ fffffff00995a4ac size=140

void FUN_fffffff00995a4ac(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (DAT_fffffff00af227e8 != 0) {
    thunk_EXT_FUN_80110000036da494(0x85180174,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xa0));
  if ((*(byte *)(param_1 + 0xa8) & 1) == 0) {
    *(undefined1 *)(param_1 + 0xa8) = 1;
    if (*(long *)(param_1 + 0x98) != 0) {
      thunk_EXT_FUN_8011000003277760();
    }
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995a534);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xa0));
  return;
}

