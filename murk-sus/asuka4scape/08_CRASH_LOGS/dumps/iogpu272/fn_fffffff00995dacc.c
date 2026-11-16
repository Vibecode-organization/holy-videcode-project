// FUN_fffffff00995dacc @ fffffff00995dacc size=168

long FUN_fffffff00995dacc(long param_1,int param_2,uint param_3)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x48);
  if (uVar5 == *(uint *)(param_1 + 0x4c)) {
    lVar4 = 0;
  }
  else {
    do {
      uVar2 = *(uint *)(param_1 + 0x54);
      uVar3 = 0;
      if (uVar2 != 0) {
        uVar3 = uVar5 / uVar2;
      }
      lVar4 = (ulong)(uVar5 - uVar3 * uVar2) * 8;
      plVar1 = (long *)(*(long *)(param_1 + 0x58) + (long)(int)lVar4);
      if (lVar4 != (int)lVar4) {
        plVar1 = (long *)(*(long *)(param_1 + 0x58) + lVar4 & 0xffffffffffffU | 0x2bad000000000000);
      }
      lVar4 = *plVar1;
    } while (((*(uint *)(lVar4 + 0x84) & 0xffffff00) != param_3 ||
              (char)*(uint *)(lVar4 + 0x84) != param_2) &&
            (((*(int *)(lVar4 + 0x88) == 0xff ||
              ((*(uint *)(lVar4 + 0x88) & 0xffffff00) != param_3 ||
               (char)*(uint *)(lVar4 + 0x88) != param_2)) &&
             (uVar5 = uVar5 + 1, uVar5 != *(uint *)(param_1 + 0x4c)))));
  }
  return lVar4;
}

