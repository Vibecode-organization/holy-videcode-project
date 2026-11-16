// FUN_fffffff009cd92dc @ fffffff009cd92dc

/* WARNING: Removing unreachable block (ram,0xfffffff009cdb010) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdae5c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdaca8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdaaf4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda83c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda8e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda748) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda578) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda24c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda060) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9e70) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9c84) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9abc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9914) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd988c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd96dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9534) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd94a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd94f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd963c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd97e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd98d4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9a1c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9bc4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9dd8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd9fc4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda1b4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda3a0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda700) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda658) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda92c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cda9ec) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdaba0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdad54) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdaf08) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdb0ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd93fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cdb0e4) */

void FUN_fffffff009cd92dc
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  bool bVar9;
  byte bVar10;
  uint uVar11;
  byte extraout_var;
  byte extraout_var_00;
  ulong uVar12;
  undefined1 *puVar13;
  long *extraout_x0;
  long lVar14;
  short *psVar15;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 auVar16 [16];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  undefined1 *local_48;
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) >> 4 & 1) != 0)) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)"%s@%s: %s::%s: system sleep\n");
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: system sleep\n");
    }
  }
  (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x1c);
  *(byte *)(param_7 + 0x4f0) = extraout_var & 0x7f;
  bVar10 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x1c);
  *(byte *)((long)param_7 + 0x2781) = bVar10 & 0x7f;
  lVar14 = param_7[0x4e3];
  uVar11 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,lVar14,0x1c);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar14,0x1c,uVar11 & 0xff80ffff);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
  }
  lVar14 = param_7[0x4e3];
  uVar11 = (**(code **)(*param_7 + 0x818))(param_7,lVar14,0x1c);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar14,0x1c,uVar11 & 0xffffff80);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
  }
  (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x18);
  *(byte *)((long)param_7 + 0x2782) = extraout_var_00 & 0x7f;
  bVar10 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x18);
  *(byte *)((long)param_7 + 0x2783) = bVar10 & 0x7f;
  lVar14 = param_7[0x4e3];
  uVar11 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,lVar14,0x18);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar14,0x18,uVar11 & 0xff80ffff);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
  }
  lVar14 = param_7[0x4e3];
  uVar11 = (**(code **)(*param_7 + 0x818))(param_7,lVar14,0x18);
  (**(code **)(*param_7 + 0x820))(*param_7 + 0x820,param_7,lVar14,0x18,uVar11 & 0xffffff80);
  if ((*(uint *)((long)param_7 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
  }
  (**(code **)(*(long *)param_7[0x4d0] + 0xa0))((long *)param_7[0x4d0],1);
  local_48 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_FUN_fffffff00a208ed8(200,1000000,(long *)&local_48);
  uVar12 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x1c);
  while ((uVar12 & 0x7f000000) != 0) {
    puVar13 = (undefined1 *)thunk_FUN_fffffff00a39bc88();
    if (local_48 <= puVar13) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar9 = thunk_FUN_fffffff00a394140(), bVar9)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: timed out waiting for BULKTHROTTLE_CTL.BULKTHROTTLE_OUTSTANDING_RD = 0x%x\n"
                  );
        auVar16 = extraout_q0;
      }
      else {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar16 = thunk_FUN_fffffff00a8df19c
                            (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0x11
                             ,(byte *)
                              "%s@%s: %s::%s: timed out waiting for BULKTHROTTLE_CTL.BULKTHROTTLE_OUTSTANDING_RD = 0x%x\n"
                            );
      }
      if (*(int *)((long)param_7 + 500) < 0) {
        auVar1._4_12_ = auVar18;
        auVar1._0_4_ = uVar17;
        auVar5._4_12_ = auVar20;
        auVar5._0_4_ = uVar19;
        FUN_fffffff009d14f9c(auVar16,param_2,auVar1,auVar5,param_5,param_6);
        auVar16 = extraout_q0_03;
        goto LAB_fffffff009cda448;
      }
      break;
    }
    thunk_FUN_fffffff00a208cfc(1,1000000);
    uVar12 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x1c);
  }
  local_48 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_FUN_fffffff00a208ed8(200,1000000,(long *)&local_48);
  uVar12 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x1c);
  while ((uVar12 & 0x7f00) != 0) {
    puVar13 = (undefined1 *)thunk_FUN_fffffff00a39bc88();
    if (local_48 <= puVar13) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar9 = thunk_FUN_fffffff00a394140(), bVar9)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: timed out waiting for BULKTHROTTLE_CTL.BULKTHROTTLE_OUTSTANDING_WR = 0x%x\n"
                  );
        auVar16 = extraout_q0_00;
      }
      else {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar16 = thunk_FUN_fffffff00a8df19c
                            (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0x11
                             ,(byte *)
                              "%s@%s: %s::%s: timed out waiting for BULKTHROTTLE_CTL.BULKTHROTTLE_OUTSTANDING_WR = 0x%x\n"
                            );
      }
      if (*(int *)((long)param_7 + 500) < 0) goto LAB_fffffff009cda448;
      break;
    }
    thunk_FUN_fffffff00a208cfc(1,1000000);
    uVar12 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x1c);
  }
  local_48 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_FUN_fffffff00a208ed8(200,1000000,(long *)&local_48);
  uVar12 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x18);
  while ((uVar12 & 0x7f000000) != 0) {
    puVar13 = (undefined1 *)thunk_FUN_fffffff00a39bc88();
    if (local_48 <= puVar13) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar9 = thunk_FUN_fffffff00a394140(), bVar9)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: timed out waiting for LLTTHROTTLE_CTL.LLTTHROTTLE_OUTSTANDING_RD = 0x%x\n"
                  );
        auVar16 = extraout_q0_01;
      }
      else {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar16 = thunk_FUN_fffffff00a8df19c
                            (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0x11
                             ,(byte *)
                              "%s@%s: %s::%s: timed out waiting for LLTTHROTTLE_CTL.LLTTHROTTLE_OUTSTANDING_RD = 0x%x\n"
                            );
      }
      if (*(int *)((long)param_7 + 500) < 0) goto LAB_fffffff009cda44c;
      break;
    }
    thunk_FUN_fffffff00a208cfc(1,1000000);
    uVar12 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x18);
  }
  local_48 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_FUN_fffffff00a208ed8(200,1000000,(long *)&local_48);
  uVar12 = (**(code **)(*param_7 + 0x818))(*param_7 + 0x818,param_7,param_7[0x4e3],0x18);
  do {
    if ((uVar12 & 0x7f00) == 0) {
LAB_fffffff009cda400:
      (**(code **)(*param_7 + 0x820))(param_7,param_7[0x4eb],0,0xffffffff);
      return;
    }
    puVar13 = (undefined1 *)thunk_FUN_fffffff00a39bc88();
    if (local_48 <= puVar13) {
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar9 = thunk_FUN_fffffff00a394140(), bVar9)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)
                   "%s@%s: %s::%s: timed out waiting for LLTTHROTTLE_CTL.LLTTHROTTLE_OUTSTANDING_WR = 0x%x\n"
                  );
        auVar16 = extraout_q0_02;
      }
      else {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar16 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar16 = thunk_FUN_fffffff00a8df19c
                            (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0x11
                             ,(byte *)
                              "%s@%s: %s::%s: timed out waiting for LLTTHROTTLE_CTL.LLTTHROTTLE_OUTSTANDING_WR = 0x%x\n"
                            );
      }
      if (*(int *)((long)param_7 + 500) < 0) goto LAB_fffffff009cda450;
      goto LAB_fffffff009cda400;
    }
    thunk_FUN_fffffff00a208cfc(1,1000000);
    uVar12 = (**(code **)(*param_7 + 0x818))(param_7,param_7[0x4e3],0x18);
  } while( true );
