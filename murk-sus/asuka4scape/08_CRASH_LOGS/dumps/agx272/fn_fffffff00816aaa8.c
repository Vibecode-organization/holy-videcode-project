// FUN_fffffff00816aaa8 @ fffffff00816aaa8 size=68

int FUN_fffffff00816aaa8(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x3b0);
  lVar2 = *(long *)(param_1 + 0x3b8);
  if (lVar2 != 0 || lVar1 != 0) {
    return (uint)(byte)(POPCOUNT((char)lVar2) + POPCOUNT((char)((ulong)lVar2 >> 8)) +
                        POPCOUNT((char)((ulong)lVar2 >> 0x10)) +
                        POPCOUNT((char)((ulong)lVar2 >> 0x18)) +
                        POPCOUNT((char)((ulong)lVar2 >> 0x20)) +
                        POPCOUNT((char)((ulong)lVar2 >> 0x28)) +
                        POPCOUNT((char)((ulong)lVar2 >> 0x30)) +
                       POPCOUNT((char)((ulong)lVar2 >> 0x38))) +
           (uint)(byte)(POPCOUNT((char)lVar1) + POPCOUNT((char)((ulong)lVar1 >> 8)) +
                        POPCOUNT((char)((ulong)lVar1 >> 0x10)) +
                        POPCOUNT((char)((ulong)lVar1 >> 0x18)) +
                        POPCOUNT((char)((ulong)lVar1 >> 0x20)) +
                        POPCOUNT((char)((ulong)lVar1 >> 0x28)) +
                        POPCOUNT((char)((ulong)lVar1 >> 0x30)) +
                       POPCOUNT((char)((ulong)lVar1 >> 0x38)));
  }
  return *(int *)(param_1 + 0x3e0);
}

