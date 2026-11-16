// FUN_fffffff0081fecd8 @ fffffff0081fecd8 size=120

undefined8 FUN_fffffff0081fecd8(long *param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar1 != 0) {
    param_1[2] = param_2;
    (**(code **)(*param_1 + 0xb8))(param_1);
  }
  return uVar1;
}

