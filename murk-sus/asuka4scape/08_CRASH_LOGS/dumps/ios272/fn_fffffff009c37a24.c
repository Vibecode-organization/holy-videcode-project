// FUN_fffffff009c37a24 @ fffffff009c37a24 size=112

void FUN_fffffff009c37a24(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x230));
  if ((*(long *)(param_1 + 0x380) == param_2) && (*(long *)(param_1 + 0x388) == param_3)) {
    *(undefined8 *)(param_1 + 0x388) = 0;
    *(undefined8 *)(param_1 + 0x380) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37a90);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x230));
  return;
}

