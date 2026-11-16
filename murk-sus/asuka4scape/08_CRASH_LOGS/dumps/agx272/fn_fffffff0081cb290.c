// FUN_fffffff0081cb290 @ fffffff0081cb290 size=376

bool FUN_fffffff0081cb290(long param_1,long param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  long *plVar2;
  int iVar3;
  bool bVar4;
  long *plVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  
  bVar4 = true;
  if (param_2 != 0) {
    lVar8 = (ulong)param_5 * 0x38 + 0x20;
    plVar2 = (long *)(param_1 + 0x1460 + (long)(int)lVar8);
    if (lVar8 != (int)lVar8) {
      plVar2 = (long *)(param_1 + 0x1460 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*plVar2 == 0) {
      uVar1 = param_3;
      if (param_4 != 0) {
        uVar1 = param_4;
      }
      iVar3 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
      uVar1 = (uVar1 + iVar3) - 1 & -iVar3;
      plVar5 = (long *)thunk_EXT_FUN_8011000003962c64(3,uVar1,(long)iVar3);
      if (plVar5 == (long *)0x0) {
        bVar4 = false;
      }
      else {
        plVar6 = (long *)(**(code **)(*plVar5 + 0xe8))(plVar5,0);
        *plVar2 = (long)plVar6;
        bVar4 = plVar6 != (long *)0x0;
        if (plVar6 != (long *)0x0) {
          uVar7 = (**(code **)(*plVar6 + 0x78))();
          thunk_EXT_FUN_8011000003a61b10(uVar7,param_2,(ulong)param_3);
          if (param_3 <= uVar1 && uVar1 - param_3 != 0) {
            lVar8 = (**(code **)(*(long *)*plVar2 + 0x78))();
            thunk_EXT_FUN_8011000003a61cc0(lVar8 + (ulong)param_3,uVar1 - param_3);
          }
        }
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
    }
  }
  return bVar4;
}

