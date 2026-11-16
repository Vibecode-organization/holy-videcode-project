// FUN_fffffff009c3c354 @ fffffff009c3c354 size=100

undefined8 FUN_fffffff009c3c354(void)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c3f1d0();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff009c24754();
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

