// FUN_fffffff009c18878 @ fffffff009c18878 size=268

undefined8
FUN_fffffff009c18878
          (long param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          long *param_6,long param_7)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = 0;
  if ((((param_2 != 0) && (param_3 != 0)) && (param_7 != 0)) &&
     (uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1), (int)uVar1 != 0)) {
    FUN_fffffff009c16670(param_1 + 0x38,param_2);
    FUN_fffffff009c18a40(param_1 + 0x40,param_3);
    *(undefined8 *)(param_1 + 0x10) = param_4;
    *(undefined8 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x20) = param_5;
    plVar2 = *(long **)(param_1 + 0x50);
    *(long **)(param_1 + 0x50) = param_6;
    if (param_6 != (long *)0x0) {
      (**(code **)(*param_6 + 0x20))(param_6);
    }
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    *(long *)(param_1 + 0x58) = param_7;
    *(byte *)(param_1 + 0x68) = *(byte *)(*(long *)(param_1 + 0x40) + 0x40) & 1;
    uVar1 = 1;
  }
  return uVar1;
}

