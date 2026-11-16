// FUN_fffffff009951218 @ fffffff009951218 size=380

void FUN_fffffff009951218(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  puVar1 = PTR_DAT_fffffff007ff27b0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22308,"IOGPUBlockFencePort",PTR_DAT_fffffff007ff27b0,0x58);
  *puVar2 = &DAT_fffffff007febaf0;
  thunk_EXT_FUN_8011000003890d88(&DAT_fffffff00af22330,"IOGPUEventFence",puVar1,0xd0);
  DAT_fffffff00af22330 = &DAT_fffffff007febc30;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22358,"IOGPUBlockFence",&DAT_fffffff00af22330,0x130);
  *puVar2 = &DAT_fffffff007febd88;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22380,"IOGPUSharedEventFence",&DAT_fffffff00af22330,0xe0);
  *puVar2 = &DAT_fffffff007febec8;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af223a8,"IOGPUMappingFence",&DAT_fffffff00af22330,0xd8);
  *puVar2 = &DAT_fffffff007fec008;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88(&DAT_fffffff00af223d0,"IOGPUFenceMachine",puVar1,0x78);
  *puVar2 = &DAT_fffffff007fec130;
  return;
}

