// FUN_fffffff009cc5f84 @ fffffff009cc5f84

/* WARNING: Removing unreachable block (ram,0xfffffff009cc60f0) */

void FUN_fffffff009cc5f84
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined4 param_3,
               undefined4 param_4,undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined *param_11)

{
  code *pcVar1;
  long *plVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined **ppuVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  ulong unaff_x30;
  undefined1 auVar10 [16];
  
  lVar8 = 0;
  lVar6 = param_7 + 0xa8;
  lVar9 = 0x10;
  do {
    lVar4 = *(long *)(lVar6 + lVar8 * 8);
    if (lVar4 != 0) {
      puVar3 = *(undefined8 **)(lVar4 + 0x18);
      *(undefined8 *)(lVar4 + 0x18) = 0;
      auVar10 = thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff008080ef8,puVar3);
      lVar4 = *(long *)(lVar6 + lVar8 * 8);
      ppuVar5 = *(undefined ***)(lVar4 + 0x48);
      if (ppuVar5 != (undefined **)0x0) {
        *(undefined8 *)(lVar4 + 0x48) = 0;
        thunk_FUN_fffffff00a902768
                  (auVar10,param_2,param_3,param_4,param_5,param_6,0xfffffff008081068,ppuVar5,
                   &DAT_00000060,param_10,param_11);
        lVar4 = *(long *)(lVar6 + lVar8 * 8);
      }
      param_1 = (**(code **)(**(long **)(param_7 + 0x88) + 0x768))(*(long **)(param_7 + 0x88),lVar4)
      ;
    }
    lVar8 = lVar8 + 1;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  if (*(long **)(param_7 + 0x98) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x98) + 0x28))(param_1);
  }
  plVar7 = (long *)(param_7 + 0x70);
  plVar2 = (long *)*plVar7;
  *(undefined8 *)(param_7 + 0x98) = 0;
  while (plVar2 != (long *)0x0) {
    lVar6 = plVar2[2];
    *plVar7 = lVar6;
    if (lVar6 == 0) {
      *(long **)(param_7 + 0x78) = plVar7;
    }
    (**(code **)(*plVar2 + 0x28))();
    plVar2 = (long *)*plVar7;
  }
  if (*(undefined8 **)(param_7 + 0xa0) != (undefined8 *)0x0) {
    thunk_FUN_fffffff00a903524(*(undefined8 **)(param_7 + 0xa0));
    *(undefined8 *)(param_7 + 0xa0) = 0;
  }
  if (*(long **)(param_7 + 0x80) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x80) + 0xb8))();
    plVar2 = (long *)(**(code **)(**(long **)(param_7 + 0x88) + 0x378))
                               (**(long **)(param_7 + 0x88) + 0x378);
    (**(code **)(*plVar2 + 0xa8))(plVar2,*(undefined8 *)(param_7 + 0x80));
    if (*(long **)(param_7 + 0x80) != (long *)0x0) {
      (**(code **)(**(long **)(param_7 + 0x80) + 0x28))();
    }
    *(undefined8 *)(param_7 + 0x80) = 0;
  }
  if (*(long **)(param_7 + 0x88) != (long *)0x0) {
    (**(code **)(**(long **)(param_7 + 0x88) + 0x28))();
  }
  *(undefined8 *)(param_7 + 0x88) = 0;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff009cc61a8);
    (*pcVar1)();
  }
  (**(code **)(PTR_DAT_fffffff0080813b0 + 0x80))(param_7);
  return;
}

