// FUN_fffffff0081d9ebc @ fffffff0081d9ebc size=8

void FUN_fffffff0081d9ebc(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae22998 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae229a0 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae229a8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae229b0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae229b8 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae229c0 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae229c8 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae229d0 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae229d8 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae229e0,"AGXGartG14",&DAT_fffffff00ae23ae0,0x300);
  *puVar1 = &DAT_fffffff007c98ef0;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae22a08,"AGXSharedGartTableBackingG14",&DAT_fffffff00ae23b48,
                      0x88);
  *puVar1 = &DAT_fffffff007c99050;
  return;
}

