// FUN_fffffff0081e0954 @ fffffff0081e0954 size=348

undefined8 FUN_fffffff0081e0954(long param_1,int param_2,int param_3,ulong param_4)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  if (param_3 == 0) {
    plVar2 = *(long **)(param_1 + 0x50);
    if (plVar2 != (long *)0x0) goto LAB_fffffff0081e0a1c;
    uVar4 = 0x10000000084;
    if (param_2 != 0) {
      uVar4 = 0x84;
    }
    plVar2 = (long *)(**(code **)(**(long **)(param_1 + 0x48) + 0x90))
                               (*(long **)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x18),
                                param_4 | uVar4 | 0x800000000);
  }
  else {
    if (param_3 != 1) {
      return 0;
    }
    plVar2 = *(long **)(param_1 + 0x50);
    if (plVar2 != (long *)0x0) goto LAB_fffffff0081e0a1c;
    uVar4 = 0x10000000084;
    if (param_2 != 0) {
      uVar4 = 0x84;
    }
    plVar2 = (long *)(**(code **)(**(long **)(param_1 + 0x48) + 0x90))
                               (*(long **)(param_1 + 0x48),*(undefined8 *)(param_1 + 0x18),
                                param_4 | 0x20900000000 | uVar4);
  }
  if (plVar2 == (long *)0x0) {
    return 0;
  }
  (**(code **)(*plVar2 + 0x20))();
  (**(code **)(*plVar2 + 0x28))(plVar2);
  *(long **)(param_1 + 0x50) = plVar2;
LAB_fffffff0081e0a1c:
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e0a50);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081e0a58. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*plVar2 + 0x98))(plVar2,(undefined8 *)(*plVar2 + 0x98));
  return uVar3;
}

