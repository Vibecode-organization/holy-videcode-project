// FUN_fffffff008210288 @ fffffff008210288 size=68

undefined8 FUN_fffffff008210288(long param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x30 + (param_2 >> 0x21 & 0x40 | 0x30)) +
                   (param_2 >> 0x24 & 7) * 8);
  if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + (param_2 >> 0x19 & 0x7ff) * 8), lVar1 != 0)) {
    return *(undefined8 *)(lVar1 + (param_2 >> 0xe & 0x7ff) * 8);
  }
  return 0;
}

