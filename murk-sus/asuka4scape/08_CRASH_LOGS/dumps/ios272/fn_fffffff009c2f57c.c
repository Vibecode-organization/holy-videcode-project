// FUN_fffffff009c2f57c @ fffffff009c2f57c size=276

undefined8
FUN_fffffff009c2f57c(long param_1,undefined8 param_2,long *param_3,long *param_4,long param_5)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = 0;
  if (((param_3 != (long *)0x0) && (param_5 != 0)) &&
     (uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1), (int)uVar1 != 0)) {
    plVar2 = *(long **)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x10) = param_2;
    *(long **)(param_1 + 0x18) = param_4;
    if (param_4 != (long *)0x0) {
      (**(code **)(*param_4 + 0x20))(param_4);
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    plVar2 = *(long **)(param_1 + 0x20);
    *(long **)(param_1 + 0x20) = param_3;
    (**(code **)(*param_3 + 0x20))(param_3);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    *(long *)(param_1 + 0x28) = param_5;
    uVar1 = 1;
  }
  return uVar1;
}

