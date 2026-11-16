// FUN_fffffff009c3ef78 @ fffffff009c3ef78 size=4

void FUN_fffffff009c3ef78(long param_1)

{
  long lVar1;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long lStack_38;
  
  lStack_38 = *(long *)PTR_DAT_fffffff00806ca40;
  if ((*(byte *)(param_1 + 0x121) & 1) == 0) {
    thunk_EXT_FUN_801100000325c0a0();
    lVar1 = thunk_EXT_FUN_80110000032970b4();
    if (lVar1 != 0) {
      uStack_58 = 0;
      uStack_60 = 0;
      uStack_48 = 0;
      uStack_50 = 0;
      uStack_78 = 0;
      uStack_80 = 0;
      uStack_68 = 0;
      uStack_70 = 0;
      uStack_98 = 0;
      uStack_a0 = 0;
      uStack_88 = 0;
      uStack_90 = 0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_a8 = 0;
      uStack_b0 = 0;
      uStack_d8 = 0;
      uStack_e0 = 0;
      uStack_c8 = 0;
      uStack_d0 = 0;
      uStack_f8 = 0;
      uStack_100 = 0;
      uStack_e8 = 0;
      uStack_f0 = 0;
      uStack_118 = 0;
      uStack_120 = 0;
      uStack_108 = 0;
      uStack_110 = 0;
      uStack_138 = 0;
      uStack_140 = 0;
      uStack_128 = 0;
      uStack_130 = 0;
      thunk_EXT_FUN_8011000003722ec0(&uStack_140,0x100);
      thunk_EXT_FUN_8011000003720f30(lVar1);
      thunk_EXT_FUN_80110000038fe9a0
                ("Security: Process %s (%d) relying on global (insecure) IOSurface lookups\n");
    }
    *(undefined1 *)(param_1 + 0x121) = 1;
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

