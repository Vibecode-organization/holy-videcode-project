// FUN_fffffff0081b97d8 @ fffffff0081b97d8 size=4

undefined8 FUN_fffffff0081b97d8(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  undefined8 uStack_40;
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  
  uVar1 = FUN_fffffff0081b991c(param_1,param_2,"SetFabPStateThreshold",FUN_fffffff0081b9b44,0);
  if (((((int)uVar1 == 0) &&
       (uVar1 = FUN_fffffff0081b991c(param_1,param_2,"SetDebouncePeriods",FUN_fffffff0081b9b08,0),
       (int)uVar1 == 0)) &&
      (uVar1 = FUN_fffffff0081b991c(param_1,param_2,"SetFabPStateStepSize",FUN_fffffff0081b9acc,0),
      (int)uVar1 == 0)) &&
     ((uVar1 = FUN_fffffff0081b991c(param_1,param_2,"SetPeriodMSec",FUN_fffffff0081b9ab8,0),
      (int)uVar1 == 0 &&
      (uVar1 = FUN_fffffff0081b991c(param_1,param_2,"SetDefaultFabPStates",FUN_fffffff0081b9a9c,0),
      (int)uVar1 == 0)))) {
    DataMemoryBarrier(2,3);
    uStack_38 = 0;
    uStack_40 = 0;
    uStack_28 = 0;
    uStack_30 = 0;
    uStack_58 = 0;
    uStack_48 = 0;
    uStack_50 = 0;
    uStack_60 = 0x23;
    FUN_fffffff0081b6d20(param_1,&uStack_60,1);
    uVar1 = 0;
  }
  return uVar1;
}

