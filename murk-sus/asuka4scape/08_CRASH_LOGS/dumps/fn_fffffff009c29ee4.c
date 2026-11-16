// FUN_fffffff009c29ee4 @ fffffff009c29ee4 size=1248
// CALLERS:
//   fffffff00afebe0e no-fn
//   fffffff007ff24a0 no-fn
//   fffffff008022068 no-fn
//   fffffff00802a188 no-fn
//   fffffff009984ab8 thunk_FUN_fffffff009c29ee4@fffffff009984aac
//   fffffff009a9a66c thunk_FUN_fffffff009c29ee4@fffffff009a9a660
//   fffffff009abd848 thunk_FUN_fffffff009c29ee4@fffffff009abd83c
// CALLEES:
//   fffffff009c2ed84 FUN_fffffff009c2ed84
//   fffffff009c2e974 FUN_fffffff009c2e974
//   fffffff009c2ee0c FUN_fffffff009c2ee0c
//   fffffff009c2ec70 FUN_fffffff009c2ec70
//   fffffff009c2ed40 FUN_fffffff009c2ed40
//   fffffff009c2ee94 FUN_fffffff009c2ee94
//   fffffff009c2e998 FUN_fffffff009c2e998
//   fffffff009c2ef1c FUN_fffffff009c2ef1c
//   fffffff009c2eb18 FUN_fffffff009c2eb18
//   fffffff009c2ea4c FUN_fffffff009c2ea4c
//   fffffff009c2e900 FUN_fffffff009c2e900
//   fffffff009c2e9a8 FUN_fffffff009c2e9a8
//   fffffff009c2efa4 FUN_fffffff009c2efa4
//   fffffff009c2ec2c FUN_fffffff009c2ec2c
//   fffffff009c2ea08 FUN_fffffff009c2ea08
//   fffffff009c2ea90 FUN_fffffff009c2ea90
//   fffffff009c2e9c8 FUN_fffffff009c2e9c8
//   fffffff009c48f3c FUN_fffffff009c48f3c
//   fffffff009c2e940 FUN_fffffff009c2e940
//   fffffff009c2eba4 FUN_fffffff009c2eba4
//   fffffff009c2e950 FUN_fffffff009c2e950
//   fffffff009c2edc8 FUN_fffffff009c2edc8
//   fffffff009c2ef60 FUN_fffffff009c2ef60
//   fffffff009c2f000 FUN_fffffff009c2f000
//   fffffff009c2ecfc FUN_fffffff009c2ecfc
//   fffffff009c2eed8 FUN_fffffff009c2eed8
//   fffffff009c49634 thunk_FUN_fffffff00a9025cc
//   fffffff009c48f64 FUN_fffffff009c48f64
//   fffffff009c2e920 FUN_fffffff009c2e920
//   fffffff009c2e9b8 FUN_fffffff009c2e9b8
//   fffffff009c49c14 thunk_FUN_fffffff00a6de494
//   fffffff009c48f28 FUN_fffffff009c48f28
//   fffffff009c2ecb4 FUN_fffffff009c2ecb4
//   fffffff009c2efbc FUN_fffffff009c2efbc
//   fffffff009c2ee50 FUN_fffffff009c2ee50
//   fffffff009c2eb60 FUN_fffffff009c2eb60
//   fffffff009c2ead4 FUN_fffffff009c2ead4
//   fffffff009c2e960 FUN_fffffff009c2e960
//   fffffff009c2e988 FUN_fffffff009c2e988
//   fffffff009c2e910 FUN_fffffff009c2e910
//   fffffff009c2e930 FUN_fffffff009c2e930
//   fffffff009c2ebe8 FUN_fffffff009c2ebe8
//   fffffff009c48f50 FUN_fffffff009c48f50

/* WARNING: Removing unreachable block (ram,0xfffffff009c29f74) */

undefined8
FUN_fffffff009c29ee4
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,long param_8)

