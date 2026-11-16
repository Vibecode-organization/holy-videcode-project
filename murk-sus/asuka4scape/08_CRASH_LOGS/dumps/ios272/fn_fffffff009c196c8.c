// FUN_fffffff009c196c8 @ fffffff009c196c8 size=544

/* WARNING: Removing unreachable block (ram,0xfffffff009c19b38) */

long * FUN_fffffff009c196c8(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  ulong uVar12;
  long *plVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong unaff_x30;
  undefined1 auVar18 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  uVar7 = *(uint *)(param_1 + 0x2c);
  if (uVar7 == 4) {
    uVar14 = param_1 + 0x38;
LAB_fffffff009c19708:
    uVar10 = *(uint *)(param_1 + 0x28);
    if (0 < (int)uVar10) {
      uVar8 = uVar14 + (ulong)uVar7 * 8;
      if (((uVar14 ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar14 <= uVar8) && (uVar8 - uVar14 >> 0x20 == 0)) {
        uVar11 = 0;
        uVar12 = 0xffffffff80000000;
        uVar15 = 0;
        do {
          if (uVar12 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c198d0:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if (((long)uVar11 < 0) || ((uint)(uVar8 - uVar14) < (int)(uVar11 >> 0x20) + 8U))
          goto LAB_fffffff009c198d0;
          plVar4 = (long *)(uVar14 + (uVar11 >> 0x20));
          uVar5 = (ulong)CARRY8(uVar14,uVar11 >> 0x20);
          uVar3 = -uVar5;
          if ((uVar3 != uVar5) || ((long)uVar3 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if (*plVar4 == param_2) {
            if (uVar12 < 0xffffffff00000000) goto LAB_fffffff009c198e4;
            *plVar4 = 0;
            *(uint *)(param_1 + 0x28) = uVar10 - 1;
            uVar10 = uVar10 - 1;
            goto LAB_fffffff009c197b8;
          }
          uVar15 = uVar15 + 1;
          uVar12 = uVar12 + 8;
          uVar11 = uVar11 + 0x800000000;
        } while (uVar10 != uVar15);
        goto LAB_fffffff009c19894;
      }
      FUN_fffffff009c48f64();
      goto LAB_fffffff009c198dc;
    }
    uVar15 = 0;
LAB_fffffff009c197b8:
    if ((int)uVar10 <= (int)uVar15) {
LAB_fffffff009c19894:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c198b0);
        (*pcVar1)();
      }
      plVar4 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
      return plVar4;
    }
    uVar8 = uVar14 + (ulong)uVar7 * 8;
    if (((uVar14 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar14 <= uVar8) && (uVar8 - uVar14 >> 0x20 == 0)) {
      uVar11 = uVar15 << 0x23;
      uVar12 = (uVar15 & 0xffffffff) * 8 - 0x80000008;
      lVar9 = (ulong)uVar10 - (uVar15 & 0xffffffff);
      do {
        if (uVar12 + 0x10 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198b8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar15 = uVar11 + 0x800000000;
        if ((long)uVar15 < 0) goto LAB_fffffff009c198b8;
        uVar7 = (uint)(uVar8 - uVar14);
        if (uVar7 < (int)(uVar15 >> 0x20) + 8U) goto LAB_fffffff009c198b8;
        uVar3 = (ulong)CARRY8(uVar14,uVar15 >> 0x20);
        uVar5 = -uVar3;
        if ((uVar5 != uVar3) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar12 = uVar12 + 8;
        if (uVar12 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198c4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar11 < 0) || (uVar3 = uVar11 >> 0x20, uVar7 < (int)(uVar11 >> 0x20) + 8U))
        goto LAB_fffffff009c198c4;
        uVar6 = (ulong)CARRY8(uVar14,uVar3);
        uVar5 = -uVar6;
        if ((uVar5 != uVar6) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar11 = uVar11 + 0x800000000;
        *(undefined8 *)(uVar14 + uVar3) = *(undefined8 *)(uVar14 + (uVar15 >> 0x20));
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
      goto LAB_fffffff009c19894;
    }
  }
  else {
    if (-1 < (int)uVar7) {
      uVar14 = *(ulong *)(param_1 + 0x30);
      goto LAB_fffffff009c19708;
    }
LAB_fffffff009c198dc:
    FUN_fffffff009c48f14();
  }
  FUN_fffffff009c48f64();
LAB_fffffff009c198e4:
  lVar9 = FUN_fffffff009c48f3c();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x20));
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(lVar9 + 0x28));
  if (plVar4 != (long *)0x0) {
    uVar7 = *(uint *)(lVar9 + 0x2c);
    if (uVar7 == 4) {
      uVar14 = lVar9 + 0x38;
    }
    else {
      if ((int)uVar7 < 0) goto LAB_fffffff009c19a58;
      uVar14 = *(ulong *)(lVar9 + 0x30);
    }
    if (0 < *(int *)(lVar9 + 0x28)) {
      uVar8 = uVar14 + (ulong)uVar7 * 8;
      if (((uVar14 ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar8 < uVar14) || (uVar8 - uVar14 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c19a58:
        auVar18 = FUN_fffffff009c48f14();
        lVar9 = auVar18._0_8_;
        plVar4 = (long *)FUN_fffffff009c37a94(DAT_fffffff00af483b0);
        if (((int)plVar4 != 0) &&
           (plVar4 = (long *)FUN_fffffff009c19b40(lVar9,lVar9,auVar18._8_8_,0),
           ((ulong)plVar4 & 1) == 0)) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0x20));
          plVar4 = *(long **)(lVar9 + 0x18);
          if (plVar4 == (long *)0x0) {
            plVar4 = (long *)thunk_EXT_FUN_80110000038ccc44(1);
            if (*(long **)(lVar9 + 0x18) != (long *)0x0) {
              (**(code **)(**(long **)(lVar9 + 0x18) + 0x28))();
            }
            *(long **)(lVar9 + 0x18) = plVar4;
          }
          (**(code **)(*plVar4 + 0xf0))(plVar4,auVar18._8_8_);
          plVar4 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x20));
          return plVar4;
        }
        return plVar4;
      }
      uVar15 = 0;
      lVar16 = 0x10000000;
      lVar17 = 1;
      do {
        if (((long)uVar15 < 0) || ((uint)(uVar8 - uVar14) < (int)(uVar15 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar11 = (ulong)CARRY8(uVar14,uVar15 >> 0x20);
        uVar12 = -uVar11;
        if ((uVar12 != uVar11) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        plVar13 = *(long **)(uVar14 + (uVar15 >> 0x20));
        iVar2 = FUN_fffffff009c410e8(plVar13);
        if (iVar2 != 0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar13);
          (**(code **)(*plVar13 + 0x28))(plVar13);
        }
        if (*(int *)(lVar9 + 0x28) <= lVar17) goto LAB_fffffff009c19a24;
        lVar17 = lVar17 + 1;
        uVar15 = uVar15 + 0x800000000;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      FUN_fffffff009c48f3c();
    }
  }
LAB_fffffff009c19a24:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0x20));
  return plVar4;
}

