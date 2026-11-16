// FUN_fffffff00a1d92c8 @ fffffff00a1d92c8 size=420

undefined8 FUN_fffffff00a1d92c8(long param_1,ulong param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  int in_wzr;
  
  if (param_1 == 0) {
    return 4;
  }
  iVar3 = (int)param_2;
  if (iVar3 - 0x25U < 0xffffffe3) {
    return 4;
  }
  lVar2 = tpidr_el1;
  lVar5 = FUN_fffffff00a25f6f4(lVar2);
  lVar6 = lVar5;
  if ((lVar5 == DAT_fffffff007c5bf10) ||
     (lVar6 = FUN_fffffff00a25ecac(), lVar6 == DAT_fffffff00ad557a8)) {
    iVar4 = FUN_fffffff00a9fa1ec(lVar6,param_2,param_3);
    if (iVar4 != 0) {
      return 8;
    }
    if (iVar3 == 0x1a) {
      return 0x2e;
    }
  }
  else if (((iVar3 != 0x14) ||
           (uVar7 = FUN_fffffff00a99e918(lVar5,"com.apple.private.xpc.launchd.event-monitor"),
           (int)uVar7 == 0)) || (iVar3 = FUN_fffffff00a9fa1ec(uVar7,0x14,param_3), iVar3 != 0)) {
    return 8;
  }
  if (*(ulong *)(param_1 + 8) == 0) {
    *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar2 + 0x4e8);
  }
  else {
    FUN_fffffff00a1ea02c(param_1,lVar2,0);
  }
  plVar1 = (long *)(param_1 + 0x10 + (param_2 & 0xffffffff) * 8);
  lVar6 = *plVar1;
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  if (param_3 == 0) {
    param_3 = 0;
  }
  *plVar1 = param_3;
  if (*(int *)(param_1 + 8) == *(int *)(lVar2 + 0x4e8)) {
    *(int *)(param_1 + 8) = in_wzr;
  }
  else {
    FUN_fffffff00a1eab60(param_1,lVar2);
  }
  if (1 < lVar6 + 1U) {
    FUN_fffffff00a1b894c(lVar6);
  }
  return 0;
}

