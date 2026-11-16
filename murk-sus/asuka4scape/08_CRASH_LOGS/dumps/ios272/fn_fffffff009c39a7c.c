// FUN_fffffff009c39a7c @ fffffff009c39a7c size=352

undefined8 FUN_fffffff009c39a7c(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long *plVar2;
  ulong *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong local_58;
  uint local_4c;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  uVar4 = 0xe00002c2;
  lVar5 = *(long *)(param_3 + 0x30);
  iVar1 = *(int *)(param_3 + 0x38);
  local_4c = 0;
  local_58 = 0;
  plVar2 = *(long **)(param_3 + 0x40);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0x0;
  }
  else {
    plVar2 = (long *)(**(code **)(*plVar2 + 0xe8))(plVar2,0x1000);
    if (plVar2 == (long *)0x0) {
      uVar4 = 0xe00002c8;
      goto LAB_fffffff009c39ba4;
    }
    lVar5 = (**(code **)(*plVar2 + 0x78))();
    iVar1 = (**(code **)(**(long **)(param_3 + 0x40) + 0xb0))();
  }
  if (lVar5 != 0 && iVar1 != 0) {
    uVar4 = FUN_fffffff009c3e384(param_1,&local_4c,&local_58,lVar5);
    puVar3 = *(ulong **)(param_3 + 0x48);
    *puVar3 = (ulong)local_4c;
    puVar3[1] = local_58;
  }
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
LAB_fffffff009c39ba4:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return uVar4;
  }
  uVar4 = thunk_EXT_FUN_8011000003a48590();
  return uVar4;
}

