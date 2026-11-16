// FUN_fffffff0081d9260 @ fffffff0081d9260 size=1204

/* WARNING: Removing unreachable block (ram,0xfffffff0081d951c) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d93ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081d9260
               (long *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined1 auVar7 [16];
  long lVar8;
  bool bVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  undefined4 *puVar13;
  ulong uVar14;
  undefined8 uVar15;
  long lVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 *puVar19;
  byte bVar20;
  undefined8 *puVar21;
  long lVar22;
  undefined4 uVar23;
  ulong uVar24;
  long lVar25;
  long lVar26;
  long lVar27;
  long *local_1f8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined4 local_1d0;
  undefined4 uStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 local_1bc;
  undefined4 uStack_1b8;
  undefined4 local_1b4;
  undefined4 uStack_1b0;
  uint local_1ac;
  long local_1a8;
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined1 auStack_194 [12];
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  long lStack_8c;
  undefined8 uStack_84;
  undefined4 local_7c;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  plVar10 = *(long **)(param_1[2] + 0x4b0);
  lVar25 = plVar10[0x5f];
  lVar22 = param_1[0x13];
  lVar11 = (**(code **)(*plVar10 + 0x208))(plVar10,param_4,0);
  uVar24 = *(ulong *)(param_2 + 0x2b8);
  uVar23 = (undefined4)uVar24;
  if ((*(byte *)(*(long *)(param_1[2] + 0x111b0) + 0x54) & 1) == 0) {
    lVar12 = *(long *)(param_3 + 0x148);
    param_1[0x18] = lVar12;
    FUN_fffffff008202ad8(lVar12,param_5,uVar24);
    bVar9 = false;
  }
  else {
    iVar1 = *(int *)(*(long *)(param_1[2] + 0x111b0) + 0x28);
    lVar12 = *(long *)(param_3 + 0x148);
    param_1[0x18] = lVar12;
    bVar20 = *(byte *)(param_3 + 0x530);
    FUN_fffffff008202ad8(lVar12,param_5,uVar24);
    if ((iVar1 == 1) && ((bVar20 & 1) == 0)) {
      bVar9 = false;
    }
    else {
      lVar12 = param_1[0x18];
      uVar3 = *(undefined4 *)(param_3 + 0x534);
      puVar13 = *(undefined4 **)(lVar12 + 0x68);
      *(undefined4 **)(lVar12 + 0x68) = puVar13 + 5;
      *puVar13 = 0x90000004;
      puVar13[1] = uVar3;
      puVar13[2] = uVar23;
      *(long *)(puVar13 + 3) = lVar11;
      bVar9 = true;
    }
  }
  local_1f8 = param_1 + 0x18;
  local_90 = 0;
  lStack_8c._0_4_ = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  uStack_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  uStack_e0 = 0;
  uStack_108 = 0;
  local_110 = 0;
  uStack_f8 = 0;
  uStack_100 = 0;
  uStack_128 = 0;
  local_130 = 0;
  uStack_118 = 0;
  uStack_120 = 0;
  uStack_148 = 0;
  local_150 = 0;
  uStack_138 = 0;
  uStack_140 = 0;
  uStack_168 = 0;
  local_170 = 0;
  uStack_158 = 0;
  uStack_160 = 0;
  uStack_188 = 0;
  auStack_194._4_8_ = 0;
  local_178 = 0;
  uStack_180 = 0;
  uStack_198 = 0;
  auStack_194._0_4_ = 0;
  local_1a0 = 0;
  uStack_19c = 0;
  local_1e0 = lVar11 + _DAT_fffffff007113b30;
  uStack_1d8 = lVar11 + _UNK_fffffff007113b38;
  local_1d0 = (undefined4)lVar25;
  uStack_1cc = (undefined4)((ulong)lVar25 >> 0x20);
  uStack_1c8 = (undefined4)lVar22;
  uStack_1c4 = (undefined4)((ulong)lVar22 >> 0x20);
  uStack_1c0 = *(undefined4 *)(param_2 + 0xc);
  local_1bc = (**(code **)(**(long **)(param_3 + 0x58) + 0x120))
                        (**(long **)(param_3 + 0x58) + 0x120);
  local_1b4 = *(undefined4 *)(param_3 + 0x1d8);
  uStack_1b0 = *(undefined4 *)(param_2 + 0x2b0);
  uStack_1b8 = *(undefined4 *)(*(long *)(param_3 + 0x208) + 8);
  uStack_198 = 0;
  lVar12 = lVar11 + 0x340;
  uStack_84 = *(undefined8 *)(param_2 + 4);
  local_7c = *(undefined4 *)(param_2 + 0x2ac);
  uVar2 = *(uint *)(param_3 + 0x6e8);
  uVar14 = (ulong)uVar2;
  lStack_8c = lVar12;
  if (uVar2 != 0) {
    lVar16 = 0;
    uStack_98 = CONCAT44(uVar2,(undefined4)uStack_98);
    do {
      puVar19 = (undefined8 *)(param_3 + 0x5e8U + lVar16 * 0x10);
      if (((param_3 + 0x5e8U ^ (ulong)puVar19) & 0xffc0000000000000) != 0) {
        puVar19 = (undefined8 *)((ulong)puVar19 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar21 = (undefined8 *)(auStack_194 + lVar16 * 0x10);
      if ((((ulong)auStack_194 ^ (ulong)puVar21) & 0xffc0000000000000) != 0) {
        puVar21 = (undefined8 *)((ulong)puVar21 & 0xffffffffffff | 0xc8a2000000000000);
      }
      *puVar21 = *puVar19;
      *(undefined4 *)(puVar21 + 1) = *(undefined4 *)(puVar19 + 1);
      *(undefined1 *)((long)puVar21 + 0xc) = *(undefined1 *)((long)puVar19 + 0xc);
      *(undefined2 *)((long)puVar21 + 0xe) = *(undefined2 *)((long)puVar19 + 0xe);
      lVar16 = lVar16 + 1;
      uVar14 = uVar14 - 1;
    } while (uVar14 != 0);
  }
  local_1ac = *(byte *)(param_3 + 0x5d8) & 1;
  puVar13 = *(undefined4 **)(param_1[0x18] + 0x68);
  *(undefined4 **)(param_1[0x18] + 0x68) = puVar13 + 0x5b;
  *puVar13 = 0xb;
  local_1a8 = lVar11 + 500;
  uStack_19c = uVar23;
  thunk_EXT_FUN_8011000003a61b10(puVar13 + 1,&local_1e0,0x168);
  FUN_fffffff008202e54(param_1[0x18],uVar24,param_2,lVar11,lVar22,1);
  (**(code **)(*param_1 + 0x170))(*param_1 + 0x170,param_1);
  FUN_fffffff008202e54(param_1[0x18],uVar24,param_2,lVar11,lVar22,0);
  if (bVar9) {
    uVar3 = *(undefined4 *)(param_3 + 0x534);
    puVar13 = *(undefined4 **)(*local_1f8 + 0x68);
    *(undefined4 **)(*local_1f8 + 0x68) = puVar13 + 5;
    *puVar13 = 0x10000004;
    puVar13[1] = uVar3;
    puVar13[2] = uVar23;
    *(long *)(puVar13 + 3) = lVar11;
  }
  uStack_1c0 = 0;
  uStack_1d8._0_4_ = 0;
  uStack_1d8._4_4_ = 0;
  local_1e0._0_4_ = 0;
  local_1e0._4_4_ = 0;
  uStack_1c8 = 0;
  uStack_1c4 = 0;
  local_1d0 = 0;
  uStack_1cc = 0;
  uVar23 = *(undefined4 *)(param_2 + 0xc);
  uVar18 = *(undefined8 *)(param_2 + 0x2a0);
  uVar3 = *(undefined4 *)(param_2 + 0x2a8);
  uVar15 = *(undefined8 *)(param_3 + 0x158);
  uVar17 = *(undefined8 *)(param_3 + 0x1c8);
  if (*(int *)(param_3 + 0x6e8) == 0) {
    lVar16 = -(ulong)(*(long *)(param_3 + 0x700) == 0);
    lVar8 = -(ulong)(*(long *)(param_3 + 0x708) == 0);
    lVar26 = -(ulong)(*(long *)(param_3 + 0x6f0) == 0);
    lVar27 = -(ulong)(*(long *)(param_3 + 0x6f8) == 0);
    auVar7[1] = ~(byte)((ulong)lVar26 >> 8);
    auVar7[0] = ~(byte)lVar26;
    auVar7[2] = ~(byte)((ulong)lVar26 >> 0x10);
    auVar7[3] = ~(byte)((ulong)lVar26 >> 0x18);
    auVar7[4] = ~(byte)lVar27;
    auVar7[5] = ~(byte)((ulong)lVar27 >> 8);
    auVar7[6] = ~(byte)((ulong)lVar27 >> 0x10);
    auVar7[7] = ~(byte)((ulong)lVar27 >> 0x18);
    auVar7[8] = ~(byte)lVar16;
    auVar7[9] = ~(byte)((ulong)lVar16 >> 8);
    auVar7[10] = ~(byte)((ulong)lVar16 >> 0x10);
    auVar7[0xb] = ~(byte)((ulong)lVar16 >> 0x18);
    auVar7[0xc] = ~(byte)lVar8;
    auVar7[0xd] = ~(byte)((ulong)lVar8 >> 8);
    auVar7[0xe] = ~(byte)((ulong)lVar8 >> 0x10);
    auVar7[0xf] = ~(byte)((ulong)lVar8 >> 0x18);
    uVar2 = NEON_umaxv(auVar7,4);
    if ((uVar2 & 1) == 0) {
      bVar20 = 0;
      goto LAB_fffffff0081d95bc;
    }
  }
  uStack_1d8._4_4_ = (undefined4)*(undefined8 *)(param_3 + 0x6f8);
  local_1d0 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x6f8) >> 0x20);
  local_1e0._4_4_ = (uint)*(undefined8 *)(param_3 + 0x6f0);
  uStack_1d8._0_4_ = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x6f0) >> 0x20);
  uStack_1c4 = (undefined4)*(undefined8 *)(param_3 + 0x708);
  uStack_1c0 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x708) >> 0x20);
  uStack_1cc = (undefined4)*(undefined8 *)(param_3 + 0x700);
  uStack_1c8 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x700) >> 0x20);
  bVar20 = 1;
LAB_fffffff0081d95bc:
  bVar6 = *(byte *)(param_1[2] + 0x11188);
  lVar16 = param_1[0x18];
  puVar13 = *(undefined4 **)(lVar16 + 0x68);
  *(undefined4 **)(lVar16 + 0x68) = puVar13 + 0x21;
  *puVar13 = 0xc;
  iVar1 = *(int *)(lVar16 + 0x5c);
  iVar4 = *(int *)(lVar16 + 0x28);
  iVar5 = *(int *)(lVar16 + 0x68);
  *(ulong *)(puVar13 + 0x10) = CONCAT44(uStack_1d8._4_4_,(undefined4)uStack_1d8);
  *(ulong *)(puVar13 + 0xe) = (ulong)local_1e0._4_4_ << 0x20;
  *(long *)(puVar13 + 1) = lVar25;
  *(long *)(puVar13 + 3) = lVar22;
  puVar13[5] = uVar23;
  *(long *)(puVar13 + 6) = lVar11 + 500;
  puVar13[8] = 0;
  *(ulong *)(puVar13 + 9) = uVar24 & 0xffffffff;
  *(undefined8 *)(puVar13 + 0xb) = uVar18;
  puVar13[0xd] = uVar3;
  *(ulong *)(puVar13 + 0x14) = CONCAT44(uStack_1c4,uStack_1c8);
  *(ulong *)(puVar13 + 0x12) = CONCAT44(uStack_1cc,local_1d0);
  *(byte *)(puVar13 + 0x18) = bVar20 | (bVar6 & 3) << 2;
  *(undefined8 *)((long)puVar13 + 0x61) = uVar15;
  *(undefined8 *)((long)puVar13 + 0x69) = uVar17;
  *(long *)((long)puVar13 + 0x71) = lVar12;
  *(long *)((long)puVar13 + 0x79) = lVar11 + 0x304;
  *(undefined1 *)((long)puVar13 + 0x83) = 0;
  *(undefined2 *)((long)puVar13 + 0x81) = 0;
  puVar13[0x16] = uStack_1c0;
  puVar13[0x17] = iVar1 + (iVar4 - iVar5) + 0x84;
  uVar15 = FUN_fffffff008202d20(param_1[0x18],param_2 + 0x1f0);
  *(undefined8 *)(param_2 + 0x1e8) = uVar15;
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_70) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

