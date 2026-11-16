// FUN_fffffff0270adf30 @ fffffff0270adf30 size=1636
// CALLERS:
//   fffffff02701c148 ?
//   fffffff0270ae8ac FUN_fffffff0270ae700@fffffff0270ae700
// CALLS:
//   fffffff0270bf2a0 FUN_fffffff0270bf2a0
//   fffffff0270e1168 FUN_fffffff0270e1168
//   fffffff0270f46f4 FUN_fffffff0270f46f4
//   fffffff0270bf7b4 FUN_fffffff0270bf7b4
//   fffffff0270ad14c FUN_fffffff0270ad14c
//   fffffff0270e08e4 FUN_fffffff0270e08e4
//   fffffff0270f46b4 FUN_fffffff0270f46b4
//   fffffff0270d3dec FUN_fffffff0270d3dec
//   fffffff0270e0b28 FUN_fffffff0270e0b28
//   fffffff0270ae594 FUN_fffffff0270ae594
//   fffffff0270e0e58 FUN_fffffff0270e0e58

undefined8 FUN_fffffff0270adf30(undefined8 param_1)

{
  ulong uVar1;
  ulong uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar7;
  byte bVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined4 uVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong *puVar17;
  ulong *puVar18;
  ulong uVar19;
  ulong uVar20;
  ulong *puVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  undefined1 auVar25 [16];
  undefined8 local_70 [2];
  byte *pbVar6;
  
  auVar25 = FUN_fffffff0270bf2a0(param_1,3,0xf);
  uVar14 = auVar25._8_8_;
  pbVar6 = auVar25._0_8_;
  uVar2 = *(ulong *)(pbVar6 + 0x28);
  uVar20 = *(ulong *)(pbVar6 + 0x30);
  if (uVar2 <= uVar20) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4
              ("%s: Corrupted map_data, current segment greater than number of segments %p %zu %zu")
    ;
  }
  uVar23 = 0;
  uVar22 = *(ulong *)(pbVar6 + 0x38);
  uVar15 = *(ulong *)(pbVar6 + 0x20);
  do {
    if (uVar2 <= uVar20) {
      DataMemoryBarrier(0,3);
      if (pbVar6[0x1a] != 1) goto LAB_fffffff0270ae558;
      pbVar6[0x1a] = 2;
      uVar14 = 0;
      bVar8 = *pbVar6;
      goto joined_r0xfffffff0270ae2a8;
    }
    puVar21 = (ulong *)(pbVar6 + 0x48 + uVar20 * 0x10);
    if ((((ulong)(pbVar6 + 0x48) ^ (ulong)puVar21) & 0xffc0000000000000) != 0) {
      puVar21 = (ulong *)((ulong)puVar21 & 0xffffffffffff | 0xc8a2000000000000);
    }
    uVar7 = puVar21[1];
    if (uVar7 <= uVar22) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: Invalid cur_seg_offset %zu %zu");
    }
    if (uVar22 == 0) {
      uVar16 = uVar7 * 0x4000;
      if (uVar7 >> 0x32 != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46f4
                  (0x4000013,uVar14,
                   "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
      }
      uVar7 = *puVar21;
      if (CARRY8(uVar7,uVar16)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46f4
                  (0x4000011,uVar14,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
      }
      uVar13 = *(undefined4 *)(pbVar6 + 0x40);
      FUN_fffffff0270ae594(uVar7,uVar13);
      FUN_fffffff0270ae594(uVar7 + uVar16,uVar13);
      FUN_fffffff0270bf7b4(uVar15,uVar16,pbVar6,0);
      uVar7 = puVar21[1];
      uVar14 = extraout_x1;
    }
    uVar10 = *(ulong *)(DAT_fffffff0270921b8 + 0x1c8);
    uVar16 = uVar7 - uVar22;
    if (uVar10 - uVar23 <= uVar7 - uVar22) {
      uVar16 = uVar10 - uVar23;
    }
    local_70[0] = 0;
    if (uVar16 != 0) {
      puVar17 = (ulong *)0x0;
      uVar7 = *puVar21 + uVar22 * 0x4000;
      uVar10 = uVar15;
      uVar24 = uVar16;
      do {
        auVar25._8_8_ = uVar14;
        auVar25._0_8_ = puVar17;
        if (((ulong)puVar17 & 0x3fff) == 0) {
          uVar12 = uVar10 >> ((ulong)*(byte *)(DAT_fffffff0270921b8 + 0x1b1) & 0x3f);
          bVar8 = 5;
          if ((uVar12 & 1) != 0) {
            bVar8 = 0xe;
          }
          if ((bVar8 & *pbVar6) == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff0270f46b4("%s: %d is not a valid UAT state object type when getting TTBR%d");
          }
          auVar25 = FUN_fffffff0270ad14c
                              (*(undefined8 *)(pbVar6 + (uVar12 & 1) * 8 + 8),uVar10,3,local_70);
        }
        uVar14 = auVar25._8_8_;
        puVar18 = auVar25._0_8_;
        if ((~(uint)*puVar18 & 3) == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f46f4
                    (0x400000d,uVar14,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
        }
        uVar9 = *(uint *)(pbVar6 + 0x40);
        uVar12 = (ulong)(uVar9 >> 8 & 2 | (uVar9 & 3) << 2 | uVar9 >> 8 & 1);
        if ((1L << uVar12 & 0x4ac0U) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f46f4
                    (0x400001f,uVar14,
                     "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
        }
        uVar19 = uVar7 & 0xfffffffff000;
        bVar8 = (&DAT_fffffff027019e80)[uVar12];
        uVar12 = 3;
        if ((uVar9 & 8) != 0) {
          uVar12 = 0xb;
        }
        if ((uVar9 & 4) != 0) {
          uVar12 = 7;
        }
        uVar1 = 0x800;
        if ((*pbVar6 & 10) != 0) {
          uVar1 = 0;
        }
        uVar11 = (ulong)bVar8 & 0xf;
        uVar9 = (uint)uVar11;
        bVar3 = uVar9 - 5 < 3;
        bVar5 = uVar11 - 9 < 2;
        bVar4 = (uVar9 & 0xe) == 2;
        uVar13 = 1;
        if ((bVar3 || bVar5) || bVar4) {
          uVar13 = 2;
        }
        if ((uVar19 == *(ulong *)(DAT_fffffff0270921b8 + 0x68)) && ((bVar3 || bVar5) || bVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f46f4
                    (0x4000012,uVar14,
                     "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n"
                    );
        }
        if (uVar19 != *(ulong *)(DAT_fffffff0270921b8 + 0x68)) {
          FUN_fffffff0270e1168(uVar19,uVar13);
        }
        uVar14 = local_70[0];
        FUN_fffffff0270e08e4(local_70[0],0x18);
        FUN_fffffff0270e0e58(uVar14,1);
        FUN_fffffff0270e0b28(uVar14);
        puVar17 = puVar18 + 1;
        *puVar18 = uVar1 | ((ulong)bVar8 & 3) << 0x35 | uVar19 |
                   uVar12 | ((ulong)(bVar8 >> 2) & 3) << 6 | 0x80000000000400;
        uVar7 = uVar7 + 0x4000;
        uVar10 = uVar10 + 0x4000;
        uVar24 = uVar24 - 1;
        uVar14 = extraout_x1_00;
      } while (uVar24 != 0);
      uVar7 = puVar21[1];
      uVar10 = *(ulong *)(DAT_fffffff0270921b8 + 0x1c8);
    }
    uVar15 = uVar15 + uVar16 * 0x4000;
    bVar3 = uVar20 == uVar2 - 1;
    uVar22 = uVar16 + uVar22;
    bVar5 = uVar22 == uVar7;
    if (bVar5) {
      uVar20 = uVar20 + 1;
    }
    if (bVar5) {
      uVar22 = 0;
    }
    uVar23 = uVar16 + uVar23;
  } while ((uVar23 < uVar10) || (bVar5 && bVar3));
  *(ulong *)(pbVar6 + 0x20) = uVar15;
  *(ulong *)(pbVar6 + 0x30) = uVar20;
  *(ulong *)(pbVar6 + 0x38) = uVar22;
  if (pbVar6[0x1a] != 1) {
LAB_fffffff0270ae558:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar6[0x1a] = 3;
  bVar8 = *pbVar6;
  uVar14 = 1;
joined_r0xfffffff0270ae2a8:
  if ((bVar8 & 5) != 0) {
    FUN_fffffff0270d3dec(pbVar6);
    FUN_fffffff0270e0b28();
  }
  return uVar14;
}

