// FUN_fffffff0081bfbb4 @ fffffff0081bfbb4 size=428

/* WARNING: Removing unreachable block (ram,0xfffffff0081bfcd0) */

long * FUN_fffffff0081bfbb4(long param_1)

{
  int iVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  
  plVar3 = (long *)thunk_EXT_FUN_801100000389d0d8(2);
  if (plVar3 != (long *)0x0) {
    iVar1 = *(int *)(*(long *)(param_1 + 0x348) + 0x980);
    plVar4 = (long *)thunk_EXT_FUN_80110000038c6e24(iVar1,0x20);
    if (plVar4 != (long *)0x0) {
      uVar2 = (**(code **)(*plVar3 + 0x100))(plVar3,"count",plVar4);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      if (uVar2 == 0 || iVar1 == 0) {
        if ((uVar2 & 1) != 0) {
          return plVar3;
        }
      }
      else {
        plVar4 = (long *)thunk_EXT_FUN_801100000389a1c8(iVar1 * 0x18);
        if (plVar4 != (long *)0x0) {
          (**(code **)(*plVar4 + 200))(plVar4,*(long *)(param_1 + 0x348) + 0x800,iVar1 * 0x18);
          uVar5 = (**(code **)(*plVar3 + 0x100))(*plVar3 + 0x100,plVar3,"config",plVar4);
          (**(code **)(*plVar4 + 0x28))(plVar4);
          if ((uVar5 & 1) != 0) {
            return plVar3;
          }
        }
      }
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return (long *)0x0;
}

