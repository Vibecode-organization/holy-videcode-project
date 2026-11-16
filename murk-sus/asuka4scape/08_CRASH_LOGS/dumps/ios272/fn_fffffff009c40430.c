// FUN_fffffff009c40430 @ fffffff009c40430 size=216

undefined4 FUN_fffffff009c40430(long param_1,long param_2,long *param_3)

{
  undefined4 uVar1;
  int iVar2;
  long *plVar3;
  
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
  uVar1 = 0xe00002bd;
  if (plVar3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x80))(param_3);
    FUN_fffffff009c34d4c(*(undefined8 *)(param_1 + 0xe8),plVar3,param_2 != 0);
    iVar2 = (**(code **)(*plVar3 + 0x30))(plVar3,param_3);
    uVar1 = 0;
    if (iVar2 == 0) {
      uVar1 = 0xe00002bd;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return uVar1;
}

