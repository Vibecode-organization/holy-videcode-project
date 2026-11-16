// FUN_fffffff0085c24dc @ fffffff0085c24dc size=4 depth=0
// CALLERS:
//   fffffff00afc5bd5 ?
//   fffffff007d0db90 ?
// CALLS:

undefined8 FUN_fffffff0085c24dc(long *param_1,undefined8 param_2,long param_3)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  long *plVar4;
  long extraout_x16;
  long extraout_x16_00;
  long extraout_x16_01;
  long extraout_x16_02;
  long extraout_x16_03;
  long extraout_x16_04;
  long extraout_x16_05;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 extraout_q0_04 [16];
  undefined1 extraout_q0_05 [16];
  undefined1 extraout_q0_06 [16];
  undefined1 extraout_q0_07 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  undefined1 auVar7 [16];
  undefined1 uStack_41;
  
  uVar5 = 0xe00002bc;
  FUN_fffffff0085b57e4();
  auVar7 = FUN_fffffff0085b5668();
  thunk_FUN_fffffff00a8df19c
            (extraout_q0,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,0,
             (byte *)"Reading %u bytes from register 0x%02X...");
  bVar1 = FUN_fffffff0085b54c4(-0xff8c7c4ef);
  if (bVar1) {
    uVar6 = 0xe00002d9;
    if ((param_1 != (long *)0x0) && (uVar2 = thunk_FUN_fffffff00a92d93c(param_1), (uVar2 & 1) == 0))
    {
      FUN_fffffff0085b5700();
      lVar3 = (**(code **)(extraout_x16 + 0x370))(param_1);
      uVar6 = uVar5;
      if (lVar3 != 0) {
        FUN_fffffff0085b57d8();
        plVar4 = (long *)(**(code **)(extraout_x16_00 + 0x370))(param_1);
        lVar3 = (**(code **)(*plVar4 + 0x370))();
        if (lVar3 != 0) {
          FUN_fffffff0085b57d8();
          plVar4 = (long *)(**(code **)(extraout_x16_01 + 0x370))(param_1);
          (**(code **)(*plVar4 + 0x370))();
          auVar7 = FUN_fffffff0085b5774();
          plVar4 = thunk_FUN_fffffff00a894f30(auVar7._0_8_,auVar7._8_8_);
          if (plVar4 == (long *)0x0) {
            FUN_fffffff0085b57d8();
            lVar3 = (**(code **)(extraout_x16_03 + 0x370))(param_1);
            if (lVar3 == 0) {
              FUN_fffffff0085b5740();
              auVar7 = FUN_fffffff0085b5668();
              thunk_FUN_fffffff00a8df19c
                        (extraout_q0_04,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,0x10
                         ,(byte *)"%s: Failed to access provider");
            }
            else {
              FUN_fffffff0085b57d8();
              plVar4 = (long *)(**(code **)(extraout_x16_04 + 0x370))(param_1);
              plVar4 = thunk_FUN_fffffff00a894f30(plVar4,(long)PTR_DAT_fffffff007d0efd8);
              if (plVar4 == (long *)0x0) {
                FUN_fffffff0085b5740();
                auVar7 = FUN_fffffff0085b5668();
                thunk_FUN_fffffff00a8df19c
                          (extraout_q0_05,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,
                           0x10,(byte *)"%s: provider is not AppleAuthCPRelayInterface");
              }
              else {
                lVar3 = FUN_fffffff0085b5818(plVar4);
                if ((lVar3 != 0) || (lVar3 = FUN_fffffff0085b57f8(), lVar3 != 0)) {
                  FUN_fffffff0085b5700();
                  uVar6 = (**(code **)(extraout_x16_05 + 0x558))(param_1,2,1,&uStack_41,0,0);
                  if ((int)uVar6 == 0) {
                    thunk_FUN_fffffff00a902968(10);
                    uVar6 = (**(code **)(*param_1 + 0x558))
                                      (param_1,1,0,0,*(undefined4 *)(param_3 + 0x60),
                                       *(undefined8 *)(param_3 + 0x58));
                    if ((int)uVar6 == 0) {
                      auVar7 = FUN_fffffff0085b5668();
                      thunk_FUN_fffffff00a8df19c
                                (extraout_q0_01,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,
                                 auVar7._8_8_,0,(byte *)"%s: SMC read of %u bytes successful!");
                    }
                    else {
                      FUN_fffffff0085b5740();
                      auVar7 = FUN_fffffff0085b5668();
                      thunk_FUN_fffffff00a8df19c
                                (extraout_q0_07,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,
                                 auVar7._8_8_,0x10,(byte *)"%s: SMC read failure! (ret: %x)");
                    }
                  }
                  else {
                    FUN_fffffff0085b5740();
                    auVar7 = FUN_fffffff0085b5668();
                    thunk_FUN_fffffff00a8df19c
                              (extraout_q0_06,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,
                               auVar7._8_8_,0x10,(byte *)"%s: SMC write failure! (ret: %x)");
                  }
                }
              }
            }
          }
          else {
            uVar5 = FUN_fffffff0085af4f0();
            uVar6 = (**(code **)(extraout_x16_02 + 0x560))(uVar5,2,0,0,1,&uStack_41);
            if ((int)uVar6 == 0) {
              thunk_FUN_fffffff00a902968(10);
              uVar6 = (**(code **)(*plVar4 + 0x560))
                                (plVar4,1,0,0,*(undefined4 *)(param_3 + 0x60),
                                 *(undefined8 *)(param_3 + 0x58));
              if ((int)uVar6 == 0) {
                auVar7 = FUN_fffffff0085b5668();
                thunk_FUN_fffffff00a8df19c
                          (extraout_q0_00,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,0,
                           (byte *)"%s: I2C read of %u bytes successful!");
              }
              else {
                FUN_fffffff0085b5740();
                auVar7 = FUN_fffffff0085b5668();
                thunk_FUN_fffffff00a8df19c
                          (extraout_q0_03,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,
                           0x10,(byte *)"%s: I2C read failure! (ret: %x)");
              }
            }
            else {
              FUN_fffffff0085b5740();
              auVar7 = FUN_fffffff0085b5668();
              thunk_FUN_fffffff00a8df19c
                        (extraout_q0_02,in_q1,in_s2,in_s3,in_s4,in_s5,auVar7._0_8_,auVar7._8_8_,0x10
                         ,(byte *)"%s: I2C write failure! (ret: %x)");
            }
          }
        }
      }
    }
  }
  else {
    uVar6 = 0xe00002c1;
  }
  return uVar6;
}

