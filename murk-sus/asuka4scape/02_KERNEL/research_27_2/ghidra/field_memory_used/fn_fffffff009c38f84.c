// FUN_fffffff009c38f84 @ fffffff009c38f84

undefined8 FUN_fffffff009c38f84(long param_1,undefined8 param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  puVar1 = *(undefined8 **)(param_3 + 0x58);
  lVar2 = *(long *)(param_1 + 0xe8);
  *puVar1 = *(undefined8 *)(lVar2 + 0xac);
  uVar3 = *(undefined8 *)(lVar2 + 0xb8);
  puVar1[2] = *(undefined8 *)(lVar2 + 0xc0);
  puVar1[1] = uVar3;
  puVar1[3] = *(undefined8 *)(lVar2 + 200);
  *(byte *)(puVar1 + 4) = *(byte *)(param_1 + 0x126) & 1;
  *(undefined2 *)((long)puVar1 + 0x22) = 1;
  *(undefined4 *)(param_3 + 0x60) = 0x28;
  return 0;
}

