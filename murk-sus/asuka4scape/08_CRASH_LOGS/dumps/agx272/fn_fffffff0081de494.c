// FUN_fffffff0081de494 @ fffffff0081de494 size=756

void FUN_fffffff0081de494(long param_1)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  code *UNRECOVERED_JUMPTABLE;
  float *pfVar13;
  ulong uVar14;
  undefined8 *puVar15;
  ulong unaff_x30;
  float fVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  iVar8 = FUN_fffffff0081d6c4c();
  if ((((iVar8 == 0x8015) || (iVar8 = FUN_fffffff0081d6c4c(), iVar8 == 0x8027)) ||
      (iVar8 = FUN_fffffff0081d6c4c(), iVar8 == 0x8020)) ||
     (iVar8 = FUN_fffffff0081d6c4c(), iVar8 == 0x8103)) {
    lVar12 = *(long *)(param_1 + 0x4b0);
    uVar14 = (lVar12 + 0xad0U) - (lVar12 + 0xa90U);
    if ((lVar12 + 0xa90U <= lVar12 + 0xad0U) && (uVar14 >> 0x20 == 0)) {
      if (3 < uVar14) {
        *(undefined4 *)(lVar12 + 0xa90) = 0x43dc8000;
        puVar1 = (undefined4 *)(lVar12 + 0xb10);
        uVar14 = (lVar12 + 0xb50) - (long)puVar1;
        if (((undefined4 *)(lVar12 + 0xb50) < puVar1) || (uVar14 >> 0x20 != 0))
        goto LAB_fffffff0081de74c;
        if (3 < uVar14) {
          *puVar1 = 0x4149999a;
          return;
        }
      }
LAB_fffffff0081de77c:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff008214ca8
                (
                "bounded_ptr<T>::operator*: Dereferencing this pointer would access memory outside of the bounds set originally"
                );
    }
  }
  else {
    plVar9 = (long *)thunk_EXT_FUN_8011000003976f54(0x23d2c8000,0x1000,1);
    if (plVar9 == (long *)0x0) {
      return;
    }
    plVar10 = (long *)thunk_EXT_FUN_801100000396cb64
                                (plVar9,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,0x101,0,0);
    if (plVar10 == (long *)0x0) {
      puVar15 = (undefined8 *)(*plVar9 + 0x28);
      UNRECOVERED_JUMPTABLE = (code *)*puVar15;
LAB_fffffff0081de724:
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff0081de748. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(plVar9,puVar15);
        return;
      }
                    /* WARNING: Does not return */
      UNRECOVERED_JUMPTABLE = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081de740);
      (*UNRECOVERED_JUMPTABLE)();
    }
    lVar11 = (**(code **)(*plVar10 + 0x78))();
    lVar12 = 0;
    if (*(long *)(param_1 + 0x3b8) == 0 && *(long *)(param_1 + 0x3b0) == 0) {
      lVar12 = 0x10;
    }
    puVar15 = (undefined8 *)(param_1 + 0x3b0 + lVar12);
    uVar18 = *puVar15;
    uVar17 = puVar15[1];
    if ((uint)(byte)(POPCOUNT((char)uVar17) + POPCOUNT((char)((ulong)uVar17 >> 8)) +
                     POPCOUNT((char)((ulong)uVar17 >> 0x10)) +
                     POPCOUNT((char)((ulong)uVar17 >> 0x18)) +
                     POPCOUNT((char)((ulong)uVar17 >> 0x20)) +
                     POPCOUNT((char)((ulong)uVar17 >> 0x28)) +
                     POPCOUNT((char)((ulong)uVar17 >> 0x30)) +
                    POPCOUNT((char)((ulong)uVar17 >> 0x38))) +
        (uint)(byte)(POPCOUNT((char)uVar18) + POPCOUNT((char)((ulong)uVar18 >> 8)) +
                     POPCOUNT((char)((ulong)uVar18 >> 0x10)) +
                     POPCOUNT((char)((ulong)uVar18 >> 0x18)) +
                     POPCOUNT((char)((ulong)uVar18 >> 0x20)) +
                     POPCOUNT((char)((ulong)uVar18 >> 0x28)) +
                     POPCOUNT((char)((ulong)uVar18 >> 0x30)) +
                    POPCOUNT((char)((ulong)uVar18 >> 0x38))) == 5) {
      uVar7 = (uint)(CONCAT44(*(undefined4 *)(lVar11 + 0x450),*(uint *)(lVar11 + 0x44c)) >> 0x19);
      pfVar13 = (float *)&DAT_fffffff007115068;
    }
    else {
      uVar7 = *(uint *)(lVar11 + 0x44c) >> 0xd;
      pfVar13 = (float *)&UNK_fffffff007115090;
    }
    fVar3 = pfVar13[3];
    uVar5 = *(uint *)(lVar11 + (ulong)(uint)pfVar13[2]);
    fVar2 = pfVar13[4];
    fVar4 = pfVar13[5];
    if (((uint)pfVar13[1] & 1) == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = (ulong)(*(uint *)(lVar11 + (ulong)(uint)pfVar13[6]) >>
                       ((ulong)(uint)pfVar13[7] & 0x3f) & (uint)pfVar13[8]) <<
               ((ulong)(uint)pfVar13[9] & 0x3f);
    }
    lVar12 = *(long *)(param_1 + 0x4b0);
    uVar6 = (lVar12 + 0xad0U) - (lVar12 + 0xa90U);
    if ((lVar12 + 0xa90U <= lVar12 + 0xad0U) && (uVar6 >> 0x20 == 0)) {
      if (3 < uVar6) {
        fVar16 = *pfVar13;
        *(float *)(lVar12 + 0xa90) = (float)((uVar7 & 0xfff) + 1);
        pfVar13 = (float *)(lVar12 + 0xb10);
        uVar6 = (long)(lVar12 + 0xb50U) - (long)pfVar13;
        if (((float *)(lVar12 + 0xb50U) < pfVar13) || (uVar6 >> 0x20 != 0))
        goto LAB_fffffff0081de74c;
        if (3 < uVar6) {
          *pfVar13 = fVar16 * (float)((uVar14 | (ulong)(uVar5 >> ((ulong)(uint)fVar3 & 0x3f) &
                                                       (uint)fVar2) << ((ulong)(uint)fVar4 & 0x3f))
                                     + 1);
          (**(code **)(*plVar9 + 0x28))(plVar9);
          puVar15 = (undefined8 *)(*plVar10 + 0x28);
          UNRECOVERED_JUMPTABLE = (code *)*puVar15;
          plVar9 = plVar10;
          goto LAB_fffffff0081de724;
        }
      }
      goto LAB_fffffff0081de77c;
    }
  }
LAB_fffffff0081de74c:
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "The range of valid memory is too large to be represented by this type, or [begin, end) is not a well-formed range"
            );
}

