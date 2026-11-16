// FUN_fffffff0081e5f44 @ fffffff0081e5f44 size=332

void FUN_fffffff0081e5f44(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  DAT_fffffff00ae231d0 = thunk_EXT_FUN_80110000038d0164("getFilteredGPUPowerToKernelClientFunction")
  ;
  DAT_fffffff00ae231d8 = thunk_EXT_FUN_80110000038d0164("getCLPCDynamicSplitRatioDictKey");
  DAT_fffffff00ae231e0 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyCountKey");
  DAT_fffffff00ae231e8 = thunk_EXT_FUN_80110000038d0164("getCLPCStandbyDurationKey");
  DAT_fffffff00ae231f0 = thunk_EXT_FUN_80110000038d0164("getCLPCPowerSamplePeriodKey");
  DAT_fffffff00ae231f8 = thunk_EXT_FUN_80110000038d0164("getCLPCPerfCtrlTargetKey");
  DAT_fffffff00ae23200 = thunk_EXT_FUN_80110000038d0164("setCLPCDeadlineControlEffortKey");
  DAT_fffffff00ae23208 = thunk_EXT_FUN_80110000038d0164("setAGXGameModeKey");
  DAT_fffffff00ae23210 = thunk_EXT_FUN_80110000038d0164("setBudgetToAGXFunction");
  puVar1 = PTR_DAT_fffffff007ca60b0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23218,"AGXMeshShadersEmuMemory",PTR_DAT_fffffff007ca60b0,
                      0x13b8);
  *puVar2 = &DAT_fffffff007c9cd60;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00ae23240,"AGXMeshShadersEmuMemoryBlock",puVar1,0x80);
  *puVar2 = &DAT_fffffff007c9ce78;
  return;
}

