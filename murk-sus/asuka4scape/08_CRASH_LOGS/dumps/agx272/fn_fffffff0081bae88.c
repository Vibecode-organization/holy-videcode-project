// FUN_fffffff0081bae88 @ fffffff0081bae88 size=4

void FUN_fffffff0081bae88(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  ulong uStack_38;
  ulong uStack_30;
  ulong uStack_28;
  
  uStack_38 = 0;
  uStack_30 = 0;
  uStack_28 = 0;
  iVar2 = (**(code **)(**(long **)(param_1 + 0x280) + 0xa80))
                    (*(long **)(param_1 + 0x280),&uStack_38,param_2,param_3);
  if (iVar2 != 0) {
    lVar1 = *(long *)(param_1 + 0x348) + 0x24c;
    uStack_28 = uStack_28 & 0xffff;
    *(ulong *)(lVar1 + uStack_28 * 8) = *(ulong *)(lVar1 + uStack_28 * 8) & uStack_38;
    *(ulong *)(lVar1 + uStack_28 * 8) =
         *(ulong *)(lVar1 + uStack_28 * 8) | param_3 << (uStack_30 & 0x3f);
  }
  return;
}

