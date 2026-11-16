// FUN_fffffff00994d550 @ fffffff00994d550 size=212

bool FUN_fffffff00994d550(long param_1,long param_2,uint *param_3)

{
  long *plVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x840));
  iVar2 = *(int *)(param_2 + 0x18);
  if (iVar2 < *(int *)(param_1 + 0x28)) {
    lVar5 = (long)iVar2 * 0x18;
    plVar1 = (long *)(param_1 + 0x848 + (long)(int)lVar5);
    if (lVar5 - (int)lVar5 != 0) {
      plVar1 = (long *)(param_1 + 0x848 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
    }
    if (*plVar1 == param_2) {
      uVar4 = *param_3 | 0x8000;
      do {
        uVar6 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
        uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
        uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
        uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
        lVar5 = LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10);
        uVar6 = (uint)lVar5;
        bVar3 = uVar6 < 0xf;
        if (0xe < uVar6) break;
        uVar4 = 1 << (ulong)(uVar6 & 0x1f) ^ uVar4;
      } while ((param_3[lVar5 + 1] & 0xff) == 0xff || (char)param_3[lVar5 + 1] != iVar2);
      goto LAB_fffffff00994d5bc;
    }
  }
  bVar3 = false;
LAB_fffffff00994d5bc:
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x840));
  return bVar3;
}

