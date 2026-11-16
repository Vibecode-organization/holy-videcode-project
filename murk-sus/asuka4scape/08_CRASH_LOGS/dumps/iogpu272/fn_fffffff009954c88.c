// FUN_fffffff009954c88 @ fffffff009954c88 size=344

uint FUN_fffffff009954c88(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  
  if ((*(uint *)(param_1 + 0x10) & 0xf) == 3) {
    uVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      if (*(long *)(param_1 + 0x30) == 0) {
        uVar8 = 0;
      }
      else {
        iVar2 = thunk_EXT_FUN_8011000002c269f8(*(undefined8 *)(*(long *)(param_1 + 0x30) + 0x10));
        uVar8 = 3;
        if (iVar2 != 0) {
          uVar8 = 1;
        }
      }
    }
    else {
      uVar1 = *(uint *)(param_2 + 0x14);
      uVar3 = uVar1 >> 0xc & 0x80 | *(uint *)(*(long *)(param_1 + 0x50) + 0x1f0) >> 0x14 & 4 |
              uVar1 >> 4 & 3;
      if ((uVar1 >> 0xc & 1) == 0) {
        uVar7 = *(uint *)(param_1 + 0x10) & 0xff;
      }
      else {
        FUN_fffffff00994af14(*(undefined8 *)(param_1 + 0x58));
        FUN_fffffff00994af14(*(long *)(param_1 + 0x58) + 0x40);
        uVar1 = *(uint *)(param_2 + 0x14);
        uVar7 = (uint)*(byte *)(param_1 + 0x10);
      }
      uVar8 = uVar3 | 3;
      if ((uVar1 & 0x30) != 0) {
        uVar8 = uVar3;
      }
      if (uVar7 == 0x82) {
        uVar3 = (**(code **)(**(long **)(param_1 + 0x30) + 0x90))(*(long **)(param_1 + 0x30),0,0);
        uVar8 = uVar3 & 0x13 | uVar8 & 0xfc;
      }
    }
    uVar3 = uVar8;
    if (((*(byte *)(param_1 + 0x10) & 0xf) == 0) &&
       (lVar4 = thunk_EXT_FUN_8011000003890f30(*(undefined8 *)(param_1 + 0x28),DAT_fffffff007fefaf0)
       , lVar4 != 0)) {
      plVar5 = (long *)FUN_fffffff009981d00();
      uVar6 = (**(code **)(*plVar5 + 0xa8))();
      uVar3 = uVar8 & 0xfffffffd;
      if ((uVar6 & 1) != 0) {
        uVar3 = uVar8;
      }
    }
  }
  return uVar3;
}

