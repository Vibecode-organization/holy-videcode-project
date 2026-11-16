// FUN_fffffff009cabb30 @ fffffff009cabb30

undefined1 *
FUN_fffffff009cabb30
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,long *param_7,long *param_8,undefined1 *param_9,
          undefined1 *param_10,ulong param_11,byte param_12)

{
  ulong uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  ulong uVar7;
  undefined1 auVar8 [16];
  bool bVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  uint uVar16;
  uint uVar17;
  ulong uVar18;
  undefined1 *puVar19;
  short *psVar20;
  undefined1 *puVar21;
  undefined1 extraout_b0;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 extraout_var_13;
  undefined1 *local_b0;
  undefined1 *puStack_a8;
  undefined1 *local_a0;
  undefined4 local_94;
  undefined1 *local_90;
  undefined1 *puStack_88;
  undefined4 local_7c;
  undefined8 local_78;
  
  lVar12 = param_7[6];
  if ((param_10 == (undefined1 *)0x0) ||
     ((param_8 != (long *)0x0 &&
      (lVar11 = (**(code **)(*param_8 + 0x98))(param_1[0],param_8), lVar11 != 0)))) {
    uVar14 = param_11;
    if (0x400 < param_11) {
      if (param_11 < 0x801) {
        uVar14 = param_11 >> 1;
      }
      else {
        uVar14 = param_11 / 3;
      }
    }
    uVar7 = 0;
    if (uVar14 != 0) {
      uVar7 = (ulong)(param_10 + (uVar14 - 1)) / uVar14;
    }
    if (uVar7 < 4) {
      puVar19 = (undefined1 *)0x0;
      uVar14 = 0;
      if (param_11 != 0) {
        uVar14 = 0xffffff / param_11;
      }
      puVar21 = (undefined1 *)(0xffffff - uVar14 * param_11 ^ 0xffffff);
      uVar14 = (ulong)*(uint *)(param_7 + 6);
      do {
        uVar16 = (int)uVar14 + 1;
        uVar13 = *(uint *)(param_7 + 5);
        uVar17 = 0;
        if (uVar13 != 0) {
          uVar17 = uVar16 / uVar13;
        }
        if (uVar16 - uVar17 * uVar13 == *(int *)((long)param_7 + 0x34)) {
          return puVar19;
        }
        local_94 = 1;
        puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
        local_b0 = &DAT_aaaaaaaaaaaaaaaa;
        local_a0 = param_9;
        if (param_10 == (undefined1 *)0x0) {
          local_b0 = (undefined1 *)0x0;
          puStack_a8 = (undefined1 *)0x0;
        }
        else {
          iVar10 = (**(code **)(*param_8 + 0xb8))(param_8,&local_a0,&local_b0,&local_94);
          if (iVar10 != 0) {
            if ((*(uint *)(param_7 + 7) & 1) == 0) {
              return puVar19;
            }
            if (((*(uint *)(param_7 + 7) >> 0x1e & 1) != 0) &&
               (bVar9 = thunk_FUN_fffffff00a394140(), bVar9)) {
              lVar12 = (**(code **)(*param_7 + 0x38))(param_7);
              thunk_FUN_fffffff00a895b28(lVar12);
              thunk_FUN_fffffff00a9029a0
                        ((byte *)"%s: %s::%s: failed to generate IOVM segments, result: 0x%x");
              return puVar19;
            }
            psVar20 = *(short **)PTR_DAT_fffffff008081388;
            lVar12 = (**(code **)(*param_7 + 0x38))(param_7);
            thunk_FUN_fffffff00a895b28(lVar12);
            auVar8[1] = extraout_var;
            auVar8[0] = extraout_b0;
            auVar8[2] = extraout_var_00;
            auVar8[3] = extraout_var_01;
            auVar8[4] = extraout_var_02;
            auVar8[5] = extraout_var_03;
            auVar8[6] = extraout_var_04;
            auVar8[7] = extraout_var_05;
            auVar8[8] = extraout_var_06;
            auVar8[9] = extraout_var_07;
            auVar8[10] = extraout_var_08;
            auVar8[0xb] = extraout_var_09;
            auVar8[0xc] = extraout_var_10;
            auVar8[0xd] = extraout_var_11;
            auVar8[0xe] = extraout_var_12;
            auVar8[0xf] = extraout_var_13;
            thunk_FUN_fffffff00a8df19c
                      (auVar8,param_2,param_3,param_4,param_5,param_6,&MACH_HEADER,psVar20,0,
                       (byte *)"%s: %s::%s: failed to generate IOVM segments, result: 0x%x");
            return puVar19;
          }
          uVar14 = (ulong)*(uint *)(param_7 + 6);
        }
        lVar15 = param_7[2];
        lVar11 = uVar14 * 0x10;
        puVar4 = (undefined8 *)(lVar15 + (int)lVar11);
        if (lVar11 != (int)lVar11) {
          puVar4 = (undefined8 *)(lVar15 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
        }
        puVar2 = param_10;
        if (puStack_a8 <= param_10) {
          puVar2 = puStack_a8;
        }
        *puVar4 = local_b0;
        if (puVar21 <= puVar2) {
          puVar2 = puVar21;
        }
        uVar18 = uVar14 << 4 | 8;
        puVar6 = (uint *)(lVar15 + (int)uVar18);
        if (uVar18 != (long)(int)uVar18) {
          puVar6 = (uint *)(lVar15 + uVar18 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar6 = (uint)puVar2;
        if (((int)uVar14 == (int)lVar12) && (puVar2 != (undefined1 *)0x0)) {
          *puVar6 = *puVar6 | (int)uVar7 * 0x1000000 - 0x1000000U;
        }
        param_10 = param_10 + -(long)puVar2;
        uVar16 = 0;
        if (param_10 != (undefined1 *)0x0) {
          uVar16 = 4;
        }
        uVar13 = 0x800;
        if ((param_12 & param_10 == (undefined1 *)0x0) == 0) {
          uVar13 = 0;
        }
        uVar17 = 0x468;
        if ((int)uVar14 != (int)lVar12) {
          uVar17 = 0x478;
        }
        uVar14 = uVar14 << 4 | 0xc;
        puVar6 = (uint *)(lVar15 + (int)uVar14);
        if (uVar14 != (long)(int)uVar14) {
          puVar6 = (uint *)(lVar15 + uVar14 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar6 = uVar17 | uVar16 | uVar13;
        DataMemoryBarrier(2,3);
        uVar14 = (ulong)*(uint *)(param_7 + 6) << 4 | 0xc;
        puVar6 = (uint *)(param_7[2] + (long)(int)uVar14);
        if (uVar14 != (long)(int)uVar14) {
          puVar6 = (uint *)(param_7[2] + uVar14 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar6 = *puVar6 | 1;
        DataMemoryBarrier(2,3);
        uVar13 = (int)((ulong)*(undefined8 *)((long)param_7 + 0x2c) >> 0x20) + 1;
        *(ulong *)((long)param_7 + 0x2c) =
             CONCAT17((char)(uVar13 >> 0x18),
                      CONCAT16((char)(uVar13 >> 0x10),
                               CONCAT15((char)(uVar13 >> 8),
                                        CONCAT14((char)uVar13,
                                                 (int)*(undefined8 *)((long)param_7 + 0x2c) + 1))));
        uVar14 = (ulong)uVar13;
        if (uVar13 == *(uint *)(param_7 + 5)) {
          local_78 = 0;
          local_7c = 1;
          puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
          local_90 = &DAT_aaaaaaaaaaaaaaaa;
          iVar10 = (**(code **)(*(long *)param_7[4] + 0xb8))
                             ((long *)param_7[4],&local_78,&local_90,&local_7c);
          uVar14 = 0;
          puVar3 = local_90;
          if (iVar10 != 0) {
            puVar3 = (undefined1 *)0x0;
          }
          lVar11 = param_7[2];
          uVar18 = (ulong)*(uint *)(param_7 + 5);
          lVar15 = uVar18 * 0x10;
          puVar4 = (undefined8 *)(lVar11 + (int)lVar15);
          if (lVar15 - (int)lVar15 != 0) {
            puVar4 = (undefined8 *)(lVar11 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar1 = uVar18 << 4 | 8;
          puVar5 = (undefined4 *)(lVar11 + (int)uVar1);
          if (uVar1 != (long)(int)uVar1) {
            puVar5 = (undefined4 *)(lVar11 + uVar1 & 0xffffffffffff | 0x2bad000000000000);
          }
          uVar18 = uVar18 << 4 | 0xc;
          puVar6 = (uint *)(lVar11 + (int)uVar18);
          if (uVar18 != (long)(int)uVar18) {
            puVar6 = (uint *)(lVar11 + uVar18 & 0xffffffffffff | 0x2bad000000000000);
          }
          *puVar4 = puVar3;
          *puVar5 = 0;
          *puVar6 = uVar16 | 0x80;
          DataMemoryBarrier(2,3);
          uVar18 = (ulong)*(uint *)(param_7 + 5) << 4 | 0xc;
          puVar6 = (uint *)(param_7[2] + (long)(int)uVar18);
          if (uVar18 != (long)(int)uVar18) {
            puVar6 = (uint *)(param_7[2] + uVar18 & 0xffffffffffff | 0x2bad000000000000);
          }
          *puVar6 = *puVar6 | 1;
          DataMemoryBarrier(2,3);
          *(undefined4 *)(param_7 + 6) = 0;
        }
        param_9 = puVar2 + (long)param_9;
        puVar19 = puVar2 + (long)puVar19;
        if (param_10 == (undefined1 *)0x0) {
          return puVar19;
        }
      } while( true );
    }
  }
  return (undefined1 *)0x0;
}

