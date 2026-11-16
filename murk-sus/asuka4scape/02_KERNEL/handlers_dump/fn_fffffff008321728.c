// FUN_fffffff008321728 @ fffffff008321728 size=652 depth=1
// CALLERS:
//   fffffff00afc2ef4 ?
//   fffffff0083211a0 FUN_fffffff008321154
// CALLS:
//   fffffff008357004 thunk_FUN_fffffff00a9026b0
//   fffffff0083570a4 thunk_FUN_fffffff00a9029a0
//   fffffff0083570e4 thunk_FUN_fffffff00a9025cc

undefined8
FUN_fffffff008321728
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,uint *param_8,
          ulong param_9,undefined8 param_10,undefined *param_11)

{
  uint uVar1;
  uint *puVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined **extraout_x0;
  undefined8 uVar8;
  undefined **extraout_x0_00;
  undefined **ppuVar9;
  undefined *puVar10;
  undefined **ppuVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  undefined8 *puVar16;
  ulong uVar17;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 auVar18 [16];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  undefined4 uVar21;
  undefined1 auVar22 [12];
  undefined4 local_48;
  uint local_44;
  
  uVar21 = param_4._0_4_;
  auVar22 = param_4._4_12_;
  uVar19 = param_3._0_4_;
  auVar20 = param_3._4_12_;
  thunk_FUN_fffffff00a9029a0((byte *)"AggressorUserClient::getSafeFreqList\n");
  uVar13 = *(uint *)(param_7 + 0xf8);
  if ((ulong)(*param_8 >> 4) < (ulong)uVar13 || (*param_8 & 0xf) != 0) {
    return 0xe00002bc;
  }
  local_48 = 0;
  if (*(int *)(param_7 + 0xe0) == 1) {
    auVar18._4_12_ = auVar20;
    auVar18._0_4_ = uVar19;
    auVar6._4_12_ = auVar22;
    auVar6._0_4_ = uVar21;
    local_44 = uVar13;
    thunk_FUN_fffffff00a9025cc
              (extraout_q0,param_2,auVar18,auVar6,param_5,param_6,(ulong *)((ulong)uVar13 << 2));
    ppuVar11 = extraout_x0_00;
    uVar8 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x90))(*(long **)(param_7 + 0xd8),&local_44);
    uVar12 = (ulong)local_44;
    if ((int)uVar8 != 0) {
      puVar10 = (undefined *)(uVar12 << 2);
      ppuVar9 = extraout_x0_00;
      auVar18 = extraout_q0_01;
      goto LAB_fffffff008321828;
    }
    ppuVar9 = extraout_x0_00;
    auVar18 = extraout_q0_01;
    if (local_44 == 0) goto LAB_fffffff008321980;
  }
  else {
    if (*(int *)(param_7 + 0xe0) != 0) {
      return 0xe00002bc;
    }
    auVar5._4_12_ = auVar20;
    auVar5._0_4_ = uVar19;
    auVar7._4_12_ = auVar22;
    auVar7._0_4_ = uVar21;
    thunk_FUN_fffffff00a9025cc
              (extraout_q0,param_2,auVar5,auVar7,param_5,param_6,(ulong *)&DAT_00000004);
    ppuVar11 = (undefined **)0x0;
    uVar8 = (**(code **)(**(long **)(param_7 + 0xd8) + 0x90))(*(long **)(param_7 + 0xd8),&local_48);
    if ((int)uVar8 != 0) {
      puVar10 = &DAT_00000004;
      ppuVar9 = extraout_x0;
      auVar18 = extraout_q0_00;
LAB_fffffff008321828:
      thunk_FUN_fffffff00a9026b0
                (auVar18,param_2,uVar19,uVar21,param_5,param_6,ppuVar9,puVar10,ppuVar11,param_10,
                 param_11);
      return uVar8;
    }
    *(undefined4 *)extraout_x0 = local_48;
    uVar12 = 1;
    local_44 = 1;
    ppuVar9 = extraout_x0;
    auVar18 = extraout_q0_00;
  }
  lVar14 = 0;
  uVar17 = uVar12;
  uVar13 = 0;
  do {
    lVar15 = lVar14 * 4;
    puVar2 = (uint *)((long)ppuVar9 + (long)(int)lVar15);
    if (lVar15 - (int)lVar15 != 0) {
      puVar2 = (uint *)((long)ppuVar9 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar1 = *puVar2;
    if (*puVar2 <= uVar13) {
      uVar1 = uVar13;
    }
    lVar14 = lVar14 + 1;
    uVar17 = uVar17 - 1;
    uVar13 = uVar1;
  } while (uVar17 != 0);
  if (*(uint *)(param_7 + 0xf8) < uVar1) {
    thunk_FUN_fffffff00a9026b0
              (auVar18,param_2,uVar19,uVar21,param_5,param_6,ppuVar9,(undefined *)(uVar12 << 2),
               ppuVar11,param_10,param_11);
    return 0xe00002bc;
  }
  uVar17 = 0;
  do {
    lVar14 = uVar17 * 4;
    puVar2 = (uint *)((long)ppuVar9 + (long)(int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      puVar2 = (uint *)((long)ppuVar9 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar14 = (ulong)*puVar2 * 8;
    puVar3 = (undefined8 *)(*(long *)(param_7 + 0xe8) + (long)(int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      puVar3 = (undefined8 *)
               (*(long *)(param_7 + 0xe8) + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    puVar16 = (undefined8 *)(param_9 + uVar17 * 0x10);
    if (((param_9 ^ (ulong)puVar16) & 0xffc0000000000000) != 0) {
      puVar16 = (undefined8 *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
    }
    lVar14 = (ulong)*puVar2 * 4;
    puVar4 = (undefined4 *)(*(long *)(param_7 + 0xf0) + (long)(int)lVar14);
    if (lVar14 - (int)lVar14 != 0) {
      puVar4 = (undefined4 *)
               (*(long *)(param_7 + 0xf0) + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar16 = *puVar3;
    *(undefined4 *)(puVar16 + 1) = *puVar4;
    thunk_FUN_fffffff00a9029a0(&DAT_fffffff0071666b3);
    uVar17 = uVar17 + 1;
    uVar12 = (ulong)local_44;
    auVar18 = extraout_q0_02;
  } while (uVar17 < uVar12);
LAB_fffffff008321980:
  *param_8 = (int)uVar12 << 4;
  thunk_FUN_fffffff00a9026b0
            (auVar18,param_2,uVar19,uVar21,param_5,param_6,ppuVar9,(undefined *)(uVar12 << 2),
             ppuVar11,param_10,param_11);
  return 0;
}

