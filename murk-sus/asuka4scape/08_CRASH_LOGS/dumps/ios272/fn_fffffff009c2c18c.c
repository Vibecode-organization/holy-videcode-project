// FUN_fffffff009c2c18c @ fffffff009c2c18c size=1372

/* WARNING: Removing unreachable block (ram,0xfffffff009c2c264) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2c1e0) */

void FUN_fffffff009c2c18c(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  long lVar15;
  ulong uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  
  lVar15 = *(long *)(param_1 + 0x40);
  if (lVar15 == 0) {
    lVar15 = 0;
  }
  uVar3 = *(uint *)(lVar15 + 0x98);
  thunk_EXT_FUN_8011000003a61cc0(param_2,0xc68);
  uVar2 = 0x14;
  if (*(uint *)(lVar15 + 0x98) < 0x15) {
    uVar2 = uVar3;
  }
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(param_1 + 0x38);
  uVar8 = *(undefined8 *)(lVar15 + 0x90);
  param_2[4] = uVar8;
  uVar17 = *(undefined8 *)(lVar15 + 0x58);
  param_2[6] = *(undefined8 *)(lVar15 + 0x60);
  param_2[5] = uVar17;
  *(undefined4 *)(param_2 + 9) = *(undefined4 *)(lVar15 + 0x80);
  param_2[7] = *(undefined8 *)(lVar15 + 0x68);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar15 + 0x70);
  param_2[10] = uVar8;
  uVar7 = *(undefined4 *)(*(long *)(lVar15 + 0x178) + 0xc);
  bVar4 = *(byte *)(*(long *)(lVar15 + 0x178) + 0x6e);
  *(undefined4 *)((long)param_2 + 100) = *(undefined4 *)(lVar15 + 0x9c);
  *(undefined4 *)(param_2 + 0xd) = uVar7;
  *(uint *)(param_2 + 0xb) = uVar2;
  *(uint *)((long)param_2 + 0x5c) = (uint)bVar4;
  uVar8 = *(undefined8 *)(param_1 + 0x50);
  param_2[1] = *(undefined8 *)(param_1 + 0x58);
  *param_2 = uVar8;
  param_2[2] = *(undefined8 *)(param_1 + 0x60);
  *(char *)((long)param_2 + 0x6c) = (char)*(undefined4 *)(lVar15 + 0x3ac);
  uVar7 = 0;
  if (*(long *)(lVar15 + 0x378) != 0) {
    uVar7 = *(undefined4 *)(*(long *)(lVar15 + 0x378) + 0x10);
  }
  *(undefined4 *)(param_2 + 0xe) = uVar7;
  param_2[0xf] = *(undefined8 *)(lVar15 + 0x380);
  *(byte *)((long)param_2 + 0x6d) = (byte)(*(uint *)(lVar15 + 0x3d0) >> 0x15) & 1;
  uVar8 = FUN_fffffff009c20364(lVar15);
  param_2[0x10] = uVar8;
  *(byte *)((long)param_2 + 0x6e) = (byte)((uint)*(undefined4 *)(lVar15 + 0x3d0) >> 0x19) & 1;
  param_2[8] = *(undefined8 *)(lVar15 + 0x78);
  puVar14 = param_2 + 0x11;
  if (uVar2 != 0) {
    uVar16 = 0;
    do {
      uVar9 = *(ulong *)(lVar15 + 0x180);
      uVar12 = uVar9 + (ulong)*(uint *)(lVar15 + 0x188) * 0x38;
      if (((uVar9 ^ uVar12) & 0xffc0000000000000) != 0) {
        uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar12 < uVar9) || (uVar12 - uVar9 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c2c68c:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      uVar5 = uVar16 * 0x38;
      uVar3 = (int)uVar5 + 0x38;
      if ((uint)(uVar12 - uVar9) < uVar3) goto LAB_fffffff009c2c68c;
      puVar10 = (undefined8 *)(uVar9 + uVar5);
      uVar12 = -(ulong)CARRY8(uVar9,uVar5);
      if ((uVar12 != CARRY8(uVar9,uVar5)) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      if (param_2 + 0x18d < puVar14) {
        FUN_fffffff009c48f64();
LAB_fffffff009c2c698:
        FUN_fffffff009c491c8();
LAB_fffffff009c2c69c:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      if (uVar16 == 0xd79436) goto LAB_fffffff009c2c698;
      uVar12 = uVar16 * 0x9800000000;
      if (((long)uVar12 < 0) ||
         ((uint)((int)(param_2 + 0x18d) - (int)puVar14) < (int)(uVar12 >> 0x20) + 0x98U))
      goto LAB_fffffff009c2c69c;
      puVar1 = (undefined8 *)((long)puVar14 + (uVar12 >> 0x20));
      uVar9 = (ulong)CARRY8((ulong)puVar14,uVar12 >> 0x20);
      uVar12 = -uVar9;
      if ((uVar12 != uVar9) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      *puVar1 = *puVar10;
      uVar8 = puVar10[1];
      puVar1[2] = puVar10[2];
      puVar1[1] = uVar8;
      uVar8 = puVar10[3];
      puVar1[4] = puVar10[4];
      puVar1[3] = uVar8;
      *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(puVar10 + 6);
      *(undefined2 *)((long)puVar1 + 0x32) = *(undefined2 *)((long)puVar10 + 0x34);
      puVar1[5] = puVar10[5];
      *(undefined1 *)((long)puVar1 + 0x35) = 0;
      *(undefined2 *)((long)puVar1 + 0x36) = 0;
      if (uVar16 < *(ulong *)(lVar15 + 0x328)) {
        uVar9 = *(ulong *)(lVar15 + 0x318);
        uVar12 = uVar9 + (ulong)*(uint *)(lVar15 + 800) * 0x18;
        if (((uVar9 ^ uVar12) & 0xffc0000000000000) != 0) {
          uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar12 < uVar9) || (uVar12 - uVar9 >> 0x20 != 0)) {
          FUN_fffffff009c48f64(puVar14 + uVar16 * 0x13);
LAB_fffffff009c2c6c0:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar13 = uVar16 * 0x18;
        if ((uint)(uVar12 - uVar9) < (int)uVar13 + 0x18U) goto LAB_fffffff009c2c6c0;
        uVar12 = -(ulong)CARRY8(uVar9,uVar13);
        if ((uVar12 != CARRY8(uVar9,uVar13)) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        FUN_fffffff009c2c6e8
                  (puVar14 + uVar16 * 0x13,(undefined1 *)(uVar9 + uVar13),
                   *(undefined1 *)(uVar9 + uVar13));
      }
      uVar9 = *(ulong *)(lVar15 + 0x180);
      uVar12 = uVar9 + (ulong)*(uint *)(lVar15 + 0x188) * 0x38;
      if (((uVar9 ^ uVar12) & 0xffc0000000000000) != 0) {
        uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar12 < uVar9) || (uVar12 - uVar9 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c2c6a8:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      if ((uint)(uVar12 - uVar9) < uVar3) goto LAB_fffffff009c2c6a8;
      uVar12 = -(ulong)CARRY8(uVar9,uVar5);
      if ((uVar12 != CARRY8(uVar9,uVar5)) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      *(undefined1 *)((long)puVar1 + 0x35) = *(undefined1 *)(uVar9 + uVar5 + 0x36);
      uVar12 = *(ulong *)(lVar15 + 0x308);
      if (uVar12 == 0) {
        puVar1[0x10] = 0;
        puVar1[0xf] = 0;
        *(undefined8 *)((long)puVar1 + 0x74) = 0;
        *(undefined8 *)((long)puVar1 + 0x6c) = 0;
        *(undefined8 *)((long)puVar1 + 100) = 0;
        *(undefined8 *)((long)puVar1 + 0x5c) = 0;
        *(undefined8 *)((long)puVar1 + 0x54) = 0;
        *(undefined8 *)((long)puVar1 + 0x4c) = 0;
        uVar7 = 0;
      }
      else {
        uVar9 = uVar12 + (ulong)*(uint *)(lVar15 + 0x310) * 0x3c;
        if (((uVar12 ^ uVar9) & 0xffc0000000000000) != 0) {
          uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar9 < uVar12) || (uVar9 - uVar12 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c2c6b4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar5 = uVar16 * 0x3c;
        if ((uint)(uVar9 - uVar12) < (int)uVar5 + 0x3cU) goto LAB_fffffff009c2c6b4;
        puVar10 = (undefined8 *)(uVar12 + uVar5);
        uVar9 = -(ulong)CARRY8(uVar12,uVar5);
        if ((uVar9 != CARRY8(uVar12,uVar5)) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar17 = puVar10[1];
        uVar8 = *puVar10;
        uVar19 = puVar10[3];
        uVar18 = puVar10[2];
        uVar21 = puVar10[5];
        uVar20 = puVar10[4];
        uVar22 = *(undefined8 *)((long)puVar10 + 0x2c);
        puVar1[0x10] = *(undefined8 *)((long)puVar10 + 0x34);
        puVar1[0xf] = uVar22;
        *(undefined8 *)((long)puVar1 + 0x74) = uVar21;
        *(undefined8 *)((long)puVar1 + 0x6c) = uVar20;
        *(undefined8 *)((long)puVar1 + 100) = uVar19;
        *(undefined8 *)((long)puVar1 + 0x5c) = uVar18;
        *(undefined8 *)((long)puVar1 + 0x54) = uVar17;
        *(undefined8 *)((long)puVar1 + 0x4c) = uVar8;
        uVar7 = *(undefined4 *)(lVar15 + 0x3b8);
      }
      *(undefined4 *)((long)param_2 + 0x74) = uVar7;
      if (uVar16 < *(ulong *)(lVar15 + 0x348) >> 5) {
        uVar9 = *(ulong *)(lVar15 + 0x350);
        uVar12 = uVar9 + (ulong)*(uint *)(lVar15 + 0x358) * 0x20;
        if (((uVar9 ^ uVar12) & 0xffc0000000000000) != 0) {
          uVar12 = uVar12 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar12 < uVar9) || (uVar12 - uVar9 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
LAB_fffffff009c2c6cc:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if ((uint)(uVar12 - uVar9) < (int)(uVar16 << 5) + 0x20U) goto LAB_fffffff009c2c6cc;
        uVar12 = uVar16 << 5 & 0xffffffe0;
        puVar10 = (undefined8 *)(uVar9 + uVar12);
        uVar9 = (ulong)CARRY8(uVar9,uVar12);
        uVar12 = -uVar9;
        if ((uVar12 != uVar9) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (uVar16 * 0x98 - (long)(int)(uVar16 * 0x98) != 0) {
          FUN_fffffff009c491c8();
          goto LAB_fffffff009c2c6d8;
        }
        uVar8 = *puVar10;
        puVar1[0x12] = puVar10[1];
        puVar1[0x11] = uVar8;
      }
      uVar16 = uVar16 + 1;
      if (uVar16 == uVar2) {
        return;
      }
    } while( true );
  }
  puVar6 = *(undefined1 **)(lVar15 + 0x318);
  puVar11 = puVar6 + (ulong)*(uint *)(lVar15 + 800) * 0x18;
  if ((((ulong)puVar6 ^ (ulong)puVar11) & 0xffc0000000000000) != 0) {
    puVar11 = (undefined1 *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
  }
  if ((puVar11 < puVar6) || ((ulong)((long)puVar11 - (long)puVar6) >> 0x20 != 0)) {
LAB_fffffff009c2c6d8:
    FUN_fffffff009c48f64();
  }
  else {
    if ((ulong)((long)puVar11 - (long)puVar6) < 0x18) goto LAB_fffffff009c2c6e0;
    FUN_fffffff009c2c6e8(puVar14,puVar6,*puVar6);
    puVar10 = *(undefined8 **)(lVar15 + 0x350);
    puVar14 = puVar10 + (ulong)*(uint *)(lVar15 + 0x358) * 4;
    if ((((ulong)puVar10 ^ (ulong)puVar14) & 0xffc0000000000000) != 0) {
      puVar14 = (undefined8 *)((ulong)puVar14 & 0xffffffffffff | 0xc8a2000000000000);
    }
    if ((puVar10 <= puVar14) && ((ulong)((long)puVar14 - (long)puVar10) >> 0x20 == 0)) {
      if (0x1f < (ulong)((long)puVar14 - (long)puVar10)) {
        uVar8 = *puVar10;
        param_2[0x23] = puVar10[1];
        param_2[0x22] = uVar8;
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28();
    }
  }
  FUN_fffffff009c48f64();
LAB_fffffff009c2c6e0:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

