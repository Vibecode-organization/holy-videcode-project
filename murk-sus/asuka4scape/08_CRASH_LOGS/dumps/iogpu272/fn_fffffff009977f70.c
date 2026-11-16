// FUN_fffffff009977f70 @ fffffff009977f70 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0099792f0) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099790e8) */

void FUN_fffffff009977f70(long *param_1,int *param_2,long param_3)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  undefined4 uVar5;
  ulong *puVar6;
  undefined8 *puVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulong uVar13;
  long lVar14;
  ulong unaff_x30;
  long *plStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  long *plStack_58;
  
  puVar6 = (ulong *)(param_2 + 2);
  iVar2 = *param_2;
  uVar10 = param_3 - (long)puVar6;
  if (iVar2 - 2U < 0x11) {
    switch(iVar2) {
    default:
      if (7 < uVar10) {
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
          thunk_EXT_FUN_80110000038fe968((uint)*puVar6);
          return;
        }
                    /* WARNING: Does not return */
        UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff009978398);
        (*UNRECOVERED_JUMPTABLE)();
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s:kIOGPUKernelCommandDebugSleep: Insufficient bytes (%llu) for sIOGPUKernelCommandDebugSleepArgs (%lu)\n"
                );
      break;
    case 3:
    case 0xb:
    case 0xc:
    case 0xd:
      FUN_fffffff0099616bc(*(undefined8 *)(param_1[0xa6] + 0x160),4);
      if (0xf < uVar10) {
        uVar11 = *(undefined8 *)(param_2 + 4);
        plStack_a0 = (long *)0x0;
        iVar1 = thunk_EXT_FUN_80110000039a3b60
                          (*(undefined8 *)(param_1[0x90] + 0x28),param_2[2],&plStack_a0);
        if ((iVar1 != 0) ||
           (lVar3 = thunk_EXT_FUN_8011000003890f30
                              (plStack_a0,*(undefined8 *)PTR_DAT_fffffff007ff2790), lVar3 == 0)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandSignalSharedEvent: bad event port name: %d obj: %p\n");
          goto LAB_fffffff009978338;
        }
        uVar12 = thunk_EXT_FUN_8011000002c12750();
        if (iVar2 == 0xd) {
          thunk_EXT_FUN_8011000002c12744(uVar12,uVar11);
        }
        else if (iVar2 == 0xc) {
          lVar3 = thunk_EXT_FUN_8011000002c13500();
          if (lVar3 != 0) {
            uVar5 = 0x12;
            goto LAB_fffffff00997833c;
          }
        }
        else {
          plVar9 = (long *)FUN_fffffff00994f734(uVar12,uVar11,param_1[0xa6],param_1);
          if (plVar9 == (long *)0x0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s:kIOGPUKernelCommandSignalSharedEvent: couldn\'t allocate signal object\n"
                      );
            *(undefined4 *)(param_1 + 0xa4) = 8;
          }
          else {
            FUN_fffffff00994c6ac
                      (*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x9b,param_1 + 0x93);
            FUN_fffffff00994c49c(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93,plVar9 + 0xe)
            ;
            FUN_fffffff009950614(*(undefined8 *)(param_1[0xa6] + 0x158),param_1,plVar9);
          }
          lVar14 = param_1[0xaa];
          lVar8 = param_1[0x83];
          thunk_EXT_FUN_8011000002c12750(lVar3);
          uVar12 = thunk_EXT_FUN_8011000002c134f4();
          thunk_EXT_FUN_80110000036da494(0x850900d0,lVar14,lVar8,uVar12,uVar11,0);
          if (plVar9 != (long *)0x0) {
            (**(code **)(*plVar9 + 0x28))(plVar9);
          }
        }
