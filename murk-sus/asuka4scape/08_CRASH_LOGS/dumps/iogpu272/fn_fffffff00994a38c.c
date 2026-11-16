// FUN_fffffff00994a38c @ fffffff00994a38c size=136

undefined8 FUN_fffffff00994a38c(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  
  uVar2 = 0xe00002c2;
  if (param_3 == 0) {
    plVar1 = (long *)FUN_fffffff009965db4(*(undefined8 *)(param_1 + 0x120),param_4);
    if (plVar1 != (long *)0x0) {
      uVar2 = FUN_fffffff0099830d0(plVar1,param_2);
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
  }
  else {
    uVar2 = 0xe00002c7;
  }
  return uVar2;
}

