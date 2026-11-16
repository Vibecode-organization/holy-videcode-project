// FUN_fffffff0081ecde4 @ fffffff0081ecde4 size=24

undefined8 FUN_fffffff0081ecde4(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x228) != 0) {
    uVar1 = (**(code **)(**(long **)(*(long *)(param_1 + 0x228) + 0x20) + 0xa0))();
    return uVar1;
  }
  return 0;
}

