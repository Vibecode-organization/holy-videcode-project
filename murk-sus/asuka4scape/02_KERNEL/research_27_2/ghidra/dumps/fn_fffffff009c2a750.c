// FUN_fffffff009c2a750 @ fffffff009c2a750 size=16
// CALLERS:
//   fffffff00afebe25 no-fn
//   fffffff007ca5bf8 no-fn
//   fffffff007e2d090 no-fn
//   fffffff007e61078 no-fn
//   fffffff00802a198 no-fn
//   fffffff009c3d51c FUN_fffffff009c3d4f8@fffffff009c3d4f8
//   fffffff008216a5c thunk_FUN_fffffff009c2a750@fffffff008216a50
//   fffffff008ca95a4 thunk_FUN_fffffff009c2a750@fffffff008ca9598
//   fffffff008e0035c thunk_FUN_fffffff009c2a750@fffffff008e00350
//   fffffff009abd868 thunk_FUN_fffffff009c2a750@fffffff009abd85c
// CALLEES:

byte FUN_fffffff009c2a750(long param_1)

{
  return *(byte *)(param_1 + 0x3d1) >> 1 & 1;
}

