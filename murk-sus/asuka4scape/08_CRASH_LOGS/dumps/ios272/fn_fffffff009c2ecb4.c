// FUN_fffffff009c2ecb4 @ fffffff009c2ecb4 size=72

uint FUN_fffffff009c2ecb4(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  uint *puVar3;
  uint uVar4;
  
  if (param_2 < 3) {
    lVar1 = *(long *)(param_1 + 0x10) + 0x30;
    lVar2 = (ulong)(param_2 * 0x60) + 0x54;
    puVar3 = (uint *)(lVar1 + (int)lVar2);
    if (lVar2 != (int)lVar2) {
      puVar3 = (uint *)(lVar1 + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar4 = *puVar3;
  }
  else {
    uVar4 = 0;
  }
  return uVar4 & 0xff;
}

