// FUN_fffffff0081e8640 @ fffffff0081e8640 size=708

/* WARNING: Removing unreachable block (ram,0xfffffff0081e8740) */

void FUN_fffffff0081e8640(long *param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  long *plVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  ulong *puVar12;
  ulong uVar13;
  int iVar14;
  ulong uVar15;
  ulong unaff_x30;
  
  lVar10 = param_1[2];
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar10 + 0x11df8));
  iVar3 = (int)param_1[0x3d];
  if (iVar3 != -1) {
    thunk_EXT_FUN_8011000003223a00(param_1[0x3a]);
    lVar11 = (long)iVar3 * 8;
    iVar9 = (int)lVar11;
    if ((*(int *)(lVar10 + 0x11e00) < 2) ||
       (iVar14 = 1 << (ulong)(-(int)LZCOUNT(*(int *)(lVar10 + 0x11e00) + -1) & 0x1f),
       iVar5 = iVar14 + -1, iVar5 == 0 || iVar14 < 1)) {
      puVar12 = (ulong *)(*(long *)(lVar10 + 0x11e18) + (long)iVar9);
      if (lVar11 - iVar9 != 0) {
        puVar12 = (ulong *)(*(long *)(lVar10 + 0x11e18) + lVar11 & 0xffffffffffffU |
                           0x2bad000000000000);
      }
      uVar15 = 0xffffffffffffffff;
      uVar13 = 0;
    }
    else {
      puVar12 = (ulong *)(*(long *)(lVar10 + 0x11e18) + (long)iVar9);
      if (lVar11 - iVar9 != 0) {
        puVar12 = (ulong *)(*(long *)(lVar10 + 0x11e18) + lVar11 & 0xffffffffffffU |
                           0x2bad000000000000);
      }
      iVar14 = (int)LZCOUNT(iVar5);
      uVar13 = (ulong)(iVar14 + 0x20);
      uVar15 = 0xffffffffffffffff;
      if (iVar14 != 0x20) {
        uVar15 = ~(-1L << (uVar13 & 0x3f));
      }
    }
    *puVar12 = (*puVar12 & uVar15) + 1 & uVar15 | (long)iVar3 << (uVar13 & 0x3f);
    puVar1 = (undefined8 *)(*(long *)(lVar10 + 0x11e20) + (long)iVar9);
    if (lVar11 - iVar9 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(lVar10 + 0x11e20) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = 0;
    (**(code **)(*param_1 + 0x128))(*param_1 + 0x128,param_1,0xffffffff);
    for (uVar15 = 0;
        uVar13 = thunk_EXT_FUN_8011000002946bb0
                           (*(undefined8 *)(*(long *)(lVar10 + 0x11df0) + 0x148)),
        uVar15 < (uVar13 & 0xffffffff); uVar15 = uVar15 + 1) {
      if (*(int *)(*(long *)(lVar10 + 0x11e10) + uVar15 * 4) == iVar3) {
        *(undefined4 *)(*(long *)(lVar10 + 0x11e10) + uVar15 * 4) = 0xffffffff;
      }
    }
    thunk_EXT_FUN_8011000003224d30(param_1[0x3a]);
    lVar11 = (long)*(int *)(lVar10 + 0x11e38) + 1;
    *(int *)(lVar10 + 0x11e38) = (int)lVar11;
    lVar11 = lVar11 * 4;
    piVar2 = (int *)(*(long *)(lVar10 + 0x11e30) + (long)(int)lVar11);
    if (lVar11 - (int)lVar11 != 0) {
      piVar2 = (int *)(*(long *)(lVar10 + 0x11e30) + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *piVar2 = iVar3;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar10 + 0x11df8));
  if ((long *)param_1[0x3c] != (long *)0x0) {
    (**(code **)(*(long *)param_1[0x3c] + 0x18))();
    param_1[0x3c] = 0;
  }
  if (param_1[0x3a] != 0) {
    thunk_EXT_FUN_80110000038ff474();
    param_1[0x3a] = 0;
  }
  uVar15 = 0xfffffffffffffff2;
  lVar10 = 1;
  do {
    plVar8 = (long *)param_1[lVar10 + 0x3e];
    if (plVar8 != (long *)0x0) {
      if ((1 << (ulong)((int)uVar15 + 0xfU & 0x1f) & 0x5f80U) == 0) {
LAB_fffffff0081e8874:
        (**(code **)(*plVar8 + 0x28))();
        bVar4 = *(byte *)(param_1 + 0x54);
        param_1[lVar10 + 0x3e] = 0;
        if ((bVar4 & 1) == 0) goto LAB_fffffff0081e883c;
      }
      else {
        thunk_EXT_FUN_80110000032222a8(DAT_fffffff00ae23bd0);
        *(undefined1 *)(param_1 + 0x54) = 1;
        plVar8 = (long *)param_1[lVar10 + 0x3e];
        if (plVar8 != (long *)0x0) goto LAB_fffffff0081e8874;
        param_1[lVar10 + 0x3e] = 0;
      }
      *(undefined1 *)(param_1 + 0x54) = 0;
      thunk_EXT_FUN_8011000003222de0(DAT_fffffff00ae23bd0);
    }
LAB_fffffff0081e883c:
    lVar10 = lVar10 + 1;
    bVar7 = 0xfffffffffffffffe < uVar15;
    uVar15 = uVar15 + 1;
    if (bVar7) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e88d4);
        (*pcVar6)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e88dc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(PTR_DAT_fffffff007ca6188 + 0x80))(param_1);
      return;
    }
  } while( true );
}