LAB_fffffff009978340:
        if (plStack_a0 == (long *)0x0) {
          return;
        }
        UNRECOVERED_JUMPTABLE = *(code **)(*plStack_a0 + 0x28);
        plVar9 = plStack_a0;
        goto LAB_fffffff009978b34;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s:kIOGPUKernelCommandSignalSharedEvent: Insufficient bytes (%llu) for sIOGPUKernelCommandSignalOrWaitEventArgs (%lu)\n"
                );
      break;
    case 4:
      if (0xf < uVar10) {
        uVar10 = *(ulong *)(param_2 + 4);
        plStack_a0 = (long *)0x0;
        iVar2 = thunk_EXT_FUN_80110000039a3b60
                          (*(undefined8 *)(param_1[0x90] + 0x28),param_2[2],&plStack_a0);
        if ((iVar2 == 0) &&
           (lVar3 = thunk_EXT_FUN_8011000003890f30
                              (plStack_a0,*(undefined8 *)PTR_DAT_fffffff007ff2790), lVar3 != 0)) {
          uVar11 = thunk_EXT_FUN_8011000002c12750();
          uVar13 = FUN_fffffff0099507a4(*(undefined8 *)(param_1[0xa6] + 0x158),param_1,uVar11);
          if ((uVar13 & 1) == 0) {
            *(undefined4 *)(param_1 + 0xa4) = 2;
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "Cmd queue %p sleep port_name %d value: %08llx timed out waiting for prior signals!\n"
                      );
            if ((*(byte *)(param_1[0xa6] + 0x1ff) >> 3 & 1) != 0) {
              thunk_EXT_FUN_8011000003a49114
                        (
                        "\"Timeout SharedEvent: Cmd queue %p sleep port_name %d value: %08llx timed out waiting for prior signals!\" @%s:%d"
                        );
              return;
            }
          }
          uVar13 = thunk_EXT_FUN_8011000002c13500(uVar11);
          if (uVar13 < uVar10) {
            plStack_58 = (long *)0x0;
            iVar2 = param_2[3];
            if (iVar2 == -1) {
              iVar2 = *(int *)(param_1[0xa6] + 700);
            }
            thunk_EXT_FUN_8011000003204ed8(iVar2,1000000000,&plStack_58);
            lVar8 = param_1[0xaa];
            lVar14 = param_1[0x83];
            thunk_EXT_FUN_8011000002c12750(lVar3);
            uVar12 = thunk_EXT_FUN_8011000002c134f4();
            thunk_EXT_FUN_80110000036da494(0x850900d5,lVar8,lVar14,uVar12,uVar10,0);
            uVar13 = thunk_EXT_FUN_8011000002c132ec(uVar11,uVar10,plStack_58);
            if ((uVar13 & 1) == 0) {
              *(undefined4 *)(param_1 + 0xa4) = 2;
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "Cmd queue %p sleep port_name %d value: %08llx timed out!\n");
              if ((*(byte *)(param_1[0xa6] + 0x1ff) >> 3 & 1) != 0) {
                thunk_EXT_FUN_8011000003a49114
                          (
                          "\"Timeout SharedEvent: Cmd queue %p sleep port_name %d value: %08llx timed out!\" @%s:%d"
                          );
                return;
              }
            }
            lVar14 = param_1[0xaa];
            lVar8 = param_1[0x83];
            thunk_EXT_FUN_8011000002c12750(lVar3);
            uVar11 = thunk_EXT_FUN_8011000002c134f4();
            thunk_EXT_FUN_80110000036da494(0x850900d6,lVar14,lVar8,uVar11,uVar10,0);
          }
          goto LAB_fffffff009978340;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandWaitSharedEvent: bad event port name: %d obj: %p\n");
LAB_fffffff009978338:
        uVar5 = 10;
