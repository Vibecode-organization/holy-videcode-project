// FUN_fffffff00997b558 @ fffffff00997b558 size=132

long * FUN_fffffff00997b558(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  
  plVar1 = (long *)FUN_fffffff00997b5dc();
  if ((plVar1 == (long *)0x0) &&
     (plVar1 = (long *)FUN_fffffff00997b640(param_1,param_2), plVar1 != (long *)0x0)) {
    FUN_fffffff00997b7e0(param_1,param_2,plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return plVar1;
}

