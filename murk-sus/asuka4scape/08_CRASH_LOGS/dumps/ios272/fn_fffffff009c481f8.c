// FUN_fffffff009c481f8 @ fffffff009c481f8 size=396

bool FUN_fffffff009c481f8
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,uint param_6)

{
  bool bVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  
  iVar2 = (*DAT_fffffff008067b70)();
  if (iVar2 == 0) {
    return false;
  }
  plVar3 = (long *)thunk_EXT_FUN_801100000392f2f0(param_4,0);
  plVar4 = (long *)thunk_EXT_FUN_801100000392ece0(plVar3,0xffffffffffffffff);
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(long **)(param_1 + 0x28) = plVar4;
  if (plVar4 != (long *)0x0) {
    plVar4 = (long *)(**(code **)(*plVar4 + 0x3c8))(plVar4,param_5);
    *(long **)(param_1 + 0x38) = plVar4;
    if (plVar4 != (long *)0x0) {
      *(uint *)(param_1 + 0x58) = param_6 & 0xf00;
      lVar5 = (**(code **)(*plVar4 + 0xb0))();
      *(long *)(param_1 + 0x48) = lVar5;
      lVar5 = thunk_EXT_FUN_801100000397b408(lVar5 + -1,*(undefined8 *)PTR_DAT_fffffff00806ca78,0,0)
      ;
      if (*(long **)(param_1 + 0x30) != (long *)0x0) {
        (**(code **)(**(long **)(param_1 + 0x30) + 0x28))();
      }
      *(long *)(param_1 + 0x30) = lVar5;
      bVar1 = lVar5 != 0;
      goto joined_r0xfffffff009c48348;
    }
  }
  bVar1 = false;
joined_r0xfffffff009c48348:
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return bVar1;
}

