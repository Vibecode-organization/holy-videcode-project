// FUN_fffffff009c3ee40 @ fffffff009c3ee40 size=108

undefined * FUN_fffffff009c3ee40(long param_1,long *param_2,uint param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  
  if (param_3 < 0xd) {
    *param_2 = param_1;
    lVar4 = (ulong)param_3 * 0x18;
    iVar3 = (int)lVar4;
    puVar2 = &UNK_fffffff008069e50 + iVar3;
    if (lVar4 - iVar3 != 0) {
      puVar2 = (undefined *)
               ((ulong)(&UNK_fffffff008069e50 + lVar4) & 0xffffffffffff | 0x2bad000000000000);
    }
    puVar1 = &UNK_fffffff008069f88 + iVar3;
    if (lVar4 - iVar3 != 0) {
      puVar1 = (undefined *)
               ((ulong)(&UNK_fffffff008069f88 + lVar4) & 0xffffffffffff | 0x2bad000000000000);
    }
    if ((*(byte *)(param_1 + 0x127) & 1) != 0) {
      puVar2 = puVar1;
    }
    return puVar2;
  }
  return (undefined *)0x0;
}

