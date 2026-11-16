// FUN_fffffff009c19f18 @ fffffff009c19f18 size=4

ulong FUN_fffffff009c19f18(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
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
  long lStack_48;
  
  lStack_48 = *(long *)PTR_DAT_fffffff00806ca40;
  if (param_2 == *(long *)(param_1 + 0x28)) {
    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = 1;
    thunk_EXT_FUN_801100000325c0a0();
    lVar2 = thunk_EXT_FUN_80110000032970b4();
    uStack_68 = 0;
    uStack_70 = 0;
    uStack_58 = 0;
    uStack_60 = 0;
    uStack_88 = 0;
    uStack_90 = 0;
    uStack_78 = 0;
    uStack_80 = 0;
    uStack_a8 = 0;
    uStack_b0 = 0;
    uStack_98 = 0;
    uStack_a0 = 0;
    uStack_c8 = 0;
    uStack_d0 = 0;
    uStack_b8 = 0;
    uStack_c0 = 0;
    uStack_e8 = 0;
    uStack_f0 = 0;
    uStack_d8 = 0;
    uStack_e0 = 0;
    uStack_108 = 0;
    uStack_110 = 0;
    uStack_f8 = 0;
    uStack_100 = 0;
    uStack_128 = 0;
    uStack_130 = 0;
    uStack_118 = 0;
    uStack_120 = 0;
    uStack_148 = 0;
    uStack_150 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    if (lVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = thunk_EXT_FUN_8011000003720f30(lVar2);
      thunk_EXT_FUN_8011000003722ec0(&uStack_150,0x100);
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
               "process %s (%d) caught causing IOFence deadlock!\n");
    thunk_EXT_FUN_801100000322ffdc("process %s (%d) caught causing IOFence deadlock!\n");
    if (((lVar2 != 0) && (iVar1 != 0)) && ((*(byte *)(param_1 + 0x31) >> 1 & 1) != 0)) {
      uVar3 = thunk_EXT_FUN_80110000037cd9d4(0x15,2);
      uStack_168 = 0;
      uStack_170 = 0;
      uStack_158 = 0;
      uStack_160 = 0;
      uStack_188 = 0;
      uStack_190 = 0;
      uStack_178 = 0;
      uStack_180 = 0;
      thunk_EXT_FUN_8011000003350958(&uStack_190,"Process caught creating IOFence deadlock",0x40);
      thunk_EXT_FUN_80110000037cde94(uVar3,0x82);
      thunk_EXT_FUN_80110000037cdf28(uVar3,2,&uStack_190,0x40);
      thunk_EXT_FUN_8011000003736f3c(lVar2,uVar3);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,
                 "Killed process %s (%d) for causing IOFence deadlock!\n");
      thunk_EXT_FUN_801100000322ffdc("Killed process %s (%d) for causing IOFence deadlock!\n");
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == lStack_48) {
    return (ulong)(*(byte *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) & 1);
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

