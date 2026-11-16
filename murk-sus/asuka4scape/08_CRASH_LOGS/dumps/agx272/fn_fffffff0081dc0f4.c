// FUN_fffffff0081dc0f4 @ fffffff0081dc0f4 size=4

void FUN_fffffff0081dc0f4(long *param_1)

{
  float *pfVar1;
  long *plVar2;
  undefined4 *puVar3;
  uint uVar4;
  long lVar5;
  float fVar6;
  double dVar7;
  code *pcVar8;
  uint uVar9;
  long *plVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  ulong uVar14;
  ulong unaff_x30;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c4;
  float fStack_bc;
  
  uVar9 = (**(code **)(*param_1 + 0x768))();
  plVar10 = (long *)param_1[0x96];
  uVar14 = (long)(plVar10 + 0x15a) - (long)(plVar10 + 0x152);
  if ((plVar10 + 0x152 <= plVar10 + 0x15a) && (uVar14 >> 0x20 == 0)) {
    if (3 < uVar14) {
      pfVar1 = (float *)(plVar10 + 0x162);
      uVar14 = (long)(plVar10 + 0x16a) - (long)pfVar1;
      if ((plVar10 + 0x16a < pfVar1) || (uVar14 >> 0x20 != 0)) goto LAB_fffffff0081dc4e8;
      if (3 < uVar14) {
        plVar2 = param_1 + 0x34ec;
        fVar23 = *(float *)(plVar10 + 0x152);
        fVar15 = *pfVar1;
        uVar4 = *(uint *)(param_1 + 0x3311);
        *(undefined4 *)plVar2 = 0;
        dVar7 = DAT_fffffff007113ff0;
        uVar13 = *(uint *)(param_1 + 0x3288);
        if (1 < uVar13) {
          uVar14 = 1;
          fStack_bc = 0.022503097;
          fStack_c4 = 0.0015366839;
          fStack_cc = 3.2924178;
          fStack_d0 = 0.023329202;
          fStack_d4 = 0.0013205158;
          fStack_d8 = 3.4317977;
          do {
            fVar16 = (float)NEON_ucvtf((int)param_1[uVar14 * 8 + 0x3291]);
            fVar16 = fVar16 / 1000.0;
            uVar13 = *(uint *)((long)param_1 + uVar14 * 4 + 0x19448);
            fVar21 = fVar16;
            if (fVar16 < (float)uVar4 / 1000.0) {
              fVar21 = (float)uVar4 / 1000.0;
            }
            uVar11 = (uint)(fVar16 * 1000.0);
            fVar17 = (float)NEON_ucvtf((int)(fVar16 * 1000.0));
            fVar18 = fStack_bc;
            if (900 < uVar11) {
              fVar18 = 0.023793403;
            }
            fVar20 = fStack_cc;
            fVar19 = fStack_c4;
            if (900 < uVar11) {
              fVar20 = 2.74751;
              fVar19 = 0.0020801106;
            }
            fVar22 = fStack_d8;
            fVar24 = fStack_d4;
            fVar6 = fStack_d0;
            if (699 < uVar11) {
              fVar22 = fVar20;
              fVar24 = fVar19;
              fVar6 = fVar18;
            }
            fVar18 = (float)thunk_EXT_FUN_8011000001149590(0x402df854,fVar22 + fVar24 * fVar17);
            fVar17 = (float)NEON_ucvtf((int)(fVar21 * 1000.0));
            fVar17 = (float)thunk_EXT_FUN_8011000001149590
                                      (0x402df854,fVar17 * 0.0041271453 + 1.7017395);
            fVar24 = (float)((ulong)uVar13 / 1000000) / 1293.0;
            fVar19 = (float)thunk_EXT_FUN_8011000001149590(fVar16 / 0.75,0x400ccccd);
            fVar20 = (float)thunk_EXT_FUN_8011000001149590(fVar21 / 0.75,0x400ccccd);
            fVar21 = fVar16 * (fVar18 * fVar23 * fVar6 +
                              (float)((double)(((float)uVar9 / 5.0) * fVar24 * fVar19 * 5229.0) *
                                     dVar7)) +
                     fVar21 * (fVar15 * 0.009326443 * fVar17 +
                              (float)((double)(((float)uVar9 / 5.0) * fVar24 * fVar20 * 56.0) *
                                     dVar7));
            if (fVar16 * 10000.0 <= fVar21) {
              fVar21 = fVar16 * 10000.0;
            }
            *(int *)(plVar2 + uVar14 * 8) = (int)fVar21;
            uVar14 = uVar14 + 1;
            uVar13 = *(uint *)(param_1 + 0x3288);
          } while (uVar14 < uVar13);
          plVar10 = (long *)param_1[0x96];
        }
        lVar5 = (ulong)(uVar13 - 1) * 0x40;
        iVar12 = (int)lVar5;
        puVar3 = (undefined4 *)((long)plVar2 + (long)iVar12);
        if (lVar5 != iVar12) {
          puVar3 = (undefined4 *)
                   ((ulong)(plVar2 + (ulong)(uVar13 - 1) * 8) & 0xffffffffffff | 0x2bad000000000000)
          ;
        }
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081dc4dc);
          (*pcVar8)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081dc4e4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*plVar10 + 0x150))(plVar10,*puVar3,(undefined8 *)(*plVar10 + 0x150));
        return;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              (
              "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
              );
  }
LAB_fffffff0081dc4e8:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
            );
}

