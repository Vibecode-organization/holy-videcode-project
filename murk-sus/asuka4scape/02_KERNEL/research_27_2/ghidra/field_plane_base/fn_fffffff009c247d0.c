// FUN_fffffff009c247d0 @ fffffff009c247d0

/* WARNING: Removing unreachable block (ram,0xfffffff009c24818) */

undefined8 FUN_fffffff009c247d0(long param_1,int param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xe00002c7;
  if ((param_2 != 0) && ((*(uint *)(param_1 + 0x3d0) >> 0xc & 1) != 0)) {
    uVar1 = 0;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0x200;
    *(char *)(*(long *)(param_1 + 0x178) + 0x14) = (char)param_2;
  }
  return uVar1;
}

