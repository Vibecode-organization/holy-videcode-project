// FUN_fffffff009962a98 @ fffffff009962a98 size=128

void FUN_fffffff009962a98(long *param_1)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = thunk_EXT_FUN_8011000003397c88();
  param_1[0x21] = lVar2;
  (**(code **)(*param_1 + 0xa0))(param_1);
  thunk_EXT_FUN_80110000032222a8(param_1[0x2c]);
  *(undefined1 *)((long)param_1 + 0x194) = 1;
  thunk_EXT_FUN_8011000003222de0(param_1[0x2c]);
  FUN_fffffff00994cc90(param_1[0x36]);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009962b14);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038ff214(param_1[0xb]);
  return;
}