LAB_fffffff00997833c:
        *(undefined4 *)(param_1 + 0xa4) = uVar5;
        goto LAB_fffffff009978340;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s:kIOGPUKernelCommandSignalSharedEvent: Insufficient bytes (%llu) for sIOGPUKernelCommandSignalOrWaitEventArgs (%lu)\n"
                );
      break;
    case 5:
      FUN_fffffff0099616bc(*(undefined8 *)(param_1[0xa6] + 0x160),4);
      if (uVar10 < 0x10) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSignalSharedEvent: Insufficient bytes (%llu) for sIOGPUKernelCommandSignalOrWaitEventArgs (%lu)\n"
                  );
      }
      else {
        uVar11 = *(undefined8 *)(param_2 + 4);
        plVar9 = (long *)FUN_fffffff009965c94(param_1[0x91],param_2[2]);
        if (plVar9 != (long *)0x0) {
          FUN_fffffff00994c6ac(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x9b,param_1 + 0x93)
          ;
          FUN_fffffff00997fef4(plVar9,param_1 + 0x93,uVar11);
          thunk_EXT_FUN_80110000036da494
                    (0x850900c8,param_1[0xaa],param_1[0x83],plVar9[0x51],uVar11,0);
          puVar7 = (undefined8 *)(*plVar9 + 0x28);
          UNRECOVERED_JUMPTABLE = (code *)*puVar7;
          goto LAB_fffffff009979420;
        }
      }
      break;
    case 6:
    case 10:
      if (uVar10 < 0x10) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSignalSharedEvent: Insufficient bytes (%llu) for sIOGPUKernelCommandSignalOrWaitEventArgs (%lu)\n"
                  );
      }
      else {
        iVar1 = param_2[3];
        if (iVar1 == -1) {
          iVar1 = *(int *)(param_1[0xa6] + 700);
        }
        uVar11 = *(undefined8 *)(param_2 + 4);
        plVar9 = (long *)FUN_fffffff009965c94(param_1[0x91],param_2[2]);
        if (plVar9 != (long *)0x0) {
          uStack_78 = 0;
          uStack_80 = 0;
          uStack_68 = 0;
          uStack_70 = 0;
          uStack_98 = 0;
          plStack_a0 = (long *)0x0;
          uStack_88 = 0;
          uStack_90 = 0;
          FUN_fffffff00994af14(&plStack_a0);
          plStack_58 = (long *)0x0;
          thunk_EXT_FUN_8011000003204ed8(iVar1,1000000000,&plStack_58);
          lVar3 = *(long *)(param_1[0xa7] + 0x240);
          uVar10 = FUN_fffffff00997ffc8
                             (plVar9,uVar11,&plStack_a0,plStack_58,param_1[0xaa],param_1[0x83]);
          if ((uVar10 & 1) == 0) {
            do {
              FUN_fffffff0099603a0(param_1[0xa7]);
              lVar8 = param_1[0xa7];
              lVar14 = *(long *)(lVar8 + 0x240);
              if (lVar3 == lVar14) {
LAB_fffffff009978ab0:
                FUN_fffffff0099603ac(lVar8);
                *(undefined4 *)(param_1 + 0xa4) = 2;
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "Timeout MTLEvent: waiting for signal (%llu) for event (%u) to be scheduled\n"
                          );
                if ((*(byte *)(param_1[0xa6] + 0x1ff) >> 3 & 1) != 0) {
                  thunk_EXT_FUN_8011000003a49114
                            (
                            "\"Timeout MTLEvent: waiting for signal (%llu) for event (%u) to be scheduled\" @%s:%d"
                            );
                  return;
                }
                goto LAB_fffffff009978b1c;
              }
              FUN_fffffff009979580(param_1,&plStack_58);
              lVar8 = param_1[0xa7];
              if (plStack_58 == (long *)0x0) goto LAB_fffffff009978ab0;
              FUN_fffffff0099603ac(lVar8);
              thunk_EXT_FUN_8011000003204fe8(plStack_58,&plStack_58);
              iVar1 = FUN_fffffff00997ffc8
                                (plVar9,uVar11,&plStack_a0,plStack_58,param_1[0xaa],param_1[0x83]);
              lVar3 = lVar14;
            } while (iVar1 == 0);
          }
          if (iVar2 == 6) {
            plVar4 = param_1 + 0x9b;
          }
          else {
            plVar4 = (long *)(param_1[0xa3] + 0x70);
          }
          FUN_fffffff00994c6ac(*(undefined8 *)(param_1[0xa6] + 0x148),&plStack_a0,plVar4);
LAB_fffffff009978b1c:
          UNRECOVERED_JUMPTABLE = *(code **)(*plVar9 + 0x28);
LAB_fffffff009978b34:
          (*UNRECOVERED_JUMPTABLE)(plVar9);
          return;
        }
      }
      break;
    case 7:
      goto code_r0xfffffff0099784c0;
    case 8:
      if (uVar10 < 4) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandPurgeResources: Insufficient bytes (%llu) for sIOGPUKernelCommandPurgeResourcesArgs (%lu)\n"
                  );
      }
      else {
        uVar13 = (ulong)(uint)*puVar6;
        if (uVar10 < uVar13 * 4 + 4) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandPurgeResources: Insufficient bytes (%llu) or size overflow for sIOGPUKernelCommandPurgeResourcesArgs (%lu)\n"
                    );
        }
        else {
          if ((uint)*puVar6 == 0) {
            return;
          }
          lVar3 = 0;
          while (plVar9 = (long *)FUN_fffffff009965628(param_1[0x91],param_2[lVar3 + 3]),
                plVar9 != (long *)0x0) {
            lVar8 = FUN_fffffff00995598c();
            if (lVar8 != 0) {
              *(uint *)(lVar8 + 0x10) = *(uint *)(lVar8 + 0x10) & 0xfff7ffff;
            }
            (**(code **)(*plVar9 + 0x28))(plVar9);
            lVar3 = lVar3 + 1;
            uVar13 = uVar13 - 1;
            if (uVar13 == 0) {
              return;
            }
          }
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandPurgeResources: Invalid resourceID %08x\n");
        }
      }
      break;
    case 9:
      if (uVar10 < 8) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSetProtectionOptions: Insufficient bytes (%llu) for sIOGPUKernelCommandSetProtectionOptionsArgs (%lu)\n"
                  );
      }
      else {
        if (*puVar6 < 0x10) {
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0099785d8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)(*param_1 + 0xb8))(param_1,*puVar6,(undefined8 *)(*param_1 + 0xb8));
            return;
          }
                    /* WARNING: Does not return */
          UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0099785d0);
          (*UNRECOVERED_JUMPTABLE)();
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSetProtectionOptions: Unsupported protecton options (%016llx) bytes\n"
                  );
      }
      break;
    case 0xe:
      if (uVar10 < 4) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandResponsibleTaskIDs: Insufficient bytes (%llu) for sIOGPUKernelCommandResponsibleTaskIDArgs (%lu)\n"
                  );
      }
      else {
        uVar13 = (ulong)(uint)*puVar6;
        if (uVar13 * 4 + 4 <= uVar10) {
          if ((uint)*puVar6 == 0) {
            return;
          }
          lVar3 = 0;
          while (uVar10 = FUN_fffffff00994f3b8(param_1[0xa3],param_2[lVar3 + 3]), (uVar10 & 1) != 0)
          {
            lVar3 = lVar3 + 1;
            uVar13 = uVar13 - 1;
            if (uVar13 == 0) {
              return;
            }
          }
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandResponsibleTaskIDs: Submit Fence failed to add PID\n");
          uVar5 = 1;
          goto LAB_fffffff009978ea8;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandResponsibleTaskIDs: Insufficient bytes (%llu) or size overflow for sIOGPUKernelCommandResponsibleTaskIDArgs (%lu)\n"
                  );
      }
      break;
    case 0xf:
      if (uVar10 < 0xa4) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSetResourceGroups: Insufficient bytes (%llu) for sIOGPUKernelCommandSetResourceGroupsArgs (%lu)\n"
                  );
      }
      else if ((uint)*puVar6 < 0x29) {
        uVar10 = FUN_fffffff0099796a4(param_1,(uint)*puVar6,param_2 + 3);
        if ((uVar10 & 1) != 0) {
          return;
        }
      }
      else {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandSetResourceGroups: group count (%u) invalid\n");
      }
      break;
    case 0x10:
      if (uVar10 < 0xc) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandUpdateMappings: Insufficient bytes (%llu) for sIOGPUUpdateMappings (%lu)\n"
                  );
      }
      else {
        uVar13 = (ulong)(uint)param_2[4];
        if ((uVar13 << 4 | 0xc) <= uVar10) {
          iVar2 = param_2[3];
          plVar9 = (long *)FUN_fffffff009965628(param_1[0x91],(uint)*puVar6);
          plVar4 = (long *)FUN_fffffff009965628(param_1[0x91],iVar2);
          if (plVar4 == (long *)0x0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s:kIOGPUKernelCommandUpdateMappings: Invalid destinationResourceID %08x\n")
            ;
            *(undefined4 *)(param_1 + 0xa4) = 10;
          }
          else {
            if (DAT_fffffff00af227d0 == 0) {
              lVar3 = param_1[0xaf];
              if (lVar3 == 0) {
                lVar3 = FUN_fffffff00996f118(param_1[0xa6],param_1,param_1[0x90],param_1[0x91]);
                param_1[0xaf] = lVar3;
                if (lVar3 != 0) goto LAB_fffffff009978f24;
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s:kIOGPUKernelCommandUpdateMappings: Failed to allocated Async Mapping Descriptor \n"
                          );
              }
              else {
LAB_fffffff009978f24:
                if (plVar9 != (long *)0x0) {
                  (**(code **)(*plVar9 + 0x20))(plVar9);
                }
                (**(code **)(*plVar4 + 0x20))(plVar4);
                uVar10 = FUN_fffffff00996f35c(lVar3,0,plVar9,plVar4,uVar13,param_2 + 5);
                if ((uVar10 & 1) != 0) goto LAB_fffffff009979384;
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s:kIOGPUKernelCommandUpdateMappings: Failed to add mapping command to descriptor \n"
                          );
              }
              *(undefined4 *)(param_1 + 0xa4) = 8;
            }
            else {
              FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93);
              if (plVar9 == (long *)0x0) {
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),plVar4[3]);
              }
              else {
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),plVar9[3]);
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),plVar4[3]);
                (**(code **)(*plVar9 + 0x20))(plVar9);
              }
              iVar2 = FUN_fffffff009957a8c(plVar4,plVar9,param_2 + 5,uVar13,0);
              if (iVar2 != 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s:kIOGPUKernelCommandUpdateMappings: Update Mappings Failed\n");
                uVar5 = 8;
                if (iVar2 != -0x1ffffd43) {
                  uVar5 = 10;
                }
                *(undefined4 *)(param_1 + 0xa4) = uVar5;
              }
              (**(code **)(*(long *)param_1[0xa6] + 0x6c0))();
            }
