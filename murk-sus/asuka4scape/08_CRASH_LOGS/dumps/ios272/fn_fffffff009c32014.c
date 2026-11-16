// FUN_fffffff009c32014 @ fffffff009c32014 size=572

void FUN_fffffff009c32014(long *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  long *plVar4;
  undefined1 *local_30;
  long local_28;
  
  local_28 = *(long *)PTR_DAT_fffffff00806ca40;
  local_30 = &DAT_aaaaaaaaaaaaaaaa;
  thunk_EXT_FUN_8011000003204ed8(0x7d,1000000,&local_30);
LAB_fffffff009c32058:
  do {
    thunk_EXT_FUN_80110000032222a8(param_1[0x3e]);
    iVar1 = (**(code **)(*(long *)param_1[0x3f] + 0x90))();
    if ((iVar1 == 0) ||
       (puVar3 = (undefined1 *)thunk_EXT_FUN_8011000003397c88(), local_30 <= puVar3)) {
      iVar1 = (**(code **)(*(long *)param_1[0x3f] + 0x90))();
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x41) = 0;
      }
      else {
        (**(code **)(*param_1 + 0x20))(param_1);
        thunk_EXT_FUN_8011000003277760(param_1[0x40]);
      }
      thunk_EXT_FUN_8011000003222de0(param_1[0x3e]);
      (**(code **)(*param_1 + 0x28))(param_1);
      if (*(long *)PTR_DAT_fffffff00806ca40 != local_28) {
        thunk_EXT_FUN_8011000003a48590();
        return;
      }
      return;
    }
    plVar4 = (long *)(**(code **)(*(long *)param_1[0x3f] + 0x118))((long *)param_1[0x3f],0);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x20))(plVar4);
    }
    (**(code **)(*(long *)param_1[0x3f] + 0x108))((long *)param_1[0x3f],0);
    if ((param_1[0x42] != 0) &&
       (uVar2 = (**(code **)(*(long *)param_1[0x3f] + 0x90))(), uVar2 < 0x80)) {
      thunk_EXT_FUN_80110000038ff08c(param_1[0x3e],param_1 + 0x3f,0);
    }
    thunk_EXT_FUN_8011000003222de0(param_1[0x3e]);
    FUN_fffffff009c233e4(plVar4);
    iVar1 = FUN_fffffff009c23440(plVar4);
    if (iVar1 == 0) goto LAB_fffffff009c32178;
  } while (plVar4 == (long *)0x0);
  goto LAB_fffffff009c32184;
LAB_fffffff009c32178:
  FUN_fffffff009c2344c(plVar4);
  if (plVar4 != (long *)0x0) {
LAB_fffffff009c32184:
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  goto LAB_fffffff009c32058;
}

