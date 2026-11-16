// FUN_fffffff0081a1614 @ fffffff0081a1614 size=296

ulong FUN_fffffff0081a1614(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar6 = (ulong)param_3;
  uVar4 = thunk_EXT_FUN_80110000037693ec(param_2,uVar6,"%s %s");
  if (*(int *)(param_1 + 8) == 0) {
    return uVar4;
  }
  uVar5 = (ulong)(param_3 - (int)uVar4);
  uVar2 = uVar5 + (uVar4 & 0xffffffff);
  if (uVar2 >> 0x20 != 0) {
LAB_fffffff0081a1724:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff008214ca8
              ("bounded_array_ref: n + m is larger than the size of any bounded_array_ref");
  }
  if (uVar2 <= uVar6) {
    iVar3 = thunk_EXT_FUN_80110000037693ec(param_2 + (uVar4 & 0xffffffff),uVar5," (");
    uVar1 = iVar3 + (int)uVar4;
    uVar4 = (ulong)(param_3 - uVar1) + (ulong)uVar1;
    if (uVar4 >> 0x20 != 0) goto LAB_fffffff0081a1724;
    if (uVar4 <= uVar6) {
      iVar3 = thunk_EXT_FUN_80110000037693ec(param_2 + (ulong)uVar1,(ulong)(param_3 - uVar1),")");
      return (ulong)(iVar3 + uVar1);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff008214ca8
            (
            "bounded_array_ref: invalid slice provided, the indices are of bounds for the bounded_array_ref"
            );
}

