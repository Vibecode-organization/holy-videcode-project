// FUN_fffffff008b150b4 @ fffffff008b150b4 size=316 depth=1
// CALLERS:
//   fffffff00afce505 ?
//   fffffff008b14590 FUN_fffffff008b144c4
// CALLS:
//   fffffff008b75044 thunk_FUN_fffffff00a394230
//   fffffff008b74f64 thunk_FUN_fffffff008c5e04c
//   fffffff008b74f54 thunk_FUN_fffffff00a912bc0
//   fffffff008b75154 thunk_FUN_fffffff00a275024

/* WARNING: Removing unreachable block (ram,0xfffffff008b151a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff008b15128) */

void FUN_fffffff008b150b4(long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

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
  (**(code **)(*plVar2 + 0x78))(plVar2,"[0x%llx][%llx][%s::%s]: ");
  lVar3 = *(long *)param_1[0x1d];
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008b151ec. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(lVar3 + 0x660))((long *)param_1[0x1d],param_2,param_3,param_4,lVar3 + 0x660);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008b151e4);
  (*pcVar1)();
}

