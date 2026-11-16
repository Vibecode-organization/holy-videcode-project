// FUN_fffffff009c1919c @ fffffff009c1919c size=212

undefined8 FUN_fffffff009c1919c(long param_1,long *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long *plVar3;
  ulong unaff_x30;
  
  uVar2 = thunk_EXT_FUN_80110000038ff010();
  *(undefined8 *)(param_1 + 0x20) = uVar2;
  plVar3 = *(long **)(param_1 + 0x10);
  *(long **)(param_1 + 0x10) = param_2;
  if (param_2 != (long *)0x0) {
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  if (plVar3 != (long *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  *(undefined4 *)(param_1 + 0x2c) = 4;
  if (*(long *)(param_1 + 0x20) != 0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c19250);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff009c19258. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(PTR_DAT_fffffff00806ca30 + 0x78))(param_1);
    return uVar2;
  }
  return 0;
}

