// FUN_fffffff0081e2070 @ fffffff0081e2070 size=376

void FUN_fffffff0081e2070(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae23030 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae23038 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae23040 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23048 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23050 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23058 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23060 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23068 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23070 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23078,"AGXLateEvalEventFence",PTR_DAT_fffffff007ca5ff8,0xe0);
  *puVar1 = &DAT_fffffff007c9c718;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae230a0,"AGXLateEvalWait",PTR_DAT_fffffff007ca60b0,200);
  *puVar1 = &DAT_fffffff007c9c830;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae230c8,"AGXLateEvalEvent",PTR_DAT_fffffff007ca6068,0x78);
  *puVar1 = &DAT_fffffff007c9c960;
  return;
}

