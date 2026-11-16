// FUN_fffffff008212c2c @ fffffff008212c2c size=4

void FUN_fffffff008212c2c(long param_1,long param_2)

{
  undefined8 uStack_40;
  undefined4 uStack_38;
  
  uStack_40 = *(undefined8 *)(param_2 + 0x4c);
  uStack_38 = *(undefined4 *)(param_2 + 0x54);
  if ((*(byte *)(param_2 + 0x48) & 1) != 0) {
    (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(*(long *)(param_1 + 0x218) + 0xe0) * 0x10)
    )(*(undefined8 *)(param_1 + 0xc0),*(long *)(param_1 + 0x218),&uStack_40,0);
  }
  uStack_40 = *(undefined8 *)(param_2 + 0x58);
  uStack_38 = *(undefined4 *)(param_2 + 0x60);
  if ((*(byte *)(param_2 + 0x49) & 1) != 0) {
    (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(*(long *)(param_1 + 0x220) + 0xe0) * 0x10)
    )(*(undefined8 *)(param_1 + 0xc0),*(long *)(param_1 + 0x220),&uStack_40,0);
  }
  return;
}

