// FUN_fffffff0081e6958 @ fffffff0081e6958 size=124

long * FUN_fffffff0081e6958(long *param_1,long param_2)

{
  long *plVar1;
  
  if ((*(byte *)(param_1[2] + 0x10a9d) & 1) == 0) {
    plVar1 = (long *)0x0;
  }
  else {
    plVar1 = (long *)(**(code **)(*param_1 + 0x150))(param_1,param_2);
  }
  if (plVar1 == (long *)0x0 || param_2 == 0) {
    plVar1 = param_1;
  }
  return plVar1;
}

