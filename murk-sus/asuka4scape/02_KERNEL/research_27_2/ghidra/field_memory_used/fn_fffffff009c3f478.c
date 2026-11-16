// FUN_fffffff009c3f478 @ fffffff009c3f478

void FUN_fffffff009c3f478
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,int param_9)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  long lVar3;
  ulong uVar4;
  uint uVar5;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
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
  uVar5 = *(uint *)(param_7 + 0x128);
  if (param_9 != 0) {
    uVar5 = uVar5 + 1;
    *(uint *)(param_7 + 0x128) = uVar5;
  }
  *(int *)(param_7 + 300) = *(int *)(param_7 + 300) + 1;
  if (0x1fff < uVar5) {
    if ((*(byte *)(param_7 + 0x124) & 1) == 0) {
      lVar3 = thunk_FUN_fffffff00a2600a0();
      uVar4 = thunk_FUN_fffffff00a29b0b4(lVar3);
      if (uVar4 != 0) {
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
        thunk_FUN_fffffff00a726ec0(&local_150,0x100);
        thunk_FUN_fffffff00a724f30(uVar4);
        auVar1._8_8_ = extraout_var;
        auVar1._0_8_ = extraout_d0;
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)"Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d\n")
        ;
        thunk_FUN_fffffff00a724f30(uVar4);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d\n")
        ;
      }
      *(undefined1 *)(param_7 + 0x124) = 1;
      uVar5 = *(uint *)(param_7 + 0x128);
    }
    if ((0x2fff < uVar5) && ((*(byte *)(param_7 + 0x125) & 1) == 0)) {
      lVar3 = thunk_FUN_fffffff00a2600a0();
      uVar4 = thunk_FUN_fffffff00a29b0b4(lVar3);
      if (uVar4 != 0) {
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
        thunk_FUN_fffffff00a726ec0(&local_150,0x100);
        thunk_FUN_fffffff00a724f30(uVar4);
        auVar2._8_8_ = extraout_var_00;
        auVar2._0_8_ = extraout_d0_00;
        thunk_FUN_fffffff00a8df19c
                  (auVar2,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00806ca48,0x10,
                   (byte *)
                   "Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d, possible leak?\n"
                  );
        thunk_FUN_fffffff00a724f30(uVar4);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "Perf: Process %s (%d) has created %d IOSurfaces out of a limit of %d, possible leak?\n"
                  );
      }
      *(undefined1 *)(param_7 + 0x125) = 1;
    }
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

