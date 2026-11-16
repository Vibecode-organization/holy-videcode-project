// FUN_fffffff009c33bbc @ fffffff009c33bbc size=108

long * FUN_fffffff009c33bbc(undefined8 param_1)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)FUN_fffffff009c33c34();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = FUN_fffffff009c33dc4(param_1,plVar1,(int)plVar1[2]), (uVar2 & 1) == 0)) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

