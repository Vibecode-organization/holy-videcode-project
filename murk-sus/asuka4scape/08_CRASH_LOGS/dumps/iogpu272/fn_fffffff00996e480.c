// FUN_fffffff00996e480 @ fffffff00996e480 size=100

void FUN_fffffff00996e480(long param_1,undefined8 param_2)

{
  long lVar1;
  
  if (0 < *(int *)(param_1 + 0x30)) {
    lVar1 = 0;
    do {
      FUN_fffffff00997b558(param_2,*(undefined8 *)(*(long *)(param_1 + 0x28) + lVar1 * 8));
      lVar1 = lVar1 + 1;
    } while (lVar1 < *(int *)(param_1 + 0x30));
  }
  return;
}

