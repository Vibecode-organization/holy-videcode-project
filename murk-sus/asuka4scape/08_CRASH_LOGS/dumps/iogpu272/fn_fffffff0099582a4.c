// FUN_fffffff0099582a4 @ fffffff0099582a4 size=1280

undefined8 FUN_fffffff0099582a4(long *param_1)

{
  undefined8 *puVar1;
  ulong *puVar2;
  uint *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  long *plVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  long *plVar15;
  undefined8 uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  long lVar20;
  uint uVar21;
  ulong uVar22;
  ulong uVar23;
  long lVar24;
  ulong uVar25;
  ulong uVar26;
  long lVar27;
  uint uVar28;
  ulong uVar29;
  long lVar30;
  uint uVar31;
  int iVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  
  uVar14 = *(uint *)(param_1 + 4);
  do {
    uVar31 = uVar14;
    uVar14 = uVar31 << 1;
  } while (uVar31 < *(uint *)(param_1 + 4) << 1);
LAB_fffffff009958310:
  plVar15 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0528);
  plVar15[1] = 0;
  *plVar15 = 0;
  plVar15[3] = 0;
  plVar15[2] = 0;
  plVar15[4] = 0;
  plVar15[5] = 0;
  plVar15[6] = 0;
  plVar15[7] = 0;
  *(undefined1 *)(plVar15 + 8) = 0;
  uVar16 = FUN_fffffff0099546e8(plVar15,uVar31,*(undefined4 *)((long)param_1 + 0x34));
  if ((int)uVar16 != 0) {
    uVar22 = 0;
    do {
      uVar23 = *(ulong *)(param_1[3] + uVar22 * 8);
      if (uVar23 != 0) {
        lVar24 = plVar15[3];
        do {
          uVar14 = 0;
          uVar25 = (uVar23 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar23 & 0x5555555555555555) << 1;
          uVar25 = (uVar25 & 0xcccccccccccccccc) >> 2 | (uVar25 & 0x3333333333333333) << 2;
          uVar25 = (uVar25 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar25 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar25 = (uVar25 & 0xff00ff00ff00ff00) >> 8 | (uVar25 & 0xff00ff00ff00ff) << 8;
          uVar25 = (uVar25 & 0xffff0000ffff0000) >> 0x10 | (uVar25 & 0xffff0000ffff) << 0x10;
          uVar25 = LZCOUNT(uVar25 >> 0x20 | uVar25 << 0x20);
          uVar26 = uVar25 | (uint)((int)uVar22 << 6);
          lVar27 = uVar26 * 8;
          plVar6 = (long *)(*param_1 + (long)(int)lVar27);
          if (lVar27 - (int)lVar27 != 0) {
            plVar6 = (long *)(*param_1 + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar27 = uVar26 * 0x10;
          puVar1 = (undefined8 *)(param_1[1] + (long)(int)lVar27);
          if (lVar27 - (int)lVar27 != 0) {
            puVar1 = (undefined8 *)(param_1[1] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar23 = uVar23 & (1L << (uVar25 & 0x3f) ^ 0xffffffffffffffffU);
          lVar27 = *plVar6;
          uVar11 = (int)plVar15[4] - 1;
          uVar7 = *(uint *)(plVar15 + 5);
          uVar26 = (ulong)(lVar27 * -0x61c8864680b583eb) >>
                   ((ulong)(uint)-*(int *)((long)plVar15 + 0x2c) & 0x3f);
          uVar25 = uVar26 >> 6 & 0x3ffffff;
          uVar28 = (uint)uVar26;
          uVar29 = *(ulong *)(lVar24 + uVar25 * 8) | -1L << (uVar26 & 0x3f) ^ 0xffffffffffffffffU;
          iVar19 = 0x40 - (uVar28 & 0x3f);
          uVar17 = (uint)uVar25;
          iVar32 = uVar17 << 6;
          while (uVar17 = uVar17 + 1, uVar29 == 0xffffffffffffffff) {
            lVar20 = (ulong)(uVar17 & uVar7) * 8;
            puVar2 = (ulong *)(lVar24 + (int)lVar20);
            if (lVar20 != (int)lVar20) {
              puVar2 = (ulong *)(lVar24 + lVar20 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar14 = iVar19 + uVar14;
            uVar29 = *puVar2;
            iVar32 = iVar32 + 0x40;
            iVar19 = 0x40;
            if (0x7f < uVar14) goto LAB_fffffff0099586bc;
          }
          uVar25 = (~uVar29 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar29 & 0x5555555555555555) << 1;
          uVar25 = (uVar25 & 0xcccccccccccccccc) >> 2 | (uVar25 & 0x3333333333333333) << 2;
          uVar25 = (uVar25 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar25 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar25 = (uVar25 & 0xff00ff00ff00ff00) >> 8 | (uVar25 & 0xff00ff00ff00ff) << 8;
          uVar25 = (uVar25 & 0xffff0000ffff0000) >> 0x10 | (uVar25 & 0xffff0000ffff) << 0x10;
          uVar14 = (int)LZCOUNT(uVar25 >> 0x20 | uVar25 << 0x20) + iVar32;
          uVar25 = (ulong)uVar14;
          if (0x7f < uVar14 - uVar28) {
LAB_fffffff0099586bc:
            FUN_fffffff009952a10(plVar15);
            thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff04e8,plVar15);
            uVar31 = uVar31 << 1;
            goto LAB_fffffff009958310;
          }
          while( true ) {
            uVar14 = (uint)uVar25;
            if (uVar14 - uVar28 < 0x20) break;
            uVar17 = uVar14 - 0x1f;
            if (0x1e < uVar14) {
              lVar20 = plVar15[2];
              uVar18 = 0xffffffe1;
              while( true ) {
                uVar17 = uVar14 + uVar18;
                lVar30 = (ulong)(uVar17 & uVar11) * 4;
                puVar3 = (uint *)(lVar20 + (int)lVar30);
                if (lVar30 != (int)lVar30) {
                  puVar3 = (uint *)(lVar20 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar8 = *puVar3;
                uVar10 = (uVar8 & 0xaaaaaaaa) >> 1 | (uVar8 & 0x55555555) << 1;
                uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
                uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
                uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
                uVar21 = (uint)LZCOUNT(uVar10 >> 0x10 | uVar10 << 0x10);
                uVar10 = uVar17 + uVar21;
                if (uVar8 != 0 && uVar10 < uVar14) break;
                uVar18 = uVar18 + 1;
                if (!CARRY4(uVar14,uVar18)) goto LAB_fffffff0099586bc;
              }
              lVar30 = (ulong)(uVar17 & uVar11) * 4;
              puVar3 = (uint *)(lVar20 + (int)lVar30);
              if (lVar30 - (int)lVar30 != 0) {
                puVar3 = (uint *)(lVar20 + lVar30 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar12 = (ulong)(uVar10 & uVar11) * 8;
              lVar20 = *plVar15;
              lVar30 = plVar15[1];
              iVar32 = (int)lVar12;
              puVar4 = (undefined8 *)(lVar20 + iVar32);
              if (lVar12 != iVar32) {
                puVar4 = (undefined8 *)(lVar20 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar13 = (ulong)(uVar10 & uVar11) * 0x10;
              iVar19 = (int)lVar13;
              puVar5 = (undefined8 *)(lVar30 + iVar19);
              if (lVar13 != iVar19) {
                puVar5 = (undefined8 *)(lVar30 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar33 = *puVar4;
              uVar35 = puVar5[1];
              uVar34 = *puVar5;
              *puVar3 = uVar8 & (1 << (ulong)(uVar21 & 0x1f) ^ 0xffffffffU) |
                        1 << (ulong)(-uVar18 & 0x1f);
              uVar18 = uVar7 & uVar14 >> 6;
              *(ulong *)(lVar24 + (ulong)uVar18 * 8) =
                   *(ulong *)(lVar24 + (ulong)uVar18 * 8) | 1L << (uVar25 & 0x3f);
              lVar24 = (ulong)(uVar14 & uVar11) * 8;
              puVar4 = (undefined8 *)(lVar20 + (int)lVar24);
              if (lVar24 != (int)lVar24) {
                puVar4 = (undefined8 *)(lVar20 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar4 = uVar33;
              lVar24 = (ulong)(uVar14 & uVar11) * 0x10;
              puVar4 = (undefined8 *)(lVar30 + (int)lVar24);
              if (lVar24 != (int)lVar24) {
                puVar4 = (undefined8 *)(lVar30 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
              }
              puVar4[1] = uVar35;
              *puVar4 = uVar34;
              puVar4 = (undefined8 *)(*plVar15 + (long)iVar32);
              if (lVar12 != iVar32) {
                puVar4 = (undefined8 *)(*plVar15 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
              }
              puVar5 = (undefined8 *)(plVar15[1] + (long)iVar19);
              if (lVar13 != iVar19) {
                puVar5 = (undefined8 *)(plVar15[1] + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar4 = 0;
              *puVar5 = 0;
              lVar24 = plVar15[3];
              uVar25 = (ulong)(uVar7 & uVar10 >> 6);
              *(ulong *)(lVar24 + uVar25 * 8) =
                   *(ulong *)(lVar24 + uVar25 * 8) &
                   (1L << ((ulong)uVar10 & 0x3f) ^ 0xffffffffffffffffU);
              uVar25 = (ulong)uVar10;
            }
            if (uVar17 == uVar14) goto LAB_fffffff0099586bc;
          }
          lVar24 = (ulong)(uVar14 & uVar11) * 8;
          plVar6 = (long *)(*plVar15 + (long)(int)lVar24);
          if (lVar24 != (int)lVar24) {
            plVar6 = (long *)(*plVar15 + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
          }
          lVar24 = (ulong)(uVar14 & uVar11) * 0x10;
          puVar4 = (undefined8 *)(plVar15[1] + (long)(int)lVar24);
          if (lVar24 != (int)lVar24) {
            puVar4 = (undefined8 *)(plVar15[1] + lVar24 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *plVar6 = lVar27;
          uVar33 = *puVar1;
          puVar4[1] = puVar1[1];
          *puVar4 = uVar33;
          lVar27 = (uVar26 & 0xffffffff) * 4;
          lVar24 = plVar15[3];
          puVar3 = (uint *)(plVar15[2] + (long)(int)lVar27);
          if (lVar27 != (int)lVar27) {
            puVar3 = (uint *)(plVar15[2] + lVar27 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar3 = *puVar3 | 1 << (ulong)(uVar14 - uVar28 & 0x1f);
          uVar7 = uVar7 & uVar14 >> 6;
          *(ulong *)(lVar24 + (ulong)uVar7 * 8) =
               *(ulong *)(lVar24 + (ulong)uVar7 * 8) | 1L << (uVar25 & 0x3f);
          *(int *)(plVar15 + 6) = (int)plVar15[6] + 1;
        } while (uVar23 != 0);
      }
      uVar14 = (int)uVar22 + 1;
      uVar22 = (ulong)uVar14;
    } while (uVar14 <= *(uint *)(param_1 + 5));
    lVar24 = *plVar15;
    lVar20 = param_1[1];
    lVar27 = *param_1;
    param_1[1] = plVar15[1];
    *param_1 = lVar24;
    plVar15[1] = lVar20;
    *plVar15 = lVar27;
    lVar24 = plVar15[2];
    lVar20 = param_1[3];
    lVar27 = param_1[2];
    param_1[3] = plVar15[3];
    param_1[2] = lVar24;
    plVar15[3] = lVar20;
    plVar15[2] = lVar27;
    lVar24 = param_1[4];
    *(int *)(param_1 + 4) = (int)plVar15[4];
    *(int *)(plVar15 + 4) = (int)lVar24;
    uVar9 = *(undefined4 *)((long)param_1 + 0x34);
    *(undefined4 *)((long)param_1 + 0x34) = *(undefined4 *)((long)plVar15 + 0x34);
    *(undefined4 *)((long)plVar15 + 0x34) = uVar9;
    uVar9 = *(undefined4 *)((long)param_1 + 0x24);
    *(undefined4 *)((long)param_1 + 0x24) = *(undefined4 *)((long)plVar15 + 0x24);
    *(undefined4 *)((long)plVar15 + 0x24) = uVar9;
    lVar24 = param_1[5];
    *(int *)(param_1 + 5) = (int)plVar15[5];
    *(int *)(plVar15 + 5) = (int)lVar24;
    uVar9 = *(undefined4 *)((long)param_1 + 0x2c);
    *(undefined4 *)((long)param_1 + 0x2c) = *(undefined4 *)((long)plVar15 + 0x2c);
    *(undefined4 *)((long)plVar15 + 0x2c) = uVar9;
    lVar24 = param_1[6];
    *(int *)(param_1 + 6) = (int)plVar15[6];
    *(int *)(plVar15 + 6) = (int)lVar24;
    lVar24 = param_1[7];
    param_1[7] = plVar15[7];
    plVar15[7] = lVar24;
    FUN_fffffff009952a10(plVar15);
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff04e8,plVar15);
  }
  return uVar16;
}

