// FUN_fffffff009963288 @ fffffff009963288 size=180

/* WARNING: Removing unreachable block (ram,0xfffffff00996330c) */

void FUN_fffffff009963288(long param_1)

{
  long *plVar1;
  long local_28;
  
  if (*(long *)(param_1 + 0xd8) == 0) {
    plVar1 = (long *)FUN_fffffff0099631a4(param_1,&local_28,0);
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 0x28))();
      *(long *)(param_1 + 0xd8) = local_28;
      (**(code **)(**(long **)(param_1 + 200) + 0x130))
                (*(long **)(param_1 + 200),*(long *)(param_1 + 0xe0) + local_28);
    }
    return;
  }
  return;
}

