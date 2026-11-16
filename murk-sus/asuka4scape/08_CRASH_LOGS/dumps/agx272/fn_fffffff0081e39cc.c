// FUN_fffffff0081e39cc @ fffffff0081e39cc size=356

long FUN_fffffff0081e39cc(long param_1,uint param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar1 = 0;
  if (param_2 <= *(byte *)(param_1 + 10)) {
    uVar1 = *(byte *)(param_1 + 10) - param_2;
  }
  uVar5 = (ulong)uVar1;
  uVar1 = 0;
  if (param_2 <= *(byte *)(param_1 + 0xb)) {
    uVar1 = *(byte *)(param_1 + 0xb) - param_2;
  }
  uVar6 = (ulong)uVar1;
  if (param_3 != 0) {
    cVar2 = *(char *)(param_1 + 0x11);
    uVar4 = (ulong)*(byte *)(param_1 + 0xe);
    if (*(char *)(param_1 + 0x10) == '\x02' && cVar2 == '\0') {
      lVar3 = 0;
      do {
        lVar3 = lVar3 + ((1L << (uVar6 & 0x3f)) << (uVar6 & 0x3f)) * uVar4;
        uVar1 = 0;
        if ((int)uVar6 != 0) {
          uVar1 = (int)uVar6 - 1;
        }
        uVar6 = (ulong)uVar1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    else if (cVar2 == '\x02') {
      lVar3 = 0;
      do {
        lVar3 = (((1L << (uVar5 & 0x3f)) << (uVar6 & 0x3f)) * uVar4 + 0x7f & 0xffffffffffffff80) +
                lVar3;
        uVar1 = 0;
        if ((int)uVar5 != 0) {
          uVar1 = (int)uVar5 - 1;
        }
        uVar5 = (ulong)uVar1;
        uVar1 = 0;
        if ((int)uVar6 != 0) {
          uVar1 = (int)uVar6 - 1;
        }
        uVar6 = (ulong)uVar1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    else if (cVar2 == '\x03') {
      lVar3 = 0;
      do {
        lVar3 = (((1L << (uVar5 & 0x3f)) << (uVar6 & 0x3f)) * uVar4 + 0x7f & 0xffffffffffffff80) +
                lVar3;
        uVar1 = 0;
        if ((int)uVar5 != 0) {
          uVar1 = (int)uVar5 - 1;
        }
        uVar5 = (ulong)uVar1;
        uVar1 = 0;
        if ((int)uVar6 != 0) {
          uVar1 = (int)uVar6 - 1;
        }
        uVar6 = (ulong)uVar1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    else if (cVar2 == '\x04') {
      lVar3 = 0;
      do {
        lVar3 = (((1L << (uVar5 & 0x3f)) << (uVar6 & 0x3f)) * uVar4 + 0x7f & 0xffffffffffffff80) +
                lVar3;
        uVar1 = 0;
        if ((int)uVar5 != 0) {
          uVar1 = (int)uVar5 - 1;
        }
        uVar5 = (ulong)uVar1;
        uVar1 = 0;
        if ((int)uVar6 != 0) {
          uVar1 = (int)uVar6 - 1;
        }
        uVar6 = (ulong)uVar1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    else {
      lVar3 = 0;
      do {
        lVar3 = lVar3 + ((1L << (uVar5 & 0x3f)) << (uVar6 & 0x3f)) * uVar4;
        uVar1 = 0;
        if ((int)uVar5 != 0) {
          uVar1 = (int)uVar5 - 1;
        }
        uVar5 = (ulong)uVar1;
        uVar1 = 0;
        if ((int)uVar6 != 0) {
          uVar1 = (int)uVar6 - 1;
        }
        uVar6 = (ulong)uVar1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    return lVar3;
  }
  return 0;
}

