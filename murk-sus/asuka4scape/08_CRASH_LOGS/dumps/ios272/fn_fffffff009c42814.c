// FUN_fffffff009c42814 @ fffffff009c42814 size=112

long FUN_fffffff009c42814(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  thunk_EXT_FUN_8011000003224180(*(undefined8 *)(param_1 + 0x10));
  lVar3 = *(long *)(param_1 + 0x20);
  do {
    lVar1 = lVar3;
    if (lVar1 == 0) break;
    lVar3 = *(long *)(lVar1 + 0x10);
  } while ((*(long *)(lVar1 + 0x28) != param_2) ||
          (uVar2 = FUN_fffffff009c49430(lVar1 + 0x20), (uVar2 & 1) == 0));
  thunk_EXT_FUN_8011000003224d30(*(undefined8 *)(param_1 + 0x10));
  return lVar1;
}

