// FUN_fffffff008b21790 @ fffffff008b21790 size=144 depth=0
// CALLERS:
//   fffffff00afce647 ?
//   fffffff007df84b0 ?
// CALLS:
//   fffffff008b74cd4 thunk_FUN_fffffff00a97adac
//   fffffff008b21eb0 FUN_fffffff008b21eb0

undefined8 FUN_fffffff008b21790(long *param_1,undefined8 param_2,long param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = thunk_FUN_fffffff00a97adac
                     (*(undefined8 *)(param_3 + 0x30),(ulong)*(uint *)(param_3 + 0x38),2);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff008b21eb0(param_1,(ulong)**(byte **)(param_3 + 0x20),plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

