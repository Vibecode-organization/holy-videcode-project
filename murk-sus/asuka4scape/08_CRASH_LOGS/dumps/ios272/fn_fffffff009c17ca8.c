// FUN_fffffff009c17ca8 @ fffffff009c17ca8 size=144

undefined8 FUN_fffffff009c17ca8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = (long *)FUN_fffffff009c17d38();
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002bd;
  }
  else {
    FUN_fffffff009c175cc(param_1,plVar1);
    uVar2 = FUN_fffffff009c177c4(param_1,param_2,param_3);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

