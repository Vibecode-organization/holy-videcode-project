// FUN_fffffff008183128 @ fffffff008183128 size=720

undefined8 FUN_fffffff008183128(long param_1,long param_2)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  
  uVar9 = *(ulong *)(param_1 + 0x28);
  uVar7 = *(ulong *)(param_1 + 0x30);
  if (uVar7 < uVar9) {
    lVar8 = *(long *)(param_1 + 0x20);
  }
  else {
    uVar7 = uVar9 << 1;
    bVar1 = uVar9 != 0;
    uVar9 = 4;
    if (bVar1) {
      uVar9 = uVar7;
    }
    uVar7 = uVar9 << 3;
    if (0x7fffffffffffffff < uVar7) {
      uVar7 = 0x8000000000000000;
    }
    if (uVar9 >> 0x3d != 0) {
      uVar7 = 0x8000000000000000;
    }
    lVar8 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2de8,uVar7);
    if (lVar8 == 0) {
      return 0;
    }
    uVar7 = *(ulong *)(param_1 + 0x30);
    if (*(long *)(param_1 + 0x20) != 0) {
      thunk_EXT_FUN_8011000003a61b10(lVar8,*(long *)(param_1 + 0x20),uVar7 << 3);
      uVar7 = *(ulong *)(param_1 + 0x30);
    }
  }
  plVar2 = (long *)thunk_EXT_FUN_8011000003962c64
                             (0x10000,(param_2 + *(long *)PTR_DAT_fffffff007ca61e8) - 1U &
                                      -*(long *)PTR_DAT_fffffff007ca61e8,1);
  if (plVar2 == (long *)0x0) goto LAB_fffffff008183310;
  lVar6 = uVar7 * 8;
  plVar3 = (long *)(lVar8 + (int)lVar6);
  if (lVar6 - (int)lVar6 != 0) {
    plVar3 = (long *)(lVar8 + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
  }
  *plVar3 = (long)plVar2;
  plVar3 = (long *)thunk_EXT_FUN_8011000003979b9c(lVar8,(int)uVar7 + 1,0,1);
  if (plVar3 == (long *)0x0) {
    plVar4 = (long *)0x0;
LAB_fffffff0081832ec:
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  else {
    plVar4 = (long *)thunk_EXT_FUN_801100000396cb64
                               (plVar3,*(undefined8 *)PTR_DAT_fffffff007ca61d0,0,1,0,0);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x20))(plVar4);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      plVar2 = (long *)0x0;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
    if (plVar2 != (long *)0x0) goto LAB_fffffff0081832ec;
  }
  if (plVar4 != (long *)0x0) {
    if (*(long **)(param_1 + 0x38) == (long *)0x0) {
      lVar6 = 0;
    }
    else {
      lVar6 = *(long *)(param_1 + 0x48) - *(long *)(param_1 + 0x40);
      (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
    }
    *(long **)(param_1 + 0x38) = plVar4;
    uVar5 = (**(code **)(*plVar4 + 0x78))(plVar4);
    uVar7 = uVar5 + lVar6;
    if (((uVar5 ^ uVar7) & 0xffc0000000000000) != 0) {
      uVar7 = uVar7 & 0xffffffffffff | 0xc8a2000000000000;
    }
    *(ulong *)(param_1 + 0x40) = uVar5;
    *(ulong *)(param_1 + 0x48) = uVar7;
    lVar6 = *(long *)(param_1 + 0x20);
    if (lVar8 != lVar6) {
      if (lVar6 != 0) {
        uVar7 = *(ulong *)(param_1 + 0x28) << 3;
        if (0x7fffffffffffffff < uVar7) {
          uVar7 = 0x8000000000000000;
        }
        if (*(ulong *)(param_1 + 0x28) >> 0x3d != 0) {
          uVar7 = 0x8000000000000000;
        }
        *(undefined8 *)(param_1 + 0x20) = 0;
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2e38,lVar6,uVar7);
      }
      *(long *)(param_1 + 0x20) = lVar8;
      *(ulong *)(param_1 + 0x28) = uVar9;
    }
    *(long *)(param_1 + 0x30) = *(long *)(param_1 + 0x30) + 1;
    return 1;
  }
LAB_fffffff008183310:
  if (lVar8 != *(long *)(param_1 + 0x20)) {
    uVar7 = uVar9 << 3;
    if (0x7fffffffffffffff < uVar7) {
      uVar7 = 0x8000000000000000;
    }
    if (uVar9 >> 0x3d != 0) {
      uVar7 = 0x8000000000000000;
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2d98,lVar8,uVar7);
  }
  return 0;
}

