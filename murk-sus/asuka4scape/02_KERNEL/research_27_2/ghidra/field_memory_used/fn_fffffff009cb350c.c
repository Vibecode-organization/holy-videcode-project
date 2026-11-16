// FUN_fffffff009cb350c @ fffffff009cb350c

/* WARNING: Removing unreachable block (ram,0xfffffff009cb3c6c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb394c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb3a88) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb3ea4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb3684) */

void FUN_fffffff009cb350c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined4 param_9)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  code *pcVar8;
  byte bVar9;
  bool bVar10;
  int iVar11;
  undefined1 *puVar12;
  long lVar13;
  int *piVar14;
  uint uVar15;
  long lVar16;
  long *plVar17;
  long lVar18;
  short *psVar19;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined4 uVar22;
  undefined1 auVar23 [12];
  undefined4 uVar24;
  undefined1 auVar25 [12];
  char *in_stack_ffffffffffffff50;
  undefined1 *local_70;
  byte local_65;
  uint local_64;
  
  uVar24 = param_4._0_4_;
  auVar25 = param_4._4_12_;
  uVar22 = param_3._0_4_;
  auVar23 = param_3._4_12_;
  plVar17 = (long *)param_7[0xb8];
  uVar15 = (uint)param_8;
  lVar18 = param_7[(ulong)(uVar15 >> 7 & 1 | (uVar15 & 0x7f) << 1) + 0x8f];
  uVar1 = *(uint *)((long)param_7 + 500);
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar1 >> 9 & 1) != 0) {
      if (((uVar1 >> 0x1e & 1) == 0) || (bVar10 = thunk_FUN_fffffff00a394140(), !bVar10)) {
        psVar19 = *(short **)PTR_DAT_fffffff008081388;
        in_stack_ffffffffffffff50 = (char *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar21 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        param_1 = thunk_FUN_fffffff00a8df19c
                            (auVar21,param_2,uVar22,uVar24,param_5,param_6,&MACH_HEADER,psVar19,0,
                             (byte *)"%s@%s: %s::%s: endpoint 0x%02x\n");
      }
      else {
        in_stack_ffffffffffffff50 = (char *)(**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: endpoint 0x%02x\n");
        param_1 = extraout_q0_00;
      }
    }
  }
  else if ((uVar1 >> 9 & 1) != 0) {
    in_stack_ffffffffffffff50 = "stopEndpoint";
    FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:endpoint 0x%02x\n");
    param_1 = extraout_q0;
  }
  if (lVar18 == 0) {
    if ((int)param_7[0x4c7] == 0) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000002) == 0) &&
         (bVar10 = thunk_FUN_fffffff00a394140(), bVar10)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: endpoint 0x%02x not active\n");
      }
      else {
        psVar19 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar21 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar21,param_2,uVar22,uVar24,param_5,param_6,&MACH_HEADER,psVar19,0x10,
                   (byte *)"%s@%s: %s::%s: endpoint 0x%02x not active\n");
      }
    }
    else if ((*(uint *)((long)param_7 + 500) >> 1 & 1) != 0) {
      FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:endpoint 0x%02x not active\n");
    }
  }
  else {
    if (*(char *)(lVar18 + 0xd) == '\x01') {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cb3728);
        (*pcVar8)();
      }
      FUN_fffffff009cbeb40(param_1,param_2,uVar22,uVar24,param_5,param_6,param_7,param_8,param_9);
      return;
    }
    if (plVar17 == (long *)0x0) {
      plVar17 = (long *)param_7[0xb7];
    }
    local_64 = 0xaaaaaaaa;
    local_65 = 0xaa;
    local_70 = &DAT_aaaaaaaaaaaaaaaa;
    if (*(long *)(lVar18 + 0x70) != 0) {
      if (*(long **)(lVar18 + 0x80) != (long *)0x0) {
        (**(code **)(**(long **)(lVar18 + 0x80) + 0x138))();
      }
      if (*(char *)(lVar18 + 0x1a) != -1) {
        iVar11 = (**(code **)(*param_7 + 0x7e0))
                           (param_7,param_8,8,*(char *)(lVar18 + 0x1a),0,1,0,0,
                            (ulong)in_stack_ffffffffffffff50 & 0xffffffff00000000);
        if (iVar11 != 0) {
          uVar1 = *(uint *)((long)param_7 + 500);
          if ((int)param_7[0x4c7] == 0) {
            if ((uVar1 & 1) != 0) {
              if (((uVar1 >> 0x1e & 1) == 0) || (bVar10 = thunk_FUN_fffffff00a394140(), !bVar10)) {
                psVar19 = *(short **)PTR_DAT_fffffff008081388;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar21 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar21,param_2,uVar22,uVar24,param_5,param_6,&MACH_HEADER,psVar19,0,
                           (byte *)
                           "%s@%s: %s::%s: failed to kEpCommandEndXfer for endpoint 0x%02x (status 0x%08x)\n"
                          );
              }
              else {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0
                          ((byte *)
                           "%s@%s: %s::%s: failed to kEpCommandEndXfer for endpoint 0x%02x (status 0x%08x)\n"
                          );
              }
            }
          }
          else if ((uVar1 & 1) != 0) {
            FUN_fffffff009cacb28
                      ((ulong)param_7,
                       (byte *)
                       "AppleUSBXDCI::%s:failed to kEpCommandEndXfer for endpoint 0x%02x (status 0x%08x)\n"
                      );
          }
        }
        auVar20 = thunk_FUN_fffffff00a208ed8(500,1000000,(long *)&local_70);
        auVar21._4_12_ = auVar23;
        auVar21._0_4_ = uVar22;
        auVar4._4_12_ = auVar25;
        auVar4._0_4_ = uVar24;
        bVar9 = FUN_fffffff009cb5a70
                          (auVar20,param_2,auVar21,auVar4,param_5,param_6,param_7,1,uVar15,7,8);
        bVar9 = bVar9 & 1;
        while ((bVar9 == 0 &&
               (puVar12 = (undefined1 *)thunk_FUN_fffffff00a39bc88(), puVar12 <= local_70))) {
          auVar21 = thunk_FUN_fffffff00a902968(2);
          auVar20._4_12_ = auVar23;
          auVar20._0_4_ = uVar22;
          auVar5._4_12_ = auVar25;
          auVar5._0_4_ = uVar24;
          bVar9 = FUN_fffffff009cb5a70
                            (auVar21,param_2,auVar20,auVar5,param_5,param_6,param_7,1,uVar15,7,8);
        }
        puVar12 = (undefined1 *)thunk_FUN_fffffff00a39bc88();
        if (local_70 < puVar12) {
          uVar1 = *(uint *)((long)param_7 + 500);
          if ((int)param_7[0x4c7] == 0) {
            if ((uVar1 >> 9 & 1) != 0) {
              if (((uVar1 >> 0x1e & 1) == 0) || (bVar10 = thunk_FUN_fffffff00a394140(), !bVar10)) {
                psVar19 = *(short **)PTR_DAT_fffffff008081388;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar21 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar21,param_2,uVar22,uVar24,param_5,param_6,&MACH_HEADER,psVar19,0,
                           (byte *)
                           "%s@%s: %s::%s: Command Completion interrupt not received on time on endpoint 0x%x\n"
                          );
              }
              else {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0
                          ((byte *)
                           "%s@%s: %s::%s: Command Completion interrupt not received on time on endpoint 0x%x\n"
                          );
              }
            }
          }
          else if ((uVar1 >> 9 & 1) != 0) {
            FUN_fffffff009cacb28
                      ((ulong)param_7,
                       (byte *)
                       "AppleUSBXDCI::%s:Command Completion interrupt not received on time on endpoint 0x%x\n"
                      );
          }
        }
        *(undefined1 *)(lVar18 + 0x1a) = 0xff;
      }
      lVar13 = FUN_fffffff009cc61f4(lVar18);
      param_1 = extraout_q0_01;
      while (lVar13 != 0) {
        FUN_fffffff009caa950(lVar13,(int *)&local_64,(uint *)0x0,&local_65);
        lVar16 = *(long *)(lVar18 + 0x48);
        if (lVar16 == 0) {
          if (((*(int *)(lVar13 + 0x3c) != 0) || (*(long *)(lVar13 + 0x18) == 0)) ||
             ((*(uint *)(*(long *)(lVar13 + 0x18) + 0xc) & 1) != 0)) {
            if ((int)param_7[0x4c7] == 0) {
              if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
                 (bVar10 = thunk_FUN_fffffff00a394140(), bVar10)) {
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                thunk_FUN_fffffff00a9029a0
                          ((byte *)
                           "%s@%s: %s::%s: did not find a pending IORequest for TRB for endpoint 0x%02x\n"
                          );
                auVar21 = extraout_q0_03;
              }
              else {
                psVar19 = *(short **)PTR_DAT_fffffff008081388;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar21 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                auVar21 = thunk_FUN_fffffff00a8df19c
                                    (auVar21,param_2,uVar22,uVar24,param_5,param_6,&MACH_HEADER,
                                     psVar19,0x11,
                                     (byte *)
                                     "%s@%s: %s::%s: did not find a pending IORequest for TRB for endpoint 0x%02x\n"
                                    );
              }
              if (*(int *)((long)param_7 + 500) < 0) {
                auVar2._4_12_ = auVar23;
                auVar2._0_4_ = uVar22;
                auVar6._4_12_ = auVar25;
                auVar6._0_4_ = uVar24;
                FUN_fffffff009cc8774(auVar21,param_2,auVar2,auVar6,param_5,param_6);
                param_1 = extraout_q0_04;
                break;
              }
            }
            else if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
              FUN_fffffff009cacb28
                        ((ulong)param_7,
                         (byte *)
                         "AppleUSBXDCI::%s:did not find a pending IORequest for TRB for endpoint 0x%02x\n"
                        );
            }
          }
        }
        else {
          *(ulong *)(lVar16 + 0x48) = *(long *)(lVar16 + 0x48) + (ulong)local_64;
        }
        FUN_fffffff009cab17c(param_7[0xb6],lVar13);
        if (((local_65 & 1) != 0) && (lVar13 = FUN_fffffff009cc62f8(lVar18), lVar13 != 0)) {
          *(undefined4 *)(lVar13 + 0x28) = param_9;
          FUN_fffffff009cc6394(lVar18,lVar13);
        }
        lVar13 = FUN_fffffff009cc61f4(lVar18);
        param_1 = extraout_q0_02;
      }
    }
    auVar3._4_12_ = auVar23;
    auVar3._0_4_ = uVar22;
    auVar7._4_12_ = auVar25;
    auVar7._0_4_ = uVar24;
    FUN_fffffff009cb5a70(param_1,param_2,auVar3,auVar7,param_5,param_6,param_7,0,0,0,0);
    FUN_fffffff009cbf1ec((long)param_7,uVar15);
    lVar13 = FUN_fffffff009cc62f8(lVar18);
    while (lVar13 != 0) {
      *(undefined4 *)(lVar13 + 0x28) = param_9;
      FUN_fffffff009cc6394(lVar18,lVar13);
      lVar13 = FUN_fffffff009cc62f8(lVar18);
    }
    piVar14 = (int *)FUN_fffffff009cc6428(lVar18);
    auVar21 = extraout_q0_05;
    while (piVar14 != (int *)0x0) {
      FUN_fffffff009cb3fd0(auVar21,param_2,uVar22,uVar24,param_5,param_6,param_7,piVar14);
      piVar14 = (int *)FUN_fffffff009cc6428(lVar18);
      auVar21 = extraout_q0_06;
    }
    if (plVar17 != (long *)0x0) {
      (**(code **)(*plVar17 + 0xb8))(plVar17);
    }
  }
  return;
}

