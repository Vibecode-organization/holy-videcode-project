// FUN_fffffff009c269a8 @ fffffff009c269a8 size=72

void FUN_fffffff009c269a8(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = thunk_EXT_FUN_8011000003397c88();
  if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
    if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
      return;
    }
    lVar2 = 0x330;
  }
  else {
    lVar2 = 0x338;
  }
  *(undefined8 *)(param_1 + lVar2) = uVar1;
  return;
}

