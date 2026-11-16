// FUN_fffffff009c041c8 @ fffffff009c041c8

void FUN_fffffff009c041c8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined *param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  undefined8 *puVar2;
  ulong unaff_x30;
  
  if ((undefined8 *)param_7[0x12] != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)param_7[0x12]);
    (**(code **)(**(long **)(param_7[0x12] + 8) + 0x28))();
    puVar2 = (undefined8 *)param_7[0x12];
    param_7[0x12] = 0;
    param_1 = thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff008064198,puVar2);
  }
  if ((long *)param_7[0x17] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x17] + 0x28))(param_1);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c04274);
    (*pcVar1)();
  }
  (*(code *)PTR_FUN_fffffff008063758)(param_7);
  return;
}

