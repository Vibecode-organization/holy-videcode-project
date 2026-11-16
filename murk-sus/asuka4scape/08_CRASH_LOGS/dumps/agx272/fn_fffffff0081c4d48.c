// FUN_fffffff0081c4d48 @ fffffff0081c4d48 size=256

long * FUN_fffffff0081c4d48(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long local_50;
  ulong uStack_48;
  
  plVar5 = (long *)thunk_EXT_FUN_801100000389a1c8(0x10);
  if (plVar5 != (long *)0x0) {
    uVar1 = **(uint **)(param_1 + 0x368);
    uStack_48 = (ulong)uVar1;
    local_50 = (long)*(int *)(*(long *)(param_1 + 0x2c0) + 0x3b64);
    uVar2 = *(uint *)(*(long *)(param_1 + 0x2c0) + 0x3b68);
    iVar3 = (**(code **)(*plVar5 + 200))(plVar5,&uStack_48,8);
    iVar4 = (**(code **)(*plVar5 + 200))(plVar5,&local_50,8);
    if ((uVar1 == uVar2 && iVar3 != 0) && iVar4 != 0) {
      **(int **)(param_1 + 0x368) = **(int **)(param_1 + 0x368) + 1;
    }
    else {
      (**(code **)(*plVar5 + 0x28))(plVar5);
      plVar5 = (long *)0x0;
    }
  }
  return plVar5;
}

