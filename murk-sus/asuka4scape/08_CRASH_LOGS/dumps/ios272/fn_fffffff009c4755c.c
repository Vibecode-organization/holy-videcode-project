// FUN_fffffff009c4755c @ fffffff009c4755c size=232

undefined8 FUN_fffffff009c4755c(long param_1,undefined8 param_2,long *param_3,uint param_4)

{
  undefined8 uVar1;
  ulong uVar2;
  long *plVar3;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  *(undefined8 *)(param_1 + 0x10) = param_2;
  if (((param_4 >> 1 & 1) == 0) && (uVar2 = FUN_fffffff009c22340(param_3), (uVar2 & 1) == 0)) {
    *(undefined1 *)(param_1 + 0x20) = 1;
  }
  plVar3 = *(long **)(param_1 + 0x18);
  *(long **)(param_1 + 0x18) = param_3;
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x20))(param_3);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  FUN_fffffff009c233d8(param_3);
  if ((*(byte *)(param_1 + 0x20) & 1) != 0) {
    FUN_fffffff009c22ee0(*(undefined8 *)(param_1 + 0x18),0);
  }
  return uVar1;
}

