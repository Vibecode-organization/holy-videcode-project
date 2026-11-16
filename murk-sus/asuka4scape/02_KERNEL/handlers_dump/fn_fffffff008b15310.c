// FUN_fffffff008b15310 @ fffffff008b15310 size=284 depth=1
// CALLERS:
//   fffffff00afce509 ?
//   fffffff008b14750 FUN_fffffff008b146d8
//   fffffff008b14738 FUN_fffffff008b146d8
// CALLS:
//   fffffff008b75044 thunk_FUN_fffffff00a394230
//   fffffff008b74f64 thunk_FUN_fffffff008c5e04c
//   fffffff008b74f54 thunk_FUN_fffffff00a912bc0
//   fffffff008b75154 thunk_FUN_fffffff00a275024

/* WARNING: Removing unreachable block (ram,0xfffffff008b153f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff008b15378) */

void FUN_fffffff008b15310(long *param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = (long *)thunk_FUN_fffffff008c5e04c((long)param_1);
  thunk_FUN_fffffff00a912bc0((long)param_1);
  lVar2 = thunk_FUN_fffffff00a394230();
  thunk_FUN_fffffff00a275024(lVar2);
  (**(code **)(*param_1 + 0x1e8))(*param_1 + 0x1e8,param_1,0);
  (**(code **)(*plVar1 + 0x78))(plVar1,"[0x%llx][%llx][%s::%s]: ");
  lVar2 = *(long *)param_1[0x1d];
  (**(code **)(lVar2 + 0x670))(lVar2 + 0x670,(long *)param_1[0x1d],param_2);
  *(undefined1 *)(param_1 + 0x23) = 0;
  return;
}

