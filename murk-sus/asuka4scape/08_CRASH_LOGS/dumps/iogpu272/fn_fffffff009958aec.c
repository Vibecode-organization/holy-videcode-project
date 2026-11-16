// FUN_fffffff009958aec @ fffffff009958aec size=212

long * FUN_fffffff009958aec(long *param_1,undefined4 param_2)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)(**(code **)(DAT_fffffff00af22470 + 0x68))();
  if (plVar2 != (long *)0x0) {
    iVar1 = (*DAT_fffffff007feb260)(plVar2);
    if ((param_1 == (long *)0x0) || (iVar1 == 0)) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
      plVar2 = (long *)0x0;
    }
    else {
      plVar2[2] = (long)param_1;
      (**(code **)(*param_1 + 0x20))(param_1);
      *(undefined4 *)(plVar2 + 5) = param_2;
    }
  }
  return plVar2;
}

