// FUN_fffffff0081bd8c4 @ fffffff0081bd8c4 size=332

undefined8 FUN_fffffff0081bd8c4(long param_1,long *param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  uVar7 = 0xe00002c2;
  lVar9 = *(long *)(param_1 + 0x280);
  uVar8 = *(undefined8 *)PTR_DAT_fffffff007ca60a8;
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(param_3,uVar8);
  if (plVar4 != (long *)0x0) {
    uVar2 = (**(code **)(*plVar4 + 0xa8))();
    lVar5 = (**(code **)(*param_2 + 0x138))(param_2,"SetPowerZoneIndex");
    if (lVar5 == 0) {
      uVar7 = 0xe0000001;
    }
    else {
      plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,uVar8);
      if ((plVar4 != (long *)0x0) && (uVar3 = (**(code **)(*plVar4 + 0xa8))(), uVar3 < 5)) {
        uVar7 = 0;
        uVar6 = (ulong)uVar3 << 4 | 8;
        lVar9 = lVar9 + 0x10f94;
        puVar1 = (undefined4 *)(lVar9 + (int)uVar6);
        if (uVar6 != (long)(int)uVar6) {
          puVar1 = (undefined4 *)(lVar9 + uVar6 & 0xffffffffffff | 0x2bad000000000000);
        }
        *puVar1 = uVar2;
        lVar9 = *(long *)(param_1 + 0x918) + 0x24;
        lVar5 = (ulong)uVar3 * 0xc + 8;
        puVar1 = (undefined4 *)(lVar9 + (int)lVar5);
        if (lVar5 != (int)lVar5) {
          puVar1 = (undefined4 *)(lVar9 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
        }
        *puVar1 = uVar2;
      }
    }
  }
  return uVar7;
}

