// FUN_fffffff009c31694 @ fffffff009c31694

/* WARNING: Removing unreachable block (ram,0xfffffff009c31f88) */

undefined8
FUN_fffffff009c31694
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7)

{
  uint *puVar1;
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
  bool bVar21;
  uint uVar22;
  int iVar23;
  undefined8 uVar24;
  long lVar25;
  long *plVar26;
  long extraout_x0;
  ulong uVar27;
  ulong uVar28;
  long *plVar29;
  long *plVar30;
  ulong extraout_x0_00;
  char *pcVar31;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong *puVar32;
  undefined8 uVar33;
  undefined *puVar34;
  uint uVar35;
  undefined4 uVar36;
  undefined8 extraout_d0;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_00;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined1 auVar37 [16];
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined1 auVar38 [16];
  undefined8 extraout_var_06;
  undefined4 uVar39;
  undefined1 auVar40 [12];
  undefined4 uVar41;
  undefined1 auVar42 [12];
  byte *local_b0;
  long *plStack_a8;
  byte local_99;
  ulong local_98;
  ulong local_90;
  undefined1 *local_88;
  uint local_7c;
  ulong local_78;
  undefined1 *local_70;
  long local_68;
  
  uVar41 = param_4._0_4_;
  auVar42 = param_4._4_12_;
  uVar39 = param_3._0_4_;
  auVar40 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar24 = (**(code **)(PTR_DAT_fffffff00806ca38 + 0x2c0))(param_1._0_8_);
  lVar25 = thunk_FUN_fffffff00a39bc88();
  param_7[0x89] = lVar25;
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x28] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x29] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  param_7[0x12] = 0;
  param_7[0x13] = (long)(param_7 + 0x12);
  param_7[0x31] = 0;
  param_7[0x32] = (long)(param_7 + 0x31);
  param_7[0x73] = 0;
  param_7[0x74] = (long)(param_7 + 0x73);
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x75] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  plVar26 = thunk_FUN_fffffff00a8a10d8(1);
  if ((long *)param_7[0x2b] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x2b] + 0x28))();
  }
  param_7[0x2b] = (long)plVar26;
  if (plVar26 == (long *)0x0) goto LAB_fffffff009c31d88;
  param_7[0x7b] = 0;
  param_7[0x7c] = (long)(param_7 + 0x7b);
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x76] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x77] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  auVar2._8_8_ = extraout_var;
  auVar2._0_8_ = extraout_d0;
  auVar9._4_12_ = auVar40;
  auVar9._0_4_ = uVar39;
  auVar15._4_12_ = auVar42;
  auVar15._0_4_ = uVar41;
  plVar26 = thunk_FUN_fffffff00a95c9e4(auVar2,param_2,auVar9,auVar15,param_5,param_6);
  if ((long *)param_7[0x91] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x91] + 0x28))();
  }
  param_7[0x91] = (long)plVar26;
  plVar26 = thunk_FUN_fffffff00a95ebd8(param_7,&LAB_fffffff009c31fb8,0,0);
  if ((long *)param_7[0x92] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x92] + 0x28))();
  }
  param_7[0x92] = (long)plVar26;
  (**(code **)(*(long *)param_7[0x91] + 0xa0))((long *)param_7[0x91],plVar26);
  (**(code **)(*(long *)param_7[0x92] + 0xb0))();
  *(undefined1 *)(param_7 + 0x11) = 1;
  lVar25 = thunk_FUN_fffffff00a903010();
  param_7[0x3e] = lVar25;
  if (lVar25 == 0) goto LAB_fffffff009c31d88;
  plVar26 = thunk_FUN_fffffff00a89a1f4(1);
  auVar37._8_8_ = extraout_var_00;
  auVar37._0_8_ = extraout_d0_00;
  if ((long *)param_7[0x3f] != (long *)0x0) {
    auVar37 = (**(code **)(*(long *)param_7[0x3f] + 0x28))();
  }
  param_7[0x3f] = (long)plVar26;
  auVar10._4_12_ = auVar40;
  auVar10._0_4_ = uVar39;
  auVar16._4_12_ = auVar42;
  auVar16._0_4_ = uVar41;
  thunk_FUN_fffffff00a27b094(auVar37,param_2,auVar10,auVar16,param_5,param_6,-0xff63cdff0,param_7,1)
  ;
  param_7[0x40] = extraout_x0;
  if (extraout_x0 == 0) goto LAB_fffffff009c31d88;
  local_78 = 8;
  local_70 = &DAT_aaaaaaaaaaaaaaaa;
  puVar32 = &local_78;
  uVar33 = 0;
  puVar34 = (undefined *)0x0;
  uVar27 = thunk_FUN_fffffff00a746368(0xfffffff00789c442,&local_70,puVar32,0,0);
  if ((int)uVar27 == 0) {
    if (local_70 == (undefined1 *)0x0) {
      local_70 = (undefined1 *)0x80;
    }
    *(int *)(param_7 + 0x15) = (int)local_70;
    iVar23 = (int)local_70 + -1;
  }
  else {
    *(undefined4 *)(param_7 + 0x15) = 0x20;
    iVar23 = 0x1f;
  }
  *(int *)((long)param_7 + 0xac) = iVar23;
  *(int *)(param_7 + 0x16) = iVar23;
  param_7[0x18] = 0x7fffffff;
  param_7[0x17] = 0x7fffffff;
  param_7[0x19] = 0x7fffffff;
  param_7[0x1c] = 0;
  auVar3._8_8_ = 0x7fffffff;
  auVar3._0_8_ = 0x7fffffff;
  auVar11._4_12_ = auVar40;
  auVar11._0_4_ = uVar39;
  auVar17._4_12_ = auVar42;
  auVar17._0_4_ = uVar41;
  FUN_fffffff009c32250
            (auVar3,param_2,auVar11,auVar17,param_5,param_6,(long)param_7,extraout_x1,puVar32,uVar33
             ,puVar34);
  param_7[0x27] = 0;
  local_7c = 0xaaaaaaaa;
  local_88 = &DAT_aaaaaaaaaaaaaaaa;
  auVar4._8_8_ = extraout_var_01;
  auVar4._0_8_ = extraout_d0_01;
  auVar12._4_12_ = auVar40;
  auVar12._0_4_ = uVar39;
  auVar18._4_12_ = auVar42;
  auVar18._0_4_ = uVar41;
  uVar27 = FUN_fffffff009c32528
                     (auVar4,param_2,auVar12,auVar18,param_5,param_6,(long)param_7,0,&local_7c,
                      &local_88);
  if ((uVar27 & 1) == 0) {
    auVar5._8_8_ = extraout_var_02;
    auVar5._0_8_ = extraout_d0_02;
    thunk_FUN_fffffff00a8df19c
              (auVar5,param_2,uVar39,uVar41,param_5,param_6,&MACH_HEADER,
               (short *)PTR_DAT_fffffff00806ca48,0x11,
               (byte *)"IOSurfaceRoot: Initial shared event memory alloc failed\n");
  }
  local_98 = 8;
  local_90 = 0;
  uVar28 = thunk_FUN_fffffff00a746368(0xfffffff00789c453,&local_90,&local_98,0,0);
  uVar27 = local_90;
  if (local_90 >> 0x23 == 0) {
    uVar27 = local_90 >> 2;
  }
  if ((int)uVar28 != 0) {
    uVar27 = 0x10000000;
  }
  param_7[0x33] = uVar27;
  *(undefined1 *)((long)param_7 + 0x89) = 1;
  lVar25 = thunk_FUN_fffffff00a39bc88();
  param_7[0x8a] = lVar25;
  puVar34 = PTR_DAT_fffffff00806ca50;
  plVar26 = thunk_FUN_fffffff00a90a044
                      ("/",*(long *)PTR_DAT_fffffff00806ca50,0,(int *)0x0,(long *)0x0);
  bVar21 = thunk_FUN_fffffff00a91280c(plVar26);
  if (bVar21) {
    *(undefined1 *)((long)param_7 + 0x89) = 0;
    (**(code **)(*param_7 + 0xd8))(param_7,"iosurface-non-coherent",1);
  }
  param_7[0x2d] = 0;
  *(undefined4 *)(param_7 + 0x2e) = 0;
  local_99 = 0;
  *(undefined1 *)(param_7 + 0x93) = 0;
  bVar21 = thunk_FUN_fffffff00a91280c(plVar26);
  if (bVar21) {
    local_99 = 1;
  }
  bVar21 = thunk_FUN_fffffff00a91280c(plVar26);
  if (bVar21) {
    *(undefined1 *)(param_7 + 0x93) = 1;
  }
  local_b0 = &local_99;
  plStack_a8 = param_7;
  plVar29 = thunk_FUN_fffffff00a90a044("/vram",*(long *)puVar34,0,(int *)0x0,(long *)0x0);
  if (plVar29 != (long *)0x0) {
    uVar22 = FUN_fffffff009c325b0(plVar29);
    *(uint *)(param_7 + 0x2e) = uVar22;
    if (uVar22 == 0) {
      auVar6._8_8_ = extraout_var_03;
      auVar6._0_8_ = extraout_d0_03;
      thunk_FUN_fffffff00a8df19c
                (auVar6,param_2,uVar39,uVar41,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0x10,
                 (byte *)
                 "IOSurface: couldn\'t count /vram\'s reg tuples; assuming a single carveout\n");
      uVar22 = 1;
    }
    iVar23 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
    if (iVar23 != 0) {
      auVar7._8_8_ = extraout_var_04;
      auVar7._0_8_ = extraout_d0_04;
      thunk_FUN_fffffff00a8df19c
                (auVar7,param_2,uVar39,uVar41,param_5,param_6,&MACH_HEADER,
                 (short *)PTR_DAT_fffffff00806ca48,0,
                 (byte *)"IOSurface: discovered %u display carveout(s) in /vram\n");
    }
    uVar35 = 0;
    do {
      plVar30 = (long *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff00806b530);
      if (plVar30 != (long *)0x0) {
        uVar36 = 0x100;
        if ((local_99 & 1) == 0) {
          uVar36 = 0x400;
        }
        *(undefined4 *)(plVar30 + 2) = uVar36;
        *(uint *)((long)plVar30 + 0x14) = uVar35;
        *(int *)(param_7 + 0x2d) = (int)param_7[0x2d] + 1;
        *plVar30 = param_7[0x2c];
        plVar30[1] = (long)&DAT_fffffff00789c4c4;
        param_7[0x2c] = (long)plVar30;
      }
      uVar35 = uVar35 + 1;
    } while (uVar22 != uVar35);
  }
  uVar27 = 0;
  plVar30 = thunk_FUN_fffffff00a90a044("/sma",*(long *)puVar34,0,(int *)0x0,(long *)0x0);
  auVar38._8_8_ = extraout_var_05;
  auVar38._0_8_ = extraout_d0_05;
  if (plVar30 != (long *)0x0) {
    (**(code **)(*plVar30 + 0x28))();
    uVar27 = 0;
    auVar38 = FUN_fffffff009c32718(&local_b0,&DAT_fffffff00789c4ce,0);
  }
  param_7[0x2f] = (long)FUN_fffffff009c32794;
  auVar13._4_12_ = auVar40;
  auVar13._0_4_ = uVar39;
  auVar19._4_12_ = auVar42;
  auVar19._0_4_ = uVar41;
  thunk_FUN_fffffff00a27b29c(auVar38,param_2,auVar13,auVar19,param_5,param_6,-0xff63cd86c,param_7);
  param_7[0x30] = extraout_x0_00;
  thunk_FUN_fffffff00a27b760(extraout_x0_00,extraout_x1_00,uVar27);
  lVar25 = thunk_FUN_fffffff00a39bc88();
  param_7[0x8b] = lVar25;
  param_7[0x3a] = 0;
  param_7[0x3b] = (long)(param_7 + 0x3a);
  auVar8._8_8_ = extraout_var_06;
  auVar8._0_8_ = extraout_d0_06;
  auVar14._4_12_ = auVar40;
  auVar14._0_4_ = uVar39;
  auVar20._4_12_ = auVar42;
  auVar20._0_4_ = uVar41;
  plVar30 = thunk_FUN_fffffff00a95c9e4(auVar8,param_2,auVar14,auVar20,param_5,param_6);
  if ((long *)param_7[0x36] != (long *)0x0) {
    (**(code **)(*(long *)param_7[0x36] + 0x28))();
  }
  param_7[0x36] = (long)plVar30;
  if (plVar30 == (long *)0x0) {
LAB_fffffff009c31d3c:
    uVar24 = 0;
  }
  else {
    plVar30 = thunk_FUN_fffffff00a960074(param_7,0);
    if ((long *)param_7[0x37] != (long *)0x0) {
      (**(code **)(*(long *)param_7[0x37] + 0x28))();
    }
    param_7[0x37] = (long)plVar30;
    if (plVar30 == (long *)0x0) goto LAB_fffffff009c31d3c;
    lVar25 = thunk_FUN_fffffff00a903010();
    param_7[0x39] = lVar25;
    if (lVar25 == 0) goto LAB_fffffff009c31d3c;
    plVar30 = thunk_FUN_fffffff00a95ebd8(param_7,&LAB_fffffff009c32a28,0,0);
    if ((long *)param_7[0x38] != (long *)0x0) {
      (**(code **)(*(long *)param_7[0x38] + 0x28))();
    }
    param_7[0x38] = (long)plVar30;
    if (((plVar30 == (long *)0x0) ||
        (iVar23 = (**(code **)(*(long *)param_7[0x36] + 0xa0))((long *)param_7[0x36],plVar30),
        iVar23 != 0)) ||
       (iVar23 = (**(code **)(*(long *)param_7[0x36] + 0xa0))((long *)param_7[0x36],param_7[0x37]),
       iVar23 != 0)) goto LAB_fffffff009c31d3c;
    (**(code **)(*(long *)param_7[0x38] + 0xb0))();
    (**(code **)(*(long *)param_7[0x37] + 0xb0))();
    lVar25 = thunk_FUN_fffffff00a39bc88();
    param_7[0x8c] = lVar25;
    *(undefined1 *)(param_7 + 0x34) = 0;
    iVar23 = thunk_FUN_fffffff00aa14b0c
                       ((byte *)"iosurface_timestamp_enable",(uint *)(param_7 + 0x34),1);
    if (iVar23 == 0) {
      *(undefined1 *)(param_7 + 0x34) = 0;
    }
    puVar1 = (uint *)(param_7 + 0x72);
    iVar23 = thunk_FUN_fffffff00aa14b0c((byte *)"iofence_ddd",puVar1,4);
    if ((iVar23 != 0) && (0x10 < *puVar1)) {
      *puVar1 = 0x10;
    }
    puVar1 = (uint *)((long)param_7 + 0x1a4);
    iVar23 = thunk_FUN_fffffff00aa14b0c((byte *)"iosurface_debug",puVar1,4);
    if (iVar23 == 0) {
      *puVar1 = 0x10;
LAB_fffffff009c31eb0:
      pcVar31 = "IOSurface disallowing global lookups\n";
    }
    else {
      uVar22 = *puVar1;
      if ((uVar22 >> 1 & 1) != 0) {
        thunk_FUN_fffffff00aa172c0((byte *)"IOSurface disallowing pixel size casting by default\n");
        uVar22 = *puVar1;
      }
      if ((uVar22 >> 2 & 1) == 0) goto LAB_fffffff009c31eb0;
      pcVar31 = "IOSurface allowing global lookups (with warnings)\n";
    }
    thunk_FUN_fffffff00aa172c0((byte *)pcVar31);
    if ((*(byte *)puVar1 >> 3 & 1) != 0) {
      *(uint *)(param_7 + 0x35) = *(uint *)(param_7 + 0x35) | 0x20;
      thunk_FUN_fffffff00aa172c0((byte *)"IOSurface using pageable shmems\n");
    }
    lVar25 = thunk_FUN_fffffff00a39bc88();
    param_7[0x8d] = lVar25;
    plVar30 = thunk_FUN_fffffff00a966c64
                        ((ulong)(*(uint *)(param_7 + 0x35) | 0x10000),
                         *(undefined8 *)PTR_DAT_fffffff00806ca78,
                         *(undefined8 *)PTR_DAT_fffffff00806ca78);
    if ((long *)param_7[0x3d] != (long *)0x0) {
      (**(code **)(*(long *)param_7[0x3d] + 0x28))();
    }
    param_7[0x3d] = (long)plVar30;
    (**(code **)(*param_7 + 0x210))(param_7,"IOCoreSurfaceRoot",0);
    lVar25 = thunk_FUN_fffffff00a39bc88();
    param_7[0x8e] = lVar25;
    (**(code **)(*param_7 + 0x2a0))(*param_7 + 0x2a0,param_7,0);
    lVar25 = thunk_FUN_fffffff00a39bc88();
    param_7[0x8f] = lVar25;
  }
  if (plVar29 != (long *)0x0) {
    (**(code **)(*plVar29 + 0x28))();
  }
  if (plVar26 != (long *)0x0) {
    (**(code **)(*plVar26 + 0x28))(plVar26);
  }
LAB_fffffff009c31d88:
  lVar25 = thunk_FUN_fffffff00a39bc88();
  param_7[0x90] = lVar25;
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar24;
}

