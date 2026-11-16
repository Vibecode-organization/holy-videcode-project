// FUN_fffffff00997165c @ fffffff00997165c size=5060

/* WARNING: Removing unreachable block (ram,0xfffffff009971db8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099727f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0099719d0) */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_fffffff00997165c(long *param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  long *plVar11;
  long *plVar12;
  long lVar13;
  undefined8 uVar14;
  long *plVar15;
  long *plVar16;
  long *plVar17;
  bool bVar18;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  ulong local_b0;
  ulong local_a8;
  int local_9c;
  int local_98 [12];
  undefined8 local_68;
  
  iVar2 = thunk_EXT_FUN_801100000391a808();
  if (iVar2 == 0) {
    return 0;
  }
  lVar8 = thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0ce8);
  param_1[0x1e] = lVar8;
  if (lVar8 == 0) {
    return 0;
  }
  local_68 = 0;
  uVar9 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)param_1[0x1e] = uVar9;
  uVar9 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1[0x1e] + 8) = uVar9;
  lVar8 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x58] = lVar8;
  if (lVar8 == 0) {
LAB_fffffff009971838:
    (**(code **)(*param_1 + 0x2b8))(param_1,param_2);
    return 0;
  }
  lVar8 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x32] = lVar8;
  if (lVar8 == 0) goto LAB_fffffff009971838;
  param_1[0x33] = 0;
  param_1[0x34] = (long)(param_1 + 0x33);
  *(undefined4 *)((long)param_1 + 0x1b4) = 0x10000000;
  lVar8 = thunk_EXT_FUN_80110000038ff010();
  param_1[0x37] = lVar8;
  if (lVar8 == 0) goto LAB_fffffff009971838;
  uVar9 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1[0x1e] + 0x10) = uVar9;
  (**(code **)(*param_1 + 0xe0))(param_1,"KDebugVersion",0x100000000,0x40);
  uVar9 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1[0x1e] + 0x18) = uVar9;
  iVar2 = thunk_EXT_FUN_8011000003a12d84(0);
  param_1[0x27] = param_2;
  if (param_2 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: provider is not the right device\n");
  }
  else {
    uVar10 = (**(code **)(*param_1 + 0x618))(param_1,param_2);
    if ((uVar10 & 1) == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: configureDevice failed\n");
    }
    else {
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x20) = uVar9;
      plVar11 = (long *)thunk_EXT_FUN_8011000003890f30
                                  (param_1[0x27],*(undefined8 *)PTR_DAT_fffffff007ff2768);
      if (plVar11 == (long *)0x0) {
LAB_fffffff009971904:
        lVar8 = 0;
      }
      else {
        plVar11 = (long *)(**(code **)(*plVar11 + 0x148))(plVar11,"model");
        plVar12 = (long *)thunk_EXT_FUN_8011000003890f30
                                    (plVar11,*(undefined8 *)PTR_DAT_fffffff007ff2798);
        if (plVar12 == (long *)0x0) {
          if (plVar11 == (long *)0x0) goto LAB_fffffff009971904;
          lVar8 = 0;
        }
        else {
          uVar3 = (**(code **)(*plVar12 + 0xa0))();
          if (uVar3 < 0xfff) {
            uVar3 = (**(code **)(*plVar12 + 0xa0))(plVar12);
          }
          else {
            uVar3 = 0xfff;
          }
          lVar13 = thunk_EXT_FUN_80110000038fe580(uVar3 + 1);
          plVar11 = plVar12;
          if (lVar13 == 0) {
            lVar8 = 0;
          }
          else {
            uVar9 = (**(code **)(*plVar12 + 0xd8))(plVar12);
            if (uVar3 == 0xffffffff) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff009972a20);
              (*pcVar1)();
            }
            thunk_EXT_FUN_8011000003a61b10(lVar13,uVar9,uVar3);
            *(undefined1 *)(lVar13 + (ulong)uVar3) = 0;
            lVar8 = thunk_EXT_FUN_80110000038ce200(lVar13);
            thunk_EXT_FUN_80110000038fe6b0(lVar13,uVar3 + 1);
          }
        }
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
      param_1[0x28] = lVar8;
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x28) = uVar9;
      FUN_fffffff00997142c(param_1);
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x30) = uVar9;
      (**(code **)(*param_1 + 0x600))(*param_1 + 0x600,param_1,param_1 + 0x3d);
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x38) = uVar9;
      *(undefined4 *)((long)param_1 + 0x1fc) = 0;
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x40) = uVar9;
      local_98[0xb] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_debug",local_98 + 0xb,4);
      if ((iVar4 != 0) && (local_98[0xb] != 0)) {
        *(uint *)((long)param_1 + 0x1fc) =
             *(uint *)((long)param_1 + 0x1fc) | local_98[0xb] & 0x7f80f1cfU;
      }
      local_98[10] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("wq_stall_panic_seconds",local_98 + 10,4);
      if (iVar4 != 0) {
        *(int *)((long)param_1 + 0x26c) = local_98[10];
      }
      local_98[9] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("wq_timeout_sec",local_98 + 9,4);
      if (iVar4 != 0) {
        iVar4 = local_98[9];
        if (local_98[9] <= local_98[10]) {
          iVar4 = local_98[10];
        }
        iVar6 = local_98[9];
        if (local_98[10] != 0) {
          iVar6 = iVar4;
        }
        *(int *)((long)param_1 + 0x26c) = iVar6;
      }
      local_98[8] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("panic_on_gpu_hang",local_98 + 8,4);
      if ((iVar4 != 0) && (local_98[8] != 0)) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 2;
      }
      local_98[7] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("spin_wait_for_gpu",local_98 + 7,4);
      if ((iVar4 != 0) && (local_98[7] != 0)) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 1;
      }
      local_98[6] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("gpu_no_zero_fill",local_98 + 6,4);
      if ((iVar4 != 0) && (local_98[6] != 0)) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 4;
      }
      local_98[5] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_pagingoff_timeout",local_98 + 5,4);
      if (iVar4 != 0) {
        *(int *)(param_1 + 0x4e) = local_98[5];
      }
      local_98[4] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_panic_on_event_timeout",local_98 + 4,4);
      if (iVar4 != 0) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x8000000;
      }
      local_98[3] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_no_prepare_avoid_throttling",local_98 + 3,4);
      if (iVar4 != 0) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x800000;
      }
      local_98[2] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_no_check_descriptor_size",local_98 + 2,4);
      if (iVar4 != 0) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x10000000;
      }
      local_98[1] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_no_throttled_multi_kick",local_98 + 1,4);
      if (iVar4 != 0) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x20000000;
      }
      local_98[0] = 0;
      iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_no_abort",local_98,4);
      if ((iVar4 != 0) && (local_98[0] != 0)) {
        *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x8000;
      }
      if (iVar2 != 0) {
        local_a8 = local_a8 & 0xffffffff00000000;
        iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_force_mapped_memory",&local_a8,4);
        if (iVar4 != 0) {
          *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x80;
        }
        local_b0 = local_b0 & 0xffffffff00000000;
        iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_disable_restart_limit",&local_b0,4);
        if (iVar4 != 0) {
          *(uint *)((long)param_1 + 0x1fc) = *(uint *)((long)param_1 + 0x1fc) | 0x40000000;
        }
        local_9c = 0;
        iVar4 = thunk_EXT_FUN_8011000003a10b0c("iogpu_event_timeout_secs",&local_9c,4);
        if ((iVar4 != 0) && (local_9c != 0)) {
          *(int *)((long)param_1 + 700) = local_9c;
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s waitForEventTimeoutSeconds = %u\n");
        }
      }
      DAT_fffffff00af227c8 = *(uint *)((long)param_1 + 0x1fc);
      if ((*(byte *)((long)param_1 + 0x1f2) >> 5 & 1) != 0) {
        DAT_fffffff00af227c8 = DAT_fffffff00af227c8 & 0xfffffffb;
        *(uint *)((long)param_1 + 0x1fc) = DAT_fffffff00af227c8;
      }
      if (DAT_fffffff00af227c8 != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "IOGPU:start() [%s: fConfig.debugBits=0x%x]\n");
      }
      uVar9 = thunk_EXT_FUN_8011000003397c88();
      *(undefined8 *)(param_1[0x1e] + 0x48) = uVar9;
      plVar11 = (long *)thunk_EXT_FUN_801100000392f2f0("IOCoreSurfaceRoot",0);
      plVar12 = (long *)thunk_EXT_FUN_801100000392ece0(plVar11,0xffffffffffffffff);
      lVar8 = thunk_EXT_FUN_8011000003890f30(plVar12,*(undefined8 *)PTR_DAT_fffffff007ff2760);
      if (lVar8 == 0) {
        param_1[0x1f] = 0;
        if ((plVar12 != (long *)0x0) &&
           ((**(code **)(*plVar12 + 0x28))(plVar12), param_1[0x1f] != 0)) goto LAB_fffffff009971d58;
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: fail to get IOSurface root\n");
        bVar18 = false;
      }
      else {
        param_1[0x1f] = lVar8;
LAB_fffffff009971d58:
        uVar9 = thunk_EXT_FUN_8011000003397c88();
        *(undefined8 *)(param_1[0x1e] + 0x50) = uVar9;
        thunk_EXT_FUN_8011000002c30760
                  (param_1[0x1f],(int)param_1[0x44],*(undefined4 *)((long)param_1 + 0x224),
                   (int)param_1[0x45],(short)param_1[0x43],*(undefined2 *)((long)param_1 + 0x21a));
        uVar5 = thunk_EXT_FUN_8011000002c3071c(param_1[0x1f],param_1);
        *(undefined4 *)(param_1 + 0x20) = uVar5;
        FUN_fffffff009972a20(param_1);
        FUN_fffffff009972b14();
        lVar8 = (**(code **)(*param_1 + 0x568))(*param_1 + 0x568,param_1);
        param_1[0x29] = lVar8;
        if (lVar8 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: failed to create event machine\n");
          bVar18 = false;
        }
        else {
          lVar8 = FUN_fffffff00994434c();
          param_1[0x3a] = lVar8;
          if (lVar8 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: fGPUTaskList alloc fail\n");
            bVar18 = false;
          }
          else {
            lVar8 = FUN_fffffff00994434c();
            param_1[0x39] = lVar8;
            if (lVar8 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: failed to create fDeviceNamespace\n");
              bVar18 = false;
            }
            else {
              lVar8 = FUN_fffffff00994434c();
              param_1[0x3b] = lVar8;
              if (lVar8 == 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s: failed to create fWorkQueueNamespace\n");
                bVar18 = false;
              }
              else {
                plVar12 = (long *)(**(code **)(*param_1 + 0x660))(param_1);
                param_1[0x2a] = (long)plVar12;
                if ((plVar12 == (long *)0x0) ||
                   (uVar10 = (**(code **)(*plVar12 + 0x78))(plVar12,param_1), (uVar10 & 1) == 0)) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s: statistics object alloc fail\n");
                  bVar18 = false;
                }
                else {
                  uVar9 = thunk_EXT_FUN_8011000003397c88();
                  *(undefined8 *)(param_1[0x1e] + 0x60) = uVar9;
                  plVar12 = (long *)thunk_EXT_FUN_80110000039589e4();
                  param_1[0x12] = (long)plVar12;
                  if (plVar12 == (long *)0x0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: workloop alloc fail\n");
                    bVar18 = false;
                  }
                  else {
                    uVar9 = (**(code **)(*plVar12 + 0x88))();
                    thunk_EXT_FUN_8011000003271c3c(uVar9,"IOGPU Default WorkLoop");
                    lVar8 = FUN_fffffff009950044(param_1);
                    param_1[0x2b] = lVar8;
                    if (lVar8 == 0) {
                      thunk_EXT_FUN_80110000038db19c
                                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                 "%s: IOGPUFenceMachine alloc or init failed\n");
                      bVar18 = false;
                    }
                    else {
                      lVar8 = thunk_EXT_FUN_80110000032770a0(FUN_fffffff009972d28,param_1,1,1);
                      param_1[0x17] = lVar8;
                      lVar8 = thunk_EXT_FUN_80110000038ff010();
                      param_1[0x18] = lVar8;
                      if ((param_1[0x17] == 0) || (lVar8 == 0)) {
                        thunk_EXT_FUN_80110000038db19c
                                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                   "%s: IOGPU event scrubber thread setup failed\n");
                        bVar18 = false;
                      }
                      else {
                        lVar8 = thunk_EXT_FUN_801100000395abd8(param_1,FUN_fffffff009972e28,0,0);
                        param_1[0x16] = lVar8;
                        if (lVar8 != 0) {
                          (**(code **)(*(long *)param_1[0x12] + 0xa0))((long *)param_1[0x12],lVar8);
                          (**(code **)(*(long *)param_1[0x16] + 0xb0))();
                        }
                        lVar8 = (**(code **)(*param_1 + 0x558))(param_1);
                        param_1[0x2c] = lVar8;
                        if (lVar8 == 0) {
                          thunk_EXT_FUN_80110000038db19c
                                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                     "%s: IOGPUScheduler alloc or init failed\n");
                          bVar18 = false;
                        }
                        else {
                          uVar9 = thunk_EXT_FUN_8011000003397c88();
                          *(undefined8 *)(param_1[0x1e] + 0x68) = uVar9;
                          local_a8 = 0;
                          local_68 = 8;
                          iVar4 = thunk_EXT_FUN_8011000003742368
                                            ("hw.memsize_physical",&local_a8,&local_68,0,0);
                          if ((iVar4 == 0) ||
                             (iVar4 = thunk_EXT_FUN_8011000003742368
                                                ("hw.memsize",&local_a8,&local_68,0,0), iVar4 == 0))
                          {
                            iVar4 = 0x2000000;
                          }
                          else {
                            local_a8 = 0x20000000;
                            iVar4 = 0x800000;
                          }
                          plVar12 = (long *)(**(code **)(*param_1 + 0x148))(param_1,"GARTCacheSize")
                          ;
                          uVar9 = *(undefined8 *)PTR_DAT_fffffff007ff27a8;
                          plVar15 = (long *)thunk_EXT_FUN_8011000003890f30(plVar12,uVar9);
                          if (plVar15 == (long *)0x0) {
                            if (plVar12 != (long *)0x0) {
                              (**(code **)(*plVar12 + 0x28))(plVar12);
                            }
                          }
                          else {
                            iVar4 = (**(code **)(*plVar15 + 0xa8))(plVar15);
                          }
                          local_9c = 0;
                          iVar6 = thunk_EXT_FUN_8011000003a10b0c("iogpu_wired_lwm_mb",&local_9c,4);
                          if (iVar6 != 0) {
                            iVar4 = local_9c << 0x14;
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,2,
                                       "IOGPU: Wired low water mark overridden to %d MB");
                            thunk_EXT_FUN_8011000003a132c0
                                      ("IOGPU: Wired low water mark overridden to %d MB\n");
                            DAT_fffffff00af227b8 = local_9c;
                          }
                          local_b0 = 0;
                          local_b4 = 0;
                          if (((iVar2 == 0) ||
                              (iVar6 = thunk_EXT_FUN_8011000003a10b0c("iogpu_sysmem_mb",&local_b0,8)
                              , iVar6 == 0)) || (local_b0 == 0)) {
                            local_b0 = (**(code **)(*param_1 + 0x608))(param_1,local_a8);
                            if (iVar2 != 0) goto LAB_fffffff009972428;
LAB_fffffff00997248c:
                            local_b4 = 0x4b;
                          }
                          else {
                            local_b0 = local_b0 << 0x14;
                            if (local_a8 <= local_b0) {
                              local_b0 = local_a8;
                            }
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s maxSysMemoryWiredSizeAPI override = %llu\n");
LAB_fffffff009972428:
                            iVar6 = thunk_EXT_FUN_8011000003a10b0c
                                              ("iogpu_single_sysmem_pct",&local_b4,4);
                            if ((iVar6 == 0) || (local_b4 == 0)) goto LAB_fffffff00997248c;
                            if (100 < local_b4) {
                              local_b4 = 100;
                            }
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s maxSingleSysMemoryPercent override = %u\n");
                          }
                          *(uint *)((long)param_1 + 0x2ec) = local_b4;
                          param_1[0x23] = local_b0;
                          lVar8 = (**(code **)(*param_1 + 0x610))(param_1,local_a8);
                          param_1[0x24] = lVar8;
                          param_1[0x59] = local_a8;
                          thunk_EXT_FUN_80110000038db19c
                                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                     "%s fMaxSingleSysMemoryPercent = %u fMaxSysMemoryWiredSize[API] = %llu fMaxSingleSysMemory = %llu\n"
                                    );
                          local_b8 = 0;
                          if (((iVar2 == 0) ||
                              (iVar6 = thunk_EXT_FUN_8011000003a10b0c
                                                 ("iogpu_gart_interval_ms",&local_b8,4), iVar6 == 0)
                              ) || (local_b8 == 0)) {
                            local_b8 = 0xfa;
                            plVar16 = (long *)(**(code **)(*param_1 + 0x148))
                                                        (param_1,"GARTReclaimInterval");
                            plVar17 = (long *)thunk_EXT_FUN_8011000003890f30(plVar16,uVar9);
                            plVar12 = plVar16;
                            if (plVar17 != (long *)0x0) {
                              plVar12 = (long *)0x0;
                            }
                            if (plVar15 != (long *)0x0) {
                              (**(code **)(*plVar15 + 0x28))(plVar15);
                            }
                            if (plVar12 != (long *)0x0) {
                              (**(code **)(*plVar16 + 0x28))(plVar16);
                            }
                            if (plVar17 != (long *)0x0) {
                              local_b8 = (**(code **)(*plVar17 + 0xa8))(plVar17);
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: GARTReclaimInterval set to non default value (%d) milisec\n"
                                        );
                            }
                            local_bc = 0;
                            plVar12 = plVar17;
                            if (iVar2 != 0) goto LAB_fffffff00997267c;
LAB_fffffff0099726d0:
                            plVar16 = (long *)(**(code **)(*param_1 + 0x148))
                                                        (param_1,"GARTReclaimTimeout");
                            plVar17 = (long *)thunk_EXT_FUN_8011000003890f30(plVar16,uVar9);
                            plVar15 = plVar16;
                            if (plVar17 != (long *)0x0) {
                              plVar15 = (long *)0x0;
                            }
                            if (plVar12 != (long *)0x0) {
                              (**(code **)(*plVar12 + 0x28))(plVar12);
                            }
                            if (plVar15 != (long *)0x0) {
                              (**(code **)(*plVar16 + 0x28))(plVar16);
                            }
                            if (plVar17 == (long *)0x0) {
                              plVar17 = (long *)0x0;
                              uVar3 = 4;
                            }
                            else {
                              uVar7 = (**(code **)(*plVar17 + 0xa8))(plVar17);
                              uVar3 = 0;
                              if (local_b8 != 0) {
                                uVar3 = uVar7 / local_b8;
                              }
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: GARTReclaimTimeout set to non default value (%d) milisec\n"
                                        );
                            }
                          }
                          else {
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s: GARTReclaimInterval set to non default value (%u) milisec\n"
                                      );
                            plVar17 = plVar15;
LAB_fffffff00997267c:
                            local_bc = 0;
                            iVar2 = thunk_EXT_FUN_8011000003a10b0c
                                              ("iogpu_gart_timeout_ms",&local_bc,4);
                            plVar12 = plVar17;
                            if ((iVar2 == 0) || (local_bc == 0)) goto LAB_fffffff0099726d0;
                            uVar3 = 0;
                            if (local_b8 != 0) {
                              uVar3 = local_bc / local_b8;
                            }
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s: GARTReclaimTimeout set to non default value (%u) milisec\n"
                                      );
                          }
                          FUN_fffffff009961a4c(param_1[0x2c],local_b8,uVar3,iVar4);
                          uVar9 = thunk_EXT_FUN_8011000003397c88();
                          *(undefined8 *)(param_1[0x1e] + 0x70) = uVar9;
                          lVar8 = (**(code **)(*param_1 + 0x628))(*param_1 + 0x628,param_1);
                          param_1[0x1a] = lVar8;
                          if (lVar8 == 0) {
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s: createKernelGPUTask failed\n");
                            bVar18 = false;
                          }
                          else {
                            uVar9 = FUN_fffffff009944798(param_1[0x3a],lVar8);
                            FUN_fffffff0099710dc(param_1[0x1a],uVar9);
                            uVar9 = thunk_EXT_FUN_8011000003397c88();
                            *(undefined8 *)(param_1[0x1e] + 0x78) = uVar9;
                            plVar12 = (long *)thunk_EXT_FUN_80110000039e0958(param_1,0x400,1);
                            param_1[0x21] = (long)plVar12;
                            if (plVar12 == (long *)0x0) {
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: IOPerfControlClient::copyClient failed\n");
                            }
                            else {
                              iVar2 = (**(code **)(*plVar12 + 0x80))(plVar12,param_1,param_1[0x27]);
                              if (iVar2 != 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: IOPerfControlClient::registerDevice failed.\n");
                                (**(code **)(*(long *)param_1[0x21] + 0x28))();
                                param_1[0x21] = 0;
                              }
                            }
                            lVar8 = thunk_EXT_FUN_8011000003a036f0(FUN_fffffff009972f0c,param_1,0);
                            param_1[0x38] = lVar8;
                            if (lVar8 == 0) {
                              *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffffbf;
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: registerPrioritySleepWakeIntererest failed\n");
                              bVar18 = false;
                            }
                            else {
                              *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
                              lVar8 = thunk_EXT_FUN_801100000332d630
                                                ("com.apple.iokit.IOGPUFamily.API",0);
                              param_1[0x5c] = lVar8;
                              if (lVar8 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: API Allocation Name allocation failed\n");
                                bVar18 = false;
                              }
                              else {
                                bVar18 = true;
                              }
                            }
                          }
                          if (plVar17 != (long *)0x0) {
                            (**(code **)(*plVar17 + 0x28))(plVar17);
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (plVar11 != (long *)0x0) {
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
      if (bVar18) {
        uVar9 = 1;
        goto LAB_fffffff00997219c;
      }
    }
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"IOGPU::start: Failure exit\n");
  FUN_fffffff009972f74(param_1,param_2);
  uVar9 = 0;
LAB_fffffff00997219c:
  uVar14 = thunk_EXT_FUN_8011000003397c88();
  *(undefined8 *)(param_1[0x1e] + 0x58) = uVar14;
  return uVar9;
}

