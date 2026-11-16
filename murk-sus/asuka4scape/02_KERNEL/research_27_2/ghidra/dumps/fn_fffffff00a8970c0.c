// FUN_fffffff00a8970c0 @ fffffff00a8970c0 size=80
// CALLERS:
//   fffffff00afbdf5c no-fn
//   fffffff007ce96c0 no-fn
//   fffffff007f35160 no-fn
//   fffffff007fc9228 no-fn
//   fffffff008066460 no-fn
//   fffffff008357310 thunk_FUN_fffffff00a8970c0@fffffff008357304
//   fffffff0093c2fbc thunk_FUN_fffffff00a8970c0@fffffff0093c2fb0
//   fffffff0098abf2c thunk_FUN_fffffff00a8970c0@fffffff0098abf20
//   fffffff009c14de4 thunk_FUN_fffffff00a8970c0@fffffff009c14dd8
// CALLEES:
//   fffffff00a896f84 FUN_fffffff00a896f84
//   fffffff00a8d4088 FUN_fffffff00a8d4088

undefined8 FUN_fffffff00a8970c0(long *param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = FUN_fffffff00a8d4088(param_1);
  uVar2 = FUN_fffffff00a896f84((long)plVar1);
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return uVar2;
}

