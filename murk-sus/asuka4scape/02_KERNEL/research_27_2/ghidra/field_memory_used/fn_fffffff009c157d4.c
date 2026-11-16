// FUN_fffffff009c157d4 @ fffffff009c157d4

void FUN_fffffff009c157d4
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  ulong unaff_x30;
  
  if (*(long *)(param_7 + 0x18) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48e20(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  plVar2 = *(long **)(param_7 + 0x30);
  if (plVar2 == (long *)0x0) goto LAB_fffffff009c15894;
  plVar3 = *(long **)(param_7 + 0x38);
  if (plVar3 == (long *)0x0) {
LAB_fffffff009c15874:
    (**(code **)(*plVar2 + 0x28))();
  }
  else {
    (**(code **)(*plVar3 + 0xb8))(plVar3);
    (**(code **)(**(long **)(param_7 + 0x30) + 0xa8))
              (*(long **)(param_7 + 0x30),*(undefined8 *)(param_7 + 0x38));
    if (*(long **)(param_7 + 0x38) != (long *)0x0) {
      (**(code **)(**(long **)(param_7 + 0x38) + 0x28))();
    }
    *(undefined8 *)(param_7 + 0x38) = 0;
    plVar2 = *(long **)(param_7 + 0x30);
    if (plVar2 != (long *)0x0) goto LAB_fffffff009c15874;
  }
  *(undefined8 *)(param_7 + 0x30) = 0;
LAB_fffffff009c15894:
  if (*(undefined8 **)(param_7 + 0x10) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903020(*(undefined8 **)(param_7 + 0x10));
    *(undefined8 *)(param_7 + 0x10) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c158cc);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_7);
  return;
}

