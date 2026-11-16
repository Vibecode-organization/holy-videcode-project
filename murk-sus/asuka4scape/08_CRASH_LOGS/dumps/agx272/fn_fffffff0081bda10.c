// FUN_fffffff0081bda10 @ fffffff0081bda10 size=376

undefined8 FUN_fffffff0081bda10(long param_1,long *param_2,undefined8 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  
  uVar9 = 0xe00002c2;
  lVar11 = *(long *)(param_1 + 0x280);
  uVar10 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
  plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,uVar10);
  if (plVar6 != (long *)0x0) {
    iVar4 = (**(code **)(*plVar6 + 0xa8))();
    lVar7 = (**(code **)(*param_2 + 0x138))(param_2,"SetPowerZoneIndex");
    if (lVar7 == 0) {
      uVar9 = 0xe0000001;
    }
    else {
      plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar7,uVar10);
      if ((plVar6 != (long *)0x0) && (uVar5 = (**(code **)(*plVar6 + 0xa8))(), uVar5 < 5)) {
        uVar9 = 0;
        lVar11 = lVar11 + 0x10f94;
        lVar7 = (ulong)uVar5 * 0x10;
        iVar8 = (int)lVar7;
        piVar1 = (int *)(lVar11 + iVar8);
        if (lVar7 != iVar8) {
          piVar1 = (int *)(lVar11 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar11 = *(long *)(param_1 + 0x280) + 0x10f94;
        piVar2 = (int *)(lVar11 + iVar8);
        if (lVar7 != iVar8) {
          piVar2 = (int *)(lVar11 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        piVar1[1] = iVar4;
        lVar11 = *(long *)(param_1 + 0x918) + 0x24;
        lVar7 = (ulong)uVar5 * 0xc + 4;
        piVar3 = (int *)(lVar11 + (int)lVar7);
        if (lVar7 != (int)lVar7) {
          piVar3 = (int *)(lVar11 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *piVar3 = *piVar2 - piVar2[1];
        *piVar3 = *piVar1 - iVar4;
      }
    }
  }
  return uVar9;
}

