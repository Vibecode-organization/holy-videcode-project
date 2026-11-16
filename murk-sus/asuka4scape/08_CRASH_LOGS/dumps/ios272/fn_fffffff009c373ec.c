// FUN_fffffff009c373ec @ fffffff009c373ec size=272

undefined8
FUN_fffffff009c373ec
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined8 param_5,
          undefined8 param_6,undefined4 *param_7)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  *param_7 = 0;
  if (param_4 != 0) {
    plVar1 = (long *)FUN_fffffff009c372dc();
    plVar2 = (long *)FUN_fffffff009c42814(plVar1,param_4);
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
    if (plVar2 != (long *)0x0) {
      uVar3 = FUN_fffffff009c44170(plVar2,param_5);
      if ((uVar3 & 1) == 0) {
        uVar4 = 0;
        *param_7 = 0xe00002e2;
      }
      else {
        uVar4 = FUN_fffffff009c372dc(param_1);
        uVar4 = FUN_fffffff009c443e0(plVar2,param_2,param_3,param_5,uVar4,param_6);
      }
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return uVar4;
    }
  }
  return 0;
}

