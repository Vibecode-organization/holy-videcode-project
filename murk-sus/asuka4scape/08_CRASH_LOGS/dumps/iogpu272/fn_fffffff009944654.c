// FUN_fffffff009944654 @ fffffff009944654 size=324

ulong FUN_fffffff009944654(long *param_1,long param_2)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar6 = (ulong)(*(uint *)((long)param_1 + 0x2c) >> 6);
  do {
    uVar2 = *(uint *)(param_1 + 5) >> 6;
    if ((uint)uVar6 < uVar2) {
      uVar4 = (ulong)((uint)uVar6 * -0x40);
      uVar3 = uVar6;
      do {
        lVar5 = uVar3 * 8;
        puVar1 = (ulong *)(param_1[3] + (long)(int)lVar5);
        if (lVar5 - (int)lVar5 != 0) {
          puVar1 = (ulong *)(param_1[3] + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
        }
        if (*puVar1 != 0xffffffffffffffff) {
          uVar6 = ~*puVar1;
          uVar6 = (uVar6 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar6 & 0x5555555555555555) << 1;
          uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
          uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
          uVar6 = (uVar6 & 0xffff0000ffff0000) >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10;
          uVar7 = LZCOUNT(uVar6 >> 0x20 | uVar6 << 0x20);
          uVar4 = uVar7 - uVar4;
          lVar5 = (uVar4 & 0xffffffff) * 8;
          uVar6 = param_1[2] + (long)(int)lVar5;
          if (lVar5 != (int)lVar5) {
            uVar6 = param_1[2] + lVar5 & 0xffffffffffffU | 0x2bad000000000000;
          }
          *(int *)((long)param_1 + 0x2c) = (int)uVar4 + 1;
          (**(code **)(*param_1 + 0x78))(param_1,uVar6,param_2);
          if (param_2 != 0) {
            *(int *)(param_1 + 6) = (int)param_1[6] + 1;
          }
          lVar5 = (uVar3 & 0xffffffff) * 8;
          puVar1 = (ulong *)(param_1[3] + (long)(int)lVar5);
          if (lVar5 != (int)lVar5) {
            puVar1 = (ulong *)(param_1[3] + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
          }
          *puVar1 = *puVar1 | 1L << (uVar7 & 0x3f);
          return uVar4;
        }
        uVar3 = uVar3 + 1;
        uVar4 = uVar4 - 0x40;
        uVar6 = (ulong)uVar2;
      } while (uVar2 != uVar3);
    }
    uVar3 = FUN_fffffff009944424(param_1);
    if ((uVar3 & 1) == 0) {
      return 0;
    }
  } while( true );
}

