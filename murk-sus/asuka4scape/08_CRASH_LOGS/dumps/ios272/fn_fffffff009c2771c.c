// FUN_fffffff009c2771c @ fffffff009c2771c size=4

undefined8
FUN_fffffff009c2771c
          (undefined8 param_1,long *param_2,undefined8 *param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined4 param_9)

{
  undefined8 uVar1;
  undefined8 uStack_70;
  long lStack_68;
  
  lStack_68 = *(long *)PTR_DAT_fffffff00806ca40;
  uStack_70 = 0;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  uVar1 = FUN_fffffff009c27118
                    (param_1,param_2,&uStack_70,param_4,param_5,param_6,param_7,param_8,param_9);
  *param_3 = uStack_70;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_68) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

