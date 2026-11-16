// FUN_fffffff00816ac5c @ fffffff00816ac5c size=500

undefined1  [16] FUN_fffffff00816ac5c(undefined8 param_1,long *param_2)

{
  uint uVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  double dVar7;
  double dVar8;
  undefined1 auVar9 [16];
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  
  uVar1 = *(uint *)(param_2 + 1);
  dVar22 = (double)param_2[3];
  lVar3 = *param_2;
  if (uVar1 == 0) {
    uVar4 = 1;
  }
  else {
    uVar6 = 0;
    do {
      dVar15 = *(double *)(lVar3 + uVar6 * 0x58);
      bVar2 = true;
      if ((dVar15 <= (double)param_2[2]) && (bVar2 = false, !NAN(dVar15))) {
        bVar2 = dVar15 == -1.0;
      }
      uVar4 = uVar6;
    } while ((!bVar2) && (uVar6 = uVar6 + 1, uVar4 = (ulong)(uVar1 + 1), uVar1 != uVar6));
  }
  lVar5 = (uVar4 & 0xffffffff) * 0x58;
  uVar4 = lVar3 + (int)lVar5;
  if (lVar5 - (int)lVar5 != 0) {
    uVar4 = lVar3 + lVar5 & 0xffffffffffffU | 0x2bad000000000000;
  }
  dVar13 = (double)param_2[4] + DAT_fffffff007113db8;
  dVar16 = *(double *)(uVar4 + 0x10);
  dVar10 = *(double *)(uVar4 + 0x18);
  dVar21 = *(double *)(uVar4 + 0x20);
  dVar23 = *(double *)(uVar4 + 0x28);
  dVar19 = *(double *)(uVar4 + 0x30);
  dVar15 = *(double *)(uVar4 + 0x38);
  dVar11 = *(double *)(uVar4 + 0x40);
  uVar17 = *(undefined8 *)(uVar4 + 0x48);
  dVar12 = *(double *)(uVar4 + 0x50);
  dVar20 = dVar13 + DAT_fffffff007113dc0 + -10.0;
  dVar7 = (double)thunk_EXT_FUN_801100000114b200(0x4000000000000000,dVar20 / *(double *)(uVar4 + 8))
  ;
  dVar8 = dVar22;
  if (dVar15 <= dVar22) {
    dVar8 = dVar15;
  }
  dVar14 = 0.75;
  if (dVar15 <= 0.75) {
    dVar14 = dVar15;
  }
  dVar21 = (double)thunk_EXT_FUN_801100000114b200
                             (dVar8 / dVar14,dVar21 * (1.0 - (dVar20 / 20.0) * dVar23));
  dVar8 = 0.75;
  if (dVar19 == 0.75 || 0.75 > dVar19) {
    dVar8 = dVar19;
  }
  dVar23 = 0.75;
  if (0.75 <= dVar19) {
    dVar23 = dVar19;
  }
  dVar14 = dVar22;
  if (dVar19 <= dVar22) {
    dVar14 = dVar19;
  }
  dVar18 = dVar22;
  if (dVar22 <= dVar19) {
    dVar18 = dVar19;
  }
  dVar19 = dVar15;
  if (dVar15 <= dVar14) {
    dVar19 = dVar14;
  }
  if (dVar15 <= dVar8) {
    dVar15 = dVar8;
  }
  dVar8 = (double)thunk_EXT_FUN_801100000114b200
                            (dVar16 * (1.0 - (dVar20 / 20.0) * dVar10) + 1.0,
                             (dVar18 - dVar23) / DAT_fffffff007113dc8);
  dVar22 = dVar22 + DAT_fffffff007113dd8;
  dVar10 = (double)thunk_EXT_FUN_801100000114b200(dVar20,0x4000000000000000);
  dVar22 = (double)thunk_EXT_FUN_801100000114b200
                             (uVar17,dVar22 * dVar11 * ((dVar10 / dVar13) * dVar12 + 1.0));
  auVar9._0_8_ = dVar22 * dVar8 * (dVar19 / dVar15) * dVar21 * dVar7 * (double)param_2[2];
  auVar9._8_8_ = 0;
  return auVar9;
}

