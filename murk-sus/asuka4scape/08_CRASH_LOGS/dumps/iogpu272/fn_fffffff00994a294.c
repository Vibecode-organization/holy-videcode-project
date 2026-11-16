// FUN_fffffff00994a294 @ fffffff00994a294 size=104

undefined * FUN_fffffff00994a294(long param_1,long *param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  
  if (param_3 < 0xe) {
    *param_2 = param_1;
    lVar4 = (ulong)param_3 * 0x18;
    iVar3 = (int)lVar4;
    puVar2 = &UNK_fffffff007feadd0 + iVar3;
    if (lVar4 - iVar3 != 0) {
      puVar2 = (undefined *)
               ((ulong)(&UNK_fffffff007feadd0 + lVar4) & 0xffffffffffff | 0x2bad000000000000);
    }
    puVar1 = &UNK_fffffff007feac80 + iVar3;
    if (lVar4 - iVar3 != 0) {
      puVar1 = (undefined *)
               ((ulong)(&UNK_fffffff007feac80 + lVar4) & 0xffffffffffff | 0x2bad000000000000);
    }
    if ((*(byte *)(param_1 + 0x103) & 1) == 0) {
      puVar2 = puVar1;
    }
    return puVar2;
  }
  return (undefined *)0x0;
}

