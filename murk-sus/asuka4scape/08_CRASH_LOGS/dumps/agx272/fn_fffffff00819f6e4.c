// FUN_fffffff00819f6e4 @ fffffff00819f6e4 size=1248

/* WARNING: Removing unreachable block (ram,0xfffffff00819faf4) */

void FUN_fffffff00819f6e4(long param_1,long *param_2)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  undefined8 local_a0;
  undefined8 uStack_98;
  ulong local_90;
  undefined8 uStack_88;
  uint local_80;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  iVar1 = *(int *)((long)param_2 + 0x4c);
  thunk_EXT_FUN_80110000032222a8(param_2[0x2e]);
  if ((param_2[0x2d] == 0) || (iVar3 = thunk_EXT_FUN_801100000294991c(), iVar3 == 0)) {
    plVar6 = (long *)0x0;
  }
  else {
    plVar6 = (long *)param_2[0x2d];
  }
  thunk_EXT_FUN_8011000003222de0(param_2[0x2e]);
  thunk_EXT_FUN_8011000003890f30(plVar6[3],&DAT_fffffff00ae21f50);
  plVar7 = *(long **)(param_1 + 0x20);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = local_90 & 0xffffffffffff0000;
  thunk_EXT_FUN_80110000037693ec(&local_a0,0x12,"%p");
  puVar2 = PTR_DAT_fffffff007ca60a8;
  iVar3 = *(int *)(param_1 + 0xc);
  if (plVar7 != (long *)0x0) {
    uVar4 = (**(code **)(*plVar7 + 0x138))(plVar7,&local_a0);
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,*(undefined8 *)puVar2);
    if (plVar5 != (long *)0x0) {
      iVar3 = (**(code **)(*plVar5 + 0xa8))();
    }
  }
  if (iVar3 == *(int *)(param_1 + 0xc)) {
    *(int *)(param_1 + 0xc) = iVar3 + 1;
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar3,0x20);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x100))(plVar7,&local_a0,plVar5);
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  plVar7 = *(long **)(param_1 + 0x28);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = local_90 & 0xffffffffffff0000;
  thunk_EXT_FUN_80110000037693ec(&local_a0,0x12,"%p");
  iVar3 = *(int *)(param_1 + 0x10);
  if (plVar7 != (long *)0x0) {
    uVar4 = (**(code **)(*plVar7 + 0x138))(plVar7,&local_a0);
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,*(undefined8 *)puVar2);
    if (plVar5 != (long *)0x0) {
      iVar3 = (**(code **)(*plVar5 + 0xa8))();
    }
  }
  if (iVar3 == *(int *)(param_1 + 0x10)) {
    *(int *)(param_1 + 0x10) = iVar3 + 1;
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar3,0x20);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x100))(plVar7,&local_a0,plVar5);
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  plVar7 = *(long **)(param_1 + 0x30);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = local_90 & 0xffffffffffff0000;
  thunk_EXT_FUN_80110000037693ec(&local_a0,0x12,"%p");
  iVar3 = *(int *)(param_1 + 0x14);
  if (plVar7 != (long *)0x0) {
    uVar4 = (**(code **)(*plVar7 + 0x138))(plVar7,&local_a0);
    plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,*(undefined8 *)puVar2);
    if (plVar5 != (long *)0x0) {
      iVar3 = (**(code **)(*plVar5 + 0xa8))();
    }
  }
  if (iVar3 == *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar3,0x20);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x100))(plVar7,&local_a0,plVar5);
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  local_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  local_90 = 0;
  if (0 < iVar1) {
    thunk_EXT_FUN_8011000003722d80(iVar1,&local_a0,0x24);
    local_80 = local_80 & 0xffffff;
  }
  (**(code **)(*param_2 + 0x150))(param_2);
  (**(code **)(*param_2 + 0x128))(*param_2 + 0x128,param_2);
  FUN_fffffff00819f584
            (param_1,
             "[%2s %3d], %15s, cq=%3d, wq=%3d, wq_st=%llu, wq_sch=%1d, dm=%1d, st=%3u, pr=%1u, (rd=%u, up=%u, ba=%u, su=%u, wr=%u)\n"
            );
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_70) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

