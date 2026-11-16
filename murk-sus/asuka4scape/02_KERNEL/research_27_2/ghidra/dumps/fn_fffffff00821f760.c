// FUN_fffffff00821f760 @ fffffff00821f760 size=192
// CALLERS:
//   fffffff00afc19db no-fn
//   fffffff007cb0018 no-fn
// CALLEES:
//   fffffff00826f868 thunk_FUN_fffffff00a894f30

undefined8 FUN_fffffff00821f760(long *param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong unaff_x30;
  
  uVar3 = 0xe00002c2;
  if (((param_3 != 0) && (*(int *)(param_3 + 0x60) == 0x28)) && (*(int *)(param_3 + 0x38) == 0x28))
  {
    uVar3 = *(undefined8 *)(param_3 + 0x58);
    plVar2 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
    if (plVar2 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00821f7fc);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff00821f804. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*plVar2 + 0x600))
                        (plVar2,*(undefined8 *)(param_3 + 0x30),uVar3,
                         (undefined8 *)(*plVar2 + 0x600));
      return uVar3;
    }
    uVar3 = 0xe00002bc;
  }
  return uVar3;
}

