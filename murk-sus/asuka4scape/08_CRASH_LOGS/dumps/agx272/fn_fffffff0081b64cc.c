// FUN_fffffff0081b64cc @ fffffff0081b64cc size=80

void FUN_fffffff0081b64cc(long param_1)

{
  if (*(uint *)(*(long *)(param_1 + 8) + 0x20) < 0x100) {
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! FW Ring write_index %x out-of-bounds\n");
  return;
}

