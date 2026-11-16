// FUN_fffffff0081f739c @ fffffff0081f739c size=640

long FUN_fffffff0081f739c(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  undefined8 uVar18;
  bool bVar19;
  long *plVar20;
  long lVar21;
  undefined4 uVar22;
  ulong uVar23;
  
  uVar10 = *(ulong *)(param_1 + 0x140);
  lVar11 = *(long *)(param_1 + 0x148);
  lVar21 = *(long *)(param_1 + 0x188);
  lVar12 = *(long *)(param_1 + 400);
  uVar8 = uVar10;
  if (lVar21 != 0) {
    uVar8 = (uVar10 + lVar21) - 1 & -lVar21;
  }
  uVar1 = uVar8 + lVar11;
  if (lVar12 != 0) {
    uVar1 = (uVar1 + lVar12) - 1 & -lVar12;
  }
  lVar21 = *(long *)(param_1 + 0x150);
  lVar13 = *(long *)(param_1 + 0x158);
  uVar2 = uVar1 + lVar21;
  lVar12 = *(long *)(param_1 + 0x198);
  lVar14 = *(long *)(param_1 + 0x1a0);
  if (lVar12 != 0) {
    uVar2 = (lVar12 + uVar2) - 1 & -lVar12;
  }
  uVar3 = uVar2 + lVar13;
  if (lVar14 != 0) {
    uVar3 = (lVar14 + uVar3) - 1 & -lVar14;
  }
  lVar12 = *(long *)(param_1 + 0x160);
  lVar15 = *(long *)(param_1 + 0x168);
  uVar4 = uVar3 + lVar12;
  lVar14 = *(long *)(param_1 + 0x1a8);
  lVar16 = *(long *)(param_1 + 0x1b0);
  if (lVar14 != 0) {
    uVar4 = (lVar14 + uVar4) - 1 & -lVar14;
  }
  uVar5 = uVar4 + lVar15;
  if (lVar16 != 0) {
    uVar5 = (lVar16 + uVar5) - 1 & -lVar16;
  }
  lVar14 = *(long *)(param_1 + 0x170);
  lVar17 = *(long *)(param_1 + 0x178);
  uVar6 = uVar5 + lVar14;
  lVar16 = *(long *)(param_1 + 0x1b8);
  plVar20 = *(long **)(param_1 + 0x1c0);
  if (lVar16 != 0) {
    uVar6 = (lVar16 + uVar6) - 1 & -lVar16;
  }
  uVar7 = uVar6 + lVar17;
  if (*(ulong *)(param_1 + 0x1c8) < uVar7) {
    lVar16 = *(long *)(param_1 + 0x120);
    uVar18 = *(undefined8 *)(param_1 + 0x128);
    uVar23 = *(ulong *)(lVar16 + 0x5c8);
    if (plVar20 != (long *)0x0) {
      (**(code **)(*plVar20 + 0xb0))(plVar20,uVar18);
      (**(code **)(**(long **)(param_1 + 0x1c0) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined8 *)(param_1 + 0x1c8) = 0;
    bVar19 = (uVar23 & 0x200000000000) != 0;
    uVar9 = 3;
    if (bVar19) {
      uVar9 = 0x1000000003;
    }
    uVar22 = 5;
    if (bVar19) {
      uVar22 = 1;
    }
    plVar20 = (long *)FUN_fffffff0081f9fc0(lVar16,uVar18,uVar7,uVar9,uVar22);
    *(long **)(param_1 + 0x1c0) = plVar20;
    if (plVar20 == (long *)0x0) {
      return 0;
    }
    *(ulong *)(param_1 + 0x1c8) = uVar7;
    (**(code **)(*plVar20 + 0x20))();
    plVar20 = *(long **)(param_1 + 0x1c0);
    if (*(uint *)(plVar20[5] + 0x78) < *(uint *)(param_1 + 600)) {
      thunk_EXT_FUN_801100000293ff9c(plVar20[5]);
      plVar20 = *(long **)(param_1 + 0x1c0);
    }
  }
  *(ulong *)(param_1 + 0x1d0) = uVar7;
  *(ulong *)(param_1 + 0x1d8) = uVar10;
  *(long *)(param_1 + 0x1e0) = lVar11;
  *(long *)(param_1 + 0x1e8) = lVar21;
  *(long *)(param_1 + 0x1f0) = lVar13;
  *(long *)(param_1 + 0x1f8) = lVar12;
  *(long *)(param_1 + 0x200) = lVar15;
  *(long *)(param_1 + 0x208) = lVar14;
  *(long *)(param_1 + 0x210) = lVar17;
  *(undefined8 *)(param_1 + 0x218) = 0;
  *(ulong *)(param_1 + 0x220) = uVar8;
  *(ulong *)(param_1 + 0x228) = uVar1;
  *(ulong *)(param_1 + 0x230) = uVar2;
  *(ulong *)(param_1 + 0x238) = uVar3;
  *(ulong *)(param_1 + 0x240) = uVar4;
  *(ulong *)(param_1 + 0x248) = uVar5;
  *(ulong *)(param_1 + 0x250) = uVar6;
  lVar21 = 0;
  if (plVar20 != (long *)0x0) {
    lVar21 = plVar20[3];
  }
  return lVar21;
}

