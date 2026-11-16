// FUN_fffffff009c1f2d4 @ fffffff009c1f2d4 size=108

void FUN_fffffff009c1f2d4(long param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(DAT_fffffff00af483b0 + 0x140));
  if ((*(uint *)(param_1 + 0x3d0) & 1) != 0) {
    FUN_fffffff009c334c4(DAT_fffffff00af483b0,param_1);
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffffe;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c1f33c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(DAT_fffffff00af483b0 + 0x140));
  return;
}

