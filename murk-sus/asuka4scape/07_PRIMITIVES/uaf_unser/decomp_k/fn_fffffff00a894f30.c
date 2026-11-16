// FUN_fffffff00a894f30 @ fffffff00a894f30 size=100
// CALLERS:

long * FUN_fffffff00a894f30(long *param_1,long param_2)

{
  long lVar1;
  
  if (param_1 != (long *)0x0) {
    lVar1 = (**(code **)(*param_1 + 0x38))();
    do {
      if (param_2 == lVar1) {
        return param_1;
      }
      lVar1 = *(long *)(lVar1 + 0x10);
    } while (lVar1 != 0);
  }
  return (long *)0x0;
}

