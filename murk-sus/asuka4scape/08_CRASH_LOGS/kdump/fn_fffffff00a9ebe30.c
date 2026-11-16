// FUN_fffffff00a9ebe30 @ fffffff00a9ebe30 size=1148
// CALLERS:
//   fffffff00afbfbc0 ?
//   fffffff007c67fc0 ?
//   fffffff00a9ec6fc FUN_fffffff00a9ec60c@fffffff00a9ec60c
// CALLS:
//   fffffff00a9ec60c FUN_fffffff00a9ec60c
//   fffffff00a2260c4 FUN_fffffff00a2260c4
//   fffffff00a903134 FUN_fffffff00a903134
//   fffffff00a9ec758 FUN_fffffff00a9ec758
//   fffffff00a9029a0 FUN_fffffff00a9029a0
//   fffffff00a382320 FUN_fffffff00a382320
//   fffffff00a8983cc FUN_fffffff00a8983cc
//   fffffff00a97f408 FUN_fffffff00a97f408
//   fffffff00a2216c4 FUN_fffffff00a2216c4
//   fffffff00a9ec2ac FUN_fffffff00a9ec2ac
//   fffffff00aa4d114 FUN_fffffff00aa4d114
//   fffffff00a9ec3f4 FUN_fffffff00a9ec3f4

