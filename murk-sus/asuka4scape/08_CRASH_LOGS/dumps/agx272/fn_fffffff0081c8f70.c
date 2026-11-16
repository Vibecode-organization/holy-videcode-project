// FUN_fffffff0081c8f70 @ fffffff0081c8f70 size=48

undefined8 FUN_fffffff0081c8f70(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x918);
  if (*(int *)(lVar2 + 0x5c4) == *(int *)(lVar2 + 0x55c)) {
    return 0;
  }
  *(int *)(lVar2 + 0x55c) = *(int *)(lVar2 + 0x5c4);
  uVar1 = thunk_EXT_FUN_80110000038c6e24((long)*(int *)(lVar2 + 0x558),0x20);
  return uVar1;
}

