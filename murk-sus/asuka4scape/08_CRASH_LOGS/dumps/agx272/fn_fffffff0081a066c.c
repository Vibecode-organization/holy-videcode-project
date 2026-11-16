// FUN_fffffff0081a066c @ fffffff0081a066c size=4

ulong FUN_fffffff0081a066c(long *param_1,long param_2,ulong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  int *piVar6;
  uint *puVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  ulong uVar12;
  undefined8 uVar13;
  bool bVar14;
  ulong auStack_60 [4];
  
  auStack_60[1] = *(ulong *)(param_2 + 0x18);
  auStack_60[0] = *(ulong *)(param_2 + 0x10);
  if ((*(byte *)(param_2 + 0x8b) & 1) == 0) {
    return auStack_60[0];
  }
  plVar4 = (long *)(**(code **)(*param_1 + 0x370))();
  uVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-fstp-downgrade");
  uVar13 = *(undefined8 *)PTR_DAT_fffffff007ca6090;
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(uVar5,uVar13);
  if ((plVar4 == (long *)0x0) || (piVar6 = (int *)(**(code **)(*plVar4 + 0xd8))(), *piVar6 == 0)) {
    bVar14 = true;
  }
  else if ((auStack_60[1] == 0 && auStack_60[0] == 0) ||
          (param_3 !=
           (ulong)(byte)(POPCOUNT((char)auStack_60[1]) + POPCOUNT((char)(auStack_60[1] >> 8)) +
                         POPCOUNT((char)(auStack_60[1] >> 0x10)) +
                         POPCOUNT((char)(auStack_60[1] >> 0x18)) +
                         POPCOUNT((char)(auStack_60[1] >> 0x20)) +
                         POPCOUNT((char)(auStack_60[1] >> 0x28)) +
                         POPCOUNT((char)(auStack_60[1] >> 0x30)) +
                        POPCOUNT((char)(auStack_60[1] >> 0x38))) +
           (ulong)(byte)(POPCOUNT((char)auStack_60[0]) + POPCOUNT((char)(auStack_60[0] >> 8)) +
                         POPCOUNT((char)(auStack_60[0] >> 0x10)) +
                         POPCOUNT((char)(auStack_60[0] >> 0x18)) +
                         POPCOUNT((char)(auStack_60[0] >> 0x20)) +
                         POPCOUNT((char)(auStack_60[0] >> 0x28)) +
                         POPCOUNT((char)(auStack_60[0] >> 0x30)) +
                        POPCOUNT((char)(auStack_60[0] >> 0x38))))) {
    bVar14 = false;
  }
  else {
    if (auStack_60[1] == 0) {
      if (auStack_60[0] != 0) {
        uVar9 = 0;
        uVar8 = auStack_60[0];
        goto LAB_fffffff0081a07a0;
      }
      uVar8 = 0xffffffff;
    }
    else {
      uVar9 = 0x40;
      uVar8 = auStack_60[1];
LAB_fffffff0081a07a0:
      uVar8 = (LZCOUNT(uVar8) | uVar9) ^ 0x3f;
    }
    bVar14 = false;
    uVar9 = uVar8 >> 3 & 0x1ffffff8;
    *(ulong *)((long)auStack_60 + uVar9) =
         *(ulong *)((long)auStack_60 + uVar9) & (1L << (uVar8 & 0x3f) ^ 0xffffffffffffffffU);
  }
  plVar4 = (long *)(**(code **)(*param_1 + 0x370))();
  uVar5 = (**(code **)(*plVar4 + 0x118))(plVar4,"gpu-fstp-downgrade-mask");
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(uVar5,uVar13);
  if (plVar4 == (long *)0x0) {
    return auStack_60[0];
  }
  puVar7 = (uint *)(**(code **)(*plVar4 + 0xd8))();
  uVar2 = *puVar7;
  if (uVar2 == 0) {
    return auStack_60[0];
  }
  if (!bVar14) {
    uVar8 = thunk_EXT_FUN_8011000003a49114
                      (
                      "AGXk: %s:%d:%s: !!! Cannot have both gpu-fstp-downgrade and gpu-fstp-downgrade-mask specified at the same time.\n"
                      );
    return uVar8;
  }
  if (auStack_60[1] == 0 && auStack_60[0] == 0) {
    return auStack_60[0];
  }
  if (param_3 !=
      (ulong)(byte)(POPCOUNT((char)auStack_60[1]) + POPCOUNT((char)(auStack_60[1] >> 8)) +
                    POPCOUNT((char)(auStack_60[1] >> 0x10)) +
                    POPCOUNT((char)(auStack_60[1] >> 0x18)) +
                    POPCOUNT((char)(auStack_60[1] >> 0x20)) +
                    POPCOUNT((char)(auStack_60[1] >> 0x28)) +
                    POPCOUNT((char)(auStack_60[1] >> 0x30)) +
                   POPCOUNT((char)(auStack_60[1] >> 0x38))) +
      (ulong)(byte)(POPCOUNT((char)auStack_60[0]) + POPCOUNT((char)(auStack_60[0] >> 8)) +
                    POPCOUNT((char)(auStack_60[0] >> 0x10)) +
                    POPCOUNT((char)(auStack_60[0] >> 0x18)) +
                    POPCOUNT((char)(auStack_60[0] >> 0x20)) +
                    POPCOUNT((char)(auStack_60[0] >> 0x28)) +
                    POPCOUNT((char)(auStack_60[0] >> 0x30)) +
                   POPCOUNT((char)(auStack_60[0] >> 0x38)))) {
    return auStack_60[0];
  }
  auStack_60[2] = 0;
  auStack_60[3] = 0;
  if (param_3 < 0x40) {
    uVar8 = 0;
    goto LAB_fffffff0081a0924;
  }
  uVar3 = (uint)param_3 - 0x40;
  uVar8 = (ulong)((uVar3 >> 6) + 1);
  if (uVar3 < 0xc0) {
    uVar9 = 0;
LAB_fffffff0081a08e4:
    lVar10 = ((uVar3 >> 6) - uVar9) + 1;
    do {
      iVar11 = (int)(uVar9 * 8);
      puVar1 = (undefined8 *)((long)auStack_60 + (long)iVar11 + 0x10);
      if (uVar9 * 8 - (long)iVar11 != 0) {
        puVar1 = (undefined8 *)
                 ((ulong)(auStack_60 + uVar9 + 2) & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar1 = 0xffffffffffffffff;
      uVar9 = uVar9 + 1;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
  else {
    lVar10 = 0;
    uVar9 = uVar8 & 0x7fffffc;
    uVar12 = uVar9;
    do {
      *(undefined8 *)(&stack0xffffffffffffffc8 + lVar10 * 8) = 0xffffffffffffffff;
      *(undefined8 *)(&stack0xffffffffffffffc0 + lVar10 * 8) = 0xffffffffffffffff;
      lVar10 = lVar10 + 4;
      uVar12 = uVar12 - 4;
    } while (uVar12 != 0);
    if (uVar9 != uVar8) goto LAB_fffffff0081a08e4;
  }
  param_3 = (ulong)((uint)param_3 & 0x3f);
LAB_fffffff0081a0924:
  if ((int)param_3 != 0) {
    auStack_60[uVar8 + 2] = auStack_60[uVar8 + 2] | -1L << (param_3 & 0x3f) ^ 0xffffffffffffffffU;
  }
  return auStack_60[0] & (auStack_60[2] & uVar2 ^ 0xffffffffffffffff);
}

