// FUN_fffffff009972e28 @ fffffff009972e28 size=228

void FUN_fffffff009972e28(void)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  int iVar4;
  ulong unaff_x30;
  
  if ((DAT_fffffff00af227e8 == 0) ||
     (plVar3 = (long *)FUN_fffffff009975a20(), plVar3 == (long *)0x0)) {
    return;
  }
  iVar2 = (**(code **)(*plVar3 + 0x90))();
  if (iVar2 != 0) {
    iVar4 = 0;
    do {
      (**(code **)(*plVar3 + 0x118))(plVar3,iVar4);
      FUN_fffffff009955e64();
      iVar4 = iVar4 + 1;
    } while (iVar2 != iVar4);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009972ef0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009972ef8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
  return;
}

