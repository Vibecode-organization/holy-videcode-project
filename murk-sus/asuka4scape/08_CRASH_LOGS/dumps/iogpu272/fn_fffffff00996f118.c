// FUN_fffffff00996f118 @ fffffff00996f118 size=200

long * FUN_fffffff00996f118
                 (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  ulong uVar2;
  
  plVar1 = (long *)(**(code **)(DAT_fffffff00af226a0 + 0x68))();
  if ((plVar1 != (long *)0x0) &&
     (uVar2 = (**(code **)(*plVar1 + 200))(plVar1,param_1,param_2,param_3,param_4), (uVar2 & 1) == 0
     )) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    plVar1 = (long *)0x0;
  }
  return plVar1;
}

