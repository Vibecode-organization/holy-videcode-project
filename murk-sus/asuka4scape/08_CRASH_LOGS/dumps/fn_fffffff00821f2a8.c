// FUN_fffffff00821f2a8 @ fffffff00821f2a8 size=8
// CALLERS:
//   fffffff00afc19d4 no-fn
//   fffffff007caffb8 no-fn
// CALLEES:

undefined8 FUN_fffffff00821f2a8(long *param_1)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  plVar2 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
  if (plVar2 == (long *)0x0) {
    return 0xe00002bc;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00821f304);
    (*pcVar1)();
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00821f30c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*plVar2 + 0x5e8))(plVar2,0,(undefined8 *)(*plVar2 + 0x5e8));
  return uVar3;
}

