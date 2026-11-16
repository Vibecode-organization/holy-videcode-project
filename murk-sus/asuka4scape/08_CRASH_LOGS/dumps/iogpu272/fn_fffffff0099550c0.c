// FUN_fffffff0099550c0 @ fffffff0099550c0 size=168

void FUN_fffffff0099550c0(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong unaff_x30;
  
  lVar3 = *(long *)(param_1 + 0x30);
  plVar2 = *(long **)(lVar3 + 0x30);
  (**(code **)(*plVar2 + 0x90))(plVar2);
  if ((*(uint *)(lVar3 + 0x10) >> 0xb & 1) == 0) {
    *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 0x80000;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00995515c);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff009955164. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*plVar2 + 0xa0))
            (plVar2,*(uint *)(*(long *)(param_1 + 0x50) + 0x1f0) >> 7 & 1,
             (undefined8 *)(*plVar2 + 0xa0));
  return;
}

