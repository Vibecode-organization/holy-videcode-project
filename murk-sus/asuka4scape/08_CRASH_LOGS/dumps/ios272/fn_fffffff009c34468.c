// FUN_fffffff009c34468 @ fffffff009c34468 size=260

long * FUN_fffffff009c34468(undefined8 param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  
  plVar1 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar2 = (long *)thunk_EXT_FUN_80110000038ce200(param_1);
  if (plVar1 == (long *)0x0) {
    plVar3 = (long *)0x0;
    if (plVar2 == (long *)0x0) {
      return (long *)0x0;
    }
  }
  else {
    if (plVar2 == (long *)0x0) {
      plVar3 = (long *)0x0;
      goto LAB_fffffff009c34538;
    }
    (**(code **)(*plVar1 + 0x100))(plVar1,DAT_fffffff008066e58,plVar2);
    (**(code **)(*plVar1 + 0x20))(plVar1);
    plVar3 = plVar1;
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
  if (plVar1 == (long *)0x0) {
    return plVar3;
  }
LAB_fffffff009c34538:
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return plVar3;
}

