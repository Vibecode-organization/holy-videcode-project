// FUN_fffffff009c172ec @ fffffff009c172ec size=312

/* WARNING: Removing unreachable block (ram,0xfffffff009c17378) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c173b4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c17330) */

undefined8 FUN_fffffff009c172ec(long param_1,ulong param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 1;
  if (**(ulong **)(param_1 + 0x20) < param_2) {
    LOAcquire();
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    LORelease();
    do {
      if (param_2 <= **(ulong **)(param_1 + 0x20)) {
LAB_fffffff009c17400:
        uVar2 = 1;
        goto LAB_fffffff009c17404;
      }
      iVar1 = thunk_EXT_FUN_8011000003243438(param_1,1,param_3);
      if (param_2 <= **(ulong **)(param_1 + 0x20)) {
        thunk_EXT_FUN_8011000003246024(param_1,0,0);
        goto LAB_fffffff009c17400;
      }
      if (iVar1 == -1) {
        iVar1 = thunk_EXT_FUN_8011000003247bfc(0);
      }
      else if (iVar1 == 0) goto LAB_fffffff009c17400;
    } while (1 < iVar1 - 1U);
    uVar2 = 0;
LAB_fffffff009c17404:
    LOAcquire();
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    LORelease();
  }
  return uVar2;
}

