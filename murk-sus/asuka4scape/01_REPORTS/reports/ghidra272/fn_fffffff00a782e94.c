// FUN_fffffff00a782e94 @ fffffff00a782e94 size=264

void FUN_fffffff00a782e94(ulong param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x28);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    param_1 = ((long)*(char *)(param_2 + 0x40) & 0xffffU | (ulong)*(byte *)(param_2 + 0x41) << 8) ^
              0x4f71;
  }
  FUN_fffffff00a77c274(param_1,lVar3);
  if (*(long *)(param_2 + 0x18) != -1) {
    if (*(char *)(param_2 + 0x40) == -1) {
      lVar2 = 0x108;
    }
    else {
      if (*(char *)(param_2 + 0x40) != -2) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff00aa4d114("invalid knote %p detach, filter: %d @%s:%d");
      }
      lVar2 = 0x140;
    }
    lVar1 = *(long *)(lVar3 + lVar2);
    if (lVar1 == param_2) {
      *(undefined8 *)(lVar3 + lVar2) = *(undefined8 *)(lVar1 + 0x18);
    }
    else {
      do {
        lVar2 = lVar1;
        lVar1 = *(long *)(lVar2 + 0x18);
      } while (lVar1 != param_2);
      *(undefined8 *)(lVar2 + 0x18) = *(undefined8 *)(lVar1 + 0x18);
    }
  }
  *(long *)(param_2 + 0x28) = 0;
  FUN_fffffff00a779b78(lVar3);
  FUN_fffffff00a77c3d0(lVar3);
  return;
}

