// FUN_fffffff009961b14 @ fffffff009961b14 size=72

void FUN_fffffff009961b14(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xc0));
  *(undefined8 *)(param_1 + 0xa8) = param_2;
  *(undefined8 *)(param_1 + 0xb0) = param_2;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009961b58);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xc0));
  return;
}

