// FUN_fffffff008167cb4 @ fffffff008167cb4 size=4

void FUN_fffffff008167cb4(long param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  float fVar5;
  
  uVar2 = (ulong)*(uint *)(param_1 + 0x19440);
  if (0xffffffffffffffef < uVar2 - 0x11) {
    if (*(int *)(param_1 + 0x414) != 0) {
      uVar4 = 0;
      uVar3 = 1;
      do {
        if ((int)uVar3 != 0) {
          uVar2 = 0;
          uVar1 = *(uint *)(param_1 + 0x19448 + uVar4 * 4);
          do {
            uVar3 = param_1 + 0x19488U + uVar4 * 0x40;
            if (((param_1 + 0x19488U ^ uVar3) & 0xffc0000000000000) != 0) {
              uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
            }
            fVar5 = (float)NEON_ucvtf(*(undefined4 *)(uVar3 + uVar2 * 4));
            fVar5 = (float)thunk_EXT_FUN_8011000001149590(fVar5 / 1000.0,0x40000000);
            uVar3 = param_1 + 0x1a760U + uVar4 * 0x40;
            if (((param_1 + 0x1a760U ^ uVar3) & 0xffc0000000000000) != 0) {
              uVar3 = uVar3 & 0xffffffffffff | 0xc8a2000000000000;
            }
            *(int *)(uVar3 + uVar2 * 4) = (int)(fVar5 * (float)((ulong)uVar1 / 1000000));
            uVar2 = uVar2 + 1;
            uVar3 = (ulong)*(uint *)(param_1 + 0x414);
          } while (uVar2 < uVar3);
          uVar2 = (ulong)*(uint *)(param_1 + 0x19440);
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    return;
  }
  thunk_EXT_FUN_8011000003a49114
            ("AGXk: %s:%d:%s: !!! Verification failed: %s: max pState greater than num supported.\n"
            );
  return;
}

