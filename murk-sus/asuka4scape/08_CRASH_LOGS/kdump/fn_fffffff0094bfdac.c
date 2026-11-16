// FUN_fffffff0094bfdac @ fffffff0094bfdac size=1600
// CALLERS:
//   fffffff00afb8027 ?
//   fffffff0094c11b8 FUN_fffffff0094c1010@fffffff0094c1010
//   fffffff0094c3b94 FUN_fffffff0094c3a14@fffffff0094c3a14
//   fffffff0094c3fec FUN_fffffff0094c3dc8@fffffff0094c3dc8
//   fffffff0094c4804 FUN_fffffff0094c4494@fffffff0094c4494
// CALLS:
//   fffffff0094bf874 FUN_fffffff0094bf874
//   fffffff0094c9a14 thunk_EXT_FUN_80110000031387d4
//   fffffff0094c5218 FUN_fffffff0094c5218
//   fffffff0094c99c4 thunk_EXT_FUN_8011000003a48590
//   fffffff0094c9a04 thunk_EXT_FUN_8011000003138628
//   fffffff0094c1954 FUN_fffffff0094c1954
//   fffffff0094c2ebc FUN_fffffff0094c2ebc
//   fffffff0094bfcf8 FUN_fffffff0094bfcf8

void FUN_fffffff0094bfdac(long param_1,undefined8 param_2,code *param_3)

