// FUN_fffffff009c15344 @ fffffff009c15344 size=144

long * FUN_fffffff009c15344(undefined8 param_1)

{
  ulong uVar1;
  long *plVar2;
  undefined1 auVar3 [16];
  
  auVar3 = (**(code **)(DAT_fffffff00af48120 + 0x68))();
  plVar2 = auVar3._0_8_;
  if ((plVar2 != (long *)0x0) &&
     (uVar1 = FUN_fffffff009c15480(plVar2,auVar3._8_8_,0,1,param_1), (uVar1 & 1) == 0)) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
    plVar2 = (long *)0x0;
  }
  return plVar2;
}

