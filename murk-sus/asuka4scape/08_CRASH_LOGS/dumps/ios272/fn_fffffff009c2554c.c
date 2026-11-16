// FUN_fffffff009c2554c @ fffffff009c2554c size=124

byte FUN_fffffff009c2554c(long param_1,long *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x40))(param_2,*(undefined8 *)(param_1 + 0x30));
  if (iVar1 != 0) {
    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18) = 1;
    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x18) = 1;
  }
  return *(byte *)(*(long *)(*(long *)(param_1 + 0x28) + 8) + 0x18) & 1;
}

