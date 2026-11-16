// FUN_fffffff0081e8430 @ fffffff0081e8430 size=528

long FUN_fffffff0081e8430(long param_1,long *param_2)

{
  ushort uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  ulong local_48;
  
  thunk_EXT_FUN_801100000296c9fc();
  if ((*(ushort *)(param_2 + 2) >> 6 & 1) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (**(code **)(*param_2 + 0x98))(param_2);
  }
  uVar3 = (**(code **)(*param_2 + 200))(param_2);
  uVar1 = *(ushort *)((long)param_2 + 0x12);
  uVar6 = (ulong)DAT_fffffff00ae2181c;
  uVar4 = (ulong)(*(uint *)((long)param_2 + 0x14) >> (uVar6 & 0x3f));
  uVar5 = uVar3 >> (uVar6 & 0x3f);
  local_48 = 0;
  uVar8 = uVar5 + uVar4 & -uVar4;
  if (uVar4 == 0) {
    uVar8 = uVar5 + 1;
  }
  if ((uVar1 == 6) || (uVar1 == 0xd)) {
    lVar10 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Cannot allocate from unmapped range!\n");
    return lVar10;
  }
  uVar11 = (uint)uVar1;
  if (uVar11 == 0) {
    lVar10 = thunk_EXT_FUN_8011000003a49114
                       ("AGXk: %s:%d:%s: !!! Cannot allocate from default range!\n");
    return lVar10;
  }
  if (uVar9 == 0) {
    plVar7 = *(long **)(param_1 + 0x1f0 + (ulong)uVar11 * 8);
    iVar2 = (**(code **)(*plVar7 + 0xb0))(plVar7,uVar8,&local_48);
    uVar9 = local_48;
    if (iVar2 != 0) goto LAB_fffffff0081e85b8;
  }
  else {
    uVar9 = uVar9 >> (uVar6 & 0x3f);
    if (((uVar4 - 1 & uVar9) == 0) &&
       (plVar7 = *(long **)(param_1 + 0x1f0 + (ulong)(uint)uVar1 * 8),
       uVar8 = (**(code **)(*plVar7 + 0xb8))(plVar7,uVar9,uVar8), (uVar8 & 1) != 0)) {
LAB_fffffff0081e85b8:
      *(ulong *)(param_1 + 0xb8 + (ulong)uVar11 * 8) =
           *(long *)(param_1 + 0xb8 + (ulong)(uint)uVar1 * 8) + uVar3;
      lVar10 = uVar9 << ((ulong)DAT_fffffff00ae2181c & 0x3f);
      if (lVar10 != 0) {
        param_2[7] = 0;
        plVar7 = *(long **)(param_1 + 0x1c0);
        param_2[8] = (long)plVar7;
        *plVar7 = (long)param_2;
        *(long **)(param_1 + 0x1c0) = param_2 + 7;
      }
      goto LAB_fffffff0081e85f4;
    }
  }
  lVar10 = 0;
LAB_fffffff0081e85f4:
  thunk_EXT_FUN_801100000296ca08(param_1);
  return lVar10;
}

