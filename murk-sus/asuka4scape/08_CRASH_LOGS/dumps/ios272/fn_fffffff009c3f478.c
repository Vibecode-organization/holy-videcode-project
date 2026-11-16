// FUN_fffffff009c3f478 @ fffffff009c3f478 size=496

void FUN_fffffff009c3f478(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar2 = *(uint *)(param_1 + 0x128);
  if (param_3 != 0) {
    uVar2 = uVar2 + 1;
    *(uint *)(param_1 + 0x128) = uVar2;
  }
  *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  if (0x1fff < uVar2) {
    if ((*(byte *)(param_1 + 0x124) & 1) == 0) {
      thunk_EXT_FUN_801100000325c0a0();
      lVar1 = thunk_EXT_FUN_80110000032970b4();
      if (lVar1 != 0) {
        uStack_68 = 0;
        local_70 = 0;
        uStack_58 = 0;
        uStack_60 = 0;
        uStack_88 = 0;
        local_90 = 0;
        uStack_78 = 0;
        uStack_80 = 0;
        uStack_a8 = 0;
        local_b0 = 0;
        uStack_98 = 0;
        uStack_a0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_b8 = 0;
        uStack_c0 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_d8 = 0;
        uStack_e0 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_f8 = 0;
        uStack_100 = 0;
        uStack_128 = 0;
        local_130 = 0;
        uStack_118 = 0;
        uStack_120 = 0;
        uStack_148 = 0;
        local_150 = 0;
        uStack_138 = 0;
        uStack_140 = 0;
        thunk_EXT_FUN_8011000003722ec0(&local_150,0x100);
        thunk_EXT_FUN_8011000003720f30(lVar1);
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d\n");
        thunk_EXT_FUN_8011000003720f30(lVar1);
        thunk_EXT_FUN_80110000038fe9a0
                  ("Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d\n");
      }
      *(undefined1 *)(param_1 + 0x124) = 1;
      uVar2 = *(uint *)(param_1 + 0x128);
    }
    if ((0x2fff < uVar2) && ((*(byte *)(param_1 + 0x125) & 1) == 0)) {
      thunk_EXT_FUN_801100000325c0a0();
      lVar1 = thunk_EXT_FUN_80110000032970b4();
      if (lVar1 != 0) {
        uStack_68 = 0;
        local_70 = 0;
        uStack_58 = 0;
        uStack_60 = 0;
        uStack_88 = 0;
        local_90 = 0;
        uStack_78 = 0;
        uStack_80 = 0;
        uStack_a8 = 0;
        local_b0 = 0;
        uStack_98 = 0;
        uStack_a0 = 0;
        uStack_c8 = 0;
        local_d0 = 0;
        uStack_b8 = 0;
        uStack_c0 = 0;
        uStack_e8 = 0;
        local_f0 = 0;
        uStack_d8 = 0;
        uStack_e0 = 0;
        uStack_108 = 0;
        local_110 = 0;
        uStack_f8 = 0;
        uStack_100 = 0;
        uStack_128 = 0;
        local_130 = 0;
        uStack_118 = 0;
        uStack_120 = 0;
        uStack_148 = 0;
        local_150 = 0;
        uStack_138 = 0;
        uStack_140 = 0;
        thunk_EXT_FUN_8011000003722ec0(&local_150,0x100);
        thunk_EXT_FUN_8011000003720f30(lVar1);
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x10,
                   "Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d, possible leak?\n"
                  );
        thunk_EXT_FUN_8011000003720f30(lVar1);
        thunk_EXT_FUN_80110000038fe9a0
                  (
                  "Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d, possible leak?\n"
                  );
      }
      *(undefined1 *)(param_1 + 0x125) = 1;
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

