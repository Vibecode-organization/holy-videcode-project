// FUN_fffffff009c21460 @ fffffff009c21460

/* WARNING: Removing unreachable block (ram,0xfffffff009c214b8) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c21534) */

int FUN_fffffff009c21460(long param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
  if (*(long *)(param_1 + 0x38) == 0 || *(long *)(param_1 + 0x38) == param_2) {
    puVar1 = *(undefined8 **)(param_1 + 0x178);
    iVar2 = (int)((ulong)*(undefined8 *)((long)puVar1 + 0xc) >> 0x20) + 1;
    *(ulong *)((long)puVar1 + 0xc) = CONCAT44(iVar2,(int)*(undefined8 *)((long)puVar1 + 0xc) + 1);
    *(long *)(param_1 + 0x38) = param_2;
    *(short *)(puVar1 + 1) = (short)*(undefined4 *)(param_2 + 0x48);
    *puVar1 = *(undefined8 *)(param_2 + 0x60);
    *(short *)((long)puVar1 + 10) = (short)*(undefined4 *)(param_2 + 0x54);
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) & 0xfffffff7;
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
  }
  else {
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
    iVar2 = *(int *)(*(long *)(param_1 + 0x178) + 0x10) + -1;
  }
  return iVar2;
}

