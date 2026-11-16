// FUN_fffffff0081fd694 @ fffffff0081fd694 size=180

void FUN_fffffff0081fd694
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000296c9fc();
  if ((1 << (ulong)((uint)param_4 & 0x1f) & 0x5f80U) != 0) {
    thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  FUN_fffffff0081e69d4(param_1,param_2,param_3,param_4,param_5);
  if ((*(byte *)(param_1 + 0x2a0) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fd744);
    (*pcVar1)();
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return;
}

