// FUN_fffffff00997b5dc @ fffffff00997b5dc size=100

undefined8 FUN_fffffff00997b5dc(long param_1,ulong param_2)

{
  uint uVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  
  uVar1 = 0;
  lVar3 = 8;
  uVar4 = param_2;
  do {
    uVar1 = (uVar1 + ((uint)uVar4 & 0xff)) * 0x401;
    uVar1 = uVar1 ^ uVar1 >> 6;
    uVar4 = uVar4 >> 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  plVar2 = (long *)(param_1 + 0x18 + (ulong)((uVar1 * 9 ^ uVar1 * 9 >> 0xb) & 0x7f) * 8);
  do {
    plVar2 = (long *)*plVar2;
    if (plVar2 == (long *)0x0) {
      return 0;
    }
  } while (plVar2[1] != *(long *)(param_2 + 0x70));
  return plVar2[2];
}

