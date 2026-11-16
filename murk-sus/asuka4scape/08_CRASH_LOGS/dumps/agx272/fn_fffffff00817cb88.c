// FUN_fffffff00817cb88 @ fffffff00817cb88 size=344

void FUN_fffffff00817cb88(long param_1)

{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x520) & 1) == 0) {
    return;
  }
  iVar1 = thunk_EXT_FUN_801100000294780c(*(undefined8 *)(param_1 + 0x148));
  if (iVar1 != 0) {
    (**(code **)(**(long **)(param_1 + 0x4b0) + 0x2a8))(*(long **)(param_1 + 0x4b0),0);
    if (*(long *)(param_1 + 0x11f18) != 0) {
      iVar1 = (**(code **)(**(long **)(param_1 + 0x11ee8) + 0x80))
                        (*(long **)(param_1 + 0x11ee8),3,*(long *)(param_1 + 0x11f18),0);
      *(undefined8 *)(param_1 + 0x11f18) = 0;
      if (iVar1 != 0) goto LAB_fffffff00817cccc;
    }
    if (*(long *)(param_1 + 0x11f08) != 0) {
      iVar1 = (**(code **)(**(long **)(param_1 + 0x11ee8) + 0x80))
                        (*(long **)(param_1 + 0x11ee8),3,*(long *)(param_1 + 0x11f08),0);
      *(undefined8 *)(param_1 + 0x11f08) = 0;
      if (iVar1 != 0) goto LAB_fffffff00817cccc;
    }
    if (*(long *)(param_1 + 0x11f28) != 0) {
      thunk_EXT_FUN_8011000001335f94(*(long *)(param_1 + 0x11f28),1);
      iVar1 = (**(code **)(**(long **)(param_1 + 0x11ee8) + 0x80))
                        (*(long **)(param_1 + 0x11ee8),3,*(undefined8 *)(param_1 + 0x11f28),0);
      *(undefined8 *)(param_1 + 0x11f28) = 0;
      if (iVar1 != 0) goto LAB_fffffff00817cccc;
    }
    if (*(long *)(param_1 + 0x11ef8) != 0) {
      (**(code **)(**(long **)(param_1 + 0x11ee8) + 0x80))
                (*(long **)(param_1 + 0x11ee8),3,*(long *)(param_1 + 0x11ef8),0);
      *(undefined8 *)(param_1 + 0x11ef8) = 0;
    }
  }
LAB_fffffff00817cccc:
  *(undefined1 *)(param_1 + 0x520) = 0;
  return;
}

