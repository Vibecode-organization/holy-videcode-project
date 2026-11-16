// FUN_fffffff00995acc0 @ fffffff00995acc0 size=4

void FUN_fffffff00995acc0(long param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long lStack_50;
  undefined1 *puStack_48;
  
  if (DAT_fffffff00af227e8 != 0) {
    thunk_EXT_FUN_80110000036da494(0x85180179,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0xa0));
  *(undefined1 *)(param_1 + 0xa8) = 0;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0xa0));
  lStack_50 = 0;
  puStack_48 = (undefined1 *)&lStack_50;
  if (DAT_fffffff00af227e8 != 0) {
    puStack_48 = (undefined1 *)&lStack_50;
    thunk_EXT_FUN_80110000036da494(0x8518017d,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x90));
  plVar6 = *(long **)(param_1 + 0x80);
  while (plVar1 = plVar6, plVar1 != (long *)0x0) {
    plVar5 = plVar1 + 0xc;
    plVar6 = (long *)*plVar5;
    iVar3 = FUN_fffffff009959e20(plVar1,&lStack_50);
    if (iVar3 != 0) {
      lVar4 = *plVar5;
      if (lVar4 == 0) {
        plVar5 = (long *)plVar1[0xd];
        if ((long *)*plVar5 != plVar1) goto LAB_fffffff00995af04;
        *(long **)(param_1 + 0x88) = plVar5;
      }
      else {
        if (*(long **)(lVar4 + 0x68) != plVar5) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995af14);
          (*pcVar2)();
        }
        if (*(long **)plVar1[0xd] != plVar1) {
LAB_fffffff00995af04:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00995af0c);
          (*pcVar2)();
        }
        *(long **)(lVar4 + 0x68) = (long *)plVar1[0xd];
        plVar5 = (long *)plVar1[0xd];
      }
      *plVar5 = lVar4;
      (**(code **)(*plVar1 + 0x28))(plVar1);
    }
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x90));
  if (DAT_fffffff00af227e8 == 0) {
    if (lStack_50 == 0) {
      return;
    }
  }
  else {
    thunk_EXT_FUN_80110000036da494(0x8518017e,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
    if (lStack_50 == 0) goto LAB_fffffff00995aecc;
    if (DAT_fffffff00af227e8 != 0) {
      thunk_EXT_FUN_80110000036da494(0x85180181,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
    }
  }
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x68));
  if (lStack_50 != 0) {
    plVar6 = *(long **)(param_1 + 0x60);
    *plVar6 = lStack_50;
    *(long **)(lStack_50 + 0x20) = plVar6;
    *(undefined1 **)(param_1 + 0x60) = puStack_48;
    lStack_50 = 0;
    puStack_48 = (undefined1 *)&lStack_50;
  }
  if (*(int *)(param_1 + 0x70) != 0) {
    thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x68),param_1,0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x68));
  if (DAT_fffffff00af227e8 == 0) {
    return;
  }
  thunk_EXT_FUN_80110000036da494(0x85180182,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
LAB_fffffff00995aecc:
  if (DAT_fffffff00af227e8 != 0) {
    thunk_EXT_FUN_80110000036da494(0x8518017a,*(undefined8 *)(param_1 + 0x30),0,0,0,0);
  }
  return;
}

