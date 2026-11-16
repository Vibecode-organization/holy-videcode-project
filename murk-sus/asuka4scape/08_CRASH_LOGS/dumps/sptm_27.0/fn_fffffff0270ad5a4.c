// FUN_fffffff0270ad5a4 @ fffffff0270ad5a4 size=768
// CALLERS:
//   fffffff02701c178 ?
//   fffffff0270ad96c FUN_fffffff0270ad8a4@fffffff0270ad8a4

undefined8 FUN_fffffff0270ad5a4(undefined8 param_1)

{
  int *piVar1;
  uint uVar2;
  ulong uVar3;
  ushort uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined8 extraout_x1;
  byte bVar7;
  ulong *puVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  
  pbVar6 = (byte *)FUN_fffffff0270be6dc(param_1,4,0xf);
  uVar16 = *(ulong *)(pbVar6 + 0x28);
  uVar3 = *(ulong *)(pbVar6 + 0x30);
  if (uVar3 <= uVar16) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              (
              "%s: Corrupted prepare_fw_unmap_data, cur_mapping greater than num_mappings %p %zu %zu"
              );
  }
  puVar8 = (ulong *)0x0;
  lVar12 = *(long *)(pbVar6 + 0x20);
  uVar15 = uVar16 + 1;
  uVar14 = lVar12 + uVar16 * 0x4000;
  uVar16 = 1;
  do {
    if (((ulong)puVar8 & 0x3fff) == 0) {
      uVar13 = FUN_fffffff0270acda8
                         (pbVar6,(uint)(uVar14 >>
                                       ((ulong)*(byte *)(DAT_fffffff0270921b8 + 0x1a1) & 0x3f)) & 1)
      ;
      puVar8 = (ulong *)FUN_fffffff0270ace00(uVar13,uVar14,3,0);
    }
    uVar9 = *puVar8;
    if ((~(uint)uVar9 & 3) == 0) {
      uVar2 = (uint)uVar9 >> 4 & 0xc;
      uVar5 = (uint)(uVar9 >> 0x35);
      if (((uVar9 & 0x1c) == 0) && ((uVar2 | uVar5 & 2) == 2 || (uVar2 | uVar5 & 3) - 5 < 3)) {
        *puVar8 = uVar9 | 8;
        pbVar6[0x38] = 1;
      }
    }
    if ((uVar15 != uVar3) && (*(ulong *)(DAT_fffffff0270921b8 + 0x1b8) <= uVar16)) {
      *(ulong *)(pbVar6 + 0x28) = uVar15;
      bVar7 = 4;
      uVar13 = 1;
      goto LAB_fffffff0270ad798;
    }
    puVar8 = puVar8 + 1;
    uVar15 = uVar15 + 1;
    uVar14 = uVar14 + 0x4000;
    uVar16 = uVar16 + 1;
  } while (uVar15 - uVar3 != 1);
  if ((pbVar6[0x38] & 1) == 0) {
    uVar13 = 0;
    goto LAB_fffffff0270ad794;
  }
  DataSynchronizationBarrier(0,2,0);
  FUN_fffffff0270ac080(pbVar6,lVar12,uVar3 << 0xe,1);
  uVar4 = *(ushort *)(pbVar6 + 0x18);
  if ((ulong)uVar4 < 0x41) {
    lVar11 = *(long *)(DAT_fffffff0270921b8 + 0x138);
    piVar1 = (int *)(lVar11 + 0x20 + (ulong)uVar4 * 0x18);
    if (*piVar1 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f353c
                (0x4000014,extraout_x1,
                 "%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx), %s(%#llx)\n");
    }
    *(long *)(piVar1 + 2) = lVar12;
    *(ulong *)(piVar1 + 4) = uVar3 << 0xe;
    if ((*(byte *)(lVar11 + 0x638) & 1) == 0) {
      uVar13 = 2;
      iVar10 = 1;
      if (((*pbVar6 & 5) != 0) && (*(uint *)(lVar11 + 0x18) != (uint)uVar4))
      goto LAB_fffffff0270ad758;
    }
    else {
LAB_fffffff0270ad758:
      uVar13 = 0;
      *(ulong *)(piVar1 + 2) = *(ulong *)(piVar1 + 2) & 0xffffffffffff;
      *(ulong *)(piVar1 + 2) = *(ulong *)(piVar1 + 2) | 0xdead000000000000;
      iVar10 = 2;
    }
    *piVar1 = iVar10;
  }
  else {
    uVar13 = 0;
  }
  DataSynchronizationBarrier(0,3,0);
LAB_fffffff0270ad794:
  bVar7 = 2;
LAB_fffffff0270ad798:
  if (pbVar6[0x1a] != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: state_guard_release - %#llx, %#llx");
  }
  pbVar6[0x1a] = bVar7;
  if ((*pbVar6 & 5) != 0) {
    FUN_fffffff0270d2f50();
    FUN_fffffff0270dfc5c();
  }
  return uVar13;
}