undefined8
FUN_fffffff00a9ebe30
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,undefined8 param_9,long param_10)

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
  int iVar13;
  uint *puVar14;
  long lVar15;
  long *plVar16;
  ulong uVar17;
  undefined8 *puVar18;
  ulong *puVar19;
  undefined8 uVar20;
  char *pcVar21;
  undefined8 uVar22;
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
  undefined8 uVar23;
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
  undefined8 local_58;
  
  if ((DAT_fffffff00add7710 >> 1 & 1) != 0) {
    FUN_fffffff00a9029a0((byte *)"IOUAT %s:%d: *** IOUnifiedAddressTranslator entry\n");
  }
  *(undefined8 *)(param_7 + 0x10) = param_8;
  *(undefined8 *)(param_7 + 0x18) = param_9;
  *(undefined4 *)(param_7 + 0x540) = 0;
  *(undefined1 *)(param_7 + 0x30) = 0;
  puVar14 = FUN_fffffff00a903134();
  *(uint **)(param_7 + 0x548) = puVar14;
  if (puVar14 == (uint *)0x0) {
    pcVar21 = "IOUAT ERROR: Failed to allocate unmap list lock\n";
  }
  else {
    lVar15 = FUN_fffffff00a2260c4(DAT_fffffff00ad966d0);
    *(long *)(param_7 + 0x28) = lVar15;
    if (lVar15 == 0) {
      pcVar21 = "IOUAT ERROR: Failed to allocate the PPL state object lock\n";
    }
    else {
      lVar15 = FUN_fffffff00a2260c4(DAT_fffffff00ad966d0);
      *(long *)(param_7 + 0x558) = lVar15;
      if (lVar15 == 0) {
        pcVar21 = "IOUAT ERROR: Failed to allocate release thread lock\n";
      }
      else {
        plVar16 = (long *)(**(code **)(DAT_fffffff00ad95bd0 + 0x68))();
        if (plVar16 != (long *)0x0) {
          uVar17 = (**(code **)(*plVar16 + 0xd0))(plVar16,0x20);
          if ((uVar17 & 1) != 0) {
            *(long **)(param_7 + 0x550) = plVar16;
            puVar18 = (undefined8 *)FUN_fffffff00a2216c4((undefined8 *)&DAT_fffffff007c6d4d0,0);
            uVar22 = 0;
            uVar23 = 0;
            puVar18[1] = 0;
            *puVar18 = 0;
            puVar18[3] = 0;
            puVar18[2] = 0;
            puVar18[5] = 0;
            puVar18[4] = 0;
            puVar18[7] = 0;
            puVar18[6] = 0;
            puVar18[9] = 0;
            puVar18[10] = 0;
            puVar18[0xb] = FUN_fffffff00a9ec7a0;
            puVar18[0xc] = param_7;
            puVar18[0xe] = 0;
            puVar18[0xf] = 0;
            puVar18[0xd] = 0;
            puVar18[8] = 0x102210002;
            *(undefined8 **)(param_7 + 0x560) = puVar18;
            if (DAT_fffffff00ad98650 == '\0') {
              DAT_fffffff00ad98650 = 1;
              plVar16 = FUN_fffffff00a9ec2ac
                                  (ZEXT816(0),param_2,param_3,param_4,param_5,param_6,param_7,
                                   "gfx-shared-region-size",8);
              puVar19 = (ulong *)(**(code **)(*plVar16 + 0xd8))();
              auVar1._8_8_ = extraout_var;
              auVar1._0_8_ = extraout_d0;
              uVar22 = FUN_fffffff00a9ec3f4
                                 (auVar1,param_2,param_3,param_4,param_5,param_6,param_7,
                                  "ASC carveout region","gfx-shared-region-base",*puVar19);
              auVar2._8_8_ = extraout_var_00;
              auVar2._0_8_ = extraout_d0_00;
              uVar23 = FUN_fffffff00a9ec3f4
                                 (auVar2,param_2,param_3,param_4,param_5,param_6,param_7,
                                  "TTBR1 shared L2 table","gfx-shared-l2-region-base",0x4000);
              auVar3._8_8_ = extraout_var_01;
              auVar3._0_8_ = extraout_d0_01;
              uVar20 = FUN_fffffff00a9ec3f4
                                 (auVar3,param_2,param_3,param_4,param_5,param_6,param_7,"TTBAT",
                                  "gpu-region-base",0x4000);
              auVar4._8_8_ = extraout_var_02;
              auVar4._0_8_ = extraout_d0_02;
              DAT_fffffff00ad98670 =
                   FUN_fffffff00a9ec3f4
                             (auVar4,param_2,param_3,param_4,param_5,param_6,param_7,
                              "GPU handoff region","gfx-handoff-base",0x4000);
              DAT_fffffff00ad98650 = '\x02';
              DAT_fffffff00ad98658 = uVar22;
              DAT_fffffff00ad98660 = uVar23;
              DAT_fffffff00ad98668 = uVar20;
              if (DAT_fffffff00add7708 == 1) {
                auVar5._8_8_ = extraout_var_03;
                auVar5._0_8_ = extraout_d0_03;
                puVar18 = (undefined8 *)
                          FUN_fffffff00a8983cc
                                    (auVar5,param_2,param_3,param_4,param_5,param_6,
                                     (long *)&DAT_fffffff007c7f810,(ulong *)0x570);
                DAT_fffffff00add7728 = (long *)FUN_fffffff00a9ec758(puVar18);
                if (DAT_fffffff00add7728 == (long *)0x0) {
                  auVar6._8_8_ = extraout_var_05;
                  auVar6._0_8_ = extraout_d0_05;
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff00aa4d114
                            (auVar6,param_2,param_3,param_4,param_5,param_6,
                             (byte *)"%s: Unable to allocate the firmware IOUAT object @%s:%d");
                }
                if (DAT_fffffff00add7708 != 1) {
                  auVar7._8_8_ = extraout_var_05;
                  auVar7._0_8_ = extraout_d0_05;
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff00aa4d114
                            (auVar7,param_2,param_3,param_4,param_5,param_6,
                             (byte *)
                             "%s: Accessing Private Mode global data access outside Private Mode @%s:%d"
                            );
                }
                uVar17 = (**(code **)(*DAT_fffffff00add7728 + 0xa8))
                                   (DAT_fffffff00add7728,DAT_fffffff007c68058,param_9,
                                    DAT_fffffff00add7718);
                uVar22 = extraout_d0_06;
                uVar23 = extraout_var_06;
                if ((uVar17 & 1) == 0) {
                  auVar8._8_8_ = extraout_var_06;
                  auVar8._0_8_ = extraout_d0_06;
                    /* WARNING: Subroutine does not return */
                  FUN_fffffff00aa4d114
                            (auVar8,param_2,param_3,param_4,param_5,param_6,
                             (byte *)"%s: Unable to initialize the firmware IOUAT object @%s:%d");
                }
              }
              else {
                uVar22 = extraout_d0_03;
                uVar23 = extraout_var_03;
                if (DAT_fffffff00add7708 == 0) {
                  auVar9._8_8_ = extraout_var_03;
                  auVar9._0_8_ = extraout_d0_03;
                  DAT_fffffff00add7728 =
                       FUN_fffffff00a9ec60c
                                 (auVar9,param_2,param_3,param_4,param_5,param_6,
                                  DAT_fffffff007c68058,param_9);
                  uVar22 = extraout_d0_04;
                  uVar23 = extraout_var_04;
                }
              }
            }
            local_58 = 0xbee5000000010004;
            if (param_10 == 0) {
              auVar10._8_8_ = uVar23;
              auVar10._0_8_ = uVar22;
              iVar13 = FUN_fffffff00a382320
                                 (auVar10,param_2,param_3,param_4,param_5,param_6,-0xff840e230,
                                  "IOUAT",(ulong)&local_58,8,(undefined8 *)(param_7 + 0x20));
              uVar22 = extraout_d0_08;
              uVar23 = extraout_var_08;
              if (iVar13 != 0) {
                pcVar21 = "IOUAT ERROR: failed to initialize PPL state object\n";
                goto LAB_fffffff00a9ec0d8;
              }
            }
            else {
              *(long *)(param_7 + 0x20) = param_10;
            }
            if ((*(byte *)(param_7 + 0x30) & 1) != 0) {
              auVar11._8_8_ = uVar23;
              auVar11._0_8_ = uVar22;
              plVar16 = FUN_fffffff00a97f408
                                  (auVar11,param_2,param_3,param_4,param_5,param_6,0,0,4,0);
              *(long **)(param_7 + 0x38) = plVar16;
              if (plVar16 == (long *)0x0) {
                auVar12._8_8_ = extraout_var_07;
                auVar12._0_8_ = extraout_d0_07;
                    /* WARNING: Subroutine does not return */
                FUN_fffffff00aa4d114
                          (auVar12,param_2,param_3,param_4,param_5,param_6,
                           (byte *)"fCodeRangeAllocator @%s:%d");
              }
              (**(code **)(*plVar16 + 0xc0))(plVar16,0x1000000000,0x100000000);
            }
            if ((DAT_fffffff00add7710 >> 1 & 1) != 0) {
              FUN_fffffff00a9029a0((byte *)"IOUAT %s:%d: *** IOUnifiedAddressTranslator success\n");
            }
            return 1;
          }
          (**(code **)(*plVar16 + 0x28))(plVar16);
        }
        *(undefined8 *)(param_7 + 0x550) = 0;
        pcVar21 = "IOUAT ERROR: Failed to allocate release array\n";
      }
    }
  }
LAB_fffffff00a9ec0d8:
  FUN_fffffff00a9029a0((byte *)pcVar21);
  return 0;
}

