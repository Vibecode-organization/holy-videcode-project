// FUN_fffffff009c916b0 @ fffffff009c916b0

/* WARNING: Removing unreachable block (ram,0xfffffff009c92010) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c920fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c91a4c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c91c34) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c9192c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c91cdc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c91fc0) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c921a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c917e4) */

undefined8
FUN_fffffff009c916b0
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,long *param_8)

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
  bool bVar13;
  uint uVar14;
  int iVar15;
  long lVar16;
  undefined8 uVar17;
  long *plVar18;
  char *pcVar19;
  ulong uVar20;
  long *plVar21;
  long *extraout_x0;
  long extraout_x0_00;
  undefined1 uVar22;
  short *psVar23;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined1 auVar24 [16];
  undefined4 uVar25;
  undefined1 auVar26 [12];
  undefined4 uVar27;
  undefined1 auVar28 [12];
  ulong local_60;
  uint local_58;
  uint local_54;
  undefined8 local_50;
  long local_48;
  
  uVar27 = param_4._0_4_;
  auVar28 = param_4._4_12_;
  uVar25 = param_3._0_4_;
  auVar26 = param_3._4_12_;
  local_48 = *(long *)PTR_DAT_fffffff00807faf0;
  lVar16 = (**(code **)(*param_7 + 0x38))(param_1._0_8_);
  uVar14 = thunk_FUN_fffffff00944ede4(lVar16,*(long *)PTR_PTR_fffffff00807fac0,0);
  *(uint *)((long)param_7 + 500) = *(uint *)((long)param_7 + 500) | uVar14;
  local_54 = 0;
  thunk_FUN_fffffff00aa14b0c((byte *)"IOUSBDeviceController-debug",&local_54,4);
  *(uint *)((long)param_7 + 500) = *(uint *)((long)param_7 + 500) | local_54;
  param_7[0x81] = 0;
  param_7[0x80] = 0;
  param_7[0x83] = 0;
  param_7[0x82] = 0;
  param_7[0x85] = 0;
  param_7[0x84] = 0;
  thunk_FUN_fffffff00aa14b0c((byte *)"usb_dev_nmi",(uint *)((long)param_7 + 300),4);
  thunk_FUN_fffffff00aa14b0c((byte *)"usb_dev_reset",(uint *)(param_7 + 0x26),4);
  thunk_FUN_fffffff00aa14b0c((byte *)"usb_max_current",(uint *)(param_7 + 0x25),4);
  thunk_FUN_fffffff00aa14b0c((byte *)"usb_compliance_mode",(uint *)((long)param_7 + 0x1fc),4);
  thunk_FUN_fffffff00aa65b10(param_7 + 0x40,(undefined8 *)&DAT_fffffff0078b2b88,0x1e0);
  local_58 = 0;
  lVar16 = (**(code **)(*param_8 + 0x118))(*param_8 + 0x118,param_8,"usb-device-slp-ddr");
  if ((lVar16 != **(long **)PTR_PTR_fffffff00807fb18) &&
     (iVar15 = thunk_FUN_fffffff00aa14b0c((byte *)"enable-acsleep",&local_58,4), iVar15 == 0)) {
    param_7[0x71] = param_7[0x71] | 0x40;
  }
  uVar17 = (**(code **)(PTR_DAT_fffffff00807fae8 + 0x2c0))(param_7,param_8);
  if ((int)uVar17 == 0) goto LAB_fffffff009c9224c;
  param_7[0x17] = (long)param_8;
  auVar1 = (**(code **)(*param_8 + 0x20))(param_8);
  auVar3._4_12_ = auVar26;
  auVar3._0_4_ = uVar25;
  auVar8._4_12_ = auVar28;
  auVar8._0_4_ = uVar27;
  FUN_fffffff009c8fd9c(auVar1,param_2,auVar3,auVar8,param_5,param_6,param_7,param_8);
  plVar18 = thunk_FUN_fffffff00a8cf1e8((long)param_7,-0xff636dd80,0);
  if (plVar18 == (long *)0x0) {
    if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
      if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
         (bVar13 = thunk_FUN_fffffff00a394140(), !bVar13)) {
        psVar23 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,uVar25,uVar27,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)"%s@%s: %s::%s: Unable to allocate serializer\n");
      }
      else {
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        (**(code **)(*param_7 + 0x218))(param_7,0);
        pcVar19 = "%s@%s: %s::%s: Unable to allocate serializer\n";
LAB_fffffff009c920a4:
        thunk_FUN_fffffff00a9029a0((byte *)pcVar19);
      }
    }
  }
  else {
    (**(code **)(*param_7 + 200))(param_7,"CurrentState",plVar18);
    (**(code **)(*plVar18 + 0x28))(plVar18);
    plVar18 = (long *)(**(code **)(*param_8 + 0x118))(*param_8 + 0x118,param_8,"bus-number");
    plVar18 = thunk_FUN_fffffff00a894f30(plVar18,*(long *)PTR_PTR_fffffff00807fa88);
    if (plVar18 != (long *)0x0) {
      (**(code **)(*plVar18 + 0xd8))();
    }
    local_50 = 0;
    thunk_FUN_fffffff00a76d3ec((undefined1 *)&local_50,8,&DAT_fffffff0078b0e27);
    (**(code **)(*param_7 + 0x230))(*param_7 + 0x230,param_7,&local_50,0);
    local_60 = 4;
    uVar20 = thunk_FUN_fffffff00a746368(0xfffffff0078b0e2a,param_7 + 0x3e,&local_60,0,0);
    if ((int)uVar20 != 0) {
      *(undefined4 *)(param_7 + 0x3e) = 0x40;
    }
    plVar18 = thunk_FUN_fffffff00a960074(param_7,0);
    plVar21 = (long *)(**(code **)(*param_7 + 0x378))(param_7);
    auVar1 = (**(code **)(*plVar21 + 0xa0))(plVar21,plVar18);
    param_7[0x11] = (long)plVar18;
    auVar4._4_12_ = auVar26;
    auVar4._0_4_ = uVar25;
    auVar9._4_12_ = auVar28;
    auVar9._0_4_ = uVar27;
    thunk_FUN_fffffff00a96c25c(auVar1,param_2,auVar4,auVar9,param_5,param_6,param_8);
    param_7[0x7e] = (long)extraout_x0;
    if (extraout_x0 == (long *)0x0) {
      if ((*(uint *)((long)param_7 + 500) >> 3 & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) == 0) ||
           (bVar13 = thunk_FUN_fffffff00a394140(), !bVar13)) {
          psVar23 = *(short **)PTR_DAT_fffffff00807fa80;
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
          thunk_FUN_fffffff00a8df19c
                    (auVar1,param_2,uVar25,uVar27,param_5,param_6,&MACH_HEADER,psVar23,0,
                     (byte *)"%s@%s: %s::%s: did not find a mapper\n");
        }
        else {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          thunk_FUN_fffffff00a9029a0((byte *)"%s@%s: %s::%s: did not find a mapper\n");
        }
      }
    }
    else {
      uVar17 = (**(code **)(*extraout_x0 + 0x548))();
      (**(code **)(*param_7 + 0xe0))(param_7,"MapperPageSize",uVar17,0x40);
    }
    uVar17 = (**(code **)(*param_7 + 0x378))(param_7);
    plVar18 = thunk_FUN_fffffff00a9617a0(uVar17);
    param_7[0x7d] = (long)plVar18;
    if (plVar18 == (long *)0x0) {
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) != 0) &&
           (bVar13 = thunk_FUN_fffffff00a394140(), bVar13)) {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar19 = "%s@%s: %s::%s: Unable to allocate IOCommandPool\n";
          goto LAB_fffffff009c920a4;
        }
        psVar23 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,uVar25,uVar27,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)"%s@%s: %s::%s: Unable to allocate IOCommandPool\n");
      }
    }
    else {
      auVar1._8_8_ = extraout_var;
      auVar1._0_8_ = extraout_d0;
      auVar5._4_12_ = auVar26;
      auVar5._0_4_ = uVar25;
      auVar10._4_12_ = auVar28;
      auVar10._0_4_ = uVar27;
      thunk_FUN_fffffff00a27b0a0
                (auVar1,param_2,auVar5,auVar10,param_5,param_6,-0xff635a78c,param_7,0,1);
      param_7[0x22] = extraout_x0_00;
      if (extraout_x0_00 != 0) {
        plVar18 = (long *)param_7[0x7e];
        if ((plVar18 == (long *)0x0) ||
           (lVar16 = (**(code **)(*plVar18 + 0x130))
                               (plVar18,"allow-subpage-mapping",
                                *(undefined8 *)PTR_DAT_fffffff00807fb08,3), lVar16 == 0)) {
          uVar22 = 0;
        }
        else {
          uVar22 = 1;
        }
        *(undefined1 *)(param_7 + 0x7f) = uVar22;
        thunk_FUN_fffffff00aa14b0c((byte *)"usb_enumeration_timeout",(uint *)(param_7 + 0x33),4);
        auVar24._8_8_ = extraout_var_00;
        auVar24._0_8_ = extraout_d0_00;
        if ((int)param_7[0x33] != 0) {
          auVar2._8_8_ = extraout_var_00;
          auVar2._0_8_ = extraout_d0_00;
          auVar6._4_12_ = auVar26;
          auVar6._0_4_ = uVar25;
          auVar11._4_12_ = auVar28;
          auVar11._0_4_ = uVar27;
          plVar18 = thunk_FUN_fffffff00a96528c
                              (auVar2,param_2,auVar6,auVar11,param_5,param_6,param_7,
                               FUN_fffffff009c9268c);
          auVar24._8_8_ = extraout_var_01;
          auVar24._0_8_ = extraout_d0_01;
          param_7[0x32] = (long)plVar18;
          if (plVar18 != (long *)0x0) {
            plVar18 = (long *)(**(code **)(*param_7 + 0x378))(param_7);
            (**(code **)(*plVar18 + 0xa0))(plVar18,param_7[0x32]);
            auVar24 = (**(code **)(*(long *)param_7[0x32] + 0xb0))();
          }
        }
        auVar7._4_12_ = auVar26;
        auVar7._0_4_ = uVar25;
        auVar12._4_12_ = auVar28;
        auVar12._0_4_ = uVar27;
        plVar18 = thunk_FUN_fffffff00a96528c
                            (auVar24,param_2,auVar7,auVar12,param_5,param_6,param_7,
                             0xfffffff009c9283c);
        param_7[0x34] = (long)plVar18;
        if (plVar18 != (long *)0x0) {
          plVar18 = (long *)(**(code **)(*param_7 + 0x378))(param_7);
          (**(code **)(*plVar18 + 0xa0))(plVar18,param_7[0x34]);
          (**(code **)(*(long *)param_7[0x34] + 0xb0))();
        }
        lVar16 = *(long *)(*param_7 + 0x730);
        if ((lVar16 == 0) &&
           (lVar16 = thunk_FUN_fffffff00a894f04(param_7,-0xff636cf74), lVar16 == 0)) {
          lVar16 = 0;
        }
        lVar16 = thunk_FUN_fffffff00aa076f0(lVar16,param_7,0);
        param_7[0x12] = lVar16;
        plVar18 = (long *)thunk_FUN_fffffff00a92f600();
        thunk_FUN_fffffff00a94c5b8(plVar18,(long)param_7);
        uVar17 = 1;
        goto LAB_fffffff009c9224c;
      }
      if ((*(uint *)((long)param_7 + 500) & 1) != 0) {
        if (((*(uint *)((long)param_7 + 500) >> 0x1e & 1) != 0) &&
           (bVar13 = thunk_FUN_fffffff00a394140(), bVar13)) {
          (**(code **)(*param_7 + 0x1e8))(param_7,0);
          (**(code **)(*param_7 + 0x218))(param_7,0);
          pcVar19 = "%s@%s: %s::%s: Unable to allocate _remoteWakeThreadcall\n";
          goto LAB_fffffff009c920a4;
        }
        psVar23 = *(short **)PTR_DAT_fffffff00807fa80;
        (**(code **)(*param_7 + 0x1e8))(param_7,0);
        auVar1 = (**(code **)(*param_7 + 0x218))(*param_7 + 0x218,param_7,0);
        thunk_FUN_fffffff00a8df19c
                  (auVar1,param_2,uVar25,uVar27,param_5,param_6,&MACH_HEADER,psVar23,0,
                   (byte *)"%s@%s: %s::%s: Unable to allocate _remoteWakeThreadcall\n");
      }
    }
  }
  (**(code **)(*param_7 + 0x2b8))(param_7,param_8);
  uVar17 = 0;
LAB_fffffff009c9224c:
  if (*(long *)PTR_DAT_fffffff00807faf0 == local_48) {
    return uVar17;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