{
  ulong *puVar1;
  undefined4 *puVar2;
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
  byte bVar20;
  undefined4 uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  long extraout_x0;
  ulong uVar25;
  ulong uVar26;
  long lVar27;
  ulong uVar28;
  ulong uVar29;
  long lVar30;
  undefined1 extraout_q0 [16];
  undefined1 extraout_q0_00 [16];
  undefined1 extraout_q0_01 [16];
  undefined1 extraout_q0_02 [16];
  undefined1 extraout_q0_03 [16];
  undefined1 auVar31 [16];
  undefined4 uVar32;
  undefined1 auVar33 [12];
  undefined4 uVar34;
  undefined1 auVar35 [12];
  
  uVar34 = param_4._0_4_;
  auVar35 = param_4._4_12_;
  uVar32 = param_3._0_4_;
  auVar33 = param_3._4_12_;
  uVar21 = FUN_fffffff009c2e900(param_8);
  *(undefined4 *)(param_7 + 0x80) = uVar21;
  uVar21 = FUN_fffffff009c2e9a8(param_8);
  *(undefined4 *)(param_7 + 0x98) = uVar21;
  bVar20 = FUN_fffffff009c2e960(param_8);
  uVar22 = 0x200;
  if (bVar20 == 0) {
    uVar22 = 0;
  }
  *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xfffffdff | uVar22;
  bVar20 = FUN_fffffff009c2e960(param_8);
  *(byte *)(*(long *)(param_7 + 0x178) + 0x14) = bVar20;
  bVar20 = FUN_fffffff009c2e974(param_8);
  uVar22 = 0x400000;
  if (bVar20 == 0) {
    uVar22 = 0;
  }
  *(uint *)(param_7 + 0x3d0) = *(uint *)(param_7 + 0x3d0) & 0xffbfffff | uVar22;
  uVar22 = FUN_fffffff009c2e950(param_8);
  *(ulong *)(param_7 + 0x90) = (ulong)uVar22;
  uVar22 = FUN_fffffff009c2e910(param_8);
  *(ulong *)(param_7 + 0x58) = (ulong)uVar22;
  uVar22 = FUN_fffffff009c2e920(param_8);
  *(ulong *)(param_7 + 0x60) = (ulong)uVar22;
  uVar22 = FUN_fffffff009c2e9b8(param_8);
  *(ulong *)(param_7 + 0x78) = (ulong)uVar22;
  uVar21 = FUN_fffffff009c2e930(param_8);
  *(char *)(param_7 + 0x72) = (char)uVar21;
  uVar21 = FUN_fffffff009c2e940(param_8);
  *(char *)(param_7 + 0x73) = (char)uVar21;
  uVar22 = FUN_fffffff009c2e988(param_8);
  *(ulong *)(param_7 + 0x68) = (ulong)uVar22;
  uVar21 = FUN_fffffff009c2e998(param_8);
  *(short *)(param_7 + 0x70) = (short)uVar21;
  uVar22 = FUN_fffffff009c2efa4(param_8);
  *(uint *)(param_7 + 0x3b8) = uVar22;
  uVar22 = 0;
  auVar31 = extraout_q0;
  if (*(uint *)(param_7 + 0x98) != 0) {
    if (3 < *(uint *)(param_7 + 0x98)) {
      return 0;
    }
    *(long *)(param_7 + 0x180) = param_7 + 0xa8;
    *(undefined4 *)(param_7 + 0x188) = 3;
    iVar23 = FUN_fffffff009c2ec70(param_8,0);
    uVar24 = *(uint *)(param_7 + 0x98);
    auVar31 = extraout_q0_00;
    if (iVar23 != 0) {
      auVar31._4_12_ = auVar33;
      auVar31._0_4_ = uVar32;
      auVar11._4_12_ = auVar35;
      auVar11._0_4_ = uVar34;
      thunk_FUN_fffffff00a9025cc
                (extraout_q0_00,param_2,auVar31,auVar11,param_5,param_6,
                 (ulong *)((ulong)uVar24 * 0x3c));
      uVar24 = *(uint *)(param_7 + 0x98);
      *(long *)(param_7 + 0x308) = extraout_x0;
      *(uint *)(param_7 + 0x310) = uVar24;
      auVar31 = extraout_q0_01;
      if (extraout_x0 == 0) {
        return 0;
      }
    }
    uVar22 = 0;
    if (uVar24 != 0) {
      lVar27 = 0;
      uVar28 = 0;
      uVar29 = 0;
      lVar30 = 0;
      uVar22 = 0;
      do {
        uVar25 = *(ulong *)(param_7 + 0x180);
        uVar26 = uVar25 + (ulong)*(uint *)(param_7 + 0x188) * 0x38;
        if (((uVar25 ^ uVar26) & 0xffc0000000000000) != 0) {
          uVar26 = uVar26 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar26 < uVar25) || (uVar26 - uVar25 >> 0x20 != 0)) {
          auVar3._4_12_ = auVar33;
          auVar3._0_4_ = uVar32;
          auVar12._4_12_ = auVar35;
          auVar12._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f64(auVar31,param_2,auVar3,auVar12,param_5,param_6);
        }
        if (lVar27 != (int)lVar27) {
          auVar4._4_12_ = auVar33;
          auVar4._0_4_ = uVar32;
          auVar13._4_12_ = auVar35;
          auVar13._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f3c(auVar31,param_2,auVar4,auVar13,param_5,param_6);
        }
        if (((long)uVar28 < 0) || ((uint)(uVar26 - uVar25) < (int)(uVar28 >> 0x20) + 0x38U)) {
          auVar5._4_12_ = auVar33;
          auVar5._0_4_ = uVar32;
          auVar14._4_12_ = auVar35;
          auVar14._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28(auVar31,param_2,auVar5,auVar14,param_5,param_6);
        }
        puVar1 = (ulong *)(uVar25 + (uVar28 >> 0x20));
        uVar25 = (ulong)CARRY8(uVar25,uVar28 >> 0x20);
        uVar26 = -uVar25;
        if ((uVar26 != uVar25) || ((long)uVar26 < 0)) {
          auVar6._4_12_ = auVar33;
          auVar6._0_4_ = uVar32;
          auVar15._4_12_ = auVar35;
          auVar15._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50(auVar31,param_2,auVar6,auVar15,param_5,param_6);
        }
        uVar24 = FUN_fffffff009c2e9c8(param_8,uVar22);
        *puVar1 = (ulong)uVar24;
        uVar24 = FUN_fffffff009c2ea08(param_8,uVar22);
        puVar1[1] = (ulong)uVar24;
        uVar21 = FUN_fffffff009c2ea4c(param_8,uVar22);
        *(char *)((long)puVar1 + 0x34) = (char)uVar21;
        uVar21 = FUN_fffffff009c2ea90(param_8,uVar22);
        *(char *)((long)puVar1 + 0x35) = (char)uVar21;
        uVar24 = FUN_fffffff009c2ead4(param_8,uVar22);
        puVar1[2] = (ulong)uVar24;
        uVar24 = FUN_fffffff009c2eb18(param_8,uVar22);
        puVar1[3] = (ulong)uVar24;
        uVar24 = FUN_fffffff009c2ebe8(param_8,uVar22);
        puVar1[5] = (ulong)uVar24;
        uVar24 = FUN_fffffff009c2eb60(param_8,uVar22);
        puVar1[4] = (ulong)uVar24;
        uVar21 = FUN_fffffff009c2eba4(param_8,uVar22);
        *(short *)(puVar1 + 6) = (short)uVar21;
        uVar21 = FUN_fffffff009c2ec2c(param_8,uVar22);
        *(char *)((long)puVar1 + 0x36) = (char)uVar21;
        uVar26 = *(ulong *)(param_7 + 0x308);
        auVar31 = extraout_q0_02;
        if (uVar26 != 0) {
          uVar25 = uVar26 + (ulong)*(uint *)(param_7 + 0x310) * 0x3c;
          if (((uVar26 ^ uVar25) & 0xffc0000000000000) != 0) {
            uVar25 = uVar25 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar25 < uVar26) || (uVar25 - uVar26 >> 0x20 != 0)) {
            auVar7._4_12_ = auVar33;
            auVar7._0_4_ = uVar32;
            auVar16._4_12_ = auVar35;
            auVar16._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f64(extraout_q0_02,param_2,auVar7,auVar16,param_5,param_6);
          }
          if (uVar29 != (long)(int)uVar29) {
            auVar8._4_12_ = auVar33;
            auVar8._0_4_ = uVar32;
            auVar17._4_12_ = auVar35;
            auVar17._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f3c(extraout_q0_02,param_2,auVar8,auVar17,param_5,param_6);
          }
          if ((lVar30 < 0) || ((uint)(uVar25 - uVar26) < (int)uVar29 + 0x3cU)) {
            auVar9._4_12_ = auVar33;
            auVar9._0_4_ = uVar32;
            auVar18._4_12_ = auVar35;
            auVar18._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28(extraout_q0_02,param_2,auVar9,auVar18,param_5,param_6);
          }
          puVar2 = (undefined4 *)(uVar26 + uVar29);
          uVar25 = -(ulong)CARRY8(uVar26,uVar29);
          if ((uVar25 != CARRY8(uVar26,uVar29)) || ((long)uVar25 < 0)) {
            auVar10._4_12_ = auVar33;
            auVar10._0_4_ = uVar32;
            auVar19._4_12_ = auVar35;
            auVar19._0_4_ = uVar34;
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50(extraout_q0_02,param_2,auVar10,auVar19,param_5,param_6);
          }
          uVar21 = FUN_fffffff009c2ee0c(param_8,uVar22);
          puVar2[5] = uVar21;
          uVar21 = FUN_fffffff009c2ee50(param_8,uVar22);
          puVar2[6] = uVar21;
          uVar21 = FUN_fffffff009c2ed84(param_8,uVar22);
          *puVar2 = uVar21;
          uVar21 = FUN_fffffff009c2edc8(param_8,uVar22);
          puVar2[1] = uVar21;
          uVar21 = FUN_fffffff009c2ec70(param_8,uVar22);
          *(char *)(puVar2 + 8) = (char)uVar21;
          uVar24 = FUN_fffffff009c2ecb4(param_8,uVar22);
          *(char *)(puVar2 + 10) = (char)uVar24;
          uVar21 = FUN_fffffff009c2ecfc(param_8,uVar22);
          puVar2[3] = uVar21;
          uVar21 = FUN_fffffff009c2ed40(param_8,uVar22);
          puVar2[2] = uVar21;
          uVar21 = FUN_fffffff009c2ee94(param_8,uVar22);
          puVar2[4] = uVar21;
          uVar21 = FUN_fffffff009c2eed8(param_8,uVar22);
          puVar2[0xb] = uVar21;
          uVar21 = FUN_fffffff009c2ef1c(param_8,uVar22);
          puVar2[0xc] = uVar21;
          uVar21 = FUN_fffffff009c2ef60(param_8,uVar22);
          puVar2[7] = uVar21;
          uVar21 = FUN_fffffff009c2efbc(param_8,uVar22);
          puVar2[0xd] = uVar21;
          uVar21 = FUN_fffffff009c2f000(param_8,uVar22);
          puVar2[0xe] = uVar21;
          auVar31 = extraout_q0_03;
        }
        lVar30 = lVar30 + 0x3c00000000;
        uVar29 = uVar29 + 0x3c;
        uVar28 = uVar28 + 0x3800000000;
        lVar27 = lVar27 + 0x38;
        uVar22 = uVar22 + 1;
      } while (uVar22 < *(uint *)(param_7 + 0x98));
      uVar22 = *(uint *)(param_7 + 0x98) << 8;
    }
  }
  auVar31 = thunk_FUN_fffffff00a6de494
                      (auVar31,param_2,uVar32,uVar34,param_5,param_6,0x5400010,
                       (ulong)*(uint *)(param_7 + 0x10),(ulong)*(uint *)(param_7 + 0x80),
                       *(long *)(param_7 + 0x90),
                       (ulong)(*(uint *)(param_7 + 0x3d0) >> 9 & 1 | uVar22));
  thunk_FUN_fffffff00a6de494
            (auVar31,param_2,uVar32,uVar34,param_5,param_6,0x5400014,
             (ulong)*(uint *)(param_7 + 0x10),*(ulong *)(param_7 + 0x58),*(long *)(param_7 + 0x60),
             (long)(int)((uint)*(byte *)(param_7 + 0x72) << 0x18) |
             (ulong)*(byte *)(param_7 + 0x73) << 0x10 | (ulong)*(ushort *)(param_7 + 0x70));
  return 1;
}

