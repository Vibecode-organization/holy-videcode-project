// FUN_fffffff008b144c4 @ fffffff008b144c4 size=344 depth=0
// CALLERS:
//   fffffff00afce4f0 ?
//   fffffff007df59d0 ?
// CALLS:
//   fffffff008b74e44 thunk_FUN_fffffff00a8d2338
//   fffffff008b75034 thunk_FUN_fffffff00a2600a0
//   fffffff008b150b4 FUN_fffffff008b150b4
//   fffffff008b74ce4 thunk_FUN_fffffff00a97ae84

undefined8 FUN_fffffff008b144c4(long *param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  uVar2 = 0xe00002c2;
  if ((param_1 != (long *)0x0) && (param_3 != 0)) {
    uVar2 = **(undefined8 **)(param_3 + 0x20);
    uVar1 = *(uint *)(*(undefined8 **)(param_3 + 0x20) + 1);
    if (*(undefined8 **)(param_3 + 0x30) == (undefined8 *)0x0 || *(uint *)(param_3 + 0x38) == 0) {
      plVar5 = (long *)0x0;
    }
    else {
      plVar5 = thunk_FUN_fffffff00a8d2338
                         (*(undefined8 **)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38));
      if (plVar5 == (long *)0x0) {
        return 0xe00002bd;
      }
    }
    lVar3 = thunk_FUN_fffffff00a2600a0();
    plVar4 = thunk_FUN_fffffff00a97ae84(uVar2,(ulong)uVar1,3,lVar3);
    uVar2 = 0xe00002bd;
    if (plVar4 != (long *)0x0) {
      uVar2 = (**(code **)(*plVar4 + 0xd8))(plVar4,3);
      if ((int)uVar2 == 0) {
        uVar2 = FUN_fffffff008b150b4(param_1,plVar4,*(undefined8 *)(param_3 + 0x48),plVar5);
        *(undefined4 *)(param_3 + 0x50) = 1;
        (**(code **)(*plVar4 + 0xe0))(plVar4,0);
      }
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  return uVar2;
}

