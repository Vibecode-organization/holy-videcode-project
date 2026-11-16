// FUN_fffffff0094c51ec @ fffffff0094c51ec size=44
// CALLERS:
//   fffffff00afb8098 ?
//   fffffff0094c8c88 FUN_fffffff0094c8c04@fffffff0094c8c04
//   fffffff0094c8c9c FUN_fffffff0094c8c04@fffffff0094c8c04
//   fffffff0094c8cb0 FUN_fffffff0094c8c04@fffffff0094c8c04
// CALLS:
//   fffffff0094c9bb4 thunk_EXT_FUN_80110000033502b4

undefined8 FUN_fffffff0094c51ec(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if ((ulong)param_2[1] < (ulong)param_1[1]) {
    return 0xffffffff;
  }
  uVar1 = thunk_EXT_FUN_80110000033502b4(*param_2,*param_1);
  return uVar1;
}

