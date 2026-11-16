// FUN_fffffff009973ec4 @ fffffff009973ec4 size=176

long * FUN_fffffff009973ec4(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(*param_1 + 0x570))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 0x78))
                        (plVar1,param_1,*(int *)((long)param_1 + 0x23c) * 1000,(int)param_1[0x40]),
     (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

