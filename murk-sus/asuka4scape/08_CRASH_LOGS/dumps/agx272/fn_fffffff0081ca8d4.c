// FUN_fffffff0081ca8d4 @ fffffff0081ca8d4 size=688

long FUN_fffffff0081ca8d4(long param_1,long param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  byte bVar7;
  uint uVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long *plVar17;
  long lVar18;
  long lVar19;
  undefined *local_f0;
  undefined8 local_e8;
  code *local_e0;
  undefined *local_d8;
  long lStack_d0;
  long local_c8;
  uint local_c0;
  uint uStack_bc;
  int local_b8;
  ulong local_b0 [4];
  uint local_90;
  long local_80;
  
  uVar9 = DAT_fffffff007113e50;
  lVar18 = 0;
  bVar7 = 0;
  lVar16 = 0;
  local_80 = *(long *)PTR_DAT_fffffff007ca61a0;
  local_90 = 0;
  local_b0[1] = 0;
  local_b0[0] = 0;
  local_b0[3] = 0;
  local_b0[2] = 0;
  uVar13 = 0xb;
  if (param_3 != 3) {
    uVar13 = 3;
  }
  lVar15 = 0x110;
  do {
    puVar1 = (uint *)(param_2 + lVar18 * 8);
    uVar3 = *puVar1;
    if ((uVar3 & 1) == 0) break;
    uVar8 = uVar3 >> 4 & 0x7f;
    uVar4 = puVar1[1];
    plVar10 = (long *)FUN_fffffff00817f2e0
                                (*(undefined8 *)(*(long *)(param_1 + 0x280) + 0x160),uVar8);
    if (plVar10 != (long *)0x0) {
      lVar11 = thunk_EXT_FUN_8011000002959acc(plVar10,uVar8,uVar4);
      lVar19 = *(long *)(lVar11 + 0x60);
      iVar5 = *(int *)(lVar19 + 0x490);
      local_b0[0] = local_b0[0] & 0xffffffffffffff00;
      if (0 < iVar5) {
        thunk_EXT_FUN_8011000003722d80(iVar5,local_b0,0x24);
        local_90 = local_90 & 0xffffff;
      }
      uVar4 = uVar3 >> 1 & 1;
      uVar2 = 5;
      if (uVar4 != 0) {
        uVar2 = uVar13;
      }
      lVar14 = *(long *)(lVar11 + 0x68);
      if ((lVar14 != 0) && ((*(uint *)(lVar14 + 200) | 8) != 0xb)) {
        *(undefined4 *)(lVar14 + 200) = uVar2;
      }
      uStack_bc = uVar3 >> 2 & 1;
      plVar17 = *(long **)(lVar11 + 0x230);
      local_f0 = PTR_DAT_fffffff007ca5f90;
      local_e8 = uVar9;
      local_e0 = FUN_fffffff0081cab84;
      local_d8 = &DAT_fffffff007c96030;
      lStack_d0 = param_2;
      local_c8 = lVar11;
      local_c0 = uVar4;
      local_b8 = param_3;
      if (plVar17 != (long *)0x0) {
        thunk_EXT_FUN_801100000294e120(plVar17);
        lVar11 = (**(code **)(*plVar17 + 0x80))(plVar17);
        uVar12 = (**(code **)(*plVar17 + 0x98))(plVar17);
        if (lVar11 != 0) {
          (*local_e0)(&local_f0,lVar11,uVar12);
          (**(code **)(*plVar17 + 0x88))(plVar17);
        }
        thunk_EXT_FUN_801100000294e12c(plVar17);
      }
      bVar6 = (bool)(uVar4 == 0 | bVar7);
      if (!bVar6) {
        lVar16 = lVar19;
      }
      bVar7 = bVar6 ^ 1U | bVar7;
      (**(code **)(*plVar10 + 0x28))(plVar10);
    }
    lVar18 = lVar18 + 1;
    lVar15 = lVar15 + -1;
  } while (lVar15 != 0);
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_80) {
    return lVar16;
  }
  lVar18 = thunk_EXT_FUN_8011000003a48590();
  return lVar18;
}

