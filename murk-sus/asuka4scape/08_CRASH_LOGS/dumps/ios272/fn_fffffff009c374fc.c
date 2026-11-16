// FUN_fffffff009c374fc @ fffffff009c374fc size=104

void FUN_fffffff009c374fc(long param_1,undefined8 param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x228));
  (**(code **)(**(long **)(param_1 + 0x220) + 0xe8))(*(long **)(param_1 + 0x220),param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37560);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x228));
  return;
}

