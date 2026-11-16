// FUN_fffffff0081f7b1c @ fffffff0081f7b1c size=332

undefined8 FUN_fffffff0081f7b1c(long param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar2 = (**(code **)(PTR_DAT_fffffff007ca6180 + 0x78))();
  if ((int)uVar2 != 0) {
    *(undefined8 *)(param_1 + 0x120) = param_2;
    *(long **)(param_1 + 0x128) = param_3;
    (**(code **)(*param_3 + 0x20))(param_3);
    uVar1 = *(uint *)(*(long *)(param_1 + 0x120) + 0x11140);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(*(long *)(param_1 + 0x120) + 0x610);
    }
    *(uint *)(param_1 + 0x280) = uVar1;
    *(undefined8 *)(param_1 + 0x284) = 0;
    *(ulong *)(param_1 + 0x278) = (ulong)uVar1 * 0x58;
    uVar3 = thunk_EXT_FUN_80110000038fe580();
    *(undefined8 *)(param_1 + 0x290) = uVar3;
    if (*(int *)(param_1 + 0x280) != 0) {
      uVar5 = 0;
      do {
        uVar4 = *(ulong *)(param_1 + 0x290) + uVar5 * 0x58;
        if (((*(ulong *)(param_1 + 0x290) ^ uVar4) & 0xffc0000000000000) != 0) {
          uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
        }
        thunk_EXT_FUN_8011000002946f14(uVar4 + 0x18);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_1 + 0x280));
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x260) = 0;
    *(undefined8 *)(param_1 + 0x148) = 0;
    *(undefined8 *)(param_1 + 0x140) = 0;
    *(undefined8 *)(param_1 + 0x158) = 0;
    *(undefined8 *)(param_1 + 0x150) = 0;
    *(undefined8 *)(param_1 + 0x188) = 0;
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined8 *)(param_1 + 0x198) = 0;
    *(undefined8 *)(param_1 + 400) = 0;
    *(undefined8 *)(param_1 + 0x168) = 0;
    *(undefined8 *)(param_1 + 0x160) = 0;
    *(undefined8 *)(param_1 + 0x178) = 0;
    *(undefined8 *)(param_1 + 0x170) = 0;
    *(undefined8 *)(param_1 + 0x1a8) = 0;
    *(undefined8 *)(param_1 + 0x1a0) = 0;
    *(undefined8 *)(param_1 + 0x1b8) = 0;
    *(undefined8 *)(param_1 + 0x1b0) = 0;
    *(bool *)(param_1 + 0x2c0) = *(int *)(*(long *)(param_1 + 0x120) + 0x10954) != 0;
    *(undefined8 *)(param_1 + 0x130) = 0;
    *(undefined8 *)(param_1 + 0x138) = param_4;
    *(undefined8 *)(param_1 + 0x1c8) = 0;
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined8 *)(param_1 + 600) = param_4;
  }
  return uVar2;
}

