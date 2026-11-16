// FUN_fffffff009c37780 @ fffffff009c37780 size=560

void FUN_fffffff009c37780(long param_1,long param_2,uint param_3,long param_4)

{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  code *pcVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x230));
  puVar2 = (undefined8 *)(param_1 + 0x240);
  puVar3 = (undefined8 *)(param_1 + 0x380);
  if ((puVar3 < puVar2) || ((ulong)((long)puVar3 - (long)puVar2) >> 0x20 != 0)) {
    FUN_fffffff009c48f64();
  }
  else {
    uVar10 = 0;
    uVar9 = 0;
    lVar13 = *(long *)(param_1 + 0x238);
    uVar8 = 0xffffffff;
    do {
      uVar12 = -(ulong)CARRY8((ulong)puVar2,uVar10);
      if ((uVar12 != CARRY8((ulong)puVar2,uVar10)) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      uVar7 = (uint)((long)puVar3 - (long)puVar2);
      if (*(long *)((long)puVar2 + uVar10) == param_2) goto LAB_fffffff009c37878;
      uVar4 = uVar9;
      if (uVar8 != 0xffffffff || *(long *)((long)puVar2 + uVar10) != 0) {
        uVar4 = uVar8;
      }
      uVar9 = uVar9 + 1;
      uVar10 = (ulong)((int)uVar10 + 0x28);
      uVar8 = uVar4;
    } while (uVar9 != 8);
    if (uVar4 == 0xffffffff) {
LAB_fffffff009c3795c:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37980);
        (*pcVar5)();
      }
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x230));
      return;
    }
    uVar9 = -uVar4;
    if (-1 < (int)uVar4) {
      uVar9 = uVar4;
    }
    uVar10 = (ulong)uVar9 * -0x28;
    if (-1 < (int)uVar4) {
      uVar10 = (ulong)uVar9 * 0x28;
    }
    if (uVar10 != (long)(int)uVar10) {
      FUN_fffffff009c48f3c();
LAB_fffffff009c379a4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28();
    }
    if (((long)uVar10 < 0) || (uVar7 < (int)uVar10 + 0x28U)) goto LAB_fffffff009c379a4;
    uVar11 = (ulong)CARRY8((ulong)puVar2,uVar10 & 0x7ffffff8);
    uVar12 = -uVar11;
    if ((uVar12 != uVar11) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50();
    }
    *(long *)((long)puVar2 + (uVar10 & 0x7ffffff8)) = param_2;
    uVar9 = uVar4;
LAB_fffffff009c37878:
    if ((3 < param_3) || (7 < (int)uVar9)) goto LAB_fffffff009c3795c;
    uVar8 = -uVar9;
    if (-1 < (int)uVar9) {
      uVar8 = uVar9;
    }
    uVar10 = (ulong)uVar8 * -0x28;
    if (-1 < (int)uVar9) {
      uVar10 = (ulong)uVar8 * 0x28;
    }
    if (uVar10 == (long)(int)uVar10) {
      if ((-1 < (long)uVar10) && ((int)uVar10 + 0x28U <= uVar7)) {
        uVar10 = uVar10 & 0x7ffffff8;
        uVar12 = -(ulong)CARRY8((ulong)puVar2,uVar10);
        if ((uVar12 != CARRY8((ulong)puVar2,uVar10)) || ((long)uVar12 < 0)) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff009c48f50();
        }
        uVar12 = (long)puVar2 + uVar10 + 8;
        uVar10 = (long)puVar2 + uVar10 + 0x28;
        uVar11 = uVar10 - uVar12;
        if ((uVar10 < uVar12) || (uVar11 >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
        }
        else {
          param_3 = param_3 * 8;
          if ((uint)uVar11 < param_3 + 8) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          plVar1 = (long *)(uVar12 + param_3);
          uVar12 = (ulong)CARRY8(uVar12,(ulong)param_3);
          uVar10 = -uVar12;
          if ((uVar10 == uVar12) && (-1 < (long)uVar10)) {
            *(long *)(param_1 + 0x238) = lVar13 - *plVar1;
            if (param_4 == 0) {
              lVar6 = 0;
            }
            else {
              lVar6 = FUN_fffffff009c1f1a8(param_4);
            }
            *plVar1 = lVar6;
            lVar6 = *(long *)(param_1 + 0x238) + lVar6;
            *(long *)(param_1 + 0x238) = lVar6;
            if ((lVar13 != lVar6) && ((code *)*puVar3 != (code *)0x0)) {
              (*(code *)*puVar3)(*(undefined8 *)(param_1 + 0x388));
            }
            goto LAB_fffffff009c3795c;
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_fffffff009c48f50();
      }
      goto LAB_fffffff009c37990;
    }
  }
  FUN_fffffff009c48f3c();
LAB_fffffff009c37990:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff009c48f28();
}

