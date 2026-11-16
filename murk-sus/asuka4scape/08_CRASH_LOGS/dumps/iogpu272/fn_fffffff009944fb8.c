// FUN_fffffff009944fb8 @ fffffff009944fb8 size=136

long FUN_fffffff009944fb8(long param_1,ulong param_2)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  
  if (((uint)param_2 == 0) || (*(uint *)(param_1 + 0x28) <= (uint)param_2)) {
    FUN_fffffff0099447e4(param_2);
    lVar3 = 0;
  }
  else {
    lVar3 = (param_2 & 0xffffffff) * 8;
    plVar1 = (long *)(*(long *)(param_1 + 0x10) + (long)(int)lVar3);
    if (lVar3 != (int)lVar3) {
      plVar1 = (long *)(*(long *)(param_1 + 0x10) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    lVar3 = *plVar1;
    if (lVar3 != 0) {
      uVar2 = *(uint *)(lVar3 + 0xc);
      *(uint *)(lVar3 + 0xc) = uVar2 + 1;
      if (0xffffffe < uVar2) {
        FUN_fffffff009983678();
      }
    }
  }
  return lVar3;
}

