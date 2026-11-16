// FUN_fffffff009c1946c @ fffffff009c1946c size=604

/* WARNING: Removing unreachable block (ram,0xfffffff009c19b38) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c198ac) */

long * FUN_fffffff009c1946c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  ulong unaff_x30;
  undefined1 auVar20 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  uVar8 = *(uint *)(param_1 + 0x28);
  uVar18 = (ulong)uVar8;
  if (0xffff < (int)uVar8) goto LAB_fffffff009c19668;
  uVar11 = *(uint *)(param_1 + 0x2c);
  uVar16 = (ulong)uVar11;
  if (uVar11 == 4) {
    uVar15 = 0;
    uVar17 = param_1 + 0x38;
LAB_fffffff009c194cc:
    if (uVar8 == uVar11) {
      uVar3 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bc00,uVar18 << 4);
      if (uVar3 == 0) goto LAB_fffffff009c196c4;
      uVar16 = uVar18 << 1;
      uVar8 = *(uint *)(param_1 + 0x28);
      uVar7 = (ulong)uVar8;
      if (0 < (int)uVar8) {
        uVar9 = uVar17 + uVar18 * 8;
        if (((uVar17 ^ uVar9) & 0xffc0000000000000) != 0) {
          uVar9 = uVar9 & 0xffffffffffff | 0xc8a2000000000000;
        }
        uVar18 = uVar3 + uVar18 * 0x10;
        if (((uVar3 ^ uVar18) & 0xffc0000000000000) != 0) {
          uVar18 = uVar18 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar9 < uVar17) || (uVar9 - uVar17 >> 0x20 != 0)) goto LAB_fffffff009c196c0;
        lVar12 = 0x10000000;
        uVar6 = 0;
        do {
          if (lVar12 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c19698:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if ((long)uVar6 < 0) goto LAB_fffffff009c19698;
          uVar13 = uVar6 >> 0x20;
          uVar11 = (int)(uVar6 >> 0x20) + 8;
          if ((uint)(uVar9 - uVar17) < uVar11) goto LAB_fffffff009c19698;
          uVar5 = -(ulong)CARRY8(uVar17,uVar13);
          if ((uVar5 != CARRY8(uVar17,uVar13)) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if ((uVar18 - uVar3 & 0xffffffff00000000) != 0 || uVar18 < uVar3) {
            FUN_fffffff009c48f64();
LAB_fffffff009c196a4:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if ((uint)(uVar18 - uVar3) < uVar11) goto LAB_fffffff009c196a4;
          uVar5 = -(ulong)CARRY8(uVar3,uVar13);
          if ((uVar5 != CARRY8(uVar3,uVar13)) || ((long)uVar5 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          *(undefined8 *)(uVar3 + uVar13) = *(undefined8 *)(uVar17 + uVar13);
          lVar12 = lVar12 + -1;
          uVar6 = uVar6 + 0x800000000;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      if (uVar15 != 0) {
        lVar12 = (long)(int)*(uint *)(param_1 + 0x2c) << 3;
        if (0x7fffffff < *(uint *)(param_1 + 0x2c)) {
          lVar12 = -0x8000000000000000;
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bc50,uVar15,lVar12);
        uVar8 = *(uint *)(param_1 + 0x28);
      }
      *(ulong *)(param_1 + 0x30) = uVar3;
      *(int *)(param_1 + 0x2c) = (int)uVar16;
      uVar17 = uVar3;
    }
    *(uint *)(param_1 + 0x28) = uVar8 + 1;
    uVar18 = uVar17 + (uVar16 & 0xffffffff) * 8;
    uVar16 = uVar18 - uVar17;
    if ((uVar18 < uVar17) || (uVar16 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      uVar11 = -uVar8;
      if (-1 < (int)uVar8) {
        uVar11 = uVar8;
      }
      uVar18 = (ulong)uVar11 * -8;
      if (-1 < (int)uVar8) {
        uVar18 = (ulong)uVar11 * 8;
      }
      if (uVar18 == (long)(int)uVar18) {
        if ((-1 < (long)uVar18) && ((int)uVar18 + 8U <= (uint)uVar16)) {
          uVar15 = (ulong)CARRY8(uVar17,uVar18 & 0x7ffffff8);
          uVar16 = -uVar15;
          if ((uVar16 != uVar15) || ((long)uVar16 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          *(undefined8 *)(uVar17 + (uVar18 & 0x7ffffff8)) = param_2;
LAB_fffffff009c19668:
          if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c19690);
            (*pcVar1)();
          }
          plVar4 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
          return plVar4;
        }
        goto LAB_fffffff009c196b4;
      }
    }
    FUN_fffffff009c48f3c();
LAB_fffffff009c196b4:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  if (-1 < (int)uVar11) {
    uVar15 = *(ulong *)(param_1 + 0x30);
    uVar17 = uVar15;
    goto LAB_fffffff009c194cc;
  }
  FUN_fffffff009c48f14();
LAB_fffffff009c196c0:
  FUN_fffffff009c48f64();
LAB_fffffff009c196c4:
  auVar20 = FUN_fffffff009c48f78();
  lVar12 = auVar20._0_8_;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 0x20));
  uVar8 = *(uint *)(lVar12 + 0x2c);
  if (uVar8 == 4) {
    uVar18 = lVar12 + 0x38;
LAB_fffffff009c19708:
    uVar11 = *(uint *)(lVar12 + 0x28);
    if (0 < (int)uVar11) {
      uVar16 = uVar18 + (ulong)uVar8 * 8;
      if (((uVar18 ^ uVar16) & 0xffc0000000000000) != 0) {
        uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar18 <= uVar16) && (uVar16 - uVar18 >> 0x20 == 0)) {
        uVar3 = 0;
        uVar15 = 0xffffffff80000000;
        uVar17 = 0;
        do {
          if (uVar15 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c198d0:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if (((long)uVar3 < 0) || ((uint)(uVar16 - uVar18) < (int)(uVar3 >> 0x20) + 8U))
          goto LAB_fffffff009c198d0;
          plVar4 = (long *)(uVar18 + (uVar3 >> 0x20));
          uVar9 = (ulong)CARRY8(uVar18,uVar3 >> 0x20);
          uVar7 = -uVar9;
          if ((uVar7 != uVar9) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if (*plVar4 == auVar20._8_8_) {
            if (uVar15 < 0xffffffff00000000) goto LAB_fffffff009c198e4;
            *plVar4 = 0;
            *(uint *)(lVar12 + 0x28) = uVar11 - 1;
            uVar11 = uVar11 - 1;
            goto LAB_fffffff009c197b8;
          }
          uVar17 = uVar17 + 1;
          uVar15 = uVar15 + 8;
          uVar3 = uVar3 + 0x800000000;
        } while (uVar11 != uVar17);
        goto LAB_fffffff009c19894;
      }
      FUN_fffffff009c48f64();
      goto LAB_fffffff009c198dc;
    }
    uVar17 = 0;
LAB_fffffff009c197b8:
    if ((int)uVar11 <= (int)uVar17) {
LAB_fffffff009c19894:
      plVar4 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x20));
      return plVar4;
    }
    uVar16 = uVar18 + (ulong)uVar8 * 8;
    if (((uVar18 ^ uVar16) & 0xffc0000000000000) != 0) {
      uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar18 <= uVar16) && (uVar16 - uVar18 >> 0x20 == 0)) {
      uVar3 = uVar17 << 0x23;
      uVar15 = (uVar17 & 0xffffffff) * 8 - 0x80000008;
      lVar10 = (ulong)uVar11 - (uVar17 & 0xffffffff);
      do {
        if (uVar15 + 0x10 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198b8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar17 = uVar3 + 0x800000000;
        if ((long)uVar17 < 0) goto LAB_fffffff009c198b8;
        uVar8 = (uint)(uVar16 - uVar18);
        if (uVar8 < (int)(uVar17 >> 0x20) + 8U) goto LAB_fffffff009c198b8;
        uVar7 = (ulong)CARRY8(uVar18,uVar17 >> 0x20);
        uVar9 = -uVar7;
        if ((uVar9 != uVar7) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar15 = uVar15 + 8;
        if (uVar15 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198c4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar3 < 0) || (uVar7 = uVar3 >> 0x20, uVar8 < (int)(uVar3 >> 0x20) + 8U))
        goto LAB_fffffff009c198c4;
        uVar6 = (ulong)CARRY8(uVar18,uVar7);
        uVar9 = -uVar6;
        if ((uVar9 != uVar6) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar3 = uVar3 + 0x800000000;
        *(undefined8 *)(uVar18 + uVar7) = *(undefined8 *)(uVar18 + (uVar17 >> 0x20));
        lVar10 = lVar10 + -1;
      } while (lVar10 != 0);
      goto LAB_fffffff009c19894;
    }
  }
  else {
    if (-1 < (int)uVar8) {
      uVar18 = *(ulong *)(lVar12 + 0x30);
      goto LAB_fffffff009c19708;
    }
LAB_fffffff009c198dc:
    FUN_fffffff009c48f14();
  }
  FUN_fffffff009c48f64();
LAB_fffffff009c198e4:
  lVar12 = FUN_fffffff009c48f3c();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 0x20));
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(lVar12 + 0x28));
  if (plVar4 != (long *)0x0) {
    uVar8 = *(uint *)(lVar12 + 0x2c);
    if (uVar8 == 4) {
      uVar18 = lVar12 + 0x38;
    }
    else {
      if ((int)uVar8 < 0) goto LAB_fffffff009c19a58;
      uVar18 = *(ulong *)(lVar12 + 0x30);
    }
    if (0 < *(int *)(lVar12 + 0x28)) {
      uVar16 = uVar18 + (ulong)uVar8 * 8;
      if (((uVar18 ^ uVar16) & 0xffc0000000000000) != 0) {
        uVar16 = uVar16 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar16 < uVar18) || (uVar16 - uVar18 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c19a58:
        auVar20 = FUN_fffffff009c48f14();
        lVar12 = auVar20._0_8_;
        plVar4 = (long *)FUN_fffffff009c37a94(DAT_fffffff00af483b0);
        if (((int)plVar4 != 0) &&
           (plVar4 = (long *)FUN_fffffff009c19b40(lVar12,lVar12,auVar20._8_8_,0),
           ((ulong)plVar4 & 1) == 0)) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar12 + 0x20));
          plVar4 = *(long **)(lVar12 + 0x18);
          if (plVar4 == (long *)0x0) {
            plVar4 = (long *)thunk_EXT_FUN_80110000038ccc44(1);
            if (*(long **)(lVar12 + 0x18) != (long *)0x0) {
              (**(code **)(**(long **)(lVar12 + 0x18) + 0x28))();
            }
            *(long **)(lVar12 + 0x18) = plVar4;
          }
          (**(code **)(*plVar4 + 0xf0))(plVar4,auVar20._8_8_);
          plVar4 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x20));
          return plVar4;
        }
        return plVar4;
      }
      uVar17 = 0;
      lVar19 = 0x10000000;
      lVar10 = 1;
      do {
        if (((long)uVar17 < 0) || ((uint)(uVar16 - uVar18) < (int)(uVar17 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar3 = (ulong)CARRY8(uVar18,uVar17 >> 0x20);
        uVar15 = -uVar3;
        if ((uVar15 != uVar3) || ((long)uVar15 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        plVar14 = *(long **)(uVar18 + (uVar17 >> 0x20));
        iVar2 = FUN_fffffff009c410e8(plVar14);
        if (iVar2 != 0) {
          (**(code **)(*plVar4 + 0xe8))(plVar4,plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        if (*(int *)(lVar12 + 0x28) <= lVar10) goto LAB_fffffff009c19a24;
        lVar10 = lVar10 + 1;
        uVar17 = uVar17 + 0x800000000;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
      FUN_fffffff009c48f3c();
    }
  }
LAB_fffffff009c19a24:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar12 + 0x20));
  return plVar4;
}

