// FUN_fffffff0081b894c @ fffffff0081b894c size=152

void FUN_fffffff0081b894c(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong unaff_x30;
  
  if (*(long *)(param_1 + 0x210) != 0) {
    if ((int)param_2 == 0) {
      iVar2 = thunk_EXT_FUN_801100000389060c(param_1 + 0x1458);
      if (iVar2 == 1) goto LAB_fffffff0081b899c;
    }
    else {
      iVar2 = thunk_EXT_FUN_80110000038905fc();
      if (iVar2 == 0) {
LAB_fffffff0081b899c:
        puVar3 = (undefined8 *)(**(long **)(param_1 + 0x210) + 0x28);
        if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081b89d8);
          (*pcVar1)();
        }
                    /* WARNING: Could not recover jumptable at 0xfffffff0081b89e0. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)*puVar3)(*(long **)(param_1 + 0x210),param_2,puVar3);
        return;
      }
    }
  }
  return;
}

