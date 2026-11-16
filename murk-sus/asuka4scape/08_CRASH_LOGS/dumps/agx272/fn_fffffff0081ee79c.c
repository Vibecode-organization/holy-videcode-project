// FUN_fffffff0081ee79c @ fffffff0081ee79c size=8

void FUN_fffffff0081ee79c(void)

{
  undefined8 *puVar1;
  
  DAT_fffffff00ae233e8 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae233f0 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae233f8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae23400 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae23408 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae23410 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23418 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23420 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23428 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23430,"AGXParameterManagementVirtual",&DAT_fffffff00ae23458,
                      0x248);
  *puVar1 = &DAT_fffffff007c9d660;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23480,"AGXParameterBufferBlockVirtual",&DAT_fffffff00ae234a8,
                      0x20);
  *puVar1 = &DAT_fffffff007c9d7a0;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae234d0,"AGXParameterMemoryVirtual",PTR_DAT_fffffff007ca5fa0,
                      0xa0);
  *puVar1 = &DAT_fffffff007c9dab8;
  return;
}

