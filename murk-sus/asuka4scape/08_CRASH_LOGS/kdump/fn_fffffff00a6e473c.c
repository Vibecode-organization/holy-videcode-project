// FUN_fffffff00a6e473c @ fffffff00a6e473c size=60
// CALLERS:
//   fffffff00afbc4e3 ?
//   fffffff007c22ad8 ?
// CALLS:
//   fffffff00a6e3bd0 FUN_fffffff00a6e3bd0

void FUN_fffffff00a6e473c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 *param_8,undefined4 *param_9,undefined8 param_10,undefined *param_11)

{
  ulong uVar1;
  
  *param_9 = 0;
  uVar1 = FUN_fffffff00a6e3bd0
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,(undefined8 *)*param_8,
                     0x40,param_10,param_11);
  if ((int)uVar1 != 0) {
    *param_9 = 0xffffffff;
  }
  return;
}

