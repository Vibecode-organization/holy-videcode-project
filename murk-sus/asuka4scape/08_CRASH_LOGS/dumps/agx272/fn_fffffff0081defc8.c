// FUN_fffffff0081defc8 @ fffffff0081defc8 size=108

void FUN_fffffff0081defc8(uint param_1,int *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  byte bVar3;
  byte bVar4;
  
  *(undefined8 *)((long)param_2 + 7) = 0;
  *(undefined8 *)((long)param_2 + 0xf) = 0;
  uVar1 = param_1 >> 0x12 & 3;
  *(undefined1 *)((long)param_2 + 0x17) = 0;
  *param_2 = (param_1 & 0x3fff) << 3;
  uVar2 = 0x40;
  if (uVar1 != 0) {
    uVar2 = (char)(uVar1 << 4);
  }
  *(undefined1 *)(param_2 + 1) = uVar2;
  *(byte *)((long)param_2 + 5) = (byte)(param_1 >> 0x14) & 3;
  *(byte *)((long)param_2 + 6) = (byte)(param_1 >> 0x16) & 1;
  bVar3 = (byte)(param_1 >> 0x17);
  bVar4 = 0;
  if (-1 < (int)param_1) {
    bVar4 = bVar3;
  }
  *(byte *)(param_2 + 2) = bVar4;
  bVar4 = (byte)(param_1 >> 0x18);
  *(byte *)((long)param_2 + 9) = bVar4 >> 7;
  *(byte *)((long)param_2 + 10) = bVar3 & (char)bVar4 >> 7;
  *(byte *)((long)param_2 + 0xe) = (byte)(param_1 >> 0xe) & 0xf;
  return;
}

