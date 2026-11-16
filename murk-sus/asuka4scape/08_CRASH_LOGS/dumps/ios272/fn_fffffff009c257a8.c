// FUN_fffffff009c257a8 @ fffffff009c257a8 size=136

/* WARNING: Removing unreachable block (ram,0xfffffff009c257f0) */

undefined8 FUN_fffffff009c257a8(long param_1,ulong param_2)

{
  long lVar1;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if ((param_2 & 1) == 0) {
    lVar1 = *(long *)(param_1 + 0x178);
    *(int *)(lVar1 + 0xc) = *(int *)(lVar1 + 0xc) + 1;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x1c;
    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
  return 0;
}

