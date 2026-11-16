// FUN_fffffff0099755c0 @ fffffff0099755c0 size=244

void FUN_fffffff0099755c0(long param_1)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  ulong unaff_x30;
  
  plVar3 = (long *)FUN_fffffff009944a54(*(undefined8 *)(param_1 + 0x1c8));
  if (plVar3 == (long *)0x0) {
    return;
  }
  iVar2 = (**(code **)(*plVar3 + 0x90))();
  if (iVar2 != 0) {
    iVar5 = 0;
    do {
      plVar4 = (long *)(**(code **)(*plVar3 + 0x118))(plVar3,iVar5);
      (**(code **)(*plVar4 + 200))();
      iVar5 = iVar5 + 1;
    } while (iVar2 != iVar5);
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009975698);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0099756a0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
  return;
}

