// FUN_fffffff0081bdb88 @ fffffff0081bdb88 size=392

undefined8 FUN_fffffff0081bdb88(long param_1,long *param_2,undefined8 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long lVar12;
  
  uVar10 = 0xe00002c2;
  lVar12 = *(long *)(param_1 + 0x280);
  uVar11 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
  plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,uVar11);
  if (plVar6 != (long *)0x0) {
    uVar4 = (**(code **)(*plVar6 + 0xa8))();
    lVar7 = (**(code **)(*param_2 + 0x138))(param_2,"SetPowerZoneIndex");
    if (lVar7 == 0) {
      uVar10 = 0xe0000001;
    }
    else {
      plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar7,uVar11);
      if ((plVar6 != (long *)0x0) && (uVar5 = (**(code **)(*plVar6 + 0xa8))(), uVar5 < 5)) {
        uVar10 = 0;
        lVar12 = lVar12 + 0x10f94;
        lVar7 = (ulong)uVar5 * 0x10;
        iVar9 = (int)lVar7;
        puVar3 = (undefined4 *)(lVar12 + iVar9);
        if (lVar7 != iVar9) {
          puVar3 = (undefined4 *)(lVar12 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar3 = uVar4;
        lVar12 = *(long *)(param_1 + 0x280) + 0x10f94;
        piVar1 = (int *)(lVar12 + iVar9);
        if (lVar7 != iVar9) {
          piVar1 = (int *)(lVar12 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        lVar12 = *(long *)(param_1 + 0x918) + 0x24;
        lVar8 = ((ulong)uVar5 + (ulong)uVar5 * 2) * 4;
        lVar7 = lVar8 + 4;
        piVar2 = (int *)(lVar12 + (int)lVar7);
        if (lVar7 != (int)lVar7) {
          piVar2 = (int *)(lVar12 + lVar7 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *piVar2 = *piVar1 - piVar1[1];
        puVar3 = (undefined4 *)(lVar12 + (int)lVar8);
        if (lVar8 - (int)lVar8 != 0) {
          puVar3 = (undefined4 *)(lVar12 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar3 = uVar4;
      }
    }
  }
  return uVar10;
}

