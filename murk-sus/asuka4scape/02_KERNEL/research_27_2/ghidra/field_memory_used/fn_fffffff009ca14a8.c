// FUN_fffffff009ca14a8 @ fffffff009ca14a8

/* WARNING: Removing unreachable block (ram,0xfffffff009ca1e1c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca21e4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca2624) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca27c8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca1ff8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca17b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca18b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca28b4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca2710) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca246c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca2568) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca206c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca1cfc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009ca153c) */

undefined8
FUN_fffffff009ca14a8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long *param_8,
          undefined8 param_9,char *param_10,undefined *param_11)

{
  uint uVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  bool bVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  undefined8 uVar9;
  char *pcVar10;
  long lVar11;
  short *psVar12;
  ulong unaff_x30;
  undefined1 auVar13 [16];
  undefined1 extraout_q0 [16];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  undefined4 uVar16;
  undefined1 auVar17 [12];
  
  uVar16 = param_4._0_4_;
  auVar17 = param_4._4_12_;
  uVar14 = param_3._0_4_;
  auVar15 = param_3._4_12_;
  plVar6 = (long *)(**(code **)(*param_8 + 0x138))(param_8,"USBDeviceCommand");
  lVar11 = *(long *)PTR_PTR_fffffff00807fab0;
  plVar6 = thunk_FUN_fffffff00a894f30(plVar6,lVar11);
  plVar7 = (long *)(**(code **)(*param_8 + 0x138))
                             (*param_8 + 0x138,param_8,"USBDeviceCommandParameter");
  uVar8 = thunk_FUN_fffffff00a725814();
  if (plVar6 == (long *)0x0) {
    if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) & 1) != 0)) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
        psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                   (byte *)"%s@%s: %s::%s: no command provided\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: no command provided\n");
      }
    }
  }
  else {
    if (uVar8 != 0) {
      thunk_FUN_fffffff00a726e04(uVar8);
      thunk_FUN_fffffff00a724838(uVar8);
    }
    uVar8 = (**(code **)(*plVar6 + 0xb8))(plVar6,"SetDeviceConfiguration");
    if (((uVar8 & 1) != 0) ||
       (iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"SetDeviceDescription"), iVar5 != 0)) {
      if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) & 1) != 0)) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
          psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          param_10 = "%s@%s: %s::%s: Got new configuration descriptor from \"%s\"\n";
          param_9 = 0;
          thunk_FUN_fffffff00a8df19c
                    (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                     (byte *)"%s@%s: %s::%s: Got new configuration descriptor from \"%s\"\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)"%s@%s: %s::%s: Got new configuration descriptor from \"%s\"\n");
        }
      }
      plVar6 = thunk_FUN_fffffff00a894f30(plVar7,*(long *)PTR_PTR_fffffff00807fa70);
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        auVar13._4_12_ = auVar15;
        auVar13._0_4_ = uVar14;
        auVar2._4_12_ = auVar17;
        auVar2._0_4_ = uVar16;
        uVar9 = FUN_fffffff009c9f1a8
                          (extraout_q0,param_2,auVar13,auVar2,param_5,param_6,param_7,plVar6,param_9
                           ,param_10,param_11);
        return uVar9;
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009ca1858);
      (*pcVar3)();
    }
    iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"DeviceDestroy");
    if (iVar5 == 0) {
      iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"GoOffAndOnBus");
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"ForceOffBusEnable");
        if (iVar5 == 0) {
          iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"ForceOffBusDisable");
          if (iVar5 == 0) {
            iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"ShowDeviceDebug");
            if (iVar5 == 0) {
              iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"SetDevicePreferredConfiguration");
              if (iVar5 != 0) {
                plVar6 = thunk_FUN_fffffff00a894f30(plVar7,*(long *)PTR_PTR_fffffff00807fa98);
                if (plVar6 != (long *)0x0) {
                  FUN_fffffff009ca8928(plVar6,(long)param_7);
                  return 0;
                }
                return 0xe00002c2;
              }
              iVar5 = (**(code **)(*plVar6 + 0xb8))(plVar6,"SetEnableTestConfig");
              if (iVar5 != 0) {
                plVar6 = thunk_FUN_fffffff00a894f30(plVar7,*(long *)PTR_PTR_fffffff00807fac8);
                *(int *)(param_7 + 0x18) = *(int *)((long)param_7 + 0xc4);
                (**(code **)(*param_7 + 0xe0))
                          (param_7,"TestConfigSpeed",(long)*(int *)((long)param_7 + 0xc4),0x20);
                (**(code **)(*param_7 + 200))(param_7,"EnableTestConfig",plVar6);
                (**(code **)(*param_7 + 0x2a0))(*param_7 + 0x2a0,param_7,0);
                return 0;
              }
              uVar9 = (**(code **)(*param_7 + 0x590))(param_7,plVar6,plVar7);
              if ((int)uVar9 != 0) {
                if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                  return uVar9;
                }
                if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) != 0) &&
                   (bVar4 = thunk_FUN_fffffff00a394140(), bVar4)) {
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  (**(code **)(*param_7 + 0x218))(param_7,0);
                  (**(code **)(*plVar6 + 0xa8))(plVar6);
                  thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: unknown command %s\n");
                  return uVar9;
                }
                psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                auVar13 = (**(code **)(*plVar6 + 0xa8))(plVar6);
                thunk_FUN_fffffff00a8df19c
                          (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                           (byte *)"%s@%s: %s::%s: unknown command %s\n");
                return uVar9;
              }
              return uVar9;
            }
            if (param_7[0x2d] == 0) {
              if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                return 0;
              }
              if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                 (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
                psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                           (byte *)"%s@%s: %s::%s: waiting to get device configuration\n");
                return 0;
              }
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              pcVar10 = "%s@%s: %s::%s: waiting to get device configuration\n";
            }
            else {
              if (param_7[0x30] != 0) {
                plVar6 = thunk_FUN_fffffff00a89ca6c(param_7[0x30]);
                if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
                  if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                     (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
                    psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                    (**(code **)(*param_7 + 0x1e8))(param_7,0);
                    auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                    thunk_FUN_fffffff00a8df19c
                              (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                               (byte *)
                               "%s@%s: %s::%s: waiting for these interface driver(s) to register:\n"
                              );
                  }
                  else {
                    (**(code **)(*param_7 + 0x1e8))(param_7,0);
                    (**(code **)(*param_7 + 0x218))(param_7,0);
                    thunk_FUN_fffffff00a9029a0
                              ((byte *)
                               "%s@%s: %s::%s: waiting for these interface driver(s) to register:\n"
                              );
                  }
                }
                while( true ) {
                  plVar7 = (long *)(**(code **)(*plVar6 + 0x88))(plVar6);
                  plVar7 = thunk_FUN_fffffff00a894f30(plVar7,lVar11);
                  if (plVar7 == (long *)0x0) break;
                  if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
                    if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                       (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
                      psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                      (**(code **)(*param_7 + 0x1e8))(param_7,0);
                      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                      auVar13 = (**(code **)(*plVar7 + 0xa8))(plVar7);
                      thunk_FUN_fffffff00a8df19c
                                (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,
                                 0,(byte *)"%s@%s: %s::%s: %s\n");
                    }
                    else {
                      (**(code **)(*param_7 + 0x1e8))(param_7,0);
                      (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                      (**(code **)(*plVar7 + 0xa8))(plVar7);
                      thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: %s\n");
                    }
                  }
                }
                (**(code **)(*plVar6 + 0x28))(plVar6);
                return 0;
              }
              if ((*(uint *)((long)param_7 + 500) & 1) == 0) {
                return 0;
              }
              if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
                 (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
                psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                (**(code **)(*param_7 + 0x1e8))(param_7,0);
                auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                thunk_FUN_fffffff00a8df19c
                          (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                           (byte *)
                           "%s@%s: %s::%s: base current=%d extra=%d suspend=%d usb state=%d(%s)\n");
                return 0;
              }
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              pcVar10 = "%s@%s: %s::%s: base current=%d extra=%d suspend=%d usb state=%d(%s)\n";
            }
          }
          else {
            iVar5 = (**(code **)(*param_7 + 0x5c0))(param_7);
            uVar1 = *(uint *)((long)param_7 + 500);
            if (iVar5 != -1) {
              if ((uVar1 & 1) != 0) {
                if (((uVar1 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
                  psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
                  param_9 = 0;
                  thunk_FUN_fffffff00a8df19c
                            (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                             (byte *)
                             "%s@%s: %s::%s: no longer forcing device off USB due to \"%s\"\n");
                }
                else {
                  (**(code **)(*param_7 + 0x1e8))(param_7,0);
                  (**(code **)(*param_7 + 0x218))(param_7,0);
                  thunk_FUN_fffffff00a9029a0
                            ((byte *)
                             "%s@%s: %s::%s: no longer forcing device off USB due to \"%s\"\n");
                }
              }
              uVar8 = (**(code **)(*param_7 + 0x718))(param_7);
              thunk_FUN_fffffff00a94d4c8(param_7,uVar8 & 0xffffffff,param_9);
              thunk_FUN_fffffff00a94dbf8(param_7);
              return 0;
            }
            if ((uVar1 & 1) == 0) {
              return 0;
            }
            if (((uVar1 >> 0x1e & 1) == 0) || (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
              psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)
                         "%s@%s: %s::%s: ignoring kIOUSBDeviceCommandForceOffBusDisable from \"%s\" as we are already off bus\n"
                        );
              return 0;
            }
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            pcVar10 = 
            "%s@%s: %s::%s: ignoring kIOUSBDeviceCommandForceOffBusDisable from \"%s\" as we are already off bus\n"
            ;
          }
          thunk_FUN_fffffff00a9029a0((byte *)pcVar10);
        }
        else {
          if ((param_7 != (long *)0x0) && ((*(uint *)((long)param_7 + 500) & 1) != 0)) {
            if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
               (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
              psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)"%s@%s: %s::%s: forcing device off USB due to \"%s\"\n");
            }
            else {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)"%s@%s: %s::%s: forcing device off USB due to \"%s\"\n");
            }
          }
          thunk_FUN_fffffff00a94db58(param_7);
          *(undefined4 *)((long)param_7 + 0x124) = 500;
          (**(code **)(*param_7 + 0x5f0))(param_7,0);
        }
      }
      else {
        iVar5 = (**(code **)(*param_7 + 0x5c0))(param_7);
        if (iVar5 != -1) {
          if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
            if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
               (bVar4 = thunk_FUN_fffffff00a394140(), !bVar4)) {
              psVar12 = *(short **)PTR_DAT_fffffff00807fa80;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar13 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar13,param_2,uVar14,uVar16,param_5,param_6,&MACH_HEADER,psVar12,0,
                         (byte *)
                         "%s@%s: %s::%s: received kIOUSBDeviceCommandGoOffAndOnBus from \"%s\"\n");
            }
            else {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)
                         "%s@%s: %s::%s: received kIOUSBDeviceCommandGoOffAndOnBus from \"%s\"\n");
            }
          }
          (**(code **)(*param_7 + 0x650))(param_7);
        }
      }
      return 0;
    }
    FUN_fffffff009c9ebfc((long)param_7);
  }
  return 0xe0000001;
}

