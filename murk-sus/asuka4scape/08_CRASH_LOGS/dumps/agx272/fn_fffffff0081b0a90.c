// FUN_fffffff0081b0a90 @ fffffff0081b0a90 size=204

int FUN_fffffff0081b0a90(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  byte bVar8;
  undefined8 uVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  
  uVar11 = *(ulong *)(param_1 + 0x90);
  if (uVar11 != 0) {
    iVar10 = 0;
    uVar11 = (uVar11 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar11 & 0x5555555555555555) << 1;
    uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
    uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
    uVar11 = (uVar11 & 0xffff0000ffff0000) >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10;
    uVar12 = LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
    uVar11 = uVar12;
    do {
      lVar14 = uVar11 * 0x20;
      puVar3 = (undefined8 *)(*(long *)(param_1 + 0x98) + (long)(int)lVar14);
      if (lVar14 - (int)lVar14 != 0) {
        puVar3 = (undefined8 *)
                 (*(long *)(param_1 + 0x98) + lVar14 & 0xffffffffffffU | 0x2bad000000000000);
      }
      uVar6 = puVar3[1];
      uVar4 = *puVar3;
      uVar9 = puVar3[3];
      uVar7 = puVar3[2];
      bVar8 = POPCOUNT((char)((ulong)uVar7 >> 0x10)) + POPCOUNT((char)((ulong)uVar7 >> 0x18));
      bVar5 = POPCOUNT((char)((ulong)uVar4 >> 0x10)) + POPCOUNT((char)((ulong)uVar4 >> 0x18));
      iVar10 = (CONCAT12(bVar5,(ushort)(byte)POPCOUNT((char)uVar4) +
                               (ushort)(byte)POPCOUNT((char)((ulong)uVar4 >> 8))) & 0xffff) +
               (uint)bVar5 +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar4 >> 0x20)) +
                            POPCOUNT((char)((ulong)uVar4 >> 0x28)) +
                           POPCOUNT((char)((ulong)uVar4 >> 0x30)) +
                           POPCOUNT((char)((ulong)uVar4 >> 0x38))) +
               (uint)(byte)(POPCOUNT((char)uVar6) + POPCOUNT((char)((ulong)uVar6 >> 8))) +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar6 >> 0x10)) +
                           POPCOUNT((char)((ulong)uVar6 >> 0x18))) +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar6 >> 0x20)) +
                            POPCOUNT((char)((ulong)uVar6 >> 0x28)) +
                           POPCOUNT((char)((ulong)uVar6 >> 0x30)) +
                           POPCOUNT((char)((ulong)uVar6 >> 0x38))) +
               (CONCAT12(bVar8,(ushort)(byte)POPCOUNT((char)uVar7) +
                               (ushort)(byte)POPCOUNT((char)((ulong)uVar7 >> 8))) & 0xffff) +
               (uint)bVar8 +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar7 >> 0x20)) +
                            POPCOUNT((char)((ulong)uVar7 >> 0x28)) +
                           POPCOUNT((char)((ulong)uVar7 >> 0x30)) +
                           POPCOUNT((char)((ulong)uVar7 >> 0x38))) +
               (uint)(byte)(POPCOUNT((char)uVar9) + POPCOUNT((char)((ulong)uVar9 >> 8))) +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar9 >> 0x10)) +
                           POPCOUNT((char)((ulong)uVar9 >> 0x18))) +
               (uint)(byte)(POPCOUNT((char)((ulong)uVar9 >> 0x20)) +
                            POPCOUNT((char)((ulong)uVar9 >> 0x28)) +
                           POPCOUNT((char)((ulong)uVar9 >> 0x30)) +
                           POPCOUNT((char)((ulong)uVar9 >> 0x38))) + iVar10;
      uVar13 = (uint)uVar12 & 0x3f;
      uVar2 = 0;
      if (uVar13 != 0x3f) {
        uVar2 = -1L << ((ulong)(uVar13 + 1) & 0x3f);
      }
      uVar2 = *(ulong *)(param_1 + 0x90 + (uVar11 >> 3 & 0x1ffffffffffffff8)) & uVar2;
      uVar11 = (uVar2 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar2 & 0x5555555555555555) << 1;
      uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
      uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
      uVar11 = (uVar11 & 0xffff0000ffff0000) >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10;
      uVar13 = (uint)LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
      if (uVar2 == 0) {
        uVar13 = 0xffffffff;
      }
      uVar1 = uVar13 + ((uint)uVar12 & 0xffffffc0);
      uVar12 = (ulong)uVar1;
      if (0x7fffffff < uVar13) {
        uVar1 = 0xffffffff;
      }
      uVar11 = (ulong)uVar1;
    } while (uVar1 != 0xffffffff);
    return iVar10;
  }
  return 0;
}

