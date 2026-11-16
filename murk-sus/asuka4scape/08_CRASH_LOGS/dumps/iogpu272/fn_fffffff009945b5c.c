// FUN_fffffff009945b5c @ fffffff009945b5c size=244

long * FUN_fffffff009945b5c
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5,undefined8 param_6)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af221a0 + 0x68))();
  if (plVar1 != (long *)0x0) {
    thunk_EXT_FUN_8011000003977ae0(plVar1,param_5,param_6);
    uVar2 = (**(code **)(*plVar1 + 0x128))(plVar1,param_1,param_2,param_3,param_4,0);
    if ((uVar2 & 1) == 0) {
      (**(code **)(*plVar1 + 0x28))(plVar1);
      plVar1 = (long *)0x0;
    }
  }
  return plVar1;
}

