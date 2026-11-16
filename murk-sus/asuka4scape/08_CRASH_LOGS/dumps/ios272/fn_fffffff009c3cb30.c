// FUN_fffffff009c3cb30 @ fffffff009c3cb30 size=68

undefined8 FUN_fffffff009c3cb30(long param_1,undefined8 *param_2,undefined4 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xe8);
  *param_2 = *(undefined8 *)(lVar1 + 0xac);
  uVar2 = *(undefined8 *)(lVar1 + 0xb8);
  param_2[2] = *(undefined8 *)(lVar1 + 0xc0);
  param_2[1] = uVar2;
  param_2[3] = *(undefined8 *)(lVar1 + 200);
  *(byte *)(param_2 + 4) = *(byte *)(param_1 + 0x126) & 1;
  *(undefined2 *)((long)param_2 + 0x22) = 1;
  *param_3 = 0x28;
  return 0;
}

