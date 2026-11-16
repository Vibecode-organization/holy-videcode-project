// FUN_fffffff0081edb74 @ fffffff0081edb74 size=904

undefined8 FUN_fffffff0081edb74(long *param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  long lVar8;
  ulong uVar9;
  undefined4 uVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  uint uVar14;
  
  *(undefined4 *)(param_1 + 0x47) = 0;
  lVar4 = thunk_EXT_FUN_80110000038fe750
                    (&DAT_fffffff007ca4878,(ulong)*(uint *)(param_1 + 0x27) << 3);
  param_1[0x46] = lVar4;
  uVar6 = 0;
  if (lVar4 != 0) {
    uVar14 = 0;
    puVar7 = (undefined4 *)param_1[0x11];
    *puVar7 = 0;
    puVar7[1] = 0;
    puVar7[2] = 0;
    while( true ) {
      uVar1 = *(uint *)((long)param_1 + 0x13c);
      if (*(uint *)((long)param_1 + 0x13c) <= *(uint *)(param_1 + 0x28)) {
        uVar1 = *(uint *)(param_1 + 0x28);
      }
      if (uVar1 <= uVar14) break;
      lVar4 = (**(code **)(*param_1 + 0xd0))(param_1);
      if (lVar4 == 0) {
        return 0;
      }
      lVar8 = (ulong)*(uint *)(lVar4 + 0xc) * 8;
      plVar5 = (long *)(param_1[0x32] + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        plVar5 = (long *)(param_1[0x32] + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar5 = lVar4;
      param_1[0x25] = param_1[0x25] + 0x20000;
      uVar14 = uVar14 + 1;
    }
    plVar5 = (long *)param_1[2];
    if ((*(byte *)((long)plVar5 + 0x1ac44) >> 3 & 1) != 0) {
      lVar4 = param_1[0x25];
      iVar2 = *(int *)(param_1[3] + 0x60);
      thunk_EXT_FUN_80110000032222a8(plVar5[0x3589]);
      thunk_EXT_FUN_80110000036da494(0x85930da4,lVar4,5,(long)iVar2,param_1,0);
      thunk_EXT_FUN_8011000003222de0(plVar5[0x3589]);
      plVar5 = (long *)param_1[2];
    }
    lVar4 = plVar5[0x22c0];
    if (lVar4 == 0) {
      lVar4 = (**(code **)(*plVar5 + 0xc10))(plVar5,0xc000000);
      plVar5 = (long *)param_1[2];
    }
    uVar11 = param_1[0x3b];
    uVar14 = *(uint *)((long)plVar5 + 0x414);
    uVar9 = 0;
    if (uVar11 != 0) {
      uVar9 = ((uVar11 + (lVar4 + 0x7fffU >> 0xf)) - 1) / uVar11;
    }
    if ((1 < uVar14) && ((int)param_1[0xb] != 0)) {
      uVar9 = uVar9 + ((uVar14 << (ulong)(*(uint *)((long)param_1 + 0x54) & 0x1f)) + uVar14);
    }
    uVar11 = (param_1[0x3c] + param_1[0x3d] * uVar9 + param_1[0x3e]) - 1 & -param_1[0x3e];
    uVar14 = *(uint *)(param_1 + 10);
    uVar9 = uVar11;
    if ((*(byte *)(plVar5 + 0x2136) & 1) == 0) {
      uVar9 = 0;
    }
    bVar3 = (plVar5[0xb9] & 0x200000000000U) != 0;
    uVar10 = 5;
    if (bVar3) {
      uVar10 = 1;
    }
    uVar12 = 0x4000000003;
    if (bVar3) {
      uVar12 = 0x5000000003;
    }
    plVar5 = (long *)FUN_fffffff0081f9fc0(plVar5,param_1[3],uVar11 * uVar14 + uVar9,uVar12,uVar10);
    param_1[9] = (long)plVar5;
    uVar6 = 0;
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x20))();
      (**(code **)(*(long *)param_1[9] + 0xb0))((long *)param_1[9],param_1[3]);
      plVar5 = *(long **)(param_1[9] + 0x20);
      if (*(uint *)(plVar5[3] + 0x78) < *(uint *)(param_1 + 0x21)) {
        thunk_EXT_FUN_801100000293ff9c(plVar5[3]);
        plVar5 = *(long **)(param_1[9] + 0x20);
      }
      lVar4 = (**(code **)(*plVar5 + 0xa0))();
      if ((int)param_1[10] != 0) {
        uVar9 = 0;
        lVar8 = lVar4 + uVar11 * uVar14;
        do {
          puVar13 = *(undefined8 **)(param_1[0xf] + uVar9 * 8);
          *puVar13 = 0;
          puVar13[1] = 0;
          puVar13[2] = 0;
          puVar13[3] = lVar4;
          if ((*(byte *)(param_1[2] + 0x109b0) & 1) != 0) {
            puVar13[4] = lVar8;
          }
          puVar13[6] = param_1[0x12];
          uVar9 = uVar9 + 1;
          lVar4 = lVar4 + uVar11;
        } while (uVar9 < *(uint *)(param_1 + 10));
      }
      plVar5 = (long *)FUN_fffffff0081f9fc0(param_1[2],param_1[3],0x8000,uVar12,uVar10);
      param_1[0x45] = (long)plVar5;
      uVar6 = 0;
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))();
        (**(code **)(*(long *)param_1[0x45] + 0xb0))((long *)param_1[0x45],param_1[3]);
        if (*(uint *)(*(long *)(*(long *)(param_1[0x45] + 0x20) + 0x18) + 0x78) <
            *(uint *)(param_1 + 0x21)) {
          thunk_EXT_FUN_801100000293ff9c();
        }
        uVar6 = 1;
      }
    }
  }
  return uVar6;
}

