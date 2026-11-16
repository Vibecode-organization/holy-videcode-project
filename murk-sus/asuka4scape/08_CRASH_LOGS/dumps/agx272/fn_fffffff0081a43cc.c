// FUN_fffffff0081a43cc @ fffffff0081a43cc size=460

undefined8 FUN_fffffff0081a43cc(long *param_1,int param_2,int param_3)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong local_68;
  
  plVar1 = param_1 + 0x109;
  uVar2 = *(uint *)(param_1[0x50] + 0x23c);
  local_68 = (ulong)uVar2;
  lVar5 = thunk_EXT_FUN_8011000003397c88();
  thunk_EXT_FUN_8011000003398268((ulong)uVar2 * 1000000000,&local_68);
  lVar6 = thunk_EXT_FUN_8011000003397c88();
  iVar3 = (**(code **)(param_1[0x109] + 0x30))(plVar1);
  iVar4 = (**(code **)(param_1[0x109] + 0x38))(plVar1);
  if ((uint)(iVar3 - param_2) <= (uint)(param_3 - param_2) && iVar3 != iVar4) {
    do {
      if (local_68 <= (ulong)(lVar6 - lVar5)) {
        return 0xe00002bc;
      }
      if (*(int *)(*(long *)(param_1[0x50] + 0x160) + 0xe8) != 0) {
        return 0xe00002bc;
      }
      uVar7 = (**(code **)(*param_1 + 0x398))(param_1);
      if ((uVar7 & 1) != 0) {
        return 0xe00002bc;
      }
      lVar6 = param_1[0x50];
      if ((*(byte *)(lVar6 + 0x5a0) & 1) != 0) {
        return 0xe00002bc;
      }
      if ((*(byte *)(lVar6 + 0x111c0) & 1) != 0) {
        (**(code **)(**(long **)(lVar6 + 0x111b0) + 0xe0))(*(long **)(lVar6 + 0x111b0),0);
      }
      lVar6 = thunk_EXT_FUN_8011000003397c88();
      iVar3 = (**(code **)(*plVar1 + 0x30))(plVar1);
      iVar4 = (**(code **)(*plVar1 + 0x38))(plVar1);
    } while ((uint)(iVar3 - param_2) <= (uint)(param_3 - param_2) && iVar3 != iVar4);
  }
  return 0;
}

