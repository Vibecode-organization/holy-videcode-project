// FUN_fffffff0081b63d0 @ fffffff0081b63d0 size=80

void FUN_fffffff0081b63d0(long param_1)

{
  if (**(uint **)(param_1 + 8) < 0x100) {
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! FW Ring read_index %x out-of-bounds\n");
  return;
}

