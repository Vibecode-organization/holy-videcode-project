// FUN_fffffff009961a4c @ fffffff009961a4c size=200

void FUN_fffffff009961a4c(long param_1,int param_2,undefined4 param_3,undefined8 param_4)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  uint uVar4;
  undefined8 *puVar5;
  
  *(int *)(param_1 + 0x90) = param_2;
  thunk_EXT_FUN_8011000003398268(param_2 * 1000000,param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = param_3;
  thunk_EXT_FUN_8011000003205048(param_1 + 0x78);
  if (*(int *)(param_1 + 0x74) != 0) {
    uVar1 = 1;
    do {
      uVar2 = uVar1;
      uVar4 = (uint)uVar2;
      uVar1 = (ulong)(uVar4 << 1);
    } while (uVar4 < *(int *)(param_1 + 0x74) + 1U);
    *(uint *)(param_1 + 0x68) = uVar4;
    uVar1 = thunk_EXT_FUN_80110000038fe580(uVar2 << 4);
    *(ulong *)(param_1 + 0x60) = uVar1;
    if (uVar1 != 0) {
      uVar2 = (ulong)*(uint *)(param_1 + 0x68);
      if (*(uint *)(param_1 + 0x68) != 0) {
        lVar3 = 0;
        do {
          puVar5 = (undefined8 *)(uVar1 + lVar3 * 0x10);
          if (((uVar1 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
            puVar5 = (undefined8 *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
          }
          *puVar5 = 0;
          *(undefined4 *)(puVar5 + 1) = 0;
          lVar3 = lVar3 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
  }
  *(undefined8 *)(param_1 + 0xa8) = param_4;
  return;
}

