// FUN_fffffff0081db458 @ fffffff0081db458 size=32

void FUN_fffffff0081db458(long param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(long *)(param_1 + 0xc0) + 0x68);
  *(undefined4 **)(*(long *)(param_1 + 0xc0) + 0x68) = puVar1 + 1;
  *puVar1 = 0x100;
  return;
}

