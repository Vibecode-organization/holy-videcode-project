// FUN_fffffff00994af14 @ fffffff00994af14 size=44

void FUN_fffffff00994af14(undefined4 *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 0;
  *param_1 = 0;
  lVar2 = 0xf;
  do {
    param_1[lVar1 + 1] = 0xff;
    lVar1 = lVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}

