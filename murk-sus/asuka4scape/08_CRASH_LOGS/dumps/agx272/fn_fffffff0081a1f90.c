// FUN_fffffff0081a1f90 @ fffffff0081a1f90 size=2704

/* WARNING: Removing unreachable block (ram,0xfffffff0081a2688) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a258c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a27f8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a29d8) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a2898) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a2938) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a2648) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a275c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081a2068) */

long FUN_fffffff0081a1f90(long *param_1,undefined8 param_2,int *param_3)

{
  undefined *puVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  int *piVar9;
  ulong uVar10;
  undefined8 uVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  
  lVar6 = thunk_EXT_FUN_801100000391a8dc();
  if (lVar6 == 0) {
    return 0;
  }
  plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(param_2,*(undefined8 *)PTR_DAT_fffffff007ca6018);
  if (plVar7 == (long *)0x0) {
    return 0;
  }
  if (DAT_fffffff00ae22ce0 == plVar7) goto LAB_fffffff0081a25bc;
  if (DAT_fffffff00ae22ce0 != (long *)0x0) {
    if ((DAT_fffffff00ae22ce8._7_1_ & 1) != 0) {
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x570))(DAT_fffffff00ae22ce0,0,0,0);
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x568))
                (*DAT_fffffff00ae22ce0 + 0x568,DAT_fffffff00ae22ce0,0,0);
      DAT_fffffff00ae22ce8._7_1_ = 0;
    }
    if (DAT_fffffff00ae22d18 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00ae22d18 + 0x28))();
      DAT_fffffff00ae22d18 = (long *)0x0;
    }
    if (DAT_fffffff00ae22d10 != (long *)0x0) {
      (**(code **)(*DAT_fffffff00ae22d10 + 0x28))();
      DAT_fffffff00ae22d10 = (long *)0x0;
    }
  }
  if ((DAT_fffffff00ae22cf0 & 1) == 0) {
    DAT_fffffff00ae22cf0 = 1;
  }
  DAT_fffffff00ae22ce8._0_2_ = 0x202;
  DAT_fffffff00ae22ce0 = plVar7;
  lVar8 = (**(code **)(*plVar7 + 0x118))(plVar7,"model-slow");
  puVar1 = PTR_DAT_fffffff007ca6090;
  if ((lVar8 == 0) ||
     (plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)PTR_DAT_fffffff007ca6090)
     , plVar7 == (long *)0x0)) {
    DAT_fffffff00ae22ce8._2_1_ = '\x02';
  }
  else {
    piVar9 = (int *)(**(code **)(*plVar7 + 0xd8))();
    DAT_fffffff00ae22ce8._2_1_ = *piVar9 != 0;
  }
  lVar8 = (**(code **)(*DAT_fffffff00ae22ce0 + 0x118))(DAT_fffffff00ae22ce0,"no-gpc");
  if ((lVar8 == 0) ||
     (plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)puVar1),
     plVar7 == (long *)0x0)) {
    DAT_fffffff00ae22ce8._3_1_ = '\x02';
  }
  else {
    piVar9 = (int *)(**(code **)(*plVar7 + 0xd8))();
    DAT_fffffff00ae22ce8._3_1_ = *piVar9 != 0;
  }
  lVar8 = (**(code **)(*DAT_fffffff00ae22ce0 + 0x118))(DAT_fffffff00ae22ce0,"has-kf");
  if ((lVar8 == 0) ||
     (plVar7 = (long *)thunk_EXT_FUN_8011000003890f30(lVar8,*(undefined8 *)puVar1),
     plVar7 == (long *)0x0)) {
    bVar12 = 0;
  }
  else {
    piVar9 = (int *)(**(code **)(*plVar7 + 0xd8))();
    bVar12 = 0;
    if (*piVar9 != 0) {
      bVar12 = 8;
    }
  }
  DAT_fffffff00ae22cf1 = DAT_fffffff00ae22cf1 & 0xf7 | bVar12;
  iVar4 = (**(code **)(*DAT_fffffff00ae22ce0 + 0x3c0))();
  if (iVar4 < 3) {
    if (iVar4 == 1) {
      uVar11 = 0;
      DAT_fffffff00ae22ce8._4_2_ = DAT_fffffff00ae22ce8._4_2_ & 0xff00;
    }
    else {
      if (iVar4 != 2) {
LAB_fffffff0081a2988:
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))(DAT_fffffff00ae22ce0,0);
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))
                  (*DAT_fffffff00ae22ce0 + 0x1e8,DAT_fffffff00ae22ce0,0);
        lVar6 = thunk_EXT_FUN_8011000003a49114
                          ("AGXk: %s:%d:%s: !!! [%s] Unsupported number of reg ranges in EDT (%u)\n"
                          );
        return lVar6;
      }
      uVar11 = 0;
      DAT_fffffff00ae22ce8._4_2_ = 0x100;
    }
  }
  else {
    if (iVar4 == 3) {
      if ((DAT_fffffff00ae22cf1 >> 3 & 1) == 0) {
        uVar11 = 0;
        DAT_fffffff00ae22ce8._4_2_ = 0x100;
        DAT_fffffff00ae22ce8._6_1_ = 2;
        goto LAB_fffffff0081a2348;
      }
    }
    else {
      if (iVar4 != 4) goto LAB_fffffff0081a2988;
      DAT_fffffff00ae22ce8._6_1_ = 3;
    }
    DAT_fffffff00ae22ce8._4_2_ = 0x201;
    uVar11 = 1;
  }
