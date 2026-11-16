// FUN_fffffff00821f204 @ fffffff00821f204 size=164
// CALLERS:
//   fffffff00afc19d2 no-fn
//   fffffff007caffa0 no-fn
// CALLEES:
//   fffffff00826f868 thunk_FUN_fffffff00a894f30

undefined8 FUN_fffffff00821f204(long *param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  ulong unaff_x30;
  
  uVar3 = 0xe00002c2;
  if (((param_3 != 0) && (*(int *)(param_3 + 0x60) == 0x2c)) &&
     (lVar4 = *(long *)(param_3 + 0x58), lVar4 != 0)) {
    plVar2 = thunk_FUN_fffffff00a894f30(param_1,-0xff51d6e70);
    if (plVar2 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00821f288);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff00821f290. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*plVar2 + 0x5e0))(plVar2,lVar4,(undefined8 *)(*plVar2 + 0x5e0));
      return uVar3;
    }
    uVar3 = 0xe00002bc;
  }
  return uVar3;
}

