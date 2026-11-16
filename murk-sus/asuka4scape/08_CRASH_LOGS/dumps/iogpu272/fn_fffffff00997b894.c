// FUN_fffffff00997b894 @ fffffff00997b894 size=188

void FUN_fffffff00997b894(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff00997b558();
  if (plVar2 != (long *)0x0) {
    plVar3 = (long *)thunk_EXT_FUN_80110000038c6e24(param_3,0x40);
    (**(code **)(*plVar2 + 0x100))(plVar2,"IOSurfaceID",plVar3);
    if (plVar3 != (long *)0x0) {
      if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997b938);
        (*pcVar1)();
      }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997b940. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*plVar3 + 0x28))(plVar3,(undefined8 *)(*plVar3 + 0x28));
      return;
    }
  }
  return;
}

