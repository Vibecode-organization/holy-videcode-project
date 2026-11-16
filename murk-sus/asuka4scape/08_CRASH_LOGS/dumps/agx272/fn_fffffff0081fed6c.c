// FUN_fffffff0081fed6c @ fffffff0081fed6c size=8

void FUN_fffffff0081fed6c(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae23a98 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23aa0 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23aa8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23ab0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23ab8 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23ac0 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23ac8 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23ad0 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23ad8 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23ae0,"AGXSecureGart",&DAT_fffffff00ae23b08,0x300);
  *puVar1 = &DAT_fffffff007c9ebc8;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23b48,"AGXSecureSharedGartTableBacking",&DAT_fffffff00ae23b70,
                      0x88);
  *puVar1 = &DAT_fffffff007c9ec50;
  return;
}

