// FUN_fffffff009cd4ae0 @ fffffff009cd4ae0

/* WARNING: Removing unreachable block (ram,0xfffffff009cd582c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd5b50) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd5704) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4dac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd58e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd535c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd50d8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4f78) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4bb0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4c18) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4c80) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd566c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd54ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd5c08) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd5a98) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd5414) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cd4b40) */

undefined8
FUN_fffffff009cd4ae0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long *param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  bool bVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  char *pcVar11;
  short *psVar12;
  long lVar13;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 auVar14 [16];
  undefined1 extraout_q0_01 [16];
  undefined4 uVar15;
  undefined1 auVar16 [12];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  
  uVar17 = param_4._0_4_;
  auVar18 = param_4._4_12_;
  uVar15 = param_3._0_4_;
  auVar16 = param_3._4_12_;
  thunk_FUN_fffffff00aa14b0c((byte *)"usbdrd-disablepmcbwr",(uint *)((long)param_7 + 0x2784),1);
  plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,2,0);
  param_7[0x89] = (long)plVar7;
  if (plVar7 == (long *)0x0) {
    if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
       (bVar6 = thunk_FUN_fffffff00a394140(), bVar6)) {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: creating _registerMap failed\n");
      auVar14 = extraout_q0;
    }
    else {
      psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar14 = thunk_FUN_fffffff00a8df19c
                          (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0x11,
                           (byte *)"%s@%s: %s::%s: creating _registerMap failed\n");
    }
    if (-1 < *(int *)((long)param_7 + 500)) {
      return 0;
    }
    auVar1._4_12_ = auVar16;
    auVar1._0_4_ = uVar15;
    auVar3._4_12_ = auVar18;
    auVar3._0_4_ = uVar17;
    FUN_fffffff009d14f78(auVar14,param_2,auVar1,auVar3,param_5,param_6);
