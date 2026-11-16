// FUN_fffffff00819bac8 @ fffffff00819bac8 size=8

void FUN_fffffff00819bac8(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae21f08 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae21f10 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae21f18 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae21f20 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae21f28 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae21f30 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae21f38 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae21f40 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae21f48 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae21f50,"AGXCommandQueue",PTR_DAT_fffffff007ca6038,0x948);
  *puVar1 = &DAT_fffffff007c93d30;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae21f78,"AGXCommandQueueReclaimableState",
                      PTR_DAT_fffffff007ca60b0,0xf8);
  *puVar1 = &DAT_fffffff007c93e50;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae21fa0,"AGXUniqueResourceSet",PTR_DAT_fffffff007ca6030,0x30);
  *puVar1 = &DAT_fffffff007c93f98;
  return;
}

