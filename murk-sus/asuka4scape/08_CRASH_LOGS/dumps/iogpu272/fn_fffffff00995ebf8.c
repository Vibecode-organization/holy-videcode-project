// FUN_fffffff00995ebf8 @ fffffff00995ebf8 size=2336

undefined8 FUN_fffffff00995ebf8(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  undefined *local_48;
  undefined8 local_40;
  code *local_38;
  undefined *local_30;
  long lStack_28;
  
  uVar2 = (**(code **)(PTR_DAT_fffffff007ff27f8 + 0x78))();
  if ((int)uVar2 != 0) {
    uVar2 = *(undefined8 *)(param_2 + 0x148);
    *(long *)(param_1 + 0x1a8) = param_2;
    *(undefined8 *)(param_1 + 0x1b0) = uVar2;
    FUN_fffffff00997d844(param_1 + 0x1b8,param_2);
    *(undefined1 *)(param_1 + 0x191) = 1;
    *(undefined8 *)(param_1 + 0x130) = 0;
    *(long *)(param_1 + 0x138) = param_1 + 0x130;
    *(undefined8 *)(param_1 + 0x140) = 0;
    *(long *)(param_1 + 0x148) = param_1 + 0x140;
    *(undefined8 *)(param_1 + 0x168) = 0;
    *(long *)(param_1 + 0x170) = param_1 + 0x168;
    lVar3 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x150) = lVar3;
    if (lVar3 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: scheduler lock alloc failure\n");
      uVar2 = 0;
    }
    else {
      lVar3 = thunk_EXT_FUN_80110000038ff010();
      *(long *)(param_1 + 0x160) = lVar3;
      if (lVar3 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: busy lock alloc failure\n");
        uVar2 = 0;
      }
      else {
        plVar4 = (long *)thunk_EXT_FUN_80110000039589e4();
        *(long **)(param_1 + 0x10) = plVar4;
        if (plVar4 == (long *)0x0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: workloop alloc fail\n");
          uVar2 = 0;
        }
        else {
          uVar2 = (**(code **)(*plVar4 + 0x88))();
          thunk_EXT_FUN_8011000003271c3c(uVar2,"IOGPU Submission");
          lVar3 = thunk_EXT_FUN_801100000395c074(param_1,0);
          *(long *)(param_1 + 0x28) = lVar3;
          if (lVar3 == 0) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: submission gate alloc failure\n");
            uVar2 = 0;
          }
          else {
            (**(code **)(**(long **)(param_1 + 0x10) + 0xa0))(*(long **)(param_1 + 0x10),lVar3);
            local_48 = PTR_DAT_fffffff007ff2748;
            local_40 = DAT_fffffff007835cd0;
            local_38 = FUN_fffffff00995f518;
            local_30 = &DAT_fffffff007fecf40;
            lStack_28 = param_1;
            lVar3 = thunk_EXT_FUN_8011000003961134(&local_30,1,param_1,&local_48);
            *(long *)(param_1 + 0x38) = lVar3;
            if (lVar3 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: fSubmissionTimer alloc fail\n");
              uVar2 = 0;
            }
            else {
              (**(code **)(**(long **)(param_1 + 0x10) + 0xa0))(*(long **)(param_1 + 0x10),lVar3);
              (**(code **)(**(long **)(param_1 + 0x38) + 0xb0))();
              plVar4 = (long *)thunk_EXT_FUN_80110000039589e4();
              *(long **)(param_1 + 0x18) = plVar4;
              if (plVar4 == (long *)0x0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: workloop alloc fail\n");
                uVar2 = 0;
              }
              else {
                uVar2 = (**(code **)(*plVar4 + 0x88))();
                thunk_EXT_FUN_8011000003271c3c(uVar2,"IOGPU Completion");
                lVar3 = thunk_EXT_FUN_801100000395c074(param_1,0);
                *(long *)(param_1 + 0x30) = lVar3;
                if (lVar3 == 0) {
                  thunk_EXT_FUN_80110000038db19c
                            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                             "%s: completion gate alloc failure\n");
                  uVar2 = 0;
                }
                else {
                  (**(code **)(**(long **)(param_1 + 0x18) + 0xa0))
                            (*(long **)(param_1 + 0x18),lVar3);
                  lVar3 = thunk_EXT_FUN_801100000395abd8(param_1,FUN_fffffff00995f670,0,0);
                  *(long *)(param_1 + 0x20) = lVar3;
                  if (lVar3 == 0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: fCompletionInterrupt alloc fail\n");
                    uVar2 = 0;
                  }
                  else {
                    (**(code **)(**(long **)(param_1 + 0x18) + 0xa0))
                              (*(long **)(param_1 + 0x18),lVar3);
                    (**(code **)(**(long **)(param_1 + 0x20) + 0xb0))();
                    lVar3 = thunk_EXT_FUN_80110000038ff134();
                    *(long *)(param_1 + 0x58) = lVar3;
                    if (lVar3 == 0) {
                      thunk_EXT_FUN_80110000038db19c
                                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                 "%s: fGPURestartRegisteredCommandQueueLock alloc fail\n");
                      uVar2 = 0;
                    }
                    else {
                      *(undefined4 *)(param_1 + 0x50) = 0x10;
                      lVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1598,0x180);
                      *(long *)(param_1 + 0x48) = lVar3;
                      if (lVar3 == 0) {
                        thunk_EXT_FUN_80110000038db19c
                                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                   "%s: sGPURestartRegisteredCommandQueue alloc fail\n");
                        uVar2 = 0;
                      }
                      else {
                        lVar3 = thunk_EXT_FUN_80110000032770a0(FUN_fffffff00995f744,param_1,1,1);
                        *(long *)(param_1 + 0xb8) = lVar3;
                        if (lVar3 == 0) {
                          thunk_EXT_FUN_80110000038db19c
                                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                     "%s: fGARTCollectorThread alloc fail\n");
                          uVar2 = 0;
                        }
                        else {
                          lVar3 = thunk_EXT_FUN_80110000038ff010();
                          *(long *)(param_1 + 0xc0) = lVar3;
                          if (lVar3 == 0) {
                            thunk_EXT_FUN_80110000038db19c
                                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                       "%s: fGARTCollectorLock alloc fail\n");
                            uVar2 = 0;
                          }
                          else {
                            lVar3 = thunk_EXT_FUN_80110000038fe5cc
                                              (*(int *)(*(long *)(param_1 + 0x1a8) + 0x200) + 1);
                            *(long *)(param_1 + 0xf8) = lVar3;
                            if (lVar3 == 0) {
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: failed to allocate fRestartTypeAsync\n");
                            }
                            else {
                              lVar3 = thunk_EXT_FUN_80110000038ff010();
                              *(long *)(param_1 + 0xf0) = lVar3;
                              if (lVar3 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: failed to allocate Hardware lock\n");
                              }
                              lVar3 = thunk_EXT_FUN_801100000395abd8
                                                (param_1,FUN_fffffff00995f8b0,0,0);
                              *(long *)(param_1 + 0x100) = lVar3;
                              if (lVar3 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: failed to allocate HW error interrupt\n");
                              }
                              else {
                                (**(code **)(**(long **)(param_1 + 0x10) + 0xa0))
                                          (*(long **)(param_1 + 0x10),lVar3);
                                (**(code **)(**(long **)(param_1 + 0x100) + 0xb0))();
                              }
                            }
                            uVar1 = *(uint *)(*(long *)(param_1 + 0x1a8) + 0x23c);
                            if (uVar1 != 0) {
                              thunk_EXT_FUN_8011000003398268
                                        ((ulong)uVar1 * 1000000000,param_1 + 0xe0);
                              lVar3 = thunk_EXT_FUN_801100000396128c(param_1,FUN_fffffff00995fbdc);
                              *(long *)(param_1 + 200) = lVar3;
                              if (lVar3 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: failed to allocate HW progress timer\n");
                              }
                              else {
                                (**(code **)(**(long **)(param_1 + 0x10) + 0xa0))
                                          (*(long **)(param_1 + 0x10),lVar3);
                                (**(code **)(**(long **)(param_1 + 200) + 0xb0))();
                              }
                              lVar3 = thunk_EXT_FUN_801100000395abd8
                                                (param_1,FUN_fffffff00995fc18,0,0);
                              *(long *)(param_1 + 0xd0) = lVar3;
                              if (lVar3 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: failed to allocate HW progress interrupt\n");
                                (**(code **)(**(long **)(param_1 + 200) + 0xb8))();
                              }
                              else {
                                (**(code **)(**(long **)(param_1 + 0x10) + 0xa0))
                                          (*(long **)(param_1 + 0x10),lVar3);
                                (**(code **)(**(long **)(param_1 + 0xd0) + 0xb0))();
                              }
                            }
                            plVar4 = (long *)thunk_EXT_FUN_80110000038cb1e8
                                                       (param_1,FUN_fffffff00995fc44,0);
                            if (plVar4 != (long *)0x0) {
                              (**(code **)(**(long **)(param_1 + 0x1a8) + 200))
                                        (*(long **)(param_1 + 0x1a8),"SchedulerState",plVar4);
                              (**(code **)(*plVar4 + 0x28))(plVar4);
                            }
                            lVar3 = thunk_EXT_FUN_80110000038ff3d8();
                            *(long *)(param_1 + 0x208) = lVar3;
                            if (lVar3 == 0) {
                              thunk_EXT_FUN_80110000038db19c
                                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                         "%s: failed to create rw Lock\n");
                              uVar2 = 0;
                            }
                            else {
                              lVar3 = thunk_EXT_FUN_80110000038ff010();
                              *(long *)(param_1 + 0x248) = lVar3;
                              if (lVar3 == 0) {
                                thunk_EXT_FUN_80110000038db19c
                                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                                           "%s: failed to create sleep lock\n");
                                uVar2 = 0;
                              }
                              else {
                                thunk_EXT_FUN_8011000002c339bc
                                          (*(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0xf8),
                                           FUN_fffffff00995fd1c,param_1);
                                uVar2 = 1;
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
        }
      }
    }
  }
  return uVar2;
}

