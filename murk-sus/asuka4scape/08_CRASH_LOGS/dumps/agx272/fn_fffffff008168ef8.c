// FUN_fffffff008168ef8 @ fffffff008168ef8 size=672

/* WARNING: Removing unreachable block (ram,0xfffffff008168f7c) */

void FUN_fffffff008168ef8(float param_1,float param_2,long *param_3,uint param_4)

{
  long lVar1;
  long *plVar2;
  undefined8 *puVar3;
  float *pfVar4;
  float *pfVar5;
  code *pcVar6;
  ulong uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  long *plVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  int iVar16;
  long lVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong unaff_x30;
  float fVar21;
  undefined1 auVar22 [16];
  float fVar24;
  float fVar25;
  undefined1 auVar23 [16];
  float fVar26;
  
  param_3[0x2235] = param_3[0x96] + 0x930;
  (**(code **)(*param_3 + 0x9a8))();
  (**(code **)(*param_3 + 0x9a0))(*param_3 + 0x9a0,param_3);
  lVar11 = param_3[0x2235];
  lVar1 = lVar11 + 0x120;
  *(undefined4 *)(lVar11 + 0x120) = 0;
  if (param_4 != 0) {
    lVar11 = lVar11 + 0x20;
    plVar2 = param_3 + 0x3291;
    param_1 = param_1 * param_1;
    uVar12 = 2;
    if (2 < param_4 + 1) {
      uVar12 = param_4 + 1;
    }
    if (param_4 + 1 < 5) {
      uVar14 = 1;
    }
    else {
      uVar15 = 0;
      uVar18 = (ulong)uVar12 - 1;
      uVar14 = uVar18 & 0xfffffffffffffffc;
      auVar22 = NEON_fmov(0x3f800000,4);
      uVar19 = uVar14;
      do {
        uVar20 = uVar15 | 1;
        uVar7 = uVar15 << 6;
        uVar15 = uVar15 + 4;
        puVar9 = (undefined4 *)((long)plVar2 + (uVar7 | 0x80));
        if ((((ulong)plVar2 ^ (ulong)puVar9) & 0xffc0000000000000) != 0) {
          puVar9 = (undefined4 *)((ulong)puVar9 & 0xffffffffffff | 0xc8a2000000000000);
        }
        puVar8 = (undefined4 *)((long)plVar2 + (uVar7 | 0xc0));
        if ((((ulong)plVar2 ^ (ulong)puVar8) & 0xffc0000000000000) != 0) {
          puVar8 = (undefined4 *)((ulong)puVar8 & 0xffffffffffff | 0xc8a2000000000000);
        }
        plVar10 = plVar2 + uVar15 * 8;
        if ((((ulong)plVar2 ^ (ulong)plVar10) & 0xffc0000000000000) != 0) {
          plVar10 = (long *)((ulong)plVar10 & 0xffffffffffff | 0xc8a2000000000000);
        }
        auVar23._0_4_ = (undefined4)plVar2[uVar20 * 8];
        auVar23._4_4_ = *puVar9;
        auVar23._8_4_ = *puVar8;
        auVar23._12_4_ = (undefined4)*plVar10;
        lVar13 = uVar20 * 4;
        auVar23 = NEON_ucvtf(auVar23,4);
        fVar21 = (auVar23._0_4_ * auVar23._0_4_) / param_1;
        fVar24 = (auVar23._4_4_ * auVar23._4_4_) / param_1;
        fVar25 = (auVar23._8_4_ * auVar23._8_4_) / param_1;
        fVar26 = (auVar23._12_4_ * auVar23._12_4_) / param_1;
        pfVar5 = (float *)(lVar1 + lVar13);
        pfVar5[2] = fVar25;
        pfVar5[3] = fVar26;
        *pfVar5 = fVar21;
        pfVar5[1] = fVar24;
        pfVar5 = (float *)(lVar11 + lVar13);
        pfVar5[2] = (0.0 / fVar25) / 100.0 + auVar22._8_4_;
        pfVar5[3] = (0.0 / fVar26) / 100.0 + auVar22._12_4_;
        *pfVar5 = (0.0 / fVar21) / 100.0 + auVar22._0_4_;
        pfVar5[1] = (0.0 / fVar24) / 100.0 + auVar22._4_4_;
        uVar19 = uVar19 - 4;
      } while (uVar19 != 0);
      if (uVar18 == uVar14) goto LAB_fffffff008169120;
      uVar14 = uVar14 | 1;
    }
    lVar13 = uVar12 - uVar14;
    do {
      iVar16 = (int)(uVar14 * 0x40);
      puVar9 = (undefined4 *)((long)plVar2 + (long)iVar16);
      if (uVar14 * 0x40 - (long)iVar16 != 0) {
        puVar9 = (undefined4 *)((ulong)(plVar2 + uVar14 * 8) & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar17 = uVar14 * 4;
      iVar16 = (int)lVar17;
      pfVar5 = (float *)(lVar1 + iVar16);
      if (lVar17 - iVar16 != 0) {
        pfVar5 = (float *)(lVar1 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
      pfVar4 = (float *)(lVar11 + iVar16);
      if (lVar17 - iVar16 != 0) {
        pfVar4 = (float *)(lVar11 + lVar17 & 0xffffffffffffU | 0x2bad000000000000);
      }
      fVar21 = (float)NEON_ucvtf(*puVar9);
      fVar21 = (fVar21 * fVar21) / param_1;
      *pfVar5 = fVar21;
      *pfVar4 = (0.0 / fVar21) / 100.0 + 1.0;
      uVar14 = uVar14 + 1;
      lVar13 = lVar13 + -1;
    } while (lVar13 != 0);
  }
LAB_fffffff008169120:
  lVar11 = (ulong)param_4 * 4;
  pfVar5 = (float *)(lVar1 + (int)lVar11);
  if (lVar11 != (int)lVar11) {
    pfVar5 = (float *)(lVar1 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
  }
  puVar3 = (undefined8 *)(*(long *)param_3[0x96] + 0x150);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008169194. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)*puVar3)((long *)param_3[0x96],(int)(param_2 * *pfVar5),puVar3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00816918c);
  (*pcVar6)();
}

