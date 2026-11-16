// FUN_fffffff00995193c @ fffffff00995193c size=116

bool FUN_fffffff00995193c(long param_1)

{
  long lVar1;
  
  if (*(long *)(param_1 + 0x30) != 0) {
    return true;
  }
  lVar1 = (**(code **)(**(long **)(param_1 + 0x28) + 0xe8))(*(long **)(param_1 + 0x28),0);
  *(long *)(param_1 + 0x30) = lVar1;
  if (lVar1 != 0) {
    FUN_fffffff0099750a8(*(undefined8 *)(param_1 + 0x20),param_1);
  }
  return lVar1 != 0;
}

