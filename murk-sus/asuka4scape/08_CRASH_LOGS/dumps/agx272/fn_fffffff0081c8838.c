// FUN_fffffff0081c8838 @ fffffff0081c8838 size=824

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0081c8838(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  local_58 = *(long *)PTR_DAT_fffffff007ca61a0;
  uVar1 = thunk_EXT_FUN_801100000389d0d8(1);
  uStack_88 = _UNK_fffffff007114120;
  local_90 = _s_Perf_0_fffffff007114118;
  uStack_78 = _UNK_fffffff007114130;
  uStack_80 = _DAT_fffffff007114128;
  uStack_68 = _UNK_fffffff007114140;
  local_70 = _DAT_fffffff007114138;
  local_60 = DAT_fffffff007114148;
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24
                             (*(undefined4 *)(*(long *)(param_1 + 0x918) + 0x5c4),0x20);
  local_98 = plVar2;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  thunk_EXT_FUN_801100000389d40c(uVar1,"pre_sample_idx",&local_98);
  if (local_98 != (long *)0x0) {
    (**(code **)(*local_98 + 0x28))();
  }
  lVar4 = 0;
  lVar5 = 0x668;
  do {
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24
                               (*(undefined8 *)(*(long *)(param_1 + 0x2c0) + 0x668 + lVar4 * 8),0x40
                               );
    if (plVar2 != (long *)0x0) {
      (**(code **)(*plVar2 + 0x28))(plVar2);
    }
    local_98 = plVar3;
    if (plVar3 != (long *)0x0) {
      (**(code **)(*plVar3 + 0x20))(plVar3);
    }
    thunk_EXT_FUN_801100000389d40c(uVar1,(long)&local_90 + lVar4 * 7,&local_98);
    if (local_98 != (long *)0x0) {
      (**(code **)(*local_98 + 0x28))();
    }
    lVar4 = lVar4 + 1;
    lVar5 = lVar5 + 8;
    plVar2 = plVar3;
  } while (lVar5 != 0x6a8);
  plVar2 = (long *)thunk_EXT_FUN_80110000038c6e24
                             (*(undefined4 *)(*(long *)(param_1 + 0x2c0) + 0x6ac4),0x20);
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  local_98 = plVar2;
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
  }
  thunk_EXT_FUN_801100000389d40c(uVar1,"duration",&local_98);
  if (local_98 != (long *)0x0) {
    (**(code **)(*local_98 + 0x28))();
  }
  plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24
                             (*(undefined4 *)(*(long *)(param_1 + 0x918) + 0x5c4),0x20);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  local_98 = plVar3;
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x20))(plVar3);
  }
  thunk_EXT_FUN_801100000389d40c(uVar1,"post_sample_idx",&local_98);
  if (local_98 != (long *)0x0) {
    (**(code **)(*local_98 + 0x28))();
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_58) {
    return uVar1;
  }
  uVar1 = thunk_EXT_FUN_8011000003a48590();
  return uVar1;
}

