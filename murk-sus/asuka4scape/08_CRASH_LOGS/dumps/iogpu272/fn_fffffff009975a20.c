// FUN_fffffff009975a20 @ fffffff009975a20 size=288

long * FUN_fffffff009975a20(long param_1)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  
  plVar2 = (long *)thunk_EXT_FUN_80110000038961f4(0x100);
  if ((plVar2 != (long *)0x0) &&
     (plVar3 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x1c8)), plVar3 != (long *)0x0
     )) {
    iVar1 = (**(code **)(*plVar3 + 0x90))();
    if (iVar1 != 0) {
      iVar5 = 0;
      do {
        (**(code **)(*plVar3 + 0x118))(plVar3,iVar5);
        plVar4 = (long *)FUN_fffffff009967400();
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar2 + 0xf8))(plVar2,plVar4);
          (**(code **)(*plVar4 + 0x28))(plVar4);
        }
        iVar5 = iVar5 + 1;
      } while (iVar1 != iVar5);
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return plVar2;
}

