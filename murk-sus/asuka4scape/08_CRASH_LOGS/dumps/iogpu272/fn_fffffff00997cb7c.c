// FUN_fffffff00997cb7c @ fffffff00997cb7c size=1756

/* WARNING: Removing unreachable block (ram,0xfffffff00997d0f4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997ce68) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997cd8c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997cec4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997d164) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997cc9c) */

void FUN_fffffff00997cb7c(long param_1,int param_2,long *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  int local_184;
  long local_180;
  long local_178;
  long local_170 [33];
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff007ff2800;
  if (*(long *)(param_1 + 0x428) == 0) {
    uVar3 = thunk_EXT_FUN_80110000038961f4(1);
    *(undefined8 *)(param_1 + 0x428) = uVar3;
  }
  plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar5 = (long *)thunk_EXT_FUN_80110000038d02e4("SysMem");
  (**(code **)(*plVar4 + 0x100))(plVar4,"MemoryPool",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  uVar3 = (**(code **)(*param_3 + 0xb0))(param_3);
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar3,0x40);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"Size",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  local_170[0x1d] = 0;
  local_170[0x1c] = 0;
  local_170[0x1f] = 0;
  local_170[0x1e] = 0;
  local_170[0x19] = 0;
  local_170[0x18] = 0;
  local_170[0x1b] = 0;
  local_170[0x1a] = 0;
  local_170[0x15] = 0;
  local_170[0x14] = 0;
  local_170[0x17] = 0;
  local_170[0x16] = 0;
  local_170[0x11] = 0;
  local_170[0x10] = 0;
  local_170[0x13] = 0;
  local_170[0x12] = 0;
  local_170[0xf] = 0;
  local_170[0xe] = 0;
  local_170[0xb] = 0;
  local_170[10] = 0;
  local_170[0xd] = 0;
  local_170[0xc] = 0;
  local_170[7] = 0;
  local_170[6] = 0;
  local_170[9] = 0;
  local_170[8] = 0;
  local_170[3] = 0;
  local_170[2] = 0;
  local_170[5] = 0;
  local_170[4] = 0;
  local_170[1] = 0;
  local_170[0] = 0;
  thunk_EXT_FUN_80110000037693ec(local_170,0x100,"%s");
  plVar5 = (long *)thunk_EXT_FUN_80110000038d02e4(local_170);
  plVar6 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar6 + 0xe8))(plVar6,plVar5);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"Devices",plVar6);
  (**(code **)(*plVar6 + 0x28))(plVar6);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  local_178 = 0;
  local_170[0] = 0;
  local_180 = 0;
  iVar2 = thunk_EXT_FUN_8011000003977f9c(param_3,local_170,&local_178,&local_180);
  puVar1 = PTR_DAT_fffffff007ff2838;
  if ((iVar2 == 0) || (iVar2 == -0x1ffffd28)) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24
                               ((local_180 + local_178) * *(long *)PTR_DAT_fffffff007ff2838,0x40);
    (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"DirtySize",plVar5);
    plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(*(long *)puVar1 * local_170[0],0x40);
    (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"ResidentSize",plVar6);
    if (plVar6 != (long *)0x0) {
      (**(code **)(*plVar6 + 0x28))(plVar6);
    }
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  else {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: IOMemoryDescriptor::getPageCounts returned 0x%08x\n");
  }
  local_184 = 0;
  iVar2 = (**(code **)(*param_3 + 0x80))(param_3,1,&local_184);
  if (iVar2 == 0) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038970c4(local_184 - 3U < 2);
    (**(code **)(*plVar4 + 0x100))(plVar4,"Purgeable",plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar4 + 0x100))(plVar4,"Descriptions",plVar5);
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200("Metal Device Shmem");
  (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24((long)param_2,0x20);
  (**(code **)(*plVar6 + 0x100))(*plVar6 + 0x100,plVar6,"PID",plVar7);
  (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"Processes",plVar5);
  if (plVar7 != (long *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
  (**(code **)(*plVar5 + 0x28))(plVar5);
  (**(code **)(**(long **)(param_1 + 0x428) + 0xe8))(*(long **)(param_1 + 0x428),plVar4);
  (**(code **)(*plVar4 + 0x28))(plVar4);
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_68) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

