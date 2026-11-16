// FUN_fffffff0081a05d0 @ fffffff0081a05d0 size=156

void FUN_fffffff0081a05d0
               (long param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x1ac45) & 1) == 0) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494(param_2 << 2 | 0x85980000,param_3,param_4,param_5,0,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a0668);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  return;
}

