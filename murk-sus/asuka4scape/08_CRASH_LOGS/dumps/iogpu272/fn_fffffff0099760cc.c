// FUN_fffffff0099760cc @ fffffff0099760cc size=296

void FUN_fffffff0099760cc(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  ulong unaff_x30;
  
  thunk_EXT_FUN_8011000003890d88
            (&DAT_fffffff00af22768,"IOAcceleratorES",PTR_DAT_fffffff007ff27c0,0x88);
  DAT_fffffff00af22768 = &DAT_fffffff007fee628;
  puVar2 = (undefined8 *)
           thunk_EXT_FUN_8011000003890d88(&DAT_fffffff00af22790,"IOGPU",&DAT_fffffff00af22768,0x2f0)
  ;
  *puVar2 = &DAT_fffffff007feeda0;
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21d50);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21da0);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21df0);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21e40);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21e90);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21ee0);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21f30);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21f80);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af21fd0);
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af22020);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099761f0);
    (*pcVar1)();
  }
  thunk_EXT_FUN_8011000003740c44(&DAT_fffffff00af22070);
  return;
}

