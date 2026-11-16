// FUN_fffffff0081d9734 @ fffffff0081d9734 size=164

void FUN_fffffff0081d9734(undefined8 param_1,long param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  undefined8 uVar5;
  
  uVar5 = *(undefined8 *)(param_3 + 0x4a8);
  *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(param_3 + 0x500);
  *(undefined8 *)(param_2 + 0x70) = uVar5;
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(param_3 + 0x510);
  *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(param_3 + 0x518);
  *(undefined8 *)(param_2 + 0x88) = *(undefined8 *)(param_3 + 0x520);
  *(undefined8 *)(param_2 + 0x90) = *(undefined8 *)(param_3 + 0x528);
  *(undefined8 *)(param_2 + 0x98) = 0x1100000000;
  uVar2 = *(uint *)(param_3 + 0x550);
  bVar3 = *(byte *)(param_3 + 0x569);
  bVar4 = *(byte *)(param_3 + 0x56a);
  uVar1 = 0;
  if (*(ulong *)(param_3 + 0x558) != 0) {
    uVar1 = *(ulong *)(param_3 + 0x558) | (ulong)(*(long *)(param_3 + 0x560) != 0);
  }
  *(long *)(param_2 + 0xb0) = *(long *)(param_3 + 0x560);
  *(ulong *)(param_2 + 0xb8) =
       ((ulong)bVar3 & 1) << 6 | (ulong)uVar2 << 0x10 | ((ulong)bVar4 & 1) << 0x18;
  uVar5 = 0x8ee0;
  if ((*(byte *)(param_3 + 0x5dc) & 1) == 0) {
    uVar5 = 0x8c60;
  }
  bVar3 = *(byte *)(param_3 + 0x568);
  *(undefined8 *)(param_2 + 0xa0) = uVar5;
  *(ulong *)(param_2 + 0xa8) = uVar1;
  uVar2 = *(uint *)(param_3 + 0x714);
  *(ulong *)(param_2 + 0xc0) = (ulong)~(uint)bVar3 & 1;
  *(ulong *)(param_2 + 200) = (ulong)uVar2 & 0x1f;
  return;
}

