// FUN_fffffff00994fc8c @ fffffff00994fc8c size=108

undefined8 FUN_fffffff00994fc8c(long param_1,long *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  uVar1 = FUN_fffffff00994ea4c(param_1,param_3,param_4);
  if ((int)uVar1 != 0) {
    (**(code **)(*param_2 + 0x20))(param_2);
    *(long **)(param_1 + 0xd0) = param_2;
  }
  return uVar1;
}

