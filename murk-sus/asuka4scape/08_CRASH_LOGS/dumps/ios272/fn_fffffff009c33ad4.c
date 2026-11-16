// FUN_fffffff009c33ad4 @ fffffff009c33ad4 size=148

undefined8
FUN_fffffff009c33ad4
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulong param_4,undefined8 param_5
          )

{
  long *plVar1;
  undefined8 uVar2;
  
  if ((param_4 & 1) == 0) {
    plVar1 = (long *)FUN_fffffff009c47474();
  }
  else {
    plVar1 = (long *)FUN_fffffff009c47a80(param_1,param_3,param_4);
  }
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xe00002bd;
  }
  else {
    uVar2 = thunk_EXT_FUN_80110000039a3b30(param_2,plVar1,param_5);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return uVar2;
}

