// FUN_fffffff009965954 @ fffffff009965954 size=96

undefined8 FUN_fffffff009965954(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009945154(*(undefined8 *)(param_1 + 0x10));
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    (**(code **)(*plVar1 + 0xb0))(plVar1,param_1);
    uVar2 = 0;
  }
  return uVar2;
}

