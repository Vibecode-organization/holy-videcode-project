// FUN_fffffff00996f22c @ fffffff00996f22c size=304

void FUN_fffffff00996f22c(long param_1)

{
  long *plVar1;
  code *pcVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  ulong unaff_x30;
  
  if (*(long **)(param_1 + 0x160) != (long *)0x0) {
    plVar1 = (long *)(param_1 + 0x160);
    plVar7 = *(long **)(param_1 + 0x160);
    do {
      plVar8 = (long *)plVar7[3];
      plVar5 = (long *)*plVar1;
      if (plVar5 == plVar7) {
        lVar6 = plVar5[3];
        *plVar1 = lVar6;
        plVar4 = plVar1;
      }
      else {
        do {
          plVar4 = plVar5;
          plVar5 = (long *)plVar4[3];
        } while (plVar5 != plVar7);
        lVar6 = plVar5[3];
        plVar4 = plVar4 + 3;
        *plVar4 = lVar6;
      }
      if (lVar6 == 0) {
        *(long **)(param_1 + 0x168) = plVar4;
      }
      (**(code **)(*plVar7 + 0x28))();
      *(int *)(param_1 + 0x170) = *(int *)(param_1 + 0x170) + -1;
      plVar7 = plVar8;
    } while (plVar8 != (long *)0x0);
  }
  if (*(long *)(param_1 + 0x150) != 0) {
    uVar3 = thunk_EXT_FUN_8011000002c13500();
    if (uVar3 < *(ulong *)(param_1 + 0x158)) {
      thunk_EXT_FUN_8011000002c12744(*(undefined8 *)(param_1 + 0x150));
    }
    (**(code **)(**(long **)(param_1 + 0x150) + 0x28))();
    *(undefined8 *)(param_1 + 0x150) = 0;
  }
  if (*(long **)(param_1 + 0x148) != (long *)0x0) {
    (**(code **)(**(long **)(param_1 + 0x148) + 0x28))();
  }
  *(undefined8 *)(param_1 + 0x148) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00996f358);
    (*pcVar2)();
  }
  FUN_fffffff00996d494(param_1);
  return;
}

