// FUN_fffffff0099516c8 @ fffffff0099516c8 size=136

undefined8 FUN_fffffff0099516c8(long param_1,long param_2,long *param_3)

{
  undefined8 uVar1;
  
  uVar1 = (*DAT_fffffff007feb260)();
  if ((((int)uVar1 != 0) && (uVar1 = 0, param_2 != 0)) && (param_3 != (long *)0x0)) {
    *(long *)(param_1 + 0x20) = param_2;
    (**(code **)(*param_3 + 0x20))(param_3);
    *(long **)(param_1 + 0x28) = param_3;
    uVar1 = 1;
  }
  return uVar1;
}

