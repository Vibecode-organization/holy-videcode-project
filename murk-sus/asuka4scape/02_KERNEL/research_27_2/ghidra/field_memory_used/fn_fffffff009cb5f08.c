// FUN_fffffff009cb5f08 @ fffffff009cb5f08

/* WARNING: Removing unreachable block (ram,0xfffffff009cb6824) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb75dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb749c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6eac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6dc4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6410) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6a24) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6184) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6730) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb613c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb68d0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb72ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6d9c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6e14) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb701c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb735c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb768c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb6be4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009cb605c) */

undefined8
FUN_fffffff009cb5f08
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,int param_8)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  bool bVar33;
  int iVar34;
  undefined4 uVar35;
  long *plVar36;
  long lVar37;
  char *pcVar38;
  uint extraout_w8;
  uint uVar39;
  uint extraout_w8_00;
  undefined8 uVar40;
  short *psVar41;
  long lVar42;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 uVar50;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined1 auVar43 [16];
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined1 auVar44 [16];
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined8 extraout_d0_07;
  undefined8 extraout_var_07;
  undefined1 auVar47 [16];
  undefined8 extraout_d0_08;
  undefined8 extraout_var_08;
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined4 uVar51;
  undefined1 auVar52 [12];
  undefined4 uVar53;
  undefined1 auVar54 [12];
  
  uVar53 = param_4._0_4_;
  auVar54 = param_4._4_12_;
  uVar51 = param_3._0_4_;
  auVar52 = param_3._4_12_;
  uVar39 = *(uint *)((long)param_7 + 500);
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar39 >> 3 & 1) != 0) {
      if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
        psVar41 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                   (byte *)"%s@%s: %s::%s: goOnBus - %d\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: goOnBus - %d\n");
      }
    }
  }
  else if ((uVar39 >> 3 & 1) != 0) {
    FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:goOnBus - %d\n");
  }
  if (param_8 == 0) {
    if ((*(byte *)(param_7 + 0x7c) & 1) == 0) {
      uVar39 = *(uint *)((long)param_7 + 500);
      if ((int)param_7[0x4c7] == 0) {
        if ((uVar39 & 1) != 0) {
          if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
            psVar41 = *(short **)PTR_DAT_fffffff008081388;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                       (byte *)"%s@%s: %s::%s: not on bus\n");
          }
          else {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: not on bus\n");
          }
        }
      }
      else if ((uVar39 & 1) != 0) {
        FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:not on bus\n");
      }
      if ((*(byte *)((long)param_7 + 0x25f4) & 1) != 0) {
        (**(code **)(*param_7 + 0x868))(param_7);
      }
      uVar40 = 0;
      *(byte *)((long)param_7 + 0x25f4) = 0;
    }
    else {
      auVar4 = thunk_FUN_fffffff009c9bc2c((long)param_7);
      *(undefined4 *)(param_7 + 0xb2) = 0;
      auVar5._4_12_ = auVar52;
      auVar5._0_4_ = uVar51;
      auVar18._4_12_ = auVar54;
      auVar18._0_4_ = uVar53;
      FUN_fffffff009cb350c(auVar4,param_2,auVar5,auVar18,param_5,param_6,param_7,0x80,0xe00002eb);
      auVar4 = (**(code **)(*param_7 + 0x5e0))(*param_7 + 0x5e0,param_7,0x80);
      auVar6._4_12_ = auVar52;
      auVar6._0_4_ = uVar51;
      auVar19._4_12_ = auVar54;
      auVar19._0_4_ = uVar53;
      FUN_fffffff009cb5358(auVar4,param_2,auVar6,auVar19,param_5,param_6,param_7);
      (**(code **)(*param_7 + 0x5e0))(*param_7 + 0x5e0,param_7,0);
      lVar37 = 0;
      lVar42 = 4;
      do {
        if ((long *)param_7[lVar37 + 0xb7] != (long *)0x0) {
          (**(code **)(*(long *)param_7[lVar37 + 0xb7] + 0x90))();
        }
        lVar37 = lVar37 + 1;
        lVar42 = lVar42 + -1;
      } while (lVar42 != 0);
      iVar34 = (**(code **)(*param_7 + 0x7c0))(param_7);
      if (iVar34 != 0) {
        uVar39 = *(uint *)((long)param_7 + 500);
        if ((int)param_7[0x4c7] == 0) {
          if ((uVar39 & 1) != 0) {
            if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
              psVar41 = *(short **)PTR_DAT_fffffff008081388;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              thunk_FUN_fffffff00a8df19c
                        (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                         (byte *)"%s@%s: %s::%s: failed stopDeviceController 0x%08x\n");
            }
            else {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)"%s@%s: %s::%s: failed stopDeviceController 0x%08x\n");
            }
          }
        }
        else if ((uVar39 & 1) != 0) {
          FUN_fffffff009cacb28
                    ((ulong)param_7,(byte *)"AppleUSBXDCI::%s:failed stopDeviceController 0x%08x\n")
          ;
        }
      }
      if ((long *)param_7[0x4c4] != (long *)0x0) {
        (**(code **)(*(long *)param_7[0x4c4] + 0xb8))();
        (**(code **)(*(long *)param_7[0x8b] + 0xa8))((long *)param_7[0x8b],param_7[0x4c4]);
        if ((long *)param_7[0x4c4] != (long *)0x0) {
          (**(code **)(*(long *)param_7[0x4c4] + 0x28))();
        }
        param_7[0x4c4] = 0;
      }
      FUN_fffffff009cab05c(param_7[0xb5]);
      FUN_fffffff009cab05c(param_7[0xb6]);
      (**(code **)(*param_7 + 0x868))(param_7);
      uVar40 = 0;
      *(undefined1 *)(param_7 + 0x7c) = 0;
    }
    goto LAB_fffffff009cb6ab4;
  }
  if ((*(byte *)(param_7 + 0x7c) & 1) == 0) {
    uVar40 = (**(code **)(*param_7 + 0x860))(param_7);
    if ((int)uVar40 != 0) {
      uVar39 = *(uint *)((long)param_7 + 500);
      if ((int)param_7[0x4c7] == 0) {
        if ((uVar39 & 1) != 0) {
          if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
            psVar41 = *(short **)PTR_DAT_fffffff008081388;
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
            thunk_FUN_fffffff00a8df19c
                      (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                       (byte *)"%s@%s: %s::%s: failed to powerOn the controller\n");
          }
          else {
            (**(code **)(*param_7 + 0x1e8))(param_7,0);
            (**(code **)(*param_7 + 0x218))(param_7,0);
            thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: failed to powerOn the controller\n");
          }
        }
      }
      else if ((uVar39 & 1) != 0) {
        FUN_fffffff009cacb28
                  ((ulong)param_7,(byte *)"AppleUSBXDCI::%s:failed to powerOn the controller\n");
      }
      *(undefined1 *)((long)param_7 + 0x25f4) = 1;
      goto LAB_fffffff009cb6a88;
    }
    FUN_fffffff009caaff0(param_7[0xb5]);
    FUN_fffffff009caaff0(param_7[0xb6]);
    uVar40 = 0;
    uVar50 = 0;
    param_7[0x4bb] = 0;
    if (*(uint *)(param_7 + 0x4c5) < 4) {
      if (param_7[0xb7] == 0) {
        auVar4._4_12_ = auVar52;
        auVar4._0_4_ = uVar51;
        auVar20._4_12_ = auVar54;
        auVar20._0_4_ = uVar53;
        plVar36 = FUN_fffffff009cc68bc
                            (ZEXT816(0),param_2,auVar4,auVar20,param_5,param_6,param_7,
                             FUN_fffffff009cb8dcc,FUN_fffffff009cb7f9c,param_7[0x17],0);
        param_7[0xb7] = (long)plVar36;
        if (plVar36 == (long *)0x0) {
          if ((int)param_7[0x4c7] == 0) {
            if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
               (bVar33 = thunk_FUN_fffffff00a394140(), bVar33)) {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)
                         "%s@%s: %s::%s: failed to create _eventHandlers[kCommonEventHandlerIndex]\n"
                        );
              auVar45._8_8_ = extraout_var_04;
              auVar45._0_8_ = extraout_d0_04;
            }
            else {
              psVar41 = *(short **)PTR_DAT_fffffff008081388;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              auVar45 = thunk_FUN_fffffff00a8df19c
                                  (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41
                                   ,0x11,(byte *)
                                         "%s@%s: %s::%s: failed to create _eventHandlers[kCommonEventHandlerIndex]\n"
                                  );
            }
            if (*(int *)((long)param_7 + 500) < 0) {
              auVar7._4_12_ = auVar52;
              auVar7._0_4_ = uVar51;
              auVar21._4_12_ = auVar54;
              auVar21._0_4_ = uVar53;
              FUN_fffffff009cc87bc(auVar45,param_2,auVar7,auVar21,param_5,param_6);
              goto LAB_fffffff009cb730c;
            }
          }
          else if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
            pcVar38 = "AppleUSBXDCI::%s:failed to create _eventHandlers[kCommonEventHandlerIndex]\n"
            ;
            goto LAB_fffffff009cb60e4;
          }
          goto LAB_fffffff009cb62d4;
        }
      }
      goto LAB_fffffff009cb6d10;
    }
    if (param_7[0xb7] == 0) {
      auVar8._4_12_ = auVar52;
      auVar8._0_4_ = uVar51;
      auVar22._4_12_ = auVar54;
      auVar22._0_4_ = uVar53;
      plVar36 = FUN_fffffff009cc68bc
                          (ZEXT816(0),param_2,auVar8,auVar22,param_5,param_6,param_7,
                           FUN_fffffff009cb76ec,FUN_fffffff009cb7f9c,param_7[0x17],0);
      param_7[0xb7] = (long)plVar36;
      uVar40 = extraout_d0;
      uVar50 = extraout_var;
      if (plVar36 != (long *)0x0) goto LAB_fffffff009cb6348;
      if ((int)param_7[0x4c7] != 0) {
        if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
          pcVar38 = "AppleUSBXDCI::%s:failed to create _eventHandlers[kBusEventHandlerIndex]\n";
          goto LAB_fffffff009cb60e4;
        }
        goto LAB_fffffff009cb62d4;
      }
      if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar33 = thunk_FUN_fffffff00a394140(), bVar33)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: failed to create _eventHandlers[kBusEventHandlerIndex]\n"
                  );
        auVar46._8_8_ = extraout_var_05;
        auVar46._0_8_ = extraout_d0_05;
      }
      else {
LAB_fffffff009cb730c:
        psVar41 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar46 = thunk_FUN_fffffff00a8df19c
                            (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0x11,
                             (byte *)
                             "%s@%s: %s::%s: failed to create _eventHandlers[kBusEventHandlerIndex]\n"
                            );
      }
      if (-1 < *(int *)((long)param_7 + 500)) goto LAB_fffffff009cb62d4;
      auVar9._4_12_ = auVar52;
      auVar9._0_4_ = uVar51;
      auVar23._4_12_ = auVar54;
      auVar23._0_4_ = uVar53;
      FUN_fffffff009cc8870(auVar46,param_2,auVar9,auVar23,param_5,param_6);
      uVar39 = extraout_w8;
