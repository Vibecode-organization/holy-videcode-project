// FUN_fffffff00830baf4 @ fffffff00830baf4 size=832 depth=1
// CALLERS:
//   fffffff00afc2c5f ?
//   fffffff00830b170 FUN_fffffff00830b124
// CALLS:
//   fffffff008357004 thunk_FUN_fffffff00a9026b0
//   fffffff00830be34 FUN_fffffff00830be34
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff0083570e4 thunk_FUN_fffffff00a9025cc

undefined8
FUN_fffffff00830baf4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          long param_9,undefined8 param_10,undefined *param_11)

{
  int *piVar1;
  undefined8 *puVar2;
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
  code *pcVar18;
  undefined **extraout_x0;
  undefined **extraout_x0_00;
  undefined **extraout_x0_01;
  undefined8 uVar19;
  undefined **ppuVar20;
  undefined8 extraout_x1;
  undefined **ppuVar21;
  uint uVar22;
  long lVar23;
  uint uVar24;
  int iVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  ulong unaff_x30;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined *puVar31;
  undefined8 extraout_d0_05;
  undefined8 extraout_d0_06;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 uVar32;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 extraout_var_06;
  undefined4 uVar33;
  undefined1 auVar34 [12];
  undefined4 uVar35;
  undefined1 auVar36 [12];
  
  uVar35 = param_4._0_4_;
  auVar36 = param_4._4_12_;
  uVar33 = param_3._0_4_;
  auVar34 = param_3._4_12_;
  lVar26 = param_9;
  thunk_FUN_fffffff00a9029a0((byte *)"VictimUserClient::removeFreqs\n");
  if (((0x2710e < *param_8 - 1 || (*param_8 & 0xf) != 0) || (*(long *)(param_7 + 0xf0) == 0)) ||
     (*(uint *)(param_7 + 0xe8) == 0)) {
    return 0xe00002bc;
  }
  auVar9._8_8_ = extraout_var;
  auVar9._0_8_ = extraout_d0;
  auVar12._4_12_ = auVar34;
  auVar12._0_4_ = uVar33;
  auVar15._4_12_ = auVar36;
  auVar15._0_4_ = uVar35;
  thunk_FUN_fffffff00a9025cc
            (auVar9,param_2,auVar12,auVar15,param_5,param_6,
             (ulong *)((ulong)*(uint *)(param_7 + 0xe8) << 2));
  if (*(int *)(param_7 + 0xe8) != 0) {
    uVar28 = 0;
    uVar30 = 0;
    uVar27 = 0;
    uVar19 = extraout_d0_00;
    uVar32 = extraout_var_00;
    do {
      lVar23 = uVar28 * 4;
      piVar1 = (int *)((long)extraout_x0 + (long)(int)lVar23);
      if (lVar23 - (int)lVar23 != 0) {
        piVar1 = (int *)((long)extraout_x0 + lVar23 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *piVar1 = -1;
      uVar22 = *param_8;
      if (uVar22 < 0x10) {
        uVar22 = 1;
      }
      else {
        uVar29 = 0;
        do {
          if (*(long *)(*(long *)(param_7 + 0xf0) + uVar28 * 0x10) ==
              *(long *)(param_9 + uVar29 * 0x10)) {
            *piVar1 = (int)uVar29;
            uVar27 = (ulong)((int)uVar27 + 1);
            thunk_FUN_fffffff00a9029a0
                      ((byte *)
                       "VictimUserClient::removeFreqs -- removing: freq=%lluHz bandwidth=%dHz priority=%d\n"
                      );
            uVar22 = *param_8;
            uVar19 = extraout_d0_01;
            uVar32 = extraout_var_01;
          }
          uVar29 = uVar29 + 1;
        } while (uVar29 < uVar22 >> 4);
        uVar22 = (uint)(*piVar1 == -1);
      }
      uVar22 = (int)uVar30 + uVar22;
      uVar30 = (ulong)uVar22;
      uVar28 = uVar28 + 1;
    } while (uVar28 < *(uint *)(param_7 + 0xe8));
    if (uVar22 != 0) {
      if (uVar22 == *(uint *)(param_7 + 0xe8)) {
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"VictimUserClient::removeFreqs -- no frequencies to remove!\n");
        auVar11._8_8_ = extraout_var_02;
        auVar11._0_8_ = extraout_d0_02;
        thunk_FUN_fffffff00a9026b0
                  (auVar11,param_2,uVar33,uVar35,param_5,param_6,extraout_x0,
                   (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 2),lVar26,param_10,param_11);
        return 0xe00002bc;
      }
      puVar3 = (ulong *)(uVar30 << 4);
      auVar6._8_8_ = uVar32;
      auVar6._0_8_ = uVar19;
      auVar13._4_12_ = auVar34;
      auVar13._0_4_ = uVar33;
      auVar16._4_12_ = auVar36;
      auVar16._0_4_ = uVar35;
      thunk_FUN_fffffff00a9025cc(auVar6,param_2,auVar13,auVar16,param_5,param_6,puVar3);
      auVar7._8_8_ = extraout_var_04;
      auVar7._0_8_ = extraout_d0_04;
      auVar14._4_12_ = auVar34;
      auVar14._0_4_ = uVar33;
      auVar17._4_12_ = auVar36;
      auVar17._0_4_ = uVar35;
      thunk_FUN_fffffff00a9025cc
                (auVar7,param_2,auVar14,auVar17,param_5,param_6,(ulong *)(uVar27 << 4));
      if (*(int *)(param_7 + 0xe8) != 0) {
        uVar28 = 0;
        uVar30 = 0;
        uVar24 = 0;
        do {
          lVar26 = uVar28 * 4;
          piVar1 = (int *)((long)extraout_x0 + (long)(int)lVar26);
          if (lVar26 - (int)lVar26 != 0) {
            piVar1 = (int *)((long)extraout_x0 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
          }
          iVar25 = *piVar1;
          if (iVar25 == -1 && (uint)uVar30 < uVar22) {
            iVar25 = (int)(uVar30 * 0x10);
            puVar2 = (undefined8 *)((long)extraout_x0_00 + (long)iVar25);
            if (uVar30 * 0x10 != (long)iVar25) {
              puVar2 = (undefined8 *)
                       ((ulong)(extraout_x0_00 + uVar30 * 2) & 0xffffffffffff | 0x2bad000000000000);
            }
            puVar4 = (undefined8 *)(*(long *)(param_7 + 0xf0) + uVar28 * 0x10);
            uVar19 = *puVar4;
            puVar2[1] = puVar4[1];
            *puVar2 = uVar19;
            uVar30 = (ulong)((uint)uVar30 + 1);
          }
          else if (iVar25 != -1 && uVar24 < (uint)uVar27) {
            lVar26 = (long)iVar25 * 0x10;
            puVar2 = (undefined8 *)(param_9 + (int)lVar26);
            if (lVar26 - (int)lVar26 != 0) {
              puVar2 = (undefined8 *)(param_9 + lVar26 & 0xffffffffffffU | 0x2bad000000000000);
            }
            puVar31 = (undefined *)*puVar2;
            (extraout_x0_01 + (ulong)uVar24 * 2)[1] = (undefined *)puVar2[1];
            extraout_x0_01[(ulong)uVar24 * 2] = puVar31;
            uVar24 = uVar24 + 1;
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < *(uint *)(param_7 + 0xe8));
      }
      ppuVar21 = extraout_x0_01;
      uVar19 = (**(code **)(**(long **)(param_7 + 0xe0) + 0x98))(*(long **)(param_7 + 0xe0),uVar27);
      auVar8._8_8_ = extraout_var_05;
      auVar8._0_8_ = extraout_d0_05;
      auVar9 = thunk_FUN_fffffff00a9026b0
                         (auVar8,param_2,uVar33,uVar35,param_5,param_6,extraout_x0_00,
                          (undefined *)puVar3,ppuVar21,param_10,param_11);
      auVar9 = thunk_FUN_fffffff00a9026b0
                         (auVar9,param_2,uVar33,uVar35,param_5,param_6,extraout_x0_01,
                          (undefined *)(uVar27 << 4),ppuVar21,param_10,param_11);
      if ((int)uVar19 != 0) {
        thunk_FUN_fffffff00a9029a0
                  ((byte *)"VictimUserClient::removeFreqs -- removeVictims call to SAC failed\n");
        auVar10._8_8_ = extraout_var_06;
        auVar10._0_8_ = extraout_d0_06;
        thunk_FUN_fffffff00a9026b0
                  (auVar10,param_2,uVar33,uVar35,param_5,param_6,(undefined **)0x0,
                   (undefined *)puVar3,ppuVar21,param_10,param_11);
        return uVar19;
      }
      ppuVar20 = *(undefined ***)(param_7 + 0xf0);
      *(undefined8 *)(param_7 + 0xf0) = 0;
      thunk_FUN_fffffff00a9026b0
                (auVar9,param_2,uVar33,uVar35,param_5,param_6,ppuVar20,
                 (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 4),ppuVar21,param_10,param_11);
      *(undefined8 *)(param_7 + 0xf0) = 0;
      *(uint *)(param_7 + 0xe8) = uVar22;
      return uVar19;
    }
  }
  thunk_FUN_fffffff00a9029a0
            ((byte *)
             "VictimUserClient::removeFreqs -- requested to remove all freqs, calling VictimUserClient::clearFreqs\n"
            );
  auVar5._8_8_ = extraout_var_03;
  auVar5._0_8_ = extraout_d0_03;
  auVar9 = thunk_FUN_fffffff00a9026b0
                     (auVar5,param_2,uVar33,uVar35,param_5,param_6,extraout_x0,
                      (undefined *)((ulong)*(uint *)(param_7 + 0xe8) << 2),lVar26,param_10,param_11)
  ;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    uVar19 = FUN_fffffff00830be34
                       (auVar9,param_2,uVar33,uVar35,param_5,param_6,param_7,extraout_x1,lVar26,
                        param_10,param_11);
    return uVar19;
  }
                    /* WARNING: Does not return */
  pcVar18 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00830bcc4);
  (*pcVar18)();
}

