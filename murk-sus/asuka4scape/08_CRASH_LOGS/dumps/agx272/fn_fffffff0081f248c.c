// FUN_fffffff0081f248c @ fffffff0081f248c size=120

bool FUN_fffffff0081f248c(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 auStack_28 [8];
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0x4c) == -1)) {
    lVar3 = *(long *)(param_1 + 0x10);
    uVar2 = thunk_EXT_FUN_80110000029636a8(param_2);
    iVar1 = FUN_fffffff00819cb78(lVar3 + 0x11df0,uVar2,0x80,auStack_28);
    *(int *)(param_1 + 0x4c) = iVar1;
    return iVar1 != -1;
  }
  return false;
}

