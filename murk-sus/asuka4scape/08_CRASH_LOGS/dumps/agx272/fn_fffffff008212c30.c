// FUN_fffffff008212c30 @ fffffff008212c30 size=180

void FUN_fffffff008212c30(long param_1,long param_2)

{
  undefined8 local_40;
  undefined4 local_38;
  
  local_40 = *(undefined8 *)(param_2 + 0x4c);
  local_38 = *(undefined4 *)(param_2 + 0x54);
  if ((*(byte *)(param_2 + 0x48) & 1) != 0) {
    (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(*(long *)(param_1 + 0x218) + 0xe0) * 0x10)
    )(*(undefined8 *)(param_1 + 0xc0),*(long *)(param_1 + 0x218),&local_40,0);
  }
  local_40 = *(undefined8 *)(param_2 + 0x58);
  local_38 = *(undefined4 *)(param_2 + 0x60);
  if ((*(byte *)(param_2 + 0x49) & 1) != 0) {
    (**(code **)(&DAT_fffffff007c93658 + (ulong)*(uint *)(*(long *)(param_1 + 0x220) + 0xe0) * 0x10)
    )(*(undefined8 *)(param_1 + 0xc0),*(long *)(param_1 + 0x220),&local_40,0);
  }
  return;
}

