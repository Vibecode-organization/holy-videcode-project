// FUN_fffffff0081953d4 @ fffffff0081953d4 size=316

void FUN_fffffff0081953d4
               (long param_1,int *param_2,long param_3,undefined8 param_4,long param_5,
               undefined8 param_6)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((param_2 != (int *)0x0) && (*param_2 < 4)) {
    thunk_EXT_FUN_80110000029486ac
              (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x858,param_4);
    if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
      FUN_fffffff0081a0304
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x810,param_1 + 0x858,param_6);
    }
    if (param_5 != 0) {
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x898,param_5);
    }
    if ((*(byte *)(param_2 + 1) & 1) != 0) {
      *(undefined4 *)(param_3 + 0x348) = *(undefined4 *)(param_1 + 0x8d8);
      thunk_EXT_FUN_80110000029486ac
                (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),
                 *(long *)(param_1 + 0x850) + 0x60,param_4);
      if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x1ac45) & 1) != 0) {
        FUN_fffffff0081a0304
                  (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),0x811,
                   *(long *)(param_1 + 0x850) + 0x60,param_6);
      }
      if (param_5 != 0) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081954f8);
          (*pcVar1)();
        }
        thunk_EXT_FUN_80110000029486ac
                  (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),
                   *(long *)(param_1 + 0x850) + 0xa0,param_5);
        return;
      }
    }
  }
  return;
}

