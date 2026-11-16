// FUN_fffffff008180f64 @ fffffff008180f64 size=4

long * FUN_fffffff008180f64(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  ulong uVar9;
  long *plVar10;
  long *plVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  long lVar15;
  float fVar16;
  long *plStack_70;
  float fStack_64;
  
  lVar14 = *(long *)(param_1 + 0x4b0);
  plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(2);
  if (plVar6 == (long *)0x0) {
    return (long *)0x0;
  }
  uVar3 = *(uint *)(*(long *)(lVar14 + 0x280) + 0x19440);
  uVar12 = (ulong)uVar3;
  plVar7 = (long *)thunk_EXT_FUN_80110000038961f4(uVar12);
  if (plVar7 == (long *)0x0) {
    plVar8 = (long *)0x0;
    goto LAB_fffffff00818124c;
  }
  plVar8 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar12,0x20);
  plVar11 = plVar6;
  if (plVar8 == (long *)0x0) {
LAB_fffffff00818121c:
    plVar8 = (long *)0x0;
  }
  else {
    iVar5 = (**(code **)(*plVar6 + 0x100))(plVar6,"valid_perf_states",plVar8);
    (**(code **)(*plVar8 + 0x28))(plVar8);
    if (iVar5 == 0) goto LAB_fffffff00818121c;
    if (uVar3 != 0) {
      uVar13 = 0;
      lVar15 = (ulong)(uVar3 - 1) * 4;
      do {
        lVar1 = *(long *)(lVar14 + 0x280) + 0x19448;
        puVar2 = (undefined4 *)(lVar1 + (int)lVar15);
        if (lVar15 - (int)lVar15 != 0) {
          puVar2 = (undefined4 *)(lVar1 + lVar15 & 0xffffffffffffU | 0x2bad000000000000);
        }
        fStack_64 = (float)NEON_ucvtf(*(undefined4 *)(lVar1 + uVar13 * 4));
        fVar16 = (float)NEON_ucvtf(*puVar2);
        fStack_64 = fStack_64 / fVar16;
        plVar8 = (long *)thunk_EXT_FUN_801100000389a264(&fStack_64,4);
        if (plVar8 == (long *)0x0) goto LAB_fffffff00818121c;
        plStack_70 = plVar8;
        (**(code **)(*plVar8 + 0x20))();
        uVar9 = thunk_EXT_FUN_8011000003896428(plVar7,uVar13,&plStack_70);
        if (plStack_70 != (long *)0x0) {
          (**(code **)(*plStack_70 + 0x28))();
        }
        (**(code **)(*plVar8 + 0x28))(plVar8);
        if ((uVar9 & 1) == 0) goto LAB_fffffff00818121c;
        uVar13 = uVar13 + 1;
      } while (uVar12 != uVar13);
    }
    plStack_70 = plVar7;
    (**(code **)(*plVar7 + 0x20))(plVar7);
    iVar5 = thunk_EXT_FUN_801100000389d40c(plVar6,"ce_normalized",&plStack_70);
    if (plStack_70 != (long *)0x0) {
      (**(code **)(*plStack_70 + 0x28))();
    }
    if (iVar5 == 0) goto LAB_fffffff00818121c;
    plVar10 = (long *)thunk_EXT_FUN_80110000038c6e24
                                ((ulong)*(uint *)(*(long *)(lVar14 + 0x280) + 0x10f5c) / 100,0x20);
    plVar8 = (long *)0x0;
    if (plVar10 != (long *)0x0) {
      uVar12 = (**(code **)(*plVar6 + 0x100))(plVar6,"base_perf_state",plVar10);
      (**(code **)(*plVar10 + 0x28))(plVar10);
      bVar4 = (uVar12 & 1) == 0;
      plVar8 = plVar6;
      if (bVar4) {
        plVar8 = (long *)0x0;
      }
      plVar11 = (long *)0x0;
      if (bVar4) {
        plVar11 = plVar6;
      }
    }
  }
  (**(code **)(*plVar7 + 0x28))(plVar7);
  plVar6 = plVar11;
  if (plVar11 == (long *)0x0) {
    return plVar8;
  }
LAB_fffffff00818124c:
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return plVar8;
}

