// FUN_fffffff0081fd7e8 @ fffffff0081fd7e8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081fdbd0) */

ulong FUN_fffffff0081fd7e8
                (long *param_1,undefined8 param_2,ulong param_3,undefined8 param_4,
                undefined8 param_5)

{
  undefined8 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  
  if (((*(byte *)(param_1 + 0x5e) & 1) != 0) &&
     ((((plVar6 = (long *)param_1[0x5b], plVar6 != (long *)0x0 &&
        (iVar4 = (**(code **)(*plVar6 + 0xd8))(plVar6,param_2,param_3,param_4,param_5), iVar4 == 0))
       || ((plVar6 = (long *)param_1[0x5c], plVar6 != (long *)0x0 &&
           (iVar4 = (**(code **)(*plVar6 + 0xd8))(plVar6,param_2,param_3,param_4,param_5),
           iVar4 == 0)))) ||
      ((plVar6 = (long *)param_1[0x5d], plVar6 != (long *)0x0 &&
       (iVar4 = (**(code **)(*plVar6 + 0xd8))(plVar6,param_2,param_3,param_4,param_5), iVar4 == 0)))
      ))) {
    return 0;
  }
  if ((((*(byte *)(param_1 + 0x5e) & 1) != 0) || (*(int *)((long)param_1 + 0x274) != 0)) &&
     (uVar5 = (**(code **)(*param_1 + 0x160))(param_1), ((uint)param_5 & (uVar5 ^ 0xffffffff)) != 0)
     ) {
    return 1;
  }
  lVar7 = param_1[2];
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a70));
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(lVar7 + 0x11a78));
  lVar7 = param_1[2];
  if (*(int *)(lVar7 + 0x11a68) != 0) {
    uVar11 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! AGXSecureGart::unmapWithAddress\n")
    ;
    return uVar11;
  }
  if ((param_3 >> 0x27 & 1) == 0) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar7 + 0x11df8));
    if ((int)param_1[0x3d] != -1) {
      lVar8 = (long)(int)param_1[0x3d] * 4;
      piVar2 = (int *)(*(long *)(lVar7 + 0x11e28) + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        piVar2 = (int *)(*(long *)(lVar7 + 0x11e28) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *piVar2 = *piVar2 + 1;
    }
    thunk_EXT_FUN_8011000003224180(param_1[0x3a]);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar7 + 0x11df8));
    uVar11 = (ulong)*(uint *)(param_1 + 0x3d);
    if (*(uint *)(param_1 + 0x3d) == 0xffffffff) {
      uVar11 = 0xffffffff;
      bVar3 = true;
      goto LAB_fffffff0081fd9ec;
    }
  }
  else {
    uVar11 = 0x40;
  }
  uVar10 = -(uVar11 >> 0x1f) & 0xfffffff800000000 | uVar11 << 3;
  iVar4 = (int)(uVar11 << 3);
  puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + iVar4);
  if (uVar10 != (long)iVar4) {
    puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + uVar10 & 0xffffffffffff | 0x2bad000000000000);
  }
  thunk_EXT_FUN_80110000032222a8(*puVar1);
  if (0xffffff9fffffffff < param_3) {
    bVar3 = false;
    if (((param_3 < 0xffffffa0c0000000) || (0xfffffffff7ffffff < param_3 + 0x5e76c00000)) ||
       (0xffffffa17fffffff < param_3)) goto LAB_fffffff0081fd9ec;
    if ((DAT_fffffff00ae25928 & 1) == 0) {
      FUN_fffffff008211088(*(undefined8 *)(param_1[0x5a] + 0x18));
    }
    else {
      uVar10 = thunk_EXT_FUN_80110000039eac08(*(undefined8 *)(param_1[0x5a] + 0x10),param_3,param_4)
      ;
      if ((uVar10 & 1) != 0) {
        (**(code **)(**(long **)(param_1[2] + 0x4b0) + 0x228))
                  (*(long **)(param_1[2] + 0x4b0),param_3,0,uVar11);
        plVar6 = *(long **)(param_1[2] + 0x4b0);
        lVar7 = *plVar6;
        (**(code **)(lVar7 + 0x238))(lVar7 + 0x238,plVar6,*(undefined4 *)(param_1[2] + 0x109f4));
      }
    }
  }
  bVar3 = false;
LAB_fffffff0081fd9ec:
  if ((DAT_fffffff00ae25928 & 1) == 0) {
    FUN_fffffff008210f0c(*(undefined8 *)(param_1[0x5a] + 0x18),param_2,param_3,param_4);
    uVar10 = 1;
  }
  else {
    iVar4 = thunk_EXT_FUN_80110000039ea854
                      (*(undefined8 *)(param_1[0x5a] + 0x10),param_2,param_3,param_4);
    uVar10 = (ulong)(iVar4 == 0);
  }
  if (!bVar3) {
    uVar9 = -(uVar11 >> 0x1f) & 0xfffffff800000000 | uVar11 << 3;
    iVar4 = (int)(uVar11 << 3);
    puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + iVar4);
    if (uVar9 != (long)iVar4) {
      puVar1 = (undefined8 *)(DAT_fffffff00ae23b38 + uVar9 & 0xffffffffffff | 0x2bad000000000000);
    }
    thunk_EXT_FUN_8011000003222de0(*puVar1);
  }
  if ((param_3 >> 0x27 & 1) == 0) {
    lVar8 = param_1[2];
    lVar7 = param_1[0x3d];
    thunk_EXT_FUN_8011000003224d30(param_1[0x3a]);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar8 + 0x11df8));
    if ((int)lVar7 != -1) {
      lVar7 = (long)(int)lVar7 * 4;
      piVar2 = (int *)(*(long *)(lVar8 + 0x11e28) + (long)(int)lVar7);
      if (lVar7 - (int)lVar7 != 0) {
        piVar2 = (int *)(*(long *)(lVar8 + 0x11e28) + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
      }
      if (((*piVar2 == 0) || (iVar4 = *piVar2 + -1, *piVar2 = iVar4, iVar4 == 0)) &&
         ((*(byte *)(lVar8 + 0x11e0c) & 1) != 0)) {
        thunk_EXT_FUN_801100000295c97c(*(undefined8 *)(*(long *)(lVar8 + 0x11df0) + 0x160));
      }
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar8 + 0x11df8));
  }
  lVar7 = param_1[2];
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a78));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(lVar7 + 0x11a70));
  return uVar10;
}

