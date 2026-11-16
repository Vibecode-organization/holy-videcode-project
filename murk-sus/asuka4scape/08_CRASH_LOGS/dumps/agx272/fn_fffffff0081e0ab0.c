// FUN_fffffff0081e0ab0 @ fffffff0081e0ab0 size=112

void FUN_fffffff0081e0ab0(long param_1)

{
  long *plVar1;
  long lVar2;
  
  plVar1 = *(long **)(param_1 + 0x60);
  if (plVar1 == (long *)0x0) {
    lVar2 = thunk_EXT_FUN_801100000297ea14(*(undefined8 *)(param_1 + 0x48),0);
    *(long *)(param_1 + 0x60) = lVar2;
    if (lVar2 == 0) {
      return;
    }
    LOAcquire();
    DAT_fffffff00ae22f48 = DAT_fffffff00ae22f48 + *(long *)(param_1 + 0x30);
    LORelease();
    plVar1 = *(long **)(param_1 + 0x60);
  }
  (**(code **)(*plVar1 + 0x78))();
  return;
}

