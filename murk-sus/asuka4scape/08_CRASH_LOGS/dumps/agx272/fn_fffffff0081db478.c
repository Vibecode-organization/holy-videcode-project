// FUN_fffffff0081db478 @ fffffff0081db478 size=1300

/* WARNING: Removing unreachable block (ram,0xfffffff0081db638) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081db478(long *param_1,long param_2,long param_3,long param_4,undefined8 param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  undefined1 auVar10 [16];
  long lVar11;
  bool bVar12;
  long *plVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  ulong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 *puVar20;
  undefined8 *puVar21;
  undefined8 uVar22;
  undefined8 *puVar23;
  byte bVar24;
  long lVar25;
  ulong uVar26;
  long lVar27;
  long lVar28;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined8 uStack_1f0;
  long lStack_1e8;
  long local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 uStack_1d0;
  undefined4 local_1cc;
  uint uStack_1c8;
  undefined4 local_1c4;
  ulong local_1c0;
  long lStack_1b8;
  long lStack_1b0;
  ulong local_1a8;
  ulong local_1a0;
  undefined1 auStack_198 [8];
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined8 uStack_180;
  undefined8 uStack_178;
  undefined8 uStack_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 uStack_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 uStack_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined8 local_80;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  plVar13 = *(long **)(param_1[2] + 0x4b0);
  lVar25 = plVar13[0x5d];
  lVar16 = param_1[0x13];
  uVar14 = (**(code **)(*plVar13 + 0x208))(plVar13,*(undefined8 *)(param_3 + 0x1020),0);
  uVar26 = *(ulong *)(param_2 + 0x5a4);
  if ((*(byte *)(*(long *)(param_1[2] + 0x111b0) + 0x54) & 1) == 0) {
    lVar15 = *(long *)(param_3 + 0x1268);
    param_1[0x18] = lVar15;
    FUN_fffffff008202ad8(lVar15,param_5,uVar26);
LAB_fffffff0081db5a8:
    bVar12 = false;
  }
  else {
    iVar1 = *(int *)(*(long *)(param_1[2] + 0x111b0) + 0x28);
    lVar15 = *(long *)(param_3 + 0x1268);
    param_1[0x18] = lVar15;
    bVar7 = *(byte *)(param_3 + 0x810);
    FUN_fffffff008202ad8(lVar15,param_5,uVar26);
    if ((iVar1 == 1) && ((bVar7 & 1) == 0)) goto LAB_fffffff0081db5a8;
    lVar15 = param_1[0x18];
    uVar2 = *(undefined4 *)(param_3 + 0x814);
    puVar20 = *(undefined4 **)(lVar15 + 0x68);
    *(undefined4 **)(lVar15 + 0x68) = puVar20 + 5;
    *puVar20 = 0x80000004;
    puVar20[1] = uVar2;
    puVar20[2] = (int)uVar26;
    *(long *)(puVar20 + 3) = param_4;
    bVar12 = true;
  }
  plVar13 = param_1 + 0x18;
  local_80 = 0;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  local_84 = 0;
  uStack_90 = 0;
  local_8c = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_a8 = 0;
  uStack_b0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  uStack_c8 = 0;
  uStack_d0 = 0;
  uStack_f8 = 0;
  local_100 = 0;
  uStack_e8 = 0;
  uStack_f0 = 0;
  uStack_118 = 0;
  local_120 = 0;
  uStack_108 = 0;
  uStack_110 = 0;
  uStack_138 = 0;
  local_140 = 0;
  uStack_128 = 0;
  uStack_130 = 0;
  uStack_158 = 0;
  local_160 = 0;
  uStack_148 = 0;
  uStack_150 = 0;
  uStack_178 = 0;
  uStack_180 = 0;
  uStack_168 = 0;
  uStack_170 = 0;
  auStack_198 = (undefined1  [8])0x0;
  local_1a0 = 0;
  uStack_188 = 0;
  uStack_190 = 0;
  lStack_1b8 = 0;
  local_1c0 = 0;
  local_1a8 = 0;
  lStack_1b0 = 0;
  local_210 = param_4 + _DAT_fffffff007113bb0;
  uStack_208 = param_4 + _UNK_fffffff007113bb8;
  local_200 = (undefined4)*(undefined8 *)(param_2 + 0x20);
  uStack_1fc = (undefined4)((ulong)*(undefined8 *)(param_2 + 0x20) >> 0x20);
  uStack_1f8 = (undefined4)uVar14;
  uStack_1f4 = (undefined4)((ulong)uVar14 >> 0x20);
  local_1d8 = *(undefined4 *)(param_2 + 0xc);
  lStack_1e8 = lVar16;
  uStack_1f0 = lVar25 + 4;
  local_1d4 = (**(code **)(**(long **)(param_3 + 0x58) + 0x120))
                        (**(long **)(param_3 + 0x58) + 0x120);
  uStack_1d0 = *(undefined4 *)(*(long *)(param_3 + 0x208) + 8);
  local_1cc = *(undefined4 *)(param_3 + 0x1010);
  uStack_1c8 = *(byte *)(param_3 + 0xf38) & 1;
  local_1c4 = *(undefined4 *)(param_3 + 0x1050);
  uVar2 = *(undefined4 *)(param_2 + 0x59c);
  lStack_1b0 = param_4 + 0x5b4;
  local_1a8 = (ulong)(CONCAT14(*(char *)(param_3 + 0x8f0) == '\x02',(uint)*(byte *)(param_3 + 0xf3b)
                              ) & 0xff00000001);
  local_8c = (undefined4)*(undefined8 *)(param_2 + 4);
  uStack_88 = (undefined4)((ulong)*(undefined8 *)(param_2 + 4) >> 0x20);
  local_84 = *(undefined4 *)(param_2 + 0x598);
  auStack_198 = (undefined1  [8])
                (CONCAT44(auStack_198._4_4_,(uint)*(byte *)(param_3 + 0xf42)) & 0xffffffff00000001);
  uVar3 = *(uint *)(param_3 + 0x1168);
  uVar17 = (ulong)uVar3;
  if (uVar3 != 0) {
    lVar15 = 0;
    uStack_98 = CONCAT44(uVar3,(undefined4)uStack_98);
    do {
      puVar21 = (undefined8 *)(param_3 + 0x1068U + lVar15 * 0x10);
      if (((param_3 + 0x1068U ^ (ulong)puVar21) & 0xffc0000000000000) != 0) {
        puVar21 = (undefined8 *)((ulong)puVar21 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar23 = (undefined8 *)(auStack_198 + 4 + lVar15 * 0x10);
      if ((((ulong)(auStack_198 + 4) ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
        puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
      }
      *puVar23 = *puVar21;
      *(undefined4 *)(puVar23 + 1) = *(undefined4 *)(puVar21 + 1);
      *(undefined1 *)((long)puVar23 + 0xc) = *(undefined1 *)((long)puVar21 + 0xc);
      *(undefined2 *)((long)puVar23 + 0xe) = *(undefined2 *)((long)puVar21 + 0xe);
      lVar15 = lVar15 + 1;
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
  }
  local_80 = CONCAT44(local_80._4_4_,(uint)*(byte *)(param_3 + 0xf41)) & 0xffffffff00000001;
  local_1c0 = (ulong)CONCAT14(*(undefined1 *)(param_3 + 0x1238),uVar2) & 0x1ffffffff;
  puVar20 = *(undefined4 **)(*plVar13 + 0x68);
  *(undefined4 **)(*plVar13 + 0x68) = puVar20 + 0x67;
  *puVar20 = 5;
  local_1e0 = param_4 + 0x568;
  lStack_1b8 = param_4 + 0x480;
  local_1a0 = uVar26 & 0xffffffff;
  thunk_EXT_FUN_8011000003a61b10(puVar20 + 1,&local_210,0x198);
  if ((*(byte *)(param_3 + 0xf38) & 1) == 0) {
    FUN_fffffff008202e54(*plVar13,uVar26,param_2,param_4,lVar16,1);
  }
  (**(code **)(*param_1 + 400))(param_1);
  if ((*(byte *)(param_3 + 0xf38) & 1) == 0) {
    FUN_fffffff008202e54(*plVar13,uVar26,param_2,param_4,lVar16,0);
  }
  if (bVar12) {
    uVar2 = *(undefined4 *)(param_3 + 0x814);
    puVar20 = *(undefined4 **)(*plVar13 + 0x68);
    *(undefined4 **)(*plVar13 + 0x68) = puVar20 + 5;
    *puVar20 = 4;
    puVar20[1] = uVar2;
    puVar20[2] = (int)uVar26;
    *(long *)(puVar20 + 3) = param_4;
  }
  uStack_1f0._0_4_ = 0;
  uStack_1f0._4_4_ = 0;
  uStack_208._0_4_ = 0;
  uStack_208._4_4_ = 0;
  local_210._0_4_ = 0;
  local_210._4_4_ = 0;
  uStack_1f8 = 0;
  uStack_1f4 = 0;
  local_200 = 0;
  uStack_1fc = 0;
  uVar22 = *(undefined8 *)(param_2 + 0x20);
  uVar2 = *(undefined4 *)(param_2 + 0xc);
  bVar7 = *(byte *)(param_3 + 0xf38);
  bVar8 = *(byte *)(param_3 + 0xf3b);
  uVar19 = *(undefined8 *)(param_2 + 0x58c);
  uVar4 = *(undefined4 *)(param_2 + 0x594);
  uVar18 = *(undefined8 *)(param_3 + 0x1c8);
  if (*(int *)(param_3 + 0x1168) == 0) {
    lVar15 = -(ulong)(*(long *)(param_3 + 0x1180) == 0);
    lVar11 = -(ulong)(*(long *)(param_3 + 0x1188) == 0);
    lVar27 = -(ulong)(*(long *)(param_3 + 0x1170) == 0);
    lVar28 = -(ulong)(*(long *)(param_3 + 0x1178) == 0);
    auVar10[1] = ~(byte)((ulong)lVar27 >> 8);
    auVar10[0] = ~(byte)lVar27;
    auVar10[2] = ~(byte)((ulong)lVar27 >> 0x10);
    auVar10[3] = ~(byte)((ulong)lVar27 >> 0x18);
    auVar10[4] = ~(byte)lVar28;
    auVar10[5] = ~(byte)((ulong)lVar28 >> 8);
    auVar10[6] = ~(byte)((ulong)lVar28 >> 0x10);
    auVar10[7] = ~(byte)((ulong)lVar28 >> 0x18);
    auVar10[8] = ~(byte)lVar15;
    auVar10[9] = ~(byte)((ulong)lVar15 >> 8);
    auVar10[10] = ~(byte)((ulong)lVar15 >> 0x10);
    auVar10[0xb] = ~(byte)((ulong)lVar15 >> 0x18);
    auVar10[0xc] = ~(byte)lVar11;
    auVar10[0xd] = ~(byte)((ulong)lVar11 >> 8);
    auVar10[0xe] = ~(byte)((ulong)lVar11 >> 0x10);
    auVar10[0xf] = ~(byte)((ulong)lVar11 >> 0x18);
    uVar3 = NEON_umaxv(auVar10,4);
    if ((uVar3 & 1) == 0) {
      bVar24 = 0;
      goto LAB_fffffff0081db85c;
    }
  }
  uStack_208._4_4_ = (undefined4)*(undefined8 *)(param_3 + 0x1178);
  local_200 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x1178) >> 0x20);
  local_210._4_4_ = (uint)*(undefined8 *)(param_3 + 0x1170);
  uStack_208._0_4_ = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x1170) >> 0x20);
  uStack_1f4 = (undefined4)*(undefined8 *)(param_3 + 0x1188);
  uStack_1f0._0_4_ = (uint)((ulong)*(undefined8 *)(param_3 + 0x1188) >> 0x20);
  uStack_1fc = (undefined4)*(undefined8 *)(param_3 + 0x1180);
  uStack_1f8 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0x1180) >> 0x20);
  bVar24 = 1;
LAB_fffffff0081db85c:
  bVar9 = *(byte *)(param_1[2] + 0x11188);
  lVar15 = param_1[0x18];
  puVar20 = *(undefined4 **)(lVar15 + 0x68);
  *(undefined4 **)(lVar15 + 0x68) = puVar20 + 0x27;
  *puVar20 = 6;
  iVar1 = *(int *)(lVar15 + 0x5c);
  iVar5 = *(int *)(lVar15 + 0x28);
  iVar6 = *(int *)(lVar15 + 0x68);
  *(ulong *)(puVar20 + 0x17) = CONCAT44(uStack_208._4_4_,(undefined4)uStack_208);
  *(ulong *)(puVar20 + 0x15) = (ulong)local_210._4_4_ << 0x20;
  *(undefined8 *)(puVar20 + 1) = uVar14;
  *(undefined8 *)(puVar20 + 3) = uVar22;
  *(long *)(puVar20 + 5) = lVar25 + 4;
  *(long *)(puVar20 + 7) = lVar16;
  *(long *)(puVar20 + 9) = param_4 + 0x568;
  puVar20[0xb] = uVar2;
  puVar20[0xc] = bVar7 & 1;
  *(long *)(puVar20 + 0xd) = param_4 + 0x480;
  puVar20[0xf] = bVar8 & 1;
  *(ulong *)(puVar20 + 0x10) = uVar26 & 0xffffffff;
  *(undefined8 *)(puVar20 + 0x12) = uVar19;
  puVar20[0x14] = uVar4;
  *(ulong *)(puVar20 + 0x1b) = CONCAT44(uStack_1f4,uStack_1f8);
  *(ulong *)(puVar20 + 0x19) = CONCAT44(uStack_1fc,local_200);
  *(ulong *)(puVar20 + 0x1d) = (ulong)(uint)uStack_1f0;
  *(byte *)(puVar20 + 0x1f) = bVar24 | (bVar9 & 3) << 2;
  *(undefined8 *)((long)puVar20 + 0x7d) = 0;
  *(undefined8 *)((long)puVar20 + 0x85) = uVar18;
  *(long *)((long)puVar20 + 0x8d) = param_4 + 0x60c;
  puVar20[0x26] = 0;
  *(undefined4 *)((long)puVar20 + 0x95) = 0;
  puVar20[0x1e] = iVar1 + (iVar5 - iVar6) + 0x9c;
  uVar14 = FUN_fffffff008202d20(param_1[0x18],param_2 + 0x474);
  *(undefined8 *)(param_2 + 0x46c) = uVar14;
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_70) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

