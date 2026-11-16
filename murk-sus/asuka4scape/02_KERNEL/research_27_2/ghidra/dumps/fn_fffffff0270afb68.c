// FUN_fffffff0270afb68 @ fffffff0270afb68 size=4608
// CALLERS:
//   fffffff02701f038 no-fn
// CALLEES:
//   fffffff0270b1214 FUN_fffffff0270b1214
//   fffffff0270b142c FUN_fffffff0270b142c
//   fffffff0270dfaa8 FUN_fffffff0270dfaa8
//   fffffff0270dffd4 FUN_fffffff0270dffd4
//   fffffff0270d4cd4 FUN_fffffff0270d4cd4
//   fffffff0270e07e8 FUN_fffffff0270e07e8
//   fffffff0270dfe50 FUN_fffffff0270dfe50
//   fffffff0270a6ac8 FUN_fffffff0270a6ac8
//   fffffff0270d3dec FUN_fffffff0270d3dec
//   fffffff0270b0d68 FUN_fffffff0270b0d68
//   fffffff0270f46b4 FUN_fffffff0270f46b4
//   fffffff0270dfbbc FUN_fffffff0270dfbbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0270afb68(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  undefined *puVar6;
  bool bVar7;
  int iVar8;
  long lVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  undefined8 in_x6;
  undefined8 in_x7;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong *puVar16;
  ulong uVar17;
  byte *pbVar18;
  long lVar19;
  long lVar20;
  undefined *puVar21;
  char *pcVar22;
  ulong **ppuVar23;
  undefined *puVar24;
  undefined8 local_c8;
  int local_bc;
  ulong *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  ulong *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  local_70 = DAT_fffffff027100000;
  FUN_fffffff0270dfe50("UAT Global");
  DAT_fffffff0270921b8 = FUN_fffffff0270e07e8();
  puVar6 = PTR_DAT_fffffff027090600;
  if (DAT_fffffff0270921b8 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: uat_instance is NULL");
  }
  if (PTR_DAT_fffffff027090600 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: Error getting SecureDT");
  }
  local_c8 = 0;
  iVar8 = FUN_fffffff0270b1214(PTR_DAT_fffffff027090600,0,"/arm-io/sgx",&local_c8);
  uVar11 = local_c8;
  if (iVar8 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: error %d looking up /arm-io/sgx");
  }
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0._4_4_ << 0x20);
  iVar8 = FUN_fffffff0270b142c
                    (local_c8,"agx-address-space-mgmt-mode",&local_90,&local_b0,
                     *(undefined8 *)puVar6,*(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
    uVar13 = 0;
    if (local_90 != (ulong *)0x0) {
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b142c
                (uVar11,"agx-address-space-mgmt-mode",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
      uVar13 = (ulong)(uint)*local_90;
    }
  }
  else {
    uVar13 = 0;
  }
  *(ulong *)(DAT_fffffff0270921b8 + 0x10) = uVar13;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"issue-gmmu-tlbis-at-retype",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
    bVar7 = false;
    if (local_90 != (ulong *)0x0) {
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b142c
                (uVar11,"issue-gmmu-tlbis-at-retype",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
      bVar7 = (uint)*local_90 != 0;
    }
  }
  else {
    bVar7 = false;
  }
  *(bool *)(DAT_fffffff0270921b8 + 0x80) = bVar7;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"verify-gmmu-tlbis-at-sync",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  lVar9 = DAT_fffffff0270921b8;
  if (iVar8 == 1) {
    if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
    if (local_90 == (ulong *)0x0) goto LAB_fffffff0270afed4;
    local_90 = (ulong *)0x0;
    local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
    FUN_fffffff0270b142c
              (uVar11,"verify-gmmu-tlbis-at-sync",&local_90,&local_b0,*(undefined8 *)puVar6,
               *(undefined8 *)(puVar6 + 8));
    lVar9 = DAT_fffffff0270921b8;
    if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
    uVar13 = *local_90;
    *(bool *)(DAT_fffffff0270921b8 + 0x81) = (uint)uVar13 != 0;
    if ((uint)uVar13 != 0) {
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      iVar8 = FUN_fffffff0270b142c
                        (uVar11,"gmmu-tlbi-verification-reg",&local_90,&local_b0,
                         *(undefined8 *)puVar6,*(undefined8 *)(puVar6 + 8));
      if (iVar8 != 1) {
LAB_fffffff0270b0d30:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46b4
                  (
                  "%s: verify-gmmu-tlbis-at-sync is enabled but gmmu-tlbi-verification-reg is not set"
                  );
      }
      if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
      if (local_90 == (ulong *)0x0) goto LAB_fffffff0270b0d30;
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b142c
                (uVar11,"gmmu-tlbi-verification-reg",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
      uVar13 = *local_90;
      if (uVar13 == 0) goto LAB_fffffff0270b0d30;
      if ((uVar13 & 7) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46b4("%s: The GMMU TLBI verification register should be 8B-aligned");
      }
      lVar9 = FUN_fffffff0270d4cd4(uVar13 & 0xffffffffffffc000,1,0);
      *(ulong *)(DAT_fffffff0270921b8 + 0x88) = (uVar13 & 0x3ff8) + lVar9;
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      iVar8 = FUN_fffffff0270b142c
                        (uVar11,"gmmu-tlbi-verification-bit",&local_90,&local_b0,
                         *(undefined8 *)puVar6,*(undefined8 *)(puVar6 + 8));
      if (iVar8 != 1) {
LAB_fffffff0270b0d4c:
                    /* WARNING: Subroutine does not return */
        FUN_fffffff0270f46b4
                  ("%s: gmmu-tlbi-verification-bit (%llu) is unset or out of range [0, 63]");
      }
      if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
      if (local_90 == (ulong *)0x0) goto LAB_fffffff0270b0d4c;
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b142c
                (uVar11,"gmmu-tlbi-verification-bit",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      lVar9 = DAT_fffffff0270921b8;
      if ((int)local_b0 != 4) goto LAB_fffffff0270b04c8;
      if (0x3f < (uint)*local_90) goto LAB_fffffff0270b0d4c;
      *(char *)(DAT_fffffff0270921b8 + 0x90) = (char)(uint)*local_90;
    }
  }
  else {
LAB_fffffff0270afed4:
    *(undefined1 *)(DAT_fffffff0270921b8 + 0x81) = 0;
  }
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gfx-shared-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) {
LAB_fffffff0270b0d14:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: error %d looking up %s");
  }
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  *(ulong *)(lVar9 + 0x128) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gfx-shared-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  uVar13 = *local_90;
  if ((uVar13 < 0x4000) || ((uVar13 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4
              (
              "%s: The ASC carveout region is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar9 + 0x130) = uVar13 >> 0xe;
  FUN_fffffff0270dffd4(*(undefined8 *)(lVar9 + 0x128),uVar13 >> 0xe,1);
  lVar9 = DAT_fffffff0270921b8;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gfx-shared-l2-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  *(ulong *)(lVar9 + 0x118) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gfx-shared-l2-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  if (*local_90 != 0x4000) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4
              ("%s: The TTBR1 shared L2 region size (0x%llx) is not equal to the SPTM_PAGE_SIZE");
  }
  *(undefined8 *)(lVar9 + 0x120) = 1;
  FUN_fffffff0270dffd4(*(undefined8 *)(lVar9 + 0x118),1,1);
  lVar9 = DAT_fffffff0270921b8;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gpu-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  *(ulong *)(lVar9 + 0x68) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gpu-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  uVar13 = *local_90;
  if ((uVar13 < 0x4000) || ((uVar13 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4
              (
              "%s: The TTBAT is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar9 + 0x70) = uVar13 >> 0xe;
  FUN_fffffff0270dffd4(*(undefined8 *)(lVar9 + 0x68),uVar13 >> 0xe,2);
  uVar13 = *(ulong *)(lVar9 + 0x68);
  if (((uint)DAT_fffffff027106040 >> 8 & 1) == 0) {
    lVar9 = (uVar13 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar14 = (ulong)DAT_fffffff0271019f8;
    if (DAT_fffffff0271019f8 != 0) {
      lVar9 = 0;
      do {
        puVar16 = &DAT_fffffff027101a00 + lVar9 * 3;
        if ((((ulong)puVar16 ^ 0xfffffff027101a00) & 0xffc0000000000000) != 0) {
          puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar17 = *puVar16;
        if ((uVar17 <= uVar13) && (uVar13 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
          lVar9 = (uVar13 - uVar17) + puVar16[1];
          goto LAB_fffffff0270b017c;
        }
        lVar9 = lVar9 + 1;
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
    }
    lVar9 = FUN_fffffff0270dfaa8();
  }
LAB_fffffff0270b017c:
  uVar11 = local_c8;
  lVar19 = DAT_fffffff0270921b8;
  *(long *)(DAT_fffffff0270921b8 + 0x78) = lVar9;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (local_c8,"gfx-handoff-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  *(ulong *)(lVar19 + 0x138) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"gfx-handoff-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b0d14;
  if ((int)local_b0 != 8) goto LAB_fffffff0270b04c8;
  uVar13 = *local_90;
  if ((uVar13 < 0x4000) || ((uVar13 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4
              (
              "%s: The Handoff region is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar19 + 0x140) = uVar13 >> 0xe;
  FUN_fffffff0270dffd4(*(undefined8 *)(lVar19 + 0x138),uVar13 >> 0xe,2);
  lVar9 = 0;
  bVar7 = true;
  do {
    bVar5 = bVar7;
    local_80 = 0;
    uStack_78 = 0;
    pcVar22 = "gfx";
    local_90 = (ulong *)0x0;
    uStack_88 = 0;
    if (!bVar5) {
      pcVar22 = (char *)&local_90;
      FUN_fffffff0270b0d68(&local_90);
    }
    lVar19 = 0;
    lVar20 = 3;
    do {
      puVar16 = (ulong *)(DAT_fffffff0270921b8 + 0x150 + lVar9 * 0x30 + lVar19 * 0x10);
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = (byte *)0x0;
      uStack_a8 = 0;
      puVar21 = (&PTR_s__fffffff02701c6d0)[lVar19];
      ppuVar23 = (ulong **)pcVar22;
      puVar24 = puVar21;
      FUN_fffffff0270b0d68(&local_b0);
      local_b8 = (ulong *)0x0;
      local_bc = 0;
      iVar8 = FUN_fffffff0270b142c
                        (uVar11,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                         *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar24);
      if (iVar8 == 1) {
        if (local_bc != 8) goto LAB_fffffff0270b04c8;
        if (local_b8 == (ulong *)0x0) goto LAB_fffffff0270b0380;
        local_b8 = (ulong *)0x0;
        local_bc = 0;
        FUN_fffffff0270b142c
                  (uVar11,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                   *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar24);
        if (local_bc != 8) goto LAB_fffffff0270b04c8;
        uVar13 = *local_b8;
        *puVar16 = uVar13;
        if ((uVar13 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f46b4("%s: The %s data%s segment base(%#llx) is not page-aligned");
        }
      }
      else {
LAB_fffffff0270b0380:
        *puVar16 = 0;
      }
      ppuVar23 = (ulong **)pcVar22;
      FUN_fffffff0270b0d68(&local_b0);
      local_b8 = (ulong *)0x0;
      local_bc = 0;
      iVar8 = FUN_fffffff0270b142c
                        (uVar11,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                         *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
      if (iVar8 == 1) {
        if (local_bc != 8) goto LAB_fffffff0270b04c8;
        if (local_b8 == (ulong *)0x0) goto LAB_fffffff0270b02b8;
        local_b8 = (ulong *)0x0;
        local_bc = 0;
        FUN_fffffff0270b142c
                  (uVar11,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                   *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
        if (local_bc != 8) goto LAB_fffffff0270b04c8;
        uVar13 = *local_b8;
        if ((uVar13 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f46b4
                    ("%s: The %s data%s segment size(%#llx) is not a multiple of the page size");
        }
        puVar16[1] = uVar13 >> 0xe;
        if ((uVar13 != 0) && (*puVar16 != 0)) {
          FUN_fffffff0270dffd4(*puVar16,uVar13 >> 0xe,1);
        }
      }
      else {
LAB_fffffff0270b02b8:
        puVar16[1] = 0;
      }
      lVar19 = lVar19 + 1;
      lVar20 = lVar20 + -1;
    } while (lVar20 != 0);
    lVar9 = 1;
    bVar7 = false;
  } while (bVar5);
  iVar8 = FUN_fffffff0270b1214(puVar6,0,"/defaults",&local_c8);
  uVar11 = local_c8;
  if (iVar8 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f46b4("%s: error %d looking up /defaults");
  }
  local_b0 = (byte *)0x0;
  local_bc = 0;
  iVar8 = FUN_fffffff0270b142c
                    (local_c8,"uat-enforce-gpu-carveout",&local_b0,&local_bc,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
  if (iVar8 == 1) {
    if (local_bc != 4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: uat-enforce-gpu-carveout is not %zu bytes wide (%d)");
    }
    *(bool *)(DAT_fffffff0270921b8 + 0x1b0) = *(int *)local_b0 != 0;
  }
  else {
    *(undefined1 *)(DAT_fffffff0270921b8 + 0x1b0) = 1;
  }
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"uat-vaddr-size",&local_b0,&local_bc,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  lVar9 = DAT_fffffff0270921b8;
  if (iVar8 == 1) {
    if (local_bc != 4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: uat-vaddr-size is %zu bytes wide (%d)");
    }
    bVar3 = *local_b0;
    uVar4 = bVar3 - 1;
    uVar13 = (ulong)uVar4;
    *(char *)(DAT_fffffff0270921b8 + 0x1b1) = (char)uVar4;
    if (8 < bVar3 - 0x28) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4
                (
                "%s: Invalid vaddr size specified in device tree (%d). Valid values are %d to %d inclusive"
                );
    }
  }
  else {
    uVar13 = 0x27;
    *(undefined1 *)(DAT_fffffff0270921b8 + 0x1b1) = 0x27;
  }
  *(ulong *)(lVar9 + 0x1b8) = 0xffffffffffffffffU >> (-(uVar13 & 0xff) & 0x3f) & 0x7ff000000000;
  local_90 = (ulong *)0x0;
  local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"uat-segment-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b8 != 4) goto LAB_fffffff0270b04c8;
    if (local_90 == (ulong *)0x0) goto LAB_fffffff0270b0630;
    local_90 = (ulong *)0x0;
    local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
    FUN_fffffff0270b142c
              (uVar11,"uat-segment-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
               *(undefined8 *)(puVar6 + 8));
    if ((int)local_b8 != 4) goto LAB_fffffff0270b04c8;
    uVar13 = (ulong)(uint)*local_90;
  }
  else {
LAB_fffffff0270b0630:
    uVar13 = 0x40;
  }
  *(ulong *)(DAT_fffffff0270921b8 + 0x1c0) = uVar13;
  local_90 = (ulong *)0x0;
  local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b142c
                    (uVar11,"uat-mapping-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b8 != 4) {
LAB_fffffff0270b04c8:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: %s is not %zu bytes wide (%d)");
    }
    if (local_90 == (ulong *)0x0) goto LAB_fffffff0270b06c4;
    local_90 = (ulong *)0x0;
    local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
    FUN_fffffff0270b142c
              (uVar11,"uat-mapping-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
               *(undefined8 *)(puVar6 + 8));
    if ((int)local_b8 != 4) goto LAB_fffffff0270b04c8;
    uVar13 = (ulong)(uint)*local_90;
  }
  else {
LAB_fffffff0270b06c4:
    uVar13 = 0x100;
  }
  lVar9 = DAT_fffffff0270921b8;
  *(ulong *)(DAT_fffffff0270921b8 + 0x1c8) = uVar13;
  if (*(long *)(lVar9 + 0x10) == 1) {
    if (((uint)DAT_fffffff027106040 >> 7 & 1) != 0) {
LAB_fffffff0270b0be4:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: Unexpected bootstrap stages reached. Expected: %p, Actual: %p");
    }
    puVar10 = (undefined1 *)FUN_fffffff0270dfbbc(10,1);
    *(undefined1 **)(lVar9 + 0x18) = puVar10;
    *puVar10 = 8;
    pbVar18 = *(byte **)(lVar9 + 0x18);
    if (((uint)DAT_fffffff027106040 >> 7 & 1) != 0) goto LAB_fffffff0270b0be4;
    FUN_fffffff0270dfbbc(10,1);
    uVar11 = FUN_fffffff0270d3dec();
    if ((*pbVar18 & 0xe) == 0) {
LAB_fffffff0270b0c58:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f46b4("%s: %d is not a valid UAT state object type when getting TTBR%d");
    }
    *(undefined8 *)(pbVar18 + 0x10) = uVar11;
    lVar19 = *(long *)(lVar9 + 0x18);
    *(undefined2 *)(lVar19 + 0x18) = 0x40;
    *(undefined1 *)(lVar19 + 0x1a) = 2;
    if ((**(byte **)(lVar9 + 0x18) & 0xe) == 0) goto LAB_fffffff0270b0c58;
    uVar13 = *(ulong *)(*(byte **)(lVar9 + 0x18) + 0x10);
    if (((uint)DAT_fffffff027106040 >> 8 & 1) == 0) {
      lVar19 = (uVar13 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
    }
    else {
      uVar14 = (ulong)DAT_fffffff0271019f8;
      if (DAT_fffffff0271019f8 != 0) {
        lVar19 = 0;
        do {
          puVar16 = &DAT_fffffff027101a00 + lVar19 * 3;
          if ((((ulong)puVar16 ^ 0xfffffff027101a00) & 0xffc0000000000000) != 0) {
            puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar17 = *puVar16;
          if ((uVar17 <= uVar13) && (uVar13 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
            lVar19 = (uVar13 - uVar17) + puVar16[1];
            goto LAB_fffffff0270b0940;
          }
          lVar19 = lVar19 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      lVar19 = FUN_fffffff0270dfaa8();
    }
LAB_fffffff0270b0940:
    lVar15 = DAT_fffffff0270921b8;
    *(ulong *)(lVar19 + 0x10) = *(ulong *)(DAT_fffffff0270921b8 + 0x118) & 0xfffffffff000 | 3;
    uVar13 = 0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(lVar15 + 0x1b1) & 0x3f);
    lVar19 = -1L << ((ulong)*(byte *)(lVar15 + 0x1b1) & 0x3f);
    bVar7 = (*(byte *)(lVar15 + 0x1b0) & 1) != 0;
    uVar11 = 0;
    lVar20 = lVar19;
    if (bVar7) {
      uVar11 = 0x1000000000;
      uVar13 = 0x6fffffffff;
      lVar20 = 1;
    }
    uVar2 = 0xffffffffffffffff;
    if (bVar7) {
      uVar2 = 0;
    }
    *(undefined8 *)(lVar9 + 0x20) = uVar11;
    *(long *)(lVar9 + 0x28) = lVar20;
    *(ulong *)(lVar9 + 0x30) = uVar13;
    *(undefined8 *)(lVar9 + 0x38) = uVar2;
    *(undefined8 *)(lVar9 + 0x40) = 1;
    *(long *)(lVar9 + 0x48) = lVar19 + 0x2000000000;
    *(undefined8 *)(lVar9 + 0x50) = 0;
    lVar19 = lVar19 + 0x2fffffffff;
  }
  else {
    lVar15 = lVar9;
    if (*(long *)(lVar9 + 0x10) != 0) goto LAB_fffffff0270b09c8;
    if (((uint)DAT_fffffff027106040 >> 7 & 1) != 0) goto LAB_fffffff0270b0be4;
    puVar10 = (undefined1 *)FUN_fffffff0270dfbbc(10,1);
    *(undefined1 **)(lVar9 + 0x18) = puVar10;
    *puVar10 = 2;
    pbVar18 = *(byte **)(lVar9 + 0x18);
    if (((uint)DAT_fffffff027106040 >> 7 & 1) != 0) goto LAB_fffffff0270b0be4;
    FUN_fffffff0270dfbbc(10,1);
    uVar11 = FUN_fffffff0270d3dec();
    if ((*pbVar18 & 0xe) == 0) goto LAB_fffffff0270b0c58;
    *(undefined8 *)(pbVar18 + 0x10) = uVar11;
    lVar19 = *(long *)(lVar9 + 0x18);
    *(undefined2 *)(lVar19 + 0x18) = 0x40;
    *(undefined1 *)(lVar19 + 0x1a) = 2;
    if ((**(byte **)(lVar9 + 0x18) & 0xe) == 0) goto LAB_fffffff0270b0c58;
    uVar13 = *(ulong *)(*(byte **)(lVar9 + 0x18) + 0x10);
    if (((uint)DAT_fffffff027106040 >> 8 & 1) == 0) {
      lVar19 = (uVar13 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
    }
    else {
      uVar14 = (ulong)DAT_fffffff0271019f8;
      if (DAT_fffffff0271019f8 != 0) {
        lVar19 = 0;
        do {
          puVar16 = &DAT_fffffff027101a00 + lVar19 * 3;
          if ((((ulong)puVar16 ^ 0xfffffff027101a00) & 0xffc0000000000000) != 0) {
            puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar17 = *puVar16;
          if ((uVar17 <= uVar13) && (uVar13 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
            lVar19 = (uVar13 - uVar17) + puVar16[1];
            goto LAB_fffffff0270b08c4;
          }
          lVar19 = lVar19 + 1;
          uVar14 = uVar14 - 1;
        } while (uVar14 != 0);
      }
      lVar19 = FUN_fffffff0270dfaa8();
    }
LAB_fffffff0270b08c4:
    lVar15 = DAT_fffffff0270921b8;
    *(ulong *)(lVar19 + 0x10) = *(ulong *)(DAT_fffffff0270921b8 + 0x118) & 0xfffffffff000 | 3;
    bVar3 = *(byte *)(lVar15 + 0x1b1);
    lVar19 = -1;
    bVar7 = (*(byte *)(lVar15 + 0x1b0) & 1) == 0;
    uVar11 = 0x1000000000;
    if (bVar7) {
      uVar11 = 0;
    }
    uVar13 = 0x6fffffffff;
    if (bVar7) {
      uVar13 = 0xffffffffffffffff >> ((ulong)-(uint)bVar3 & 0x3f);
    }
    *(undefined8 *)(lVar9 + 0x20) = uVar11;
    *(undefined8 *)(lVar9 + 0x28) = 1;
    *(ulong *)(lVar9 + 0x30) = uVar13;
    uVar11 = _DAT_fffffff027019e20;
    *(undefined8 *)(lVar9 + 0x40) = _UNK_fffffff027019e28;
    *(undefined8 *)(lVar9 + 0x38) = uVar11;
    *(long *)(lVar9 + 0x48) = -1L << ((ulong)bVar3 & 0x3f);
    *(undefined8 *)(lVar9 + 0x50) = 0;
  }
  *(long *)(lVar9 + 0x58) = lVar19;
LAB_fffffff0270b09c8:
  *(undefined1 *)(lVar15 + 0x60) = 0;
  uVar13 = *(ulong *)(lVar15 + 0x138);
  if (((uint)DAT_fffffff027106040 >> 8 & 1) == 0) {
    puVar12 = (undefined8 *)((uVar13 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0);
  }
  else {
    uVar14 = (ulong)DAT_fffffff0271019f8;
    if (DAT_fffffff0271019f8 != 0) {
      lVar9 = 0;
      do {
        puVar16 = &DAT_fffffff027101a00 + lVar9 * 3;
        if ((((ulong)puVar16 ^ 0xfffffff027101a00) & 0xffc0000000000000) != 0) {
          puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar17 = *puVar16;
        if ((uVar17 <= uVar13) && (uVar13 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
          puVar12 = (undefined8 *)((uVar13 - uVar17) + puVar16[1]);
          goto LAB_fffffff0270b0a40;
        }
        lVar9 = lVar9 + 1;
        uVar14 = uVar14 - 1;
      } while (uVar14 != 0);
    }
    puVar12 = (undefined8 *)FUN_fffffff0270dfaa8();
  }
LAB_fffffff0270b0a40:
  lVar9 = 0;
  *puVar12 = 0x4b1d000000000003;
  *(undefined4 *)(puVar12 + 3) = 0xffff;
  puVar12[200] = 0;
  *(undefined1 *)(puVar12 + 199) = 1;
  lVar19 = 0x41;
  do {
    puVar1 = puVar12 + lVar9 * 3 + 4;
    *(undefined4 *)puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    lVar20 = DAT_fffffff0270921b8;
    lVar9 = lVar9 + 1;
    lVar19 = lVar19 + -1;
  } while (lVar19 != 0);
  *(undefined1 *)(DAT_fffffff0270921b8 + 0x91) = 0;
  *(undefined1 *)(puVar12 + 2) = 0;
  *(undefined1 *)((long)puVar12 + 0x11) = 0;
  *(undefined4 *)((long)puVar12 + 0x14) = 1;
  *(undefined1 *)(puVar12 + 0xc9) = 0;
  *(undefined8 **)(lVar20 + 0x148) = puVar12;
  *(long *)(lVar20 + 0x1d0) = *(long *)(lVar20 + 0x1c0) * 0x10 + 0x48;
  if (DAT_fffffff027100000 == local_70) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270a6ac8();
}

