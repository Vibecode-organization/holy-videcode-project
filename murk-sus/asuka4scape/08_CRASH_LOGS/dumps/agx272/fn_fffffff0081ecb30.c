// FUN_fffffff0081ecb30 @ fffffff0081ecb30 size=452

void FUN_fffffff0081ecb30(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  DAT_fffffff00ae23320 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23328 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23330 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23338 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23340 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23348 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23350 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23358 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23360 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23458,"AGXParameterManagement",PTR_DAT_fffffff007ca5fa8,0x228)
  ;
  *puVar2 = &DAT_fffffff007c9d1a0;
  puVar1 = PTR_DAT_fffffff007ca60b0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae234a8,"AGXParameterBufferBlock",PTR_DAT_fffffff007ca60b0,0x10)
  ;
  *puVar2 = &DAT_fffffff007c9d228;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23368,"AGXCommandQueuePMConfig",puVar1,0x30);
  *puVar2 = &DAT_fffffff007c9d348;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23390,"AGXHWParamBufferManager",&DAT_fffffff00ae233b8,0xa0);
  *puVar2 = &DAT_fffffff007c9d478;
  return;
}

