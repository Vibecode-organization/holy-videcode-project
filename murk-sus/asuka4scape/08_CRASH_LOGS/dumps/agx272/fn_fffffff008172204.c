// FUN_fffffff008172204 @ fffffff008172204 size=148

undefined8 FUN_fffffff008172204(long param_1,ulong param_2)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_1 + 0x115c0);
  if (param_2 != *pbVar1) {
    *pbVar1 = (byte)param_2;
    (**(code **)(**(long **)(param_1 + 0x310) + 0xe8))
              (*(long **)(param_1 + 0x310),FUN_fffffff008172298,pbVar1,0,0,0);
  }
  thunk_EXT_FUN_8011000003948c0c(param_1);
  return 0;
}

