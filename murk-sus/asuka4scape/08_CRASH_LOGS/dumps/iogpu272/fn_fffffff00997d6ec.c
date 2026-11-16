// FUN_fffffff00997d6ec @ fffffff00997d6ec size=236

void FUN_fffffff00997d6ec(void)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff00997b558();
  lVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,"CachedCopy");
  if (lVar3 == 0) {
    plVar4 = (long *)thunk_EXT_FUN_80110000038970c4(1);
    (**(code **)(*plVar2 + 0x100))(plVar2,"CachedCopy",plVar4);
    if (plVar4 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997d7cc);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997d7d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar4 + 0x28))(plVar4,(undefined8 *)(*plVar4 + 0x28));
      return;
    }
  }
  return;
}

