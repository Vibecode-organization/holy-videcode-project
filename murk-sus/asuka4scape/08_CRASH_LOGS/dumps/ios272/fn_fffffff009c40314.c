// FUN_fffffff009c40314 @ fffffff009c40314 size=148

bool FUN_fffffff009c40314(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = param_2[0xc];
  lVar4 = *(long *)(param_1 + 0x28);
  if (lVar3 == lVar4) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x20) + 8);
    plVar2 = *(long **)(lVar1 + 0x28);
    *(long **)(lVar1 + 0x28) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  return lVar3 == lVar4;
}

