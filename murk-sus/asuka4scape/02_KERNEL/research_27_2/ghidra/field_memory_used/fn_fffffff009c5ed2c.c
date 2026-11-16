// FUN_fffffff009c5ed2c @ fffffff009c5ed2c

/* WARNING: Removing unreachable block (ram,0xfffffff009c5f754) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c5f520) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c5f714) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c5f7b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c5ee88) */

void FUN_fffffff009c5ed2c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long *param_7)

{
  uint uVar1;
  undefined *puVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  byte *pbVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  uint uVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 auVar21 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined8 local_70;
  uint local_68;
  undefined2 local_64;
  
  plVar7 = thunk_FUN_fffffff00a89a1f4(0);
  local_64 = 0;
  local_68 = 0;
  if (plVar7 == (long *)0x0) {
    FUN_fffffff009c7b3c8(extraout_q0,param_2,param_3,param_4,param_5,param_6);
    return;
  }
  plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"IOEthernetInterface",(long *)0x0);
  if (plVar8 == (long *)0x0) {
    FUN_fffffff009c7b384(extraout_q0_00,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    plVar9 = thunk_FUN_fffffff00a9326e0(plVar8);
    (**(code **)(*plVar8 + 0x28))(plVar8);
    if (plVar9 != (long *)0x0) {
      plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
      if (plVar8 != (long *)0x0) {
        lVar19 = *(long *)PTR_PTR_fffffff00807b5c0;
        lVar20 = *(long *)PTR_PTR_fffffff00807b608;
        do {
          plVar10 = thunk_FUN_fffffff00a894f30(plVar8,lVar19);
          if (plVar10 != (long *)0x0) {
            plVar11 = thunk_FUN_fffffff00a895554(plVar10,(byte *)"IO80211Interface");
            plVar12 = (long *)(**(code **)(*plVar10 + 0x560))(plVar10);
            plVar12 = thunk_FUN_fffffff00a895554(plVar12,(byte *)"AppleThunderboltIPPort");
            plVar13 = (long *)(**(code **)(*plVar10 + 0x560))(*plVar10 + 0x560,plVar10);
            plVar13 = thunk_FUN_fffffff00a895554(plVar13,(byte *)"AppleUSBNCMData");
            if ((plVar13 == (long *)0x0 && plVar12 == (long *)0x0) && plVar11 == (long *)0x0) {
              plVar11 = (long *)(**(code **)(*plVar10 + 0x118))(plVar10,"IOBuiltin");
              plVar11 = thunk_FUN_fffffff00a894f30(plVar11,lVar20);
              if ((plVar11 != (long *)0x0) && (iVar5 = (**(code **)(*plVar11 + 0x88))(), iVar5 != 0)
                 ) {
                pbVar14 = (byte *)(**(code **)(*plVar10 + 0x590))(plVar10);
                uVar6 = (**(code **)(*plVar10 + 0x5c8))(plVar10);
                FUN_fffffff009c60a20(plVar8,pbVar14,uVar6,plVar7);
              }
            }
          }
          plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
        } while (plVar8 != (long *)0x0);
      }
      (**(code **)(*plVar9 + 0x28))(plVar9);
    }
    plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"TSNInterface",(long *)0x0);
    if (plVar8 == (long *)0x0) {
      FUN_fffffff009c7b340(extraout_q0_01,param_2,param_3,param_4,param_5,param_6);
    }
    else {
      plVar9 = thunk_FUN_fffffff00a9326e0(plVar8);
      (**(code **)(*plVar8 + 0x28))(plVar8);
      if (plVar9 != (long *)0x0) {
        plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
        puVar2 = PTR_DAT_fffffff008072c88;
        while (plVar8 != (long *)0x0) {
          plVar10 = thunk_FUN_fffffff00a894f30(plVar8,(long)puVar2);
          if (plVar10 != (long *)0x0) {
            bVar3 = FUN_fffffff009c5ae2c((long)plVar10);
            iVar5 = FUN_fffffff009c5a458((long)plVar10);
            if (iVar5 != 2) {
              iVar5 = FUN_fffffff009c5a458((long)plVar10);
              bVar3 = iVar5 == 1 & bVar3;
            }
            if (bVar3 != 0) {
              plVar11 = (long *)FUN_fffffff009c5a530((long)plVar10);
              pbVar14 = (byte *)(**(code **)(*plVar11 + 0xa8))();
              uVar4 = FUN_fffffff009c5a53c((long)plVar10);
              FUN_fffffff009c60a20(plVar8,pbVar14,(uint)uVar4,plVar7);
            }
          }
          plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
        }
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      iVar5 = (**(code **)(*plVar7 + 0x90))(plVar7);
      if (iVar5 == 0) {
        plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"IOEthernetInterface",(long *)0x0);
        if (plVar8 == (long *)0x0) {
          FUN_fffffff009c7b2fc(extraout_q0_02,param_2,param_3,param_4,param_5,param_6);
          goto LAB_fffffff009c5f9c8;
        }
        plVar9 = thunk_FUN_fffffff00a9326e0(plVar8);
        (**(code **)(*plVar8 + 0x28))(plVar8);
        if (plVar9 != (long *)0x0) {
          plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
          if (plVar8 != (long *)0x0) {
            lVar20 = *(long *)PTR_PTR_fffffff00807b5c0;
            lVar19 = *(long *)PTR_PTR_fffffff00807b608;
            do {
              plVar10 = thunk_FUN_fffffff00a894f30(plVar8,lVar20);
              if ((plVar10 != (long *)0x0) &&
                 (plVar11 = thunk_FUN_fffffff00a895554(plVar10,(byte *)"IO80211Interface"),
                 plVar11 != (long *)0x0)) {
                plVar11 = (long *)(**(code **)(*plVar10 + 0x118))(plVar10,"IOBuiltin");
                plVar11 = thunk_FUN_fffffff00a894f30(plVar11,lVar19);
                if ((plVar11 != (long *)0x0) &&
                   (iVar5 = (**(code **)(*plVar11 + 0x88))(), iVar5 != 0)) {
                  pbVar14 = (byte *)(**(code **)(*plVar10 + 0x590))(plVar10);
                  uVar6 = (**(code **)(*plVar10 + 0x5c8))(plVar10);
                  FUN_fffffff009c60a20(plVar8,pbVar14,uVar6,plVar7);
                }
              }
              plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
            } while (plVar8 != (long *)0x0);
          }
          (**(code **)(*plVar9 + 0x28))(plVar9);
        }
        plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"TSNInterface",(long *)0x0);
        if (plVar8 == (long *)0x0) {
          FUN_fffffff009c7b2b8(extraout_q0_03,param_2,param_3,param_4,param_5,param_6);
          goto LAB_fffffff009c5f9c8;
        }
        plVar9 = thunk_FUN_fffffff00a9326e0(plVar8);
        (**(code **)(*plVar8 + 0x28))(plVar8);
        if (plVar9 != (long *)0x0) {
          plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
          puVar2 = PTR_DAT_fffffff008072c88;
          while (plVar8 != (long *)0x0) {
            plVar10 = thunk_FUN_fffffff00a894f30(plVar8,(long)puVar2);
            if (plVar10 != (long *)0x0) {
              bVar3 = FUN_fffffff009c5ae2c((long)plVar10);
              iVar5 = FUN_fffffff009c5a458((long)plVar10);
              if ((iVar5 == 3) && (bVar3 != 0)) {
                plVar11 = (long *)FUN_fffffff009c5a530((long)plVar10);
                pbVar14 = (byte *)(**(code **)(*plVar11 + 0xa8))();
                uVar4 = FUN_fffffff009c5a53c((long)plVar10);
                FUN_fffffff009c60a20(plVar8,pbVar14,(uint)uVar4,plVar7);
              }
            }
            plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
          }
          (**(code **)(*plVar9 + 0x28))(plVar9);
        }
        iVar5 = (**(code **)(*plVar7 + 0x90))(plVar7);
        if (iVar5 == 0) {
          plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"IOEthernetInterface",(long *)0x0);
          if (plVar8 == (long *)0x0) {
            FUN_fffffff009c7b274(extraout_q0_04,param_2,param_3,param_4,param_5,param_6);
            goto LAB_fffffff009c5f9c8;
          }
          plVar9 = thunk_FUN_fffffff00a9326e0(plVar8);
          (**(code **)(*plVar8 + 0x28))(plVar8);
          if (plVar9 != (long *)0x0) {
            plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
            if (plVar8 != (long *)0x0) {
              lVar19 = *(long *)PTR_PTR_fffffff00807b5c0;
              do {
                plVar10 = thunk_FUN_fffffff00a894f30(plVar8,lVar19);
                if (plVar10 != (long *)0x0) {
                  plVar11 = (long *)(**(code **)(*plVar10 + 0x560))();
                  plVar11 = thunk_FUN_fffffff00a895554(plVar11,(byte *)"AppleThunderboltIPPort");
                  plVar12 = (long *)(**(code **)(*plVar10 + 0x560))(*plVar10 + 0x560,plVar10);
                  plVar12 = thunk_FUN_fffffff00a895554(plVar12,(byte *)"AppleUSBNCMData");
                  if (plVar12 != (long *)0x0) {
                    for (plVar12 = (long *)(**(code **)(*plVar10 + 0x370))(plVar10);
                        plVar12 != (long *)0x0;
                        plVar12 = (long *)(**(code **)(*plVar12 + 0x370))(plVar12)) {
                      plVar13 = thunk_FUN_fffffff00a895554(plVar12,(byte *)"IOBufferCopyController")
                      ;
                      if (plVar13 != (long *)0x0) goto LAB_fffffff009c5f60c;
                    }
                  }
                  if (plVar11 == (long *)0x0) {
                    pbVar14 = (byte *)(**(code **)(*plVar10 + 0x590))(plVar10);
                    uVar6 = (**(code **)(*plVar10 + 0x5c8))(plVar10);
                    FUN_fffffff009c60a20(plVar8,pbVar14,uVar6,plVar7);
                  }
                }
LAB_fffffff009c5f60c:
                plVar8 = (long *)(**(code **)(*plVar9 + 0x88))(plVar9);
              } while (plVar8 != (long *)0x0);
            }
            (**(code **)(*plVar9 + 0x28))(plVar9);
          }
          plVar8 = thunk_FUN_fffffff00a932f4c((byte *)"TSNInterface",(long *)0x0);
          if (plVar8 == (long *)0x0) {
            FUN_fffffff009c7b230(extraout_q0_05,param_2,param_3,param_4,param_5,param_6);
            goto LAB_fffffff009c5f9c8;
          }
          FUN_fffffff009c7b050(plVar8,plVar7);
        }
      }
      iVar5 = (**(code **)(*plVar7 + 0x90))(plVar7);
      if (iVar5 == 0) {
        FUN_fffffff009c7b1ec(extraout_q0_06,param_2,param_3,param_4,param_5,param_6);
      }
      else {
        plVar8 = (long *)(**(code **)(*plVar7 + 0x118))(plVar7,0);
        lVar19 = *(long *)PTR_PTR_fffffff00807b5c0;
        plVar9 = thunk_FUN_fffffff00a894f30(plVar8,lVar19);
        puVar2 = PTR_DAT_fffffff008072c88;
        if (plVar9 == (long *)0x0) {
          plVar9 = thunk_FUN_fffffff00a894f30(plVar8,(long)PTR_DAT_fffffff008072c88);
          if (plVar9 == (long *)0x0) goto LAB_fffffff009c5f9c8;
          plVar8 = thunk_FUN_fffffff00a894f30(plVar8,(long)puVar2);
          lVar19 = (**(code **)(*plVar8 + 0x38))();
          thunk_FUN_fffffff00a895b28(lVar19);
          plVar9 = (long *)FUN_fffffff009c5a530((long)plVar8);
          (**(code **)(*plVar9 + 0xa8))();
          FUN_fffffff009c5a53c((long)plVar8);
          auVar21 = thunk_FUN_fffffff00a8df19c
                              (extraout_q0_08,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff00807b638,0,
                               (byte *)
                               "IOTimeSyncClockManager::Using interface %s %s%u for identifier\n");
          local_70 = (ulong)local_70._6_2_ << 0x30;
          uVar16 = FUN_fffffff009c5ad30
                             (auVar21,param_2,param_3,param_4,param_5,param_6,(long)plVar8,
                              (undefined4 *)&local_70);
          if ((int)uVar16 != 0) {
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_09,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00807b638,0x10,
                       (byte *)"Failed to get MAC Address from interface: %d\n");
            goto LAB_fffffff009c5f9c8;
          }
          local_68 = (uint)local_70;
          local_64 = local_70._4_2_;
        }
        else {
          plVar8 = thunk_FUN_fffffff00a894f30(plVar8,lVar19);
          lVar19 = (**(code **)(*plVar8 + 0x38))();
          thunk_FUN_fffffff00a895b28(lVar19);
          (**(code **)(*plVar8 + 0x590))(*plVar8 + 0x590,plVar8);
          auVar21 = (**(code **)(*plVar8 + 0x5c8))(*plVar8 + 0x5c8,plVar8);
          thunk_FUN_fffffff00a8df19c
                    (auVar21,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00807b638,0,
                     (byte *)"IOTimeSyncClockManager::Using interface %s %s%u for identifier\n");
          plVar9 = (long *)(**(code **)(*plVar8 + 0x118))(*plVar8 + 0x118,plVar8,"IOMACAddress");
          lVar19 = *(long *)PTR_PTR_fffffff00807b5d0;
          plVar9 = thunk_FUN_fffffff00a894f30(plVar9,lVar19);
          if (plVar9 == (long *)0x0) {
            plVar8 = (long *)(**(code **)(*plVar8 + 0x560))(plVar8);
            plVar8 = (long *)(**(code **)(*plVar8 + 0x118))(plVar8,"IOMACAddress");
            plVar9 = thunk_FUN_fffffff00a894f30(plVar8,lVar19);
            if (plVar9 == (long *)0x0) goto LAB_fffffff009c5f9c8;
          }
          uVar6 = (**(code **)(*plVar9 + 0xa0))();
          uVar18 = (ulong)uVar6;
          if (uVar6 < 3) {
            thunk_FUN_fffffff00a8df19c
                      (extraout_q0_07,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                       (short *)PTR_DAT_fffffff00807b638,0x10,
                       (byte *)"MAC address data length length is smaller (%u) than expected (%u)");
          }
          if (5 < uVar18) {
            uVar18 = 6;
          }
          puVar15 = (undefined8 *)(**(code **)(*plVar9 + 0xd8))(plVar9);
          thunk_FUN_fffffff00aa65b10((undefined8 *)&local_68,puVar15,uVar18);
        }
        uVar6 = local_68 >> 8;
        uVar17 = local_68 & 0xff;
        uVar1 = local_68 >> 0x10;
        local_70 = 0xcafecafecafecafe;
        auVar21 = thunk_FUN_fffffff00a36ce24((long)&local_70,8);
        param_7[0x14] =
             (ulong)(uVar17 << 0x10 | (uVar6 & 0xff) << 8 | uVar1 & 0xff) << 0x28 |
             (local_70 & 0xffffff) << 0x10;
        thunk_FUN_fffffff00a8df19c
                  (auVar21,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,
                   (short *)PTR_DAT_fffffff00807b638,0,
                   (byte *)"IOTimeSyncClockManager:: Generated random clockID %llx\n");
        (**(code **)(*param_7 + 0xe0))(param_7,"TimeSyncTimeClockID",param_7[0x14],0x40);
        (**(code **)(*param_7 + 0xe0))
                  (param_7,"TimeSyncTimeCoreAudioClockDomain",(int)param_7[0x15],0x20);
        param_7[0x16] = param_7[0x14] | 0x100000000000000;
        *(undefined2 *)(param_7 + 0x17) = 0;
        *(undefined1 *)((long)param_7 + 0xbb) = 1;
      }
    }
  }
LAB_fffffff009c5f9c8:
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return;
}