LAB_fffffff009979384:
            (**(code **)(*plVar4 + 0x28))(plVar4);
          }
          if (plVar9 == (long *)0x0) {
            return;
          }
LAB_fffffff009979400:
          puVar7 = (undefined8 *)(*plVar9 + 0x28);
          UNRECOVERED_JUMPTABLE = (code *)*puVar7;
LAB_fffffff009979420:
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009979450. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
            (*UNRECOVERED_JUMPTABLE)(plVar9,puVar7);
            return;
          }
                    /* WARNING: Does not return */
          UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff009979448);
          (*UNRECOVERED_JUMPTABLE)();
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandUpdateMappings: Insufficient bytes (%llu) or size overflow for sIOGPUUpdateMappings (%lu)\n"
                  );
      }
      break;
    case 0x11:
      if (uVar10 < 0xc) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandCopyMappings: Insufficient bytes (%llu) for sIOGPUCopyMappings (%lu)\n"
                  );
      }
      else {
        uVar13 = (ulong)(uint)param_2[4];
        if (uVar10 < (uVar13 << 4 | 0xc)) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandCopyMappings: Insufficient bytes (%llu) or size overflow for sIOGPUUpdateMappings (%lu)\n"
                    );
        }
        else {
          iVar2 = param_2[3];
          plVar9 = (long *)FUN_fffffff009965628(param_1[0x91],param_2[2]);
          if (plVar9 != (long *)0x0) {
            plVar4 = (long *)FUN_fffffff009965628(param_1[0x91],iVar2);
            if (plVar4 == (long *)0x0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s:kIOGPUKernelCommandCopyMappings: Invalid destination resourceID %08x\n"
                        );
              *(undefined4 *)(param_1 + 0xa4) = 10;
            }
            else {
              if (DAT_fffffff00af227d0 == 0) {
                lVar3 = param_1[0xaf];
                if (lVar3 == 0) {
                  lVar3 = FUN_fffffff00996f118(param_1[0xa6],param_1,param_1[0x90],param_1[0x91]);
                  param_1[0xaf] = lVar3;
                  if (lVar3 == 0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s:kIOGPUKernelCommandCopyMappings: Failed to allocated Async Mapping Descriptor \n"
                              );
                    *(undefined4 *)(param_1 + 0xa4) = 8;
                    goto LAB_fffffff0099793e8;
                  }
                }
                (**(code **)(*plVar9 + 0x20))(plVar9);
                (**(code **)(*plVar4 + 0x20))(plVar4);
                uVar10 = FUN_fffffff00996f35c(lVar3,1,plVar9,plVar4,uVar13,param_2 + 5);
                if ((uVar10 & 1) == 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s:kIOGPUKernelCommandCopyMappings: Failed to add mapping command to descriptor \n"
                            );
                  *(undefined4 *)(param_1 + 0xa4) = 8;
                }
              }
              else {
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),param_1 + 0x93);
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),plVar9[3]);
                FUN_fffffff00994b870(*(undefined8 *)(param_1[0xa6] + 0x148),plVar4[3]);
                (**(code **)(*plVar4 + 0x20))(plVar4);
                iVar2 = FUN_fffffff009957f50(plVar9,plVar4,param_2 + 5,uVar13,0);
                if (iVar2 != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s:kIOGPUKernelCommandCopyMappings: Copy Mappings Failed\n");
                  uVar5 = 8;
                  if (iVar2 != -0x1ffffd43) {
                    uVar5 = 10;
                  }
                  *(undefined4 *)(param_1 + 0xa4) = uVar5;
                }
                (**(code **)(*(long *)param_1[0xa6] + 0x6c0))();
              }
