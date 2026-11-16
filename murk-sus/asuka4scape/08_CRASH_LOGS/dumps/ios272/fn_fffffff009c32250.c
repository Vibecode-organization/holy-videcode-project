// FUN_fffffff009c32250 @ fffffff009c32250 size=728

undefined8 FUN_fffffff009c32250(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  
  uVar1 = *(uint *)(param_1 + 0xd8);
  uVar13 = (ulong)uVar1;
  if (uVar1 == 0) {
    uVar16 = 0x200;
  }
  else {
    if (uVar1 >> 0x10 != 0) {
      return 0;
    }
    uVar16 = uVar13 << 1;
  }
  uVar15 = uVar16 >> 6;
  uVar12 = *(ulong *)(param_1 + 0xd0);
  uVar11 = *(ulong *)(param_1 + 0xe8);
  uVar2 = *(uint *)(param_1 + 0xf0);
  uVar14 = (ulong)uVar2;
  uVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806c100,uVar16 << 3);
  *(undefined8 *)(param_1 + 0xd0) = uVar3;
  *(int *)(param_1 + 0xd8) = (int)uVar16;
  puVar4 = (undefined8 *)thunk_EXT_FUN_80110000038fe5cc(uVar15 << 3);
  *(undefined8 **)(param_1 + 0xe8) = puVar4;
  *(int *)(param_1 + 0xf0) = (int)uVar15;
  uVar16 = *(ulong *)(param_1 + 0xd0);
  if ((uVar16 == 0) || (puVar4 == (undefined8 *)0x0)) {
    thunk_EXT_FUN_80110000038fe9a0("IOMalloc failed to alloc handles");
    *(ulong *)(param_1 + 0xd0) = uVar12;
    *(uint *)(param_1 + 0xd8) = uVar1;
    *(ulong *)(param_1 + 0xe8) = uVar11;
    *(uint *)(param_1 + 0xf0) = uVar2;
    return 0;
  }
  if (uVar12 == 0) {
    uVar13 = (long)(puVar4 + uVar15) - (long)puVar4;
    if ((puVar4 <= puVar4 + uVar15) && (uVar13 >> 0x20 == 0)) {
      if (7 < uVar13) {
        *puVar4 = 1;
        return 1;
      }
      goto LAB_fffffff009c32524;
    }
LAB_fffffff009c3251c:
    FUN_fffffff009c48f64();
  }
  else {
    if (uVar1 != 0) {
      uVar5 = uVar12 + uVar13 * 8;
      if (((uVar12 ^ uVar5) & 0xffc0000000000000) != 0) {
        uVar5 = uVar5 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar5 < uVar12) || (uVar5 - uVar12 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
        goto LAB_fffffff009c3251c;
      }
      lVar7 = 0x10000000;
      uVar6 = 0;
      uVar10 = uVar13;
      do {
        if (lVar7 == 0) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c324ec:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((long)uVar6 < 0) goto LAB_fffffff009c324ec;
        uVar8 = uVar6 >> 0x20;
        uVar1 = (int)(uVar6 >> 0x20) + 8;
        if ((uint)(uVar5 - uVar12) < uVar1) goto LAB_fffffff009c324ec;
        uVar9 = -(ulong)CARRY8(uVar12,uVar8);
        if ((uVar9 != CARRY8(uVar12,uVar8)) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar9 = uVar16 + (ulong)*(uint *)(param_1 + 0xd8) * 8;
        if (((uVar16 ^ uVar9) & 0xffc0000000000000) != 0) {
          uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar9 < uVar16) || (uVar9 - uVar16 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c324f8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((uint)(uVar9 - uVar16) < uVar1) goto LAB_fffffff009c324f8;
        uVar9 = -(ulong)CARRY8(uVar16,uVar8);
        if ((uVar9 != CARRY8(uVar16,uVar8)) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        *(undefined8 *)(uVar16 + uVar8) = *(undefined8 *)(uVar12 + uVar8);
        lVar7 = lVar7 + -1;
        uVar6 = uVar6 + 0x800000000;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (uVar2 == 0) {
LAB_fffffff009c32450:
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806c150,uVar12,uVar13 << 3);
      thunk_EXT_FUN_80110000038fe6b0(uVar11,uVar14 << 3);
      return 1;
    }
    uVar16 = uVar11 + uVar14 * 8;
    if (((uVar11 ^ uVar16) & 0xffc0000000000000) != 0) {
      uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar11 <= uVar16) && (uVar16 - uVar11 >> 0x20 == 0)) {
      lVar7 = 0x10000000;
      uVar5 = 0;
      uVar6 = uVar14;
      do {
        if (lVar7 == 0) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c32504:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((long)uVar5 < 0) goto LAB_fffffff009c32504;
        uVar10 = uVar5 >> 0x20;
        uVar1 = (int)(uVar5 >> 0x20) + 8;
        if ((uint)(uVar16 - uVar11) < uVar1) goto LAB_fffffff009c32504;
        uVar8 = -(ulong)CARRY8(uVar11,uVar10);
        if ((uVar8 != CARRY8(uVar11,uVar10)) || ((long)uVar8 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (puVar4 + uVar15 < puVar4) {
          FUN_fffffff009c48f64();
LAB_fffffff009c32510:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((uint)((int)(puVar4 + uVar15) - (int)puVar4) < uVar1) goto LAB_fffffff009c32510;
        uVar8 = -(ulong)CARRY8((ulong)puVar4,uVar10);
        if ((uVar8 != CARRY8((ulong)puVar4,uVar10)) || ((long)uVar8 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        *(undefined8 *)((long)puVar4 + uVar10) = *(undefined8 *)(uVar11 + uVar10);
        lVar7 = lVar7 + -1;
        uVar5 = uVar5 + 0x800000000;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
      goto LAB_fffffff009c32450;
    }
  }
  FUN_fffffff009c48f64();
LAB_fffffff009c32524:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