LAB_fffffff0081a2348:
  bVar2 = (byte)DAT_fffffff00ae22ce8 - 1 < 2;
  bVar12 = DAT_fffffff00ae22cf1 & 0xfc;
  if (bVar2) {
    bVar12 = bVar12 + 1;
  }
  bVar3 = DAT_fffffff00ae22ce8._3_1_ != '\x01';
  if (DAT_fffffff00ae22ce8._1_1_ != '\x02') {
    bVar3 = DAT_fffffff00ae22ce8._1_1_ == '\x01';
  }
  bVar13 = 2;
  if (!bVar3) {
    bVar13 = 0;
  }
  bVar15 = 0;
  if (DAT_fffffff00ae22ce8._5_1_ != -1) {
    bVar15 = 4;
  }
  if (!bVar2 || bVar13 == 0 && (bVar12 & 10) == 0) {
    bVar15 = 0;
  }
  bVar14 = 0x10;
  if (DAT_fffffff00ae22ce8._2_1_ != '\x01') {
    bVar14 = 0;
  }
  DAT_fffffff00ae22cf1 = bVar14 | bVar13 | bVar12 & 0xeb | bVar15;
  if ((DAT_fffffff00ae22cf8 == 0) &&
     (lVar8 = (**(code **)(*DAT_fffffff00ae22ce0 + 0x3c8))(DAT_fffffff00ae22ce0,uVar11), lVar8 != 0)
     ) {
    DAT_fffffff00ae22cf8 = thunk_EXT_FUN_80110000039788dc();
  }
  if (DAT_fffffff00ae22ce8._5_1_ == -1) {
joined_r0xfffffff0081a2498:
    if ((DAT_fffffff00ae22d00 == 0) && ((DAT_fffffff00ae22cf1 >> 2 & 1) != 0)) {
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))(DAT_fffffff00ae22ce0,0);
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))
                (*DAT_fffffff00ae22ce0 + 0x1e8,DAT_fffffff00ae22ce0,0);
      lVar6 = thunk_EXT_FUN_8011000003a49114
                        (
                        "AGXk: %s:%d:%s: !!! Verification failed: %s: [%s] Fender address unknown\n"
                        );
      return lVar6;
    }
  }
  else if (DAT_fffffff00ae22d00 == 0) {
    lVar8 = (**(code **)(*DAT_fffffff00ae22ce0 + 0x3c8))();
    if (lVar8 != 0) {
      DAT_fffffff00ae22d00 = thunk_EXT_FUN_80110000039788dc();
    }
    goto joined_r0xfffffff0081a2498;
  }
  if ((DAT_fffffff00ae22cf1 & 1) != 0) {
    DAT_fffffff00ae22d10 =
         (long *)(**(code **)(*DAT_fffffff00ae22ce0 + 0x3d0))
                           (DAT_fffffff00ae22ce0,DAT_fffffff00ae22ce8._4_1_,0);
    if (DAT_fffffff00ae22d10 == (long *)0x0) {
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))(DAT_fffffff00ae22ce0,0);
      (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))
                (*DAT_fffffff00ae22ce0 + 0x1e8,DAT_fffffff00ae22ce0,0);
      lVar6 = thunk_EXT_FUN_8011000003a49114
                        (
                        "AGXk: %s:%d:%s: !!! Verification failed: %s: [%s] Could not map GPU reg range\n"
                        );
      return lVar6;
    }
    if ((DAT_fffffff00ae22cf1 >> 2 & 1) != 0) {
      DAT_fffffff00ae22d18 =
           (long *)(**(code **)(*DAT_fffffff00ae22ce0 + 0x3d0))
                             (DAT_fffffff00ae22ce0,DAT_fffffff00ae22ce8._5_1_,0);
      if (DAT_fffffff00ae22d18 == (long *)0x0) {
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))(DAT_fffffff00ae22ce0,0);
        (**(code **)(*DAT_fffffff00ae22ce0 + 0x1e8))
                  (*DAT_fffffff00ae22ce0 + 0x1e8,DAT_fffffff00ae22ce0,0);
        lVar6 = thunk_EXT_FUN_8011000003a49114
                          (
                          "AGXk: %s:%d:%s: !!! Verification failed: %s: [%s] Could not map Fender reg range\n"
                          );
        return lVar6;
      }
    }
  }
  if (((DAT_fffffff00ae22ce8._7_1_ & 1) == 0) && ((DAT_fffffff00ae22cf1 & 1) != 0)) {
    (**(code **)(*DAT_fffffff00ae22ce0 + 0x568))(DAT_fffffff00ae22ce0,1,0);
    (**(code **)(*DAT_fffffff00ae22ce0 + 0x570))
              (*DAT_fffffff00ae22ce0 + 0x570,DAT_fffffff00ae22ce0,1,0,0);
    thunk_EXT_FUN_80110000038fe988(10);
    DAT_fffffff00ae22ce8._7_1_ = 1;
  }
