// FUN_fffffff0081b6330 @ fffffff0081b6330 size=80

void FUN_fffffff0081b6330(long param_1)

{
  if (*(uint *)(*(long *)(param_1 + 8) + 0x10) < 0x100) {
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! FW Ring cfi_index %x out-of-bounds\n");
  return;
}