LAB_fffffff009cb73bc:
      if ((((uVar39 ^ 0xffffffff) & 0x40000001) == 0) &&
         (bVar33 = thunk_FUN_fffffff00a394140(), bVar33)) {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"%s@%s: %s::%s: _eventHandlers[kIsocEventHandlerIndex]\n");
        auVar48._8_8_ = extraout_var_07;
        auVar48._0_8_ = extraout_d0_07;
      }
      else {
        psVar41 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        auVar48 = thunk_FUN_fffffff00a8df19c
                            (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0x11,
                             (byte *)"%s@%s: %s::%s: _eventHandlers[kIsocEventHandlerIndex]\n");
      }
      if (-1 < *(int *)((long)param_7 + 500)) goto LAB_fffffff009cb62d4;
      auVar13._4_12_ = auVar52;
      auVar13._0_4_ = uVar51;
      auVar27._4_12_ = auVar54;
      auVar27._0_4_ = uVar53;
      FUN_fffffff009cc8828(auVar48,param_2,auVar13,auVar27,param_5,param_6);
LAB_fffffff009cb763c:
      psVar41 = *(short **)PTR_DAT_fffffff008081388;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
      auVar49 = thunk_FUN_fffffff00a8df19c
                          (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0x11,
                           (byte *)
                           "%s@%s: %s::%s: failed to create _eventHandlers[kDeviceEventHandlerIndex]\n"
                          );
    }
    else {
LAB_fffffff009cb6348:
      if (param_7[0xb8] == 0) {
        auVar1._8_8_ = uVar50;
        auVar1._0_8_ = uVar40;
        auVar10._4_12_ = auVar52;
        auVar10._0_4_ = uVar51;
        auVar24._4_12_ = auVar54;
        auVar24._0_4_ = uVar53;
        plVar36 = FUN_fffffff009cc68bc
                            (auVar1,param_2,auVar10,auVar24,param_5,param_6,param_7,
                             FUN_fffffff009cb7fa8,FUN_fffffff009cb7f9c,param_7[0x17],1);
        param_7[0xb8] = (long)plVar36;
        uVar40 = extraout_d0_00;
        uVar50 = extraout_var_00;
        if (plVar36 != (long *)0x0) goto LAB_fffffff009cb6390;
        if ((int)param_7[0x4c7] != 0) {
          if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
            pcVar38 = "AppleUSBXDCI::%s:failed to create _eventHandlers[kIOEventHandlerIndex]\n";
            goto LAB_fffffff009cb60e4;
          }
          goto LAB_fffffff009cb62d4;
        }
        if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
           (bVar33 = thunk_FUN_fffffff00a394140(), bVar33)) {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "%s@%s: %s::%s: failed to create _eventHandlers[kIOEventHandlerIndex]\n");
          auVar47._8_8_ = extraout_var_06;
          auVar47._0_8_ = extraout_d0_06;
        }
        else {
          psVar41 = *(short **)PTR_DAT_fffffff008081388;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          auVar47 = thunk_FUN_fffffff00a8df19c
                              (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,
                               0x11,(byte *)
                                    "%s@%s: %s::%s: failed to create _eventHandlers[kIOEventHandlerIndex]\n"
                              );
        }
        if (-1 < *(int *)((long)param_7 + 500)) goto LAB_fffffff009cb62d4;
        auVar11._4_12_ = auVar52;
        auVar11._0_4_ = uVar51;
        auVar25._4_12_ = auVar54;
        auVar25._0_4_ = uVar53;
        FUN_fffffff009cc884c(auVar47,param_2,auVar11,auVar25,param_5,param_6);
        uVar39 = extraout_w8_00;
      }
      else {
LAB_fffffff009cb6390:
        if (param_7[0xb9] == 0) {
          auVar2._8_8_ = uVar50;
          auVar2._0_8_ = uVar40;
          auVar12._4_12_ = auVar52;
          auVar12._0_4_ = uVar51;
          auVar26._4_12_ = auVar54;
          auVar26._0_4_ = uVar53;
          plVar36 = FUN_fffffff009cc68bc
                              (auVar2,param_2,auVar12,auVar26,param_5,param_6,param_7,
                               FUN_fffffff009cb7ff4,FUN_fffffff009cb8310,param_7[0x17],2);
          param_7[0xb9] = (long)plVar36;
          if (plVar36 == (long *)0x0) {
            uVar39 = *(uint *)((long)param_7 + 500);
            if ((int)param_7[0x4c7] != 0) {
              if ((uVar39 & 0x80000001) != 0) {
                pcVar38 = "AppleUSBXDCI::%s:_eventHandlers[kIsocEventHandlerIndex]\n";
                goto LAB_fffffff009cb60e4;
              }
              goto LAB_fffffff009cb62d4;
            }
            goto LAB_fffffff009cb73bc;
          }
        }
        if (param_7[0xba] != 0) {
LAB_fffffff009cb6d10:
          if ((int)param_7[0x18] - 1U < 2) {
            (**(code **)(*param_7 + 0x810))(param_7,0x11c,0x1a,0x4000000,1);
          }
          auVar43 = (**(code **)(*param_7 + 0x810))(param_7,0x110,0xc,0x3000,2);
          lVar37 = *(long *)(*param_7 + 0x8b8);
          if (lVar37 == 0) {
            lVar37 = thunk_FUN_fffffff00a894f04(param_7,-0xff6347188);
            auVar43._8_8_ = extraout_var_02;
            auVar43._0_8_ = extraout_d0_02;
            auVar32._8_8_ = extraout_var_02;
            auVar32._0_8_ = extraout_d0_02;
            if (lVar37 == 0) {
              lVar37 = 0;
              auVar43 = auVar32;
            }
          }
          auVar15._4_12_ = auVar52;
          auVar15._0_4_ = uVar51;
          auVar29._4_12_ = auVar54;
          auVar29._0_4_ = uVar53;
          plVar36 = thunk_FUN_fffffff00a96528c
                              (auVar43,param_2,auVar15,auVar29,param_5,param_6,param_7,lVar37);
          param_7[0x4c4] = (long)plVar36;
          (**(code **)(*(long *)param_7[0x8b] + 0xa0))((long *)param_7[0x8b],plVar36);
          (**(code **)(*(long *)param_7[0x4c4] + 0xb0))();
          *(undefined1 *)(param_7 + 0x7c) = 1;
          *(undefined1 *)((long)param_7 + 0x25f4) = 0;
          uVar40 = (**(code **)(*param_7 + 0x7b8))(*param_7 + 0x7b8,param_7);
          if ((int)uVar40 == 0) {
            uVar35 = (**(code **)(*param_7 + 0x688))(param_7);
            *(undefined4 *)(param_7 + 0x4bf) = uVar35;
            *(undefined4 *)(param_7 + 0x86) = 0;
            goto LAB_fffffff009cb6ab4;
          }
          if ((int)param_7[0x4c7] == 0) {
            if ((((*(uint *)((long)param_7 + 500) ^ 0xffffffff) & 0x40000001) == 0) &&
               (bVar33 = thunk_FUN_fffffff00a394140(), bVar33)) {
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              (**(code **)(*param_7 + 0x218))(param_7,0);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)"%s@%s: %s::%s: failed initDeviceController 0x%08x\n");
              auVar44._8_8_ = extraout_var_03;
              auVar44._0_8_ = extraout_d0_03;
            }
            else {
              psVar41 = *(short **)PTR_DAT_fffffff008081388;
              (**(code **)(*param_7 + 0x1e8))(param_7,0);
              auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
              auVar44 = thunk_FUN_fffffff00a8df19c
                                  (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41
                                   ,0x11,(byte *)
                                         "%s@%s: %s::%s: failed initDeviceController 0x%08x\n");
            }
            if (*(int *)((long)param_7 + 500) < 0) {
              auVar16._4_12_ = auVar52;
              auVar16._0_4_ = uVar51;
              auVar30._4_12_ = auVar54;
              auVar30._0_4_ = uVar53;
              FUN_fffffff009cc87e0(auVar44,param_2,auVar16,auVar30,param_5,param_6);
              goto LAB_fffffff009cb7080;
            }
          }
          else if ((*(uint *)((long)param_7 + 500) & 0x80000001) != 0) {
            FUN_fffffff009cacb28
                      ((ulong)param_7,
                       (byte *)"AppleUSBXDCI::%s:failed initDeviceController 0x%08x\n");
          }
