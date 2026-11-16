// FUN_fffffff009c46e3c @ fffffff009c46e3c size=264

void FUN_fffffff009c46e3c(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  puVar1 = PTR_DAT_fffffff00806ca00;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48430,"IOSurfaceDescriptorContext",PTR_DAT_fffffff00806ca00,
                      0x40);
  *puVar2 = &DAT_fffffff00806a458;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48458,"IOSurfaceDescriptorComponent",puVar1,0x20);
  *puVar2 = &DAT_fffffff00806a580;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48480,"IOSurfaceMemoryPoolBunch",puVar1,0x48);
  *puVar2 = &DAT_fffffff00806a6a8;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88(&DAT_fffffff00af484a8,"IOSurfaceMemoryPool",puVar1,0xb0);
  *puVar2 = &DAT_fffffff00806a7d8;
  return;
}

