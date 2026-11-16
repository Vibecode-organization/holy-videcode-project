// FUN_fffffff009ccefe4 @ fffffff009ccefe4

/* WARNING: Removing unreachable block (ram,0xfffffff009ccf274) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ccf110) */

undefined8
FUN_fffffff009ccefe4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  code *pcVar3;
  bool bVar4;
  uint uVar5;
  long *plVar6;
  short *psVar7;
  undefined8 uVar8;
  long *extraout_x0;
  ulong uVar9;
  short *unaff_x22;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 auVar10 [16];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  undefined4 uVar13;
  undefined1 auVar14 [12];
  ulong uStack_98;
  short *psStack_90;
  short *psStack_88;
  long *plStack_80;
  long *plStack_78;
  undefined1 *puStack_70;
  undefined8 uStack_68;
  short *local_60;
  undefined8 uStack_58;
  char *local_50;
  char *pcStack_48;
  ulong local_40;
  
  uVar13 = param_4._0_4_;
  auVar14 = param_4._4_12_;
  uVar11 = param_3._0_4_;
  auVar12 = param_3._4_12_;
  plVar6 = thunk_FUN_fffffff00a894f30((long *)param_7[0x17],*(long *)PTR_PTR_fffffff008089ca8);
  if ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
      psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
      unaff_x22 = (short *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
      uStack_58 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      local_50 = "AppleT8027USBXDCI";
      pcStack_48 = "disableClock";
      local_60 = unaff_x22;
      thunk_FUN_fffffff00a8df19c
                (extraout_q0,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar7,0,
                 (byte *)"%s@%s: %s::%s: \n");
    }
    else {
      psVar7 = (short *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
      uStack_58 = (**(code **)(*param_7 + 0x218))(param_7,0);
      local_50 = "AppleT8027USBXDCI";
      pcStack_48 = "disableClock";
      local_60 = psVar7;
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: \n");
    }
  }
  if ((int)param_7[0x4ce] != 0) {
    if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
       (bVar4 = thunk_FUN_fffffff00a394140(), bVar4)) {
      psVar7 = (short *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
      uStack_58 = (**(code **)(*param_7 + 0x218))(param_7,0);
      local_40 = (ulong)*(uint *)(param_7 + 0x4ce);
      local_50 = "AppleT8027USBXDCI";
      pcStack_48 = "disableClock";
      local_60 = psVar7;
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
      auVar10 = extraout_q0_00;
    }
    else {
      psVar7 = *(short **)PTR_DAT_fffffff008089cb8;
      unaff_x22 = (short *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
      uStack_58 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      local_40 = (ulong)*(uint *)(param_7 + 0x4ce);
      local_50 = "AppleT8027USBXDCI";
      pcStack_48 = "disableClock";
      local_60 = unaff_x22;
      auVar10 = thunk_FUN_fffffff00a8df19c
                          (extraout_q0_01,param_2,uVar11,uVar13,param_5,param_6,&MACH_HEADER,psVar7,
                           0x11,(byte *)"%s@%s: %s::%s: unexpected _clockReferenceCount %u\n");
    }
    if (*(int *)((long)param_7 + 500) < 0) {
      auVar1._4_12_ = auVar12;
      auVar1._0_4_ = uVar11;
      auVar2._4_12_ = auVar14;
      auVar2._0_4_ = uVar13;
      FUN_fffffff009d14ed0(auVar10,param_2,auVar1,auVar2,param_5,param_6);
      uStack_68 = 0xfffffff009ccf34c;
      psStack_90 = unaff_x22;
      psStack_88 = psVar7;
      plStack_80 = plVar6;
      plStack_78 = param_7;
      puStack_70 = &stack0xfffffffffffffff0;
      uVar8 = (*(code *)PTR_FUN_fffffff0080876c8)();
      if ((int)uVar8 == 0) {
        uVar8 = 0xe00002d6;
        uStack_98 = 0;
        thunk_FUN_fffffff00a208ed8(1000,1000,(long *)&uStack_98);
        uVar9 = thunk_FUN_fffffff00a39bc88();
        if (uVar9 < uStack_98) {
          do {
            uVar5 = (**(code **)(*extraout_x0 + 0x818))(extraout_x0,extraout_x0[0x4e3],0);
            if ((uVar5 >> 0xf & 1) == 0) {
              return 0;
            }
            thunk_FUN_fffffff00a902988(0x14);
            uVar9 = thunk_FUN_fffffff00a39bc88();
          } while (uVar9 < uStack_98);
        }
      }
      return uVar8;
    }
  }
  (**(code **)(*plVar6 + 0x580))(plVar6,6,0);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    uVar8 = (*(code *)PTR_LAB_fffffff008087768)(param_7,&PTR_LAB_fffffff008087768);
    return uVar8;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ccf33c);
  (*pcVar3)();
}