LAB_fffffff0099793e8:
              (**(code **)(*plVar4 + 0x28))(plVar4);
            }
            goto LAB_fffffff009979400;
          }
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s:kIOGPUKernelCommandCopyMappings: Invalid source resourceID %08x\n");
        }
      }
      break;
    case 0x12:
      if (DAT_fffffff00af227d0 == 0) {
        if (0xf < uVar10) {
          if (param_1[0xaf] == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s:kIOGPUKernelCommandPostMappingWaitEvent: Async Mapping Descriptor not allocated\n"
                      );
            uVar5 = 7;
            goto LAB_fffffff009978ea8;
          }
          FUN_fffffff00996dc30(param_1[0xaf],param_1[0xa3]);
          uVar11 = *(undefined8 *)(param_2 + 4);
          iVar2 = param_2[3];
          plStack_58 = (long *)0x0;
          iVar1 = thunk_EXT_FUN_80110000039a3b60
                            (*(undefined8 *)(param_1[0x90] + 0x28),param_2[2],&plStack_58);
          if ((iVar1 == 0) &&
             (lVar3 = thunk_EXT_FUN_8011000003890f30
                                (plStack_58,*(undefined8 *)PTR_DAT_fffffff007ff2790), lVar3 != 0)) {
            plVar9 = (long *)thunk_EXT_FUN_8011000002c1275c();
            FUN_fffffff00996f700(param_1[0xaf],plVar9,uVar11);
            uStack_78 = 0;
            uStack_80 = 0;
            uStack_68 = 0;
            uStack_70 = 0;
            uStack_98 = 0;
            plStack_a0 = (long *)0x0;
            uStack_88 = 0;
            uStack_90 = 0;
            FUN_fffffff00994af14(&plStack_a0);
            (**(code **)(*param_1 + 0x138))(*param_1 + 0x138,param_1,&plStack_a0);
            iVar1 = FUN_fffffff00994b9f8(*(undefined8 *)(param_1[0xa6] + 0x148),&plStack_a0);
            if (iVar1 == 0) {
              plVar4 = (long *)FUN_fffffff00994fbc8(param_1[0xaf],param_1[0xa6],param_1);
              if (plVar4 == (long *)0x0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s:kIOGPUKernelCommandPostMappingWaitEvent: Failed to allocated Mapping fence\n"
                          );
                uVar5 = 8;
LAB_fffffff009979484:
                *(undefined4 *)(param_1 + 0xa4) = uVar5;
              }
              else {
                FUN_fffffff00994c49c
                          (*(undefined8 *)(param_1[0xa6] + 0x148),&plStack_a0,plVar4 + 0xe);
                FUN_fffffff009950614(*(undefined8 *)(param_1[0xa6] + 0x158),param_1,plVar4);
                iVar2 = (**(code **)(*param_1 + 0x140))
                                  (*param_1 + 0x140,param_1,plVar9,uVar11,iVar2);
                if (iVar2 != 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s:kIOGPUKernelCommandPostMappingWaitEvent: Failed to schedule post mapping event\n"
                            );
                  uVar5 = 1;
                  goto LAB_fffffff009979484;
                }
              }
              if (DAT_fffffff00af227e8 != 0) {
                uVar12 = *(undefined8 *)(param_1[0xaf] + 0x100);
                lVar3 = param_1[0xaa];
                uVar11 = thunk_EXT_FUN_801100000390ebc0(param_1[0xa6]);
                thunk_EXT_FUN_80110000036da494(0x851801b8,uVar12,lVar3,uVar11,0,0);
              }
              if (plVar4 != (long *)0x0) {
                (**(code **)(*plVar4 + 0x28))(plVar4);
              }
            }
            else {
              FUN_fffffff00996f47c();
            }
          }
          else {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s:kIOGPUKernelCommandPostMappingWaitEvent: Invalid signal event port name: %d obj: %p\n"
                      );
            plVar9 = (long *)0x0;
            *(undefined4 *)(param_1 + 0xa4) = 10;
          }
          if (plStack_58 != (long *)0x0) {
            (**(code **)(*plStack_58 + 0x28))();
          }
          plStack_58 = (long *)0x0;
          if ((long *)param_1[0xaf] != (long *)0x0) {
            (**(code **)(*(long *)param_1[0xaf] + 0x28))();
          }
          param_1[0xaf] = 0;
          if (plVar9 == (long *)0x0) {
            return;
          }
          goto LAB_fffffff009978b1c;
        }
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandPostMappingWaitEvent: Insufficient bytes (%llu) for sIOGPUKernelCommandSignalOrWaitEventArgs (%lu)\n"
                  );
      }
      else {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s:kIOGPUKernelCommandPostMappingWaitEvent: Async Mapping Disabled\n");
      }
    }
  }
  else {
code_r0xfffffff0099784c0:
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Invalid eIOGPUKernelCommands enum (command_id=%u command_size=%llubytes)\n");
  }
  uVar5 = 10;
LAB_fffffff009978ea8:
  *(undefined4 *)(param_1 + 0xa4) = uVar5;
  return;
}