LAB_fffffff009cb6a88:
          (**(code **)(*param_7 + 0x6c8))(param_7,1,&DAT_fffffff0078bd710);
          goto LAB_fffffff009cb6ab4;
        }
        lVar37 = thunk_FUN_fffffff00a894f04(param_7,0);
        if (lVar37 == 0) {
          lVar37 = 0;
        }
        auVar3._8_8_ = extraout_var_01;
        auVar3._0_8_ = extraout_d0_01;
        auVar14._4_12_ = auVar52;
        auVar14._0_4_ = uVar51;
        auVar28._4_12_ = auVar54;
        auVar28._0_4_ = uVar53;
        plVar36 = FUN_fffffff009cc68bc
                            (auVar3,param_2,auVar14,auVar28,param_5,param_6,param_7,lVar37,
                             FUN_fffffff009cb7f9c,param_7[0x17],3);
        param_7[0xba] = (long)plVar36;
        if (plVar36 != (long *)0x0) goto LAB_fffffff009cb6d10;
LAB_fffffff009cb7080:
        uVar39 = *(uint *)((long)param_7 + 500);
        if ((int)param_7[0x4c7] != 0) {
          if ((uVar39 & 0x80000001) != 0) {
            pcVar38 = "AppleUSBXDCI::%s:failed to create _eventHandlers[kDeviceEventHandlerIndex]\n"
            ;
            goto LAB_fffffff009cb60e4;
          }
          goto LAB_fffffff009cb62d4;
        }
      }
      if ((((uVar39 ^ 0xffffffff) & 0x40000001) != 0) ||
         (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) goto LAB_fffffff009cb763c;
      (**(code **)(*param_7 + 0x1e8))(param_7,0);
      (**(code **)(*param_7 + 0x218))(param_7,0);
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "%s@%s: %s::%s: failed to create _eventHandlers[kDeviceEventHandlerIndex]\n");
      auVar49._8_8_ = extraout_var_08;
      auVar49._0_8_ = extraout_d0_08;
    }
    if (*(int *)((long)param_7 + 500) < 0) {
      auVar17._4_12_ = auVar52;
      auVar17._0_4_ = uVar51;
      auVar31._4_12_ = auVar54;
      auVar31._0_4_ = uVar53;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009cc8804(auVar49,param_2,auVar17,auVar31,param_5,param_6);
    }
  }
  else {
    uVar39 = *(uint *)((long)param_7 + 500);
    if ((int)param_7[0x4c7] == 0) {
      if ((uVar39 & 1) != 0) {
        if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
          psVar41 = *(short **)PTR_DAT_fffffff008081388;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                     (byte *)"%s@%s: %s::%s: already on bus\n");
          uVar40 = 0;
          goto LAB_fffffff009cb6ab4;
        }
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: already on bus\n");
      }
    }
    else if ((uVar39 & 1) != 0) {
      pcVar38 = "AppleUSBXDCI::%s:already on bus\n";
LAB_fffffff009cb60e4:
      FUN_fffffff009cacb28((ulong)param_7,(byte *)pcVar38);
    }
  }
LAB_fffffff009cb62d4:
  uVar40 = 0;
LAB_fffffff009cb6ab4:
  uVar39 = *(uint *)((long)param_7 + 500);
  if ((int)param_7[0x4c7] == 0) {
    if ((uVar39 >> 3 & 1) != 0) {
      if (((uVar39 >> 0x1e & 1) == 0) || (bVar33 = thunk_FUN_fffffff00a394140(), !bVar33)) {
        psVar41 = *(short **)PTR_DAT_fffffff008081388;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar4 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar4,param_2,uVar51,uVar53,param_5,param_6,&MACH_HEADER,psVar41,0,
                   (byte *)"%s@%s: %s::%s: completed with status 0x%08x\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: completed with status 0x%08x\n");
      }
    }
  }
  else if ((uVar39 >> 3 & 1) != 0) {
    FUN_fffffff009cacb28((ulong)param_7,(byte *)"AppleUSBXDCI::%s:completed with status 0x%08x\n");
  }
  return uVar40;
}

