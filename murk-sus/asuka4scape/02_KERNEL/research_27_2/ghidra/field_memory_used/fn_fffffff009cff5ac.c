// FUN_fffffff009cff5ac @ fffffff009cff5ac

void FUN_fffffff009cff5ac
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               uint *param_8,ulong param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  undefined8 extraout_x1;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9324ec
            (param_1,param_2,param_3,param_4,param_5,param_6,(uint *)param_7[0x17],
             0xffffffffffffffff,param_9,param_10,param_11);
  (**(code **)(*param_7 + 0x8d0))(param_7);
  *(undefined1 *)(param_7 + 0x4d2) = 1;
  if ((*(byte *)((long)param_7 + 0x2691) & 1) == 0) {
    (**(code **)(*param_7 + 0x8d8))(param_7);
  }
  (**(code **)(*(long *)param_7[0x4d4] + 0xf0))((long *)param_7[0x4d4],0);
  (**(code **)(*param_7 + 0x28))(param_7);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cff69c);
    (*pcVar1)();
  }
  thunk_FUN_fffffff00a27b31c(param_8,extraout_x1,param_9);
  return;
}

