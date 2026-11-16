// FUN_fffffff009c24784 @ fffffff009c24784 size=76

/* WARNING: Removing unreachable block (ram,0xfffffff009c247c4) */

void FUN_fffffff009c24784(long param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = 0x200;
  if (param_2 == 0) {
    uVar1 = 0;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffdff | uVar1;
  *(char *)(*(long *)(param_1 + 0x178) + 0x14) = (char)param_2;
  return;
}