LAB_fffffff009cd4fd8:
    if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
       (bVar6 = thunk_FUN_fffffff00a394140(), bVar6)) {
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: creating _configRegistersMap failed\n");
      auVar14 = extraout_q0_00;
    }
    else {
      psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar14 = thunk_FUN_fffffff00a8df19c
                          (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0x11,
                           (byte *)"%s@%s: %s::%s: creating _configRegistersMap failed\n");
    }
    if (-1 < *(int *)((long)param_7 + 500)) {
      return 0;
    }
    auVar2._4_12_ = auVar16;
    auVar2._0_4_ = uVar15;
    auVar4._4_12_ = auVar18;
    auVar4._0_4_ = uVar17;
    FUN_fffffff009d14f54(auVar14,param_2,auVar2,auVar4,param_5,param_6);
  }
  else {
    lVar8 = (**(code **)(*plVar7 + 0x78))();
    param_7[0x8a] = lVar8;
    plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,1,0);
    param_7[0x4e2] = (long)plVar7;
    if (plVar7 == (long *)0x0) goto LAB_fffffff009cd4fd8;
    lVar8 = (**(code **)(*plVar7 + 0x78))();
    param_7[0x4e3] = lVar8;
    plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,3,0);
    param_7[0x4e4] = (long)plVar7;
    if (plVar7 != (long *)0x0) {
      lVar8 = (**(code **)(*plVar7 + 0x78))();
      param_7[0x4e5] = lVar8;
      plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,4,0);
      param_7[0x4e6] = (long)plVar7;
      if (plVar7 == (long *)0x0) {
        if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
          return 0;
        }
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
          psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                     (byte *)"%s@%s: %s::%s: creating _coreEvtRegistersMap failed\n");
          return 0;
        }
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        pcVar11 = "%s@%s: %s::%s: creating _coreEvtRegistersMap failed\n";
      }
      else {
        lVar8 = (**(code **)(*plVar7 + 0x78))();
        param_7[0x4e7] = lVar8;
        if ((*(byte *)((long)param_7 + 0x2784) & 1) == 0) {
          plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(param_8,9,0);
          param_7[0x4e8] = (long)plVar7;
          if (plVar7 == (long *)0x0) {
            if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
              return 0;
            }
            if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
               (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
              psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)"%s@%s: %s::%s: creating _pmcBWRAUSBCRegistersMap failed\n");
              return 0;
            }
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            pcVar11 = "%s@%s: %s::%s: creating _pmcBWRAUSBCRegistersMap failed\n";
            goto LAB_fffffff009cd5a1c;
          }
          lVar8 = (**(code **)(*plVar7 + 0x78))();
          param_7[0x4e9] = lVar8;
        }
        uVar9 = (*(code *)PTR_FUN_fffffff0080870e0)(param_7,param_8);
        if ((uVar9 & 1) == 0) {
          if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
            return 0;
          }
          if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
             (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
            psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                       (byte *)"%s@%s: %s::%s: super::start() failed\n");
            return 0;
          }
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar11 = "%s@%s: %s::%s: super::start() failed\n";
        }
        else {
          lVar8 = (**(code **)(*(long *)param_7[0x17] + 0x118))
                            ((long *)param_7[0x17],"usb-device-slp-ddr");
          lVar13 = **(long **)PTR_PTR_fffffff008089d58;
          plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,10,0);
          param_7[0x4ea] = (long)plVar7;
          if ((plVar7 == (long *)0x0) && (lVar8 == lVar13)) {
            if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
              return 0;
            }
            if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
               (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
              psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)"%s@%s: %s::%s: creating _ausbintr2axiRegsMap failed\n");
              return 0;
            }
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            pcVar11 = "%s@%s: %s::%s: creating _ausbintr2axiRegsMap failed\n";
          }
          else {
            lVar10 = (**(code **)(*plVar7 + 0x78))();
            param_7[0x4eb] = lVar10;
            plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,0xb,0);
            param_7[0x4ec] = (long)plVar7;
            if ((plVar7 == (long *)0x0) && (lVar8 == lVar13)) {
              if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                return 0;
              }
              if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                 (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
                psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                           (byte *)"%s@%s: %s::%s: creating _atcusbClkCfgRegMap failed\n");
                return 0;
              }
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              pcVar11 = "%s@%s: %s::%s: creating _atcusbClkCfgRegMap failed\n";
            }
            else {
              lVar10 = (**(code **)(*plVar7 + 0x78))();
              param_7[0x4ed] = lVar10;
              plVar7 = (long *)(**(code **)(*param_8 + 0x3d0))(*param_8 + 0x3d0,param_8,0xc,0);
              param_7[0x4ee] = (long)plVar7;
              if ((plVar7 == (long *)0x0) && (lVar8 == lVar13)) {
                if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                  return 0;
                }
                if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                   (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
                  psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                  thunk_FUN_fffffff00a8df19c
                            (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                             (byte *)"%s@%s: %s::%s: creating _atcusbPipeClkCfgRegMap failed\n");
                  return 0;
                }
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                pcVar11 = "%s@%s: %s::%s: creating _atcusbPipeClkCfgRegMap failed\n";
              }
              else {
                lVar10 = (**(code **)(*plVar7 + 0x78))();
                param_7[0x4ef] = lVar10;
                auVar14._4_12_ = auVar16;
                auVar14._0_4_ = uVar15;
                auVar5._4_12_ = auVar18;
                auVar5._0_4_ = uVar17;
                lVar10 = thunk_FUN_fffffff008305b0c
                                   (extraout_q0_01,param_2,auVar14,auVar5,param_5,param_6,param_8,
                                    (byte *)"function-vote_force_wakeup_dram");
                param_7[0x4f1] = lVar10;
                if (lVar10 != 0) {
                  return 1;
                }
                if (lVar8 != lVar13) {
                  return 1;
                }
                if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                  return 0;
                }
                if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                   (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
                  psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                  thunk_FUN_fffffff00a8df19c
                            (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
                             (byte *)"%s@%s: %s::%s: function-vote_force_wakeup_dram not found\n");
                  return 0;
                }
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(param_7,0);
                pcVar11 = "%s@%s: %s::%s: function-vote_force_wakeup_dram not found\n";
              }
            }
          }
        }
      }
      goto LAB_fffffff009cd5a1c;
    }
  }
  if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
    return 0;
  }
  if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
     (bVar6 = thunk_FUN_fffffff00a394140(), !bVar6)) {
    psVar12 = *(short **)PTR_DAT_fffffff008089cb8;
    (**(code **)(*param_7 + 0x1e8))(param_7,0);
    auVar14 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
    thunk_FUN_fffffff00a8df19c
              (auVar14,param_2,uVar15,uVar17,param_5,param_6,&MACH_HEADER,psVar12,0,
               (byte *)"%s@%s: %s::%s: creating _pipeHandlerRegistersMap failed\n");
    return 0;
  }
  (**(code **)(*param_7 + 0x1e8))(param_7,0);
  (**(code **)(*param_7 + 0x218))(param_7,0);
  pcVar11 = "%s@%s: %s::%s: creating _pipeHandlerRegistersMap failed\n";
LAB_fffffff009cd5a1c:
  thunk_FUN_fffffff00a9029a0((byte *)pcVar11);
  return 0;
}

