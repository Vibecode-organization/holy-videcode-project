// FUN_fffffff00997a368 @ fffffff00997a368 size=164

void FUN_fffffff00997a368(long *param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 local_38;
  
  local_38 = 0;
  thunk_EXT_FUN_8011000003398228(param_3,&local_38);
  plVar1 = (long *)thunk_EXT_FUN_80110000038c6e24(local_38,0x40);
  if (plVar1 != (long *)0x0) {
    (**(code **)(*param_1 + 0xf0))(param_1,param_2,plVar1);
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return;
}

