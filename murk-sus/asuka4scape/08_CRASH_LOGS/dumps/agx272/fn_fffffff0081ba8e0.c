// FUN_fffffff0081ba8e0 @ fffffff0081ba8e0 size=4

void FUN_fffffff0081ba8e0(long param_1,ulong param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uStack_48;
  ulong uStack_40;
  ulong uStack_38;
  
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  iVar3 = (**(code **)(**(long **)(param_1 + 0x280) + 0xac0))
                    (*(long **)(param_1 + 0x280),&uStack_48);
  if (iVar3 != 0) {
    lVar2 = *(long *)(param_1 + 0x348) + 0x6c4;
    lVar1 = (uStack_38 & 0xffff) + (param_2 & 0xffffffff) * 8;
    *(ulong *)(lVar2 + lVar1 * 8) = *(ulong *)(lVar2 + lVar1 * 8) & uStack_48;
    *(ulong *)(lVar2 + lVar1 * 8) = *(ulong *)(lVar2 + lVar1 * 8) | param_4 << (uStack_40 & 0x3f);
  }
  return;
}

