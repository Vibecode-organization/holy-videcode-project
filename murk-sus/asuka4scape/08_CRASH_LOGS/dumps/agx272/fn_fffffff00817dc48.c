// FUN_fffffff00817dc48 @ fffffff00817dc48 size=176

void FUN_fffffff00817dc48
               (long param_1,uint param_2,uint param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  code *pcVar1;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494
            (param_3 | (param_2 & 0x3fff) << 2 | 0x85000000 | param_2 * 0x100 + 0x900000 & 0xff0000,
             param_4,param_5,param_6,param_7,param_8);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817dcf4);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  return;
}

