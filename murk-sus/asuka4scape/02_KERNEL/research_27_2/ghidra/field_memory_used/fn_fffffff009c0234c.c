// FUN_fffffff009c0234c @ fffffff009c0234c

void FUN_fffffff009c0234c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined *param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  ulong unaff_x30;
  
  if ((long *)param_7[0x17] != (long *)0x0) {
    param_1 = (**(code **)(*(long *)param_7[0x17] + 0x28))();
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c023b0);
    (*pcVar1)();
  }
  (*(code *)PTR_FUN_fffffff0080630f0)(param_1,param_7);
  return;
}

