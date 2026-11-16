// FUN_fffffff009950de4 @ fffffff009950de4 size=108

bool FUN_fffffff009950de4(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = (long *)*param_2;
  do {
    plVar2 = plVar3;
    if (plVar2 == (long *)0x0) break;
    plVar3 = (long *)plVar2[0x16];
    iVar1 = (**(code **)(*plVar2 + 0x88))(plVar2,param_3);
  } while (iVar1 == 0);
  return plVar2 != (long *)0x0;
}

