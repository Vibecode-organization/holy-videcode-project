// FUN_fffffff00830b554 @ fffffff00830b554 size=1440
// CALLERS:
//   fffffff00afc2c5e no-fn
//   fffffff00830b120 FUN_fffffff00830b0d4@fffffff00830b0d4
// CALLEES:
//   fffffff0083570e4 thunk_FUN_fffffff00a9025cc
//   fffffff008357ad4 thunk_FUN_fffffff00aa65b10
//   fffffff008357004 thunk_FUN_fffffff00a9026b0
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff0083570b4 thunk_FUN_fffffff00a902580

undefined8
FUN_fffffff00830b554
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          undefined **param_9,undefined8 param_10,undefined *param_11)

{
  int *piVar1;
  uint uVar2;
  ulong *puVar3;
  undefined8 *puVar4;
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
  uint uVar22;
  code *pcVar23;
  undefined **extraout_x0;
  undefined **extraout_x0_00;
  undefined8 *extraout_x0_01;
  undefined **extraout_x0_02;
  undefined **extraout_x0_03;
  undefined **ppuVar24;
  undefined **ppuVar25;
  undefined8 uVar26;
  long lVar27;
  ulong uVar28;
  ulong uVar29;
  int iVar30;
  uint uVar31;
  undefined8 *puVar32;
  undefined *puVar33;
  undefined8 uVar34;
  ulong *puVar35;
  uint uVar36;
  ulong uVar37;
  ulong uVar38;
  undefined8 extraout_d0;
  undefined8 extraout_d0_06;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined1 auVar39 [16];
  undefined8 extraout_var_06;
  undefined4 uVar40;
  undefined1 auVar41 [12];
  undefined4 uVar42;
  undefined1 auVar43 [12];
  
  uVar42 = param_4._0_4_;
  auVar43 = param_4._4_12_;
  uVar40 = param_3._0_4_;
  auVar41 = param_3._4_12_;
  uVar34 = 0xe00002bc;
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::addFreqs\n");
  uVar2 = *param_8;
  if (uVar2 - 1 < 0x2710f && (uVar2 & 0xf) == 0) {
    uVar22 = uVar2 >> 4;
    uVar38 = (ulong)uVar22;
    if (0xf < uVar2) {
      uVar37 = 0;
      do {
        lVar27 = 0;
        uVar28 = uVar38;
        uVar29 = uVar37;
        do {
          if ((uVar29 != 0) && (param_9[uVar37 * 2] == param_9[lVar27 * 2])) {
            thunk_FUN_fffffff00a9029a0
                      ((byte *)"VictimUserClient::addFreqs -- duplicates in provided frequencies\n")
            ;
            return 0xe00002c2;
          }
          lVar27 = lVar27 + 1;
          uVar29 = uVar29 - 1;
          uVar28 = uVar28 - 1;
        } while (uVar28 != 0);
        uVar37 = uVar37 + 1;
      } while (uVar37 != uVar38);
    }
    if (*(long *)(param_7 + 0xf0) == 0) {
      *(uint *)(param_7 + 0xe8) = uVar22;
      auVar39._8_8_ = extraout_var;
      auVar39._0_8_ = extraout_d0;
      auVar12._4_12_ = auVar41;
      auVar12._0_4_ = uVar40;
      auVar17._4_12_ = auVar43;
      auVar17._0_4_ = uVar42;
      thunk_FUN_fffffff00a902580
                (auVar39,param_2,auVar12,auVar17,param_5,param_6,(ulong *)(ulong)uVar2);
      *(undefined8 **)(param_7 + 0xf0) = extraout_x0_01;
      if (uVar2 < *param_8) {
LAB_fffffff00830baf0:
                    /* WARNING: Does not return */
        pcVar23 = (code *)SoftwareBreakpoint(0xbffe,0xfffffff00830baf4);
        (*pcVar23)();
      }
      thunk_FUN_fffffff00aa65b10(extraout_x0_01,param_9,(ulong)*param_8);
      if (extraout_x0_01 == (undefined8 *)0x0) {
        thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::addFreqs - memcpy failed\n");
      }
      else {
        if (*(int *)(param_7 + 0xe8) == 0) {
          uVar38 = 0;
        }
        else {
          uVar37 = 0;
          do {
            thunk_FUN_fffffff00a9029a0
                      ((byte *)
                       "VictimUserClient::addFreqs - adding: freq=%lluHz bandwidth=%dHz priority=%d\n"
                      );
            uVar37 = uVar37 + 1;
            uVar38 = (ulong)*(uint *)(param_7 + 0xe8);
          } while (uVar37 < uVar38);
        }
        uVar26 = *(undefined8 *)(param_7 + 0xf0);
        uVar34 = (**(code **)(**(long **)(param_7 + 0xe0) + 0x90))
                           (*(long **)(param_7 + 0xe0),uVar38);
        if ((int)uVar34 != 0) {
          thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::addFreqs - Failed to add Freqs\n");
          ppuVar24 = *(undefined ***)(param_7 + 0xf0);
          if (ppuVar24 != (undefined **)0x0) {
            *(undefined8 *)(param_7 + 0xf0) = 0;
            auVar5._8_8_ = extraout_var_06;
            auVar5._0_8_ = extraout_d0_06;
            thunk_FUN_fffffff00a9026b0
                      (auVar5,param_2,uVar40,uVar42,param_5,param_6,ppuVar24,
                       (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 4),uVar26,param_10,param_11
                      );
          }
          *(undefined4 *)(param_7 + 0xe8) = 0;
        }
      }
    }
    else {
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "VictimUserClient::addFreqs -- victims exist, going through validation process\n");
      auVar6._8_8_ = extraout_var_00;
      auVar6._0_8_ = extraout_d0_00;
      auVar13._4_12_ = auVar41;
      auVar13._0_4_ = uVar40;
      auVar18._4_12_ = auVar43;
      auVar18._0_4_ = uVar42;
      thunk_FUN_fffffff00a9025cc
                (auVar6,param_2,auVar13,auVar18,param_5,param_6,
                 (ulong *)((ulong)*(uint *)(param_7 + 0xe8) << 2));
      puVar35 = (ulong *)(ulong)(uVar22 << 2);
      auVar7._8_8_ = extraout_var_01;
      auVar7._0_8_ = extraout_d0_01;
      auVar14._4_12_ = auVar41;
      auVar14._0_4_ = uVar40;
      auVar19._4_12_ = auVar43;
      auVar19._0_4_ = uVar42;
      thunk_FUN_fffffff00a9025cc(auVar7,param_2,auVar14,auVar19,param_5,param_6,puVar35);
      if (0xf < uVar2) {
        lVar27 = 0;
        uVar37 = uVar38;
        do {
          *(undefined4 *)((long)extraout_x0_00 + lVar27 * 4) = 1;
          lVar27 = lVar27 + 1;
          uVar37 = uVar37 - 1;
        } while (uVar37 != 0);
      }
      uVar37 = uVar38;
      if (*(int *)(param_7 + 0xe8) == 0) {
        iVar30 = 0;
      }
      else {
        uVar28 = 0;
        iVar30 = 0;
        do {
          lVar27 = uVar28 * 4;
          piVar1 = (int *)((long)extraout_x0 + (long)(int)lVar27);
          if (lVar27 - (int)lVar27 != 0) {
            piVar1 = (int *)((long)extraout_x0 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *piVar1 = -1;
          if (uVar2 < 0x10) {
            uVar31 = 1;
          }
          else {
            uVar29 = 0;
            puVar32 = (undefined8 *)(*(ulong *)(param_7 + 0xf0) + uVar28 * 0x10);
            if (((*(ulong *)(param_7 + 0xf0) ^ (ulong)puVar32) & 0xffc0000000000000) != 0) {
              puVar32 = (undefined8 *)((ulong)puVar32 & 0xffffffffffff | 0xc8a2000000000000);
            }
            puVar33 = (undefined *)*puVar32;
            do {
              ppuVar24 = param_9 + uVar29 * 2;
              if (puVar33 == *ppuVar24) {
                if ((*(int *)(puVar32 + 1) == *(int *)(ppuVar24 + 1)) &&
                   (*(int *)((long)puVar32 + 0xc) == *(int *)((long)ppuVar24 + 0xc))) {
                  *(undefined4 *)((long)extraout_x0_00 + uVar29 * 4) = 0;
                  uVar37 = (ulong)((int)uVar37 - 1);
                }
                else {
                  *piVar1 = (int)uVar29;
                }
              }
              uVar29 = uVar29 + 1;
            } while (uVar38 != uVar29);
            uVar31 = (uint)(*piVar1 == -1);
          }
          iVar30 = iVar30 + uVar31;
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_7 + 0xe8));
      }
      uVar36 = (uint)uVar37;
      uVar31 = iVar30 + uVar36;
      puVar3 = (ulong *)((ulong)uVar31 << 4);
      auVar8._8_8_ = extraout_var_02;
      auVar8._0_8_ = extraout_d0_02;
      auVar15._4_12_ = auVar41;
      auVar15._0_4_ = uVar40;
      auVar20._4_12_ = auVar43;
      auVar20._0_4_ = uVar42;
      thunk_FUN_fffffff00a9025cc(auVar8,param_2,auVar15,auVar20,param_5,param_6,puVar3);
      ppuVar24 = param_9;
      if ((uVar36 != uVar22) &&
         (auVar9._8_8_ = extraout_var_03, auVar9._0_8_ = extraout_d0_03, auVar16._4_12_ = auVar41,
         auVar16._0_4_ = uVar40, auVar21._4_12_ = auVar43, auVar21._0_4_ = uVar42,
         thunk_FUN_fffffff00a9025cc
                   (auVar9,param_2,auVar16,auVar21,param_5,param_6,(ulong *)(uVar37 << 4)),
         ppuVar24 = extraout_x0_03, 0xf < uVar2)) {
        lVar27 = 0;
        uVar28 = 0;
        do {
          if (0 < *(int *)((long)extraout_x0_00 + lVar27 * 4)) {
            if (uVar36 <= (uint)uVar28) goto LAB_fffffff00830baf0;
            iVar30 = (int)(uVar28 * 0x10);
            puVar32 = (undefined8 *)((long)extraout_x0_03 + (long)iVar30);
            if (uVar28 * 0x10 != (long)iVar30) {
              puVar32 = (undefined8 *)
                        ((ulong)(extraout_x0_03 + uVar28 * 2) & 0xffffffffffff | 0x2bad000000000000)
              ;
            }
            puVar33 = param_9[lVar27 * 2];
            puVar32[1] = (param_9 + lVar27 * 2)[1];
            *puVar32 = puVar33;
            uVar28 = (ulong)((uint)uVar28 + 1);
          }
          lVar27 = lVar27 + 1;
          uVar38 = uVar38 - 1;
        } while (uVar38 != 0);
      }
      thunk_FUN_fffffff00a9029a0
                ((byte *)"VictimUserClient::addFreqs - registering the following with SAC\n");
      uVar38 = uVar37;
      if (uVar36 != 0) {
        do {
          thunk_FUN_fffffff00a9029a0
                    ((byte *)
                     "VictimUserClient::addFreqs - registering: freq=%lluHz bandwidth=%dHz priority=%d\n"
                    );
          uVar38 = uVar38 - 1;
        } while (uVar38 != 0);
      }
      ppuVar25 = ppuVar24;
      uVar34 = (**(code **)(**(long **)(param_7 + 0xe0) + 0x90))(*(long **)(param_7 + 0xe0),uVar37);
      if ((int)uVar34 == 0) {
        uVar34 = extraout_d0_04;
        uVar26 = extraout_var_04;
        if (uVar31 != 0) {
          uVar28 = 0;
          uVar38 = 0;
          uVar29 = 0;
          do {
            if (uVar38 < *(uint *)(param_7 + 0xe8)) {
              lVar27 = uVar38 * 4;
              piVar1 = (int *)((long)extraout_x0 + (long)(int)lVar27);
              if (lVar27 - (int)lVar27 != 0) {
                piVar1 = (int *)((long)extraout_x0 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
              }
              if (*piVar1 == -1) {
                iVar30 = (int)(uVar28 * 0x10);
                puVar32 = (undefined8 *)((long)extraout_x0_02 + (long)iVar30);
                if (uVar28 * 0x10 != (long)iVar30) {
                  puVar32 = (undefined8 *)
                            ((ulong)(extraout_x0_02 + uVar28 * 2) & 0xffffffffffff |
                            0x2bad000000000000);
                }
                puVar4 = (undefined8 *)(*(long *)(param_7 + 0xf0) + uVar38 * 0x10);
                uVar26 = puVar4[1];
                uVar34 = *puVar4;
                puVar32[1] = uVar26;
                *puVar32 = uVar34;
                uVar28 = (ulong)((int)uVar28 + 1);
              }
              uVar38 = uVar38 + 1;
            }
            else if (uVar38 == *(uint *)(param_7 + 0xe8) && (uint)uVar29 < uVar36) {
              iVar30 = (int)(uVar29 * 0x10);
              puVar32 = (undefined8 *)((long)ppuVar24 + (long)iVar30);
              if (uVar29 * 0x10 != (long)iVar30) {
                puVar32 = (undefined8 *)
                          ((ulong)(ppuVar24 + uVar29 * 2) & 0xffffffffffff | 0x2bad000000000000);
              }
              iVar30 = (int)(uVar28 * 0x10);
              puVar4 = (undefined8 *)((long)extraout_x0_02 + (long)iVar30);
              if (uVar28 * 0x10 != (long)iVar30) {
                puVar4 = (undefined8 *)
                         ((ulong)(extraout_x0_02 + uVar28 * 2) & 0xffffffffffff | 0x2bad000000000000
                         );
              }
              uVar26 = puVar32[1];
              uVar34 = *puVar32;
              puVar4[1] = uVar26;
              *puVar4 = uVar34;
              uVar28 = (ulong)((int)uVar28 + 1);
              uVar29 = (ulong)((uint)uVar29 + 1);
            }
          } while ((uint)uVar28 < uVar31);
        }
        auVar10._8_8_ = uVar26;
        auVar10._0_8_ = uVar34;
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar10,param_2,uVar40,uVar42,param_5,param_6,extraout_x0,
                             (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 2),ppuVar25,param_10,
                             param_11);
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar39,param_2,uVar40,uVar42,param_5,param_6,extraout_x0_00,
                             (undefined *)puVar35,ppuVar25,param_10,param_11);
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar39,param_2,uVar40,uVar42,param_5,param_6,extraout_x0_02,
                             (undefined *)puVar3,ppuVar25,param_10,param_11);
        if (ppuVar24 != param_9) {
          auVar39 = thunk_FUN_fffffff00a9026b0
                              (auVar39,param_2,uVar40,uVar42,param_5,param_6,ppuVar24,
                               (undefined *)(uVar37 << 4),ppuVar25,param_10,param_11);
        }
        ppuVar24 = *(undefined ***)(param_7 + 0xf0);
        *(undefined8 *)(param_7 + 0xf0) = 0;
        thunk_FUN_fffffff00a9026b0
                  (auVar39,param_2,uVar40,uVar42,param_5,param_6,ppuVar24,
                   (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 4),ppuVar25,param_10,param_11);
        uVar34 = 0;
        *(undefined8 *)(param_7 + 0xf0) = 0;
        *(uint *)(param_7 + 0xe8) = uVar31;
      }
      else {
        thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::addFreqs - Failed to add freqs\n");
        auVar11._8_8_ = extraout_var_05;
        auVar11._0_8_ = extraout_d0_05;
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar11,param_2,uVar40,uVar42,param_5,param_6,extraout_x0,
                             (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 2),ppuVar25,param_10,
                             param_11);
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar39,param_2,uVar40,uVar42,param_5,param_6,extraout_x0_00,
                             (undefined *)puVar35,ppuVar25,param_10,param_11);
        auVar39 = thunk_FUN_fffffff00a9026b0
                            (auVar39,param_2,uVar40,uVar42,param_5,param_6,extraout_x0_02,
                             (undefined *)puVar3,ppuVar25,param_10,param_11);
        if (ppuVar24 != param_9) {
          thunk_FUN_fffffff00a9026b0
                    (auVar39,param_2,uVar40,uVar42,param_5,param_6,ppuVar24,
                     (undefined *)(uVar37 << 4),ppuVar25,param_10,param_11);
        }
      }
    }
  }
  return uVar34;
}

