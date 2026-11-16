// FUN_fffffff0081fc6d0 @ fffffff0081fc6d0 size=4

undefined8 FUN_fffffff0081fc6d0(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  ulong *puVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong unaff_x30;
  
  if ((*(byte *)(param_1 + 0x2f0) & 1) == 0) goto LAB_fffffff0081fc8a4;
  if (*(long **)(param_1 + 0x2d8) == (long *)0x0) {
LAB_fffffff0081fc798:
    uVar8 = 0;
    plVar6 = *(long **)(param_1 + 0x2e0);
joined_r0xfffffff0081fc7a0:
    if (plVar6 != (long *)0x0) {
      uVar4 = (**(code **)(*plVar6 + 0x160))();
      if ((7 < uVar4) || ((0x8bU >> (ulong)(uVar4 & 0x1f) & 1) == 0)) goto LAB_fffffff0081fc940;
      lVar2 = (ulong)uVar4 * 8;
      puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
      if (lVar2 != (int)lVar2) {
        puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                          0x2bad000000000000);
      }
      uVar9 = *puVar1;
      if ((uVar9 & param_4) != 0) {
        iVar5 = FUN_fffffff0081fc968(*(undefined8 *)(param_1 + 0x2e0),param_2,param_3);
        if (iVar5 == 0) goto LAB_fffffff0081fc898;
        uVar8 = uVar9 | uVar8;
      }
    }
    if (*(long **)(param_1 + 0x2e8) != (long *)0x0) {
      uVar4 = (**(code **)(**(long **)(param_1 + 0x2e8) + 0x160))();
      if ((7 < uVar4) || ((0x8bU >> (ulong)(uVar4 & 0x1f) & 1) == 0)) {
LAB_fffffff0081fc940:
        uVar7 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! unsupported\n");
        return uVar7;
      }
      lVar2 = (ulong)uVar4 * 8;
      puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
      if (lVar2 != (int)lVar2) {
        puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                          0x2bad000000000000);
      }
      uVar9 = *puVar1;
      if ((uVar9 & param_4) != 0) {
        iVar5 = FUN_fffffff0081fc968(*(undefined8 *)(param_1 + 0x2e8),param_2,param_3);
        if (iVar5 == 0) {
          uVar9 = 0;
        }
        uVar8 = uVar8 | uVar9;
      }
    }
  }
  else {
    uVar4 = (**(code **)(**(long **)(param_1 + 0x2d8) + 0x160))();
    if ((7 < uVar4) || ((0x8bU >> (ulong)(uVar4 & 0x1f) & 1) == 0)) goto LAB_fffffff0081fc940;
    lVar2 = (ulong)uVar4 * 8;
    puVar1 = (ulong *)(&DAT_fffffff007115328 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar1 = (ulong *)((ulong)(&DAT_fffffff007115328 + lVar2) & 0xffffffffffff |
                        0x2bad000000000000);
    }
    uVar8 = *puVar1;
    if ((uVar8 & param_4) == 0) goto LAB_fffffff0081fc798;
    iVar5 = FUN_fffffff0081fc968(*(undefined8 *)(param_1 + 0x2d8),param_2,param_3);
    if (iVar5 != 0) {
      plVar6 = *(long **)(param_1 + 0x2e0);
      goto joined_r0xfffffff0081fc7a0;
    }
    uVar8 = 0;
  }
LAB_fffffff0081fc898:
  if (uVar8 != (param_4 & 0xfffffffffffffffe)) {
    FUN_fffffff0081fbde8(param_1,param_2,uVar8);
    return 0;
  }
LAB_fffffff0081fc8a4:
  if ((((param_4 & 1) == 0) && ((*(byte *)(param_1 + 0x1d8) & 1) == 0)) &&
     (*(long *)(param_1 + 0x28) != *(long *)PTR_DAT_fffffff007ca61d0)) {
    return 1;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    uVar7 = FUN_fffffff0081fc968(param_1,param_2,param_3);
    return uVar7;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081fc8fc);
  (*pcVar3)();
}

