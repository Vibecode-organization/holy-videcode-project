// FUN_fffffff00820ef68 @ fffffff00820ef68 size=156

long * FUN_fffffff00820ef68(undefined8 param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(*param_2 + 0x758))(param_2);
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff00820f004(plVar1,param_1,param_2), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

