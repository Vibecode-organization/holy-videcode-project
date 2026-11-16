// FUN_fffffff008200c90 @ fffffff008200c90 size=256

void FUN_fffffff008200c90(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae23c48 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23c50 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23c58 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23c60 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23c68 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23c70 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23c78 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23c80 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23c88 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23c90,"AGXShared",PTR_DAT_fffffff007ca5f98,0x218);
  *puVar1 = &DAT_fffffff007c9eec8;
  return;
}

