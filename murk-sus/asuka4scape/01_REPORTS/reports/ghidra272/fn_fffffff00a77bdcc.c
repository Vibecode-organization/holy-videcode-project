// FUN_fffffff00a77bdcc @ fffffff00a77bdcc size=452

void FUN_fffffff00a77bdcc(long param_1)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x28);
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  piVar1 = (int *)(lVar5 + 0x1e0);
  iVar2 = *piVar1;
  *piVar1 = iVar2 + 1;
  if (iVar2 + 0xf0000001U < 0xf0000002) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff00aa61ed0(piVar1);
  }
  lVar4 = tpidr_el1;
  if (*(ulong *)(lVar5 + 8) == 0) {
    *(ulong *)(lVar5 + 8) = (ulong)*(uint *)(lVar4 + 0x4e8);
  }
  else {
    FUN_fffffff00a2262d4(lVar5,lVar4,0);
  }
  *(long *)(lVar5 + 0x1e8) = lVar4;
  if (*(long *)(param_1 + 0x18) != -1) {
    if (*(char *)(param_1 + 0x40) == -1) {
      lVar4 = 0x108;
    }
    else {
      if (*(char *)(param_1 + 0x40) != -2) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("invalid knote %p detach, filter: %d @%s:%d");
      }
      lVar4 = 0x140;
    }
    lVar3 = *(long *)(lVar5 + lVar4);
    if (lVar3 == param_1) {
      *(undefined8 *)(lVar5 + lVar4) = *(undefined8 *)(lVar3 + 0x18);
    }
    else {
      do {
        lVar4 = lVar3;
        lVar3 = *(long *)(lVar4 + 0x18);
      } while (lVar3 != param_1);
      *(undefined8 *)(lVar4 + 0x18) = *(undefined8 *)(lVar3 + 0x18);
    }
  }
  *(long *)(param_1 + 0x28) = 0;
  FUN_fffffff00a779b78(lVar5);
  iVar2 = *(int *)(lVar5 + 0x1e0);
  *(int *)(lVar5 + 0x1e0) = iVar2 + -1;
  LORelease();
  if (iVar2 != 0) {
    if (iVar2 != 1) {
      return;
    }
    FUN_fffffff00a7849f8(lVar5 + 0x10);
    FUN_fffffff00a7849f8(lVar5 + 0x48);
    FUN_fffffff00a7849f8(lVar5 + 0x80);
    FUN_fffffff00a2261c0(lVar5,&DAT_fffffff00ad2489c);
    FUN_fffffff00a29762c(&DAT_fffffff007c790d0,lVar5);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa61ea0();
}

