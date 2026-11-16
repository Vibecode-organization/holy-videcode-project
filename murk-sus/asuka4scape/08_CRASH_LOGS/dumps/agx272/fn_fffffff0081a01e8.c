// FUN_fffffff0081a01e8 @ fffffff0081a01e8 size=8

void FUN_fffffff0081a01e8(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae22280 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae22288 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae22290 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae22298 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae222a0 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae222a8 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae222b0 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae222b8 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae222c0 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae222c8,"AGXEventMachine",PTR_DAT_fffffff007ca6040,0x21450);
  *puVar1 = &DAT_fffffff007c94e28;
  return;
}

