// FUN_fffffff0081d71d4 @ fffffff0081d71d4 size=80

uint FUN_fffffff0081d71d4(long param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x10);
  if (*(int *)(lVar2 + 0xdfbc) != 1) {
    uVar1 = FUN_fffffff0081f2fb8(lVar2,0xd01010);
    return uVar1 & 1;
  }
  return *(uint *)((*(long *)(lVar2 + 0x11568) - *(long *)(lVar2 + 0xe1c8)) + 0xd01010) & 1;
}

