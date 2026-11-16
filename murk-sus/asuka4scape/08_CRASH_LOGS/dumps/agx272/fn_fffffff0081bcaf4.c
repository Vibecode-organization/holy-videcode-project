// FUN_fffffff0081bcaf4 @ fffffff0081bcaf4 size=448

/* WARNING: Removing unreachable block (ram,0xfffffff0081bcb60) */

undefined8 FUN_fffffff0081bcaf4(long *param_1,long *param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  float *pfVar4;
  int iVar5;
  undefined8 uVar6;
  float fVar7;
  float fVar8;
  
  (**(code **)(*param_1 + 0x6c0))(param_1,0,0);
  lVar2 = (**(code **)(*param_2 + 0x138))(*param_2 + 0x138,param_2,"control");
  if (lVar2 != 0) {
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca6090);
    if (plVar3 == (long *)0x0) {
      return 0xe00002c2;
    }
    pfVar4 = (float *)(**(code **)(*plVar3 + 0xd8))();
    fVar7 = *pfVar4;
    if (fVar7 != 0.0) {
      if (fVar7 < 0.0) {
        return 0xe00002c2;
      }
      fVar8 = (float)NEON_ucvtf((int)param_1[0x31e]);
      if (fVar8 < fVar7) {
        return 0xe00002c2;
      }
    }
    iVar5 = (int)fVar7;
    *(int *)(param_1 + 800) = iVar5;
    if (iVar5 == 0) {
      iVar5 = *(int *)((long)param_1 + 0x18ec);
    }
    *(int *)(param_1[0x69] + 0xe4) = iVar5;
  }
  lVar2 = (**(code **)(*param_2 + 0x138))(param_2,"transfer");
  if (lVar2 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0xe00002c2;
    plVar3 = (long *)thunk_EXT_FUN_8011000003890f30(lVar2,*(undefined8 *)PTR_DAT_fffffff007ca60a8);
    if ((plVar3 != (long *)0x0) &&
       ((uVar1 = (**(code **)(*plVar3 + 0xa8))(), uVar1 == 0 ||
        ((99 < uVar1 && (uVar1 <= (uint)((int)param_1[0x16e] * 100))))))) {
      uVar6 = 0;
      *(uint *)((long)param_1 + 0x1904) = uVar1;
      *(uint *)(param_1[0x69] + 0xe8) = uVar1;
    }
  }
  return uVar6;
}

