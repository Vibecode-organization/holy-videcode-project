// FUN_fffffff008169968 @ fffffff008169968 size=608

void FUN_fffffff008169968(long *param_1,uint param_2)

{
  uint uVar1;
  float *pfVar2;
  uint uVar3;
  code *pcVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  
  if ((param_1[0x3585] == 0) ||
     (plVar5 = (long *)thunk_EXT_FUN_8011000003976f54(param_1[0x3585],0x1000,1),
     plVar5 == (long *)0x0)) {
    return;
  }
  plVar6 = (long *)thunk_EXT_FUN_801100000396cb64
                             (plVar5,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,0x101,0,0);
  if (plVar6 != (long *)0x0) {
    lVar7 = (**(code **)(*plVar6 + 0x78))();
    fVar10 = (float)(**(code **)(*param_1 + 0x970))(param_1,lVar7);
    if ((*(byte *)((long)param_1 + 0x5ca) >> 1 & 1) == 0) {
      if (param_2 != 0) {
        fVar12 = *(float *)(param_1 + 0x3581);
        uVar9 = 1;
        do {
          fVar11 = (float)NEON_ucvtf((int)param_1[uVar9 * 8 + 0x3291]);
          uVar13 = NEON_ucvtf(*(undefined4 *)((long)param_1 + 0x1ac1c));
          fVar11 = (float)thunk_EXT_FUN_8011000001149590
                                    (fVar11 / *(float *)(param_1 + 0x3581),uVar13);
          *(float *)(param_1[0x2235] + 0xe0 + uVar9 * 4) =
               fVar10 * (fVar12 / 1000.0) * 32.0 * fVar11;
          uVar1 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar1;
        } while (uVar1 <= param_2);
      }
    }
    else {
      uVar8 = *(ulong *)(lVar7 + (ulong)*(uint *)(param_1 + 0x3582));
      lVar7 = param_1[0x96];
      uVar9 = (lVar7 + 0xad0U) - (lVar7 + 0xa90U);
      if ((lVar7 + 0xad0U < lVar7 + 0xa90U) || (uVar9 >> 0x20 != 0)) {
LAB_fffffff008169bb0:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
                  );
      }
      if (uVar9 < 4) {
LAB_fffffff008169bbc:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff008214ca8
                  (
                  "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                  );
      }
      uVar1 = *(uint *)(param_1 + 0x3583);
      uVar3 = *(uint *)((long)param_1 + 0x1ac24);
      fVar12 = *(float *)((long)param_1 + 0x1ac04);
      *(float *)(lVar7 + 0xa90) = fVar10;
      pfVar2 = (float *)(lVar7 + 0xb10);
      uVar9 = (long)(lVar7 + 0xb50U) - (long)pfVar2;
      if (((float *)(lVar7 + 0xb50U) < pfVar2) || (uVar9 >> 0x20 != 0)) goto LAB_fffffff008169bb0;
      if (uVar9 < 4) goto LAB_fffffff008169bbc;
      *pfVar2 = fVar12 * (float)((uVar8 >> ((ulong)uVar1 & 0x3f) & (ulong)uVar3) + 1);
    }
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff008169b90. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar5 + 0x28))(plVar5,(undefined8 *)(*plVar5 + 0x28));
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008169b88);
  (*pcVar4)();
}

