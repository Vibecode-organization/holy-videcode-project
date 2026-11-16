// FUN_fffffff0081b6a04 @ fffffff0081b6a04 size=500

undefined8
FUN_fffffff0081b6a04
          (undefined8 param_1,ulong *param_2,uint param_3,uint *param_4,undefined8 param_5,
          ulong param_6,undefined8 param_7)

{
  ulong *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  undefined4 uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  
  puVar5 = PTR_DAT_fffffff007ca5f88;
  if (param_2 == (ulong *)0x0) {
    return 0;
  }
  if ((int)param_6 == 1) {
    uVar10 = *param_2;
    *param_4 = (uint)uVar10 &
               (-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f) ^ 0xffffffffU);
    iVar3 = 1 << (ulong)(*(uint *)puVar5 & 0x1f);
    uVar9 = 3;
    if ((int)param_5 == 0) {
      uVar9 = 1;
    }
    plVar6 = (long *)thunk_EXT_FUN_8011000003976f54
                               (uVar10 & (long)-iVar3,
                                ((uVar10 + param_3 + (long)iVar3) - 1 & -(long)iVar3) -
                                (uVar10 & (long)-iVar3),uVar9);
  }
  else {
    *param_4 = 0;
    puVar5 = PTR_DAT_fffffff007ca5f88;
    if ((param_3 & (-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f) ^ 0xffffffffU)) != 0) {
      return 0;
    }
    lVar4 = (param_6 & 0xffffffff) << 4;
    lVar8 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca34c8,lVar4);
    if (lVar8 == 0) {
      return 0;
    }
    if ((int)param_6 != 0) {
      lVar11 = 0;
      uVar10 = param_6 & 0xffffffff;
      uVar2 = *(uint *)puVar5;
      do {
        if ((param_2[lVar11] & (ulong)(uint)~(-1 << (ulong)(uVar2 & 0x1f))) != 0) {
          thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3518,lVar8,lVar4);
          return 0;
        }
        lVar12 = lVar11 * 0x10;
        puVar1 = (ulong *)(lVar8 + (int)lVar12);
        if (lVar12 - (int)lVar12 != 0) {
          puVar1 = (ulong *)(lVar8 + lVar12 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar1 = param_2[lVar11];
        puVar1[1] = (ulong)param_3;
        lVar11 = lVar11 + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    uVar9 = 3;
    if ((int)param_5 == 0) {
      uVar9 = 1;
    }
    plVar6 = (long *)thunk_EXT_FUN_8011000003977010(lVar8,param_6,uVar9,0);
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca3568,lVar8,lVar4);
  }
  if (plVar6 == (long *)0x0) {
    return 0;
  }
  uVar7 = FUN_fffffff0081b6bf8(param_1,plVar6,param_5,param_7);
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return uVar7;
}

