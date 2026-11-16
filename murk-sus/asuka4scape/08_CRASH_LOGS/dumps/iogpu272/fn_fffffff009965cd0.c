// FUN_fffffff009965cd0 @ fffffff009965cd0 size=168

undefined8 FUN_fffffff009965cd0(long param_1,int *param_2)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)FUN_fffffff00994ddb0(*(undefined8 *)(param_1 + 0x48));
  if (plVar2 != (long *)0x0) {
    iVar1 = thunk_FUN_fffffff009944798(*(undefined8 *)(param_1 + 0x80),plVar2);
    if (iVar1 != 0) {
      *param_2 = iVar1;
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return 0;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *param_2 = 0;
  return 0xe00002bd;
}

