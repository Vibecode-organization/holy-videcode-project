// FUN_fffffff009c157d4 @ fffffff009c157d4 size=264

/* WARNING: Removing unreachable block (ram,0xfffffff009c159ac) */

void FUN_fffffff009c157d4(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  ulong unaff_x30;
  undefined1 auVar5 [16];
  
  if (*(long *)(param_1 + 0x18) != 0) {
    auVar5 = FUN_fffffff009c48e20();
    plVar3 = auVar5._8_8_;
    plVar2 = auVar5._0_8_;
    thunk_EXT_FUN_80110000032222a8(plVar2[2]);
    plVar3[5] = 0;
    plVar4 = (long *)plVar2[4];
    plVar3[6] = (long)plVar4;
    *plVar4 = (long)plVar3;
    plVar2[4] = (long)(plVar3 + 5);
    (**(code **)(*plVar3 + 0x20))(plVar3);
    if ((*(byte *)(plVar2 + 5) & 1) == 0) {
      *(undefined1 *)(plVar2 + 5) = 1;
      (**(code **)(*plVar2 + 0x20))(plVar2);
      (**(code **)(*(long *)plVar2[7] + 0xf8))((long *)plVar2[7],0,0,0);
    }
    thunk_EXT_FUN_8011000003222de0(plVar2[2]);
    return;
  }
  plVar2 = *(long **)(param_1 + 0x30);
  if (plVar2 == (long *)0x0) goto LAB_fffffff009c15894;
  plVar3 = *(long **)(param_1 + 0x38);
  if (plVar3 == (long *)0x0) {
LAB_fffffff009c15874:
    (**(code **)(*plVar2 + 0x28))();
  }
  else {
    (**(code **)(*plVar3 + 0xb8))(plVar3);
    (**(code **)(**(long **)(param_1 + 0x30) + 0xa8))
              (*(long **)(param_1 + 0x30),*(undefined8 *)(param_1 + 0x38));
    if (*(long **)(param_1 + 0x38) != (long *)0x0) {
      (**(code **)(**(long **)(param_1 + 0x38) + 0x28))();
    }
    *(undefined8 *)(param_1 + 0x38) = 0;
    plVar2 = *(long **)(param_1 + 0x30);
    if (plVar2 != (long *)0x0) goto LAB_fffffff009c15874;
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
LAB_fffffff009c15894:
  if (*(long *)(param_1 + 0x10) != 0) {
    thunk_EXT_FUN_80110000038ff020();
    *(undefined8 *)(param_1 + 0x10) = 0;
  }
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0xfffffff009c158d4. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009c158cc);
  (*pcVar1)();
}

