// FUN_fffffff009c2b358 @ fffffff009c2b358 size=8

void FUN_fffffff009c2b358(void)

{
  int iVar1;
  undefined8 *puVar2;
  
  iVar1 = thunk_EXT_FUN_8011000003a12d84(0);
  DAT_fffffff00af48578 = iVar1 != 0;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_80110000038918a0
                     (&DAT_fffffff00af48210,"IOSurface",PTR_DAT_fffffff00806ca00,0x3e0,
                      &DAT_fffffff00af48580,"iokit.IOSurface",0x2000000);
  *puVar2 = &DAT_fffffff0080671d0;
  return;
}

