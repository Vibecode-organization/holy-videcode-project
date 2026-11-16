// FUN_fffffff009c71bcc @ fffffff009c71bcc

undefined8
FUN_fffffff009c71bcc
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint param_8,
          uint param_9,long param_10,undefined8 param_11)

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
  undefined *puVar22;
  undefined *puVar23;
  int iVar24;
  ulong uVar25;
  long lVar26;
  long *plVar27;
  undefined8 *puVar28;
  undefined8 uVar29;
  ulong uVar30;
  ulong uVar31;
  ulong *puVar32;
  long lVar33;
  ulong uVar34;
  ulong *puVar35;
  ulong uVar36;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_07;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined8 extraout_var_07;
  undefined1 auVar37 [16];
  undefined4 uVar38;
  undefined1 auVar39 [12];
  undefined4 uVar40;
  undefined1 auVar41 [12];
  undefined1 auVar42 [16];
  uint local_b4;
  long local_b0 [9];
  long local_68;
  
  uVar40 = param_4._0_4_;
  auVar41 = param_4._4_12_;
  uVar38 = param_3._0_4_;
  auVar39 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff00807b630;
  local_b4 = 0;
  if (param_8 < 100) {
    FUN_fffffff009c7d274(param_1,param_2,uVar38,uVar40,param_5,param_6);
  }
  else if (param_9 == 0) {
    FUN_fffffff009c7d230(param_1,param_2,uVar38,uVar40,param_5,param_6);
  }
  else if (param_9 < 5) {
    if (param_10 == 0) {
      FUN_fffffff009c7d1a8(param_1,param_2,uVar38,uVar40,param_5,param_6);
    }
    else {
      uVar25 = (**(code **)(PTR_DAT_fffffff00807b620 + 0x78))();
      if ((uVar25 & 1) == 0) {
        auVar42._8_8_ = extraout_var;
        auVar42._0_8_ = extraout_d0;
        FUN_fffffff009c7cf88(auVar42,param_2,uVar38,uVar40,param_5,param_6);
      }
      else {
        *(undefined8 *)(param_7 + 0xb8) = 0;
        *(undefined8 *)(param_7 + 0xc0) = 0;
        *(ulong *)(param_7 + 0x30) = (ulong)param_8;
        *(char *)(param_7 + 0x40) = (char)param_9;
        *(undefined8 *)(param_7 + 0xe8) = param_11;
        lVar26 = thunk_FUN_fffffff00a903010();
        *(long *)(param_7 + 0x28) = lVar26;
        if (lVar26 == 0) {
          auVar3._8_8_ = extraout_var_00;
          auVar3._0_8_ = extraout_d0_00;
          FUN_fffffff009c7d164(auVar3,param_2,uVar38,uVar40,param_5,param_6);
        }
        else {
          auVar1._8_8_ = 0;
          auVar1._0_8_ = *(ulong *)(param_7 + 0x30);
          puVar32 = (ulong *)(*(ulong *)(param_7 + 0x30) * 0x30);
          puVar35 = (ulong *)0x8000000000000000;
          if (SUB168(auVar1 * ZEXT816(0x30),8) == 0 && -1 < (long)puVar32) {
            puVar35 = puVar32;
          }
          auVar4._8_8_ = extraout_var_00;
          auVar4._0_8_ = extraout_d0_00;
          auVar14._4_12_ = auVar39;
          auVar14._0_4_ = uVar38;
          auVar18._4_12_ = auVar41;
          auVar18._0_4_ = uVar40;
          auVar42 = thunk_FUN_fffffff00a902750
                              (auVar4,param_2,auVar14,auVar18,param_5,param_6,0xfffffff00807b060,
                               puVar35);
          *(long *)(param_7 + 0x38) = auVar42._0_8_;
          if (auVar42._0_8_ == 0) {
            auVar5._8_8_ = extraout_var_01;
            auVar5._0_8_ = extraout_d0_01;
            FUN_fffffff009c7d120(auVar5,param_2,uVar38,uVar40,param_5,param_6);
          }
          else {
            auVar2._8_8_ = 0;
            auVar2._0_8_ = *(ulong *)(param_7 + 0x30);
            puVar32 = (ulong *)(*(ulong *)(param_7 + 0x30) * 0x18);
            puVar35 = (ulong *)0x8000000000000000;
            if (SUB168(auVar2 * ZEXT816(0x18),8) == 0 && -1 < (long)puVar32) {
              puVar35 = puVar32;
            }
            auVar6._8_8_ = extraout_var_01;
            auVar6._0_8_ = extraout_d0_01;
            auVar15._4_12_ = auVar39;
            auVar15._0_4_ = uVar38;
            auVar19._4_12_ = auVar41;
            auVar19._0_4_ = uVar40;
            auVar42 = thunk_FUN_fffffff00a902750
                                (auVar6,param_2,auVar15,auVar19,param_5,param_6,0xfffffff00807b0b0,
                                 puVar35);
            *(long *)(param_7 + 0x10) = auVar42._0_8_;
            puVar23 = PTR_DAT_fffffff00807b660;
            if (auVar42._0_8_ == 0) {
              auVar7._8_8_ = extraout_var_02;
              auVar7._0_8_ = extraout_d0_02;
              FUN_fffffff009c7d0dc(auVar7,param_2,uVar38,uVar40,param_5,param_6);
            }
            else {
              plVar27 = thunk_FUN_fffffff00a966900
                                  (*(undefined8 *)PTR_DAT_fffffff00807b660,0x10000,
                                   *(long *)(param_7 + 0x30) * 0x58,1);
              *(long **)(param_7 + 0x88) = plVar27;
              if (plVar27 == (long *)0x0) {
                auVar8._8_8_ = extraout_var_03;
                auVar8._0_8_ = extraout_d0_03;
                FUN_fffffff009c7d098(auVar8,param_2,uVar38,uVar40,param_5,param_6);
              }
              else {
                auVar9._8_8_ = extraout_var_03;
                auVar9._0_8_ = extraout_d0_03;
                auVar16._4_12_ = auVar39;
                auVar16._0_4_ = uVar38;
                auVar20._4_12_ = auVar41;
                auVar20._0_4_ = uVar40;
                plVar27 = (long *)thunk_FUN_fffffff00a970b64
                                            (auVar9,param_2,auVar16,auVar20,param_5,param_6,plVar27,
                                             *(long *)puVar23,0,(undefined ********)0x1,
                                             (undefined ********)0x0,0);
                *(long **)(param_7 + 0xb0) = plVar27;
                if (plVar27 != (long *)0x0) {
                  local_b0[5] = 0;
                  local_b0[4] = 0;
                  local_b0[7] = 0;
                  local_b0[6] = 0;
                  local_b0[1] = 0;
                  local_b0[0] = 0;
                  local_b0[3] = 0;
                  local_b0[2] = 0;
                  puVar28 = (undefined8 *)(**(code **)(*plVar27 + 0x78))();
                  uVar25 = (**(code **)(**(long **)(param_7 + 0xb0) + 0x88))();
                  thunk_FUN_fffffff00aa65cc0(puVar28,uVar25);
                  puVar22 = PTR_DAT_fffffff00807b5a8;
                  if (*(char *)(param_7 + 0x40) != '\0') {
                    uVar25 = 0;
                    do {
                      lVar26 = *(long *)(param_10 + uVar25 * 8);
                      *(long *)(param_7 + 0x48 + uVar25 * 8) = lVar26;
                      uVar30 = lVar26 * *(long *)(param_7 + 0x30);
                      if (*(long *)(param_7 + 0xe8) == 0) {
                        uVar31 = 1;
                      }
                      else {
                        uVar31 = (ulong)(1 << (ulong)(*(uint *)puVar22 & 0x1f));
                        uVar34 = 0;
                        if (uVar31 != 0) {
                          uVar34 = uVar30 / uVar31;
                        }
                        lVar33 = uVar30 - uVar34 * uVar31;
                        lVar26 = 0;
                        if (lVar33 != 0) {
                          lVar26 = uVar31 - lVar33;
                        }
                        uVar30 = lVar26 + uVar30;
                      }
                      plVar27 = thunk_FUN_fffffff00a966c64(0x10000,uVar30,uVar31);
                      *(long **)(param_7 + 0x68 + uVar25 * 8) = plVar27;
                      if (plVar27 == (long *)0x0) {
                        auVar11._8_8_ = extraout_var_05;
                        auVar11._0_8_ = extraout_d0_05;
                        FUN_fffffff009c7d010(auVar11,param_2,uVar38,uVar40,param_5,param_6);
                        goto LAB_fffffff009c72088;
                      }
                      auVar12._8_8_ = extraout_var_05;
                      auVar12._0_8_ = extraout_d0_05;
                      auVar17._4_12_ = auVar39;
                      auVar17._0_4_ = uVar38;
                      auVar21._4_12_ = auVar41;
                      auVar21._0_4_ = uVar40;
                      plVar27 = (long *)thunk_FUN_fffffff00a970b64
                                                  (auVar12,param_2,auVar17,auVar21,param_5,param_6,
                                                   plVar27,*(long *)puVar23,0,
                                                   (undefined ********)0x1,(undefined ********)0x0,0
                                                  );
                      *(long **)(param_7 + 0x90 + uVar25 * 8) = plVar27;
                      if (plVar27 == (long *)0x0) {
                        auVar13._8_8_ = extraout_var_06;
                        auVar13._0_8_ = extraout_d0_06;
                        FUN_fffffff009c7cfcc(auVar13,param_2,uVar38,uVar40,param_5,param_6);
                        goto LAB_fffffff009c72088;
                      }
                      puVar28 = (undefined8 *)(**(code **)(*plVar27 + 0x78))();
                      *(undefined8 **)(param_7 + 200 + uVar25 * 8) = puVar28;
                      uVar30 = (**(code **)(**(long **)(param_7 + 0x90 + uVar25 * 8) + 0x88))();
                      thunk_FUN_fffffff00aa65cc0(puVar28,uVar30);
                      uVar25 = uVar25 + 1;
                      uVar30 = (ulong)*(byte *)(param_7 + 0x40);
                    } while (uVar25 < uVar30);
                    if (*(byte *)(param_7 + 0x40) != 0) {
                      lVar26 = 0;
                      do {
                        lVar33 = *(long *)(param_10 + lVar26 * 8);
                        local_b0[lVar26 * 2] = 0;
                        local_b0[lVar26 * 2 + 1] = lVar33;
                        lVar26 = lVar26 + 1;
                        uVar30 = uVar30 - 1;
                      } while (uVar30 != 0);
                    }
                  }
                  lVar26 = (**(code **)(**(long **)(param_7 + 0xb0) + 0x78))();
                  auVar37._8_8_ = extraout_var_07;
                  auVar37._0_8_ = extraout_d0_07;
                  if (*(long *)(param_7 + 0x30) == 0) {
                    uVar25 = *(ulong *)(param_7 + 0x10);
                    lVar26 = -1;
                  }
                  else {
                    uVar30 = 0;
                    uVar31 = *(ulong *)(param_7 + 0x38);
                    uVar34 = (ulong)*(byte *)(param_7 + 0x40);
                    do {
                      puVar28 = (undefined8 *)(uVar31 + uVar30 * 0x30);
                      if (((uVar31 ^ (ulong)puVar28) & 0xffc0000000000000) != 0) {
                        puVar28 = (undefined8 *)
                                  ((ulong)puVar28 & 0xffffffffffff | 0xc8a2000000000000);
                      }
                      lVar33 = uVar30 * 0x58;
                      uVar25 = lVar26 + (int)lVar33;
                      if (lVar33 - (int)lVar33 != 0) {
                        uVar25 = lVar26 + lVar33 & 0xffffffffffffU | 0x2bad000000000000;
                      }
                      auVar37 = FUN_fffffff009c64238
                                          (auVar37,param_2,uVar38,uVar40,param_5,param_6,puVar28,
                                           param_7,uVar25,local_b0,uVar34);
                      uVar31 = *(ulong *)(param_7 + 0x38);
                      uVar34 = uVar31 + uVar30 * 0x30;
                      if (((uVar31 ^ uVar34) & 0xffc0000000000000) != 0) {
                        uVar34 = uVar34 & 0xffffffffffff | 0xc8a2000000000000;
                      }
                      *(ulong *)(uVar34 + 8) = uVar30;
                      uVar25 = *(ulong *)(param_7 + 0x10);
                      puVar35 = (ulong *)(uVar25 + uVar30 * 0x18);
                      if (((uVar25 ^ (ulong)puVar35) & 0xffc0000000000000) != 0) {
                        puVar35 = (ulong *)((ulong)puVar35 & 0xffffffffffff | 0xc8a2000000000000);
                      }
                      *puVar35 = uVar34;
                      uVar34 = uVar25 + uVar30 * 0x18 + 0x18;
                      if (((uVar25 ^ uVar34) & 0xffc0000000000000) != 0) {
                        uVar34 = uVar34 & 0xffffffffffff | 0xc8a2000000000000;
                      }
                      puVar35[1] = uVar34;
                      uVar34 = (ulong)*(byte *)(param_7 + 0x40);
                      if (uVar34 != 0) {
                        lVar33 = 0;
                        uVar36 = uVar34;
                        do {
                          local_b0[lVar33 * 2] = local_b0[lVar33 * 2] + local_b0[lVar33 * 2 + 1];
                          lVar33 = lVar33 + 1;
                          uVar36 = uVar36 - 1;
                        } while (uVar36 != 0);
                      }
                      uVar30 = uVar30 + 1;
                    } while (uVar30 < *(ulong *)(param_7 + 0x30));
                    lVar26 = *(ulong *)(param_7 + 0x30) - 1;
                  }
                  lVar26 = lVar26 * 0x18;
                  uVar30 = uVar25 + (long)(int)lVar26;
                  if (lVar26 - (int)lVar26 != 0) {
                    uVar30 = uVar25 + lVar26 & 0xffffffffffff | 0x2bad000000000000;
                  }
                  *(ulong *)(param_7 + 0x18) = uVar25;
                  *(ulong *)(param_7 + 0x20) = uVar30;
                  *(undefined8 *)(uVar30 + 8) = 0;
                  iVar24 = thunk_FUN_fffffff00aa14b0c((byte *)"timesync_panic",&local_b4,4);
                  if (iVar24 == 0) {
                    iVar24 = thunk_FUN_fffffff00aa16d84((undefined4 *)0x0);
                    if (iVar24 == 0) {
                      *(undefined2 *)(param_7 + 0xf0) = 0;
                    }
                    else {
                      *(undefined2 *)(param_7 + 0xf0) = 0x101;
                    }
                  }
                  else {
                    *(byte *)(param_7 + 0xf0) = (byte)local_b4 & 1;
                    *(byte *)(param_7 + 0xf1) = (byte)local_b4 >> 1 & 1;
                  }
                  uVar29 = 1;
                  goto LAB_fffffff009c72044;
                }
                auVar10._8_8_ = extraout_var_04;
                auVar10._0_8_ = extraout_d0_04;
                FUN_fffffff009c7d054(auVar10,param_2,uVar38,uVar40,param_5,param_6);
              }
            }
          }
        }
      }
    }
  }
  else {
    FUN_fffffff009c7d1ec(param_1,param_2,uVar38,uVar40,param_5,param_6);
  }
LAB_fffffff009c72088:
  uVar29 = 0;
LAB_fffffff009c72044:
  if (*(long *)PTR_DAT_fffffff00807b630 == local_68) {
    return uVar29;
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_fffffff00aa4c590();
}

