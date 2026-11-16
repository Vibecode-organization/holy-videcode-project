// FUN_fffffff00996f35c @ fffffff00996f35c size=288

bool FUN_fffffff00996f35c
               (long param_1,undefined8 param_2,long *param_3,long *param_4,undefined8 param_5,
               undefined8 param_6)

{
  long lVar1;
  
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x20))(param_3);
  }
  if (param_4 != (long *)0x0) {
    (**(code **)(*param_4 + 0x20))(param_4);
  }
  lVar1 = FUN_fffffff00996e9f0(param_2,param_3,param_4,param_5,param_6);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x18) = 0;
    **(long **)(param_1 + 0x168) = lVar1;
    *(undefined8 **)(param_1 + 0x168) = (undefined8 *)(lVar1 + 0x18);
    *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + 1;
  }
  if (param_4 != (long *)0x0) {
    (**(code **)(*param_4 + 0x28))(param_4);
  }
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  return lVar1 != 0;
}

