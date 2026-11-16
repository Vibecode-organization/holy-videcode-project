// FUN_fffffff008c24310 @ fffffff008c24310 size=4 depth=0
// CALLERS:
//   fffffff00afd026f ?
//   fffffff007e105b0 ?
// CALLS:

undefined8 FUN_fffffff008c24310(long *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  thunk_FUN_fffffff00a9029a0((byte *)"%s::%s / %d\n");
  plVar2 = thunk_FUN_fffffff00a894f30(param_1,-0xff51b8e58);
  if (plVar2 == (long *)0x0) {
    return 0xe00002bc;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff008c243b0);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff008c243b8. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*plVar2 + 0x600))(plVar2,param_3,(undefined8 *)(*plVar2 + 0x600));
  return uVar3;
}

