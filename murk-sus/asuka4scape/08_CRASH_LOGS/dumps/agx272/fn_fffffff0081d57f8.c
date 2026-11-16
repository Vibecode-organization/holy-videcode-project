// FUN_fffffff0081d57f8 @ fffffff0081d57f8 size=1280

/* WARNING: Removing unreachable block (ram,0xfffffff0081d59e8) */

void FUN_fffffff0081d57f8(long *param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  undefined8 uVar15;
  long *plVar16;
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  ulong unaff_x30;
  
  plVar12 = param_1 + 0x22ad;
  piVar1 = (int *)((long)param_1 + 0xdfbc);
  if (*piVar1 == 1) {
    uVar10 = (ulong)*(uint *)((*plVar12 - param_1[0x1c39]) + 0xd04000);
LAB_fffffff0081d5c94:
    uVar6 = *(uint *)((*plVar12 - param_1[0x1c39]) + 0xd04010);
LAB_fffffff0081d5cac:
    uVar7 = *(uint *)((*plVar12 - param_1[0x1c39]) + 0xd04014);
LAB_fffffff0081d5cc4:
    uVar8 = *(uint *)((*plVar12 - param_1[0x1c39]) + 0xd04018);
LAB_fffffff0081d5cdc:
    uVar9 = *(uint *)((*plVar12 - param_1[0x1c39]) + 0xd0401c);
  }
  else {
    uVar10 = FUN_fffffff0081f2fb8(param_1,0xd04000);
    if (*piVar1 == 1) goto LAB_fffffff0081d5c94;
    uVar6 = FUN_fffffff0081f2fb8(param_1,0xd04010);
    if (*piVar1 == 1) goto LAB_fffffff0081d5cac;
    uVar7 = FUN_fffffff0081f2fb8(param_1,0xd04014);
    if (*piVar1 == 1) goto LAB_fffffff0081d5cc4;
    uVar8 = FUN_fffffff0081f2fb8(param_1,0xd04018);
    if (*piVar1 == 1) goto LAB_fffffff0081d5cdc;
    uVar9 = FUN_fffffff0081f2fb8(param_1,0xd0401c);
  }
  uVar19 = (uint)uVar10;
  if (((uint)(uVar10 >> 0x18) & 0xff) == 5) {
    uVar4 = uVar19 >> 0x10 & 0xff;
    if (uVar4 == 0) {
      uVar17 = 5;
    }
    else {
      if (uVar4 != 2) goto LAB_fffffff0081d58f8;
      uVar17 = 6;
    }
    *(undefined4 *)(param_2 + 0x20) = uVar17;
  }
LAB_fffffff0081d58f8:
  if ((uVar10 & 0xf00) == 0 && (uVar19 >> 0xc & 0xf) == 0) {
    uVar17 = 1;
LAB_fffffff0081d5924:
    *(undefined4 *)(param_2 + 0x24) = uVar17;
  }
  else if (((uVar19 >> 0xc & 0xf) == 1) && ((uVar10 & 0xf00) == 0)) {
    uVar17 = 3;
    goto LAB_fffffff0081d5924;
  }
  *(uint *)(param_2 + 100) = uVar9 >> 0xc & 0xff;
  *(undefined4 *)(param_2 + 0x92) = 2;
  *(uint *)(param_2 + 0x7c) = uVar6 & 0xff;
  uVar19 = uVar6 >> 8 & 0xff;
  *(uint *)(param_2 + 0x30) = uVar6 & 0xff;
  *(uint *)(param_2 + 0x34) = uVar7 >> 8 & 0xff;
  *(uint *)(param_2 + 0x38) = uVar7 & 0xff;
  *(uint *)(param_2 + 0x3c) = uVar7 >> 0x10 & 0xff;
  *(uint *)(param_2 + 0x40) = uVar19 * (uVar6 >> 0x10 & 0xff);
  *(uint *)(param_2 + 0x44) = uVar19;
  iVar18 = (uVar9 & 0xf) * (uVar8 >> 0x10 & 0xf);
  iVar2 = (uVar9 >> 4 & 0xf) * (uVar8 >> 0x14 & 0xf);
  *(int *)(param_2 + 0x48) = iVar18;
  *(int *)(param_2 + 0x4c) = iVar2;
  iVar3 = (uVar9 >> 8 & 0xf) * (uVar8 >> 0x18 & 0xf);
  *(int *)(param_2 + 0x50) = iVar3;
  *(int *)(param_2 + 0x54) = iVar18;
  *(int *)(param_2 + 0x58) = iVar2;
  *(int *)(param_2 + 0x5c) = iVar3;
  iVar18 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
  uVar6 = -iVar18;
  uVar10 = (ulong)(uVar6 & 0xd01500);
  lVar11 = (**(code **)(*param_1 + 0x800))(*param_1 + 0x800,param_1,1);
  plVar12 = (long *)thunk_EXT_FUN_8011000003976f54
                              (lVar11 + uVar10,(iVar18 + 0xd014ffU & uVar6) - uVar10,1);
  plVar13 = (long *)(**(code **)(*plVar12 + 0xe8))(plVar12,0);
  lVar11 = (**(code **)(*plVar13 + 0x78))();
  *(undefined1 *)(param_2 + 0x8a) = 1;
  *(undefined1 *)(param_2 + 0x8c) = 0;
  *(undefined4 *)(param_2 + 0x74) = 1;
  *(ulong *)(param_2 + 0x10) = (ulong)*(uint *)((lVar11 - uVar10) + 0xd01500);
  *(undefined8 *)(param_2 + 0x18) = 0;
  iVar18 = *(int *)(param_2 + 0x20);
  if (iVar18 != 5) {
    if (iVar18 != 6) goto LAB_fffffff0081d5aa8;
    iVar18 = 10;
  }
  *(int *)(param_2 + 0x78) = iVar18;
LAB_fffffff0081d5aa8:
  (**(code **)(*plVar13 + 0x28))(plVar13);
  (**(code **)(*plVar12 + 0x28))(plVar12);
  lVar11 = thunk_EXT_FUN_80110000031cd550("/arm-io/gfx-asc");
  lVar14 = thunk_EXT_FUN_80110000031cd550("IODeviceTree:");
  lVar11 = lVar11 + lVar14;
  uVar15 = thunk_EXT_FUN_80110000038fe580(lVar11 + 1);
  thunk_EXT_FUN_80110000037693ec(uVar15,lVar11 + 1,"%s%s");
  plVar12 = (long *)thunk_EXT_FUN_8011000003906044(uVar15,0,0,0,0);
  if (plVar12 != (long *)0x0) {
    plVar13 = (long *)(**(code **)(*plVar12 + 0x148))(plVar12,"compatible");
    if (plVar13 != (long *)0x0) {
      plVar16 = (long *)thunk_EXT_FUN_8011000003890f30
                                  (plVar13,*(undefined8 *)PTR_DAT_fffffff007ca60b8);
      if (plVar16 == (long *)0x0) {
        plVar16 = (long *)thunk_EXT_FUN_8011000003890f30
                                    (plVar13,*(undefined8 *)PTR_DAT_fffffff007ca6090);
        if (plVar16 == (long *)0x0) {
          (**(code **)(*plVar13 + 0x38))(plVar13);
          thunk_EXT_FUN_8011000003891b28();
        }
        else {
          (**(code **)(*plVar16 + 0xd8))();
        }
      }
      else {
        (**(code **)(*plVar16 + 0xa8))();
      }
      (**(code **)(*plVar13 + 0x28))(plVar13);
    }
    (**(code **)(*plVar12 + 0x28))(plVar12);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_80110000038fe6b0(uVar15,lVar11 + 1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081d5c78);
  (*pcVar5)();
}

