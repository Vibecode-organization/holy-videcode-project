// FUN_fffffff00820e6fc @ fffffff00820e6fc size=56

void FUN_fffffff00820e6fc(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x20);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  **(undefined8 **)(param_1 + 0x20) = 0;
  *(undefined8 *)(*(long *)(param_1 + 0x20) + 8) = *(undefined8 *)(param_1 + 0x28);
  lVar2 = *(long *)(param_1 + 0x20);
  *(uint *)(lVar2 + 0x10) = (uint)(*(int *)(param_1 + 0x38) == 2);
  *(undefined4 *)(lVar2 + 0x14) = 0;
  return;
}

