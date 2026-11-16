// FUN_fffffff0081ddb24 @ fffffff0081ddb24 size=396

ulong FUN_fffffff0081ddb24(float param_1,long *param_2,long param_3)

{
  uint *puVar1;
  ulong uVar2;
  uint uVar3;
  long lVar4;
  ulong local_98;
  ulong uStack_90;
  ulong local_88;
  
  if (param_3 != 0) {
    lVar4 = 0;
    do {
      uVar3 = *(uint *)((long)param_2 + lVar4 * 4 + 0x19448);
      if (*(uint *)(param_2 + lVar4 * 8 + 0x3291) == 0 || uVar3 == 0) {
        uVar3 = 0xffff;
      }
      else {
        uVar3 = (uint)((param_1 * 1e+06) /
                      (((float)uVar3 / 1e+06) * (float)*(uint *)(param_2 + lVar4 * 8 + 0x3291) *
                      0.003));
      }
      puVar1 = (uint *)(param_3 + 4 + lVar4 * 4);
      *puVar1 = uVar3 | (uint)*(ushort *)((long)puVar1 + 2) << 0x10;
      local_98 = 0;
      uStack_90 = 0;
      local_88 = 0;
      uVar2 = (**(code **)(*param_2 + 0xa98))(param_2,&local_98,(uint)lVar4 & 0xffff,(ulong)uVar3);
      if ((uVar2 & 1) == 0) {
        uVar2 = thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Verification failed: %s\n");
        return uVar2;
      }
      *(ulong *)(param_3 + 0x38c + (local_88 & 0xffff) * 8) =
           (ulong)uVar3 << (uStack_90 & 0x3f) |
           *(ulong *)(param_3 + 0x38c + (local_88 & 0xffff) * 8) & local_98;
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x10);
  }
  return (ulong)(param_3 != 0);
}

