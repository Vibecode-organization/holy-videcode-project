// FUN_fffffff0081dd498 @ fffffff0081dd498 size=4

void FUN_fffffff0081dd498(long *param_1)

{
  float *pfVar1;
  long *plVar2;
  undefined4 *puVar3;
  uint uVar4;
  long lVar5;
  undefined4 uVar6;
  float fVar7;
  double dVar8;
  double dVar9;
  code *pcVar10;
  uint uVar11;
  long *plVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  ulong uVar16;
  ulong unaff_x30;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined4 uStack_e8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_b8;
  
  uVar11 = (**(code **)(*param_1 + 0x768))();
  plVar12 = (long *)param_1[0x96];
  uVar16 = (long)(plVar12 + 0x15a) - (long)(plVar12 + 0x152);
  if ((plVar12 + 0x152 <= plVar12 + 0x15a) && (uVar16 >> 0x20 == 0)) {
    if (3 < uVar16) {
      pfVar1 = (float *)(plVar12 + 0x162);
      uVar16 = (long)(plVar12 + 0x16a) - (long)pfVar1;
      if ((plVar12 + 0x16a < pfVar1) || (uVar16 >> 0x20 != 0)) goto LAB_fffffff0081dd89c;
      if (3 < uVar16) {
        plVar2 = param_1 + 0x34ec;
        fVar26 = *(float *)(plVar12 + 0x152);
        fVar17 = *pfVar1;
        uVar4 = *(uint *)(param_1 + 0x3311);
        *(undefined4 *)plVar2 = 0;
        dVar9 = DAT_fffffff007114000;
        dVar8 = DAT_fffffff007113ff0;
        uVar15 = *(uint *)(param_1 + 0x3288);
        if (1 < uVar15) {
          uVar16 = 1;
          fStack_b8 = 0.02785523;
          fStack_c0 = 0.0013109692;
          fStack_c8 = 3.1907175;
          fStack_cc = 0.026811397;
          fStack_d0 = 0.0012122365;
          fStack_d4 = 3.3114624;
          uStack_e8 = 0x4019999a;
          do {
            fVar18 = (float)NEON_ucvtf((int)param_1[uVar16 * 8 + 0x3291]);
            fVar18 = fVar18 / 1000.0;
            uVar15 = *(uint *)((long)param_1 + uVar16 * 4 + 0x19448);
            fVar23 = fVar18;
            if (fVar18 < (float)uVar4 / 1000.0) {
              fVar23 = (float)uVar4 / 1000.0;
            }
            uVar13 = (uint)(fVar18 * 1000.0);
            fVar19 = (float)NEON_ucvtf((int)(fVar18 * 1000.0));
            fVar20 = fStack_b8;
            if (900 < uVar13) {
              fVar20 = 0.027628511;
            }
            fVar21 = fStack_c8;
            fVar25 = fStack_c0;
            if (900 < uVar13) {
              fVar21 = 3.0134423;
              fVar25 = 0.0015320845;
            }
            fVar24 = fStack_d4;
            fVar22 = fStack_d0;
            fVar7 = fStack_cc;
            if (699 < uVar13) {
              fVar24 = fVar21;
              fVar22 = fVar25;
              fVar7 = fVar20;
            }
            fVar20 = (float)thunk_EXT_FUN_8011000001149590(0x402df854,fVar24 + fVar22 * fVar19);
            fVar19 = (float)NEON_ucvtf((int)(fVar23 * 1000.0));
            fVar19 = (float)thunk_EXT_FUN_8011000001149590
                                      (0x402df854,fVar19 * 0.0027760358 + 2.4288254);
            fVar25 = (float)((ulong)uVar15 / 1000000) / 1293.0;
            uVar6 = 0x3f800000;
            if (0.75 <= fVar18) {
              uVar6 = uStack_e8;
            }
            fVar21 = (float)thunk_EXT_FUN_8011000001149590(fVar18 / 0.75,uVar6);
            fVar22 = (float)thunk_EXT_FUN_8011000001149590(fVar23 / 0.75,0x3f800000);
            fVar23 = fVar18 * (fVar20 * fVar26 * fVar7 +
                              (float)((double)(((float)uVar11 / 5.0) * fVar25 * fVar21 * 6380.0) *
                                     dVar8)) +
                     fVar23 * (fVar17 * 0.017328747 * fVar19 +
                              (float)((double)(((float)uVar11 / 5.0) * fVar25 * fVar22 * 56.0) *
                                     dVar9));
            if (fVar18 * 10000.0 <= fVar23) {
              fVar23 = fVar18 * 10000.0;
            }
            *(int *)(plVar2 + uVar16 * 8) = (int)fVar23;
            uVar16 = uVar16 + 1;
            uVar15 = *(uint *)(param_1 + 0x3288);
          } while (uVar16 < uVar15);
          plVar12 = (long *)param_1[0x96];
        }
        lVar5 = (ulong)(uVar15 - 1) * 0x40;
        iVar14 = (int)lVar5;
        puVar3 = (undefined4 *)((long)plVar2 + (long)iVar14);
        if (lVar5 != iVar14) {
          puVar3 = (undefined4 *)
                   ((ulong)(plVar2 + (ulong)(uVar15 - 1) * 8) & 0xffffffffffff | 0x2bad000000000000)
          ;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081dd890);
          (*pcVar10)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081dd898. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar12 + 0x150))(plVar12,*puVar3,(undefined8 *)(*plVar12 + 0x150));
        return;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
              );
  }
LAB_fffffff0081dd89c:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
            );
}

