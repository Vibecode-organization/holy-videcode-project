// FUN_fffffff009c37e34 @ fffffff009c37e34 size=268

void FUN_fffffff009c37e34(long param_1,long *param_2)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x3b8));
  plVar2 = (long *)(param_1 + 0x3d8);
  do {
    plVar2 = (long *)*plVar2;
    if (plVar2 == (long *)0x0) {
      thunk_EXT_FUN_8011000003a49114
                (
                "\"IOSurfaceRoot::removeEventNotifierClient() invoked with bad client notifier %p\" @%s:%d"
                );
      return;
    }
  } while (plVar2 != param_2);
  lVar3 = *param_2;
  if (lVar3 == 0) {
    plVar2 = (long *)param_2[1];
    if ((long *)*plVar2 != param_2) goto LAB_fffffff009c37f10;
    *(long **)(param_1 + 0x3e0) = plVar2;
  }
  else {
    if (*(long **)(lVar3 + 8) != param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c37f20);
      (*pcVar1)();
    }
    if (*(long **)param_2[1] != param_2) {
LAB_fffffff009c37f10:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009c37f18);
      (*pcVar1)();
    }
    *(undefined8 **)(lVar3 + 8) = (undefined8 *)param_2[1];
    plVar2 = (long *)param_2[1];
  }
  *plVar2 = lVar3;
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x3b8));
  if ((long *)param_2[3] != (long *)0x0) {
    (**(code **)(*(long *)param_2[3] + 0x28))();
  }
  param_2[3] = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c37f0c);
    (*pcVar1)();
  }
  thunk_EXT_FUN_80110000038fe270(&DAT_fffffff00806b4f0,param_2);
  return;
}

