// FUN_fffffff009c4257c @ fffffff009c4257c size=512

void FUN_fffffff009c4257c(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  ulong unaff_x30;
  
  FUN_fffffff009c4277c(*(undefined8 *)(param_1 + 0x18),param_1);
  plVar2 = (long *)FUN_fffffff009c42814
                             (*(undefined8 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10));
  if ((plVar2 != (long *)0x0) &&
     (plVar3 = (long *)thunk_EXT_FUN_8011000003898a6c(*(undefined8 *)(param_1 + 0x28)),
     plVar3 != (long *)0x0)) {
    plVar6 = (long *)0x0;
    while( true ) {
      uVar4 = (**(code **)(*plVar3 + 0x88))(plVar3);
      plVar5 = (long *)thunk_EXT_FUN_8011000003890f30(uVar4,&DAT_fffffff00af48458);
      if (plVar5 != (long *)0x0) {
        (**(code **)(*plVar5 + 0x20))(plVar5);
      }
      if (plVar6 != (long *)0x0) {
        (**(code **)(*plVar6 + 0x28))(plVar6);
      }
      if (plVar5 == (long *)0x0) break;
      *(undefined1 *)(plVar5 + 2) = 1;
      (**(code **)(*plVar5 + 0x20))(plVar5);
      FUN_fffffff009c42884(plVar2,plVar5);
      plVar6 = plVar5;
    }
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if (*(long **)(param_1 + 0x28) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x28) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  if (*(long **)(param_1 + 0x18) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  (**(code **)(PTR_DAT_fffffff00806ca30 + 0x80))(param_1);
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

