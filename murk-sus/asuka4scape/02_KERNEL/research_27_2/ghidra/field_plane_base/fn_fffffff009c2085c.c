// FUN_fffffff009c2085c @ fffffff009c2085c

/* WARNING: Removing unreachable block (ram,0xfffffff009c208fc) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c208b4) */

undefined4 FUN_fffffff009c2085c(long param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
  lVar3 = *(long *)(param_1 + 0x178);
  if (param_3 != 0) {
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
  }
  uVar2 = 0x1c;
  if (param_2 == 0) {
    uVar2 = 0xc;
  }
  *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | uVar2;
  uVar1 = *(undefined4 *)(lVar3 + 0xc);
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
  return uVar1;
}

