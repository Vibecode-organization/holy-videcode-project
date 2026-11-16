// FUN_fffffff0099408a4 @ fffffff0099408a4 size=72

void FUN_fffffff0099408a4(undefined8 param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000038942e0();
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099408e8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003894430(&DAT_fffffff007fefde8,param_1,0xd8);
  return;
}

