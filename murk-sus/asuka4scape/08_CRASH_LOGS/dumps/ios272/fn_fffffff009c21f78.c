// FUN_fffffff009c21f78 @ fffffff009c21f78 size=148

long * FUN_fffffff009c21f78(long *param_1,long *param_2)

{
  undefined *puVar1;
  long *plVar2;
  
  plVar2 = (long *)*param_1;
  *param_1 = (long)param_2;
  puVar1 = PTR_DAT_fffffff00806c9c0;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x48))(param_2,*(undefined8 *)PTR_DAT_fffffff00806c9c0);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x50))(plVar2,*(undefined8 *)puVar1);
  }
  return param_1;
}

