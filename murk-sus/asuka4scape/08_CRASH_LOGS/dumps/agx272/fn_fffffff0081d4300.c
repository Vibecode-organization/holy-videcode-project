// FUN_fffffff0081d4300 @ fffffff0081d4300 size=308

bool FUN_fffffff0081d4300(long param_1,long param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  
  lVar3 = *(long *)(param_2 + 0x10);
  uVar4 = *(ulong *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18);
  if (uVar4 + lVar3 <= *(ulong *)(param_1 + 0x30)) {
    lVar6 = *(long *)(param_1 + 0x28);
    plVar5 = (long *)(param_2 + 0x20);
    lVar7 = *plVar5;
    lVar8 = *(long *)(param_2 + 0x18);
    if (lVar7 == 0) {
      plVar9 = *(long **)(param_2 + 0x28);
      if (*plVar9 != param_2) goto LAB_fffffff0081d4424;
      lVar10 = *(long *)(lVar6 + 0x20);
      lVar11 = lVar8 * 0x18 + 0x10;
      puVar1 = (undefined8 *)(lVar10 + (int)lVar11);
      if (lVar11 != (int)lVar11) {
        puVar1 = (undefined8 *)(lVar10 + lVar11 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *puVar1 = plVar9;
    }
    else {
      if (*(long **)(lVar7 + 0x28) != plVar5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d4434);
        (*pcVar2)();
      }
      if (**(long **)(param_2 + 0x28) != param_2) {
LAB_fffffff0081d4424:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081d442c);
        (*pcVar2)();
      }
      *(long **)(lVar7 + 0x28) = *(long **)(param_2 + 0x28);
      plVar9 = *(long **)(param_2 + 0x28);
      lVar10 = *(long *)(lVar6 + 0x20);
    }
    *plVar9 = lVar7;
    lVar8 = lVar8 * 0x18;
    plVar9 = (long *)(lVar10 + (int)lVar8);
    if (lVar8 - (int)lVar8 != 0) {
      plVar9 = (long *)(lVar10 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar9 = *plVar9 - lVar3;
    *(long *)(lVar6 + 0x38) = *(long *)(lVar6 + 0x38) + -1;
    *(long *)(lVar6 + 0x30) = *(long *)(lVar6 + 0x30) - lVar3;
    lVar6 = *(long *)(param_1 + 0x38);
    plVar9 = *(long **)(lVar6 + 8);
    *(undefined8 *)(param_2 + 0x20) = 0;
    *(long **)(param_2 + 0x28) = plVar9;
    *plVar9 = param_2;
    *(long **)(lVar6 + 8) = plVar5;
    lVar6 = *(long *)(*(long *)(param_1 + 0x20) + 8);
    *(long *)(lVar6 + 0x18) = *(long *)(lVar6 + 0x18) + lVar3;
    uVar4 = *(ulong *)(*(long *)(*(long *)(param_1 + 0x20) + 8) + 0x18);
  }
  return uVar4 < *(ulong *)(param_1 + 0x40);
}

