// FUN_fffffff0082139b0 @ fffffff0082139b0 size=4

void FUN_fffffff0082139b0(long param_1,long param_2)

{
  undefined8 uStack_20;
  undefined4 uStack_18;
  
  uStack_20 = *(undefined8 *)(param_2 + 100);
  uStack_18 = *(undefined4 *)(param_2 + 0x6c);
  if ((*(byte *)(param_2 + 0x4a) & 1) != 0) {
    (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(*(long *)(param_1 + 0x218) + 0xe0) * 0x10)
    )(*(undefined8 *)(param_1 + 0xc0),*(long *)(param_1 + 0x218),&uStack_20,0);
  }
  return;
}

