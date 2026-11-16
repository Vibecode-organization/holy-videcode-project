// FUN_fffffff009c3a60c @ fffffff009c3a60c size=108

bool FUN_fffffff009c3a60c(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  long *plVar2;
  
  plVar1 = (long *)thunk_EXT_FUN_80110000039a2b94(param_2,param_3);
  plVar2 = (long *)**(undefined8 **)PTR_DAT_fffffff00806ca60;
  if (plVar1 != (long *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return plVar2 == plVar1;
}

