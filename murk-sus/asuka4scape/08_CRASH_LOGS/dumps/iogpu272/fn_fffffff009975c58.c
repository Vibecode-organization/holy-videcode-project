// FUN_fffffff009975c58 @ fffffff009975c58 size=4

void FUN_fffffff009975c58(long param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  undefined8 uStack_48;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x2c0));
  *(uint *)(param_1 + 0x1e0) = *(uint *)(param_1 + 0x1e0) | 0x80;
  plVar2 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x1d8));
  if ((plVar2 != (long *)0x0) && (iVar1 = (**(code **)(*plVar2 + 0x90))(plVar2), iVar1 != 0)) {
    iVar4 = 0;
    do {
      lVar3 = (**(code **)(*plVar2 + 0x118))(plVar2,iVar4);
      if (lVar3 != 0) {
        thunk_EXT_FUN_8011000003246024(lVar3,0,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  FUN_fffffff009975e34(param_1);
  uStack_48 = 0;
  iVar1 = 0x1e;
  if (*(int *)(param_1 + 0x270) != 0) {
    iVar1 = *(int *)(param_1 + 0x270);
  }
  thunk_EXT_FUN_8011000003204ed8(iVar1,1000000000,&uStack_48);
  do {
    if (*(int *)(param_1 + 0xd8) == 0) goto LAB_fffffff009975da8;
    iVar1 = thunk_EXT_FUN_80110000038ff078(*(undefined8 *)(param_1 + 0x2c0),param_1,uStack_48,0);
  } while (iVar1 != 1);
  if (*(int *)(param_1 + 0x270) != 0) {
    thunk_EXT_FUN_8011000003a49114
              (
              "\"IOGPU::systemPagingOff() timeout. %d threads still stuck. addCommandToTail_slow %u, waitForAllSubmitted %u, workQueuesDisabled %u, waitingOnResources %u, waitForStamp %u, wireMemory %u\\n\" @%s:%d"
              );
    return;
  }
  thunk_EXT_FUN_801100000322ffdc
            (
            "IOGPU::systemPagingOff() timeout. %d threads still stuck. addCommandToTail_slow %u, waitForAllSubmitted %u, workQueuesDisabled %u, waitingOnResources %u, waitForStamp %u, wireMemory %u\n"
            );
LAB_fffffff009975da8:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x2c0));
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return;
}

