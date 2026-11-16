// FUN_fffffff0081a4318 @ fffffff0081a4318 size=180

void FUN_fffffff0081a4318(long param_1,uint *param_2,ulong param_3)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  if (*(uint *)(param_1 + 0x28) < 5 && *(uint *)(param_1 + 0x28) != 2) {
    if (7 < param_3) {
      lVar3 = *(long *)(*(long *)(param_1 + 0x20) + 0x230);
      uVar2 = *(uint *)(lVar3 + 0x68);
      if ((ulong)(uVar2 + 1) * 8 + 8 <= param_3) {
        lVar5 = (ulong)uVar2 * 8;
        iVar4 = (int)lVar5;
        puVar1 = (ulong *)((long)param_2 + (long)iVar4 + 8);
        if (lVar5 - iVar4 != 0) {
          puVar1 = (ulong *)((ulong)(param_2 + (ulong)uVar2 * 2 + 2) & 0xffffffffffff |
                            0x2bad000000000000);
        }
        *puVar1 = *(ulong *)(*(long *)(param_1 + 0x20) + 0x228) & 0x1ffffffffffffff |
                  0xe00000000000000;
        *param_2 = uVar2 + 1;
        *(int *)(lVar3 + 0x68) = *(int *)(lVar3 + 0x68) + 1;
      }
    }
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! ChannelError of unknown type! (%d)\n");
  return;
}