LAB_fffffff0081a25bc:
  if ((DAT_fffffff00ae22cf1 & 1) == 0) {
    lVar6 = 0;
  }
  else {
    lVar8 = (**(code **)(*DAT_fffffff00ae22d10 + 0x78))();
    param_1[0x61] = lVar8;
    param_1[0x228b] = lVar8;
    lVar8 = (**(code **)(*DAT_fffffff00ae22d18 + 0x78))();
    param_1[0x22ad] = lVar8;
    uVar10 = (**(code **)(*param_1 + 0x858))(*param_1 + 0x858,param_1);
    lVar8 = (**(code **)(*param_1 + 0x800))(*param_1 + 0x800,param_1,1);
    uVar5 = (**(code **)(*DAT_fffffff00ae22d18 + 0x88))();
    param_1[0x1bf7] = DAT_fffffff007113e88;
    param_1[0x1bf8] = lVar8 + (uVar10 & 0xffffffff);
    param_1[0x1bfa] = 0;
    param_1[0x1bf9] = 0;
    param_1[0x1bfc] = 0;
    param_1[0x1bfb] = 0;
    param_1[0x1bfe] = 0;
    param_1[0x1bfd] = 0;
    param_1[0x1c00] = 0;
    param_1[0x1bff] = 0;
    param_1[0x1c02] = 0;
    param_1[0x1c01] = 0;
    param_1[0x1c04] = 0;
    param_1[0x1c03] = 0;
    param_1[0x1c06] = 0;
    param_1[0x1c05] = 0;
    param_1[0x1c08] = 0;
    param_1[0x1c07] = 0;
    param_1[0x1c0a] = 0;
    param_1[0x1c09] = 0;
    param_1[0x1c0c] = 0;
    param_1[0x1c0b] = 0;
    param_1[0x1c0e] = 0;
    param_1[0x1c0d] = 0;
    param_1[0x1c10] = 0;
    param_1[0x1c0f] = 0;
    param_1[0x1c12] = 0;
    param_1[0x1c11] = 0;
    param_1[0x1c14] = 0;
    param_1[0x1c13] = 0;
    param_1[0x1c16] = 0;
    param_1[0x1c15] = 0;
    param_1[0x1c18] = 0;
    param_1[0x1c17] = 0;
    param_1[0x1c1a] = 0;
    param_1[0x1c19] = 0;
    param_1[0x1c1c] = 0;
    param_1[0x1c1b] = 0;
    param_1[0x1c1e] = 0;
    param_1[0x1c1d] = 0;
    param_1[0x1c20] = 0;
    param_1[0x1c1f] = 0;
    param_1[0x1c22] = 0;
    param_1[0x1c21] = 0;
    param_1[0x1c24] = 0;
    param_1[0x1c23] = 0;
    param_1[0x1c26] = 0;
    param_1[0x1c25] = 0;
    param_1[0x1c28] = 0;
    param_1[0x1c27] = 0;
    param_1[0x1c2a] = 0;
    param_1[0x1c29] = 0;
    param_1[0x1c2c] = 0;
    param_1[0x1c2b] = 0;
    param_1[0x1c2e] = 0;
    param_1[0x1c2d] = 0;
    param_1[0x1c30] = 0;
    param_1[0x1c2f] = 0;
    param_1[0x1c32] = 0;
    param_1[0x1c31] = 0;
    param_1[0x1c34] = 0;
    param_1[0x1c33] = 0;
    param_1[0x1c36] = 0;
    param_1[0x1c35] = 0;
    param_1[0x1c37] = 0;
    *(undefined4 *)(param_1 + 0x1c38) = uVar5;
    *(undefined4 *)((long)param_1 + 0xe1c4) = 0;
    param_1[0x1c39] = uVar10 & 0xffffffff;
    iVar4 = (**(code **)(*param_1 + 0xda0))(*param_1 + 0xda0,param_1);
    *param_3 = iVar4;
    if (iVar4 < 1) {
      lVar6 = 0;
    }
  }
  return lVar6;
}

