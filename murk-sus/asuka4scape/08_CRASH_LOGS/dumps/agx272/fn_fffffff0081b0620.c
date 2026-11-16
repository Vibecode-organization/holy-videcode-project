// FUN_fffffff0081b0620 @ fffffff0081b0620 size=108

void FUN_fffffff0081b0620(undefined8 param_1,undefined4 *param_2)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if (*(long **)(param_2 + 2) != (long *)0x0) {
    (**(code **)(**(long **)(param_2 + 2) + 0x28))();
  }
  *(undefined8 *)(param_2 + 2) = 0;
  *(undefined8 *)(param_2 + 4) = 0;
  *param_2 = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b0688);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ca1288);
  return;
}

