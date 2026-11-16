// FUN_fffffff0081d772c @ fffffff0081d772c size=152

ulong FUN_fffffff0081d772c(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  uVar2 = (**(code **)(*param_1 + 0xd8))();
  if ((int)uVar2 != 0) {
    lVar3 = param_1[2];
    if (*(int *)(lVar3 + 0xdfbc) == 1) {
      uVar1 = *(uint *)((*(long *)(lVar3 + 0x11568) - *(long *)(lVar3 + 0xe1c8)) + 0xd01000);
    }
    else {
      uVar1 = FUN_fffffff0081f2fb8(lVar3,0xd01000);
    }
    uVar2 = (ulong)(uVar1 & 0xf);
  }
  return uVar2;
}

