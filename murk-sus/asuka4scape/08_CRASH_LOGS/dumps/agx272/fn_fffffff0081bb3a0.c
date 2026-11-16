// FUN_fffffff0081bb3a0 @ fffffff0081bb3a0 size=4

void FUN_fffffff0081bb3a0(long param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  int iVar2;
  ulong uStack_38;
  ulong uStack_30;
  undefined8 uStack_28;
  
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  iVar2 = (**(code **)(**(long **)(param_1 + 0x280) + 0xa28))
                    (*(long **)(param_1 + 0x280),&uStack_38,param_2,param_3);
  if (iVar2 != 0) {
    puVar1 = (ulong *)(*(long *)(param_1 + 0x348) + 0x1e4);
    *puVar1 = *puVar1 & uStack_38;
    *puVar1 = *puVar1 | param_3 << (uStack_30 & 0x3f);
  }
  return;
}

