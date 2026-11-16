// FUN_fffffff00a21e488 @ fffffff00a21e488 size=696

ulong FUN_fffffff00a21e488
                (long param_1,uint param_2,long param_3,undefined8 param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  
  if ((param_2 & 0xffffc001) != 0) {
    return 4;
  }
  uVar7 = (uint)param_4;
  if (1 < param_3 + 1U) {
    if (4 < (uVar7 & 0x1fffffff) - 1) {
      return 4;
    }
    iVar3 = FUN_fffffff00a213330(param_1,param_3);
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
  uVar8 = uVar7 >> 0x1d & 1;
  if ((uVar7 & 0x1fffffff) == 4) {
    uVar8 = 1;
  }
  if ((-1 < (int)uVar7) && (uVar8 != 0)) {
    return 4;
  }
  uVar2 = tpidr_el1;
  lVar4 = FUN_fffffff00a29bafc(uVar2);
  if (((lVar4 != DAT_fffffff007c68058) && (lVar5 = FUN_fffffff00a29b0b4(lVar4), lVar5 != 0)) &&
     (uVar6 = (**(code **)(DAT_fffffff007c64e38 + 0x1c8))
                        (lVar5,"com.apple.private.set-exception-port"), (int)uVar6 == 0)) {
    return uVar6;
  }
  if (((lVar4 != DAT_fffffff007c68058) && (lVar4 = FUN_fffffff00a29b0b4(lVar4), lVar4 != 0)) &&
     (uVar6 = (**(code **)(DAT_fffffff007c64e38 + 0x1c8))(lVar4,"com.apple.security.cs.debugger"),
     (int)uVar6 == 0)) {
    return uVar6;
  }
  if (param_1 == 0) {
    uVar8 = 0;
LAB_fffffff00a21e6bc:
    if ((1 < param_3 + 1U) && (DAT_fffffff007bc7030 != param_3)) {
      if (param_1 != 0) {
        if ((uVar8 >> 1 & 1) == 0) {
          uVar8 = uVar8 >> 9 & 1;
        }
        else {
          uVar8 = uVar8 & 0x604;
        }
        if (uVar8 == 0) goto LAB_fffffff00a21e6c8;
      }
      if ((5 < (uVar7 & 0x1fffffff)) || ((1 << (ulong)(uVar7 & 0x1f) & 0x34U) == 0))
      goto joined_r0xfffffff00a21e724;
    }
LAB_fffffff00a21e6c8:
    uVar6 = 0;
  }
  else {
    uVar6 = *(ulong *)(*(long *)(param_1 + 0x310) + 0x58);
    iVar3 = FUN_fffffff00a9dee48(param_1,"com.apple.security.only-one-exception-port");
    if (iVar3 == 0) {
LAB_fffffff00a21e68c:
      uVar8 = (uint)*(undefined8 *)(*(long *)(param_1 + 0x310) + 0x58);
      goto LAB_fffffff00a21e6bc;
    }
    uVar8 = 1;
    if ((uVar6 & 4) == 0) {
      uVar8 = (uint)((uVar6 & 0x600) != 0);
    }
    uVar1 = (uint)uVar6 >> 9 & 1;
    if ((uVar6 & 2) != 0) {
      uVar1 = uVar8;
    }
    if ((uVar1 == 0) || (param_6 != 0)) goto LAB_fffffff00a21e68c;
joined_r0xfffffff00a21e724:
    if ((DAT_fffffff007bc3158 & 1) != 0) {
      FUN_fffffff00aa4ca7c(param_4,param_2,6);
    }
    uVar6 = (ulong)(-(DAT_fffffff007bc3158 & 1) & 0x35);
  }
  return uVar6;
}

