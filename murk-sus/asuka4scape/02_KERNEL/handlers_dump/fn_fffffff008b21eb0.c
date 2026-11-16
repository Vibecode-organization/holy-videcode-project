// FUN_fffffff008b21eb0 @ fffffff008b21eb0 size=308 depth=1
// CALLERS:
//   fffffff00afce659 ?
//   fffffff008b217d8 FUN_fffffff008b21790
// CALLS:
//   fffffff008b75044 thunk_FUN_fffffff00a394230
//   fffffff008b74f64 thunk_FUN_fffffff008c5e04c
//   fffffff008b74f54 thunk_FUN_fffffff00a912bc0
//   fffffff008b75154 thunk_FUN_fffffff00a275024

/* WARNING: Removing unreachable block (ram,0xfffffff008b21f9c) */
/* WARNING: Removing unreachable block (ram,0xfffffff008b21f1c) */

void FUN_fffffff008b21eb0(long *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  plVar2 = (long *)thunk_FUN_fffffff008c5e04c((long)param_1);
  thunk_FUN_fffffff00a912bc0((long)param_1);
  lVar3 = thunk_FUN_fffffff00a394230();
  thunk_FUN_fffffff00a275024(lVar3);
  (**(code **)(*param_1 + 0x1e8))(*param_1 + 0x1e8,param_1,0);
  (**(code **)(*plVar2 + 0x78))(plVar2,"[0x%llx][%llx][%s::%s]: reportID : %d");
  lVar3 = *(long *)param_1[0x1d];
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008b21fe0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar3 + 0x5f8))((long *)param_1[0x1d],param_2,param_3,2,lVar3 + 0x5f8);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008b21fd8);
  (*pcVar1)();
}

