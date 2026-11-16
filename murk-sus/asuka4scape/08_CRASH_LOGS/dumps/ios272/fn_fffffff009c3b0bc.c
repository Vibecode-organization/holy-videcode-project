// FUN_fffffff009c3b0bc @ fffffff009c3b0bc size=388

void FUN_fffffff009c3b0bc(long param_1,int param_2)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  long *local_40;
  long local_38;
  
  local_38 = *(long *)PTR_DAT_fffffff00806ca40;
  local_40 = (long *)0x0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xd8));
  iVar2 = (**(code **)(**(long **)(param_1 + 0x140) + 0x90))();
  if (iVar2 != 0) {
    iVar5 = 0;
    do {
      lVar3 = (**(code **)(**(long **)(param_1 + 0x140) + 0x118))(*(long **)(param_1 + 0x140),iVar5)
      ;
      if (*(int *)(lVar3 + 0x38) == param_2) {
        FUN_fffffff009c16670(&local_40,lVar3);
        plVar1 = local_40;
        if (local_40 != (long *)0x0) {
          (**(code **)(**(long **)(param_1 + 0x140) + 0x108))(*(long **)(param_1 + 0x140),iVar5);
          if ((*(byte *)(plVar1 + 0xe) & 1) != 0) {
            *(int *)(param_1 + 0x128) = *(int *)(param_1 + 0x128) + -1;
          }
          *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + -1;
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
          (**(code **)(*plVar1 + 0x28))(plVar1);
          uVar4 = 0;
          goto LAB_fffffff009c3b210;
        }
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar2 != iVar5);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xd8));
  uVar4 = 0xe00002c2;
LAB_fffffff009c3b210:
  if (*(long *)PTR_DAT_fffffff00806ca40 != local_38) {
    thunk_EXT_FUN_8011000003a48590(uVar4);
    return;
  }
  return;
}

