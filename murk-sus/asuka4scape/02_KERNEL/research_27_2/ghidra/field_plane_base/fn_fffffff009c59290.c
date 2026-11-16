// FUN_fffffff009c59290 @ fffffff009c59290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff009c59290
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
          undefined8 param_8,long *param_9,undefined2 param_10,undefined ********param_11,
          undefined4 param_12,long *param_13,undefined1 param_14,undefined8 param_15)

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
  undefined *puVar25;
  int iVar26;
  ulong uVar27;
  long lVar28;
  undefined8 uVar29;
  long *plVar30;
  undefined ********ppppppppuVar31;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_d0_08;
  undefined8 extraout_d0_09;
  undefined8 extraout_d0_10;
  undefined8 extraout_d0_11;
  undefined8 extraout_d0_12;
  undefined8 extraout_d0_13;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined8 extraout_var_08;
  undefined8 extraout_var_09;
  undefined8 extraout_var_10;
  undefined8 extraout_var_11;
  undefined8 extraout_var_12;
  undefined8 extraout_var_13;
  undefined4 uVar32;
  undefined1 auVar33 [12];
  undefined4 uVar34;
  undefined1 auVar35 [12];
  uint local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  uVar34 = param_4._0_4_;
  auVar35 = param_4._4_12_;
  uVar32 = param_3._0_4_;
  auVar33 = param_3._4_12_;
  local_70 = *(long *)PTR_DAT_fffffff00807b630;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  local_c4 = 0;
  if (param_9 == (long *)0x0) {
    FUN_fffffff009c7a9f4(ZEXT816(0),param_2,uVar32,uVar34,param_5,param_6);
  }
  else {
    ppppppppuVar31 = param_11;
    uVar27 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_15);
    if ((uVar27 & 1) == 0) {
      auVar2._8_8_ = extraout_var;
      auVar2._0_8_ = extraout_d0;
      FUN_fffffff009c7a63c(auVar2,param_2,uVar32,uVar34,param_5,param_6);
    }
    else {
      param_7[0x13] = (long)param_9;
      (**(code **)(*param_9 + 0x20))(param_9);
      *(undefined4 *)((long)param_7 + 0xa2) = (int)param_8;
      *(undefined2 *)(param_7 + 0x14) = param_10;
      *(short *)((long)param_7 + 0xa6) = (short)((ulong)param_8 >> 0x20);
      *(int *)(param_7 + 0x15) = (int)param_11;
      *(undefined4 *)(param_7 + 0x16) = param_12;
      *(undefined4 *)((long)param_7 + 0xac) = param_12;
      iVar26 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_ts_mode",&local_c4,4);
      if (iVar26 != 0) {
        if (local_c4 < 4) {
          lVar28 = (**(code **)(*param_7 + 0x38))(param_7);
          thunk_FUN_fffffff00a895b28(lVar28);
          auVar2 = (**(code **)(*param_9 + 0xa8))(param_9);
          thunk_FUN_fffffff00a8df19c
                    (auVar2,param_2,uVar32,uVar34,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00807b638,0,
                     (byte *)
                     "  %s(%s): Boot-arg timesync_ts_mode overriding %s%d mode from %d to %d");
          *(uint *)((long)param_7 + 0xac) = local_c4;
        }
        else {
          auVar1._8_8_ = extraout_var_00;
          auVar1._0_8_ = extraout_d0_00;
          thunk_FUN_fffffff00a8df19c
                    (auVar1,param_2,uVar32,uVar34,param_5,param_6,&MACH_HEADER,
                     (short *)PTR_DAT_fffffff00807b638,0x10,
                     (byte *)"Boot-arg timesync_ts_mode=%d out of range (%d-%d), ignoring\n");
        }
      }
      param_7[0x17] = (long)param_13;
      if (param_13 != (long *)0x0) {
        (**(code **)(*param_13 + 0x20))(param_13);
      }
      *(undefined1 *)(param_7 + 0x18) = param_14;
      lVar28 = thunk_FUN_fffffff00a903010();
      param_7[0x19] = lVar28;
      if (lVar28 == 0) {
        auVar3._8_8_ = extraout_var_01;
        auVar3._0_8_ = extraout_d0_01;
        FUN_fffffff009c7a9b0(auVar3,param_2,uVar32,uVar34,param_5,param_6);
      }
      else {
        lVar28 = thunk_FUN_fffffff00a903010();
        param_7[0x20] = lVar28;
        if (lVar28 == 0) {
          auVar4._8_8_ = extraout_var_02;
          auVar4._0_8_ = extraout_d0_02;
          FUN_fffffff009c7a96c(auVar4,param_2,uVar32,uVar34,param_5,param_6);
        }
        else {
          lVar28 = thunk_FUN_fffffff00a903010();
          param_7[0x1a] = lVar28;
          if (lVar28 == 0) {
            auVar5._8_8_ = extraout_var_03;
            auVar5._0_8_ = extraout_d0_03;
            FUN_fffffff009c7a928(auVar5,param_2,uVar32,uVar34,param_5,param_6);
          }
          else {
            lVar28 = thunk_FUN_fffffff00a903010();
            param_7[0x28] = lVar28;
            if (lVar28 == 0) {
              auVar6._8_8_ = extraout_var_04;
              auVar6._0_8_ = extraout_d0_04;
              FUN_fffffff009c7a8e4(auVar6,param_2,uVar32,uVar34,param_5,param_6);
            }
            else {
              lVar28 = thunk_FUN_fffffff00a903010();
              param_7[0x2a] = lVar28;
              if (lVar28 == 0) {
                auVar7._8_8_ = extraout_var_05;
                auVar7._0_8_ = extraout_d0_05;
                FUN_fffffff009c7a8a0(auVar7,param_2,uVar32,uVar34,param_5,param_6);
              }
              else {
                lVar28 = thunk_FUN_fffffff00a903010();
                param_7[0x2e] = lVar28;
                if (lVar28 == 0) {
                  auVar8._8_8_ = extraout_var_06;
                  auVar8._0_8_ = extraout_d0_06;
                  FUN_fffffff009c7a85c(auVar8,param_2,uVar32,uVar34,param_5,param_6);
                }
                else {
                  lVar28 = thunk_FUN_fffffff00a903010();
                  param_7[0x2f] = lVar28;
                  if (lVar28 == 0) {
                    auVar9._8_8_ = extraout_var_07;
                    auVar9._0_8_ = extraout_d0_07;
                    FUN_fffffff009c7a818(auVar9,param_2,uVar32,uVar34,param_5,param_6);
                  }
                  else {
                    *(undefined1 *)(param_7 + 0x11) = 1;
                    param_7[0x12] = 0;
                    *(undefined4 *)(param_7 + 0x1e) = 1;
                    puVar25 = PTR_DAT_fffffff00807b660;
                    auVar10._8_8_ = extraout_var_07;
                    auVar10._0_8_ = extraout_d0_07;
                    auVar19._4_12_ = auVar33;
                    auVar19._0_4_ = uVar32;
                    auVar22._4_12_ = auVar35;
                    auVar22._0_4_ = uVar34;
                    uVar29 = thunk_FUN_fffffff00a25a5ec
                                       (auVar10,param_2,auVar19,auVar22,param_5,param_6,
                                        *(ulong *)PTR_DAT_fffffff00807b660,param_7 + 0x23,0,
                                        (undefined ********)0x0,ppppppppuVar31);
                    if ((int)uVar29 == 0) {
                      auVar12._8_8_ = extraout_var_08;
                      auVar12._0_8_ = extraout_d0_08;
                      auVar20._4_12_ = auVar33;
                      auVar20._0_4_ = uVar32;
                      auVar23._4_12_ = auVar35;
                      auVar23._0_4_ = uVar34;
                      uVar29 = thunk_FUN_fffffff00a25a5ec
                                         (auVar12,param_2,auVar20,auVar23,param_5,param_6,
                                          *(ulong *)puVar25,param_7 + 0x24,0,(undefined ********)0x0
                                          ,ppppppppuVar31);
                      if ((int)uVar29 == 0) {
                        auVar14._8_8_ = extraout_var_09;
                        auVar14._0_8_ = extraout_d0_09;
                        auVar21._4_12_ = auVar33;
                        auVar21._0_4_ = uVar32;
                        auVar24._4_12_ = auVar35;
                        auVar24._0_4_ = uVar34;
                        uVar29 = thunk_FUN_fffffff00a25a5ec
                                           (auVar14,param_2,auVar21,auVar24,param_5,param_6,
                                            *(ulong *)puVar25,param_7 + 0x25,0,
                                            (undefined ********)0x0,ppppppppuVar31);
                        if ((int)uVar29 == 0) {
                          thunk_FUN_fffffff00a39c268(50000000,param_7 + 0x26);
                          plVar30 = thunk_FUN_fffffff00a89a1f4(1);
                          param_7[0x27] = (long)plVar30;
                          if (plVar30 == (long *)0x0) {
                            auVar16._8_8_ = extraout_var_11;
                            auVar16._0_8_ = extraout_d0_11;
                            FUN_fffffff009c7a7d4(auVar16,param_2,uVar32,uVar34,param_5,param_6);
                          }
                          else {
                            plVar30 = thunk_FUN_fffffff00a89a1f4(1);
                            param_7[0x29] = (long)plVar30;
                            if (plVar30 == (long *)0x0) {
                              auVar17._8_8_ = extraout_var_12;
                              auVar17._0_8_ = extraout_d0_12;
                              FUN_fffffff009c7a790(auVar17,param_2,uVar32,uVar34,param_5,param_6);
                            }
                            else {
                              (**(code **)(*param_9 + 0xa8))(param_9);
                              thunk_FUN_fffffff00a76d3ec
                                        ((undefined1 *)&local_c0,0x4f,(byte *)"%s%hu");
                              plVar30 = thunk_FUN_fffffff00a8d2200(&local_c0);
                              param_7[0x37] = (long)plVar30;
                              if (plVar30 != (long *)0x0) {
                                lVar28 = (**(code **)(*plVar30 + 0xa8))();
                                param_7[0x38] = lVar28;
                                *(undefined2 *)(param_7 + 0x21) = 0;
                                lVar28 = _DAT_fffffff0078aedc0;
                                param_7[0x1d] = _UNK_fffffff0078aedc8;
                                param_7[0x1c] = lVar28;
                                (**(code **)(*param_7 + 200))(param_7,"BSDPrefix",param_7[0x13]);
                                (**(code **)(*param_7 + 0xe0))
                                          (param_7,"BSDUnitNumber",(short)param_7[0x14],0x10);
                                (**(code **)(*param_7 + 0xd8))
                                          (param_7,"LinkActive",*(byte *)(param_7 + 0x1b) & 1);
                                (**(code **)(*param_7 + 0xe8))
                                          (param_7,"MACAddress",(undefined4 *)((long)param_7 + 0xa2)
                                           ,6);
                                (**(code **)(*param_7 + 0xe0))
                                          (param_7,"InterfaceState",(int)param_7[0x1e],0x20);
                                (**(code **)(*param_7 + 200))(param_7,"InterfaceName",param_7[0x37])
                                ;
                                (**(code **)(*param_7 + 0xd8))
                                          (param_7,"Builtin",*(byte *)(param_7 + 0x18) & 1);
                                uVar29 = 1;
                                goto LAB_fffffff009c59710;
                              }
                              auVar18._8_8_ = extraout_var_13;
                              auVar18._0_8_ = extraout_d0_13;
                              FUN_fffffff009c7a74c(auVar18,param_2,uVar32,uVar34,param_5,param_6);
                            }
                          }
                        }
                        else {
                          auVar15._8_8_ = extraout_var_10;
                          auVar15._0_8_ = extraout_d0_10;
                          FUN_fffffff009c7a708(auVar15,param_2,uVar32,uVar34,param_5,param_6);
                        }
                      }
                      else {
                        auVar13._8_8_ = extraout_var_09;
                        auVar13._0_8_ = extraout_d0_09;
                        FUN_fffffff009c7a6c4(auVar13,param_2,uVar32,uVar34,param_5,param_6);
                      }
                    }
                    else {
                      auVar11._8_8_ = extraout_var_08;
                      auVar11._0_8_ = extraout_d0_08;
                      FUN_fffffff009c7a680(auVar11,param_2,uVar32,uVar34,param_5,param_6);
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
  uVar29 = 0;
LAB_fffffff009c59710:
  if (*(long *)PTR_DAT_fffffff00807b630 == local_70) {
    return uVar29;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

