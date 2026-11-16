// FUN_fffffff009c279f0 @ fffffff009c279f0 size=504

void FUN_fffffff009c279f0(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long *local_50;
  long local_48;
  
  local_48 = *(long *)PTR_DAT_fffffff00806ca40;
  plVar3 = *(long **)(param_2 + 0x18);
  if (plVar3 == (long *)0x0) goto LAB_fffffff009c27a54;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
  if (((*(byte *)(param_2 + 0x53) & 1) == 0) && (*(int *)(param_2 + 0x4c) == 0)) {
    lVar2 = *(long *)(param_2 + 0x60);
    while ((lVar2 = **(long **)(lVar2 + 8), lVar2 != 0 && (*(int *)(lVar2 + 0x4c) == 0))) {
      if ((((*(byte *)(param_2 + 0x52) & 1) == 0) ||
          ((*(int *)(param_2 + 0x20) == 0 || (*(int *)(param_2 + 0x20) != *(int *)(lVar2 + 0x20)))))
         && ((*(int *)(param_2 + 0x24) != 1 || (*(int *)(lVar2 + 0x24) != 1))))
      goto LAB_fffffff009c27afc;
      lVar2 = *(long *)(lVar2 + 0x60);
    }
    goto LAB_fffffff009c27b6c;
  }
  goto LAB_fffffff009c27a4c;
LAB_fffffff009c27afc:
  do {
    plVar1 = *(long **)(lVar2 + 0x18);
    if (plVar1 != plVar3) {
      local_50 = plVar1;
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x20))();
      }
      thunk_EXT_FUN_80110000038cceec(param_3,&local_50);
      if (local_50 != (long *)0x0) {
        (**(code **)(*local_50 + 0x28))();
      }
    }
    lVar2 = **(long **)(*(long *)(lVar2 + 0x60) + 8);
  } while (lVar2 != 0);
LAB_fffffff009c27b6c:
  lVar2 = *(long *)(param_1 + 0x248);
  while( true ) {
    lVar2 = **(long **)(lVar2 + 8);
    if (lVar2 == 0) break;
    plVar1 = *(long **)(lVar2 + 0x18);
    if (plVar1 != plVar3) {
      local_50 = plVar1;
      if (plVar1 != (long *)0x0) {
        (**(code **)(*plVar1 + 0x20))();
      }
      thunk_EXT_FUN_80110000038cceec(param_3,&local_50);
      if (local_50 != (long *)0x0) {
        (**(code **)(*local_50 + 0x28))();
      }
    }
    lVar2 = *(long *)(lVar2 + 0x60);
  }
LAB_fffffff009c27a4c:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
LAB_fffffff009c27a54:
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x28))(param_3);
  }
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_48) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

