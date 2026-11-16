// FUN_fffffff0081ec8e0 @ fffffff0081ec8e0 size=56

undefined8 FUN_fffffff0081ec8e0(long param_1,int param_2)

{
  bool bVar1;
  long lVar2;
  
  if (param_2 != 0) {
    LOAcquire();
    LORelease();
    bVar1 = DAT_fffffff00ae233e0 == -1;
    lVar2 = DAT_fffffff00ae233e0;
    DAT_fffffff00ae233e0 = DAT_fffffff00ae233e0 + 1;
    if (bVar1) {
      LOAcquire();
      DAT_fffffff00ae233e0 = 1;
      LORelease();
      lVar2 = 0;
    }
    *(long *)(param_1 + 0x68) = lVar2;
  }
  return 1;
}

