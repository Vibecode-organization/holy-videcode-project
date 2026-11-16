// FUN_fffffff009963d30 @ fffffff009963d30 size=252

undefined8 FUN_fffffff009963d30(long param_1,int *param_2)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  uVar5 = (ulong)(*(uint *)(param_1 + 0x54) >> 6);
  do {
    uVar2 = *(uint *)(param_1 + 0x50) >> 6;
    uVar6 = uVar5;
    if ((uint)uVar5 < uVar2) {
      lVar4 = *(long *)(param_1 + 0x40);
      iVar7 = (uint)uVar5 * -0x40;
      do {
        lVar8 = uVar5 * 8;
        puVar1 = (ulong *)(lVar4 + (int)lVar8);
        if (lVar8 - (int)lVar8 != 0) {
          puVar1 = (ulong *)(lVar4 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if (*puVar1 != 0xffffffffffffffff) {
          uVar6 = ~*puVar1;
          uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
          uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
          uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
          uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
          uVar6 = LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20);
          iVar7 = (int)uVar6 - iVar7;
          *(int *)(param_1 + 0x54) = iVar7 + 1;
          lVar8 = (uVar5 & 0xffffffff) * 8;
          puVar1 = (ulong *)(lVar4 + (int)lVar8);
          if (lVar8 != (int)lVar8) {
            puVar1 = (ulong *)(lVar4 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
          }
          uVar9 = 1;
          *puVar1 = *puVar1 | 1L << (uVar6 & 0x3f);
          *param_2 = iVar7;
          goto LAB_fffffff009963e10;
        }
        uVar5 = uVar5 + 1;
        iVar7 = iVar7 + -0x40;
        uVar6 = (ulong)uVar2;
      } while (uVar2 != uVar5);
    }
    uVar3 = FUN_fffffff009963c60(param_1);
    uVar5 = uVar6;
    if ((uVar3 & 1) == 0) {
      uVar9 = 0;
LAB_fffffff009963e10:
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
      return uVar9;
    }
  } while( true );
}

