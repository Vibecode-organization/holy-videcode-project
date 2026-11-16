// FUN_fffffff00a1e21f4 @ fffffff00a1e21f4 size=676

ulong FUN_fffffff00a1e21f4
                (long param_1,uint param_2,long param_3,undefined8 param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  uint uVar7;
  
  if ((param_2 & 0xffffc001) != 0) {
    return 4;
  }
  uVar6 = (uint)param_4;
  if (1 < param_3 + 1U) {
    if (4 < (uVar6 & 0x1fffffff) - 1) {
      return 4;
    }
    iVar3 = FUN_fffffff00a1d7060(param_1,param_3);
    if (iVar3 == 0) {
      return 0x11;
    }
  }
  if (0x1b < param_5) {
    return 4;
  }
  if ((1 << (ulong)(param_5 & 0x1f) & 0xa03c6ffU) == 0) {
    return 4;
  }
  uVar7 = uVar6 >> 0x1d & 1;
  if ((uVar6 & 0x1fffffff) == 4) {
    uVar7 = 1;
  }
  if ((-1 < (int)uVar6) && (uVar7 != 0)) {
    return 4;
  }
  uVar2 = tpidr_el1;
  lVar4 = FUN_fffffff00a25f6f4(uVar2);
  if (((lVar4 != DAT_fffffff007c5bf10) && (lVar4 = FUN_fffffff00a25ecac(), lVar4 != 0)) &&
     (uVar5 = (**(code **)(DAT_fffffff007c58cf0 + 0x1c8))
                        (lVar4,"com.apple.private.set-exception-port"), (int)uVar5 == 0)) {
    return uVar5;
  }
  if (param_1 == 0) {
    uVar7 = 0;
LAB_fffffff00a1e23bc:
    if ((1 < param_3 + 1U) && (DAT_fffffff007bbb030 != param_3)) {
      if (param_1 != 0) {
        if ((uVar7 >> 1 & 1) == 0) {
          uVar7 = uVar7 >> 9 & 1;
        }
        else {
          uVar7 = uVar7 & 0x604;
        }
        if (uVar7 == 0) goto LAB_fffffff00a1e23c8;
      }
      if ((5 < (uVar6 & 0x1fffffff)) || ((1 << (ulong)(uVar6 & 0x1f) & 0x34U) == 0))
      goto LAB_fffffff00a1e2460;
    }
LAB_fffffff00a1e23c8:
    uVar5 = 0;
  }
  else {
    uVar5 = *(ulong *)(*(long *)(param_1 + 0x310) + 0x58);
    if (((param_1 == DAT_fffffff007c5bf10) || (lVar4 = FUN_fffffff00a25ecac(param_1), lVar4 == 0))
       || (iVar3 = (**(code **)(DAT_fffffff007c58cf0 + 0x1c8))
                             (lVar4,"com.apple.security.only-one-exception-port"), iVar3 != 0)) {
LAB_fffffff00a1e2338:
      uVar7 = (uint)*(undefined8 *)(*(long *)(param_1 + 0x310) + 0x58);
      goto LAB_fffffff00a1e23bc;
    }
    uVar7 = 1;
    if ((uVar5 & 4) == 0) {
      uVar7 = (uint)((uVar5 & 0x600) != 0);
    }
    uVar1 = (uint)uVar5 >> 9 & 1;
    if ((uVar5 & 2) != 0) {
      uVar1 = uVar7;
    }
    if ((uVar1 == 0) || (param_6 != 0)) goto LAB_fffffff00a1e2338;
LAB_fffffff00a1e2460:
    if ((DAT_fffffff007bb7158 & 1) != 0) {
      FUN_fffffff00aa0be60(param_4,param_2,6);
    }
    uVar5 = (ulong)(-(DAT_fffffff007bb7158 & 1) & 0x35);
  }
  return uVar5;
}

