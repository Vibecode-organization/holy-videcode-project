// FUN_fffffff009c35bd8 @ fffffff009c35bd8 size=500

/* WARNING: Removing unreachable block (ram,0xfffffff009c35ec8) */

undefined8 FUN_fffffff009c35bd8(long param_1,int *param_2,ulong param_3)

{
  ulong *puVar1;
  long *plVar2;
  uint uVar3;
  char *pcVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  undefined8 uVar16;
  ulong uVar17;
  undefined1 auVar18 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  uVar17 = *(ulong *)(param_1 + 0xe0) >> 6;
  do {
    uVar9 = (ulong)*(uint *)(param_1 + 0xf0);
    lVar11 = uVar9 - uVar17;
    if (uVar17 <= uVar9 && lVar11 != 0) {
      uVar12 = *(ulong *)(param_1 + 0xe8);
      uVar7 = uVar12 + uVar9 * 8;
      if (((uVar12 ^ uVar7) & 0xffc0000000000000) != 0) {
        uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar7 < uVar12) || (uVar7 - uVar12 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c35db8:
        FUN_fffffff009c48f64();
LAB_fffffff009c35dbc:
        FUN_fffffff009c48f3c();
LAB_fffffff009c35dc0:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f28();
      }
      uVar10 = uVar17 * 0x200 - 0x80000000;
      lVar8 = uVar17 * -0x40;
      iVar6 = (int)uVar17 * -0x40;
      uVar14 = uVar17 << 0x23;
      uVar13 = uVar17 * 8 - 0x80000008;
      do {
        uVar13 = uVar13 + 8;
        if (uVar13 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c35dac:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar14 < 0) || ((uint)(uVar7 - uVar12) < (int)(uVar14 >> 0x20) + 8U))
        goto LAB_fffffff009c35dac;
        puVar1 = (ulong *)(uVar12 + (uVar14 >> 0x20));
        uVar5 = (ulong)CARRY8(uVar12,uVar14 >> 0x20);
        uVar17 = -uVar5;
        if ((uVar17 != uVar5) || ((long)uVar17 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (*puVar1 != 0xffffffffffffffff) {
          uVar9 = *(ulong *)(param_1 + 0xd0);
          uVar17 = uVar9 + (ulong)*(uint *)(param_1 + 0xd8) * 8;
          if (((uVar9 ^ uVar17) & 0xffc0000000000000) != 0) {
            uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar17 < uVar9) || (uVar17 - uVar9 >> 0x20 != 0)) goto LAB_fffffff009c35db8;
          if (uVar10 < 0xffffffff00000000) goto LAB_fffffff009c35dbc;
          uVar7 = ~*puVar1;
          uVar7 = (uVar7 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar7 & 0x5555555555555555) << 1;
          uVar7 = (uVar7 & 0xcccccccccccccccc) >> 2 | (uVar7 & 0x3333333333333333) << 2;
          uVar7 = (uVar7 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar7 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar7 = (uVar7 & 0xff00ff00ff00ff00) >> 8 | (uVar7 & 0xff00ff00ff00ff) << 8;
          uVar7 = (uVar7 & 0xffff0000ffff0000) >> 0x10 | (uVar7 & 0xffff0000ffff) << 0x10;
          uVar12 = LZCOUNT(uVar7 >> 0x20 | uVar7 << 0x20);
          uVar7 = uVar12 - lVar8;
          if (((uVar7 & 0x1fffffff) >> 0x1c != 0) ||
             (uVar15 = (int)uVar7 * 8, (uint)(uVar17 - uVar9) < uVar15 + 8))
          goto LAB_fffffff009c35dc0;
          uVar13 = (ulong)CARRY8(uVar9,(ulong)uVar15);
          uVar17 = -uVar13;
          if ((uVar17 != uVar13) || ((long)uVar17 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if (*(long *)(uVar9 + uVar15) != 0) {
            auVar18 = FUN_fffffff009c49224();
            lVar11 = auVar18._0_8_;
            thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar11 + 0x140));
            uVar15 = (uint)param_3;
            if ((uVar15 != 0) && (uVar15 < *(uint *)(lVar11 + 0xd8))) {
              uVar9 = *(ulong *)(lVar11 + 0xd0);
              uVar17 = uVar9 + (ulong)*(uint *)(lVar11 + 0xd8) * 8;
              if (((uVar9 ^ uVar17) & 0xffc0000000000000) != 0) {
                uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
              }
              if ((uVar17 < uVar9) || (uVar17 - uVar9 >> 0x20 != 0)) {
                FUN_fffffff009c48f64();
              }
              else {
                uVar7 = param_3 & 0xffffffff;
                if (uVar7 * 8 - (long)(int)(uVar7 * 8) == 0) {
                  if (((param_3 & 0x1fffffff) >> 0x1c != 0) ||
                     (uVar3 = uVar15 * 8, (uint)(uVar17 - uVar9) < uVar3 + 8))
                  goto LAB_fffffff009c35f60;
                  plVar2 = (long *)(uVar9 + uVar3);
                  uVar9 = (ulong)CARRY8(uVar9,(ulong)uVar3);
                  uVar17 = -uVar9;
                  if ((uVar17 != uVar9) || ((long)uVar17 < 0)) {
                    /* WARNING: Subroutine does not return */
                    FUN_fffffff009c48f50();
                  }
                  lVar8 = *plVar2;
                  if ((lVar8 == 0) || (lVar8 == auVar18._8_8_)) {
                    if (uVar7 < *(ulong *)(lVar11 + 0xe0)) {
                      *(ulong *)(lVar11 + 0xe0) = uVar7;
                    }
                    *plVar2 = 0;
                    uVar9 = *(ulong *)(lVar11 + 0xe8);
                    uVar17 = uVar9 + (ulong)*(uint *)(lVar11 + 0xf0) * 8;
                    if (((uVar9 ^ uVar17) & 0xffc0000000000000) != 0) {
                      uVar17 = uVar17 & 0xffffffffffff | 0xc8a2000000000000;
                    }
                    if ((uVar17 < uVar9) || (uVar17 - uVar9 >> 0x20 != 0)) {
                      FUN_fffffff009c48f64();
LAB_fffffff009c35f6c:
                    /* WARNING: Subroutine does not return */
                      FUN_fffffff009c48f50();
                    }
                    uVar15 = uVar15 >> 3 & 0x1ffffff8;
                    if ((uint)(uVar17 - uVar9) < uVar15 + 8) {
                    /* WARNING: Subroutine does not return */
                      FUN_fffffff009c48f28();
                    }
                    puVar1 = (ulong *)(uVar9 + uVar15);
                    uVar9 = (ulong)CARRY8(uVar9,(ulong)uVar15);
                    uVar17 = -uVar9;
                    if ((uVar17 != uVar9) || ((long)uVar17 < 0)) goto LAB_fffffff009c35f6c;
                    *puVar1 = *puVar1 & ~(1L << (param_3 & 0x3f));
                    goto LAB_fffffff009c35ea8;
                  }
                  pcVar4 = "Entry for surface handle %d %p is not equal to %p";
                  goto LAB_fffffff009c35ea4;
                }
              }
              FUN_fffffff009c48f3c();
LAB_fffffff009c35f60:
                    /* WARNING: Subroutine does not return */
              FUN_fffffff009c48f28();
            }
            pcVar4 = "trying to free apparently bogus surface handle %d";
LAB_fffffff009c35ea4:
            thunk_EXT_FUN_80110000038fe9a0(pcVar4);
LAB_fffffff009c35ea8:
            uVar16 = thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar11 + 0x140));
            return uVar16;
          }
          *(ulong *)(param_1 + 0xe0) = uVar7 + 1;
          uVar16 = 1;
          *puVar1 = *puVar1 | 1L << (uVar12 & 0x3f);
          *param_2 = (int)uVar12 - iVar6;
          goto LAB_fffffff009c35d84;
        }
        uVar10 = uVar10 + 0x200;
        lVar8 = lVar8 + -0x40;
        iVar6 = iVar6 + -0x40;
        uVar14 = uVar14 + 0x800000000;
        lVar11 = lVar11 + -1;
        uVar17 = uVar9;
      } while (lVar11 != 0);
    }
    uVar9 = FUN_fffffff009c32250(param_1);
    if ((uVar9 & 1) == 0) {
      uVar16 = 0;
LAB_fffffff009c35d84:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
      return uVar16;
    }
  } while( true );
}

