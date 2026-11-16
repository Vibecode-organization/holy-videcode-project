// FUN_fffffff00a21e488 @ fffffff00a21e488 size=696
// CALLERS:
//   fffffff00afb8626 no-fn
//   fffffff00a216574 FUN_fffffff00a216520@fffffff00a216520
//   fffffff00a216c64 FUN_fffffff00a216c04@fffffff00a216c04
//   fffffff00a21ed20 FUN_fffffff00a21ecd8@fffffff00a21ecd8
//   fffffff00a21ee00 FUN_fffffff00a21ed70@fffffff00a21ed70
//   fffffff00a21f1ec FUN_fffffff00a21f13c@fffffff00a21f13c
//   fffffff00a21f688 FUN_fffffff00a21f5e8@fffffff00a21f5e8
//   fffffff00a220554 FUN_fffffff00a2204c0@fffffff00a2204c0
// CALLEES:
//   fffffff00a29bafc FUN_fffffff00a29bafc
//   fffffff00a213330 FUN_fffffff00a213330
//   fffffff00a9dee48 FUN_fffffff00a9dee48
//   fffffff00a29b0b4 FUN_fffffff00a29b0b4
//   fffffff00aa4ca7c FUN_fffffff00aa4ca7c

ulong FUN_fffffff00a21e488
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
                ulong param_8,undefined1 (*param_9) [16],ulong param_10,uint param_11,int param_12)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  uint uVar7;
  
  if ((param_8 & 0xffffc001) != 0) {
    return 4;
  }
  uVar7 = (uint)param_10;
  if ((undefined1 *)0x1 < *param_9 + 1) {
    if (4 < (uVar7 & 0x1fffffff) - 1) {
      return 4;
    }
    uVar3 = FUN_fffffff00a213330(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
    if (uVar3 == 0) {
      return 0x11;
    }
  }
  if (0x1b < param_11) {
    return 4;
  }
  if ((1 << (ulong)(param_11 & 0x1f) & 0xa03c6ffU) == 0) {
    return 4;
  }
  uVar3 = uVar7 >> 0x1d & 1;
  if ((uVar7 & 0x1fffffff) == 4) {
    uVar3 = 1;
  }
  if ((-1 < (int)uVar7) && (uVar3 != 0)) {
    return 4;
  }
  lVar4 = tpidr_el1;
  lVar4 = FUN_fffffff00a29bafc(lVar4);
  if (((lVar4 != DAT_fffffff007c68058) && (uVar5 = FUN_fffffff00a29b0b4(lVar4), uVar5 != 0)) &&
     (uVar6 = (**(code **)(DAT_fffffff007c64e38 + 0x1c8))
                        (uVar5,"com.apple.private.set-exception-port"), (int)uVar6 == 0)) {
    return uVar6;
  }
  if (((lVar4 != DAT_fffffff007c68058) && (uVar5 = FUN_fffffff00a29b0b4(lVar4), uVar5 != 0)) &&
     (uVar6 = (**(code **)(DAT_fffffff007c64e38 + 0x1c8))(uVar5,"com.apple.security.cs.debugger"),
     (int)uVar6 == 0)) {
    return uVar6;
  }
  if (param_7 == 0) {
    uVar3 = 0;
LAB_fffffff00a21e6bc:
    if (((undefined1 *)0x1 < *param_9 + 1) && (DAT_fffffff007bc7030 != param_9)) {
      if (param_7 != 0) {
        if ((uVar3 >> 1 & 1) == 0) {
          uVar3 = uVar3 >> 9 & 1;
        }
        else {
          uVar3 = uVar3 & 0x604;
        }
        if (uVar3 == 0) goto LAB_fffffff00a21e6c8;
      }
      if ((5 < (uVar7 & 0x1fffffff)) || ((1 << (ulong)(uVar7 & 0x1f) & 0x34U) == 0))
      goto joined_r0xfffffff00a21e724;
    }
LAB_fffffff00a21e6c8:
    uVar5 = 0;
  }
  else {
    uVar5 = *(ulong *)(*(long *)(param_7 + 0x310) + 0x58);
    bVar2 = FUN_fffffff00a9dee48(param_7,-0xff8fb9b59);
    if (!bVar2) {
LAB_fffffff00a21e68c:
      uVar3 = (uint)*(undefined8 *)(*(long *)(param_7 + 0x310) + 0x58);
      goto LAB_fffffff00a21e6bc;
    }
    uVar3 = 1;
    if ((uVar5 & 4) == 0) {
      uVar3 = (uint)((uVar5 & 0x600) != 0);
    }
    uVar1 = (uint)uVar5 >> 9 & 1;
    if ((uVar5 & 2) != 0) {
      uVar1 = uVar3;
    }
    if ((uVar1 == 0) || (param_12 != 0)) goto LAB_fffffff00a21e68c;
joined_r0xfffffff00a21e724:
    if ((DAT_fffffff007bc3158 & 1) != 0) {
      FUN_fffffff00aa4ca7c(param_10,param_8 & 0xffffffff,6);
    }
    uVar5 = (ulong)(-(DAT_fffffff007bc3158 & 1) & 0x35);
  }
  return uVar5;
}

