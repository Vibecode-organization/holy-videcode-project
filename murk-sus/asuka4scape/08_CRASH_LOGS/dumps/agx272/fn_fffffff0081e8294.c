// FUN_fffffff0081e8294 @ fffffff0081e8294 size=412

void FUN_fffffff0081e8294(long param_1,long *param_2,ulong param_3)

{
  ushort uVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  ulong unaff_x30;
  
  thunk_EXT_FUN_801100000296c9fc();
  uVar3 = (**(code **)(*param_2 + 200))(param_2);
  uVar1 = *(ushort *)((long)param_2 + 0x12);
  if (uVar1 == 6 || uVar1 == 0xd) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Cannot deallocate from unmapped range!\n");
    return;
  }
  uVar10 = (uint)uVar1;
  if (uVar10 == 0) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! Cannot deallocate from default range!\n");
    return;
  }
  uVar7 = (ulong)DAT_fffffff00ae2181c;
  uVar4 = (ulong)(*(uint *)((long)param_2 + 0x14) >> (uVar7 & 0x3f));
  uVar8 = uVar3 >> (uVar7 & 0x3f);
  uVar9 = uVar8 + uVar4 & -uVar4;
  if (uVar4 == 0) {
    uVar9 = uVar8 + 1;
  }
  plVar5 = *(long **)(param_1 + 0x1f0 + (ulong)uVar10 * 8);
  (**(code **)(*plVar5 + 0xc0))(plVar5,param_3 >> (uVar7 & 0x3f),uVar9);
  *(ulong *)(param_1 + 0xb8 + (ulong)uVar10 * 8) =
       *(long *)(param_1 + 0xb8 + (ulong)uVar10 * 8) - uVar3;
  lVar6 = param_2[7];
  if (lVar6 == 0) {
    plVar5 = (long *)param_2[8];
    if ((long *)*plVar5 != param_2) goto LAB_fffffff0081e8420;
    *(long **)(param_1 + 0x1c0) = plVar5;
  }
  else {
    if (*(long **)(lVar6 + 0x40) != param_2 + 7) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081e8430);
      (*pcVar2)();
    }
    if (*(long **)param_2[8] != param_2) {
LAB_fffffff0081e8420:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0xbffd,0xfffffff0081e8428);
      (*pcVar2)();
    }
    *(long **)(lVar6 + 0x40) = (long *)param_2[8];
    plVar5 = (long *)param_2[8];
  }
  *plVar5 = lVar6;
  if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081e83f4);
    (*pcVar2)();
  }
  thunk_EXT_FUN_801100000296ca08(param_1);
  return;
}

