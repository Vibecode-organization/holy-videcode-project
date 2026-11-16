// FUN_fffffff00996fe3c @ fffffff00996fe3c size=128

void FUN_fffffff00996fe3c(long param_1)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 0x18);
  lVar4 = *(long *)(param_1 + 0x20);
  if (lVar2 != 0 && lVar4 != 0) {
    lVar5 = 0;
    do {
      piVar1 = (int *)(*(long *)(lVar2 + lVar5 * 8) + 0xc);
      iVar3 = *piVar1;
      *piVar1 = iVar3 + -1;
      LORelease();
      if (iVar3 == 1) {
        FUN_fffffff0099836b0();
      }
      *(undefined8 *)(lVar2 + lVar5 * 8) = 0;
      lVar5 = lVar5 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  return;
}

