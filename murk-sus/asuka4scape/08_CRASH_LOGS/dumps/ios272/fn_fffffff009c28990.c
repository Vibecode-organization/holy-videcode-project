// FUN_fffffff009c28990 @ fffffff009c28990 size=136

/* WARNING: Removing unreachable block (ram,0xfffffff009c289bc) */

undefined8 FUN_fffffff009c28990(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_2 < 5) {
    lVar3 = param_2 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x300) + (long)(int)lVar3);
    if (lVar3 - (int)lVar3 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x300) + lVar3 & 0xffffffffffffU | 0x2bad000000000000);
    }
    return *puVar1;
  }
  uVar2 = thunk_EXT_FUN_8011000003a49114("\"%s called with invalid index: %lld\" @%s:%d");
  return uVar2;
}

