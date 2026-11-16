// FUN_fffffff00995c904 @ fffffff00995c904 size=676

undefined8 FUN_fffffff00995c904(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  
  uVar12 = *(uint *)(param_1 + 0x48);
  uVar5 = *(uint *)(param_1 + 0x4c);
  *(undefined8 *)(param_1 + 0xd0) = 0;
  if (uVar12 == uVar5) {
    return 1;
  }
  bVar4 = false;
  plVar9 = (long *)0x0;
  do {
    uVar2 = *(uint *)(param_1 + 0x54);
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = uVar12 / uVar2;
    }
    uVar13 = (ulong)(uVar12 - uVar3 * uVar2);
    lVar8 = uVar13 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar8);
    if (lVar8 != (int)lVar8) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x58) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    plVar10 = (long *)*puVar1;
    if (plVar10 != (long *)0x0) {
      uVar6 = FUN_fffffff00994b4ec
                        (*(undefined8 *)(*(long *)(param_1 + 0xc0) + 0x148),plVar10 + 0x10);
      if ((uVar6 & 1) == 0) {
        if (!bVar4) {
          return 0;
        }
        FUN_fffffff00994c49c
                  (*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x1b0),plVar10 + 0x10,param_1 + 0x80)
        ;
        uVar7 = 0;
        goto LAB_fffffff00995cb04;
      }
      if ((plVar9 == (long *)0x0) && (plVar9 = (long *)plVar10[0xc], plVar9 != (long *)0x0)) {
        (**(code **)(*plVar9 + 0x20))(plVar9);
      }
      if (DAT_fffffff00af227e8 == 0) {
        lVar11 = 0;
        lVar8 = 0;
      }
      else {
        uVar7 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
        lVar8 = plVar10[0x20];
        lVar11 = plVar10[0x21];
        thunk_EXT_FUN_80110000036da494
                  (0x85180165,uVar7,*(undefined8 *)(param_1 + 200),lVar11,lVar8,0);
      }
      (**(code **)(*plVar10 + 0x98))(plVar10);
      *(long *)(param_1 + 0xd0) = *(long *)(param_1 + 0xd0) + plVar10[0x27];
      (**(code **)(*plVar10 + 0x28))(plVar10);
      if (DAT_fffffff00af227e8 != 0) {
        uVar7 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
        thunk_EXT_FUN_80110000036da494
                  (0x85180166,uVar7,*(undefined8 *)(param_1 + 200),lVar11,lVar8,0);
      }
      lVar8 = uVar13 * 8;
      puVar1 = (undefined8 *)(*(long *)(param_1 + 0x58) + (long)(int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        puVar1 = (undefined8 *)
                 (*(long *)(param_1 + 0x58) + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = 0;
      bVar4 = true;
    }
    uVar12 = uVar12 + 1;
    *(uint *)(param_1 + 0x48) = uVar12;
    if (uVar12 == uVar5) {
      DataMemoryBarrier(2,3);
      uVar5 = *(uint *)(param_1 + 0x4c);
    }
  } while (uVar12 != uVar5);
  uVar7 = 1;
  if (!bVar4) {
    return 1;
  }
LAB_fffffff00995cb04:
  uVar6 = *(ulong *)(param_1 + 0x78);
  uVar13 = thunk_EXT_FUN_8011000003397c88();
  *(ulong *)(param_1 + 0x78) = uVar13;
  lVar8 = uVar13 - uVar6;
  if (uVar13 < uVar6 || lVar8 == 0) {
    if (plVar9 == (long *)0x0) goto LAB_fffffff00995cb64;
  }
  else {
    FUN_fffffff009961688(*(undefined8 *)(param_1 + 0x10),uVar13,lVar8,param_1);
    if (plVar9 == (long *)0x0) goto LAB_fffffff00995cb64;
    FUN_fffffff00997a2a4(plVar9,lVar8);
  }
  (**(code **)(*plVar9 + 0x28))(plVar9);
LAB_fffffff00995cb64:
  if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
    thunk_EXT_FUN_8011000003246024(param_1,0,0);
  }
  return uVar7;
}

