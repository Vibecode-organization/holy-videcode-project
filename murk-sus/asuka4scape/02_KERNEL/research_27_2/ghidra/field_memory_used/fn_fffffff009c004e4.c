// FUN_fffffff009c004e4 @ fffffff009c004e4

/* WARNING: Removing unreachable block (ram,0xfffffff009c005e0) */

undefined1 FUN_fffffff009c004e4(long *param_1)

{
  undefined1 uVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  
  iVar2 = (*(code *)PTR_FUN_fffffff008063330)();
  uVar1 = 0;
  if (iVar2 != 0) {
    plVar3 = thunk_FUN_fffffff00a89ca6c(param_1[0x17]);
    uVar1 = 0;
    if (plVar3 != (long *)0x0) {
      plVar4 = (long *)(**(code **)(*plVar3 + 0x88))();
      while (plVar4 != (long *)0x0) {
        iVar2 = (**(code **)(*plVar4 + 0x360))(plVar4,param_1);
        if (iVar2 != 0) {
          (**(code **)(*param_1 + 0x5a0))(param_1,plVar4);
          (**(code **)(*plVar4 + 0x2a0))(*plVar4 + 0x2a0,plVar4,0);
        }
        plVar4 = (long *)(**(code **)(*plVar3 + 0x88))(plVar3);
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
      param_1[0x12] = param_1[0x12] | 1;
      uVar1 = 1;
    }
  }
  return uVar1;
}

