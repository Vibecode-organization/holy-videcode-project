// FUN_fffffff009c37204 @ fffffff009c37204 size=192

void FUN_fffffff009c37204(long *param_1,long *param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(param_1[0x3e]);
  (**(code **)(*(long *)param_1[0x3f] + 0xe8))((long *)param_1[0x3f],param_2);
  (**(code **)(*param_2 + 0x28))(param_2);
  if ((*(byte *)(param_1 + 0x41) & 1) == 0) {
    *(undefined1 *)(param_1 + 0x41) = 1;
    (**(code **)(*param_1 + 0x20))(param_1);
    thunk_EXT_FUN_8011000003277760(param_1[0x40]);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c372c0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(param_1[0x3e]);
  return;
}

