// FUN_fffffff00820f51c @ fffffff00820f51c size=192

void FUN_fffffff00820f51c(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (DAT_fffffff00ae258b0 == (long *)0x0) {
    uVar3 = *(undefined8 *)PTR_DAT_fffffff007ca61d0;
    plVar1 = (long *)(**(code **)(*param_1 + 0x758))(param_1);
    if ((plVar1 != (long *)0x0) &&
       (uVar2 = FUN_fffffff00820f004(plVar1,uVar3,param_1), (uVar2 & 1) == 0)) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
      plVar1 = (long *)0x0;
    }
    DAT_fffffff00ae258b0 = plVar1;
    *(undefined1 *)(plVar1 + 0x19) = 1;
  }
  return;
}

