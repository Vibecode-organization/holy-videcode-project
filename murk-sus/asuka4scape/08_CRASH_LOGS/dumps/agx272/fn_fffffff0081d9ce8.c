// FUN_fffffff0081d9ce8 @ fffffff0081d9ce8 size=176

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081d9ce8(long param_1)

{
  uint uVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(short *)(param_1 + 0x18) = (short)DAT_fffffff00ae21818;
  *(char *)(param_1 + 0x1a) = (char)DAT_fffffff00ae2181c;
  uVar1 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
  uVar2 = (undefined2)uVar1;
  *(undefined2 *)(param_1 + 0x22) = uVar2;
  *(undefined2 *)(param_1 + 0x42) = uVar2;
  *(undefined2 *)(param_1 + 0x62) = uVar2;
  *(undefined2 *)(param_1 + 0x20) = 8;
  uVar2 = (undefined2)(uVar1 >> 3);
  *(undefined2 *)(param_1 + 0x40) = uVar2;
  *(undefined2 *)(param_1 + 0x60) = uVar2;
  *(int *)(param_1 + 0x1b) = (int)DAT_fffffff007113fc8;
  uVar4 = _UNK_fffffff007113b48;
  uVar3 = _DAT_fffffff007113b40;
  *(undefined8 *)(param_1 + 0x2c) = _UNK_fffffff007113b48;
  *(undefined8 *)(param_1 + 0x24) = uVar3;
  *(undefined8 *)(param_1 + 0x4c) = uVar4;
  *(undefined8 *)(param_1 + 0x44) = uVar3;
  *(undefined8 *)(param_1 + 0x6c) = uVar4;
  *(undefined8 *)(param_1 + 100) = uVar3;
  *(undefined1 *)(param_1 + 0x1f) = 0x24;
  *(int *)(param_1 + 0x3c) = (int)DAT_fffffff007113fd0;
  *(int *)(param_1 + 0x5c) = (int)DAT_fffffff007113fd8;
  *(undefined8 *)(param_1 + 0x34) = 0x7000000000;
  *(undefined8 *)(param_1 + 0x54) = 0xffe000000;
  *(undefined8 *)(param_1 + 0x74) = 0x1ffc000;
  return;
}

