// FUN_fffffff009c37bb0 @ fffffff009c37bb0 size=188

void FUN_fffffff009c37bb0(long *param_1,ulong param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x76]);
  param_1[0x79] = param_1[0x79] + 1;
  if ((param_2 & 1) == 0) {
    FUN_fffffff009c37c6c(param_1);
  }
  else if ((*(byte *)(param_1 + 0x7a) & 1) == 0) {
    *(undefined1 *)(param_1 + 0x7a) = 1;
    (**(code **)(*param_1 + 0x20))(param_1);
    (**(code **)(*(long *)param_1[0x92] + 0xf8))((long *)param_1[0x92],0,0,0);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37c68);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x76]);
  return;
}

