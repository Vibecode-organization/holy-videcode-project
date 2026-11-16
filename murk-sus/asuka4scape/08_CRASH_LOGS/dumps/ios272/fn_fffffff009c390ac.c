// FUN_fffffff009c390ac @ fffffff009c390ac size=72

undefined8 FUN_fffffff009c390ac(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 0x38);
  if (uVar1 < 0x200) {
    if (*(long *)(param_3 + 0x40) != 0) {
      return 0xe00002bd;
    }
    if ((*(long *)(param_3 + 0x30) != 0 && uVar1 != 0) &&
       (*(char *)(*(long *)(param_3 + 0x30) + (ulong)(uVar1 - 1)) == '\0')) {
      thunk_EXT_FUN_8011000003a132c0("%.512s");
      return 0;
    }
  }
  return 0xe00002c2;
}

