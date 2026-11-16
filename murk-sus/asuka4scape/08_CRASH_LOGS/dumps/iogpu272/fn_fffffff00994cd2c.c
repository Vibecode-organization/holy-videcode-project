// FUN_fffffff00994cd2c @ fffffff00994cd2c size=740

ulong FUN_fffffff00994cd2c(long param_1,long param_2,long *param_3)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  long *plVar11;
  uint uVar12;
  ulong uVar13;
  long *plVar14;
  undefined8 local_68;
  
  uVar6 = *(uint *)(param_2 + 0x18);
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  if ((-1 < (int)uVar6) && ((int)uVar6 < *(int *)(param_1 + 0x28))) {
    lVar8 = (ulong)uVar6 * 0x18;
    plVar11 = (long *)(param_1 + 0x848 + (long)(int)lVar8);
    if (lVar8 - (int)lVar8 != 0) {
      plVar11 = (long *)(param_1 + 0x848 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*plVar11 == param_2) {
      *(undefined4 *)(plVar11 + 2) = 0xffffffff;
      thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
      return (ulong)uVar6;
    }
  }
  lVar8 = thunk_EXT_FUN_8011000003397c88();
  iVar5 = 0;
  uVar1 = param_1 + 0x848;
  uVar13 = 0xffffffff;
  do {
    uVar6 = *(uint *)(param_1 + 0x28);
    if (0 < (int)uVar6) {
      lVar9 = 0;
      uVar7 = 0;
      iVar10 = *(int *)(param_1 + 0x1448);
      do {
        plVar11 = (long *)(uVar1 + uVar7 * 0x18);
        if (((uVar1 ^ (ulong)plVar11) & 0xffc0000000000000) != 0) {
          plVar11 = (long *)((ulong)plVar11 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar12 = (uint)uVar7;
        if (*plVar11 == 0) goto joined_r0xfffffff00994ce54;
        iVar2 = (int)plVar11[2];
        iVar3 = iVar10;
        if ((iVar2 != -1) &&
           (*(int *)(param_1 + 0x40 + (uVar7 << 4 | 8)) -
            **(int **)(*(long *)(param_1 + 0x20) + uVar7 * 8) < 1)) {
          bVar4 = -1 < iVar2 - iVar10;
          if (bVar4) {
            uVar12 = (uint)uVar13;
          }
          uVar13 = (ulong)uVar12;
          iVar3 = iVar2;
          if (bVar4) {
            iVar3 = iVar10;
          }
        }
        iVar10 = iVar3;
        uVar7 = uVar7 + 1;
        lVar9 = lVar9 + 8;
      } while ((ulong)uVar6 * 8 - lVar9 != 0);
    }
    uVar12 = (uint)uVar13;
    uVar7 = uVar13;
joined_r0xfffffff00994ce54:
    uVar13 = uVar7;
    iVar10 = (int)uVar13;
    if ((-1 < (int)uVar12) && (iVar10 < (int)uVar6)) {
      bVar4 = iVar5 == 0;
      goto LAB_fffffff00994ce9c;
    }
    iVar5 = iVar5 + 1;
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
    thunk_EXT_FUN_80110000038fe968(100);
    thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  } while (iVar5 != 100);
  if (-1 < iVar10) {
    bVar4 = false;
    uVar6 = *(uint *)(param_1 + 0x28);
LAB_fffffff00994ce9c:
    if (iVar10 < (int)uVar6) {
      lVar9 = (uVar13 & 0xffffffff) * 0x18;
      plVar11 = (long *)(uVar1 + (long)(int)lVar9);
      if (lVar9 - (int)lVar9 != 0) {
        plVar11 = (long *)(uVar1 + lVar9 & 0xffffffffffff | 0x2bad000000000000);
      }
      *plVar11 = param_2;
      plVar14 = (long *)plVar11[1];
      if ((plVar14 != (long *)0x0) && (iVar5 = FUN_fffffff00994d91c(plVar14), iVar5 != 0)) {
        (**(code **)(*plVar14 + 0xd8))(plVar14,uVar13);
        (**(code **)(*plVar14 + 0x28))(plVar14);
      }
      plVar11[1] = (long)param_3;
      if (param_3 != (long *)0x0) {
        (**(code **)(*param_3 + 0xd0))(param_3,uVar13);
      }
      *(undefined4 *)(plVar11 + 2) = 0xffffffff;
    }
    if (bVar4) goto LAB_fffffff00994cfd0;
  }
  local_68 = 0;
  lVar9 = thunk_EXT_FUN_8011000003397c88();
  thunk_EXT_FUN_8011000003398228(lVar9 - lVar8,&local_68);
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "%s: sleeping %llu miliseconds %s find stamp index %d.\n");
LAB_fffffff00994cfd0:
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return uVar13;
}

