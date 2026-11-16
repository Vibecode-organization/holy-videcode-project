// FUN_fffffff00997f744 @ fffffff00997f744 size=364

ulong FUN_fffffff00997f744(long *param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_4 == (long *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*param_4 + 0xb0))(param_4);
  }
  if (DAT_fffffff00af227e8 != 0) {
    uVar1 = *(uint *)(param_1[3] + 0x30);
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1[3] + 0x10));
    thunk_EXT_FUN_80110000036da494
              (0x851801a5,uVar2,uVar1 >> 5 & 1,uVar3,*(undefined4 *)(param_1[4] + 0x20),0);
  }
  uVar4 = (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3,param_4);
  if ((uVar4 & 1) == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: updateGPUPageTable failed\n");
  }
  if (DAT_fffffff00af227e8 != 0) {
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1[3] + 0x10));
    thunk_EXT_FUN_80110000036da494
              (0x851801a6,uVar2,uVar4 & 0xffffffff,uVar3,*(undefined4 *)(param_1[4] + 0x20),0);
  }
  return uVar4;
}

