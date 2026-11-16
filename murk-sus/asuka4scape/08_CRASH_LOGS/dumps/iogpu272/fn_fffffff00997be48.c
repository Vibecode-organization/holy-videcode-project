// FUN_fffffff00997be48 @ fffffff00997be48 size=344

void FUN_fffffff00997be48(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  undefined8 uVar3;
  long *plVar4;
  ulong unaff_x30;
  
  plVar2 = (long *)FUN_fffffff00997b558();
  uVar3 = (**(code **)(*plVar2 + 0x138))(plVar2,"Descriptions");
  plVar4 = (long *)thunk_EXT_FUN_8011000003890f30(uVar3,*(undefined8 *)PTR_DAT_fffffff007ff27a0);
  if (plVar4 == (long *)0x0) {
    plVar4 = (long *)thunk_EXT_FUN_80110000038961f4(1);
    (**(code **)(*plVar2 + 0x100))(plVar2,"Descriptions",plVar4);
    if (plVar4 != (long *)0x0) {
      (**(code **)(*plVar4 + 0x28))(plVar4);
    }
  }
  plVar2 = (long *)thunk_EXT_FUN_80110000038ce200(param_3);
  (**(code **)(*plVar4 + 0xe8))(plVar4,plVar2);
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00997bf84);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00997bf8c. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x28))(plVar2,(undefined8 *)(*plVar2 + 0x28));
    return;
  }
  return;
}

