// FUN_fffffff009cac2a4 @ fffffff009cac2a4

/* WARNING: Removing unreachable block (ram,0xfffffff009caca14) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cac80c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cac95c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cacacc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cac414) */

undefined8
FUN_fffffff009cac2a4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  bool bVar9;
  int iVar10;
  undefined8 uVar11;
  long extraout_x0;
  long lVar12;
  long *plVar13;
  long extraout_x0_00;
  char *pcVar14;
  short *psVar15;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 auVar16 [16];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  uVar11 = (**(code **)(PTR_DAT_fffffff0080813a8 + 0xb8))();
  if ((int)uVar11 == 0) {
    return uVar11;
  }
  puVar1 = (uint *)(param_7 + 0x4c7);
  uVar2 = *(uint *)((long)param_7 + 500);
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar2 >> 3 & 1) != 0) {
      if (((uVar2 >> 0x1e & 1) == 0) || (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
        psVar15 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                   (byte *)"%s@%s: %s::%s: [%p] debug logging mask 0x%08x\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: [%p] debug logging mask 0x%08x\n");
      }
    }
  }
  else if ((uVar2 >> 3 & 1) != 0) {
    FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:[%p] debug logging mask 0x%08x\n")
    ;
  }
  iVar10 = thunk_FUN_fffffff00aa14b0c((byte *)"debug-usb",puVar1,4);
  auVar16 = extraout_q0;
  if (iVar10 != 0) {
    uVar3 = *puVar1;
    uVar2 = uVar3;
    if (0xfe < uVar3) {
      uVar2 = 0xff;
    }
    *puVar1 = uVar2;
    if (uVar3 != 0) {
      *(uint *)(param_7 + 0x4c7) = uVar2 << 10;
      auVar16._4_12_ = auVar18;
      auVar16._0_4_ = uVar17;
      auVar6._4_12_ = auVar20;
      auVar6._0_4_ = uVar19;
      thunk_FUN_fffffff00a902580
                (extraout_q0,param_2,auVar16,auVar6,param_5,param_6,(ulong *)(ulong)(uVar2 << 10));
      param_7[0x4c8] = extraout_x0;
      lVar12 = extraout_x0;
      auVar16 = extraout_q0_00;
      if (extraout_x0 == 0) {
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"AppleUSBXDCI: failed to allocate logging buffer of %d bytes");
        *(undefined4 *)(param_7 + 0x4c7) = 0;
        lVar12 = param_7[0x4c8];
        auVar16 = extraout_q0_01;
      }
      param_7[0x4c9] = lVar12;
    }
  }
  auVar4._4_12_ = auVar18;
  auVar4._0_4_ = uVar17;
  auVar7._4_12_ = auVar20;
  auVar7._0_4_ = uVar19;
  plVar13 = thunk_FUN_fffffff00a95c9e4(auVar16,param_2,auVar4,auVar7,param_5,param_6);
  param_7[0x8b] = (long)plVar13;
  if (plVar13 == (long *)0x0) {
    uVar2 = *(uint *)((long)param_7 + 500);
    if ((int)param_7[0x4c7] == 0) {
      if ((uVar2 & 1) == 0) {
        return 0;
      }
      if (((uVar2 >> 0x1e & 1) == 0) || (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
        psVar15 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                   (byte *)"%s@%s: %s::%s: failed to create workLoop\n");
        return 0;
      }
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      pcVar14 = "%s@%s: %s::%s: failed to create workLoop\n";
      goto LAB_fffffff009cac8f8;
    }
    if ((uVar2 & 1) == 0) {
      return 0;
    }
    pcVar14 = "AppleUSBXDCI::%s:failed to create workLoop\n";
  }
  else {
    plVar13 = thunk_FUN_fffffff00a960074(param_7,0);
    param_7[0x8c] = (long)plVar13;
    if (plVar13 == (long *)0x0) {
      uVar2 = *(uint *)((long)param_7 + 500);
      if ((int)param_7[0x4c7] == 0) {
        if ((uVar2 & 1) == 0) {
          return 0;
        }
        if (((uVar2 >> 0x1e & 1) == 0) || (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
          psVar15 = *(short **)PTR_DAT_fffffff008081388;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                     (byte *)"%s@%s: %s::%s: failed to create commandGate\n");
          return 0;
        }
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        pcVar14 = "%s@%s: %s::%s: failed to create commandGate\n";
        goto LAB_fffffff009cac8f8;
      }
      if ((uVar2 & 1) == 0) {
        return 0;
      }
      pcVar14 = "AppleUSBXDCI::%s:failed to create commandGate\n";
    }
    else {
      lVar12 = thunk_FUN_fffffff00a90348c();
      param_7[0x8d] = lVar12;
      if (lVar12 == 0) {
        uVar2 = *(uint *)((long)param_7 + 500);
        if ((int)param_7[0x4c7] == 0) {
          if ((uVar2 & 1) == 0) {
            return 0;
          }
          if (((uVar2 >> 0x1e & 1) == 0) || (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
            psVar15 = *(short **)PTR_DAT_fffffff008081388;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                       (byte *)"%s@%s: %s::%s: failed to allocate interrupt lock\n");
            return 0;
          }
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar14 = "%s@%s: %s::%s: failed to allocate interrupt lock\n";
          goto LAB_fffffff009cac8f8;
        }
        if ((uVar2 & 1) == 0) {
          return 0;
        }
        pcVar14 = "AppleUSBXDCI::%s:failed to allocate interrupt lock\n";
      }
      else {
        lVar12 = thunk_FUN_fffffff00a902074((long *)&DAT_fffffff008080d78);
        param_7[0x4bc] = lVar12;
        *(undefined4 *)(param_7 + 0x4be) = 0x14;
        auVar5._4_12_ = auVar18;
        auVar5._0_4_ = uVar17;
        auVar8._4_12_ = auVar20;
        auVar8._0_4_ = uVar19;
        thunk_FUN_fffffff00a9025cc
                  (extraout_q0_02,param_2,auVar5,auVar8,param_5,param_6,(ulong *)&DAT_00000014);
        param_7[0x4bd] = extraout_x0_00;
        if ((extraout_x0_00 != 0) && (param_7[0x4bc] != 0)) {
          return 1;
        }
        uVar2 = *(uint *)((long)param_7 + 500);
        if ((int)param_7[0x4c7] == 0) {
          if ((uVar2 & 1) == 0) {
            return 0;
          }
          if (((uVar2 >> 0x1e & 1) == 0) || (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
            psVar15 = *(short **)PTR_DAT_fffffff008081388;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                       (byte *)
                       "%s@%s: %s::%s: failed to allocate Device Capability Descriptors memory\n");
            return 0;
          }
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar14 = "%s@%s: %s::%s: failed to allocate Device Capability Descriptors memory\n";
LAB_fffffff009cac8f8:
          thunk_FUN_fffffff00a9029a0((byte *)pcVar14);
          return 0;
        }
        if ((uVar2 & 1) == 0) {
          return 0;
        }
        pcVar14 = "AppleUSBXDCI::%s:failed to allocate Device Capability Descriptors memory\n";
      }
    }
  }
  FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar14);
  return 0;
}

