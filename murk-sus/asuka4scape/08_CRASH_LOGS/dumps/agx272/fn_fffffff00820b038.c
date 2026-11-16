// FUN_fffffff00820b038 @ fffffff00820b038 size=100

void FUN_fffffff00820b038(long param_1)

{
  code *pcVar1;
  long *plVar2;
  ulong unaff_x30;
  
  plVar2 = *(long **)(param_1 + 0x188);
  if (plVar2 != (long *)0x0) {
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  *(undefined8 *)(param_1 + 0x188) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00820b098);
    (*pcVar1)();
  }
  FUN_fffffff008184fb4();
  return;
}

