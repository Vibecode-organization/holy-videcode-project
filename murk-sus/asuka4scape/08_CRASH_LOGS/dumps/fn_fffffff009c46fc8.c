// FUN_fffffff009c46fc8 @ fffffff009c46fc8 size=48
// CALLERS:
//   fffffff00afec211 no-fn
//   fffffff009c4945c FUN_fffffff009c49430@fffffff009c49430
//   fffffff009c46fc4 FUN_fffffff009c46fb8@fffffff009c46fb8
// CALLEES:
//   fffffff009c494f0 FUN_fffffff009c494f0
//   fffffff009c494bc FUN_fffffff009c494bc

void FUN_fffffff009c46fc8
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,undefined8 param_7,
               uint param_8)

{
  if (param_8 == 0) {
    param_1 = FUN_fffffff009c494bc(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (param_8 < 0xfffffff) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c494f0(param_1,param_2,param_3,param_4,param_5,param_6);
}

