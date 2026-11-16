// FUN_fffffff009c34228 @ fffffff009c34228 size=252

void FUN_fffffff009c34228(long param_1,undefined8 param_2)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  undefined8 local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x140));
  do {
    if (*(int *)(param_1 + 0x168) == *(int *)(param_1 + 0x16c)) {
      plVar2 = *(long **)(param_1 + 0x158);
      if (plVar2 == (long *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,param_2);
        uVar3 = thunk_EXT_FUN_8011000003890f30(uVar3,DAT_fffffff008067ad8);
      }
      FUN_fffffff009c16670(&local_30,uVar3);
      thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
      uVar3 = local_30;
      goto LAB_fffffff009c342f8;
    }
    iVar1 = thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x140),param_1 + 0x16c,1);
  } while (iVar1 != 2);
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x140));
  uVar3 = 0;
LAB_fffffff009c342f8:
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_28) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590(uVar3);
  return;
}

