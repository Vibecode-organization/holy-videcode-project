// FUN_fffffff0081bb640 @ fffffff0081bb640 size=444

/* WARNING: Removing unreachable block (ram,0xfffffff0081bb6b4) */

undefined8 FUN_fffffff0081bb640(long *param_1,long *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  float *pfVar7;
  undefined4 extraout_s0;
  float fVar8;
  undefined4 uVar9;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar5 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"control");
  uVar9 = extraout_s0;
  if (lVar5 != 0) {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar7 = (float *)(**(code **)(*plVar6 + 0xd8))();
    fVar8 = *pfVar7;
    if (fVar8 != 0.0) {
      bVar1 = false;
      bVar2 = false;
      bVar3 = false;
      if (0.0 <= fVar8) {
        bVar1 = false;
        bVar2 = false;
        bVar3 = true;
        if (!NAN(fVar8)) {
          bVar1 = fVar8 < 65536.0;
          bVar2 = fVar8 == 65536.0;
          bVar3 = false;
        }
      }
      if (!bVar2 && bVar1 == bVar3) {
        return 0xe00002c2;
      }
    }
    lVar5 = param_1[0x123];
    *(float *)(lVar5 + 100) = fVar8;
    uVar9 = *(undefined4 *)(lVar5 + 100);
  }
  lVar5 = (**(code **)(*param_2 + 0x138))(uVar9,param_2,"transfer");
  if (lVar5 == 0) {
    lVar5 = param_1[0x123];
  }
  else {
    plVar6 = (long *)thunk_EXT_FUN_8011000003890f30(lVar5,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if (plVar6 == (long *)0x0) {
      return 0xe00002c2;
    }
    uVar4 = (**(code **)(*plVar6 + 0xa8))();
    if (uVar4 != 0) {
      if (uVar4 < *(uint *)(param_1[0x50] + 0x10aa8)) {
        return 0xe00002c2;
      }
      if ((uint)((int)param_1[0x16e] * 100) < uVar4) {
        return 0xe00002c2;
      }
    }
    lVar5 = param_1[0x123];
    *(uint *)(lVar5 + 0x68) = uVar4;
  }
  *(undefined4 *)(lVar5 + 0x60) = 1;
  return 0;
}

