// FUN_fffffff0081d7bf8 @ fffffff0081d7bf8 size=588

void FUN_fffffff0081d7bf8(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  uint local_84;
  ulong local_70 [2];
  
  local_70[0] = *(ulong *)(param_1 + 0x3b0);
  uVar6 = *(ulong *)(param_1 + 0x3b8);
  bVar5 = local_70[0] == 0;
  if (uVar6 == 0 && local_70[0] == 0) {
    local_70[0] = 0;
    local_84 = *(uint *)(param_1 + 0x3e0);
  }
  else {
    local_84 = 0;
  }
  uVar8 = 0;
  local_70[1] = uVar6;
  do {
    if (uVar6 == 0 && bVar5) {
      if (local_84 <= uVar8) {
        return;
      }
      uVar9 = uVar8;
      uVar8 = uVar8 + 1;
    }
    else {
      if (local_70[1] == 0 && local_70[0] == 0) {
        return;
      }
      if (local_70[0] == 0) {
        if (local_70[1] != 0) {
          uVar9 = 0x40;
          uVar11 = local_70[1];
          goto LAB_fffffff0081d7cb4;
        }
        uVar9 = 0xffffffff;
      }
      else {
        uVar9 = 0;
        uVar11 = local_70[0];
LAB_fffffff0081d7cb4:
        uVar11 = (uVar11 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar11 & 0x5555555555555555) << 1;
        uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
        uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
        uVar11 = (uVar11 & 0xffff0000ffff0000) >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10;
        uVar9 = uVar9 | (uint)LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
      }
      uVar11 = (ulong)(uVar9 >> 3) & 0x1ffffff8;
      *(ulong *)((long)local_70 + uVar11) =
           *(ulong *)((long)local_70 + uVar11) & (1L << ((ulong)uVar9 & 0x3f) ^ 0xffffffffffffffffU)
      ;
    }
    lVar7 = *(long *)(param_1 + 0x308);
    *(uint *)(lVar7 + 0x11000) = uVar9;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = (ulong)*(uint *)(param_1 + 0x1944c) + 999999;
    uVar10 = SUB164(auVar4 * ZEXT816(0x10c6f7a0b5ee),8);
    uVar1 = ((0x10 << (*(ulong *)(lVar7 + 0x11200) >> 0x10 & 3)) + uVar10) - 1;
    uVar9 = uVar1 & 0xffff;
    uVar2 = 0;
    if (uVar10 != 0) {
      uVar2 = uVar9 / uVar10;
    }
    uVar3 = 0;
    if (uVar10 != 0) {
      uVar3 = (uVar1 + (uVar2 * uVar10 - uVar9)) / uVar10;
    }
    if (*(int *)(param_1 + 0x3f8) != 0) {
      uVar9 = 0;
      do {
        *(uint *)(lVar7 + 0x100e8) = uVar9;
        thunk_EXT_FUN_80110000038fe988(uVar3);
        lVar7 = *(long *)(param_1 + 0x308);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 0x3f8));
    }
    if (*(int *)(param_1 + 0x3fc) != 0) {
      uVar9 = 0;
      do {
        *(uint *)(lVar7 + 0x100e0) = uVar9;
        thunk_EXT_FUN_80110000038fe988(uVar3);
        lVar7 = *(long *)(param_1 + 0x308);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 0x3fc));
    }
    if (*(int *)(param_1 + 0x400) != 0) {
      uVar9 = 0;
      do {
        *(uint *)(lVar7 + 0x100f0) = uVar9;
        thunk_EXT_FUN_80110000038fe988(uVar3);
        lVar7 = *(long *)(param_1 + 0x308);
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 0x400));
    }
  } while( true );
}

