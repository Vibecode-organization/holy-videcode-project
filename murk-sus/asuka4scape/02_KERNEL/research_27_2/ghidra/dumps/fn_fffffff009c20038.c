// FUN_fffffff009c20038 @ fffffff009c20038 size=220
// CALLERS:
//   fffffff00afebcea no-fn
//   fffffff009c1b5b0 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b5c8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b644 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b674 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b69c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b7ec FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b8f8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1b934 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1ba2c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bbd0 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bdac FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1be48 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1be80 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bef4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bf1c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bf78 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1bfdc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c018 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c054 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c088 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c0cc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c1d0 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c214 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c324 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c444 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c4d0 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c654 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c7a8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c7c8 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c7f4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c81c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c8fc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c950 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c978 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1c9dc FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1d034 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1d518 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1da70 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1da9c FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1dfd4 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e050 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e090 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e0c0 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1e554 FUN_fffffff009c1af14@fffffff009c1af14
//   fffffff009c1ff8c FUN_fffffff009c1ff50@fffffff009c1ff50
//   fffffff009c20150 FUN_fffffff009c20114@fffffff009c20114
//   fffffff009c202c4 FUN_fffffff009c20288@fffffff009c20288
// CALLEES:
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30

bool FUN_fffffff009c20038(long *param_1,undefined8 param_2,ulong *param_3)

{
  long *plVar1;
  ulong uVar2;
  ulong uVar3;
  
  plVar1 = (long *)(**(code **)(*param_1 + 0x138))();
  plVar1 = thunk_FUN_fffffff00a894f30(plVar1,*(long *)PTR_PTR_fffffff00806c9f8);
  if (plVar1 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar1 + 0x88))(plVar1);
    uVar3 = (**(code **)(*plVar1 + 0xb0))(plVar1);
    *param_3 = uVar3;
    if (((uint)uVar2 < 0x40) && ((uVar3 >> ((ulong)((uint)uVar2 - 1) & 0x3f) & 1) != 0)) {
      *param_3 = uVar3 | -1L << (uVar2 & 0x3f);
    }
  }
  return plVar1 != (long *)0x0;
}

