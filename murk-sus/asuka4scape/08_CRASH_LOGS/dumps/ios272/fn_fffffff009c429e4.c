// FUN_fffffff009c429e4 @ fffffff009c429e4 size=868

undefined8 FUN_fffffff009c429e4(long param_1,long *param_2)

{
  bool bVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  long *local_70;
  long local_68;
  
  local_68 = *(long *)PTR_DAT_fffffff00806ca40;
  (**(code **)(**(long **)(param_1 + 0x28) + 0x90))();
  plVar2 = (long *)thunk_EXT_FUN_80110000038961f4();
  bVar1 = plVar2 != (long *)0x0;
  if (plVar2 != (long *)0x0) {
    local_70 = (long *)0x0;
    thunk_EXT_FUN_80110000032db760(*(undefined8 *)(param_1 + 0x20),&local_70);
    local_70 = (long *)thunk_EXT_FUN_80110000038c6e24(local_70,0x40);
    thunk_EXT_FUN_801100000389d40c(param_2,"Descriptor address",&local_70);
    if (local_70 != (long *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
    local_70 = (long *)thunk_EXT_FUN_80110000038c6e24(*(undefined8 *)(param_1 + 0x10),0x40);
    thunk_EXT_FUN_801100000389d40c(param_2,"Pool Id",&local_70);
    if (local_70 != (long *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
  }
  plVar3 = (long *)thunk_EXT_FUN_8011000003898a6c(*(undefined8 *)(param_1 + 0x28));
  if (plVar3 == (long *)0x0) {
    if (plVar2 != (long *)0x0) goto LAB_fffffff009c42c5c;
  }
  else {
    plVar7 = (long *)0x0;
    while( true ) {
      uVar4 = (**(code **)(*plVar3 + 0x88))(plVar3);
      plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,&DAT_fffffff00af48458);
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))(plVar5);
      }
      if (plVar7 != (long *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
      if (plVar5 == (long *)0x0) break;
      plVar6 = (long *)thunk_EXT_FUN_801100000389d0d8(1);
      bVar1 = plVar6 != (long *)0x0;
      plVar7 = plVar5;
      if (plVar6 != (long *)0x0) {
        FUN_fffffff009c42d48(plVar5,plVar6);
        local_70 = plVar6;
        (**(code **)(*plVar6 + 0x20))(plVar6);
        thunk_EXT_FUN_80110000038963f0(plVar2,&local_70);
        if (local_70 != (long *)0x0) {
          (**(code **)(*local_70 + 0x28))();
        }
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
    if (bVar1) {
LAB_fffffff009c42c5c:
      local_70 = plVar2;
      if (plVar2 != (long *)0x0) {
        (**(code **)(*plVar2 + 0x20))(plVar2);
      }
      thunk_EXT_FUN_801100000389d40c(param_2,"Components",&local_70);
      if (local_70 != (long *)0x0) {
        (**(code **)(*local_70 + 0x28))();
      }
      uVar4 = 1;
      goto joined_r0xfffffff009c42c50;
    }
  }
  uVar4 = 0;
joined_r0xfffffff009c42c50:
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_68) {
    return uVar4;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

