// FUN_fffffff00995bd18 @ fffffff00995bd18 size=208

void FUN_fffffff00995bd18(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22470,"IOGPUIOCommandDescriptor",&DAT_fffffff00af22290,0x58);
  *puVar1 = &DAT_fffffff007fec6c8;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af22498,"IOGPUIOCommandBuffer",&DAT_fffffff00af22290,0x70);
  *puVar1 = &DAT_fffffff007fec810;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af224c0,"IOGPUIOCommandQueue",&DAT_fffffff00af22290,0xb0);
  *puVar1 = &DAT_fffffff007fec950;
  return;
}

