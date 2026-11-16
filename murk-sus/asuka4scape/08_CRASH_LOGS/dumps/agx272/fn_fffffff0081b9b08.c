// FUN_fffffff0081b9b08 @ fffffff0081b9b08 size=60

bool FUN_fffffff0081b9b08(long param_1,ulong param_2)

{
  undefined1 *puVar1;
  
  if ((param_2 & 0xfc) == 0) {
    puVar1 = (undefined1 *)(*(long *)(param_1 + 0x348) + 0x9e7 + (param_2 & 3) * 6);
    *puVar1 = (char)(param_2 >> 0x10);
    puVar1[1] = (char)(param_2 >> 8);
  }
  return (param_2 & 0xfc) == 0;
}

