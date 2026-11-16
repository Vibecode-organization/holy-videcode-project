// FUN_fffffff009c32718 @ fffffff009c32718 size=124

void FUN_fffffff009c32718(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = param_1[1];
  puVar1 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff00806b530);
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = 0x100;
    if ((*(byte *)*param_1 & 1) == 0) {
      uVar2 = 0x400;
    }
    *(undefined4 *)(puVar1 + 2) = uVar2;
    *(undefined4 *)((long)puVar1 + 0x14) = param_3;
    *(int *)(lVar3 + 0x168) = *(int *)(lVar3 + 0x168) + 1;
    *puVar1 = *(undefined8 *)(lVar3 + 0x160);
    puVar1[1] = param_2;
    *(undefined8 **)(lVar3 + 0x160) = puVar1;
  }
  return;
}

