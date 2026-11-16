// FUN_fffffff00a2153dc @ fffffff00a2153dc size=372

undefined8 FUN_fffffff00a2153dc(long param_1,uint param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  int in_wzr;
  
  if ((param_2 < 0x25) && (param_2 - 8 < 0xfffffffc)) {
    if (param_2 == 0x1a) {
      uVar3 = 0x2e;
    }
    else {
      lVar2 = tpidr_el1;
      if (*(ulong *)(param_1 + 8) == 0) {
        *(ulong *)(param_1 + 8) = (ulong)*(uint *)(lVar2 + 0x4e8);
      }
      else {
        FUN_fffffff00a2262d4(param_1,lVar2,0);
      }
      plVar1 = (long *)(param_1 + 0x10 + (ulong)param_2 * 8);
      lVar4 = *plVar1;
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      if (param_3 == 0) {
        param_3 = 0;
      }
      *plVar1 = param_3;
      if (*(int *)(param_1 + 8) == *(int *)(lVar2 + 0x4e8)) {
        *(int *)(param_1 + 8) = in_wzr;
      }
      else {
        FUN_fffffff00a226e08(param_1,lVar2);
      }
      if (1 < lVar4 + 1U) {
        FUN_fffffff00a1f4ae8(lVar4);
      }
      if (param_2 == 0x21) {
        FUN_fffffff00a8df19c(&MACH_HEADER,&DAT_fffffff00ad98ba0,1,"Memory error logging started\n");
        FUN_fffffff00a232c9c(&DAT_fffffff00adc4f30);
      }
      uVar3 = 0;
    }
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4d114("attempted to set invalid special port %d @%s:%d");
}

