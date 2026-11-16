// FUN_fffffff0081df9c4 @ fffffff0081df9c4 size=196

ulong FUN_fffffff0081df9c4(long param_1,int param_2,ulong param_3)

{
  ushort *puVar1;
  byte bVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  
  bVar2 = *(byte *)(param_1 + 8);
  if (param_2 < 2) {
    if (param_2 == 0) {
      if ((bVar2 & 1) == 0) goto LAB_fffffff0081dfa58;
      lVar5 = *(long *)(param_1 + 0x130);
    }
    else {
      if ((bVar2 & 1) == 0) {
LAB_fffffff0081dfa58:
        uVar4 = thunk_EXT_FUN_8011000003a49114
                          (
                          "AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n"
                          );
        return uVar4;
      }
      lVar5 = *(long *)(param_1 + 0x138);
    }
  }
  else if (param_2 == 2) {
    if ((bVar2 & 1) == 0) goto LAB_fffffff0081dfa58;
    lVar5 = *(long *)(param_1 + 0x140);
  }
  else {
    if ((bVar2 & 1) == 0) goto LAB_fffffff0081dfa58;
    lVar5 = *(long *)(param_1 + 0x148);
  }
  if (lVar5 == 0) {
    uVar4 = 0;
  }
  else {
    lVar3 = (param_3 & 0xffffffff) * 2;
    puVar1 = (ushort *)(lVar5 + (int)lVar3);
    if (lVar3 != (int)lVar3) {
      puVar1 = (ushort *)(lVar5 + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar4 = (ulong)*puVar1;
  }
  return uVar4;
}