{
  undefined1 *puVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  code *pcVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  uint *puVar10;
  uint *puVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  ulong uVar16;
  undefined8 *puVar17;
  ulong uVar18;
  byte bVar19;
  int iVar20;
  ulong uVar21;
  int iVar22;
  uint uVar23;
  undefined1 *local_180;
  undefined1 *puStack_178;
  undefined1 *local_170;
  undefined1 *puStack_168;
  undefined1 *local_160;
  undefined1 *puStack_158;
  undefined1 *local_150;
  undefined1 *local_148;
  byte local_139;
  undefined1 *local_138;
  undefined8 uStack_130;
  undefined1 *local_128;
  undefined1 *puStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined1 *local_108;
  undefined1 *puStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined1 *local_d8;
  undefined1 *local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  ulong local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 *local_80;
  undefined1 *local_78;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007f5bb60;
  puVar4 = *(undefined1 **)(param_1 + 0x28);
  uVar9 = *(ulong *)(param_1 + 0x30);
  if (CARRY8((ulong)puVar4,uVar9)) {
LAB_fffffff0094c03dc:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5513,0xfffffff0094c03e0);
    (*pcVar6)();
  }
  puVar1 = puVar4 + uVar9;
  if (puVar1 < puVar4) {
LAB_fffffff0094c0360:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5519,0xfffffff0094c0364);
    (*pcVar6)();
  }
  puStack_120 = (undefined1 *)0x0;
  local_128 = (undefined1 *)0x0;
  uStack_110 = 0;
  local_118 = 0;
  puStack_100 = (undefined1 *)0x0;
  local_108 = (undefined1 *)0x0;
  local_138 = &DAT_aaaaaaaaaaaaaaaa;
  local_80 = puVar4;
  local_78 = puVar1;
  if (puVar4 < puVar1) {
    bVar19 = 0;
    iVar20 = 0x30003;
    uVar5 = 0x30107;
    iVar22 = 0x100;
    uVar23 = 0;
    do {
      uVar18 = (ulong)uVar5;
      local_139 = 0;
      uStack_98 = 0;
      local_90 = 0;
      local_128 = (undefined1 *)0x0;
      uStack_130 = 0;
      local_118 = 0;
      puStack_120 = (undefined1 *)0x0;
      local_108 = (undefined1 *)0x0;
      uStack_110 = 0;
      uStack_f8 = 0;
      puStack_100 = (undefined1 *)0x0;
      uStack_e8 = 0;
      local_f0 = 0;
      local_d8 = (undefined1 *)0x0;
      uStack_e0 = 0;
      uStack_c8 = 0;
      local_d0 = (undefined1 *)0x0;
      uStack_b8 = 0;
      uStack_c0 = 0;
      uStack_a8 = 0;
      local_b0 = 0;
      uStack_88 = 0x50001;
      local_a0 = (ulong)(byte)((char)uVar23 + 1);
      uVar9 = FUN_fffffff0094bf874(&local_80,0x2000000000000010,&local_139,&local_138);
      if ((uVar9 & 1) == 0) {
        uVar18 = (ulong)(uVar5 - 6);
        goto LAB_fffffff0094c0328;
      }
      if (CARRY8((ulong)local_80,(ulong)local_138)) goto LAB_fffffff0094c03dc;
      puVar4 = local_80 + (long)local_138;
      if ((puVar4 < local_80) || (local_78 < puVar4)) goto LAB_fffffff0094c0360;
      local_150 = local_80;
      local_148 = puVar4;
      uVar9 = thunk_EXT_FUN_80110000031387d4(&local_150,&uStack_130);
      puVar1 = local_148;
      puVar4 = local_150;
      if ((uVar9 & 1) == 0) {
        uVar18 = (ulong)(uVar5 - 5);
        goto LAB_fffffff0094c0328;
      }
      if (local_148 < local_150) goto LAB_fffffff0094c0360;
      local_160 = local_150;
      puStack_158 = local_148;
      local_170 = local_150;
      puStack_168 = local_148;
      iVar8 = thunk_EXT_FUN_8011000003138628(&local_150,0x2000000000000010,&local_138);
      puVar12 = local_150;
      puVar14 = local_148;
      if (iVar8 == 0) {
        uVar9 = thunk_EXT_FUN_8011000003138628(&local_160,0x8000000000000000,&local_138);
        puVar12 = local_160;
        puVar14 = puStack_158;
        if (((uVar9 & 1) != 0) ||
           (iVar8 = thunk_EXT_FUN_8011000003138628(&local_170,0xa000000000000000,&local_138),
           puVar12 = local_170, puVar14 = puStack_168, iVar8 != 0)) {
          if (puVar12 <= puVar14) goto LAB_fffffff0094bff44;
          goto LAB_fffffff0094c0360;
        }
LAB_fffffff0094c0378:
        uVar18 = (ulong)(uint)(iVar20 + iVar22);
        goto LAB_fffffff0094c0328;
      }
LAB_fffffff0094bff44:
      local_148 = puVar14;
      puVar14 = local_138 + ((long)puVar12 - (long)puVar4);
      if (CARRY8((ulong)local_138,(long)puVar12 - (long)puVar4)) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5500,0xfffffff0094c03e8);
        (*pcVar6)();
      }
      if (puVar1 + -(long)puVar4 < puVar14) goto LAB_fffffff0094c0360;
      local_128 = puVar4;
      puStack_120 = puVar14;
      if (CARRY8((ulong)puVar12,(ulong)local_138)) goto LAB_fffffff0094c03dc;
      puVar4 = puVar12 + (long)local_138;
      if ((puVar4 < puVar12) || (local_148 < puVar4)) goto LAB_fffffff0094c0360;
      local_150 = puVar4;
      iVar8 = FUN_fffffff0094c5218(&local_150,&local_118);
      if (iVar8 == 0) {
        iVar20 = 0x30004;
        goto LAB_fffffff0094c0378;
      }
      if (local_148 < local_150) goto LAB_fffffff0094c0360;
      local_180 = local_150;
      puStack_178 = local_148;
      iVar8 = thunk_EXT_FUN_8011000003138628(&local_180,0xa000000000000000,&local_138);
      if (iVar8 == 0) {
        local_108 = (undefined1 *)0x0;
        puStack_100 = (undefined1 *)0x0;
      }
      else {
        if ((puStack_178 < local_180) || (puStack_178 + -(long)local_180 < local_138))
        goto LAB_fffffff0094c0360;
        local_108 = local_180;
        puStack_100 = local_138;
        if (CARRY8((ulong)local_180,(ulong)local_138)) goto LAB_fffffff0094c03dc;
        puVar4 = local_180 + (long)local_138;
        if ((puStack_178 < puVar4) || (puVar4 < local_180)) goto LAB_fffffff0094c0360;
        local_148 = puStack_178;
        local_150 = puVar4;
      }
      uVar9 = FUN_fffffff0094c5218(&local_150,&uStack_f8);
      if ((uVar9 & 1) == 0) {
        uVar18 = (ulong)(uVar5 - 2);
        goto LAB_fffffff0094c0328;
      }
      uVar9 = thunk_EXT_FUN_8011000003138628(&local_150,4,&local_138);
      if ((uVar9 & 1) == 0) {
        uVar18 = (ulong)(uVar5 - 1);
        goto LAB_fffffff0094c0328;
      }
      if ((local_148 < local_150) || (local_148 + -(long)local_150 < local_138))
      goto LAB_fffffff0094c0360;
      local_d8 = local_150;
      local_d0 = local_138;
      if (CARRY8((ulong)local_150,(ulong)local_138)) goto LAB_fffffff0094c03dc;
      puVar4 = local_150 + (long)local_138;
      if ((local_148 < puVar4) || (puVar4 < local_150)) goto LAB_fffffff0094c0360;
      puStack_178 = local_148;
      local_180 = puVar4;
      local_150 = puVar4;
      iVar8 = FUN_fffffff0094c1954(&local_180,0xa000000000000001,0,0x7d);
      if (iVar8 != 0) {
        if (puStack_178 < local_180) goto LAB_fffffff0094c0360;
        local_150 = local_180;
        local_148 = puStack_178;
      }
      iVar8 = FUN_fffffff0094bfcf8(&local_150,local_139 & 1);
      if (iVar8 == 0) goto LAB_fffffff0094c0328;
      puVar10 = (uint *)FUN_fffffff0094c2ebc(&local_118);
      if ((puVar10 != (uint *)0x0) &&
         ((*(uint *)(param_1 + 0x60) == 0 || (*puVar10 <= *(uint *)(param_1 + 0x60))))) {
        uVar18 = (*param_3)(param_2,param_1,&uStack_130);
        if ((int)uVar18 != 0x5001e) {
          if ((int)uVar18 != 0) goto LAB_fffffff0094c0328;
          uVar9 = (ulong)bVar19;
          uVar18 = *(ulong *)(param_1 + 0x40);
          if (bVar19 < uVar18) {
            if ((*(uint *)(param_1 + 0x60) == 0) || (*puVar10 <= *(uint *)(param_1 + 0x60))) {
              if (CARRY8(*(ulong *)(param_1 + 0x38),(long)(int)(char)bVar19 * 0xb0))
              goto LAB_fffffff0094c03dc;
              if ((uVar18 - uVar9) * 0xb0 < 0xb0) goto LAB_fffffff0094c0360;
              puVar13 = (undefined8 *)(*(ulong *)(param_1 + 0x38) + uVar9 * 0xb0);
              puVar13[0x13] = uStack_98;
              puVar13[0x12] = local_a0;
              puVar13[0x15] = uStack_88;
              puVar13[0x14] = local_90;
              puVar13[0xf] = uStack_b8;
              puVar13[0xe] = uStack_c0;
              puVar13[0x11] = uStack_a8;
              puVar13[0x10] = local_b0;
              puVar13[0xb] = local_d8;
              puVar13[10] = uStack_e0;
              puVar13[0xd] = uStack_c8;
              puVar13[0xc] = local_d0;
              puVar13[7] = uStack_f8;
              puVar13[6] = puStack_100;
              puVar13[9] = uStack_e8;
              puVar13[8] = local_f0;
              puVar13[3] = local_118;
              puVar13[2] = puStack_120;
              puVar13[5] = local_108;
              puVar13[4] = uStack_110;
              puVar13[1] = local_128;
              *puVar13 = uStack_130;
              if (bVar19 == 0xff) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x5507,0xfffffff0094c03ec);
                (*pcVar6)();
              }
              bVar19 = bVar19 + 1;
            }
          }
          else if (uVar18 != 0) {
            uVar16 = *(ulong *)(param_1 + 0x38);
            uVar21 = uVar9 * 0xb0 - 0xb0;
            if (CARRY8(uVar16,uVar21)) goto LAB_fffffff0094c03dc;
            uVar2 = uVar16 + uVar21;
            uVar18 = uVar16 + uVar18 * 0xb0;
            if (((uVar16 ^ uVar18) & 0xffc0000000000000) != 0) {
              uVar18 = uVar18 & 0xffffffffffff | 0xc8a2000000000000;
            }
            if ((((uVar2 < uVar16) || (uVar18 < uVar2 + 0xb0)) || (uVar2 + 0xb0 < uVar2)) ||
               (uVar2 + 0x28 < uVar2 + 0x18)) goto LAB_fffffff0094c0360;
            puVar11 = (uint *)FUN_fffffff0094c2ebc();
            if (((puVar11 != (uint *)0x0) && (*puVar11 < *puVar10)) &&
               ((*(uint *)(param_1 + 0x60) == 0 || (*puVar10 <= *(uint *)(param_1 + 0x60))))) {
              puVar13 = *(undefined8 **)(param_1 + 0x38);
              if (CARRY8((ulong)puVar13,uVar21)) goto LAB_fffffff0094c03dc;
              puVar17 = puVar13 + *(long *)(param_1 + 0x40) * 0x16;
              if ((((ulong)puVar13 ^ (ulong)puVar17) & 0xffc0000000000000) != 0) {
                puVar17 = (undefined8 *)((ulong)puVar17 & 0xffffffffffff | 0xc8a2000000000000);
              }
              if (((*(long *)(param_1 + 0x40) * 0xb0 - uVar21 < 0xb0) ||
                  (puVar3 = puVar13 + uVar9 * 0x16 + -0x16, puVar17 < puVar3)) || (puVar3 < puVar13)
                 ) goto LAB_fffffff0094c0360;
              puVar3[0x13] = uStack_98;
              puVar3[0x12] = local_a0;
              puVar3[0x15] = uStack_88;
              puVar3[0x14] = local_90;
              puVar3[0xf] = uStack_b8;
              puVar3[0xe] = uStack_c0;
              puVar3[0x11] = uStack_a8;
              puVar3[0x10] = local_b0;
              puVar3[0xb] = local_d8;
              puVar3[10] = uStack_e0;
              puVar3[0xd] = uStack_c8;
              puVar3[0xc] = local_d0;
              puVar3[7] = uStack_f8;
              puVar3[6] = puStack_100;
              puVar3[9] = uStack_e8;
              puVar3[8] = local_f0;
              puVar3[3] = local_118;
              puVar3[2] = puStack_120;
              puVar3[5] = local_108;
              puVar3[4] = uStack_110;
              puVar3[1] = local_128;
              *puVar3 = uStack_130;
            }
          }
        }
      }
      if ((local_78 < local_150) || (local_150 < local_80)) goto LAB_fffffff0094c0360;
      local_80 = local_150;
      uVar15 = uVar23 + 1;
      if (local_78 <= local_150) break;
      iVar22 = iVar22 + 0x100;
      uVar5 = uVar5 + 0x100;
      bVar7 = uVar23 < 7;
      uVar23 = uVar15;
    } while (bVar7);
    if (local_150 == local_78) {
      if ((bVar19 == 0) && (*(long *)(param_1 + 0x40) != 0)) {
        uVar18 = 0;
        puVar13 = *(undefined8 **)(param_1 + 0x38);
        puVar13[0x13] = uStack_98;
        puVar13[0x12] = local_a0;
        puVar13[0x15] = uStack_88;
        puVar13[0x14] = local_90;
        puVar13[0xf] = uStack_b8;
        puVar13[0xe] = uStack_c0;
        puVar13[0x11] = uStack_a8;
        puVar13[0x10] = local_b0;
        puVar13[0xb] = local_d8;
        puVar13[10] = uStack_e0;
        puVar13[0xd] = uStack_c8;
        puVar13[0xc] = local_d0;
        puVar13[7] = uStack_f8;
        puVar13[6] = puStack_100;
        puVar13[9] = uStack_e8;
        puVar13[8] = local_f0;
        puVar13[3] = local_118;
        puVar13[2] = puStack_120;
        puVar13[5] = local_108;
        puVar13[4] = uStack_110;
        puVar13[1] = local_128;
        *puVar13 = uStack_130;
      }
      else {
        uVar18 = 0;
      }
      goto LAB_fffffff0094c0328;
    }
  }
  else {
    uVar15 = 0;
    uVar18 = 0;
    if (uVar9 == 0) goto LAB_fffffff0094c0328;
  }
  uVar18 = (ulong)(uVar15 * 0x100 + 0x30008);
LAB_fffffff0094c0328:
  if (*(long *)PTR_DAT_fffffff007f5bb60 != local_70) {
    thunk_EXT_FUN_8011000003a48590(uVar18);
    return;
  }
  return;
}

