// FUN_fffffff0082142a4 @ fffffff0082142a4 size=448

void FUN_fffffff0082142a4(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae25ac8 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae25ad0 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae25ad8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae25ae0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae25ae8 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae25af0 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae25af8 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae25b00 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae25b08 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  thunk_EXT_FUN_8011000003890d88
            (&DAT_fffffff00ae25b10,"AGXWorkQueue",PTR_DAT_fffffff007ca5fe8,0x240);
  DAT_fffffff00ae25b10 = &DAT_fffffff007ca0498;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae25b38,"AGX3DWorkQueue",&DAT_fffffff00ae25b10,0x240);
  *puVar1 = &DAT_fffffff007ca0688;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae25b60,"AGXCLWorkQueue",&DAT_fffffff00ae25b10,0x240);
  *puVar1 = &DAT_fffffff007ca0838;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae25b88,"AGXScheduler",PTR_DAT_fffffff007ca5fd8,0x250);
  *puVar1 = &DAT_fffffff007ca0990;
  return;
}

