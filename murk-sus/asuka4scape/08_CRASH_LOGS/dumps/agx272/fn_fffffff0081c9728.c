// FUN_fffffff0081c9728 @ fffffff0081c9728 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff0081c978c) */

void FUN_fffffff0081c9728(long param_1,undefined4 param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  ulong uStack_38;
  
  lVar2 = thunk_EXT_FUN_8011000003397c88();
  uStack_38 = 0;
  thunk_EXT_FUN_8011000003398268(param_2,&uStack_38);
  uVar1 = uStack_38;
  lVar4 = **(long **)(param_1 + 0x1460);
  (**(code **)(lVar4 + 0x568))(lVar4 + 0x568,*(long **)(param_1 + 0x1460),0x85000000000000,0);
  do {
    if ((*(int **)(param_1 + 0x14b0))[4] == **(int **)(param_1 + 0x14b0)) {
      return;
    }
    lVar4 = thunk_EXT_FUN_8011000003397c88();
    uVar3 = lVar4 - lVar2;
  } while (uVar3 <= uVar1);
  if ((*(int **)(param_1 + 0x14b0))[4] == **(int **)(param_1 + 0x14b0)) {
    return;
  }
  FUN_fffffff008214acc(uVar3);
  FUN_fffffff008214acc(uVar3);
  thunk_EXT_FUN_8011000003a49114
            (
            "AGXk: %s:%d:%s: !!! AGXSecureGart::unmap Timed out waiting for FW to process secure unmap after %llu ns\n"
            );
  return;
}

