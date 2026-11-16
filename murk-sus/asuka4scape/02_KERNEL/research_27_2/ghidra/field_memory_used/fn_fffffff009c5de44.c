// FUN_fffffff009c5de44 @ fffffff009c5de44

undefined8
FUN_fffffff009c5de44
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8)

{
  undefined1 auVar1 [16];
  undefined *puVar2;
  int iVar3;
  long extraout_x0;
  long lVar4;
  long *plVar5;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  undefined8 extraout_x1_01;
  undefined8 extraout_x1_02;
  undefined8 extraout_x1_03;
  undefined8 extraout_x1_04;
  undefined8 extraout_x1_05;
  undefined8 extraout_x1_06;
  undefined8 extraout_x1_07;
  undefined8 extraout_x1_08;
  undefined8 extraout_x1_09;
  undefined8 extraout_x1_10;
  undefined8 uVar6;
  undefined8 extraout_x1_11;
  undefined8 extraout_x1_12;
  undefined8 extraout_x1_13;
  undefined8 extraout_x1_14;
  undefined8 extraout_x1_15;
  undefined8 extraout_x1_16;
  undefined8 extraout_x1_17;
  undefined8 extraout_x1_18;
  undefined8 extraout_x1_19;
  undefined8 extraout_x1_20;
  ulong uVar7;
  undefined1 auVar8 [16];
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 extraout_q0_08 [16];
  undefined1 extraout_q0_09 [16];
  undefined1 extraout_q0_10 [16];
  undefined4 uVar9;
  undefined1 auVar10 [12];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  undefined1 auVar13 [16];
  
  uVar11 = param_4._0_4_;
  auVar12 = param_4._4_12_;
  uVar9 = param_3._0_4_;
  auVar10 = param_3._4_12_;
  auVar8 = thunk_FUN_fffffff00a8df19c
                     (param_1,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                      (short *)PTR_DAT_fffffff00807b638,0,(byte *)"IOTimeSyncClockManager::init\n");
  *(undefined8 *)(param_7 + 0x88) = 0;
  *(undefined8 *)(param_7 + 0xd0) = 0;
  *(undefined8 *)(param_7 + 0xe0) = 0;
  *(undefined8 *)(param_7 + 0xe8) = 0;
  *(undefined8 *)(param_7 + 0xa0) = 0xffffffffffffffff;
  *(undefined4 *)(param_7 + 0xa8) = 0x63690000;
  *(undefined8 *)(param_7 + 0xb0) = 0xffffffffffff0000;
  *(undefined4 *)(param_7 + 0xb8) = 0x10000;
  *(undefined1 *)(param_7 + 200) = 0;
  *(undefined2 *)(param_7 + 0xd8) = 1;
  *(undefined1 *)(param_7 + 0xda) = 1;
  auVar13._4_12_ = auVar10;
  auVar13._0_4_ = uVar9;
  auVar1._4_12_ = auVar12;
  auVar1._0_4_ = uVar11;
  thunk_FUN_fffffff00a27b29c(auVar8,param_2,auVar13,auVar1,param_5,param_6,-0xff63a1a88,param_7);
  *(long *)(param_7 + 0xc0) = extraout_x0;
  puVar2 = PTR_DAT_fffffff00807b638;
  if (extraout_x0 == 0) {
    auVar13 = thunk_FUN_fffffff00a8df19c
                        (extraout_q0,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                         (short *)PTR_DAT_fffffff00807b638,0,
                         (byte *)
                         " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                        );
    uVar7 = 0;
    thunk_FUN_fffffff00a8df19c
              (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0,
               (byte *)"Failed to allocate thread call\n");
    uVar6 = extraout_x1;
  }
  else {
    lVar4 = thunk_FUN_fffffff00a903010();
    *(long *)(param_7 + 0xe0) = lVar4;
    puVar2 = PTR_DAT_fffffff00807b638;
    if (lVar4 == 0) {
      auVar13 = thunk_FUN_fffffff00a8df19c
                          (extraout_q0_00,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                           (short *)PTR_DAT_fffffff00807b638,0,
                           (byte *)
                           " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                          );
      uVar7 = 0;
      thunk_FUN_fffffff00a8df19c
                (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0,
                 (byte *)"failed to allocate mapping lock\n");
      uVar6 = extraout_x1_00;
    }
    else {
      lVar4 = thunk_FUN_fffffff00a903010();
      *(long *)(param_7 + 0xe8) = lVar4;
      puVar2 = PTR_DAT_fffffff00807b638;
      if (lVar4 == 0) {
        auVar13 = thunk_FUN_fffffff00a8df19c
                            (extraout_q0_01,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                             (short *)PTR_DAT_fffffff00807b638,0,
                             (byte *)
                             " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                            );
        uVar7 = 0;
        thunk_FUN_fffffff00a8df19c
                  (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0,
                   (byte *)"Failed to allocate dynamic lock\n");
        uVar6 = extraout_x1_01;
      }
      else {
        lVar4 = thunk_FUN_fffffff00a903010();
        *(long *)(param_7 + 0xf0) = lVar4;
        puVar2 = PTR_DAT_fffffff00807b638;
        if (lVar4 == 0) {
          auVar13 = thunk_FUN_fffffff00a8df19c
                              (extraout_q0_02,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                               (short *)PTR_DAT_fffffff00807b638,0,
                               (byte *)
                               " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                              );
          uVar7 = 0;
          thunk_FUN_fffffff00a8df19c
                    (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0,
                     (byte *)"failed to allocate gPTP reference lock\n");
          uVar6 = extraout_x1_02;
        }
        else {
          lVar4 = thunk_FUN_fffffff00a903010();
          *(long *)(param_7 + 0xf8) = lVar4;
          puVar2 = PTR_DAT_fffffff00807b638;
          if (lVar4 == 0) {
            auVar13 = thunk_FUN_fffffff00a8df19c
                                (extraout_q0_03,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                                 (short *)PTR_DAT_fffffff00807b638,0,
                                 (byte *)
                                 " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                );
            uVar7 = 0;
            thunk_FUN_fffffff00a8df19c
                      (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0,
                       (byte *)"failed to allocate clock ID lock\n");
            uVar6 = extraout_x1_03;
          }
          else {
            lVar4 = thunk_FUN_fffffff00a903010();
            *(long *)(param_7 + 0x108) = lVar4;
            puVar2 = PTR_DAT_fffffff00807b638;
            if (lVar4 == 0) {
              auVar13 = thunk_FUN_fffffff00a8df19c
                                  (extraout_q0_04,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                                   (short *)PTR_DAT_fffffff00807b638,0,
                                   (byte *)
                                   " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                  );
              uVar7 = 0;
              thunk_FUN_fffffff00a8df19c
                        (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2,0
                         ,(byte *)"failed to allocate user clocks lock\n");
              uVar6 = extraout_x1_04;
            }
            else {
              lVar4 = thunk_FUN_fffffff00a903010();
              *(long *)(param_7 + 0x118) = lVar4;
              puVar2 = PTR_DAT_fffffff00807b638;
              if (lVar4 == 0) {
                auVar13 = thunk_FUN_fffffff00a8df19c
                                    (extraout_q0_05,param_2,uVar9,uVar11,param_5,param_6,
                                     &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                     (byte *)
                                     " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                    );
                uVar7 = 0;
                thunk_FUN_fffffff00a8df19c
                          (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,(short *)puVar2
                           ,0,(byte *)"failed to allocate persistent user clocks lock\n");
                uVar6 = extraout_x1_05;
              }
              else {
                plVar5 = thunk_FUN_fffffff00a89a1f4(0);
                *(long **)(param_7 + 0x88) = plVar5;
                puVar2 = PTR_DAT_fffffff00807b638;
                if (plVar5 == (long *)0x0) {
                  auVar13 = thunk_FUN_fffffff00a8df19c
                                      (extraout_q0_06,param_2,uVar9,uVar11,param_5,param_6,
                                       &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                       (byte *)
                                       " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                      );
                  uVar7 = 0;
                  thunk_FUN_fffffff00a8df19c
                            (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                             (short *)puVar2,0,
                             (byte *)"failed to create Dynamic Clock ID ref count array\n");
                  uVar6 = extraout_x1_06;
                }
                else {
                  plVar5 = thunk_FUN_fffffff00a89a1f4(0);
                  *(long **)(param_7 + 0xd0) = plVar5;
                  puVar2 = PTR_DAT_fffffff00807b638;
                  if (plVar5 == (long *)0x0) {
                    auVar13 = thunk_FUN_fffffff00a8df19c
                                        (extraout_q0_07,param_2,uVar9,uVar11,param_5,param_6,
                                         &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                         (byte *)
                                         " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                        );
                    uVar7 = 0;
                    thunk_FUN_fffffff00a8df19c
                              (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                               (short *)puVar2,0,
                               (byte *)"failed to create coreaudio clock ID mappings array\n");
                    uVar6 = extraout_x1_07;
                  }
                  else {
                    plVar5 = thunk_FUN_fffffff00a89a1f4(0);
                    *(long **)(param_7 + 0x110) = plVar5;
                    puVar2 = PTR_DAT_fffffff00807b638;
                    if (plVar5 == (long *)0x0) {
                      auVar13 = thunk_FUN_fffffff00a8df19c
                                          (extraout_q0_08,param_2,uVar9,uVar11,param_5,param_6,
                                           &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                           (byte *)
                                           " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                          );
                      uVar7 = 0;
                      thunk_FUN_fffffff00a8df19c
                                (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                                 (short *)puVar2,0,(byte *)"failed to allocate user clocks array\n")
                      ;
                      uVar6 = extraout_x1_08;
                    }
                    else {
                      plVar5 = thunk_FUN_fffffff00a8a10d8(0);
                      *(long **)(param_7 + 0x120) = plVar5;
                      puVar2 = PTR_DAT_fffffff00807b638;
                      if (plVar5 == (long *)0x0) {
                        auVar13 = thunk_FUN_fffffff00a8df19c
                                            (extraout_q0_09,param_2,uVar9,uVar11,param_5,param_6,
                                             &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                             (byte *)
                                             " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                            );
                        uVar7 = 0;
                        thunk_FUN_fffffff00a8df19c
                                  (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                                   (short *)puVar2,0,
                                   (byte *)"failed to allocate persistent user clocks dict\n");
                        uVar6 = extraout_x1_09;
                      }
                      else {
                        lVar4 = thunk_FUN_fffffff00a903010();
                        *(long *)(param_7 + 0x100) = lVar4;
                        puVar2 = PTR_DAT_fffffff00807b638;
                        if (lVar4 == 0) {
                          auVar13 = thunk_FUN_fffffff00a8df19c
                                              (extraout_q0_10,param_2,uVar9,uVar11,param_5,param_6,
                                               &MACH_HEADER,(short *)PTR_DAT_fffffff00807b638,0,
                                               (byte *)
                                               " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                              );
                          uVar7 = 0;
                          thunk_FUN_fffffff00a8df19c
                                    (auVar13,param_2,uVar9,uVar11,param_5,param_6,&MACH_HEADER,
                                     (short *)puVar2,0,
                                     (byte *)"Failed to allocate tsn capture lock\n");
                          uVar6 = extraout_x1_10;
                        }
                        else {
                          uVar7 = 0;
                          iVar3 = thunk_FUN_fffffff00aa14b0c
                                            ((byte *)"-timesync_bringup",(uint *)0x0,0);
                          *(bool *)(param_7 + 0x128) = iVar3 != 0;
                          auVar13 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_8);
                          uVar6 = auVar13._8_8_;
                          if ((auVar13._0_8_ & 1) != 0) {
                            return 1;
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
  if (*(undefined8 **)(param_7 + 0xe8) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xe8));
    *(undefined8 *)(param_7 + 0xe8) = 0;
    uVar6 = extraout_x1_11;
  }
  if (*(undefined8 **)(param_7 + 0xe0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xe0));
    *(undefined8 *)(param_7 + 0xe0) = 0;
    uVar6 = extraout_x1_12;
  }
  if (*(undefined8 **)(param_7 + 0xf0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xf0));
    *(undefined8 *)(param_7 + 0xf0) = 0;
    uVar6 = extraout_x1_13;
  }
  if (*(undefined8 **)(param_7 + 0xf8) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xf8));
    *(undefined8 *)(param_7 + 0xf8) = 0;
    uVar6 = extraout_x1_14;
  }
  if (*(undefined8 **)(param_7 + 0x108) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x108));
    *(undefined8 *)(param_7 + 0x108) = 0;
    uVar6 = extraout_x1_15;
  }
  if (*(undefined8 **)(param_7 + 0x118) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x118));
    *(undefined8 *)(param_7 + 0x118) = 0;
    uVar6 = extraout_x1_16;
  }
  if (*(long **)(param_7 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
    *(undefined8 *)(param_7 + 0x88) = 0;
    uVar6 = extraout_x1_17;
  }
  if (*(long **)(param_7 + 0xd0) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0xd0) + 0x28))();
    *(undefined8 *)(param_7 + 0xd0) = 0;
    uVar6 = extraout_x1_18;
  }
  if (*(long **)(param_7 + 0x110) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x110) + 0x28))();
    *(undefined8 *)(param_7 + 0x110) = 0;
    uVar6 = extraout_x1_19;
  }
  if (*(long **)(param_7 + 0x120) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x120) + 0x28))();
    *(undefined8 *)(param_7 + 0x120) = 0;
    uVar6 = extraout_x1_20;
  }
  if (*(uint **)(param_7 + 0xc0) != (uint *)0x0) {
    thunk_FUN_fffffff00a27b31c(*(uint **)(param_7 + 0xc0),uVar6,uVar7);
    *(undefined8 *)(param_7 + 0xc0) = 0;
  }
  if (*(undefined8 **)(param_7 + 0x100) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x100));
    *(undefined8 *)(param_7 + 0x100) = 0;
  }
  return 0;
}

