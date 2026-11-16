// FUN_fffffff0081a5848 @ fffffff0081a5848 size=204

void FUN_fffffff0081a5848
               (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long lVar2;
  ulong unaff_x30;
  
  lVar2 = *(long *)(param_1 + 0x280);
  if ((*(uint *)(lVar2 + 0x1ac44) >> (ulong)((int)param_2 >> 8 & 0x1f) & 1) == 0) {
    return;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar2 + 0x1ac48));
  thunk_EXT_FUN_80110000036da494
            (param_2 * 0x100 + 0x900000 & 0xff0000 | (param_2 & 0x3fff) << 2 | 0x85000000,param_3,
             param_4,param_5,param_6,param_7);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081a58f8);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar2 + 0x1ac48));
  return;
}

