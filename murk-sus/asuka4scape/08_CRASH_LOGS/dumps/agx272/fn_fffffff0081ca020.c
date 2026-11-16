// FUN_fffffff0081ca020 @ fffffff0081ca020 size=48

void FUN_fffffff0081ca020
               (undefined8 param_1,long param_2,undefined4 param_3,long param_4,undefined2 param_5)

{
  *(undefined4 *)(param_2 + 0x10) = param_3;
  *(undefined8 *)(param_2 + 8) = *(undefined8 *)(param_4 + 0x98);
  *(undefined2 *)(param_2 + 0x14) = param_5;
  *(char *)(param_2 + 0x16) = (char)*(undefined4 *)(param_4 + 0x18);
  *(byte *)(param_2 + 0x17) = (*(byte *)(param_4 + 0x3c) ^ 0xff) & 1;
  return;
}

