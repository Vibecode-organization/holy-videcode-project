// FUN_fffffff009c18b44 @ fffffff009c18b44 size=324

void FUN_fffffff009c18b44(void)

{
  undefined *puVar1;
  undefined8 *puVar2;
  
  puVar1 = PTR_DAT_fffffff00806ca00;
  thunk_EXT_FUN_8011000003890d88
            (&DAT_fffffff00af48120,"IOSurfaceSharedEventListener",PTR_DAT_fffffff00806ca00,0x50);
  DAT_fffffff00af48120 = &DAT_fffffff008066728;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48148,"IOSurfaceSharedEventNotificationPort",
                      &DAT_fffffff00af48120,0x90);
  *puVar2 = &DAT_fffffff008066850;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48170,"IOSurfaceSharedEventReference",puVar1,0x18);
  *puVar2 = &DAT_fffffff008066978;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88(&DAT_fffffff00af48198,"IOSurfaceSharedEvent",puVar1,0x68);
  *puVar2 = &DAT_fffffff008066aa8;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af481c0,"IOSurfaceSharedEventNotification",puVar1,0x70);
  *puVar2 = &DAT_fffffff008066bd0;
  return;
}

