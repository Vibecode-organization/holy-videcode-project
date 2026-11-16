// FUN_fffffff009c2b8c8 @ fffffff009c2b8c8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009c2bb88) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bb00) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bacc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bb3c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2bbf8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c2b93c) */

undefined8 FUN_fffffff009c2b8c8(long param_1,long *param_2,long *param_3,undefined1 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  
  plVar8 = (long *)(param_1 + 0x40);
  if (param_3 == (long *)0x0) {
    *plVar8 = 0;
    plVar9 = (long *)0x0;
  }
  else {
    *plVar8 = (long)param_3;
    plVar9 = param_3;
    if (param_3 == (long *)0x0) {
      plVar9 = (long *)0x0;
    }
  }
  (**(code **)(*plVar9 + 0x20))();
  FUN_fffffff009c233d8(param_3);
  *(undefined4 *)(param_1 + 0x38) = 0;
  plVar9 = *(long **)(param_1 + 0x10);
  *(long **)(param_1 + 0x10) = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar9 != (long *)0x0) {
    (**(code **)(*plVar9 + 0x28))(plVar9);
  }
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined1 *)(param_1 + 0x70) = param_4;
  lVar7 = param_3[2];
  *(int *)(param_1 + 0x38) = (int)lVar7;
  uVar3 = FUN_fffffff009c41c14
                    (*(undefined8 *)(param_1 + 0x10),(int)lVar7,param_1 + 0x58,param_1 + 0x60);
  if ((uVar3 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"%s: map_surface_client_shared() failed\n"
              );
    uVar4 = 0;
  }
  else {
    uVar6 = *(uint *)(param_3 + 0x13);
    uVar3 = (ulong)uVar6;
    if (uVar6 != 0) {
      if (uVar6 < 4) {
        lVar7 = param_1 + 0x78;
        *(long *)(param_1 + 0x68) = lVar7;
      }
      else {
        lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bfc0,uVar3 << 3);
        *(long *)(param_1 + 0x68) = lVar7;
        if (lVar7 == 0) {
          return 0;
        }
        uVar3 = (ulong)*(uint *)(param_3 + 0x13);
      }
      thunk_EXT_FUN_8011000003a61cc0(lVar7,uVar3 << 3);
    }
    lVar7 = *plVar8;
    if (*(long **)(lVar7 + 0x30) == (long *)0x0) {
      uVar6 = 1;
    }
    else {
      iVar2 = (**(code **)(**(long **)(lVar7 + 0x30) + 0xa8))();
      uVar6 = 0x1001;
      if (iVar2 != 2) {
        uVar6 = 1;
      }
      lVar7 = *plVar8;
    }
    uVar1 = *(uint *)(lVar7 + 0x9c);
    uVar4 = FUN_fffffff009c41bd8(*(undefined8 *)(param_1 + 0x10));
    lVar7 = *(long *)(param_1 + 0x40);
    if (lVar7 == 0) {
      lVar7 = 0;
    }
    lVar7 = FUN_fffffff009c20364(lVar7);
    if (lVar7 == 0) {
      uVar5 = 1;
      if ((*(uint *)(*plVar8 + 0x3d0) & 0x400000) == 0) {
        uVar5 = *(uint *)(*plVar8 + 0x3d0) >> 0x18 & 1;
      }
    }
    else {
      uVar5 = 1;
    }
    iVar2 = FUN_fffffff009c2bc3c(param_1,uVar4,uVar6 | uVar1,uVar5);
    if (iVar2 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff00806ca48,0x11,"%s: mapInTask() failed\n");
      uVar4 = 0;
    }
    else {
      lVar7 = *plVar8;
      if (lVar7 == 0) {
        lVar7 = 0;
      }
      FUN_fffffff009c2a738(lVar7);
      *(undefined8 *)(param_1 + 0x28) = 0;
      lVar7 = *(long *)(param_1 + 0x40);
      plVar8 = *(long **)(lVar7 + 0x2f8);
      *(long **)(param_1 + 0x30) = plVar8;
      *plVar8 = param_1;
      *(undefined8 **)(lVar7 + 0x2f8) = (undefined8 *)(param_1 + 0x28);
      FUN_fffffff009c2a744();
      uVar4 = 1;
    }
  }
  return uVar4;
}

