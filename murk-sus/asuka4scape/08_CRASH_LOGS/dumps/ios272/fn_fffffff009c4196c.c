// FUN_fffffff009c4196c @ fffffff009c4196c size=232

undefined8 FUN_fffffff009c4196c(long param_1,long param_2,long *param_3,undefined1 param_4)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  if ((int)uVar1 != 0) {
    plVar3 = *(long **)(param_1 + 0x20);
    *(long **)(param_1 + 0x20) = param_3;
    if (param_3 != (long *)0x0) {
      (**(code **)(*param_3 + 0x20))(param_3);
    }
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    lVar2 = param_2;
    if (param_2 == 0) {
      lVar2 = 0;
    }
    *(long *)(param_1 + 0x10) = lVar2;
    thunk_EXT_FUN_801100000326c6a4(param_2);
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x18) = lVar2;
    uVar1 = 0;
    if (lVar2 != 0) {
      *(undefined1 *)(param_1 + 0x40) = param_4;
      uVar1 = 1;
    }
  }
  return uVar1;
}

