// FUN_fffffff008167e08 @ fffffff008167e08 size=744

void FUN_fffffff008167e08(long param_1,int param_2)

{
  int iVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  
  if ((param_2 != 0) && ((*(byte *)(param_1 + 0x520) & 1) != 0)) {
    *(undefined1 *)(param_1 + 0x520) = 0;
    (**(code **)(**(long **)(param_1 + 0x518) + 0x138))();
  }
  if ((*(byte *)(param_1 + 0x65d) & 1) != 0) {
    if (((*(byte *)(param_1 + 0x531) & 1) != 0) && (*(char *)(param_1 + 0x115c1) == '\x02')) {
      (**(code **)(**(long **)(param_1 + 0x4b0) + 0x298))(*(long **)(param_1 + 0x4b0),1);
      *(char *)(param_1 + 0x115c1) = '\x01';
      if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930c0c,0,0,0,0,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
      }
    }
    if (param_2 == 0) {
      if ((*(byte *)(param_1 + 0x578) & 1) == 0) {
        return;
      }
      iVar1 = thunk_EXT_FUN_8011000002946de4(*(undefined8 *)(param_1 + 0x148));
      if (iVar1 == 0) {
        return;
      }
      if ((*(byte *)(param_1 + 0x531) & 1) == 0) {
        return;
      }
      if ((*(byte *)(param_1 + 0x530) & 1) != 0) {
        return;
      }
      *(undefined1 *)(param_1 + 0x530) = 1;
      (**(code **)(**(long **)(param_1 + 0x528) + 0xf0))
                (*(long **)(param_1 + 0x528),*(undefined1 *)(param_1 + 0x65c));
      return;
    }
    if ((*(byte *)(param_1 + 0x530) & 1) != 0) {
      (**(code **)(**(long **)(param_1 + 0x528) + 0x138))();
      *(undefined1 *)(param_1 + 0x530) = 0;
    }
  }
  plVar2 = *(long **)(param_1 + 0x4b0);
  if (param_2 == 0) {
    return;
  }
  if ((*(byte *)((long)plVar2 + 0x292) & 1) != 0) {
    return;
  }
  (**(code **)(*plVar2 + 0x2a8))(plVar2,1);
  plVar2 = (long *)(param_1 + 0x11ee8);
  plVar3 = (long *)*plVar2;
  if (plVar3 == (long *)0x0) {
    return;
  }
  plVar4 = (long *)(param_1 + 0x11ef8);
  if (*plVar4 == 0) {
LAB_fffffff008167f94:
    iVar1 = (**(code **)(*plVar3 + 0x80))(plVar3,4,*(undefined8 *)(param_1 + 0x11ef0),plVar4);
    if (iVar1 == 0) goto LAB_fffffff008167fc4;
    *plVar4 = 0;
    plVar3 = (long *)*plVar2;
  }
  else {
    iVar1 = thunk_EXT_FUN_8011000001335e8c(*plVar4);
    if (iVar1 == 0) {
      plVar3 = (long *)*plVar2;
      goto LAB_fffffff008167f94;
    }
LAB_fffffff008167fc4:
    plVar3 = (long *)*plVar2;
  }
  if (plVar3 == (long *)0x0) {
    return;
  }
  plVar4 = (long *)(param_1 + 0x11f08);
  if (*plVar4 == 0) {
LAB_fffffff008167fe8:
    iVar1 = (**(code **)(*plVar3 + 0x80))(plVar3,4,*(undefined8 *)(param_1 + 0x11f00),plVar4);
    if (iVar1 != 0) goto LAB_fffffff00816806c;
  }
  else {
    iVar1 = thunk_EXT_FUN_8011000001335e8c(*plVar4);
    if (iVar1 == 0) {
      plVar3 = (long *)*plVar2;
      goto LAB_fffffff008167fe8;
    }
  }
  plVar3 = (long *)*plVar2;
  if (plVar3 == (long *)0x0) {
    return;
  }
  plVar4 = (long *)(param_1 + 0x11f28);
  if (*plVar4 != 0) {
    iVar1 = thunk_EXT_FUN_8011000001335e8c(*plVar4);
    if (iVar1 != 0) {
      return;
    }
    plVar3 = (long *)*plVar2;
  }
  iVar1 = (**(code **)(*plVar3 + 0x80))(plVar3,4,*(undefined8 *)(param_1 + 0x11f20),plVar4);
  if (iVar1 == 0) {
    return;
  }
LAB_fffffff00816806c:
  *plVar4 = 0;
  return;
}

