// FUN_fffffff008200704 @ fffffff008200704 size=376

ulong FUN_fffffff008200704(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  *(undefined8 *)(param_1 + 0xd8) = 0;
  lVar2 = thunk_EXT_FUN_80110000038ff010();
  *(long *)(param_1 + 0x198) = lVar2;
  uVar3 = 0;
  if (lVar2 != 0) {
    lVar2 = thunk_EXT_FUN_80110000038ff010();
    *(long *)(param_1 + 0x1b0) = lVar2;
    uVar3 = 0;
    if (lVar2 != 0) {
      *(undefined8 *)(param_1 + 0x150) = 0;
      *(undefined8 *)(param_1 + 0x148) = 0;
      *(undefined8 *)(param_1 + 0x160) = 0;
      *(undefined8 *)(param_1 + 0x158) = 0;
      *(undefined8 *)(param_1 + 0x130) = 0;
      *(undefined8 *)(param_1 + 0x128) = 0;
      *(undefined8 *)(param_1 + 0x140) = 0;
      *(undefined8 *)(param_1 + 0x138) = 0;
      lVar2 = thunk_EXT_FUN_80110000038ff010();
      *(long *)(param_1 + 0x168) = lVar2;
      uVar3 = 0;
      if (lVar2 != 0) {
        *(undefined1 *)(param_1 + 0x170) = 0;
        *(undefined8 *)(param_1 + 0x210) = 0;
        *(undefined8 *)(param_1 + 0xd8) = param_4;
        uVar3 = (**(code **)(PTR_DAT_fffffff007ca60d0 + 0x90))(param_1,param_2,param_3);
        if ((int)uVar3 != 0) {
          *(undefined4 *)(param_1 + 0x180) = 0;
          uVar1 = *(uint *)(*(long *)(param_1 + 0x48) + 0x618);
          *(uint *)(param_1 + 0x184) = uVar1;
          *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(*(long *)(param_1 + 0x48) + 0x61c);
          if (uVar1 != 0) {
            lVar2 = thunk_EXT_FUN_80110000038fe580((ulong)uVar1 << 6);
            *(long *)(param_1 + 400) = lVar2;
            if (lVar2 == 0) {
              return 0;
            }
            if (*(int *)(param_1 + 0x184) != 0) {
              uVar3 = 0;
              do {
                uVar4 = *(ulong *)(param_1 + 400) + uVar3 * 0x40;
                if (((*(ulong *)(param_1 + 400) ^ uVar4) & 0xffc0000000000000) != 0) {
                  uVar4 = uVar4 & 0xffffffffffff | 0xc8a2000000000000;
                }
                thunk_EXT_FUN_8011000002946f14(uVar4);
                uVar3 = uVar3 + 1;
              } while (uVar3 < *(uint *)(param_1 + 0x184));
            }
          }
          *(undefined8 *)(param_1 + 0x178) = 0;
          *(undefined4 *)(param_1 + 0x1f8) = 0;
          *(undefined8 *)(param_1 + 0x200) = 0;
          *(undefined4 *)(param_1 + 0x208) = 0;
          *(undefined1 *)(param_1 + 0x120) = 2;
          *(undefined4 *)(param_1 + 0x1b8) = 0;
          lVar2 = thunk_EXT_FUN_80110000038ff010();
          *(long *)(param_1 + 0x1c0) = lVar2;
          uVar3 = 0;
          if (lVar2 != 0) {
            *(undefined1 *)(param_1 + 0x1bc) = 0;
            *(undefined1 *)(param_1 + 0x1c8) = 0;
            *(undefined8 *)(param_1 + 0x1f0) = 0;
            if ((((*(byte *)(param_1 + 0x40) >> 1 & 1) == 0) ||
                ((*(byte *)(*(long *)(param_1 + 0x48) + 0x10a9d) & 1) == 0)) ||
               (uVar3 = FUN_fffffff0081feeec(*(undefined8 *)(param_1 + 0x58)), (int)uVar3 != 0)) {
              *(undefined8 *)(param_1 + 0x1d8) = 0;
              *(undefined8 *)(param_1 + 0x1e0) = 0;
              lVar2 = thunk_EXT_FUN_80110000038ff010();
              *(long *)(param_1 + 0x1e8) = lVar2;
              uVar3 = (ulong)(lVar2 != 0);
            }
          }
        }
      }
    }
  }
  return uVar3;
}

