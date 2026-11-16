// FUN_fffffff009943aa8 @ fffffff009943aa8 size=4

/* WARNING: Removing unreachable block (ram,0xfffffff009943de4) */
/* WARNING: Removing unreachable block (ram,0xfffffff009943b88) */

void FUN_fffffff009943aa8(long *param_1,long *param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  int iStack_44;
  
  plVar2 = (long *)thunk_EXT_FUN_80110000038d02e4("SysMem");
  (**(code **)(*param_2 + 0x100))(param_2,"MemoryPool",plVar2);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  uVar3 = (**(code **)(*param_1 + 0x88))(param_1);
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(uVar3,0x40);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"Size",plVar2);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038970c4(*(uint *)(param_1 + 6) & 1);
  (**(code **)(*param_2 + 0x100))(param_2,"Internal",plVar2);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038970c4(*(uint *)(param_1 + 6) >> 1 & 1);
  (**(code **)(*param_2 + 0x100))(param_2,"AlwaysResident",plVar2);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038970c4(*(uint *)(param_1 + 6) >> 5 & 1);
  (**(code **)(*param_2 + 0x100))(param_2,"Virtual",plVar2);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  iStack_44 = 0;
  iVar1 = (**(code **)(*param_1 + 0xa8))(param_1,1,&iStack_44);
  if (iVar1 == 0) {
    plVar2 = (long *)thunk_EXT_FUN_80110000038970c4(iStack_44 - 3U < 2);
    (**(code **)(*param_2 + 0x100))(param_2,"Purgeable",plVar2);
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(param_1[0xe],0x40);
  plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(1);
  (**(code **)(*plVar4 + 0xe8))(plVar4,plVar2);
  (**(code **)(*param_2 + 0x100))(*param_2 + 0x100,param_2,"AllocationIdentifiers",plVar4);
  (**(code **)(*plVar4 + 0x28))(plVar4);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return;
}

