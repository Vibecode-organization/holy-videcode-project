// FUN_fffffff0081f7d90 @ fffffff0081f7d90 size=332

void FUN_fffffff0081f7d90(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  DAT_fffffff00ae237d0 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae237d8 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae237e0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae237e8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae237f0 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae237f8 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23800 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23808 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23810 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = PTR_DAT_fffffff007ca60b0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23818,"AGXFastRenderTarget",PTR_DAT_fffffff007ca60b0,0xa0);
  *puVar2 = &DAT_fffffff007c9e348;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23840,"AGXRenderTargetMemory",puVar1,0x2c8);
  *puVar2 = &DAT_fffffff007c9e4a8;
  return;
}

