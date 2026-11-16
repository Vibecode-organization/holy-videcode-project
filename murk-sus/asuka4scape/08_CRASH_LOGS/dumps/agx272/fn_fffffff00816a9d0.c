// FUN_fffffff00816a9d0 @ fffffff00816a9d0 size=216

ulong FUN_fffffff00816a9d0(long param_1,int param_2)

{
  long lVar1;
  uint uVar2;
  ulong *puVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  ulong local_10 [2];
  
  uVar2 = *(uint *)(param_1 + 0x42c);
  uVar4 = (ulong)uVar2;
  if ((*(byte *)(param_1 + 0x43a) & 1) != 0) {
    lVar1 = 0;
    if (*(long *)(param_1 + 0x3b8) == 0 && *(long *)(param_1 + 0x3b0) == 0) {
      lVar1 = 0x10;
    }
    uVar6 = uVar2 * param_2;
    puVar3 = (ulong *)(param_1 + 0x3b0 + lVar1);
    local_10[1] = puVar3[1];
    local_10[0] = *puVar3;
    uVar5 = uVar6 & 0x3f;
    if (uVar5 == 0) {
      if (uVar6 < 0x80) {
        uVar5 = (uint)local_10[uVar6 >> 6];
      }
      else {
        uVar5 = 0;
      }
    }
    else if (uVar6 < 0x80) {
      if (uVar6 < 0x40) {
        uVar5 = (uint)(local_10[1] << ((ulong)(0x40 - uVar5) & 0x3f)) |
                (uint)(local_10[uVar6 >> 6] >> uVar5);
      }
      else {
        uVar5 = (uint)(local_10[uVar6 >> 6] >> uVar5);
      }
    }
    else {
      uVar5 = (uint)(0L >> uVar5);
    }
    uVar6 = 0xffffffff;
    if (uVar2 < 0x40) {
      uVar6 = ~(uint)(-1L << (uVar4 & 0x3f));
    }
    uVar6 = uVar6 & uVar5;
    uVar4 = (ulong)(byte)(POPCOUNT((char)uVar6) + POPCOUNT((char)(uVar6 >> 8)) +
                          POPCOUNT((char)(uVar6 >> 0x10)) + POPCOUNT((char)(uVar6 >> 0x18)));
  }
  return uVar4;
}

