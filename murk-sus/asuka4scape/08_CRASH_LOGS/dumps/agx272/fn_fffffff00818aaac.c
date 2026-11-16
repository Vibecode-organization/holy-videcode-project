// FUN_fffffff00818aaac @ fffffff00818aaac size=316

void FUN_fffffff00818aaac(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae21e98 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae21ea0 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae21ea8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae21eb0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae21eb8 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae21ec0 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae21ec8 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae21ed0 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae21ed8 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23d28,"AGXCommandDescriptor",PTR_DAT_fffffff007ca6070,0x240);
  *puVar1 = &DAT_fffffff007c939d0;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae21ee0,"AGXCommandBuffer",PTR_DAT_fffffff007ca60b0,0x17c0);
  *puVar1 = &DAT_fffffff007c93b30;
  return;
}

