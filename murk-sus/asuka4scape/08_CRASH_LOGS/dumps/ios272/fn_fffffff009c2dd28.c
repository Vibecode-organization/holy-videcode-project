// FUN_fffffff009c2dd28 @ fffffff009c2dd28 size=96

bool FUN_fffffff009c2dd28(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar2 = FUN_fffffff009c2a6e0(*(undefined8 *)(param_1 + 0x10));
  lVar3 = FUN_fffffff009c22324(*(undefined8 *)(param_1 + 0x10));
  iVar2 = iVar2 - (uint)(lVar3 != 0 && lVar3 != param_1);
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar2 != iVar1) {
    *(int *)(param_1 + 0x50) = iVar2;
  }
  return iVar2 != iVar1;
}

