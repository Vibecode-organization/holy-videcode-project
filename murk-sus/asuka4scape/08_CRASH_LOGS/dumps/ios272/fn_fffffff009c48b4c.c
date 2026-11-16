// FUN_fffffff009c48b4c @ fffffff009c48b4c size=152

byte FUN_fffffff009c48b4c(long param_1,long *param_2,undefined8 param_3,undefined1 param_4)

{
  byte bVar1;
  
  bVar1 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))();
  bVar1 = param_2 != (long *)0x0 & bVar1;
  if (bVar1 == 1) {
    (**(code **)(*param_2 + 0x20))(param_2);
    *(long **)(param_1 + 0x18) = param_2;
    *(undefined8 *)(param_1 + 0x20) = param_3;
    *(undefined1 *)(param_1 + 0x28) = param_4;
  }
  return bVar1;
}

