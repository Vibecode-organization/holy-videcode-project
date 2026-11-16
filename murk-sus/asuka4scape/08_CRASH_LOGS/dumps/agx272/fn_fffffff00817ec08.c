// FUN_fffffff00817ec08 @ fffffff00817ec08 size=324

void FUN_fffffff00817ec08(long param_1,long *param_2)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  ulong unaff_x30;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x358));
  lVar2 = param_2[2];
  if (lVar2 == 0) {
    plVar3 = (long *)param_2[3];
    if ((long *)*plVar3 != param_2) goto LAB_fffffff00817ed3c;
    *(long **)(param_1 + 0x368) = plVar3;
  }
  else {
    if (*(long **)(lVar2 + 0x18) != param_2 + 2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817ed4c);
      (*pcVar1)();
    }
    if (*(long **)param_2[3] != param_2) {
LAB_fffffff00817ed3c:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00817ed44);
      (*pcVar1)();
    }
    *(long **)(lVar2 + 0x18) = (long *)param_2[3];
    plVar3 = (long *)param_2[3];
  }
  *plVar3 = lVar2;
  FUN_fffffff00817eb58(param_1,0,*(undefined8 *)(param_2[10] + 0x30));
  if ((*(byte *)(param_1 + 0x1ac44) >> 3 & 1) != 0) {
    lVar2 = *(long *)(param_2[10] + 0x30);
    uVar4 = param_2[7];
    if (uVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
      if (uVar4 != 0) {
        uVar5 = (ulong)(lVar2 * 100) / uVar4;
      }
    }
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac48));
    thunk_EXT_FUN_80110000036da494(0x85930d34,param_2,uVar4,lVar2,uVar5,0);
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac48));
  }
  (**(code **)(*param_2 + 0x28))(param_2);
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x358));
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00817ed38);
  (*pcVar1)();
}

