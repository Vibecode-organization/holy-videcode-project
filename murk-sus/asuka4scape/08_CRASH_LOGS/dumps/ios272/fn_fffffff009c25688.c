// FUN_fffffff009c25688 @ fffffff009c25688 size=96

void FUN_fffffff009c25688(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  FUN_fffffff009c250a8(param_1,param_2,param_3);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c256e4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return;
}

