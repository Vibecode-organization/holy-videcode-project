// FUN_fffffff009943810 @ fffffff009943810 size=220

undefined4 FUN_fffffff009943810(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (*(int *)(param_1 + 0x50) == 2) {
    lVar3 = param_1 + 0x60;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x58);
  }
  if (*(int *)(param_1 + 0x54) < 1) {
    uVar2 = 0;
    if (*(int *)(param_1 + 0x54) != 0) {
      uVar2 = 0xe00002bd;
    }
  }
  else {
    uVar4 = 0;
    do {
      iVar1 = FUN_fffffff00997f414(*(undefined8 *)(lVar3 + uVar4 * 8),param_2);
      if (iVar1 == 0) break;
      uVar4 = uVar4 + 1;
    } while ((long)uVar4 < (long)*(int *)(param_1 + 0x54));
    if (*(int *)(param_1 + 0x54) == (int)uVar4) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0xe00002bd;
      if (0 < (int)uVar4) {
        uVar5 = uVar4 & 0x7fffffff;
        uVar4 = uVar4 + 1;
        do {
          uVar5 = uVar5 - 1;
          FUN_fffffff00997f598(*(undefined8 *)(lVar3 + uVar5 * 8),param_2);
          uVar4 = uVar4 - 1;
        } while (1 < uVar4);
      }
    }
  }
  return uVar2;
}

