// FUN_fffffff009c4257c @ fffffff009c4257c size=512
// CALLERS:
//   fffffff00afec19a no-fn
//   fffffff00806a438 no-fn
// CALLEES:
//   fffffff009c498d4 thunk_FUN_fffffff00a894f30
//   fffffff009c4277c FUN_fffffff009c4277c
//   fffffff009c42884 FUN_fffffff009c42884
//   fffffff00a89790c FUN_fffffff00a89790c
//   fffffff009c499a4 thunk_FUN_fffffff00a89ca6c
//   fffffff009c42814 FUN_fffffff009c42814

void FUN_fffffff009c4257c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  ulong unaff_x30;
  undefined1 extraout_q0 [16];
  
  FUN_fffffff009c4277c(*(long *)(param_7 + 0x18),param_7);
  plVar2 = (long *)FUN_fffffff009c42814
                             (extraout_q0,param_2,param_3,param_4,param_5,param_6,
                              *(long *)(param_7 + 0x18),*(long *)(param_7 + 0x10));
  if ((plVar2 != (long *)0x0) &&
     (plVar3 = thunk_FUN_fffffff00a89ca6c(*(undefined8 *)(param_7 + 0x28)), plVar3 != (long *)0x0))
  {
    plVar5 = (long *)0x0;
    while( true ) {
      plVar4 = (long *)(**(code **)(*plVar3 + 0x88))(plVar3);
      plVar4 = thunk_FUN_fffffff00a894f30(plVar4,-0xff50b7ba8);
      if (plVar4 != (long *)0x0) {
        (**(code **)(*plVar4 + 0x20))(plVar4);
      }
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x28))(plVar5);
      }
      if (plVar4 == (long *)0x0) break;
      *(undefined1 *)(plVar4 + 2) = 1;
      (**(code **)(*plVar4 + 0x20))(plVar4);
      FUN_fffffff009c42884((long)plVar2,plVar4);
      plVar5 = plVar4;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long **)(param_7 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x28) = 0;
  if (*(long **)(param_7 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x18) = 0;
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_7);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c42758);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c42760. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  return;
}

