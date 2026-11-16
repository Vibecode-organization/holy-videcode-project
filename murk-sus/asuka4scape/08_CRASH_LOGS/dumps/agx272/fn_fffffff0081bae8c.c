// FUN_fffffff0081bae8c @ fffffff0081bae8c size=156

void FUN_fffffff0081bae8c(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  ulong local_38;
  ulong local_30;
  ulong local_28;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  iVar2 = (**(code **)(**(long **)(param_1 + 0x280) + 0xa80))
                    (*(long **)(param_1 + 0x280),&local_38,param_2,param_3);
  if (iVar2 != 0) {
    lVar1 = *(long *)(param_1 + 0x348) + 0x24c;
    local_28 = local_28 & 0xffff;
    *(ulong *)(lVar1 + local_28 * 8) = *(ulong *)(lVar1 + local_28 * 8) & local_38;
    *(ulong *)(lVar1 + local_28 * 8) =
         *(ulong *)(lVar1 + local_28 * 8) | param_3 << (local_30 & 0x3f);
  }
  return;
}

