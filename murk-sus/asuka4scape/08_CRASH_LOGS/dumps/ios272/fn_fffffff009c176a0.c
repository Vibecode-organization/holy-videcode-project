// FUN_fffffff009c176a0 @ fffffff009c176a0 size=108

undefined8 FUN_fffffff009c176a0(undefined8 param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c1770c();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002bd;
  }
  else {
    FUN_fffffff009c175cc(param_1,plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

