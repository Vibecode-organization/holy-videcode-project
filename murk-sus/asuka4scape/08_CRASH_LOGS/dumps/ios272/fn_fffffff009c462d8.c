// FUN_fffffff009c462d8 @ fffffff009c462d8 size=1976

/* WARNING: Removing unreachable block (ram,0xfffffff009c46598) */

undefined8 FUN_fffffff009c462d8(long param_1,uint param_2,ulong param_3,long *param_4,uint param_5)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  long *plVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  undefined8 uVar16;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  if (9 < param_2) {
    uVar16 = 0;
    goto LAB_fffffff009c46a20;
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x40));
  lVar1 = param_1 + 0x48;
  lVar13 = (ulong)param_2 * 8;
  puVar4 = (undefined8 *)(lVar1 + (int)lVar13);
  if (lVar13 != (int)lVar13) {
    puVar4 = (undefined8 *)(lVar1 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
  }
  plVar8 = (long *)thunk_EXT_FUN_8011000003898a6c(*puVar4);
  if (plVar8 == (long *)0x0) {
    plVar15 = (long *)0x0;
    bVar5 = true;
    uVar16 = 0;
  }
  else {
    uVar2 = (uint)param_3 & 0xf00;
    plVar11 = (long *)0x0;
    plVar14 = (long *)0x0;
    while( true ) {
      plVar15 = plVar14;
      uVar16 = (**(code **)(*plVar8 + 0x88))(plVar8);
      plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(uVar16,&DAT_fffffff00af48458);
      if (plVar9 != (long *)0x0) {
        (**(code **)(*plVar9 + 0x20))(plVar9);
      }
      if (plVar11 != (long *)0x0) {
        (**(code **)(*plVar11 + 0x28))(plVar11);
      }
      if (plVar9 == (long *)0x0) goto LAB_fffffff009c46504;
      uVar3 = *(uint *)((long)plVar9 + 0xc) & 0xf00;
      if (uVar3 == uVar2) break;
      plVar11 = plVar9;
      plVar14 = plVar15;
      if (((*(byte *)(param_1 + 0xa1) & 1) != 0) &&
         (((plVar15 == (long *)0x0 ||
           ((uVar3 != 0x700 && ((*(uint *)((long)plVar15 + 0xc) & 0xf00) == 0x700)))) &&
          ((**(code **)(*plVar9 + 0x20))(plVar9), plVar14 = plVar9, plVar15 != (long *)0x0)))) {
        (**(code **)(*plVar15 + 0x28))(plVar15);
      }
    }
    (**(code **)(*plVar9 + 0x20))(plVar9);
    if (plVar15 != (long *)0x0) {
      (**(code **)(*plVar15 + 0x28))(plVar15);
    }
    (**(code **)(*plVar9 + 0x28))(plVar9);
    plVar15 = plVar9;
LAB_fffffff009c46504:
    param_3 = param_3 & 0xffffffff;
    (**(code **)(*plVar8 + 0x28))(plVar8);
    if (plVar15 == (long *)0x0) {
      uVar16 = 0;
    }
    else {
      lVar13 = (ulong)param_2 * 8;
      puVar4 = (undefined8 *)(lVar1 + (int)lVar13);
      if (lVar13 - (int)lVar13 != 0) {
        puVar4 = (undefined8 *)(lVar1 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
      }
      plVar8 = (long *)*puVar4;
      uVar16 = (**(code **)(*plVar8 + 0x128))(plVar8,plVar15,0);
      (**(code **)(*plVar8 + 0x108))(*plVar8 + 0x108,plVar8,uVar16);
      if ((uVar2 == 0x700) && ((*(uint *)((long)plVar15 + 0xc) & 0xf00) != 0x700)) {
        (**(code **)(*plVar15 + 0x28))(plVar15);
        plVar15 = (long *)0x0;
        uVar16 = 0;
        bVar5 = false;
        param_5 = 1;
        goto LAB_fffffff009c46610;
      }
      (**(code **)(*param_4 + 0xe8))(param_4,plVar15);
      uVar16 = 1;
    }
    bVar5 = true;
  }
LAB_fffffff009c46610:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x40));
  if (((param_2 != 0) && ((int)uVar16 == 0)) && (bVar5)) {
    plVar8 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    iVar7 = param_2 - 1;
    if (plVar8 == (long *)0x0) {
      uVar10 = FUN_fffffff009c462d8(param_1,iVar7,param_3,0,0);
      if ((uVar10 & 1) != 0) goto LAB_fffffff009c466b4;
LAB_fffffff009c467cc:
      plVar11 = (long *)thunk_EXT_FUN_8011000003898a6c(plVar8);
      if (plVar11 != (long *)0x0) {
        plVar14 = (long *)0x0;
        while( true ) {
          uVar12 = (**(code **)(*plVar11 + 0x88))(plVar11);
          plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(uVar12,&DAT_fffffff00af48458);
          if (plVar9 != (long *)0x0) {
            (**(code **)(*plVar9 + 0x20))(plVar9);
          }
          if (plVar14 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          if (plVar9 == (long *)0x0) break;
          (**(code **)(*plVar9 + 0x20))(plVar9);
          FUN_fffffff009c42884(param_1,plVar9);
          plVar14 = plVar9;
        }
        (**(code **)(*plVar11 + 0x28))(plVar11);
        param_3 = param_3 & 0xffffffff;
      }
    }
    else {
      (**(code **)(*plVar8 + 0x20))(plVar8);
      iVar6 = FUN_fffffff009c462d8(param_1,iVar7,param_3,plVar8,0);
      if (iVar6 == 0) goto LAB_fffffff009c467cc;
      (**(code **)(*plVar8 + 0x20))(plVar8);
LAB_fffffff009c466b4:
      iVar7 = FUN_fffffff009c462d8(param_1,iVar7,param_3,plVar8,0);
      if (iVar7 == 0) goto LAB_fffffff009c467cc;
      plVar11 = (long *)thunk_EXT_FUN_8011000003898a6c(plVar8);
      if (plVar11 == (long *)0x0) {
        uVar16 = 1;
      }
      else {
        plVar14 = (long *)0x0;
        while( true ) {
          uVar16 = (**(code **)(*plVar11 + 0x88))(plVar11);
          plVar9 = (long *)thunk_EXT_FUN_8011000003890f30(uVar16,&DAT_fffffff00af48458);
          if (plVar9 != (long *)0x0) {
            (**(code **)(*plVar9 + 0x20))(plVar9);
          }
          if (plVar14 != (long *)0x0) {
            (**(code **)(*plVar14 + 0x28))(plVar14);
          }
          if (plVar9 == (long *)0x0) break;
          local_70 = plVar9;
          (**(code **)(*plVar9 + 0x20))(plVar9);
          thunk_EXT_FUN_80110000038963f0(param_4,&local_70);
          plVar14 = plVar9;
          if (local_70 != (long *)0x0) {
            (**(code **)(*local_70 + 0x28))();
          }
        }
        (**(code **)(*plVar11 + 0x28))(plVar11);
        uVar16 = 1;
      }
    }
    if (plVar8 != (long *)0x0) {
      (**(code **)(*plVar8 + 0x28))(plVar8);
    }
  }
  if ((param_5 & ((uint)uVar16 ^ 1)) == 1) {
    plVar8 = (long *)(**(code **)(DAT_fffffff00af48458 + 0x68))();
    if (plVar15 != (long *)0x0) {
      (**(code **)(*plVar15 + 0x28))(plVar15);
    }
    if (plVar8 == (long *)0x0) goto LAB_fffffff009c46a20;
    iVar7 = FUN_fffffff009c43270
                      (plVar8,param_3,
                       (long)((1 << (ulong)(*(uint *)PTR_DAT_fffffff00806c9b0 & 0x1f)) <<
                             (ulong)(param_2 & 0x1f)));
    if (iVar7 != 0) {
      (**(code **)(*param_4 + 0xe8))(param_4,plVar8);
      uVar16 = 1;
    }
  }
  else {
    plVar8 = plVar15;
    if (plVar15 == (long *)0x0) goto LAB_fffffff009c46a20;
  }
  (**(code **)(*plVar8 + 0x28))(plVar8);
LAB_fffffff009c46a20:
  if (param_4 != (long *)0x0) {
    (**(code **)(*param_4 + 0x28))(param_4);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar16;
  }
  uVar16 = thunk_EXT_FUN_8011000003a48590();
  return uVar16;
}

