// FUN_fffffff0081fe6f0 @ fffffff0081fe6f0 size=160

void FUN_fffffff0081fe6f0(long param_1,long param_2,undefined8 param_3)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000296c9fc();
  if ((1 << (ulong)(*(ushort *)(param_2 + 0x12) & 0x1f) & 0x5f80U) != 0) {
    thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  FUN_fffffff0081e8294(param_1,param_2,param_3);
  if ((*(byte *)(param_1 + 0x2a0) & 1) != 0) {
    *(undefined1 *)(param_1 + 0x2a0) = 0;
    thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fe78c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return;
}

