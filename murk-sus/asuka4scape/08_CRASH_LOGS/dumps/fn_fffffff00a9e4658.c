// FUN_fffffff00a9e4658 @ fffffff00a9e4658 size=148
// CALLERS:
//   fffffff00afbfb01 no-fn
//   fffffff007c88d40 no-fn
// CALLEES:
//   fffffff00a894d88 FUN_fffffff00a894d88

void FUN_fffffff00a9e4658
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6)

{
  undefined8 *puVar1;
  undefined *in_x4;
  undefined1 extraout_q0 [16];
  
  puVar1 = FUN_fffffff00a894d88
                     (param_1,param_2,param_3,param_4,param_5,param_6,
                      (undefined8 *)&DAT_fffffff00ad98460,"IOPerfControlClient",
                      &DAT_fffffff00ad98798,0x70,in_x4);
  *puVar1 = &PTR_FUN_fffffff007c66ad8;
  puVar1 = FUN_fffffff00a894d88
                     (extraout_q0,param_2,param_3,param_4,param_5,param_6,
                      (undefined8 *)&DAT_fffffff00ad98488,"IOPerfControlWorkContext",
                      &DAT_fffffff00ad98798,0x50,in_x4);
  *puVar1 = &PTR_FUN_fffffff007c66c00;
  return;
}

