// FUN_fffffff009c2892c @ fffffff009c2892c size=100

/* WARNING: Removing unreachable block (ram,0xfffffff009c28960) */

undefined8 FUN_fffffff009c2892c(long param_1,ulong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  long lVar2;
  
  if (param_2 < 5) {
    lVar2 = param_2 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x300) + (long)(int)lVar2);
    if (lVar2 - (int)lVar2 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x300) + lVar2 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = param_3;
    return 0;
  }
  return 0xe00002c2;
}

