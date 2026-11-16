// FUN_fffffff0081d9714 @ fffffff0081d9714 size=32

void FUN_fffffff0081d9714(long param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(long *)(param_1 + 0xc0) + 0x68);
  *(undefined4 **)(*(long *)(param_1 + 0xc0) + 0x68) = puVar1 + 1;
  *puVar1 = 0x800000;
  return;
}

