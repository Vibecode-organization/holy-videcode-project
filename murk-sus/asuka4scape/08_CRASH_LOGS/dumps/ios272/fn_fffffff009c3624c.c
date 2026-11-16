// FUN_fffffff009c3624c @ fffffff009c3624c size=356

undefined8 FUN_fffffff009c3624c(long param_1,int *param_2,ulong param_3)

{
  ulong *puVar1;
  long *plVar2;
  char *pcVar3;
  ulong uVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  undefined8 uVar15;
  ulong uVar16;
  undefined1 auVar17 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x148));
  uVar16 = *(ulong *)(param_1 + 0x128) >> 6;
  do {
    uVar4 = (ulong)*(uint *)(param_1 + 0x120);
    lVar5 = uVar4 - uVar16;
    if (uVar16 <= uVar4 && lVar5 != 0) {
      uVar8 = *(ulong *)(param_1 + 0x118);
      uVar7 = uVar8 + uVar4 * 8;
      if (((uVar8 ^ uVar7) & 0xffc0000000000000) != 0) {
        uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar7 < uVar8) || (uVar7 - uVar8 >> 0x20 != 0)) {
        auVar17 = FUN_fffffff009c48f64();
        lVar5 = auVar17._0_8_;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar5 + 0x148));
        uVar14 = (uint)param_3;
        if ((uVar14 != 0) && (uVar14 < *(uint *)(lVar5 + 0x110))) {
          uVar4 = *(ulong *)(lVar5 + 0x108);
          uVar16 = uVar4 + (ulong)*(uint *)(lVar5 + 0x110) * 8;
          if (((uVar4 ^ uVar16) & 0xffc0000000000000) != 0) {
            uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
          }
          if ((uVar16 < uVar4) || (uVar16 - uVar4 >> 0x20 != 0)) {
            FUN_fffffff009c48f64();
          }
          else {
            lVar9 = (param_3 & 0xffffffff) * 8;
            if (lVar9 - (int)lVar9 == 0) {
              if (((param_3 & 0x1fffffff) >> 0x1c != 0) ||
                 (uVar14 = uVar14 * 8, (uint)(uVar16 - uVar4) < uVar14 + 8))
              goto LAB_fffffff009c364b8;
              plVar2 = (long *)(uVar4 + uVar14);
              uVar4 = (ulong)CARRY8(uVar4,(ulong)uVar14);
              uVar16 = -uVar4;
              if ((uVar16 != uVar4) || ((long)uVar16 < 0)) {
                    /* WARNING: Subroutine does not return */
                FUN_fffffff009c48f50();
              }
              if (*plVar2 == 0) {
                *plVar2 = auVar17._8_8_;
                uVar15 = 1;
                goto LAB_fffffff009c36484;
              }
              pcVar3 = "Entry for shared event handle %d is not NULL (%p)";
              goto LAB_fffffff009c3647c;
            }
          }
          FUN_fffffff009c48f3c();
LAB_fffffff009c364b8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        pcVar3 = "trying to use apparently bogus event handle %d";
LAB_fffffff009c3647c:
        thunk_EXT_FUN_80110000038fe9a0(pcVar3);
        uVar15 = 0;
LAB_fffffff009c36484:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar5 + 0x148));
        return uVar15;
      }
      uVar10 = uVar16 << 6 ^ 0xffffffffffffffff;
      iVar6 = (int)uVar16 * -0x40;
      uVar11 = uVar16 << 0x23;
      uVar12 = uVar16 * 8 - 0x80000008;
      do {
        uVar12 = uVar12 + 8;
        if (uVar12 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c363a4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar11 < 0) || ((uint)(uVar7 - uVar8) < (int)(uVar11 >> 0x20) + 8U))
        goto LAB_fffffff009c363a4;
        puVar1 = (ulong *)(uVar8 + (uVar11 >> 0x20));
        uVar16 = (ulong)CARRY8(uVar8,uVar11 >> 0x20);
        uVar13 = -uVar16;
        if ((uVar13 != uVar16) || ((long)uVar13 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        if (*puVar1 != 0xffffffffffffffff) {
          uVar16 = ~*puVar1;
          uVar16 = (uVar16 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar16 & 0x5555555555555555) << 1;
          uVar16 = (uVar16 & 0xcccccccccccccccc) >> 2 | (uVar16 & 0x3333333333333333) << 2;
          uVar16 = (uVar16 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar16 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar16 = (uVar16 & 0xff00ff00ff00ff00) >> 8 | (uVar16 & 0xff00ff00ff00ff) << 8;
          uVar16 = (uVar16 & 0xffff0000ffff0000) >> 0x10 | (uVar16 & 0xffff0000ffff) << 0x10;
          uVar16 = LZCOUNT(uVar16 >> 0x20 | uVar16 << 0x20);
          *(ulong *)(param_1 + 0x128) = uVar16 - uVar10;
          uVar15 = 1;
          *puVar1 = *puVar1 | 1L << (uVar16 & 0x3f);
          *param_2 = (int)uVar16 - iVar6;
          goto LAB_fffffff009c3637c;
        }
        uVar10 = uVar10 - 0x40;
        iVar6 = iVar6 + -0x40;
        uVar11 = uVar11 + 0x800000000;
        lVar5 = lVar5 + -1;
        uVar16 = uVar4;
      } while (lVar5 != 0);
    }
    uVar4 = FUN_fffffff009c35f74(param_1);
    if ((uVar4 & 1) == 0) {
      uVar15 = 0;
LAB_fffffff009c3637c:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x148));
      return uVar15;
    }
  } while( true );
}

