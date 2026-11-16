// FUN_fffffff00996a418 @ fffffff00996a418 size=1344

/* WARNING: Removing unreachable block (ram,0xfffffff00996a7f0) */

undefined8 FUN_fffffff00996a418(long *param_1,uint param_2)

{
  ulong *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  long *plVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  long lVar14;
  long *plVar15;
  undefined8 uVar16;
  long *plVar17;
  long lVar18;
  uint uVar19;
  int iVar20;
  ulong uVar21;
  long lVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  ulong uVar26;
  ulong uVar27;
  long lVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  ulong uVar32;
  ulong uVar33;
  undefined8 uVar34;
  
  uVar6 = *(uint *)(param_1 + 5);
  uVar24 = uVar6 << 1;
  if (param_2 != 0) {
    uVar24 = param_2;
  }
  do {
    uVar31 = uVar6;
    uVar6 = uVar31 << 1;
  } while (uVar31 < uVar24);
LAB_fffffff00996a470:
  plVar15 = (long *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0968);
  plVar15[4] = 0;
  plVar15[5] = 0;
  plVar15[1] = 0;
  *plVar15 = 0;
  plVar15[3] = 0;
  plVar15[2] = 0;
  plVar15[6] = 0;
  plVar15[7] = 0;
  plVar15[9] = 0;
  *(undefined4 *)(plVar15 + 8) = 0;
  *(undefined2 *)(plVar15 + 10) = 0x100;
  uVar16 = FUN_fffffff009968c04(plVar15,uVar31,(int)param_1[8],*(byte *)((long)param_1 + 0x51) & 1);
  if ((int)uVar16 != 0) {
    uVar32 = 0;
    do {
      uVar33 = *(ulong *)(param_1[3] + uVar32 * 8);
      if (uVar33 != 0) {
        do {
          uVar24 = 0;
          uVar21 = (uVar33 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar33 & 0x5555555555555555) << 1;
          uVar21 = (uVar21 & 0xcccccccccccccccc) >> 2 | (uVar21 & 0x3333333333333333) << 2;
          uVar21 = (uVar21 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar21 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar21 = (uVar21 & 0xff00ff00ff00ff00) >> 8 | (uVar21 & 0xff00ff00ff00ff) << 8;
          uVar21 = (uVar21 & 0xffff0000ffff0000) >> 0x10 | (uVar21 & 0xffff0000ffff) << 0x10;
          uVar21 = LZCOUNT(uVar21 >> 0x20 | uVar21 << 0x20);
          uVar33 = uVar33 & (1L << (uVar21 & 0x3f) ^ 0xffffffffffffffffU);
          uVar21 = uVar21 | (uint)((int)uVar32 << 6);
          lVar22 = uVar21 * 8;
          plVar17 = (long *)(*param_1 + (long)(int)lVar22);
          if (lVar22 - (int)lVar22 != 0) {
            plVar17 = (long *)(*param_1 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
          }
          plVar17 = (long *)*plVar17;
          lVar22 = uVar21 * 4;
          puVar3 = (undefined4 *)(param_1[1] + (long)(int)lVar22);
          if (lVar22 - (int)lVar22 != 0) {
            puVar3 = (undefined4 *)(param_1[1] + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar7 = *puVar3;
          uVar12 = (int)plVar15[5] - 1;
          uVar6 = *(uint *)(plVar15 + 6);
          uVar21 = (ulong)((long)plVar17 * -0x61c8864680b583eb) >>
                   ((ulong)(uint)-*(int *)((long)plVar15 + 0x34) & 0x3f);
          uVar26 = uVar21 >> 6 & 0x3ffffff;
          lVar22 = plVar15[3];
          uVar23 = (uint)uVar21;
          uVar27 = *(ulong *)(lVar22 + uVar26 * 8) | -1L << (uVar21 & 0x3f) ^ 0xffffffffffffffffU;
          iVar29 = 0x40 - (uVar23 & 0x3f);
          uVar25 = (uint)uVar26;
          iVar20 = uVar25 << 6;
          while (uVar25 = uVar25 + 1, uVar27 == 0xffffffffffffffff) {
            lVar18 = (ulong)(uVar25 & uVar6) * 8;
            puVar1 = (ulong *)(lVar22 + (int)lVar18);
            if (lVar18 != (int)lVar18) {
              puVar1 = (ulong *)(lVar22 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
            }
            uVar24 = iVar29 + uVar24;
            uVar27 = *puVar1;
            iVar20 = iVar20 + 0x40;
            iVar29 = 0x40;
            if (0x7f < uVar24) goto LAB_fffffff00996a838;
          }
          uVar26 = (~uVar27 & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uVar27 & 0x5555555555555555) << 1;
          uVar26 = (uVar26 & 0xcccccccccccccccc) >> 2 | (uVar26 & 0x3333333333333333) << 2;
          uVar26 = (uVar26 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar26 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar26 = (uVar26 & 0xff00ff00ff00ff00) >> 8 | (uVar26 & 0xff00ff00ff00ff) << 8;
          uVar26 = (uVar26 & 0xffff0000ffff0000) >> 0x10 | (uVar26 & 0xffff0000ffff) << 0x10;
          uVar24 = (int)LZCOUNT(uVar26 >> 0x20 | uVar26 << 0x20) + iVar20;
          uVar26 = (ulong)uVar24;
          if (0x7f < uVar24 - uVar23) {
LAB_fffffff00996a838:
            FUN_fffffff009968820(plVar15);
            thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff09a8,plVar15);
            uVar31 = uVar31 << 1;
            goto LAB_fffffff00996a470;
          }
          while( true ) {
            uVar24 = (uint)uVar26;
            if (uVar24 - uVar23 < 0x20) break;
            uVar25 = uVar24 - 0x1f;
            if (0x1e < uVar24) {
              lVar18 = plVar15[2];
              uVar30 = 0xffffffe1;
              while( true ) {
                uVar25 = uVar24 + uVar30;
                lVar28 = (ulong)(uVar25 & uVar12) * 4;
                puVar2 = (uint *)(lVar18 + (int)lVar28);
                if (lVar28 != (int)lVar28) {
                  puVar2 = (uint *)(lVar18 + lVar28 & 0xffffffffffffU | 0x2bad000000000000);
                }
                uVar8 = *puVar2;
                uVar11 = (uVar8 & 0xaaaaaaaa) >> 1 | (uVar8 & 0x55555555) << 1;
                uVar11 = (uVar11 & 0xcccccccc) >> 2 | (uVar11 & 0x33333333) << 2;
                uVar11 = (uVar11 & 0xf0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f) << 4;
                uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
                uVar19 = (uint)LZCOUNT(uVar11 >> 0x10 | uVar11 << 0x10);
                uVar11 = uVar25 + uVar19;
                if (uVar8 != 0 && uVar11 < uVar24) break;
                uVar30 = uVar30 + 1;
                if (!CARRY4(uVar24,uVar30)) goto LAB_fffffff00996a838;
              }
              lVar28 = (ulong)(uVar25 & uVar12) * 4;
              puVar2 = (uint *)(lVar18 + (int)lVar28);
              if (lVar28 - (int)lVar28 != 0) {
                puVar2 = (uint *)(lVar18 + lVar28 & 0xffffffffffffU | 0x2bad000000000000);
              }
              lVar13 = (ulong)(uVar11 & uVar12) * 8;
              lVar18 = *plVar15;
              lVar28 = plVar15[1];
              iVar20 = (int)lVar13;
              puVar4 = (undefined8 *)(lVar18 + iVar20);
              if (lVar13 != iVar20) {
                puVar4 = (undefined8 *)(lVar18 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar34 = *puVar4;
              lVar14 = (ulong)(uVar11 & uVar12) * 4;
              puVar3 = (undefined4 *)(lVar28 + (int)lVar14);
              if (lVar14 != (int)lVar14) {
                puVar3 = (undefined4 *)(lVar28 + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
              }
              uVar9 = *puVar3;
              *puVar2 = uVar8 & (1 << (ulong)(uVar19 & 0x1f) ^ 0xffffffffU) |
                        1 << (ulong)(-uVar30 & 0x1f);
              uVar30 = uVar6 & uVar24 >> 6;
              *(ulong *)(lVar22 + (ulong)uVar30 * 8) =
                   *(ulong *)(lVar22 + (ulong)uVar30 * 8) | 1L << (uVar26 & 0x3f);
              lVar22 = (ulong)(uVar24 & uVar12) * 8;
              puVar4 = (undefined8 *)(lVar18 + (int)lVar22);
              if (lVar22 != (int)lVar22) {
                puVar4 = (undefined8 *)(lVar18 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar4 = uVar34;
              lVar22 = (ulong)(uVar24 & uVar12) * 4;
              puVar3 = (undefined4 *)(lVar28 + (int)lVar22);
              if (lVar22 != (int)lVar22) {
                puVar3 = (undefined4 *)(lVar28 + lVar22 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar3 = uVar9;
              puVar4 = (undefined8 *)(*plVar15 + (long)iVar20);
              if (lVar13 != iVar20) {
                puVar4 = (undefined8 *)(*plVar15 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
              }
              *puVar4 = 0;
              lVar22 = plVar15[3];
              uVar30 = uVar6 & uVar11 >> 6;
              *(ulong *)(lVar22 + (ulong)uVar30 * 8) =
                   *(ulong *)(lVar22 + (ulong)uVar30 * 8) &
                   (1L << ((ulong)uVar11 & 0x3f) ^ 0xffffffffffffffffU);
              uVar26 = (ulong)uVar11;
            }
            if (uVar25 == uVar24) goto LAB_fffffff00996a838;
          }
          lVar18 = (ulong)(uVar24 & uVar12) * 8;
          lVar22 = plVar15[1];
          plVar5 = (long *)(*plVar15 + (long)(int)lVar18);
          if (lVar18 != (int)lVar18) {
            plVar5 = (long *)(*plVar15 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *plVar5 = (long)plVar17;
          lVar18 = (ulong)(uVar24 & uVar12) * 4;
          puVar3 = (undefined4 *)(lVar22 + (int)lVar18);
          if (lVar18 != (int)lVar18) {
            puVar3 = (undefined4 *)(lVar22 + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar3 = uVar7;
          lVar18 = (uVar21 & 0xffffffff) * 4;
          lVar22 = plVar15[3];
          puVar2 = (uint *)(plVar15[2] + (long)(int)lVar18);
          if (lVar18 != (int)lVar18) {
            puVar2 = (uint *)(plVar15[2] + lVar18 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar2 = *puVar2 | 1 << (ulong)(uVar24 - uVar23 & 0x1f);
          uVar6 = uVar6 & uVar24 >> 6;
          *(ulong *)(lVar22 + (ulong)uVar6 * 8) =
               *(ulong *)(lVar22 + (ulong)uVar6 * 8) | 1L << (uVar26 & 0x3f);
          lVar22 = (**(code **)(*plVar17 + 0x108))(*plVar17 + 0x108);
          plVar15[9] = plVar15[9] + lVar22;
          *(int *)(plVar15 + 7) = (int)plVar15[7] + 1;
        } while (uVar33 != 0);
      }
      uVar24 = (int)uVar32 + 1;
      uVar32 = (ulong)uVar24;
    } while (uVar24 <= *(uint *)(param_1 + 6));
    lVar22 = *plVar15;
    lVar28 = param_1[1];
    lVar18 = *param_1;
    param_1[1] = plVar15[1];
    *param_1 = lVar22;
    plVar15[1] = lVar28;
    *plVar15 = lVar18;
    lVar22 = plVar15[2];
    lVar28 = param_1[3];
    lVar18 = param_1[2];
    param_1[3] = plVar15[3];
    param_1[2] = lVar22;
    plVar15[3] = lVar28;
    plVar15[2] = lVar18;
    lVar22 = param_1[4];
    param_1[4] = plVar15[4];
    plVar15[4] = lVar22;
    lVar22 = param_1[5];
    *(int *)(param_1 + 5) = (int)plVar15[5];
    *(int *)(plVar15 + 5) = (int)lVar22;
    lVar22 = param_1[8];
    *(int *)(param_1 + 8) = (int)plVar15[8];
    *(int *)(plVar15 + 8) = (int)lVar22;
    uVar7 = *(undefined4 *)((long)param_1 + 0x2c);
    *(undefined4 *)((long)param_1 + 0x2c) = *(undefined4 *)((long)plVar15 + 0x2c);
    *(undefined4 *)((long)plVar15 + 0x2c) = uVar7;
    lVar22 = param_1[6];
    *(int *)(param_1 + 6) = (int)plVar15[6];
    *(int *)(plVar15 + 6) = (int)lVar22;
    uVar7 = *(undefined4 *)((long)param_1 + 0x34);
    *(undefined4 *)((long)param_1 + 0x34) = *(undefined4 *)((long)plVar15 + 0x34);
    *(undefined4 *)((long)plVar15 + 0x34) = uVar7;
    lVar22 = param_1[7];
    *(int *)(param_1 + 7) = (int)plVar15[7];
    *(int *)(plVar15 + 7) = (int)lVar22;
    uVar7 = *(undefined4 *)((long)param_1 + 0x3c);
    *(undefined4 *)((long)param_1 + 0x3c) = *(undefined4 *)((long)plVar15 + 0x3c);
    *(undefined4 *)((long)plVar15 + 0x3c) = uVar7;
    lVar22 = param_1[9];
    param_1[9] = plVar15[9];
    plVar15[9] = lVar22;
    bVar10 = *(byte *)((long)param_1 + 0x51);
    *(byte *)((long)param_1 + 0x51) = *(byte *)((long)plVar15 + 0x51) & 1;
    *(byte *)((long)plVar15 + 0x51) = bVar10 & 1;
    FUN_fffffff009968820(plVar15);
    thunk_EXT_FUN_80110000038fe270(&DAT_fffffff007ff09a8,plVar15);
  }
  return uVar16;
}

