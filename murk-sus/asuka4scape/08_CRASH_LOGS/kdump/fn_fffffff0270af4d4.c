// FUN_fffffff0270af4d4 @ fffffff0270af4d4 size=4040
// CALLERS:
//   fffffff02701f030 ?
// CALLS:
//   fffffff0270df91c FUN_fffffff0270df91c
//   fffffff0270df108 FUN_fffffff0270df108
//   fffffff0270b049c FUN_fffffff0270b049c
//   fffffff0270decf0 FUN_fffffff0270decf0
//   fffffff0270b0ac8 FUN_fffffff0270b0ac8
//   fffffff0270debdc FUN_fffffff0270debdc
//   fffffff0270def84 FUN_fffffff0270def84
//   fffffff0270d2f50 FUN_fffffff0270d2f50
//   fffffff0270a6ac4 FUN_fffffff0270a6ac4
//   fffffff0270f34fc FUN_fffffff0270f34fc
//   fffffff0270b08b0 FUN_fffffff0270b08b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_fffffff0270af4d4(void)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  undefined *puVar6;
  bool bVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 in_x6;
  undefined8 in_x7;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
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
  
  local_70 = DAT_fffffff0270fc000;
  FUN_fffffff0270def84("UAT Global");
  DAT_fffffff0270921b8 = FUN_fffffff0270df91c();
  puVar6 = PTR_DAT_fffffff027090600;
  if (DAT_fffffff0270921b8 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: uat_instance is NULL");
  }
  if (PTR_DAT_fffffff027090600 == (undefined *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: Error getting SecureDT");
  }
  local_c8 = 0;
  iVar8 = FUN_fffffff0270b08b0(PTR_DAT_fffffff027090600,0,"/arm-io/sgx",&local_c8);
  uVar10 = local_c8;
  if (iVar8 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: error %d looking up /arm-io/sgx");
  }
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0._4_4_ << 0x20);
  iVar8 = FUN_fffffff0270b0ac8
                    (local_c8,"agx-address-space-mgmt-mode",&local_90,&local_b0,
                     *(undefined8 *)puVar6,*(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b0 != 4) goto LAB_fffffff0270afc60;
    uVar12 = 0;
    if (local_90 != (ulong *)0x0) {
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b0ac8
                (uVar10,"agx-address-space-mgmt-mode",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      if ((int)local_b0 != 4) goto LAB_fffffff0270afc60;
      uVar12 = (ulong)(uint)*local_90;
    }
  }
  else {
    uVar12 = 0;
  }
  *(ulong *)(DAT_fffffff0270921b8 + 0x10) = uVar12;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"issue-gmmu-tlbis-at-retype",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b0 != 4) goto LAB_fffffff0270afc60;
    bVar7 = false;
    if (local_90 != (ulong *)0x0) {
      local_90 = (ulong *)0x0;
      local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
      FUN_fffffff0270b0ac8
                (uVar10,"issue-gmmu-tlbis-at-retype",&local_90,&local_b0,*(undefined8 *)puVar6,
                 *(undefined8 *)(puVar6 + 8));
      if ((int)local_b0 != 4) goto LAB_fffffff0270afc60;
      bVar7 = (uint)*local_90 != 0;
    }
  }
  else {
    bVar7 = false;
  }
  lVar15 = DAT_fffffff0270921b8;
  *(bool *)(DAT_fffffff0270921b8 + 0x80) = bVar7;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gfx-shared-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) {
LAB_fffffff0270b047c:
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: error %d looking up %s");
  }
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  *(ulong *)(lVar15 + 0x118) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gfx-shared-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  uVar12 = *local_90;
  if ((uVar12 < 0x4000) || ((uVar12 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              (
              "%s: The ASC carveout region is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar15 + 0x120) = uVar12 >> 0xe;
  FUN_fffffff0270df108(*(undefined8 *)(lVar15 + 0x118),uVar12 >> 0xe,1);
  lVar15 = DAT_fffffff0270921b8;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gfx-shared-l2-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  *(ulong *)(lVar15 + 0x108) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gfx-shared-l2-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  if (*local_90 != 0x4000) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              ("%s: The TTBR1 shared L2 region size (0x%llx) is not equal to the SPTM_PAGE_SIZE");
  }
  *(undefined8 *)(lVar15 + 0x110) = 1;
  FUN_fffffff0270df108(*(undefined8 *)(lVar15 + 0x108),1,1);
  lVar15 = DAT_fffffff0270921b8;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gpu-region-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  *(ulong *)(lVar15 + 0x68) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gpu-region-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  uVar12 = *local_90;
  if ((uVar12 < 0x4000) || ((uVar12 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              (
              "%s: The TTBAT is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar15 + 0x70) = uVar12 >> 0xe;
  FUN_fffffff0270df108(*(undefined8 *)(lVar15 + 0x68),uVar12 >> 0xe,2);
  uVar12 = *(ulong *)(lVar15 + 0x68);
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    lVar15 = (uVar12 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar13 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar15 = 0;
      do {
        puVar16 = &DAT_fffffff0270fda00 + lVar15 * 3;
        if ((((ulong)puVar16 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar17 = *puVar16;
        if ((uVar17 <= uVar12) && (uVar12 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
          lVar15 = (uVar12 - uVar17) + puVar16[1];
          goto LAB_fffffff0270af914;
        }
        lVar15 = lVar15 + 1;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    lVar15 = FUN_fffffff0270debdc();
  }
LAB_fffffff0270af914:
  uVar10 = local_c8;
  lVar19 = DAT_fffffff0270921b8;
  *(long *)(DAT_fffffff0270921b8 + 0x78) = lVar15;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (local_c8,"gfx-handoff-base",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  *(ulong *)(lVar19 + 0x128) = *local_90;
  local_90 = (ulong *)0x0;
  local_b0 = (byte *)((ulong)local_b0 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"gfx-handoff-size",&local_90,&local_b0,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 != 1) goto LAB_fffffff0270b047c;
  if ((int)local_b0 != 8) goto LAB_fffffff0270afc60;
  uVar12 = *local_90;
  if ((uVar12 < 0x4000) || ((uVar12 & 0x3fff) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc
              (
              "%s: The Handoff region is smaller than a page in size or not a multiple of the SPTM_PAGE_SIZE %llu"
              );
  }
  *(ulong *)(lVar19 + 0x130) = uVar12 >> 0xe;
  FUN_fffffff0270df108(*(undefined8 *)(lVar19 + 0x128),uVar12 >> 0xe,2);
  lVar15 = 0;
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
      FUN_fffffff0270b049c(&local_90);
    }
    lVar19 = 0;
    lVar20 = 3;
    do {
      puVar16 = (ulong *)(DAT_fffffff0270921b8 + 0x140 + lVar15 * 0x30 + lVar19 * 0x10);
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = (byte *)0x0;
      uStack_a8 = 0;
      puVar21 = (&PTR_s__fffffff02701c6d0)[lVar19];
      ppuVar23 = (ulong **)pcVar22;
      puVar24 = puVar21;
      FUN_fffffff0270b049c(&local_b0);
      local_b8 = (ulong *)0x0;
      local_bc = 0;
      iVar8 = FUN_fffffff0270b0ac8
                        (uVar10,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                         *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar24);
      if (iVar8 == 1) {
        if (local_bc != 8) goto LAB_fffffff0270afc60;
        if (local_b8 == (ulong *)0x0) goto LAB_fffffff0270afb18;
        local_b8 = (ulong *)0x0;
        local_bc = 0;
        FUN_fffffff0270b0ac8
                  (uVar10,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                   *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar24);
        if (local_bc != 8) goto LAB_fffffff0270afc60;
        uVar12 = *local_b8;
        *puVar16 = uVar12;
        if ((uVar12 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc("%s: The %s data%s segment base(%#llx) is not page-aligned");
        }
      }
      else {
LAB_fffffff0270afb18:
        *puVar16 = 0;
      }
      ppuVar23 = (ulong **)pcVar22;
      FUN_fffffff0270b049c(&local_b0);
      local_b8 = (ulong *)0x0;
      local_bc = 0;
      iVar8 = FUN_fffffff0270b0ac8
                        (uVar10,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                         *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
      if (iVar8 == 1) {
        if (local_bc != 8) goto LAB_fffffff0270afc60;
        if (local_b8 == (ulong *)0x0) goto LAB_fffffff0270afa50;
        local_b8 = (ulong *)0x0;
        local_bc = 0;
        FUN_fffffff0270b0ac8
                  (uVar10,&local_b0,&local_b8,&local_bc,*(undefined8 *)puVar6,
                   *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
        if (local_bc != 8) goto LAB_fffffff0270afc60;
        uVar12 = *local_b8;
        if ((uVar12 & 0x3fff) != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_fffffff0270f34fc
                    ("%s: The %s data%s segment size(%#llx) is not a multiple of the page size");
        }
        puVar16[1] = uVar12 >> 0xe;
        if ((uVar12 != 0) && (*puVar16 != 0)) {
          FUN_fffffff0270df108(*puVar16,uVar12 >> 0xe,1);
        }
      }
      else {
LAB_fffffff0270afa50:
        puVar16[1] = 0;
      }
      lVar19 = lVar19 + 1;
      lVar20 = lVar20 + -1;
    } while (lVar20 != 0);
    lVar15 = 1;
    bVar7 = false;
  } while (bVar5);
  iVar8 = FUN_fffffff0270b08b0(puVar6,0,"/defaults",&local_c8);
  uVar10 = local_c8;
  if (iVar8 != 1) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f34fc("%s: error %d looking up /defaults");
  }
  local_b0 = (byte *)0x0;
  local_bc = 0;
  iVar8 = FUN_fffffff0270b0ac8
                    (local_c8,"uat-enforce-gpu-carveout",&local_b0,&local_bc,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8),in_x6,in_x7,ppuVar23,puVar21);
  if (iVar8 == 1) {
    if (local_bc != 4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: uat-enforce-gpu-carveout is not %zu bytes wide (%d)");
    }
    *(bool *)(DAT_fffffff0270921b8 + 0x1a0) = *(int *)local_b0 != 0;
  }
  else {
    *(undefined1 *)(DAT_fffffff0270921b8 + 0x1a0) = 1;
  }
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"uat-vaddr-size",&local_b0,&local_bc,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  lVar15 = DAT_fffffff0270921b8;
  if (iVar8 == 1) {
    if (local_bc != 4) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: uat-vaddr-size is %zu bytes wide (%d)");
    }
    bVar3 = *local_b0;
    uVar4 = bVar3 - 1;
    uVar12 = (ulong)uVar4;
    *(char *)(DAT_fffffff0270921b8 + 0x1a1) = (char)uVar4;
    if (8 < bVar3 - 0x28) {
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc
                (
                "%s: Invalid vaddr size specified in device tree (%d). Valid values are %d to %d inclusive"
                );
    }
  }
  else {
    uVar12 = 0x27;
    *(undefined1 *)(DAT_fffffff0270921b8 + 0x1a1) = 0x27;
  }
  *(ulong *)(lVar15 + 0x1a8) = 0xffffffffffffffffU >> (-(uVar12 & 0xff) & 0x3f) & 0x7ff000000000;
  local_90 = (ulong *)0x0;
  local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"uat-segment-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b8 != 4) goto LAB_fffffff0270afc60;
    if (local_90 == (ulong *)0x0) goto LAB_fffffff0270afdc8;
    local_90 = (ulong *)0x0;
    local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
    FUN_fffffff0270b0ac8
              (uVar10,"uat-segment-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
               *(undefined8 *)(puVar6 + 8));
    if ((int)local_b8 != 4) goto LAB_fffffff0270afc60;
    uVar12 = (ulong)(uint)*local_90;
  }
  else {
LAB_fffffff0270afdc8:
    uVar12 = 0x40;
  }
  *(ulong *)(DAT_fffffff0270921b8 + 0x1b0) = uVar12;
  local_90 = (ulong *)0x0;
  local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
  iVar8 = FUN_fffffff0270b0ac8
                    (uVar10,"uat-mapping-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
                     *(undefined8 *)(puVar6 + 8));
  if (iVar8 == 1) {
    if ((int)local_b8 != 4) {
LAB_fffffff0270afc60:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: %s is not %zu bytes wide (%d)");
    }
    if (local_90 == (ulong *)0x0) goto LAB_fffffff0270afe5c;
    local_90 = (ulong *)0x0;
    local_b8 = (ulong *)((ulong)local_b8 & 0xffffffff00000000);
    FUN_fffffff0270b0ac8
              (uVar10,"uat-mapping-limit",&local_90,&local_b8,*(undefined8 *)puVar6,
               *(undefined8 *)(puVar6 + 8));
    if ((int)local_b8 != 4) goto LAB_fffffff0270afc60;
    uVar12 = (ulong)(uint)*local_90;
  }
  else {
LAB_fffffff0270afe5c:
    uVar12 = 0x100;
  }
  lVar15 = DAT_fffffff0270921b8;
  *(ulong *)(DAT_fffffff0270921b8 + 0x1b8) = uVar12;
  if (*(long *)(lVar15 + 0x10) == 1) {
    if (((uint)DAT_fffffff027102040 >> 7 & 1) != 0) {
LAB_fffffff0270b0364:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: Unexpected bootstrap stages reached. Expected: %p, Actual: %p");
    }
    puVar9 = (undefined1 *)FUN_fffffff0270decf0(10,1);
    *(undefined1 **)(lVar15 + 0x18) = puVar9;
    *puVar9 = 8;
    pbVar18 = *(byte **)(lVar15 + 0x18);
    if (((uint)DAT_fffffff027102040 >> 7 & 1) != 0) goto LAB_fffffff0270b0364;
    FUN_fffffff0270decf0(10,1);
    uVar10 = FUN_fffffff0270d2f50();
    if ((*pbVar18 & 0xe) == 0) {
LAB_fffffff0270b03d8:
                    /* WARNING: Subroutine does not return */
      FUN_fffffff0270f34fc("%s: %d is not a valid UAT state object type when getting TTBR%d");
    }
    *(undefined8 *)(pbVar18 + 0x10) = uVar10;
    lVar19 = *(long *)(lVar15 + 0x18);
    *(undefined2 *)(lVar19 + 0x18) = 0x40;
    *(undefined1 *)(lVar19 + 0x1a) = 2;
    if ((**(byte **)(lVar15 + 0x18) & 0xe) == 0) goto LAB_fffffff0270b03d8;
    uVar12 = *(ulong *)(*(byte **)(lVar15 + 0x18) + 0x10);
    if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
      lVar19 = (uVar12 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
    }
    else {
      uVar13 = (ulong)DAT_fffffff0270fd9f8;
      if (DAT_fffffff0270fd9f8 != 0) {
        lVar19 = 0;
        do {
          puVar16 = &DAT_fffffff0270fda00 + lVar19 * 3;
          if ((((ulong)puVar16 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
            puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar17 = *puVar16;
          if ((uVar17 <= uVar12) && (uVar12 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
            lVar19 = (uVar12 - uVar17) + puVar16[1];
            goto LAB_fffffff0270b00d8;
          }
          lVar19 = lVar19 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      lVar19 = FUN_fffffff0270debdc();
    }
LAB_fffffff0270b00d8:
    lVar14 = DAT_fffffff0270921b8;
    *(ulong *)(lVar19 + 0x10) = *(ulong *)(DAT_fffffff0270921b8 + 0x108) & 0xfffffffff000 | 3;
    uVar12 = 0xffffffffffffffff >> ((ulong)-(uint)*(byte *)(lVar14 + 0x1a1) & 0x3f);
    lVar19 = -1L << ((ulong)*(byte *)(lVar14 + 0x1a1) & 0x3f);
    bVar7 = (*(byte *)(lVar14 + 0x1a0) & 1) != 0;
    uVar10 = 0;
    lVar20 = lVar19;
    if (bVar7) {
      uVar10 = 0x1000000000;
      uVar12 = 0x6fffffffff;
      lVar20 = 1;
    }
    uVar2 = 0xffffffffffffffff;
    if (bVar7) {
      uVar2 = 0;
    }
    *(undefined8 *)(lVar15 + 0x20) = uVar10;
    *(long *)(lVar15 + 0x28) = lVar20;
    *(ulong *)(lVar15 + 0x30) = uVar12;
    *(undefined8 *)(lVar15 + 0x38) = uVar2;
    *(undefined8 *)(lVar15 + 0x40) = 1;
    *(long *)(lVar15 + 0x48) = lVar19 + 0x2000000000;
    *(undefined8 *)(lVar15 + 0x50) = 0;
    lVar19 = lVar19 + 0x2fffffffff;
  }
  else {
    lVar14 = lVar15;
    if (*(long *)(lVar15 + 0x10) != 0) goto LAB_fffffff0270b0160;
    if (((uint)DAT_fffffff027102040 >> 7 & 1) != 0) goto LAB_fffffff0270b0364;
    puVar9 = (undefined1 *)FUN_fffffff0270decf0(10,1);
    *(undefined1 **)(lVar15 + 0x18) = puVar9;
    *puVar9 = 2;
    pbVar18 = *(byte **)(lVar15 + 0x18);
    if (((uint)DAT_fffffff027102040 >> 7 & 1) != 0) goto LAB_fffffff0270b0364;
    FUN_fffffff0270decf0(10,1);
    uVar10 = FUN_fffffff0270d2f50();
    if ((*pbVar18 & 0xe) == 0) goto LAB_fffffff0270b03d8;
    *(undefined8 *)(pbVar18 + 0x10) = uVar10;
    lVar19 = *(long *)(lVar15 + 0x18);
    *(undefined2 *)(lVar19 + 0x18) = 0x40;
    *(undefined1 *)(lVar19 + 0x1a) = 2;
    if ((**(byte **)(lVar15 + 0x18) & 0xe) == 0) goto LAB_fffffff0270b03d8;
    uVar12 = *(ulong *)(*(byte **)(lVar15 + 0x18) + 0x10);
    if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
      lVar19 = (uVar12 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
    }
    else {
      uVar13 = (ulong)DAT_fffffff0270fd9f8;
      if (DAT_fffffff0270fd9f8 != 0) {
        lVar19 = 0;
        do {
          puVar16 = &DAT_fffffff0270fda00 + lVar19 * 3;
          if ((((ulong)puVar16 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
            puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
          }
          uVar17 = *puVar16;
          if ((uVar17 <= uVar12) && (uVar12 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
            lVar19 = (uVar12 - uVar17) + puVar16[1];
            goto LAB_fffffff0270b005c;
          }
          lVar19 = lVar19 + 1;
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
      }
      lVar19 = FUN_fffffff0270debdc();
    }
LAB_fffffff0270b005c:
    lVar14 = DAT_fffffff0270921b8;
    *(ulong *)(lVar19 + 0x10) = *(ulong *)(DAT_fffffff0270921b8 + 0x108) & 0xfffffffff000 | 3;
    bVar3 = *(byte *)(lVar14 + 0x1a1);
    lVar19 = -1;
    bVar7 = (*(byte *)(lVar14 + 0x1a0) & 1) == 0;
    uVar10 = 0x1000000000;
    if (bVar7) {
      uVar10 = 0;
    }
    uVar12 = 0x6fffffffff;
    if (bVar7) {
      uVar12 = 0xffffffffffffffff >> ((ulong)-(uint)bVar3 & 0x3f);
    }
    *(undefined8 *)(lVar15 + 0x20) = uVar10;
    *(undefined8 *)(lVar15 + 0x28) = 1;
    *(ulong *)(lVar15 + 0x30) = uVar12;
    uVar10 = _DAT_fffffff027019950;
    *(undefined8 *)(lVar15 + 0x40) = _UNK_fffffff027019958;
    *(undefined8 *)(lVar15 + 0x38) = uVar10;
    *(long *)(lVar15 + 0x48) = -1L << ((ulong)bVar3 & 0x3f);
    *(undefined8 *)(lVar15 + 0x50) = 0;
  }
  *(long *)(lVar15 + 0x58) = lVar19;
LAB_fffffff0270b0160:
  *(undefined1 *)(lVar14 + 0x60) = 0;
  uVar12 = *(ulong *)(lVar14 + 0x128);
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    puVar11 = (undefined8 *)((uVar12 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0);
  }
  else {
    uVar13 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar15 = 0;
      do {
        puVar16 = &DAT_fffffff0270fda00 + lVar15 * 3;
        if ((((ulong)puVar16 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar16 = (ulong *)((ulong)puVar16 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar17 = *puVar16;
        if ((uVar17 <= uVar12) && (uVar12 < uVar17 + (ulong)(uint)puVar16[2] * 0x4000)) {
          puVar11 = (undefined8 *)((uVar12 - uVar17) + puVar16[1]);
          goto LAB_fffffff0270b01d8;
        }
        lVar15 = lVar15 + 1;
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    puVar11 = (undefined8 *)FUN_fffffff0270debdc();
  }
LAB_fffffff0270b01d8:
  lVar15 = 0;
  *puVar11 = 0x4b1d000000000002;
  *(undefined4 *)(puVar11 + 3) = 0xffff;
  puVar11[200] = 0;
  *(undefined1 *)(puVar11 + 199) = 1;
  lVar19 = 0x41;
  do {
    puVar1 = puVar11 + lVar15 * 3 + 4;
    *(undefined4 *)puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    lVar20 = DAT_fffffff0270921b8;
    lVar15 = lVar15 + 1;
    lVar19 = lVar19 + -1;
  } while (lVar19 != 0);
  *(undefined8 **)(DAT_fffffff0270921b8 + 0x138) = puVar11;
  *(long *)(lVar20 + 0x1c0) = *(long *)(lVar20 + 0x1b0) * 0x10 + 0x48;
  if (DAT_fffffff0270fc000 == local_70) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270a6ac4();
}

