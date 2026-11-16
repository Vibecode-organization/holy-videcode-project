// FUN_fffffff0081d4690 @ fffffff0081d4690 size=1224

/* WARNING: Removing unreachable block (ram,0xfffffff0081d4864) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081d4690
               (long *param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  undefined1 auVar9 [16];
  bool bVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  undefined8 uVar17;
  long lVar18;
  undefined8 uVar19;
  undefined4 *puVar20;
  undefined8 *puVar21;
  byte bVar22;
  undefined8 *puVar23;
  undefined4 uVar24;
  ulong uVar25;
  long lVar26;
  long lVar27;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined4 local_1d0;
  undefined8 local_1cc;
  undefined4 uStack_1c4;
  undefined4 uStack_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 uStack_1b4;
  uint local_1b0;
  undefined4 uStack_1ac;
  undefined4 local_1a8;
  long local_1a4;
  long local_19c;
  undefined4 local_194;
  undefined4 uStack_190;
  undefined1 auStack_18c [12];
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
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
  undefined8 uStack_90;
  undefined4 uStack_88;
  long local_84;
  undefined8 uStack_7c;
  undefined4 local_74;
  long local_70;
  
  local_70 = *(long *)PTR_DAT_fffffff007ca61a0;
  plVar11 = *(long **)(param_1[2] + 0x4b0);
  lVar14 = plVar11[0x5e];
  lVar15 = param_1[0x13];
  lVar12 = (**(code **)(*plVar11 + 0x208))(plVar11,param_4,0);
  uVar25 = *(ulong *)(param_2 + 0x5dc);
  bVar7 = *(byte *)(param_3 + 0x83b);
  uVar24 = (undefined4)uVar25;
  if (((bVar7 & 1) == 0) && ((*(byte *)(*(long *)(param_1[2] + 0x111b0) + 0x54) & 1) != 0)) {
    iVar2 = *(int *)(*(long *)(param_1[2] + 0x111b0) + 0x28);
    lVar13 = *(long *)(param_3 + 0x148);
    param_1[0x18] = lVar13;
    bVar22 = *(byte *)(param_3 + 0x810);
    FUN_fffffff008202ad8(lVar13,param_5,uVar25);
    if ((iVar2 == 1) && ((bVar22 & 1) == 0)) goto LAB_fffffff0081d47dc;
    lVar13 = param_1[0x18];
    uVar3 = *(undefined4 *)(param_3 + 0x814);
    puVar20 = *(undefined4 **)(lVar13 + 0x68);
    *(undefined4 **)(lVar13 + 0x68) = puVar20 + 5;
    *puVar20 = 0x88000004;
    puVar20[1] = uVar3;
    puVar20[2] = uVar24;
    *(long *)(puVar20 + 3) = lVar12;
    bVar10 = true;
  }
  else {
    lVar13 = *(long *)(param_3 + 0x148);
    param_1[0x18] = lVar13;
    FUN_fffffff008202ad8(lVar13,param_5,uVar25);
LAB_fffffff0081d47dc:
    bVar10 = false;
  }
  plVar11 = param_1 + 0x18;
  uStack_98 = 0;
  local_a0 = 0;
  uStack_88 = 0;
  local_84._0_4_ = 0;
  uStack_90 = 0;
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
  local_180 = 0;
  uStack_168 = 0;
  local_170 = 0;
  auStack_18c._4_8_ = 0;
  uStack_190 = 0;
  auStack_18c._0_4_ = 0;
  local_1e0 = lVar12 + _DAT_fffffff007113970;
  uStack_1d8 = lVar12 + _UNK_fffffff007113978;
  local_1d0 = 0;
  lVar13 = lVar14 + 8;
  uStack_1c4 = (undefined4)lVar15;
  uStack_1c0 = (undefined4)((ulong)lVar15 >> 0x20);
  local_1bc = *(undefined4 *)(param_2 + 0xc);
  local_1cc = lVar13;
  local_1b8 = (**(code **)(**(long **)(param_3 + 0x58) + 0x120))
                        (**(long **)(param_3 + 0x58) + 0x120);
  uStack_1b4 = *(undefined4 *)(*(long *)(param_3 + 0x208) + 8);
  local_1b0 = *(byte *)(param_3 + 0x83b) & 1;
  local_19c = lVar12 + 0x5ec;
  uStack_1ac = *(undefined4 *)(param_3 + 0x1d8);
  local_1a8 = *(undefined4 *)(param_2 + 0x5d4);
  uStack_190 = 0;
  lVar1 = lVar12 + 0x63c;
  uStack_7c = *(undefined8 *)(param_2 + 4);
  local_74 = *(undefined4 *)(param_2 + 0x5d0);
  uVar4 = *(uint *)(param_3 + 0xa00);
  uVar16 = (ulong)uVar4;
  local_84 = lVar1;
  if (uVar4 != 0) {
    lVar18 = 0;
    uStack_90 = CONCAT44(uVar4,(undefined4)uStack_90);
    do {
      puVar21 = (undefined8 *)(param_3 + 0x900U + lVar18 * 0x10);
      if (((param_3 + 0x900U ^ (ulong)puVar21) & 0xffc0000000000000) != 0) {
        puVar21 = (undefined8 *)((ulong)puVar21 & 0xffffffffffff | 0xc8a2000000000000);
      }
      puVar23 = (undefined8 *)(auStack_18c + lVar18 * 0x10);
      if ((((ulong)auStack_18c ^ (ulong)puVar23) & 0xffc0000000000000) != 0) {
        puVar23 = (undefined8 *)((ulong)puVar23 & 0xffffffffffff | 0xc8a2000000000000);
      }
      *puVar23 = *puVar21;
      *(undefined4 *)(puVar23 + 1) = *(undefined4 *)(puVar21 + 1);
      *(undefined1 *)((long)puVar23 + 0xc) = *(undefined1 *)((long)puVar21 + 0xc);
      *(undefined2 *)((long)puVar23 + 0xe) = *(undefined2 *)((long)puVar21 + 0xe);
      lVar18 = lVar18 + 1;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  puVar20 = *(undefined4 **)(*plVar11 + 0x68);
  *(undefined4 **)(*plVar11 + 0x68) = puVar20 + 0x5d;
  *puVar20 = 9;
  local_1a4 = lVar12 + 0x4a4;
  local_194 = uVar24;
  thunk_EXT_FUN_8011000003a61b10(puVar20 + 1,&local_1e0,0x170);
  if ((bVar7 & 1) == 0) {
    FUN_fffffff008202e54(*plVar11,uVar25,param_2,lVar12,lVar15,1);
  }
  (**(code **)(*param_1 + 400))(param_1,lVar14);
  if ((bVar7 & 1) == 0) {
    FUN_fffffff008202e54(*plVar11,uVar25,param_2,lVar12,lVar15,0);
    if (bVar10) {
      uVar3 = *(undefined4 *)(param_3 + 0x814);
      puVar20 = *(undefined4 **)(*plVar11 + 0x68);
      *(undefined4 **)(*plVar11 + 0x68) = puVar20 + 5;
      *puVar20 = 0x8000004;
      puVar20[1] = uVar3;
      puVar20[2] = uVar24;
      *(long *)(puVar20 + 3) = lVar12;
    }
  }
  uStack_1c0 = 0;
  uStack_1d8._0_4_ = 0;
  uStack_1d8._4_4_ = 0;
  local_1e0._0_4_ = 0;
  local_1e0._4_4_ = 0;
  local_1cc._4_4_ = 0;
  uStack_1c4 = 0;
  local_1d0 = 0;
  local_1cc._0_4_ = 0;
  uVar24 = *(undefined4 *)(param_2 + 0xc);
  bVar7 = *(byte *)(param_3 + 0x83b);
  uVar17 = *(undefined8 *)(param_2 + 4);
  uVar19 = *(undefined8 *)(param_2 + 0x5c4);
  uVar3 = *(undefined4 *)(param_2 + 0x5cc);
  if (*(int *)(param_3 + 0xa00) == 0) {
    lVar14 = -(ulong)(*(long *)(param_3 + 0xa18) == 0);
    lVar18 = -(ulong)(*(long *)(param_3 + 0xa20) == 0);
    lVar26 = -(ulong)(*(long *)(param_3 + 0xa08) == 0);
    lVar27 = -(ulong)(*(long *)(param_3 + 0xa10) == 0);
    auVar9[1] = ~(byte)((ulong)lVar26 >> 8);
    auVar9[0] = ~(byte)lVar26;
    auVar9[2] = ~(byte)((ulong)lVar26 >> 0x10);
    auVar9[3] = ~(byte)((ulong)lVar26 >> 0x18);
    auVar9[4] = ~(byte)lVar27;
    auVar9[5] = ~(byte)((ulong)lVar27 >> 8);
    auVar9[6] = ~(byte)((ulong)lVar27 >> 0x10);
    auVar9[7] = ~(byte)((ulong)lVar27 >> 0x18);
    auVar9[8] = ~(byte)lVar14;
    auVar9[9] = ~(byte)((ulong)lVar14 >> 8);
    auVar9[10] = ~(byte)((ulong)lVar14 >> 0x10);
    auVar9[0xb] = ~(byte)((ulong)lVar14 >> 0x18);
    auVar9[0xc] = ~(byte)lVar18;
    auVar9[0xd] = ~(byte)((ulong)lVar18 >> 8);
    auVar9[0xe] = ~(byte)((ulong)lVar18 >> 0x10);
    auVar9[0xf] = ~(byte)((ulong)lVar18 >> 0x18);
    uVar4 = NEON_umaxv(auVar9,4);
    if ((uVar4 & 1) == 0) {
      bVar22 = 0;
      goto LAB_fffffff0081d4a38;
    }
  }
  uStack_1d8._4_4_ = (undefined4)*(undefined8 *)(param_3 + 0xa10);
  local_1d0 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa10) >> 0x20);
  local_1e0._4_4_ = (uint)*(undefined8 *)(param_3 + 0xa08);
  uStack_1d8._0_4_ = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa08) >> 0x20);
  uStack_1c4 = (undefined4)*(undefined8 *)(param_3 + 0xa20);
  uStack_1c0 = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa20) >> 0x20);
  local_1cc._0_4_ = (undefined4)*(undefined8 *)(param_3 + 0xa18);
  local_1cc._4_4_ = (undefined4)((ulong)*(undefined8 *)(param_3 + 0xa18) >> 0x20);
  bVar22 = 1;
LAB_fffffff0081d4a38:
  bVar8 = *(byte *)(param_1[2] + 0x11188);
  lVar14 = param_1[0x18];
  puVar20 = *(undefined4 **)(lVar14 + 0x68);
  *(undefined4 **)(lVar14 + 0x68) = puVar20 + 0x1f;
  *puVar20 = 10;
  iVar2 = *(int *)(lVar14 + 0x5c);
  iVar5 = *(int *)(lVar14 + 0x28);
  iVar6 = *(int *)(lVar14 + 0x68);
  *(ulong *)(puVar20 + 0x10) = CONCAT44(uStack_1d8._4_4_,(undefined4)uStack_1d8);
  *(ulong *)(puVar20 + 0xe) = (ulong)local_1e0._4_4_ << 0x20;
  *(long *)(puVar20 + 1) = lVar13;
  *(long *)(puVar20 + 3) = lVar15;
  puVar20[5] = uVar24;
  puVar20[6] = bVar7 & 1;
  *(long *)(puVar20 + 7) = lVar12 + 0x4a4;
  *(ulong *)(puVar20 + 9) = uVar25 & 0xffffffff;
  *(undefined8 *)(puVar20 + 0xb) = uVar19;
  puVar20[0xd] = uVar3;
  *(ulong *)(puVar20 + 0x14) = CONCAT44(uStack_1c4,local_1cc._4_4_);
  *(ulong *)(puVar20 + 0x12) = CONCAT44((undefined4)local_1cc,local_1d0);
  *(byte *)(puVar20 + 0x18) = bVar22 | (bVar8 & 3) << 2;
  *(long *)((long)puVar20 + 0x61) = lVar1;
  *(undefined8 *)((long)puVar20 + 0x69) = uVar17;
  *(long *)((long)puVar20 + 0x71) = lVar12 + 0x678;
  *(undefined1 *)((long)puVar20 + 0x7b) = 0;
  *(undefined2 *)((long)puVar20 + 0x79) = 0;
  puVar20[0x16] = uStack_1c0;
  puVar20[0x17] = iVar2 + (iVar5 - iVar6) + 0x7c;
  uVar17 = FUN_fffffff008202d20(param_1[0x18],param_2 + 0x4a0);
  *(undefined8 *)(param_2 + 0x498) = uVar17;
  if (*(long *)PTR_DAT_fffffff007ca61a0 != local_70) {
    thunk_EXT_FUN_8011000003a48590();
    return;
  }
  return;
}

