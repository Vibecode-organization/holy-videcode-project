// FUN_fffffff009941410 @ fffffff009941410 size=1172

/* WARNING: Removing unreachable block (ram,0xfffffff00994179c) */

void FUN_fffffff009941410(long *param_1,long *param_2)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  long local_170;
  long local_168;
  long local_160 [33];
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff007ff2800;
  (*DAT_fffffff007fe90d0)();
  lVar7 = param_1[0x10];
  lVar3 = 0;
  if ((long *)param_1[0x16] != (long *)0x0) {
    lVar3 = (**(code **)(*(long *)param_1[0x16] + 0xb0))();
  }
  lVar4 = 0;
  if ((long *)param_1[0x17] != (long *)0x0) {
    lVar4 = (**(code **)(*(long *)param_1[0x17] + 0xb0))();
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(lVar3 + lVar7 + lVar4,0x40);
  (**(code **)(*param_2 + 0x100))(param_2,"Size",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*param_2 + 0x100))(param_2,"Descriptions",plVar5);
  local_160[0x1d] = 0;
  local_160[0x1c] = 0;
  local_160[0x1f] = 0;
  local_160[0x1e] = 0;
  local_160[0x19] = 0;
  local_160[0x18] = 0;
  local_160[0x1b] = 0;
  local_160[0x1a] = 0;
  local_160[0x15] = 0;
  local_160[0x14] = 0;
  local_160[0x17] = 0;
  local_160[0x16] = 0;
  local_160[0x11] = 0;
  local_160[0x10] = 0;
  local_160[0x13] = 0;
  local_160[0x12] = 0;
  local_160[0xd] = 0;
  local_160[0xc] = 0;
  local_160[0xf] = 0;
  local_160[0xe] = 0;
  local_160[9] = 0;
  local_160[8] = 0;
  local_160[0xb] = 0;
  local_160[10] = 0;
  local_160[5] = 0;
  local_160[4] = 0;
  local_160[7] = 0;
  local_160[6] = 0;
  local_160[1] = 0;
  local_160[0] = 0;
  local_160[3] = 0;
  local_160[2] = 0;
  (**(code **)(*param_1 + 0x88))(param_1);
  thunk_EXT_FUN_80110000037693ec
            (local_160,0x100,"Aliased Virtual Resource (Virtual Size = %llu bytes)");
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200(local_160);
  (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  if (param_1[0x16] == 0) {
    lVar7 = 0;
    lVar3 = 0;
  }
  else {
    local_168 = 0;
    local_160[0] = 0;
    local_170 = 0;
    iVar2 = thunk_EXT_FUN_8011000003977f9c(param_1[0x16],local_160,&local_168,&local_170);
    if ((iVar2 == 0) || (iVar2 == -0x1ffffd28)) {
      lVar7 = local_170 + local_168;
      lVar3 = local_160[0];
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: IOMemoryDescriptor::getPageCounts returned 0x%08x for meta data\n");
      lVar7 = 0;
      lVar3 = 0;
    }
  }
  if (param_1[0x17] != 0) {
    local_168 = 0;
    local_160[0] = 0;
    local_170 = 0;
    iVar2 = thunk_EXT_FUN_8011000003977f9c(param_1[0x17],local_160,&local_168,&local_170);
    if ((iVar2 == 0) || (iVar2 == -0x1ffffd28)) {
      lVar3 = local_160[0] + lVar3;
      lVar7 = local_168 + lVar7 + local_170;
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: IOMemoryDescriptor::getPageCounts returned 0x%08x for residency data\n");
    }
  }
  puVar1 = PTR_DAT_fffffff007ff2838;
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(*(long *)PTR_DAT_fffffff007ff2838 * lVar3,0x40);
  (**(code **)(*param_2 + 0x100))(param_2,"ResidentSize",plVar5);
  plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(*(long *)puVar1 * lVar7,0x40);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"DirtySize",plVar6);
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  FUN_fffffff0099437e4(param_1);
  plVar5 = (long *)thunk_EXT_FUN_80110000038970c4();
  (**(code **)(*param_2 + 0x100))(param_2,"Wired",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_58) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

