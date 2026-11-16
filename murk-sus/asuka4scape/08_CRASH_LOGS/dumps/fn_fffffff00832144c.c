// FUN_fffffff00832144c @ fffffff00832144c size=460
// CALLERS:
//   fffffff00afc2ef0 no-fn
//   fffffff008321074 FUN_fffffff008321024@fffffff008321024
//   fffffff008321a18 FUN_fffffff0083219b4@fffffff0083219b4
// CALLEES:
//   fffffff0083570e4 thunk_FUN_fffffff00a9025cc
//   fffffff008357004 thunk_FUN_fffffff00a9026b0
//   fffffff0083493d8 FUN_fffffff0083493d8
//   fffffff0083570c4 thunk_FUN_fffffff00a902074
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0

undefined8
FUN_fffffff00832144c
          (long param_1,uint *param_2,ulong param_3,undefined8 *param_4,undefined *param_5)

{
  undefined1 (*pauVar1) [16];
  long lVar2;
  uint uVar3;
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
  undefined8 *puVar16;
  undefined **ppuVar17;
  undefined8 extraout_x0;
  undefined8 extraout_x0_00;
  long *plVar18;
  ulong uVar19;
  undefined8 *puVar20;
  undefined8 uVar21;
  ulong uVar22;
  undefined8 uVar23;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 uVar24;
  undefined1 auVar25 [16];
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined8 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined8 uVar34;
  undefined4 in_s4;
  undefined4 in_s5;
  ulong local_50;
  code *local_48;
  
  uVar21 = 0xe00002bc;
  uVar19 = param_3;
  puVar20 = param_4;
  thunk_FUN_fffffff00a9029a0
            ((byte *)"AggressorUserClient::registerAggressor - Registering aggressor!\n");
  if (*param_2 - 1 < 0x2710f && (*param_2 & 0xf) == 0) {
    puVar16 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff007ce8818);
    *(undefined8 **)(param_1 + 0x110) = puVar16;
    pauVar1 = (undefined1 (*) [16])(param_4 + 4);
    uVar23 = *(undefined8 *)*pauVar1;
    auVar25 = *pauVar1;
    auVar6 = *pauVar1;
    uVar28 = param_4[7];
    uVar27 = *(undefined8 *)*(undefined1 (*) [16])(param_4 + 6);
    auVar4 = *(undefined1 (*) [16])(param_4 + 6);
    uVar34 = param_4[1];
    uVar26 = *param_4;
    uVar32 = (undefined4)uVar26;
    uVar33 = (undefined4)((ulong)uVar26 >> 0x20);
    uVar31 = param_4[3];
    uVar24 = param_4[2];
    uVar29 = (undefined4)uVar24;
    uVar30 = (undefined4)((ulong)uVar24 >> 0x20);
    puVar16[5] = param_4[5];
    puVar16[4] = uVar23;
    puVar16[7] = uVar28;
    puVar16[6] = uVar27;
    puVar16[1] = uVar34;
    *puVar16 = uVar26;
    puVar16[3] = uVar31;
    puVar16[2] = uVar24;
    uVar3 = *param_2 >> 4;
    ppuVar17 = *(undefined ***)(param_1 + 0xe8);
    if (ppuVar17 != (undefined **)0x0) {
      *(undefined8 *)(param_1 + 0xe8) = 0;
      auVar25 = thunk_FUN_fffffff00a9026b0
                          (auVar6,auVar4,uVar29,uVar32,in_s4,in_s5,ppuVar17,
                           (undefined *)((ulong)uVar3 << 3),uVar19,puVar20,param_5);
      *(undefined8 *)(param_1 + 0xe8) = 0;
    }
    ppuVar17 = *(undefined ***)(param_1 + 0xf0);
    if (ppuVar17 != (undefined **)0x0) {
      *(undefined8 *)(param_1 + 0xf0) = 0;
      auVar6._8_8_ = uVar28;
      auVar6._0_8_ = uVar27;
      thunk_FUN_fffffff00a9026b0
                (auVar25,auVar6,uVar29,uVar32,in_s4,in_s5,ppuVar17,(undefined *)(ulong)(uVar3 << 2),
                 uVar19,puVar20,param_5);
      auVar25._8_8_ = extraout_var;
      auVar25._0_8_ = extraout_d0;
      *(undefined8 *)(param_1 + 0xf0) = 0;
    }
    *(uint *)(param_1 + 0xf8) = uVar3;
    auVar7._8_8_ = uVar28;
    auVar7._0_8_ = uVar27;
    auVar10._4_4_ = uVar30;
    auVar10._0_4_ = uVar29;
    auVar10._8_8_ = uVar31;
    auVar13._4_4_ = uVar33;
    auVar13._0_4_ = uVar32;
    auVar13._8_8_ = uVar34;
    thunk_FUN_fffffff00a9025cc
              (auVar25,auVar7,auVar10,auVar13,in_s4,in_s5,(ulong *)(ulong)(uVar3 << 3));
    *(undefined8 *)(param_1 + 0xe8) = extraout_x0;
    auVar4._8_8_ = extraout_var_00;
    auVar4._0_8_ = extraout_d0_00;
    auVar8._8_8_ = uVar28;
    auVar8._0_8_ = uVar27;
    auVar11._4_4_ = uVar30;
    auVar11._0_4_ = uVar29;
    auVar11._8_8_ = uVar31;
    auVar14._4_4_ = uVar33;
    auVar14._0_4_ = uVar32;
    auVar14._8_8_ = uVar34;
    thunk_FUN_fffffff00a9025cc
              (auVar4,auVar8,auVar11,auVar14,in_s4,in_s5,
               (ulong *)((ulong)*(uint *)(param_1 + 0xf8) << 2));
    *(undefined8 *)(param_1 + 0xf0) = extraout_x0_00;
    if (*(int *)(param_1 + 0xf8) == 0) {
      uVar19 = 0;
      uVar24 = extraout_d0_01;
      uVar26 = extraout_var_01;
    }
    else {
      uVar22 = 0;
      do {
        puVar20 = (undefined8 *)(param_3 + uVar22 * 0x10);
        if (((param_3 ^ (ulong)puVar20) & 0xffc0000000000000) != 0) {
          puVar20 = (undefined8 *)((ulong)puVar20 & 0xffffffffffff | 0xc8a2000000000000);
        }
        lVar2 = *(long *)(param_1 + 0xf0);
        *(undefined8 *)(*(long *)(param_1 + 0xe8) + uVar22 * 8) = *puVar20;
        *(undefined4 *)(lVar2 + uVar22 * 4) = *(undefined4 *)(puVar20 + 1);
        thunk_FUN_fffffff00a9029a0(&DAT_fffffff007166517);
        uVar22 = uVar22 + 1;
        uVar19 = (ulong)*(uint *)(param_1 + 0xf8);
        uVar24 = extraout_d0_02;
        uVar26 = extraout_var_02;
      } while (uVar22 < uVar19);
    }
    uVar3 = *(uint *)(param_1 + 0xe0);
    local_48 = FUN_fffffff008320d5c;
    if (uVar3 != 0) {
      if (uVar3 != 1) {
        return 0xe00002bc;
      }
      local_48 = FUN_fffffff008320e34;
    }
    local_50 = (ulong)uVar3;
    auVar5._8_8_ = uVar26;
    auVar5._0_8_ = uVar24;
    auVar9._8_8_ = uVar28;
    auVar9._0_8_ = uVar27;
    auVar12._4_4_ = uVar30;
    auVar12._0_4_ = uVar29;
    auVar12._8_8_ = uVar31;
    auVar15._4_4_ = uVar33;
    auVar15._0_4_ = uVar32;
    auVar15._8_8_ = uVar34;
    plVar18 = FUN_fffffff0083493d8
                        (auVar5,auVar9,auVar12,auVar15,in_s4,in_s5,*(long **)(param_1 + 0x100),
                         (byte *)"function-saca",param_1,&local_50,uVar19,
                         *(undefined8 *)(param_1 + 0xe8),*(undefined8 *)(param_1 + 0xf0));
    *(long **)(param_1 + 0xd8) = plVar18;
    if (plVar18 == (long *)0x0) {
      thunk_FUN_fffffff00a9029a0
                ((byte *)
                 "AggressorUserClient::registerAggressor - ERROR - failed to register aggressor\n");
    }
    else {
      uVar21 = 0;
    }
  }
  return uVar21;
}

