// FUN_fffffff009c409ec @ fffffff009c409ec size=96

undefined8 FUN_fffffff009c409ec(void)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    FUN_fffffff009c2aec8();
    (**(code **)(*plVar1 + 0x28))(plVar1);
    uVar2 = 0;
  }
  return uVar2;
}

