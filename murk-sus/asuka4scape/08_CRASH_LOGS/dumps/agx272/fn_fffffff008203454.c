// FUN_fffffff008203454 @ fffffff008203454 size=8

void FUN_fffffff008203454(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae23e28 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23e30 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23e38 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23e40 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23e48 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23e50 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23e58 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23e60 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23e68 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23e70,"AGXSpillMetadataBlock",PTR_DAT_fffffff007ca60b0,0x50);
  *puVar1 = &DAT_fffffff007c9f210;
  return;
}

