// FUN_fffffff00996f770 @ fffffff00996f770 size=212

void FUN_fffffff00996f770(void)

{
  undefined8 *puVar1;
  
  thunk_EXT_FUN_8011000003890d88
            (&DAT_fffffff00af22650,"IOGPUCommandDescriptor",&DAT_fffffff00af22290,0x140);
  DAT_fffffff00af22650 = &DAT_fffffff007fed890;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22678,"IOGPUMappingCommand",&DAT_fffffff00af22290,0x40);
  *puVar1 = &DAT_fffffff007fed9c0;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af226a0,"IOGPUMappingCommandDescriptor",&DAT_fffffff00af22650,
                      0x180);
  *puVar1 = &DAT_fffffff007fedb40;
  return;
}

