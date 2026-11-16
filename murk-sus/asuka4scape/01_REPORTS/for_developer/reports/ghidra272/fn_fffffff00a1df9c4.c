// FUN_fffffff00a1df9c4 @ fffffff00a1df9c4 size=164

long FUN_fffffff00a1df9c4(long param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar3 = *(ulong *)(param_1 + 0x48);
  if (0xff < param_2) {
    if ((uVar3 >> 0x26 & 1) == 0) {
      if (uVar3 == 0) {
        return 0;
      }
      uVar2 = (uVar3 & 0x3fff) << 0xe;
      uVar3 = uVar3 & 0xffffffffffffc000 | 0x4000000000;
    }
    else {
      uVar2 = (uVar3 & 0x10 | 0x20) << (uVar3 & 0xf);
      uVar3 = uVar3 & 0xffffffffffffffe0;
    }
    if (((ulong)(param_2 >> 8) * 0x18 + 0x18 <= uVar2) &&
       (lVar1 = uVar3 + (ulong)(param_2 >> 8) * 0x18, lVar1 != 0)) {
      if (((*(uint *)(lVar1 + 8) & 0x1f0000) != 0) &&
         ((*(uint *)(lVar1 + 8) & 0xfc000000 | 0x3000000) == param_2 * 0x1000000)) {
        return lVar1;
      }
    }
  }
  return 0;
}

