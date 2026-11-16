// FUN_fffffff009947548 @ fffffff009947548 size=52

undefined8 FUN_fffffff009947548(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_3 + 0x58);
  uVar1 = FUN_fffffff00997554c(*(undefined8 *)(param_1 + 0xf8));
  *puVar2 = uVar1;
  puVar2[1] = 0;
  return 0;
}