LAB_fffffff009cda448:
  auVar2._4_12_ = auVar18;
  auVar2._0_4_ = uVar17;
  auVar6._4_12_ = auVar20;
  auVar6._0_4_ = uVar19;
  FUN_fffffff009d14fc0(auVar16,param_2,auVar2,auVar6,param_5,param_6);
  auVar16 = extraout_q0_04;
LAB_fffffff009cda44c:
  auVar3._4_12_ = auVar18;
  auVar3._0_4_ = uVar17;
  auVar7._4_12_ = auVar20;
  auVar7._0_4_ = uVar19;
  FUN_fffffff009d14fe4(auVar16,param_2,auVar3,auVar7,param_5,param_6);
  auVar16 = extraout_q0_05;
LAB_fffffff009cda450:
  auVar4._4_12_ = auVar18;
  auVar4._0_4_ = uVar17;
  auVar8._4_12_ = auVar20;
  auVar8._0_4_ = uVar19;
  FUN_fffffff009d15008(auVar16,param_2,auVar4,auVar8,param_5,param_6);
  if (extraout_x0 != (long *)0x0) {
    if ((*(uint *)((long)extraout_x0 + 500) >> 4 & 1) != 0) {
      if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
         (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        auVar16 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                   (byte *)"%s@%s: %s::%s: system wake\n");
      }
      else {
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: system wake\n");
      }
    }
    if ((*(uint *)((long)extraout_x0 + 500) >> 4 & 1) != 0) {
      if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
         (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
        auVar16 = (**(code **)(*extraout_x0 + 0x838))
                            (*extraout_x0 + 0x838,extraout_x0,extraout_x0[0x4ed],0);
        thunk_FUN_fffffff00a8df19c
                  (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                   (byte *)"%s@%s: %s::%s: _atcusbClkCfgRegister 0x%lx\n");
      }
      else {
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x838))(*extraout_x0 + 0x838,extraout_x0,extraout_x0[0x4ed],0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: _atcusbClkCfgRegister 0x%lx\n");
      }
    }
    if ((*(uint *)((long)extraout_x0 + 500) >> 4 & 1) != 0) {
      if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
         (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
        psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
        auVar16 = (**(code **)(*extraout_x0 + 0x838))
                            (*extraout_x0 + 0x838,extraout_x0,extraout_x0[0x4ef],0);
        thunk_FUN_fffffff00a8df19c
                  (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                   (byte *)"%s@%s: %s::%s: _atcusbPipeClkCfgRegister 0x%lx\n");
      }
      else {
        (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
        (**(code **)(*extraout_x0 + 0x838))(*extraout_x0 + 0x838,extraout_x0,extraout_x0[0x4ef],0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: _atcusbPipeClkCfgRegister 0x%lx\n");
      }
    }
  }
  lVar14 = extraout_x0[0x4e3];
  uVar11 = (**(code **)(*extraout_x0 + 0x818))(extraout_x0,lVar14,0x1c);
  (**(code **)(*extraout_x0 + 0x820))
            (*extraout_x0 + 0x820,extraout_x0,lVar14,0x1c,
             uVar11 & 0xff800000 | uVar11 & 0xffff | (*(byte *)(extraout_x0 + 0x4f0) & 0x7f) << 0x10
            );
  if ((*(uint *)((long)extraout_x0 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      auVar16 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
  }
  lVar14 = extraout_x0[0x4e3];
  uVar11 = (**(code **)(*extraout_x0 + 0x818))(extraout_x0,lVar14,0x1c);
  (**(code **)(*extraout_x0 + 0x820))
            (*extraout_x0 + 0x820,extraout_x0,lVar14,0x1c,
             uVar11 & 0xffffff80 | *(byte *)((long)extraout_x0 + 0x2781) & 0x7f);
  if ((*(uint *)((long)extraout_x0 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      auVar16 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_BULKTHROTTLE_CTL.BULKTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
  }
  lVar14 = extraout_x0[0x4e3];
  uVar11 = (**(code **)(*extraout_x0 + 0x818))(extraout_x0,lVar14,0x18);
  (**(code **)(*extraout_x0 + 0x820))
            (*extraout_x0 + 0x820,extraout_x0,lVar14,0x18,
             uVar11 & 0xff800000 |
             uVar11 & 0xffff | (*(byte *)((long)extraout_x0 + 0x2782) & 0x7f) << 0x10);
  if ((*(uint *)((long)extraout_x0 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      auVar16 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_RD_LIMIT = 0x%x\n"
                );
    }
  }
  lVar14 = extraout_x0[0x4e3];
  uVar11 = (**(code **)(*extraout_x0 + 0x818))(extraout_x0,lVar14,0x18);
  (**(code **)(*extraout_x0 + 0x820))
            (*extraout_x0 + 0x820,extraout_x0,lVar14,0x18,
             uVar11 & 0xffffff80 | *(byte *)((long)extraout_x0 + 0x2783) & 0x7f);
  if ((*(uint *)((long)extraout_x0 + 500) >> 2 & 1) != 0) {
    if (((*(uint *)((long)extraout_x0 + 500) >> 0x1e & 1) == 0) ||
       (bVar9 = thunk_FUN_fffffff00a394140(), !bVar9)) {
      psVar15 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      auVar16 = (**(code **)(*extraout_x0 + 0x218))(*extraout_x0 + 0x218,extraout_x0,0);
      thunk_FUN_fffffff00a8df19c
                (auVar16,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,psVar15,0,
                 (byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
    else {
      (**(code **)(*extraout_x0 + 0x1e8))(extraout_x0,0);
      (**(code **)(*extraout_x0 + 0x218))(extraout_x0,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: ATC_USB31DRD_CFG_BLK_LLTTHROTTLE_CTL.LLTTHROTTLE_WR_LIMIT = 0x%x\n"
                );
    }
  }
  (**(code **)(*(long *)extraout_x0[0x4d0] + 0xa0))((long *)extraout_x0[0x4d0],2);
                    /* WARNING: Could not recover jumptable at 0xfffffff009cdb0f0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*extraout_x0 + 0x820))(extraout_x0,extraout_x0[0x4eb],0,0,*extraout_x0 + 0x820);
  return;
}

