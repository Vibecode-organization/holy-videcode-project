// FUN_fffffff0081d19e4 @ fffffff0081d19e4 size=128

void FUN_fffffff0081d19e4(long param_1,undefined4 param_2,uint param_3,uint param_4)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  
  if ((param_4 == 0) || ((param_4 & 1) != 0)) {
    lVar3 = (**(code **)(**(long **)(param_1 + 0x1498) + 0x78))();
    uVar2 = *(uint *)(param_1 + 0x14e4);
    puVar1 = (ulong *)(lVar3 + (ulong)uVar2);
    *(undefined4 *)(puVar1 + 1) = param_2;
    *puVar1 = (ulong)param_3;
    *(undefined8 *)((long)puVar1 + 0xc) = DAT_fffffff007113ec0;
    *(uint *)(param_1 + 0x14e4) = uVar2 + 0x18;
  }
  return;
}

