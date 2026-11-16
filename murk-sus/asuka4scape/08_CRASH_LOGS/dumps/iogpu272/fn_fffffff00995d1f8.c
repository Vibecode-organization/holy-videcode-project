// FUN_fffffff00995d1f8 @ fffffff00995d1f8 size=432

void FUN_fffffff00995d1f8(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  ulong local_50;
  undefined8 local_48;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  lVar4 = thunk_EXT_FUN_8011000003397c88();
  *(undefined1 *)(param_1 + 0x60) = 1;
  FUN_fffffff009975c34(*(undefined8 *)(param_1 + 0xc0),0x100);
  if (DAT_fffffff00af227e8 != 0) {
    uVar5 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x85180155,uVar5,*(undefined8 *)(param_1 + 200),0,0,0);
  }
  do {
    local_48 = 0;
    thunk_EXT_FUN_8011000003204ed8(100,1000000,&local_48);
    iVar3 = thunk_EXT_FUN_8011000003243438(param_1,0,local_48);
    if (*(int *)(param_1 + 0x48) == iVar1) {
      thunk_EXT_FUN_8011000003246024(param_1,0,0);
      break;
    }
    if (iVar3 == -1) {
      thunk_EXT_FUN_8011000003247bfc(0);
    }
    lVar6 = thunk_EXT_FUN_8011000003397c88();
    local_50 = 0;
    thunk_EXT_FUN_8011000003398228(lVar6 - lVar4,&local_50);
    uVar2 = *(uint *)(*(long *)(param_1 + 0xc0) + 0x26c);
    if ((uVar2 != 0) && ((ulong)uVar2 <= local_50 / 1000000000)) {
      thunk_EXT_FUN_8011000003a49114
                ("\"Excessive time stalled (>%ds) in IOGPUWorkQueue::waitForAllSubmitted()\" @%s:%d"
                );
      return;
    }
  } while (*(int *)(param_1 + 0x48) != iVar1);
  if (DAT_fffffff00af227e8 != 0) {
    uVar5 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x85180156,uVar5,*(undefined8 *)(param_1 + 200),0,0,0);
  }
  FUN_fffffff009975c44(*(undefined8 *)(param_1 + 0xc0),0x100);
  *(undefined1 *)(param_1 + 0x60) = 0;
  return;
}

