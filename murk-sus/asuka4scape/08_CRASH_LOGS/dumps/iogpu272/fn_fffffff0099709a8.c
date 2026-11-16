// FUN_fffffff0099709a8 @ fffffff0099709a8 size=84

undefined8 FUN_fffffff0099709a8(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x18));
  if ((*(long *)(param_1 + 0x30) == 0) || (iVar1 = FUN_fffffff00994d91c(), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(param_1 + 0x30);
  }
  thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x18));
  return uVar2;
}

