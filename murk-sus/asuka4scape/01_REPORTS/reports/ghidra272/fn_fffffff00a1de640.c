// FUN_fffffff00a1de640 @ fffffff00a1de640 size=612

void FUN_fffffff00a1de640(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined *puVar6;
  undefined4 uVar7;
  long lVar8;
  long *plVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  
  if (DAT_fffffff007c6a5b8 < 9) {
    lVar8 = tpidr_el1;
    uVar7 = (undefined4)
            *(undefined8 *)(PTR_DAT_fffffff00ad0e4a8 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
    lVar8 = tpidr_el1;
    uVar10 = (undefined4)
             *(undefined8 *)(PTR_DAT_fffffff00ad0e498 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
  }
  else {
    if (PTR_DAT_fffffff00ad0e4a8 < PTR_DAT_fffffff00ad0e4a8 + (ulong)DAT_fffffff007bc7180 * 0x4000)
    {
      lVar8 = 0;
      plVar9 = (long *)PTR_DAT_fffffff00ad0e4a8;
      do {
        lVar8 = *plVar9 + lVar8;
        uVar7 = (undefined4)lVar8;
        plVar9 = plVar9 + 0x800;
      } while (plVar9 < PTR_DAT_fffffff00ad0e4a8 + (ulong)DAT_fffffff007bc7180 * 0x4000);
    }
    else {
      uVar7 = 0;
    }
    if (PTR_DAT_fffffff00ad0e498 < PTR_DAT_fffffff00ad0e498 + (ulong)DAT_fffffff007bc7180 * 0x4000)
    {
      lVar8 = 0;
      plVar9 = (long *)PTR_DAT_fffffff00ad0e498;
      do {
        lVar8 = *plVar9 + lVar8;
        uVar10 = (undefined4)lVar8;
        plVar9 = plVar9 + 0x800;
      } while (plVar9 < PTR_DAT_fffffff00ad0e498 + (ulong)DAT_fffffff007bc7180 * 0x4000);
    }
    else {
      uVar10 = 0;
    }
  }
  *param_1 = 0xbfcabcde;
  uVar4 = DAT_fffffff00ad95318;
  uVar3 = DAT_fffffff00ad95310;
  param_1[1] = DAT_fffffff00ad95310;
  param_1[2] = uVar4;
  param_1[3] = DAT_fffffff00ad9531c;
  uVar4 = DAT_fffffff00ad95320;
  if (DAT_fffffff007c6a5b8 < 9) {
    lVar8 = tpidr_el1;
    uVar12 = (undefined4)
             *(undefined8 *)(PTR_DAT_fffffff00ad18f30 + (ulong)*(ushort *)(lVar8 + 0x1b0) * 0x4000);
  }
  else if (PTR_DAT_fffffff00ad18f30 <
           PTR_DAT_fffffff00ad18f30 + (ulong)DAT_fffffff007bc7180 * 0x4000) {
    lVar8 = 0;
    plVar9 = (long *)PTR_DAT_fffffff00ad18f30;
    do {
      lVar8 = *plVar9 + lVar8;
      uVar12 = (undefined4)lVar8;
      plVar9 = plVar9 + 0x800;
    } while (plVar9 < PTR_DAT_fffffff00ad18f30 + (ulong)DAT_fffffff007bc7180 * 0x4000);
  }
  else {
    uVar12 = 0;
  }
  iVar11 = 0;
  param_1[4] = uVar12;
  param_1[5] = uVar4;
  uVar4 = DAT_fffffff00ad95314;
  *(undefined4 *)((long)param_1 + 0x3d) = DAT_fffffff00ad94ce0;
  uVar12 = DAT_fffffff00ad95324;
  param_1[6] = uVar4;
  param_1[7] = uVar12;
  param_1[0xc] = DAT_fffffff00ad7204c + DAT_fffffff00adc8820;
  param_1[8] = DAT_fffffff00ad94cd8;
  param_1[9] = uVar7;
  param_1[10] = uVar10;
  param_1[0xb] = DAT_fffffff00adbb42c;
  puVar1 = &DAT_fffffff00ad94f60;
  if ((DAT_fffffff00ad0e3d0 & 1) == 0) {
    puVar1 = &DAT_fffffff00ad94f5c;
  }
  *(undefined4 *)((long)param_1 + 0x41) = *puVar1;
  *(undefined4 *)((long)param_1 + 0x45) = DAT_fffffff00ad94f6c;
  uVar13 = 8;
  if (DAT_fffffff00ad46154 != 0) {
    uVar13 = DAT_fffffff00ad46154 - 1;
  }
  iVar14 = -0x27;
  do {
    puVar6 = &DAT_fffffff00ad46158 + (ulong)uVar13 * 0x3f8;
    if ((((ulong)puVar6 ^ 0xfffffff00ad46158) & 0xffc0000000000000) != 0) {
      puVar6 = (undefined *)((ulong)puVar6 & 0xffffffffffff | 0xc8a2000000000000);
    }
    iVar11 = (int)*(undefined8 *)(puVar6 + 0x238) +
             (int)((ulong)*(undefined8 *)(puVar6 + 0x238) >> 0x20) +
             (int)*(undefined8 *)(puVar6 + 0x240) +
             (int)((ulong)*(undefined8 *)(puVar6 + 0x240) >> 0x20) + iVar11;
    uVar2 = uVar13 - 1;
    bVar5 = uVar13 != 0;
    uVar13 = 8;
    if (bVar5) {
      uVar13 = uVar2;
    }
  } while ((uVar13 != DAT_fffffff00ad46154) && (bVar5 = iVar14 != 0, iVar14 = iVar14 + 1, bVar5));
  iVar14 = 0;
  if (uVar3 <= DAT_fffffff00ad94868) {
    iVar14 = DAT_fffffff00ad94868 - uVar3;
  }
  param_1[0xd] = iVar14;
  param_1[0xe] = iVar11;
  *(undefined1 *)(param_1 + 0xf) = 1;
  return;
}

