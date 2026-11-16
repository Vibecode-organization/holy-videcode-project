// FUN_fffffff009c2aa08 @ fffffff009c2aa08

/* WARNING: Removing unreachable block (ram,0xfffffff009c2aacc) */

void FUN_fffffff009c2aa08(long param_1,long *param_2)

{
  byte bVar1;
  long *plVar2;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  thunk_FUN_fffffff00a2262a8(*(ulong *)(param_1 + 0x50));
  plVar2 = *(long **)(param_1 + 0x3c8);
  local_40 = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  thunk_FUN_fffffff00a89a3f0(plVar2,&local_40);
  if (local_40 != (long *)0x0) {
    (**(code **)(*local_40 + 0x28))();
  }
  bVar1 = FUN_fffffff009c48d20((long)param_2);
  if (bVar1 != 0) {
    *(int *)(*(long *)(param_1 + 0x178) + 0xc) = *(int *)(*(long *)(param_1 + 0x178) + 0xc) + 1;
    *(uint *)(param_1 + 0x3d0) = *(uint *)(param_1 + 0x3d0) | 0xc;
  }
  thunk_FUN_fffffff00a226de0(*(ulong *)(param_1 + 0x50));
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return;
}

