// FUN_fffffff009976c70 @ fffffff009976c70 size=136

void FUN_fffffff009976c70(long *param_1)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0xa5]);
  if ((*(byte *)((long)param_1 + 0x526) & 1) == 0) {
    thunk_EXT_FUN_80110000032222a8(param_1[0x8b]);
    (**(code **)(*param_1 + 0xe0))(param_1);
    *(undefined1 *)((long)param_1 + 0x525) = 0;
    thunk_EXT_FUN_8011000003222de0(param_1[0x8b]);
  }
  else {
    *(undefined1 *)((long)param_1 + 0x525) = 1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009976cf4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0xa5]);
  return;
}

