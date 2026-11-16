// FUN_fffffff008b151f0 @ fffffff008b151f0 size=288 depth=1
// CALLERS:
//   fffffff00afce507 ?
//   fffffff008b14694 FUN_fffffff008b1461c
//   fffffff008b1467c FUN_fffffff008b1461c
// CALLS:
//   fffffff008b75044 thunk_FUN_fffffff00a394230
//   fffffff008b74f64 thunk_FUN_fffffff008c5e04c
//   fffffff008b74f54 thunk_FUN_fffffff00a912bc0
//   fffffff008b75154 thunk_FUN_fffffff00a275024

/* WARNING: Removing unreachable block (ram,0xfffffff008b152d4) */
/* WARNING: Removing unreachable block (ram,0xfffffff008b15258) */

void FUN_fffffff008b151f0(long *param_1,undefined8 param_2)

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
  (**(code **)(lVar2 + 0x668))(lVar2 + 0x668,(long *)param_1[0x1d],param_2);
  *(undefined1 *)(param_1 + 0x23) = 1;
  return;
}

