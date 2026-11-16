// FUN_fffffff009c382d0 @ fffffff009c382d0 size=156

void FUN_fffffff009c382d0(void)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48360,"IOSurfaceRootParavirtMapperInterface",
                      PTR_DAT_fffffff00806ca00,0x10);
  *puVar1 = &DAT_fffffff008067d18;
  puVar1 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88
                     (&DAT_fffffff00af48388,"IOSurfaceRoot",PTR_DAT_fffffff00806ca18,0x4a0);
  *puVar1 = &DAT_fffffff008068308;
  DAT_fffffff00af485a0 = thunk_EXT_FUN_80110000038d02e4("setIomdCacheAttribute");
  return;
}

