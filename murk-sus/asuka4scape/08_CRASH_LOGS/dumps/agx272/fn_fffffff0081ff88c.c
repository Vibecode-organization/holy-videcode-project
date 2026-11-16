// FUN_fffffff0081ff88c @ fffffff0081ff88c size=232

long * FUN_fffffff0081ff88c(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  
  plVar4 = *(long **)(param_1 + 0x48);
  uVar3 = *(undefined8 *)(param_1 + 0xd8);
  plVar2 = (long *)(**(code **)(*plVar4 + 0x860))(plVar4);
  if (plVar2 == (long *)0x0) {
    plVar4 = (long *)0x0;
  }
  else {
    iVar1 = (**(code **)(*plVar2 + 0xa8))(plVar2,plVar4,param_2,uVar3);
    if (iVar1 == 0) {
      plVar4 = (long *)0x0;
    }
    else {
      (**(code **)(*plVar2 + 0x20))(plVar2);
      plVar4 = plVar2;
    }
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return plVar4;
}

