// FUN_fffffff0099703fc @ fffffff0099703fc size=212

void FUN_fffffff0099703fc(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  puVar1 = PTR_DAT_fffffff007ff27b0;
  thunk_EXT_FUN_8011000003890d88
            (&DAT_fffffff00af226c8,"IOGPUResourceSet",PTR_DAT_fffffff007ff27b0,0x30);
  DAT_fffffff00af226c8 = &DAT_fffffff007fedc78;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af226f0,"IOGPUWeakResourceSet",&DAT_fffffff00af226c8,0x30);
  *puVar2 = &DAT_fffffff007feddb0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22718,"IOGPUSegmentResourceList",puVar1,0x10);
  *puVar2 = &DAT_fffffff007fedee0;
  return;
}

