// FUN_fffffff00995d3a8 @ fffffff00995d3a8 size=580

void FUN_fffffff00995d3a8(long param_1,long *param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  ulong local_60;
  undefined8 local_58;
  
  iVar1 = *(int *)(param_1 + 0x50);
  lVar5 = thunk_EXT_FUN_8011000003397c88();
  *(undefined1 *)(param_1 + 0x60) = 1;
  FUN_fffffff009975c34(*(undefined8 *)(param_1 + 0xc0),1);
  if (DAT_fffffff00af227e8 != 0) {
    uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x85180155,uVar6,*(undefined8 *)(param_1 + 200),0,0,0);
  }
  do {
    local_58 = 0;
    thunk_EXT_FUN_8011000003204ed8(100,1000000,&local_58);
    iVar4 = thunk_EXT_FUN_8011000003243438(param_1,0,local_58);
    bVar3 = iVar1 - *(int *)(param_1 + 0x48) == *(int *)(param_1 + 0x54);
    if ((!bVar3) || (*(char *)(*(long *)(param_1 + 0xc0) + 0x1e0) < '\0')) {
      thunk_EXT_FUN_8011000003246024(param_1,0,0);
      goto LAB_fffffff00995d524;
    }
    if (iVar4 == -1) {
      thunk_EXT_FUN_8011000003247bfc(0);
    }
    lVar7 = thunk_EXT_FUN_8011000003397c88();
    local_60 = 0;
    thunk_EXT_FUN_8011000003398228(lVar7 - lVar5,&local_60);
    uVar2 = *(uint *)(*(long *)(param_1 + 0xc0) + 0x26c);
    if (((uVar2 != 0) && ((ulong)uVar2 <= local_60 / 1000000000)) &&
       (iVar1 - *(int *)(param_1 + 0x48) == *(int *)(param_1 + 0x54))) {
      thunk_EXT_FUN_8011000003a49114
                (
                "\"Excessive time stalled (>%ds) in IOGPUWorkQueue::addCommandToTail_slow()\" @%s:%d"
                );
      return;
    }
  } while (iVar1 - *(int *)(param_1 + 0x48) == *(int *)(param_1 + 0x54));
  bVar3 = false;
LAB_fffffff00995d524:
  if (DAT_fffffff00af227e8 != 0) {
    uVar6 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0xc0));
    thunk_EXT_FUN_80110000036da494(0x85180156,uVar6,*(undefined8 *)(param_1 + 200),0,0,0);
  }
  FUN_fffffff009975c44(*(undefined8 *)(param_1 + 0xc0),1);
  *(undefined1 *)(param_1 + 0x60) = 0;
  if (bVar3) {
    if ((*(byte *)((long)param_2 + 0x4c) & 1) == 0) {
      (**(code **)(*param_2 + 0x88))(param_2);
    }
    if (param_2[0xd] != 0) {
      *(undefined4 *)(param_2[0xd] + 200) = 0x13;
    }
  }
  else {
    FUN_fffffff00995d5ec(param_1,param_2);
  }
  return;
}

