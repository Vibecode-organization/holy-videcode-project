// FUN_fffffff0081eeb0c @ fffffff0081eeb0c size=8

void FUN_fffffff0081eeb0c(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae234f8 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23500 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23508 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23510 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23518 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23520 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23528 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23530 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23538 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  DAT_fffffff00ae23540 = thunk_EXT_FUN_80110000038d0164("registerKernelClientToApplePPMFunction");
  DAT_fffffff00ae23548 = thunk_EXT_FUN_80110000038d0164("setBudgetToKernelClientFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23550,"AGXPeakPowerManager",PTR_DAT_fffffff007ca60b0,0x38);
  *puVar1 = &DAT_fffffff007c9dbd0;
  return;
}

