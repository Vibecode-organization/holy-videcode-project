// FUN_fffffff0081baa34 @ fffffff0081baa34 size=164

void FUN_fffffff0081baa34(long param_1,ulong param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong local_48;
  ulong local_40;
  ulong local_38;
  
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  iVar3 = (**(code **)(**(long **)(param_1 + 0x280) + 0xa90))(*(long **)(param_1 + 0x280),&local_48)
  ;
  if (iVar3 != 0) {
    lVar2 = *(long *)(param_1 + 0x348) + 0x26c;
    lVar1 = (local_38 & 0xffff) + (param_2 & 0xffffffff) * 8;
    *(ulong *)(lVar2 + lVar1 * 8) = *(ulong *)(lVar2 + lVar1 * 8) & local_48;
    *(ulong *)(lVar2 + lVar1 * 8) = *(ulong *)(lVar2 + lVar1 * 8) | param_4 << (local_40 & 0x3f);
  }
  return;
}

