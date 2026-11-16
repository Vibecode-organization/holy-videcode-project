// FUN_fffffff008b1461c @ fffffff008b1461c size=188 depth=0
// CALLERS:
//   fffffff00afce4f1 ?
//   fffffff007df59e8 ?
// CALLS:
//   fffffff008b74e44 thunk_FUN_fffffff00a8d2338
//   fffffff008b151f0 FUN_fffffff008b151f0

undefined8 FUN_fffffff008b1461c(long *param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong unaff_x30;
  
  uVar2 = 0xe00002c2;
  if ((param_1 != (long *)0x0) && (param_3 != 0)) {
    if (*(undefined8 **)(param_3 + 0x30) == (undefined8 *)0x0 || *(uint *)(param_3 + 0x38) == 0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008b1467c);
        (*pcVar1)();
      }
      uVar2 = FUN_fffffff008b151f0(param_1,0);
      return uVar2;
    }
    plVar3 = thunk_FUN_fffffff00a8d2338
                       (*(undefined8 **)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38));
    if (plVar3 == (long *)0x0) {
      uVar2 = 0xe00002bd;
    }
    else {
      uVar2 = FUN_fffffff008b151f0(param_1,plVar3);
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
  }
  return uVar2;
}

