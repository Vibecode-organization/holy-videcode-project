// FUN_fffffff009c46b38 @ fffffff009c46b38 size=740

ulong FUN_fffffff009c46b38(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  bool bVar2;
  long *plVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  ulong uVar12;
  long local_78;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x40));
  lVar6 = 0;
  uVar12 = 0;
  do {
    plVar3 = (long *)thunk_EXT_FUN_8011000003898a6c(*(undefined8 *)(param_1 + 0x48 + lVar6 * 8));
    if (plVar3 != (long *)0x0) {
      plVar11 = (long *)0x0;
      while( true ) {
        uVar4 = (**(code **)(*plVar3 + 0x88))(plVar3);
        plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,&DAT_fffffff00af48458);
        if (plVar5 != (long *)0x0) {
          (**(code **)(*plVar5 + 0x20))(plVar5);
        }
        if (plVar11 != (long *)0x0) {
          (**(code **)(*plVar11 + 0x28))(plVar11);
        }
        if (plVar5 == (long *)0x0) break;
        plVar11 = plVar5;
        if (((*(uint *)((long)plVar5 + 0xc) ^ (uint)param_2) & 0xf00) == 0) {
          uVar12 = uVar12 + (long)((1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)) <<
                                  (ulong)((uint)lVar6 & 0x1f));
        }
      }
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    lVar6 = lVar6 + 1;
  } while (lVar6 != 10);
  if (uVar12 < param_3) {
    local_78 = 9;
    do {
      uVar7 = param_3 - uVar12 >> (local_78 != 0);
      uVar9 = 1;
      iVar1 = (1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)) <<
              (ulong)((uint)local_78 & 0x1f);
      if ((ulong)(long)iVar1 < uVar7) {
        uVar10 = (ulong)iVar1;
        do {
          plVar3 = (long *)(**(code **)(DAT_fffffff00af48458 + 0x68))(&DAT_fffffff00af48458);
          if (plVar3 == (long *)0x0) {
            uVar9 = 0;
            goto LAB_fffffff009c46dd0;
          }
          uVar9 = FUN_fffffff009c43270(plVar3,param_2,uVar10);
          if ((uVar9 & 1) != 0) {
            uVar4 = *(undefined8 *)(param_1 + 0x48 + local_78 * 8);
            local_70 = plVar3;
            (**(code **)(*plVar3 + 0x20))(plVar3);
            thunk_EXT_FUN_80110000038963f0(uVar4,&local_70);
            if (local_70 != (long *)0x0) {
              (**(code **)(*local_70 + 0x28))();
            }
            uVar7 = uVar7 - uVar10;
            uVar12 = uVar12 + uVar10;
          }
          (**(code **)(*plVar3 + 0x28))(plVar3);
          uVar8 = 0;
          if (uVar10 < uVar7) {
            uVar8 = (uint)uVar9;
          }
        } while ((uVar8 & 1) != 0);
      }
      bVar2 = local_78 != 0;
      local_78 = local_78 + -1;
    } while (((bVar2) && ((int)uVar9 != 0)) && (uVar12 < param_3));
  }
  else {
    uVar9 = 1;
  }
LAB_fffffff009c46dd0:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x40));
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_68) {
    uVar12 = thunk_EXT_FUN_8011000003a48590();
    return uVar12;
  }
  return uVar9;
}

