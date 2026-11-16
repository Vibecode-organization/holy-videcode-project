// FUN_fffffff00819a1f4 @ fffffff00819a1f4 size=628

/* WARNING: Removing unreachable block (ram,0xfffffff00819a250) */

void FUN_fffffff00819a1f4(long param_1)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  ulong unaff_x30;
  
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0x98))();
  lVar3 = **(long **)(*(long *)(param_1 + 0x530) + 0x4b0);
  (**(code **)(lVar3 + 0x230))(lVar3 + 0x230);
  lVar3 = *(long *)(param_1 + 0x610);
  if (lVar3 == 0) {
    return;
  }
  if (*(int *)(lVar3 + 0x98) != 0) {
    uVar4 = 0;
    do {
      (**(code **)(**(long **)(lVar3 + 0x28 + uVar4 * 8) + 0x100))();
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(lVar3 + 0x98));
  }
  if (*(int *)(lVar3 + 0x9c) != 0) {
    uVar4 = 0;
    do {
      (**(code **)(**(long **)(lVar3 + 0x48 + uVar4 * 8) + 0x100))();
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(lVar3 + 0x9c));
  }
  if (*(long **)(lVar3 + 0x68) == (long *)0x0) {
    plVar2 = *(long **)(lVar3 + 0x80);
  }
  else {
    (**(code **)(**(long **)(lVar3 + 0x68) + 0x100))();
    plVar2 = *(long **)(lVar3 + 0x80);
  }
  if (plVar2 == (long *)0x0) {
    plVar2 = *(long **)(lVar3 + 0x70);
  }
  else {
    (**(code **)(*plVar2 + 0x100))();
    plVar2 = *(long **)(lVar3 + 0x70);
  }
  if (plVar2 == (long *)0x0) {
    plVar2 = *(long **)(lVar3 + 0x88);
  }
  else {
    (**(code **)(*plVar2 + 0x100))();
    plVar2 = *(long **)(lVar3 + 0x88);
  }
  if (plVar2 == (long *)0x0) {
    plVar2 = *(long **)(lVar3 + 0x78);
  }
  else {
    (**(code **)(*plVar2 + 0x100))();
    plVar2 = *(long **)(lVar3 + 0x78);
  }
  if (plVar2 == (long *)0x0) {
    plVar2 = *(long **)(lVar3 + 0x90);
  }
  else {
    (**(code **)(*plVar2 + 0x100))();
    plVar2 = *(long **)(lVar3 + 0x90);
  }
  if (plVar2 != (long *)0x0) {
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0xc471,0xfffffff00819a45c);
      (*pcVar1)();
    }
                    /* WARNING: Could not recover jumptable at 0xfffffff00819a464. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*plVar2 + 0x100))(plVar2,(undefined8 *)(*plVar2 + 0x100));
    return;
  }
  return;
}

