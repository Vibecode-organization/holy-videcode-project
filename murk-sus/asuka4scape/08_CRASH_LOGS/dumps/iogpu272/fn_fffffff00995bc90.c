// FUN_fffffff00995bc90 @ fffffff00995bc90 size=112

undefined8 FUN_fffffff00995bc90(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009945040(*(undefined8 *)(param_1 + 0x38));
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002c2;
  }
  else {
    uVar2 = FUN_fffffff00995a5cc(plVar1,param_3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

