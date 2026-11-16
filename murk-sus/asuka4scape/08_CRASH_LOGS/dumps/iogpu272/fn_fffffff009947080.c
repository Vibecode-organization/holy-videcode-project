// FUN_fffffff009947080 @ fffffff009947080 size=664

void FUN_fffffff009947080(long *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff007ff2800;
  thunk_EXT_FUN_80110000032222a8(param_1[0x1e]);
  lVar6 = param_1[0x1b];
  param_2 = *(int *)(lVar6 + 0x10) + param_2;
  *(int *)(lVar6 + 0x10) = param_2;
  if (*(int *)(lVar6 + 0x14) < param_2) {
    if ((param_2 * -0x33333333 + 0x19999998U >> 1 | param_2 * -0x80000000) < 0x19999999) {
      uStack_58 = 0;
      local_60 = 0;
      uStack_48 = 0;
      uStack_50 = 0;
      thunk_EXT_FUN_8011000003722d80((int)param_1[0x1c],&local_60,0x20);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0,
                 "%s has reached a high water mark of %d gpu command queues.");
      lVar6 = param_1[0x1b];
      param_2 = *(int *)(lVar6 + 0x10);
    }
    *(int *)(lVar6 + 0x14) = param_2;
    plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24((long)param_2,0x20);
    (**(code **)(*param_1 + 200))(param_1,"CommandQueueCountMax",plVar4);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  uVar1 = *(uint *)(param_1[0x1b] + 0x10);
  lVar6 = param_1[0x24];
  lVar7 = *(long *)(lVar6 + 0x48);
  if (*(uint *)(lVar7 + 0x2ac) <= uVar1) {
    uVar2 = *(uint *)(lVar7 + 0x2b0);
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = uVar1 / uVar2;
    }
    if (uVar1 == uVar3 * uVar2 && DAT_fffffff00af227e8 != 0) {
      uVar8 = *(undefined8 *)(lVar6 + 0x38);
      lVar6 = param_1[0x1d];
      uVar5 = thunk_EXT_FUN_801100000390ebc0(param_1[0x1f]);
      thunk_EXT_FUN_80110000036da494
                (0x85d00000,uVar8,lVar6,uVar5,(long)*(int *)(param_1[0x1b] + 0x10),0);
      lVar6 = param_1[0x24];
      lVar7 = *(long *)(lVar6 + 0x48);
    }
  }
  uVar1 = *(uint *)(*(long *)(lVar6 + 0x88) + 0x30);
  uVar2 = *(uint *)(lVar7 + 0x2b4);
  if (uVar2 <= uVar1) {
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = uVar1 / uVar2;
    }
    if (uVar1 == uVar3 * uVar2 && DAT_fffffff00af227e8 != 0) {
      uVar8 = *(undefined8 *)(lVar6 + 0x38);
      lVar6 = param_1[0x1d];
      uVar5 = thunk_EXT_FUN_801100000390ebc0(param_1[0x1f]);
      thunk_EXT_FUN_80110000036da494(0x85d00004,uVar8,lVar6,uVar5,uVar1,0);
    }
  }
  plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24((long)*(int *)(param_1[0x1b] + 0x10),0x20);
  (**(code **)(*param_1 + 200))(param_1,"CommandQueueCount",plVar4);
  thunk_EXT_FUN_8011000003222de0(param_1[0x1e]);
  if (plVar4 != (long *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  if (*(long *)PTR_DAT_fffffff007ff2800 == local_38) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

