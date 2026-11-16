// FUN_fffffff009c3b58c @ fffffff009c3b58c size=156

undefined8
FUN_fffffff009c3b58c(undefined8 param_1,undefined4 *param_2,long param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if ((((param_3 != 0) && (param_2 != (undefined4 *)0x0)) && (param_4 == 0xc)) && (*param_5 == 4)) {
    uVar1 = param_2[1];
    plVar2 = (long *)FUN_fffffff009c3f1d0(param_1,*param_2);
    if (plVar2 != (long *)0x0) {
      uVar3 = FUN_fffffff009c20f04(plVar2,uVar1,param_3);
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return uVar3;
    }
  }
  return 0xe00002c2;
}

