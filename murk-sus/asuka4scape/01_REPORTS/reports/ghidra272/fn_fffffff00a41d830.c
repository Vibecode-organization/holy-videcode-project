// FUN_fffffff00a41d830 @ fffffff00a41d830 size=4

uint FUN_fffffff00a41d830(ulong *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 != (ulong *)0x0) {
    if (((*param_1 & 0xfffffffffffffffe) != 0) &&
       (lVar1 = FUN_fffffff00a29b12c(*param_1 & 0xfffffffffffffffe), lVar1 != 0))
    goto LAB_fffffff00a41d860;
  }
  lVar2 = FUN_fffffff00a29b24c();
  lVar1 = *(long *)(lVar2 + 0x18);
  if ((*(long *)(lVar2 + 0x18) == 0) && (lVar1 = DAT_fffffff007c6b250, DAT_fffffff007c6b250 == 0)) {
    return 1;
  }
LAB_fffffff00a41d860:
  return *(uint *)(lVar1 + 0x450) >> 3 & 1;
}

