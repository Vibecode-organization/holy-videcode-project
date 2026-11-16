// FUN_fffffff00995e2b8 @ fffffff00995e2b8 size=1400

undefined8 FUN_fffffff00995e2b8(long param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  long *plVar2;
  long *plVar3;
  char *pcVar4;
  long *plVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  long lVar9;
  long *local_58;
  
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x18),0x20);
  if (plVar2 == (long *)0x0) {
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x1c),0x20);
  }
  else {
    local_58 = plVar2;
    (**(code **)(*plVar2 + 0x20))();
    thunk_EXT_FUN_801100000389d40c(param_2,"finished",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x1c),0x20);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (plVar3 == (long *)0x0) {
    plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x20),0x20);
  }
  else {
    local_58 = plVar3;
    (**(code **)(*plVar3 + 0x20))(plVar3);
    thunk_EXT_FUN_801100000389d40c(param_2,"submitted",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x20),0x20);
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (plVar2 == (long *)0x0) {
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x24),0x20);
  }
  else {
    local_58 = plVar2;
    (**(code **)(*plVar2 + 0x20))(plVar2);
    thunk_EXT_FUN_801100000389d40c(param_2,"added",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined4 *)(param_1 + 0x24),0x20);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)0x0;
  }
  else {
    local_58 = plVar3;
    (**(code **)(*plVar3 + 0x20))(plVar3);
    thunk_EXT_FUN_801100000389d40c(param_2,"id",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
  }
  if (*(uint *)(param_1 + 0x28) < 4) {
    lVar9 = (ulong)*(uint *)(param_1 + 0x28) * 8;
    puVar1 = (undefined8 *)(&DAT_fffffff007fecdb8 + (int)lVar9);
    if (lVar9 - (int)lVar9 != 0) {
      puVar1 = (undefined8 *)
               ((ulong)(&DAT_fffffff007fecdb8 + lVar9) & 0xffffffffffff | 0x2bad000000000000);
    }
    pcVar4 = (char *)*puVar1;
  }
  else {
    pcVar4 = "Unknown";
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038ce200(pcVar4);
  local_58 = plVar2;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  thunk_EXT_FUN_801100000389d40c(param_2,"state",&local_58);
  if (local_58 != (long *)0x0) {
    (**(code **)(*local_58 + 0x28))();
  }
  plVar5 = (long *)thunk_EXT_FUN_80110000038970c4(*(byte *)(param_1 + 0xb0) & 1);
  local_58 = plVar5;
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x20))(plVar5);
  }
  thunk_EXT_FUN_801100000389d40c(param_2,"aborted",&local_58);
  if (local_58 != (long *)0x0) {
    (**(code **)(*local_58 + 0x28))();
  }
  uVar6 = FUN_fffffff00994b9f8(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x148),param_1 + 0x30);
  if ((uVar6 & 1) == 0) {
    plVar7 = (long *)thunk_EXT_FUN_80110000038961f4(0xf);
    plVar8 = plVar7;
    if (plVar7 != (long *)0x0) {
      FUN_fffffff00995e1c0(plVar7,param_1 + 0x30);
      local_58 = plVar7;
      (**(code **)(*plVar7 + 0x20))(plVar7);
      plVar8 = local_58;
    }
    local_58 = plVar8;
    thunk_EXT_FUN_801100000389d40c(param_2,"barrier",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    if (plVar7 != (long *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
  }
  plVar8 = (long *)thunk_EXT_FUN_80110000038961f4(0xf);
  if (plVar8 != (long *)0x0) {
    FUN_fffffff00995e1c0(plVar8,param_1 + 0x70);
    local_58 = plVar8;
    (**(code **)(*plVar8 + 0x20))(plVar8);
    thunk_EXT_FUN_801100000389d40c(param_2,"submit",&local_58);
    if (local_58 != (long *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    (**(code **)(*plVar8 + 0x28))(plVar8);
  }
  if (plVar5 != (long *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return 1;
}

