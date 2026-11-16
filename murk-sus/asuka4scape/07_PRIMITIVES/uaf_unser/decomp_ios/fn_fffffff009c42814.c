// FUN_fffffff009c42814 @ fffffff009c42814 size=112
// CALLERS:
//   fffffff009c4409c FUN_fffffff009c4405c@fffffff009c4405c
//   fffffff009c3743c FUN_fffffff009c373ec@fffffff009c373ec
//   fffffff009c3ad4c FUN_fffffff009c3ab8c@fffffff009c3ab8c
//   fffffff009c425b0 FUN_fffffff009c4257c@fffffff009c4257c

long FUN_fffffff009c42814(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  FUN_fffffff009c49664(*(undefined8 *)(param_1 + 0x10));
  lVar3 = *(long *)(param_1 + 0x20);
  do {
    lVar1 = lVar3;
    if (lVar1 == 0) break;
    lVar3 = *(long *)(lVar1 + 0x10);
  } while ((*(long *)(lVar1 + 0x28) != param_2) ||
          (uVar2 = FUN_fffffff009c49430(lVar1 + 0x20), (uVar2 & 1) == 0));
  FUN_fffffff009c49674(*(undefined8 *)(param_1 + 0x10));
  return lVar1;
}

