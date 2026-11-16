// FUN_fffffff008200e48 @ fffffff008200e48 size=384

long * FUN_fffffff008200e48
                 (long param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined8 param_5
                 ,undefined8 param_6)

{
  long *plVar1;
  long *plVar2;
  
  if ((((uint)param_5 | (uint)param_4) & ~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f)))
      == 0) {
    if (param_4 == 0) {
      plVar1 = (long *)thunk_EXT_FUN_801100000297cd4c
                                 (*(long *)(param_1 + 0x48),param_2,param_1,0,
                                  *(uint *)(*(long *)(param_1 + 0x48) + 0x18b70) | 0x23,param_5,0);
    }
    else {
      plVar1 = (long *)thunk_EXT_FUN_801100000297c714();
    }
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x20))(plVar1);
      (**(code **)(*plVar1 + 0x28))(plVar1);
      thunk_EXT_FUN_801100000297dcd4(plVar1);
      plVar2 = (long *)(**(code **)(*plVar1 + 0x90))(plVar1,param_3,param_6);
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x20))(plVar2);
        (**(code **)(*plVar2 + 0x28))(plVar2);
      }
      (**(code **)(*plVar1 + 0x28))(plVar1);
      return plVar2;
    }
  }
  return (long *)0x0;
}

