// FUN_fffffff009952c9c @ fffffff009952c9c size=56

undefined8 FUN_fffffff009952c9c(long param_1)

{
  byte bVar1;
  
  while( true ) {
    bVar1 = *(byte *)(param_1 + 0x10);
    if (bVar1 != 0x82) break;
    param_1 = *(long *)(param_1 + 0x30);
  }
  if ((bVar1 != 0x40) && ((bVar1 & 0xf) == 0)) {
    return *(undefined8 *)(param_1 + 0x78);
  }
  return 0;
}

