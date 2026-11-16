// FUN_fffffff0081d4b58 @ fffffff0081d4b58 size=1524

/* WARNING: Removing unreachable block (ram,0xfffffff0081d4c58) */
/* WARNING: Removing unreachable block (ram,0xfffffff0081d4c14) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong FUN_fffffff0081d4b58
                (long *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  undefined1 auVar9 [16];
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  undefined4 *puVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 *puVar20;
  undefined8 uVar21;
  undefined8 *puVar22;
  byte bVar23;
  uint uVar24;
  long lVar25;
  undefined4 uVar26;
  long *plVar27;
  ulong uVar28;
  long lVar29;
  long lVar30;
  long local_250;
  long lStack_248;
  long local_240;
  long lStack_238;
  long local_230;
  long lStack_228;
  long local_220;
  long lStack_218;
  long local_210;
  long lStack_208;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  uint uStack_1f0;
  undefined4 local_1ec;
  ulong local_1e8;
  long lStack_1e0;
  long local_1d8;
  ulong uStack_1d0;
  undefined8 local_1c8;
  uint uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined1 auStack_1b4 [12];
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 uStack_b8;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  long local_78;
  
  local_78 = *(long *)PTR_DAT_fffffff007ca61a0;
  plVar27 = *(long **)(param_1[2] + 0x4b0);
  lVar15 = plVar27[0x5e];
  lVar25 = param_1[0x13];
  lVar10 = (**(code **)(*plVar27 + 0x208))(plVar27,*(undefined8 *)(param_3 + 0x8b8),0);
  uVar11 = (**(code **)(*plVar27 + 0x208))
                     (*plVar27 + 0x208,plVar27,*(undefined8 *)(param_3 + 0x8b0),0);
  lVar12 = (**(code **)(*plVar27 + 0x208))(*plVar27 + 0x208,plVar27,param_4,0);
  uVar28 = *(ulong *)(param_2 + 0x908);
  bVar7 = *(byte *)(param_3 + 0x83b);
  if (((bVar7 & 1) == 0) && ((*(byte *)(*(long *)(param_1[2] + 0x111b0) + 0x54) & 1) != 0)) {
    bVar23 = *(int *)(*(long *)(param_1[2] + 0x111b0) + 0x28) != 1 | *(byte *)(param_3 + 0x810);
  }
  else {
    bVar23 = 0;
  }
  lVar13 = *(long *)(param_3 + 0x148);
  param_1[0x18] = lVar13;
  FUN_fffffff008202ad8(lVar13,param_5,uVar28);
  uStack_c0 = 0;
  local_c8 = 0;
  uStack_b0 = 0;
  uStack_ac = 0;
  uStack_b8 = 0;
  uStack_e0 = 0;
  local_e8 = 0;
  uStack_d0 = 0;
  uStack_d8 = 0;
  uStack_100 = 0;
  local_108 = 0;
  uStack_f0 = 0;
  uStack_f8 = 0;
  uStack_120 = 0;
  local_128 = 0;
  uStack_110 = 0;
  uStack_118 = 0;
  uStack_140 = 0;
  local_148 = 0;
  uStack_130 = 0;
  uStack_138 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  uStack_150 = 0;
  local_158 = 0;
  uStack_160 = 0;
  local_168 = 0;
  uStack_170 = 0;
  local_178 = 0;
  uStack_180 = 0;
  local_188 = 0;
  uStack_190 = 0;
  local_198 = 0;
  uStack_1a0 = 0;
  local_1a8 = 0;
  auStack_1b4._4_8_ = 0;
  uStack_1b8 = 0;
  auStack_1b4._0_4_ = 0;
  uStack_1c0 = 0;
  uStack_1bc = 0;
  local_1c8 = 0;
  uStack_1d0 = 0;
  local_1d8 = 0;
  lStack_1e0 = 0;
  local_1e8 = 0;
  uVar26 = (undefined4)uVar28;
  if ((bVar23 & 1) != 0) {
    uVar1 = *(undefined4 *)(param_3 + 0x814);
    puVar14 = *(undefined4 **)(param_1[0x18] + 0x68);
    *(undefined4 **)(param_1[0x18] + 0x68) = puVar14 + 5;
    *puVar14 = 0x88000004;
    puVar14[1] = uVar1;
    puVar14[2] = uVar26;
    *(long *)(puVar14 + 3) = lVar12;
  }
  local_250 = lVar12 + _DAT_fffffff007113980;
  lStack_248 = lVar12 + _UNK_fffffff007113988;
  lVar13 = lVar15 + 8;
  lStack_228 = lVar10 + 0x3c;
  local_200 = *(undefined4 *)(param_2 + 0xc);
  local_240 = lVar10;
  lStack_238 = lVar13;
  local_230 = lVar12 + 0x888;
  local_220 = lVar12 + 0x8d8;
  lStack_218 = lVar12 + 0x8dc;
  local_210 = lVar25;
  lStack_208 = lVar12;
  local_1fc = (**(code **)(**(long **)(param_3 + 0x58) + 0x120))();
  uStack_1f8 = *(undefined4 *)(*(long *)(param_3 + 0x208) + 8);
  local_1f4 = *(undefined4 *)(param_3 + 0x8a8);
  uStack_1f0 = *(byte *)(param_3 + 0x83f) & 1;
  local_1ec = *(undefined4 *)(param_3 + 0x1d8);
  uVar1 = *(undefined4 *)(param_2 + 0x900);
  local_1d8 = lVar12 + 0x918;
  if ((*(byte *)(param_1[2] + 0x109b0) & 1) == 0) {
    uVar24 = 0;
  }
  else {
    uVar24 = *(byte *)(param_3 + 0xac9) & 1;
  }
  uStack_ac = (undefined4)*(undefined8 *)(param_2 + 4);
  local_a8 = (undefined4)((ulong)*(undefined8 *)(param_2 + 4) >> 0x20);
  local_1c8 = CONCAT44(local_1c8._4_4_,uVar24);
  uStack_1d0 = (ulong)CONCAT14(*(undefined1 *)(param_3 + 0x83c),(uint)*(byte *)(param_3 + 0x83d)) &
               0x100000001;
  uStack_1b8 = 0;
  uStack_a4 = *(undefined4 *)(param_2 + 0x8fc);
  uStack_1c0 = (uint)(*(char *)(param_3 + 0x8f0) == '\x02');
  uVar2 = *(uint *)(param_3 + 0xa00);
  uVar16 = (ulong)uVar2;
  if (uVar2 != 0) {
    lVar17 = 0;
    uStack_b8 = CONCAT44(uVar2,(undefined4)uStack_b8);
    do {
      puVar20 = (undefined8 *)(param_3 + 0x900U + lVar17 * 0x10);
      if (((param_3 + 0x900U ^ (ulong)puVar20) & 0xffc0000000000000) != 0) {
        puVar20 = (undefined8 *)((ulong)puVar20 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar22 = (undefined8 *)(auStack_1b4 + lVar17 * 0x10);
      if ((((ulong)auStack_1b4 ^ (ulong)puVar22) & 0xffc0000000000000) != 0) {
        puVar22 = (undefined8 *)((ulong)puVar22 & 0xffffffffffff | 0xc8a2000000000000);
      }
      *puVar22 = *puVar20;
      *(undefined4 *)(puVar22 + 1) = *(undefined4 *)(puVar20 + 1);
      *(undefined1 *)((long)puVar22 + 0xc) = *(undefined1 *)((long)puVar20 + 0xc);
      *(undefined2 *)((long)puVar22 + 0xe) = *(undefined2 *)((long)puVar20 + 0xe);
      lVar17 = lVar17 + 1;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  local_1e8 = (ulong)CONCAT14(*(undefined1 *)(param_3 + 0xac8),uVar1) & 0x1ffffffff;
  puVar14 = *(undefined4 **)(param_1[0x18] + 0x68);
  *(undefined4 **)(param_1[0x18] + 0x68) = puVar14 + 0x6d;
  *puVar14 = 7;
  lStack_1e0 = lVar12 + 0x770;
  uStack_1bc = uVar26;
  thunk_EXT_FUN_8011000003a61b10(puVar14 + 1,&local_250,0x1b0);
  if ((*(byte *)(param_3 + 0x83b) & 1) == 0) {
    FUN_fffffff008202e54(param_1[0x18],uVar28,param_2,lVar12,lVar25,1);
  }
  uStack_80 = 0;
  uStack_98 = 0;
  uStack_94 = 0;
  local_a0 = 0;
  uStack_9c = 0;
  uStack_88 = 0;
  uStack_84 = 0;
  uStack_90 = 0;
  local_8c = 0;
  (**(code **)(*param_1 + 400))(param_1,lVar15);
  if (((bVar7 & 1) == 0) &&
     (FUN_fffffff008202e54(param_1[0x18],uVar28,param_2,lVar12,lVar25,0), (bVar23 & 1) != 0)) {
    uVar1 = *(undefined4 *)(param_3 + 0x814);
    puVar14 = *(undefined4 **)(param_1[0x18] + 0x68);
    *(undefined4 **)(param_1[0x18] + 0x68) = puVar14 + 5;
    *puVar14 = 0x8000004;
    puVar14[1] = uVar1;
    puVar14[2] = uVar26;
    *(long *)(puVar14 + 3) = lVar12;
  }
  uVar26 = *(undefined4 *)(param_2 + 0xc);
  bVar7 = *(byte *)(param_3 + 0x83d);
  uVar21 = *(undefined8 *)(param_2 + 0x8f0);
  uVar1 = *(undefined4 *)(param_2 + 0x8f8);
  uVar3 = *(undefined4 *)(param_2 + 0x8fc);
  uVar18 = *(undefined8 *)(param_3 + 0x158);
  uVar19 = *(undefined8 *)(param_3 + 0x1c8);
  if (*(int *)(param_3 + 0xa00) == 0) {
    lVar15 = -(ulong)(*(long *)(param_3 + 0xa18) == 0);
    lVar17 = -(ulong)(*(long *)(param_3 + 0xa20) == 0);
    lVar29 = -(ulong)(*(long *)(param_3 + 0xa08) == 0);
    lVar30 = -(ulong)(*(long *)(param_3 + 0xa10) == 0);
    auVar9[1] = ~(byte)((ulong)lVar29 >> 8);
    auVar9[0] = ~(byte)lVar29;
    auVar9[2] = ~(byte)((ulong)lVar29 >> 0x10);
    auVar9[3] = ~(byte)((ulong)lVar29 >> 0x18);
    auVar9[4] = ~(byte)lVar30;
    auVar9[5] = ~(byte)((ulong)lVar30 >> 8);
    auVar9[6] = ~(byte)((ulong)lVar30 >> 0x10);
    auVar9[7] = ~(byte)((ulong)lVar30 >> 0x18);
    auVar9[8] = ~(byte)lVar15;
    auVar9[9] = ~(byte)((ulong)lVar15 >> 8);
    auVar9[10] = ~(byte)((ulong)lVar15 >> 0x10);
    auVar9[0xb] = ~(byte)((ulong)lVar15 >> 0x18);
    auVar9[0xc] = ~(byte)lVar17;
    auVar9[0xd] = ~(byte)((ulong)lVar17 >> 8);
    auVar9[0xe] = ~(byte)((ulong)lVar17 >> 0x10);
    auVar9[0xf] = ~(byte)((ulong)lVar17 >> 0x18);
    uVar2 = NEON_umaxv(auVar9,4);
    if ((uVar2 & 1) == 0) {
      bVar23 = 0;
      goto LAB_fffffff0081d4fd8;
    }
  }
  uStack_94 = (undefined4)*(undefined8 *)(param_3 + 0xa10);
  uStack_90 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa10) >> 0x20);
  uStack_9c = (undefined4)*(undefined8 *)(param_3 + 0xa08);
  uStack_98 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa08) >> 0x20);
  uStack_84 = (undefined4)*(undefined8 *)(param_3 + 0xa20);
  uStack_80 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa20) >> 0x20);
  local_8c = (undefined4)*(undefined8 *)(param_3 + 0xa18);
  uStack_88 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa18) >> 0x20);
  bVar23 = 1;
LAB_fffffff0081d4fd8:
  bVar8 = *(byte *)(param_1[2] + 0x11188);
  lVar15 = param_1[0x18];
  puVar14 = *(undefined4 **)(lVar15 + 0x68);
  *(undefined4 **)(lVar15 + 0x68) = puVar14 + 0x2f;
  *puVar14 = 8;
  iVar4 = *(int *)(lVar15 + 0x5c);
  iVar5 = *(int *)(lVar15 + 0x28);
  iVar6 = *(int *)(lVar15 + 0x68);
  *(ulong *)(puVar14 + 0x1f) = CONCAT44(uStack_94,uStack_98);
  *(ulong *)(puVar14 + 0x1d) = CONCAT44(uStack_9c,local_a0);
  *(ulong *)(puVar14 + 1) = uVar28 & 0xffffffff;
  *(undefined8 *)(puVar14 + 3) = uVar21;
  puVar14[5] = uVar1;
  puVar14[6] = 0;
  *(long *)(puVar14 + 7) = lVar10;
  *(undefined8 *)(puVar14 + 9) = uVar11;
  puVar14[0xb] = 1;
  *(long *)(puVar14 + 0xc) = lVar13;
  *(long *)(puVar14 + 0xe) = lVar12 + 0x8d8;
  *(long *)(puVar14 + 0x10) = lVar12 + 0x8dc;
  *(long *)(puVar14 + 0x12) = lVar12 + 0x888;
  *(long *)(puVar14 + 0x14) = lVar25;
  *(long *)(puVar14 + 0x16) = lVar12;
  puVar14[0x18] = uVar26;
  *(long *)(puVar14 + 0x19) = lVar12 + 0x770;
  puVar14[0x1b] = bVar7 & 1;
  puVar14[0x1c] = uVar24;
  *(ulong *)(puVar14 + 0x23) = CONCAT44(uStack_84,uStack_88);
  *(ulong *)(puVar14 + 0x21) = CONCAT44(local_8c,uStack_90);
  *(byte *)(puVar14 + 0x27) = bVar23 | (bVar8 & 3) << 2;
  *(undefined8 *)((long)puVar14 + 0x9d) = uVar18;
  *(undefined8 *)((long)puVar14 + 0xa5) = uVar19;
  *(long *)((long)puVar14 + 0xad) = lVar12 + 0x970;
  *(undefined4 *)((long)puVar14 + 0xb5) = uVar3;
  *(undefined1 *)((long)puVar14 + 0xbb) = 0;
  *(undefined2 *)((long)puVar14 + 0xb9) = 0;
  puVar14[0x25] = uStack_80;
  puVar14[0x26] = iVar4 + (iVar5 - iVar6) + 0xbc;
  uVar28 = FUN_fffffff008202d20(param_1[0x18],param_2 + 0x1c);
  *(ulong *)(param_2 + 0x14) = uVar28;
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_78) {
    lVar10 = thunk_EXT_FUN_8011000003a48590();
    return (ulong)(*(uint *)(*(long *)(lVar10 + 0x10) + 0x5c8) >> 0x13 & 1);
  }
  return uVar28;
}

