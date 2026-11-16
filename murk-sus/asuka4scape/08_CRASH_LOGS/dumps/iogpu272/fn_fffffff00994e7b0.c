// FUN_fffffff00994e7b0 @ fffffff00994e7b0 size=120

undefined8 FUN_fffffff00994e7b0(long param_1,long *param_2)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar1 != 0) {
    *(long **)(param_1 + 0x50) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  return uVar1;
}

