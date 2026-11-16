// FUN_fffffff009973e04 @ fffffff009973e04 size=136

long * FUN_fffffff009973e04(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(*param_1 + 0x560))();
  if ((plVar1 != (long *)0x0) && (uVar2 = FUN_fffffff00995ebf8(plVar1,param_1), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

