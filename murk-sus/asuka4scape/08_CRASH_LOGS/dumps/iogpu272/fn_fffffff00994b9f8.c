// FUN_fffffff00994b9f8 @ fffffff00994b9f8 size=80

void FUN_fffffff00994b9f8(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  iVar1 = FUN_fffffff00994b4ec();
  if (iVar1 != 0) {
    lVar2 = 0;
    *param_2 = 0;
    lVar3 = 0xf;
    do {
      param_2[lVar2 + 1] = 0xff;
      lVar2 = lVar2 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  return;
}

