// FUN_fffffff00996d358 @ fffffff00996d358 size=316

int FUN_fffffff00996d358(long param_1,long param_2,long *param_3,long *param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = (*DAT_fffffff007feb260)();
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = iVar2;
  }
  if (iVar1 == 1) {
    FUN_fffffff00994af14(param_1 + 0x80);
    FUN_fffffff00994af14(param_1 + 0xc0);
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(long *)(param_1 + 0x10) = param_2;
    *(undefined8 *)(param_1 + 0x11c) = 0x2000000020;
    *(undefined8 *)(param_1 + 0x130) = 0;
    *(undefined8 **)(param_1 + 0x40) = (undefined8 *)(param_1 + 0x38);
    uVar3 = thunk_EXT_FUN_80110000038905f0(1,&DAT_fffffff00af220c0);
    *(undefined8 *)(param_1 + 0x100) = uVar3;
    if (param_3 != (long *)0x0) {
      (**(code **)(*param_3 + 0x20))(param_3);
      *(long **)(param_1 + 0x60) = param_3;
      *(int *)(param_1 + 0x78) = (int)param_3[0xa8];
      *(long *)(param_1 + 0x108) = param_3[0x82];
      FUN_fffffff00997a424(param_3,param_1);
      *(ulong *)(param_1 + 0x128) = param_3[0xa9] + 1U & (param_3[0xa9] ^ 0xffffffffffffffffU);
    }
    if ((*(byte *)(*(long *)(param_1 + 0x10) + 0x239) >> 1 & 1) == 0) {
      *(undefined8 *)(param_1 + 0x128) = 0xf;
    }
    if (param_4 != (long *)0x0) {
      (**(code **)(*param_4 + 0x20))(param_4);
      *(long **)(param_1 + 0x58) = param_4;
    }
  }
  return iVar1;
}

