// FUN_fffffff0099611ac @ fffffff0099611ac size=644

void FUN_fffffff0099611ac(long param_1,long *param_2,ulong param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  uint local_44;
  
  local_44 = 0;
  uVar2 = FUN_fffffff00995cba8(param_2,&local_44);
  if (DAT_fffffff00af227e8 != 0) {
    uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
    thunk_EXT_FUN_80110000036da494(0x85180150,uVar3,param_2[0x19],uVar2,local_44,0);
  }
  if (((param_3 & 1) == 0) && (local_44 == uVar2)) {
    return;
  }
  if (local_44 == 3) {
    lVar4 = param_2[4];
    if (lVar4 == 0) {
      plVar5 = (long *)param_2[5];
      if ((long *)*plVar5 != param_2) goto LAB_fffffff009961414;
      *(long **)(param_1 + 0x148) = plVar5;
    }
    else {
      if (*(long **)(lVar4 + 0x28) != param_2 + 4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009961430);
        (*pcVar1)();
      }
      plVar5 = (long *)param_2[5];
      if ((long *)*plVar5 != param_2) {
LAB_fffffff009961414:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff00996141c);
        (*pcVar1)();
      }
LAB_fffffff0099612c4:
      *(long **)(lVar4 + 0x28) = plVar5;
      plVar5 = (long *)param_2[5];
    }
  }
  else {
    if (local_44 != 1) {
      if (local_44 == 0) {
        (**(code **)(*param_2 + 0x20))(param_2);
      }
      goto LAB_fffffff009961300;
    }
    lVar4 = param_2[4];
    if (lVar4 != 0) {
      if (*(long **)(lVar4 + 0x28) != param_2 + 4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009961428);
        (*pcVar1)();
      }
      plVar5 = (long *)param_2[5];
      if ((long *)*plVar5 != param_2) goto LAB_fffffff00996140c;
      goto LAB_fffffff0099612c4;
    }
    plVar5 = (long *)param_2[5];
    if ((long *)*plVar5 != param_2) {
LAB_fffffff00996140c:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009961414);
      (*pcVar1)();
    }
    *(long **)(param_1 + 0x138) = plVar5;
  }
  *plVar5 = lVar4;
LAB_fffffff009961300:
  if (uVar2 == 0) {
    (**(code **)(*param_2 + 0x28))(param_2);
  }
  else {
    if (uVar2 == 3) {
      plVar5 = (long *)(param_1 + 0x140);
      if ((local_44 == 1) &&
         (thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x150),param_2,0),
         DAT_fffffff00af227e8 != 0)) {
        uVar3 = thunk_EXT_FUN_801100000390ebc0(*(undefined8 *)(param_1 + 0x1a8));
        thunk_EXT_FUN_80110000036da494(0x85180140,uVar3,param_2[0x19],4,0,0);
      }
    }
    else {
      if (uVar2 != 1) {
        return;
      }
      plVar5 = (long *)(param_1 + 0x130);
    }
    lVar4 = *plVar5;
    if (lVar4 != 0) {
      do {
        if (*(int *)((long)param_2 + 0x6c) < *(int *)(lVar4 + 0x6c)) {
          if (**(long **)(lVar4 + 0x28) == lVar4) {
            param_2[5] = (long)*(long **)(lVar4 + 0x28);
            param_2[4] = lVar4;
            **(long **)(lVar4 + 0x28) = (long)param_2;
            *(long **)(lVar4 + 0x28) = param_2 + 4;
            return;
          }
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff009961420);
          (*pcVar1)();
        }
        lVar4 = *(long *)(lVar4 + 0x20);
      } while (lVar4 != 0);
    }
    param_2[4] = 0;
    plVar6 = (long *)plVar5[1];
    param_2[5] = (long)plVar6;
    *plVar6 = (long)param_2;
    plVar5[1] = (long)(param_2 + 4);
  }
  return;
}

