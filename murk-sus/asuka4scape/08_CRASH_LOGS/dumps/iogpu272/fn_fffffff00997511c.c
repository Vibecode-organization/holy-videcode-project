// FUN_fffffff00997511c @ fffffff00997511c size=184

void FUN_fffffff00997511c(long param_1,long *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  undefined8 uVar5;
  
  lVar3 = param_2[2];
  if (lVar3 == 0) {
    plVar4 = (long *)param_2[3];
    if ((long *)*plVar4 != param_2) goto LAB_fffffff0099751c4;
    *(long **)(param_1 + 0x1a0) = plVar4;
  }
  else {
    if (*(long **)(lVar3 + 0x18) != param_2 + 2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099751d4);
      (*pcVar1)();
    }
    if (*(long **)param_2[3] != param_2) {
LAB_fffffff0099751c4:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0099751cc);
      (*pcVar1)();
    }
    *(long **)(lVar3 + 0x18) = (long *)param_2[3];
    plVar4 = (long *)param_2[3];
  }
  *plVar4 = lVar3;
  iVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  uVar5 = *(undefined8 *)(param_1 + 0x1ac);
  *(undefined8 *)(param_1 + 0x1ac) = CONCAT44((int)((ulong)uVar5 >> 0x20) - iVar2,(int)uVar5 + -1);
  return;
}

