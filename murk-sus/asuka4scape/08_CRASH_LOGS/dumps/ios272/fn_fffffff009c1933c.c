// FUN_fffffff009c1933c @ fffffff009c1933c size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009c19b38) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c198ac) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c1968c) */

long * FUN_fffffff009c1933c(long param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  long *plVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  ulong unaff_x30;
  undefined1 auVar20 [16];
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x20));
  uVar7 = *(uint *)(param_1 + 0x2c);
  if (uVar7 == 4) {
    uVar18 = param_1 + 0x38;
LAB_fffffff009c19388:
    if (*(int *)(param_1 + 0x28) < 1) {
LAB_fffffff009c1942c:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
        plVar3 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x20));
        return plVar3;
      }
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c19458);
      (*pcVar1)();
    }
    uVar8 = uVar18 + (ulong)uVar7 * 8;
    if (((uVar18 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar18 <= uVar8) && (uVar8 - uVar18 >> 0x20 == 0)) {
      uVar15 = 0;
      lVar16 = 0x10000000;
      lVar17 = 1;
      do {
        if (((long)uVar15 < 0) || ((uint)(uVar8 - uVar18) < (int)(uVar15 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar11 = (ulong)CARRY8(uVar18,uVar15 >> 0x20);
        uVar9 = -uVar11;
        if ((uVar9 != uVar11) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        thunk_EXT_FUN_801100000322ffdc("\tfence: %p\n");
        if (*(int *)(param_1 + 0x28) <= lVar17) goto LAB_fffffff009c1942c;
        lVar17 = lVar17 + 1;
        uVar15 = uVar15 + 0x800000000;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      FUN_fffffff009c48f3c();
      goto LAB_fffffff009c1942c;
    }
    FUN_fffffff009c48f64();
  }
  else if (-1 < (int)uVar7) {
    uVar18 = *(ulong *)(param_1 + 0x30);
    goto LAB_fffffff009c19388;
  }
  auVar20 = FUN_fffffff009c48f14();
  lVar17 = auVar20._0_8_;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x20));
  uVar7 = *(uint *)(lVar17 + 0x28);
  uVar18 = (ulong)uVar7;
  if (0xffff < (int)uVar7) goto LAB_fffffff009c19668;
  uVar12 = *(uint *)(lVar17 + 0x2c);
  uVar8 = (ulong)uVar12;
  if (uVar12 == 4) {
    uVar9 = 0;
    uVar15 = lVar17 + 0x38;
LAB_fffffff009c194cc:
    if (uVar7 == uVar12) {
      uVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bc00,uVar18 << 4);
      if (uVar11 == 0) goto LAB_fffffff009c196c4;
      uVar8 = uVar18 << 1;
      uVar7 = *(uint *)(lVar17 + 0x28);
      uVar6 = (ulong)uVar7;
      if (0 < (int)uVar7) {
        uVar10 = uVar15 + uVar18 * 8;
        if (((uVar15 ^ uVar10) & 0xffc0000000000000) != 0) {
          uVar10 = uVar10 & 0xffffffffffff | 0xc8a2000000000000;
        }
        uVar18 = uVar11 + uVar18 * 0x10;
        if (((uVar11 ^ uVar18) & 0xffc0000000000000) != 0) {
          uVar18 = uVar18 & 0xffffffffffff | 0xc8a2000000000000;
        }
        if ((uVar10 < uVar15) || (uVar10 - uVar15 >> 0x20 != 0)) goto LAB_fffffff009c196c0;
        lVar16 = 0x10000000;
        uVar5 = 0;
        do {
          if (lVar16 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c19698:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if ((long)uVar5 < 0) goto LAB_fffffff009c19698;
          uVar13 = uVar5 >> 0x20;
          uVar12 = (int)(uVar5 >> 0x20) + 8;
          if ((uint)(uVar10 - uVar15) < uVar12) goto LAB_fffffff009c19698;
          uVar4 = -(ulong)CARRY8(uVar15,uVar13);
          if ((uVar4 != CARRY8(uVar15,uVar13)) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if ((uVar18 - uVar11 & 0xffffffff00000000) != 0 || uVar18 < uVar11) {
            FUN_fffffff009c48f64();
LAB_fffffff009c196a4:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if ((uint)(uVar18 - uVar11) < uVar12) goto LAB_fffffff009c196a4;
          uVar4 = -(ulong)CARRY8(uVar11,uVar13);
          if ((uVar4 != CARRY8(uVar11,uVar13)) || ((long)uVar4 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          *(undefined8 *)(uVar11 + uVar13) = *(undefined8 *)(uVar15 + uVar13);
          lVar16 = lVar16 + -1;
          uVar5 = uVar5 + 0x800000000;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      if (uVar9 != 0) {
        lVar16 = (long)(int)*(uint *)(lVar17 + 0x2c) << 3;
        if (0x7fffffff < *(uint *)(lVar17 + 0x2c)) {
          lVar16 = -0x8000000000000000;
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bc50,uVar9,lVar16);
        uVar7 = *(uint *)(lVar17 + 0x28);
      }
      *(ulong *)(lVar17 + 0x30) = uVar11;
      *(int *)(lVar17 + 0x2c) = (int)uVar8;
      uVar15 = uVar11;
    }
    *(uint *)(lVar17 + 0x28) = uVar7 + 1;
    uVar18 = uVar15 + (uVar8 & 0xffffffff) * 8;
    uVar8 = uVar18 - uVar15;
    if ((uVar18 < uVar15) || (uVar8 >> 0x20 != 0)) {
      FUN_fffffff009c48f64();
    }
    else {
      uVar12 = -uVar7;
      if (-1 < (int)uVar7) {
        uVar12 = uVar7;
      }
      uVar18 = (ulong)uVar12 * -8;
      if (-1 < (int)uVar7) {
        uVar18 = (ulong)uVar12 * 8;
      }
      if (uVar18 == (long)(int)uVar18) {
        if ((-1 < (long)uVar18) && ((int)uVar18 + 8U <= (uint)uVar8)) {
          uVar9 = (ulong)CARRY8(uVar15,uVar18 & 0x7ffffff8);
          uVar8 = -uVar9;
          if ((uVar8 != uVar9) || ((long)uVar8 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          *(long *)(uVar15 + (uVar18 & 0x7ffffff8)) = auVar20._8_8_;
LAB_fffffff009c19668:
          plVar3 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x20));
          return plVar3;
        }
        goto LAB_fffffff009c196b4;
      }
    }
    FUN_fffffff009c48f3c();
LAB_fffffff009c196b4:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f28();
  }
  if (-1 < (int)uVar12) {
    uVar9 = *(ulong *)(lVar17 + 0x30);
    uVar15 = uVar9;
    goto LAB_fffffff009c194cc;
  }
  FUN_fffffff009c48f14();
LAB_fffffff009c196c0:
  FUN_fffffff009c48f64();
LAB_fffffff009c196c4:
  auVar20 = FUN_fffffff009c48f78();
  lVar17 = auVar20._0_8_;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x20));
  uVar7 = *(uint *)(lVar17 + 0x2c);
  if (uVar7 == 4) {
    uVar18 = lVar17 + 0x38;
LAB_fffffff009c19708:
    uVar12 = *(uint *)(lVar17 + 0x28);
    if (0 < (int)uVar12) {
      uVar8 = uVar18 + (ulong)uVar7 * 8;
      if (((uVar18 ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar18 <= uVar8) && (uVar8 - uVar18 >> 0x20 == 0)) {
        uVar11 = 0;
        uVar9 = 0xffffffff80000000;
        uVar15 = 0;
        do {
          if (uVar9 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c198d0:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if (((long)uVar11 < 0) || ((uint)(uVar8 - uVar18) < (int)(uVar11 >> 0x20) + 8U))
          goto LAB_fffffff009c198d0;
          plVar3 = (long *)(uVar18 + (uVar11 >> 0x20));
          uVar10 = (ulong)CARRY8(uVar18,uVar11 >> 0x20);
          uVar6 = -uVar10;
          if ((uVar6 != uVar10) || ((long)uVar6 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          if (*plVar3 == auVar20._8_8_) {
            if (uVar9 < 0xffffffff00000000) goto LAB_fffffff009c198e4;
            *plVar3 = 0;
            *(uint *)(lVar17 + 0x28) = uVar12 - 1;
            uVar12 = uVar12 - 1;
            goto LAB_fffffff009c197b8;
          }
          uVar15 = uVar15 + 1;
          uVar9 = uVar9 + 8;
          uVar11 = uVar11 + 0x800000000;
        } while (uVar12 != uVar15);
        goto LAB_fffffff009c19894;
      }
      FUN_fffffff009c48f64();
      goto LAB_fffffff009c198dc;
    }
    uVar15 = 0;
LAB_fffffff009c197b8:
    if ((int)uVar12 <= (int)uVar15) {
LAB_fffffff009c19894:
      plVar3 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x20));
      return plVar3;
    }
    uVar8 = uVar18 + (ulong)uVar7 * 8;
    if (((uVar18 ^ uVar8) & 0xffc0000000000000) != 0) {
      uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
    }
    if ((uVar18 <= uVar8) && (uVar8 - uVar18 >> 0x20 == 0)) {
      uVar11 = uVar15 << 0x23;
      uVar9 = (uVar15 & 0xffffffff) * 8 - 0x80000008;
      lVar16 = (ulong)uVar12 - (uVar15 & 0xffffffff);
      do {
        if (uVar9 + 0x10 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198b8:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar15 = uVar11 + 0x800000000;
        if ((long)uVar15 < 0) goto LAB_fffffff009c198b8;
        uVar7 = (uint)(uVar8 - uVar18);
        if (uVar7 < (int)(uVar15 >> 0x20) + 8U) goto LAB_fffffff009c198b8;
        uVar6 = (ulong)CARRY8(uVar18,uVar15 >> 0x20);
        uVar10 = -uVar6;
        if ((uVar10 != uVar6) || ((long)uVar10 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar9 = uVar9 + 8;
        if (uVar9 < 0xffffffff00000000) {
          FUN_fffffff009c48f3c();
LAB_fffffff009c198c4:
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        if (((long)uVar11 < 0) || (uVar6 = uVar11 >> 0x20, uVar7 < (int)(uVar11 >> 0x20) + 8U))
        goto LAB_fffffff009c198c4;
        uVar5 = (ulong)CARRY8(uVar18,uVar6);
        uVar10 = -uVar5;
        if ((uVar10 != uVar5) || ((long)uVar10 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar11 = uVar11 + 0x800000000;
        *(undefined8 *)(uVar18 + uVar6) = *(undefined8 *)(uVar18 + (uVar15 >> 0x20));
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
      goto LAB_fffffff009c19894;
    }
  }
  else {
    if (-1 < (int)uVar7) {
      uVar18 = *(ulong *)(lVar17 + 0x30);
      goto LAB_fffffff009c19708;
    }
LAB_fffffff009c198dc:
    FUN_fffffff009c48f14();
  }
  FUN_fffffff009c48f64();
LAB_fffffff009c198e4:
  lVar17 = FUN_fffffff009c48f3c();
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x20));
  plVar3 = (long *)thunk_EXT_FUN_80110000038961f4(*(undefined4 *)(lVar17 + 0x28));
  if (plVar3 != (long *)0x0) {
    uVar7 = *(uint *)(lVar17 + 0x2c);
    if (uVar7 == 4) {
      uVar18 = lVar17 + 0x38;
    }
    else {
      if ((int)uVar7 < 0) goto LAB_fffffff009c19a58;
      uVar18 = *(ulong *)(lVar17 + 0x30);
    }
    if (0 < *(int *)(lVar17 + 0x28)) {
      uVar8 = uVar18 + (ulong)uVar7 * 8;
      if (((uVar18 ^ uVar8) & 0xffc0000000000000) != 0) {
        uVar8 = uVar8 & 0xffffffffffff | 0xc8a2000000000000;
      }
      if ((uVar8 < uVar18) || (uVar8 - uVar18 >> 0x20 != 0)) {
        FUN_fffffff009c48f64();
LAB_fffffff009c19a58:
        auVar20 = FUN_fffffff009c48f14();
        lVar17 = auVar20._0_8_;
        plVar3 = (long *)FUN_fffffff009c37a94(DAT_fffffff00af483b0);
        if (((int)plVar3 != 0) &&
           (plVar3 = (long *)FUN_fffffff009c19b40(lVar17,lVar17,auVar20._8_8_,0),
           ((ulong)plVar3 & 1) == 0)) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar17 + 0x20));
          plVar3 = *(long **)(lVar17 + 0x18);
          if (plVar3 == (long *)0x0) {
            plVar3 = (long *)thunk_EXT_FUN_80110000038ccc44(1);
            if (*(long **)(lVar17 + 0x18) != (long *)0x0) {
              (**(code **)(**(long **)(lVar17 + 0x18) + 0x28))();
            }
            *(long **)(lVar17 + 0x18) = plVar3;
          }
          (**(code **)(*plVar3 + 0xf0))(plVar3,auVar20._8_8_);
          plVar3 = (long *)thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x20));
          return plVar3;
        }
        return plVar3;
      }
      uVar15 = 0;
      lVar19 = 0x10000000;
      lVar16 = 1;
      do {
        if (((long)uVar15 < 0) || ((uint)(uVar8 - uVar18) < (int)(uVar15 >> 0x20) + 8U)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f28();
        }
        uVar11 = (ulong)CARRY8(uVar18,uVar15 >> 0x20);
        uVar9 = -uVar11;
        if ((uVar9 != uVar11) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        plVar14 = *(long **)(uVar18 + (uVar15 >> 0x20));
        iVar2 = FUN_fffffff009c410e8(plVar14);
        if (iVar2 != 0) {
          (**(code **)(*plVar3 + 0xe8))(plVar3,plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
        if (*(int *)(lVar17 + 0x28) <= lVar16) goto LAB_fffffff009c19a24;
        lVar16 = lVar16 + 1;
        uVar15 = uVar15 + 0x800000000;
        lVar19 = lVar19 + -1;
      } while (lVar19 != 0);
      FUN_fffffff009c48f3c();
    }
  }
LAB_fffffff009c19a24:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar17 + 0x20));
  return plVar3;
}

