// FUN_fffffff0099517f0 @ fffffff0099517f0 size=332

undefined8 FUN_fffffff0099517f0(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  FUN_fffffff009974fa8(param_1[4]);
  if (param_1[6] == 0) {
    lVar3 = (**(code **)(*param_1 + 0x98))(param_1);
    lVar4 = param_1[4];
    if (lVar3 + (ulong)*(uint *)(lVar4 + 0x1b0) < (ulong)*(uint *)(lVar4 + 0x1b4)) {
      uVar5 = FUN_fffffff00995193c(param_1);
      if ((uVar5 & 1) == 0) {
        lVar4 = param_1[4];
        goto LAB_fffffff0099518ac;
      }
LAB_fffffff0099518b8:
      if (param_1[6] != 0) goto LAB_fffffff00995181c;
    }
    else {
LAB_fffffff0099518ac:
      iVar1 = FUN_fffffff009974fc0(lVar4,param_1);
      if (iVar1 != 0) goto LAB_fffffff0099518b8;
      (**(code **)(*param_1 + 0x98))(param_1);
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: fail. request=%llu, current=%d, max=%d\n");
    }
    FUN_fffffff009974fb4(param_1[4]);
    uVar2 = 0;
  }
  else {
LAB_fffffff00995181c:
    iVar1 = *(int *)(param_1[4] + 0x1a8);
    *(int *)(param_1[4] + 0x1a8) = iVar1 + 1;
    *(int *)(param_1 + 7) = (int)param_1[7] + 1;
    *(int *)((long)param_1 + 0x3c) = iVar1;
    FUN_fffffff009974fb4();
    uVar2 = (**(code **)(*(long *)param_1[6] + 0x78))();
  }
  return uVar2;
}

