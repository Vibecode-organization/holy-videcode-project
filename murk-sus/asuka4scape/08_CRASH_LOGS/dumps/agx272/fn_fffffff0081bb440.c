// FUN_fffffff0081bb440 @ fffffff0081bb440 size=152

void FUN_fffffff0081bb440(long param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  int iVar2;
  ulong local_38;
  ulong local_30;
  undefined8 local_28;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  iVar2 = (**(code **)(**(long **)(param_1 + 0x280) + 0xa20))
                    (*(long **)(param_1 + 0x280),&local_38,param_2,param_3);
  if (iVar2 != 0) {
    puVar1 = (ulong *)(*(long *)(param_1 + 0x348) + 0x1dc);
    *puVar1 = *puVar1 & local_38;
    *puVar1 = *puVar1 | param_3 << (local_30 & 0x3f);
  }
  return;
}

