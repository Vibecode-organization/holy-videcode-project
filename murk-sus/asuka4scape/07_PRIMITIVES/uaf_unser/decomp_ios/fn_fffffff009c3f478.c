// FUN_fffffff009c3f478 @ fffffff009c3f478 size=496
// CALLERS:
//   fffffff009c3ae90 FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c3b708 FUN_fffffff009c3b628@fffffff009c3b628
//   fffffff009c3b95c FUN_fffffff009c3b7b0@fffffff009c3b7b0
//   fffffff009c3bd78 FUN_fffffff009c3bb20@fffffff009c3bb20
//   fffffff009c3c1b0 FUN_fffffff009c3bf44@fffffff009c3bf44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

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
  
  local_48 = *_DAT_fffffff00806ca40;
  uVar2 = *(uint *)(param_1 + 0x128);
  if (param_3 != 0) {
    uVar2 = uVar2 + 1;
    *(uint *)(param_1 + 0x128) = uVar2;
  }
  *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  if (0x1fff < uVar2) {
    if ((*(byte *)(param_1 + 0x124) & 1) == 0) {
      FUN_fffffff009c49bc4();
      lVar1 = FUN_fffffff009c49bd4();
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
        FUN_fffffff009c49d44(&local_150,0x100);
        FUN_fffffff009c49d14(lVar1);
        FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0d60);
        FUN_fffffff009c49d14(lVar1);
        FUN_fffffff009c495f4(0xfffffff00789d072);
      }
      *(undefined1 *)(param_1 + 0x124) = 1;
      uVar2 = *(uint *)(param_1 + 0x128);
    }
    if ((0x2fff < uVar2) && ((*(byte *)(param_1 + 0x125) & 1) == 0)) {
      FUN_fffffff009c49bc4();
      lVar1 = FUN_fffffff009c49bd4();
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
        FUN_fffffff009c49d44(&local_150,0x100);
        FUN_fffffff009c49d14(lVar1);
        FUN_fffffff009c49b74(0xfffffff00789a030,_DAT_fffffff00806ca48,0x10,0xfffffff0078a0da6);
        FUN_fffffff009c49d14(lVar1);
        FUN_fffffff009c495f4(0xfffffff00789d0b8);
      }
      *(undefined1 *)(param_1 + 0x125) = 1;
    }
  }
  if (*_DAT_fffffff00806ca40 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c49b64();
}

