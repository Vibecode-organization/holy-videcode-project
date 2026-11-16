// FUN_fffffff008169198 @ fffffff008169198 size=576

void FUN_fffffff008169198(float param_1,float param_2,long *param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  undefined8 *puVar4;
  float *pfVar5;
  float *pfVar6;
  code *pcVar7;
  ulong uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  long *plVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  int iVar18;
  long lVar19;
  ulong uVar20;
  ulong uVar21;
  ulong unaff_x30;
  float fVar22;
  float fVar24;
  float fVar25;
  undefined1 auVar23 [16];
  float fVar26;
  
  param_3[0x2235] = param_3[0x96] + 0x930;
  *(undefined4 *)(param_3[0x96] + 0xa50) = 0;
  (**(code **)(*param_3 + 0x998))();
  lVar13 = param_3[0x2235];
  if (param_4 != 0) {
    lVar1 = lVar13 + 0x120;
    lVar2 = lVar13 + 0xa0;
    plVar3 = param_3 + 0x3291;
    param_1 = param_1 * param_1;
    uVar14 = 2;
    if (2 < param_4 + 1) {
      uVar14 = param_4 + 1;
    }
    if (param_4 + 1 < 5) {
      uVar16 = 1;
    }
    else {
      uVar17 = 0;
      uVar20 = (ulong)uVar14 - 1;
      uVar16 = uVar20 & 0xfffffffffffffffc;
      uVar21 = uVar16;
      do {
        uVar8 = uVar17 | 1;
        uVar9 = uVar17 << 6;
        uVar17 = uVar17 + 4;
        puVar11 = (undefined4 *)((long)plVar3 + (uVar9 | 0x80));
        if ((((ulong)plVar3 ^ (ulong)puVar11) & 0xffc0000000000000) != 0) {
          puVar11 = (undefined4 *)((ulong)puVar11 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar10 = (undefined4 *)((long)plVar3 + (uVar9 | 0xc0));
        if ((((ulong)plVar3 ^ (ulong)puVar10) & 0xffc0000000000000) != 0) {
          puVar10 = (undefined4 *)((ulong)puVar10 & 0xffffffffffff | 0xc8a2000000000000);
        }
        plVar12 = plVar3 + uVar17 * 8;
        if ((((ulong)plVar3 ^ (ulong)plVar12) & 0xffc0000000000000) != 0) {
          plVar12 = (long *)((ulong)plVar12 & 0xffffffffffff | 0xc8a2000000000000);
        }
        auVar23._0_4_ = (undefined4)plVar3[uVar8 * 8];
        auVar23._4_4_ = *puVar11;
        auVar23._8_4_ = *puVar10;
        lVar15 = uVar8 * 4;
        auVar23._12_4_ = (undefined4)*plVar12;
        auVar23 = NEON_ucvtf(auVar23,4);
        fVar22 = (auVar23._0_4_ * auVar23._0_4_) / param_1;
        fVar24 = (auVar23._4_4_ * auVar23._4_4_) / param_1;
        fVar25 = (auVar23._8_4_ * auVar23._8_4_) / param_1;
        fVar26 = (auVar23._12_4_ * auVar23._12_4_) / param_1;
        pfVar6 = (float *)(lVar1 + lVar15);
        pfVar6[2] = fVar25;
        pfVar6[3] = fVar26;
        *pfVar6 = fVar22;
        pfVar6[1] = fVar24;
        pfVar6 = (float *)(lVar2 + lVar15);
        pfVar6[2] = fVar25 * 0.0;
        pfVar6[3] = fVar26 * 0.0;
        *pfVar6 = fVar22 * 0.0;
        pfVar6[1] = fVar24 * 0.0;
        uVar21 = uVar21 - 4;
      } while (uVar21 != 0);
      if (uVar20 == uVar16) goto LAB_fffffff00816935c;
      uVar16 = uVar16 | 1;
    }
    lVar15 = uVar14 - uVar16;
    do {
      lVar19 = uVar16 * 4;
      iVar18 = (int)lVar19;
      pfVar6 = (float *)(lVar1 + iVar18);
      if (lVar19 - iVar18 != 0) {
        pfVar6 = (float *)(lVar1 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
      pfVar5 = (float *)(lVar2 + iVar18);
      if (lVar19 - iVar18 != 0) {
        pfVar5 = (float *)(lVar2 + lVar19 & 0xffffffffffffU | 0x2bad000000000000);
      }
      iVar18 = (int)(uVar16 * 0x40);
      puVar11 = (undefined4 *)((long)plVar3 + (long)iVar18);
      if (uVar16 * 0x40 - (long)iVar18 != 0) {
        puVar11 = (undefined4 *)((ulong)(plVar3 + uVar16 * 8) & 0xffffffffffff | 0x2bad000000000000)
        ;
      }
      fVar22 = (float)NEON_ucvtf(*puVar11);
      fVar22 = (fVar22 * fVar22) / param_1;
      *pfVar6 = fVar22;
      *pfVar5 = fVar22 * 0.0;
      uVar16 = uVar16 + 1;
      lVar15 = lVar15 + -1;
    } while (lVar15 != 0);
  }
LAB_fffffff00816935c:
  lVar1 = (ulong)param_4 * 4;
  pfVar6 = (float *)(lVar13 + 0x120 + (long)(int)lVar1);
  if (lVar1 != (int)lVar1) {
    pfVar6 = (float *)(lVar13 + 0x120 + lVar1 & 0xffffffffffffU | 0x2bad000000000000);
  }
  puVar4 = (undefined8 *)(*(long *)param_3[0x96] + 0x150);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081693cc);
    (*pcVar7)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081693d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*puVar4)((long *)param_3[0x96],(int)(param_2 * *pfVar6),puVar4);
  return;
}

