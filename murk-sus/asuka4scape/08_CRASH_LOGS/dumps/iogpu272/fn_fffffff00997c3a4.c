// FUN_fffffff00997c3a4 @ fffffff00997c3a4 size=2008

/* WARNING: Removing unreachable block (ram,0xfffffff00997c96c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c680) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c5a4) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c6dc) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997ca1c) */
/* WARNING: Removing unreachable block (ram,0xfffffff00997c4bc) */

void FUN_fffffff00997c3a4
               (long param_1,long *param_2,long param_3,undefined4 param_4,long param_5,
               ulong param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  int local_194;
  long local_190;
  long local_188;
  long local_180 [33];
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ff2800;
  if (*(long *)(param_1 + 0x420) == 0) {
    uVar3 = thunk_EXT_FUN_80110000038961f4(1);
    *(undefined8 *)(param_1 + 0x420) = uVar3;
  }
  plVar4 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  plVar5 = (long *)thunk_EXT_FUN_80110000038d02e4("SysMem");
  (**(code **)(*plVar4 + 0x100))(plVar4,"MemoryPool",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  uVar3 = thunk_EXT_FUN_8011000003977d8c(param_2,0);
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar3,0x40);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"Size",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  local_180[0x1d] = 0;
  local_180[0x1c] = 0;
  local_180[0x1f] = 0;
  local_180[0x1e] = 0;
  local_180[0x19] = 0;
  local_180[0x18] = 0;
  local_180[0x1b] = 0;
  local_180[0x1a] = 0;
  local_180[0x15] = 0;
  local_180[0x14] = 0;
  local_180[0x17] = 0;
  local_180[0x16] = 0;
  local_180[0x11] = 0;
  local_180[0x10] = 0;
  local_180[0x13] = 0;
  local_180[0x12] = 0;
  local_180[0xf] = 0;
  local_180[0xe] = 0;
  local_180[0xb] = 0;
  local_180[10] = 0;
  local_180[0xd] = 0;
  local_180[0xc] = 0;
  local_180[7] = 0;
  local_180[6] = 0;
  local_180[9] = 0;
  local_180[8] = 0;
  local_180[3] = 0;
  local_180[2] = 0;
  local_180[5] = 0;
  local_180[4] = 0;
  local_180[1] = 0;
  local_180[0] = 0;
  thunk_EXT_FUN_80110000037693ec(local_180,0x100,"%s");
  plVar5 = (long *)thunk_EXT_FUN_80110000038d02e4(local_180);
  plVar6 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar6 + 0xe8))(plVar6,plVar5);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"Devices",plVar6);
  (**(code **)(*plVar6 + 0x28))(plVar6);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  local_188 = 0;
  local_180[0] = 0;
  local_190 = 0;
  iVar2 = thunk_EXT_FUN_8011000003977f9c(param_2,local_180,&local_188,&local_190);
  puVar1 = PTR_DAT_fffffff007ff2838;
  if ((iVar2 == 0) || (iVar2 == -0x1ffffd28)) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24
                               ((local_190 + local_188) * *(long *)PTR_DAT_fffffff007ff2838,0x40);
    (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"DirtySize",plVar5);
    plVar6 = (long *)thunk_EXT_FUN_80110000038c6e24(*(long *)puVar1 * local_180[0],0x40);
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
  local_194 = 0;
  iVar2 = (**(code **)(*param_2 + 0x80))(param_2,1,&local_194);
  if (iVar2 == 0) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038970c4(local_194 - 3U < 2);
    (**(code **)(*plVar4 + 0x100))(plVar4,"Purgeable",plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038c6e24(param_4,0x20);
  (**(code **)(*plVar4 + 0x100))(plVar4,"IOSurfaceID",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar4 + 0x100))(plVar4,"Descriptions",plVar5);
  plVar6 = (long *)thunk_EXT_FUN_80110000038ce200("IOSurface Backing Store");
  (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
  if (param_3 != 0) {
    (**(code **)(*plVar5 + 0xe8))(plVar5,param_3);
  }
  if (plVar6 != (long *)0x0) {
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  plVar5 = (long *)thunk_EXT_FUN_80110000038970c4(0);
  (**(code **)(*plVar4 + 0x100))(*plVar4 + 0x100,plVar4,"CachedCopy",plVar5);
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if ((int)param_6 != 0) {
    plVar5 = (long *)thunk_EXT_FUN_80110000038961f4(param_6);
    if (0 < (int)param_6) {
      lVar8 = 0;
      param_6 = param_6 & 0xffffffff;
      do {
        plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
        plVar7 = (long *)thunk_EXT_FUN_80110000038c6e24((long)*(int *)(param_5 + lVar8 * 4),0x20);
        (**(code **)(*plVar6 + 0x100))(*plVar6 + 0x100,plVar6,"PID",plVar7);
        (**(code **)(*plVar5 + 0xe8))(plVar5,plVar6);
        if (plVar7 != (long *)0x0) {
          (**(code **)(*plVar7 + 0x28))(plVar7);
        }
        (**(code **)(*plVar6 + 0x28))(plVar6);
        lVar8 = lVar8 + 1;
        param_6 = param_6 - 1;
      } while (param_6 != 0);
    }
    (**(code **)(*plVar4 + 0x100))(plVar4,"Processes",plVar5);
    if (plVar5 != (long *)0x0) {
      (**(code **)(*plVar5 + 0x28))(plVar5);
    }
  }
  (**(code **)(**(long **)(param_1 + 0x420) + 0xe8))(*(long **)(param_1 + 0x420),plVar4);
  (**(code **)(*plVar4 + 0x28))(plVar4);
  if (*(long *)PTR_DAT_fffffff007ff2800 != local_78) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

