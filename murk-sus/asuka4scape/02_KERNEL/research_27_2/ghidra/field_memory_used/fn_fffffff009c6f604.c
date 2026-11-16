// FUN_fffffff009c6f604 @ fffffff009c6f604

undefined8
FUN_fffffff009c6f604
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long *param_8)

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
  undefined *puVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  long *plVar14;
  long lVar15;
  ulong uVar16;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  long local_38;
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  *(undefined **)(param_7 + 0x88) = &DAT_fffffff0078a321e;
  *(undefined8 *)(param_7 + 0x98) = 0;
  *(undefined8 *)(param_7 + 0x90) = 0;
  *(undefined4 *)(param_7 + 0xa0) = 0;
  *(undefined8 *)(param_7 + 0xb0) = 0;
  *(undefined8 *)(param_7 + 0xa8) = 0;
  *(undefined8 *)(param_7 + 0xc0) = 0;
  *(undefined8 *)(param_7 + 0xb8) = 0;
  *(undefined8 *)(param_7 + 0xe0) = 0xffffffffffffffff;
  local_38 = 0;
  iVar11 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_tsnotifytest",(uint *)&local_38,8);
  *(bool *)(param_7 + 0xd8) = iVar11 != 0 && local_38 != 0;
  puVar13 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff00807ad60);
  *(undefined8 **)(param_7 + 0xf8) = puVar13;
  if (puVar13 == (undefined8 *)0x0) {
    auVar7._8_8_ = extraout_var;
    auVar7._0_8_ = extraout_d0;
    FUN_fffffff009c7ca84(auVar7,param_2,uVar17,uVar19,param_5,param_6);
  }
  else {
    puVar13[1] = 0xffffffff;
    *puVar13 = 0xffffffff;
    if (param_8 != (long *)0x0) {
      plVar14 = (long *)(**(code **)(*param_8 + 0x138))(param_8,"ClockName");
      plVar14 = thunk_FUN_fffffff00a894f30(plVar14,*(long *)PTR_PTR_fffffff00807b5f0);
      if (plVar14 != (long *)0x0) {
        *(long **)(param_7 + 0x98) = plVar14;
        (**(code **)(*plVar14 + 0x20))();
      }
      plVar14 = (long *)(**(code **)(*param_8 + 0x138))(param_8,"ClockTransportType");
      plVar14 = thunk_FUN_fffffff00a894f30(plVar14,*(long *)PTR_PTR_fffffff00807b5e0);
      if (plVar14 != (long *)0x0) {
        uVar12 = (**(code **)(*plVar14 + 0xa8))();
        *(undefined4 *)(param_7 + 0xa0) = uVar12;
      }
    }
    plVar14 = thunk_FUN_fffffff00a89a1f4(1);
    *(long **)(param_7 + 0xa8) = plVar14;
    puVar10 = PTR_DAT_fffffff00807b638;
    if (plVar14 == (long *)0x0) {
      auVar1._8_8_ = extraout_var_00;
      auVar1._0_8_ = extraout_d0_00;
      auVar7 = thunk_FUN_fffffff00a8df19c
                         (auVar1,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,
                          (short *)PTR_DAT_fffffff00807b638,0,
                          (byte *)
                          " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                         );
      thunk_FUN_fffffff00a8df19c
                (auVar7,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,(short *)puVar10,0,
                 (byte *)"Failed to allocate notification clients array\n");
    }
    else {
      lVar15 = thunk_FUN_fffffff00a903010();
      *(long *)(param_7 + 0xb0) = lVar15;
      puVar10 = PTR_DAT_fffffff00807b638;
      if (lVar15 == 0) {
        auVar2._8_8_ = extraout_var_01;
        auVar2._0_8_ = extraout_d0_01;
        auVar7 = thunk_FUN_fffffff00a8df19c
                           (auVar2,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,
                            (short *)PTR_DAT_fffffff00807b638,0,
                            (byte *)
                            " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                           );
        thunk_FUN_fffffff00a8df19c
                  (auVar7,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,(short *)puVar10,0,
                   (byte *)"Failed to allocate notification clients lock\n");
      }
      else {
        plVar14 = thunk_FUN_fffffff00a89a1f4(1);
        *(long **)(param_7 + 200) = plVar14;
        if (plVar14 == (long *)0x0) {
          auVar3._8_8_ = extraout_var_02;
          auVar3._0_8_ = extraout_d0_02;
          FUN_fffffff009c7ca40(auVar3,param_2,uVar17,uVar19,param_5,param_6);
        }
        else {
          lVar15 = thunk_FUN_fffffff00a903010();
          *(long *)(param_7 + 0xd0) = lVar15;
          if (lVar15 == 0) {
            auVar4._8_8_ = extraout_var_03;
            auVar4._0_8_ = extraout_d0_03;
            FUN_fffffff009c7c9fc(auVar4,param_2,uVar17,uVar19,param_5,param_6);
          }
          else {
            auVar5._8_8_ = extraout_var_03;
            auVar5._0_8_ = extraout_d0_03;
            auVar8._4_12_ = auVar18;
            auVar8._0_4_ = uVar17;
            auVar9._4_12_ = auVar20;
            auVar9._0_4_ = uVar19;
            plVar14 = thunk_FUN_fffffff00a95c9e4(auVar5,param_2,auVar8,auVar9,param_5,param_6);
            *(long **)(param_7 + 0xe8) = plVar14;
            puVar10 = PTR_DAT_fffffff00807b638;
            if (plVar14 == (long *)0x0) {
              auVar6._8_8_ = extraout_var_04;
              auVar6._0_8_ = extraout_d0_04;
              auVar7 = thunk_FUN_fffffff00a8df19c
                                 (auVar6,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,
                                  (short *)PTR_DAT_fffffff00807b638,0,
                                  (byte *)
                                  " IOTimeSyncFamily assertion FailIfNULL \"%s\" failed in %s at line %d goto Exit. "
                                 );
              thunk_FUN_fffffff00a8df19c
                        (auVar7,param_2,uVar17,uVar19,param_5,param_6,&MACH_HEADER,(short *)puVar10,
                         0,(byte *)"Failed to allocate work loop\n");
            }
            else {
              uVar16 = (**(code **)(PTR_DAT_fffffff00807b628 + 0xb8))(param_7,param_8);
              if ((uVar16 & 1) != 0) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
  if (*(long **)(param_7 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x98) + 0x28))();
    *(undefined8 *)(param_7 + 0x98) = 0;
  }
  if (*(long **)(param_7 + 0xa8) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0xa8) + 0x28))();
    *(undefined8 *)(param_7 + 0xa8) = 0;
  }
  if (*(undefined8 **)(param_7 + 0xb0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xb0));
    *(undefined8 *)(param_7 + 0xb0) = 0;
  }
  if (*(long **)(param_7 + 200) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 200) + 0x28))();
    *(undefined8 *)(param_7 + 200) = 0;
  }
  if (*(undefined8 **)(param_7 + 0xd0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0xd0));
    *(undefined8 *)(param_7 + 0xd0) = 0;
  }
  return 0;
}

