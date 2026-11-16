// FUN_fffffff0081b9a9c @ fffffff0081b9a9c size=28

undefined8 FUN_fffffff0081b9a9c(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x348);
  *(char *)(lVar1 + 0x9e5) = (char)param_2;
  *(char *)(lVar1 + 0x9e4) = (char)((uint)param_2 >> 8);
  return 1;
}

