// FUN_fffffff0081cad9c @ fffffff0081cad9c size=140

void FUN_fffffff0081cad9c(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  
  *(undefined4 *)(param_1 + 0x14e4) = 0;
  (**(code **)(**(long **)(param_1 + 0x280) + 0x748))(*(long **)(param_1 + 0x280),1);
  lVar3 = (**(code **)(**(long **)(param_1 + 0x1498) + 0x78))();
  uVar2 = *(uint *)(param_1 + 0x14e4);
  puVar1 = (undefined8 *)(lVar3 + (ulong)uVar2);
  *(undefined4 *)(puVar1 + 2) = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  *(uint *)(param_1 + 0x14e4) = uVar2 + 0x18;
  return;
}

