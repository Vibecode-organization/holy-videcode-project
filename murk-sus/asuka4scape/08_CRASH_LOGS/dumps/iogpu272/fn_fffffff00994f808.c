// FUN_fffffff00994f808 @ fffffff00994f808 size=116

undefined8
FUN_fffffff00994f808
          (long param_1,long *param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
  uVar1 = FUN_fffffff00994ea4c(param_1,param_4,param_5);
  if ((int)uVar1 != 0) {
    *(long **)(param_1 + 0xd0) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    *(undefined8 *)(param_1 + 0xd8) = param_3;
  }
  return uVar1;
}

