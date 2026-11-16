// FUN_fffffff0099555a8 @ fffffff0099555a8 size=124

void FUN_fffffff0099555a8(long param_1)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x30);
  iVar1 = (**(code **)(*plVar2 + 0xb0))(plVar2);
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*plVar2 + 0x98))(plVar2), iVar1 != 0)) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0x80000;
  }
  return;
}

