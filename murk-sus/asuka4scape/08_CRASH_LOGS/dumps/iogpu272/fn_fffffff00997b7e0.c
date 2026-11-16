// FUN_fffffff00997b7e0 @ fffffff00997b7e0 size=180

void FUN_fffffff00997b7e0(long param_1,ulong param_2,long *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar2 = 0;
  lVar3 = 8;
  uVar5 = param_2;
  do {
    uVar2 = (uVar2 + ((uint)uVar5 & 0xff)) * 0x401;
    uVar2 = uVar2 ^ uVar2 >> 6;
    uVar5 = uVar5 >> 8;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  uVar2 = (uVar2 * 9 ^ uVar2 * 9 >> 0xb) & 0x7f;
  puVar1 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff0e28);
  uVar4 = *(undefined8 *)(param_2 + 0x70);
  *puVar1 = *(undefined8 *)(param_1 + 0x18 + (ulong)uVar2 * 8);
  puVar1[1] = uVar4;
  puVar1[2] = param_3;
  (**(code **)(*param_3 + 0x20))(param_3);
  *(undefined8 **)(param_1 + 0x18 + (ulong)uVar2 * 8) = puVar1;
  return;
}

