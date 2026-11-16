// FUN_fffffff00816b660 @ fffffff00816b660 size=36

void FUN_fffffff00816b660(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  if (param_2 != 0) {
    if (*(long *)(param_2 + 0x20) != 0) {
      param_3 = *(long *)(param_2 + 0x20);
    }
    thunk_EXT_FUN_8011000002977e48(param_4,*(undefined8 *)(param_2 + 0x48),param_3);
    return;
  }
  return;
}

