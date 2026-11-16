// FUN_fffffff00a4f017c @ fffffff00a4f017c size=7488

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a4f017c(long param_1,char *param_2,char *param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  uint uVar4;
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  bool bVar13;
  undefined8 uVar14;
  uint uVar15;
  code *pcVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 uVar24;
  ulong uVar25;
  undefined8 uVar26;
  long lVar27;
  ulong uVar28;
  long lVar29;
  char cVar30;
  ulong uVar31;
  long lVar32;
  undefined4 uVar33;
  byte bVar34;
  undefined8 in_stack_fffffffffffffd00;
  ulong in_stack_fffffffffffffd08;
  ulong in_stack_fffffffffffffd10;
  ulong in_stack_fffffffffffffd20;
  undefined8 in_stack_fffffffffffffd58;
  long local_230;
  undefined4 local_228;
  undefined4 local_224;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 uStack_200;
  undefined8 uStack_1f8;
  undefined8 local_1f0;
  undefined8 uStack_1e8;
  undefined8 uStack_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1c0;
  undefined8 uStack_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 uStack_1a0;
  long local_198;
  undefined8 local_190;
  long local_188;
  int local_17c;
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
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  ulong local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  long local_70;
  
  uVar33 = (undefined4)((ulong)in_stack_fffffffffffffd58 >> 0x20);
  local_70 = DAT_fffffff00ad30000;
  local_178 = 0;
  local_17c = 0;
  local_190 = 0;
  local_188 = 0;
  uStack_88 = 0;
  local_90 = 0;
  uStack_78 = 0;
  uStack_80 = 0;
  uStack_a8 = 0;
  local_b0 = 0;
  uStack_98 = 0;
  uStack_a0 = 0;
  uStack_1a8 = 0;
  local_1b0 = 0;
  local_198 = 0;
  uStack_1a0 = 0;
  uStack_1c8 = 0;
  local_1d0 = 0;
  uStack_1b8 = 0;
  local_1c0 = 0;
  uStack_1e8 = 0;
  local_1f0 = 0;
  local_1d8 = 0;
  uStack_1e0 = 0;
  uStack_208 = 0;
  local_210 = 0;
  uStack_1f8 = 0;
  uStack_200 = 0;
  uStack_218 = 0;
  local_220 = 0;
  local_224 = 0;
  uVar24 = 0;
  if (param_1 == 0) goto LAB_fffffff00a4f0f68;
  if (param_2 == (char *)0x0) {
LAB_fffffff00a4f020c:
    param_2 = (char *)0x0;
    if (param_3 != (char *)0x0) goto LAB_fffffff00a4f022c;
LAB_fffffff00a4f0248:
    param_3 = (char *)0x0;
  }
  else {
    if (param_2[1] == '\x02') {
      cVar30 = '\x10';
    }
    else {
      if (param_2[1] != '\x1e') goto LAB_fffffff00a4f020c;
      cVar30 = '\x1c';
    }
    if (cVar30 != *param_2) {
      param_2 = (char *)0x0;
    }
    if (param_3 == (char *)0x0) goto LAB_fffffff00a4f0248;
LAB_fffffff00a4f022c:
    if (param_3[1] == '\x02') {
      cVar30 = '\x10';
    }
    else {
      if (param_3[1] != '\x1e') goto LAB_fffffff00a4f0248;
      cVar30 = '\x1c';
    }
    if (cVar30 != *param_3) {
      param_3 = (char *)0x0;
    }
  }
  uVar31 = *(ulong *)(param_1 + 0x40);
  if (DAT_fffffff00ad7ce04 == 0) {
LAB_fffffff00a4f02d0:
    iVar20 = 0;
  }
  else {
    lVar32 = *(long *)(uVar31 + 0x208);
    iVar20 = FUN_fffffff00aa39574(lVar32,0x271c);
    if (((iVar20 == 0) &&
        ((*(int *)(lVar32 + 0x18) == 0 ||
         (iVar20 = FUN_fffffff00aa39798(lVar32,0x271c), iVar20 == 0)))) ||
       ((iVar21 = FUN_fffffff00aa39574(lVar32,0x271d), iVar20 = DAT_fffffff00ad7ce04, iVar21 == 0 &&
        ((*(int *)(lVar32 + 0x18) == 0 ||
         (iVar21 = FUN_fffffff00aa39798(lVar32,0x271d), iVar20 = DAT_fffffff00ad7ce04, iVar21 == 0))
        )))) goto LAB_fffffff00a4f02d0;
  }
  uVar14 = _DAT_fffffff00700f5c0;
  if ((DAT_fffffff00ad7ce0c == 0) &&
     ((DAT_fffffff00adcd960 == 0 ||
      (((*(byte *)(param_1 + 0x94) >> 2 & 1) == 0 && (DAT_fffffff00adcd968 == 0)))))) {
    if (DAT_fffffff00ad7cdf8 != 0 || iVar20 != 0) {
      *(undefined8 *)(param_1 + 0x1a8) = _UNK_fffffff00700f5c8;
      *(undefined8 *)(param_1 + 0x1a0) = uVar14;
      *(undefined4 *)(param_1 + 0x1b0) = 0;
      *(undefined8 *)(param_1 + 0x1c0) = 0;
      *(undefined4 *)(param_1 + 0x1c8) = 0;
      iVar20 = FUN_fffffff00a4f1ebc(param_2,param_3,param_1);
      if ((iVar20 == 0) || (iVar20 == 3)) goto LAB_fffffff00a4f03ac;
      goto LAB_fffffff00a4f0410;
    }
    goto LAB_fffffff00a4f0f64;
  }
  iVar21 = FUN_fffffff00a4f1ebc(param_2,param_3,param_1);
  if (iVar21 == 1) {
LAB_fffffff00a4f03d0:
    if ((*(int *)(param_1 + 0x1b8) == 0xc) && ((*(byte *)(param_1 + 0x95) >> 5 & 1) != 0)) {
      *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
      *(undefined8 *)(param_1 + 0xb0) = 0;
    }
    uVar14 = _DAT_fffffff00700f5c0;
    *(undefined8 *)(param_1 + 0x1a8) = _UNK_fffffff00700f5c8;
    *(undefined8 *)(param_1 + 0x1a0) = uVar14;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
LAB_fffffff00a4f0410:
    uVar24 = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    goto LAB_fffffff00a4f0f68;
  }
  if (iVar21 == 3) {
    if ((*(int *)(param_1 + 0x1b8) == 0xc) && ((*(byte *)(param_1 + 0x95) >> 5 & 1) != 0)) {
      *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
      *(undefined8 *)(param_1 + 0xb0) = 0;
    }
    uVar14 = _DAT_fffffff00700f5c0;
    *(undefined8 *)(param_1 + 0x1a8) = _UNK_fffffff00700f5c8;
    *(undefined8 *)(param_1 + 0x1a0) = uVar14;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
LAB_fffffff00a4f03ac:
    uVar24 = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 3;
    goto LAB_fffffff00a4f0f68;
  }
  if ((iVar21 == 2) && (_DAT_fffffff00ad11f40 == 1)) goto LAB_fffffff00a4f03d0;
  FUN_fffffff00a228180(&DAT_fffffff00adcd940);
  FUN_fffffff00a4f204c
            (param_1,param_2,param_3,param_4,0,iVar20,&local_188,&local_220,
             CONCAT71((int7)((ulong)in_stack_fffffffffffffd00 >> 8),iVar21 == 2) & 0xffffffff,
             in_stack_fffffffffffffd08 & 0xffffffffffffff00);
  iVar20 = DAT_fffffff00adcd97c;
  uVar14 = DAT_fffffff00ad7ce10;
  if (DAT_fffffff00adcd990 == 0) {
    if (DAT_fffffff00adcd97c != 0) {
      if ((((DAT_fffffff00adcd988 != 0) &&
           (((int)local_220 == 0 || ((int)local_220 == DAT_fffffff00adcd988)))) ||
          ((DAT_fffffff00adcd984 != 0 && (DAT_fffffff00adcd984 == uStack_1c8._4_2_)))) ||
         ((DAT_fffffff00adcd98c != 0 && ((int)local_1d8 == DAT_fffffff00adcd98c))))
      goto LAB_fffffff00a4f0554;
      if (DAT_fffffff00adcd980 != 0) goto LAB_fffffff00a4f0534;
      goto LAB_fffffff00a4f062c;
    }
LAB_fffffff00a4f0624:
    bVar13 = false;
  }
  else {
    if (DAT_fffffff00adcd97c == 0) goto LAB_fffffff00a4f0624;
    if ((((DAT_fffffff00adcd988 == 0) || ((int)local_220 == 0)) ||
        ((int)local_220 == DAT_fffffff00adcd988)) &&
       (((DAT_fffffff00adcd984 == 0 || (DAT_fffffff00adcd984 == uStack_1c8._4_2_)) &&
        ((DAT_fffffff00adcd98c == 0 || ((int)local_1d8 == DAT_fffffff00adcd98c)))))) {
      if (DAT_fffffff00adcd980 != 0) {
LAB_fffffff00a4f0534:
        if ((DAT_fffffff00adcd980 !=
             ((uint)(local_210._2_2_ >> 8) | (local_210._2_2_ & 0xff00ff) << 8)) &&
           (DAT_fffffff00adcd980 !=
            ((uint)(uStack_1f8._6_2_ >> 8) | (uStack_1f8._6_2_ & 0xff00ff) << 8)))
        goto LAB_fffffff00a4f062c;
      }
LAB_fffffff00a4f0554:
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uVar25 = uVar31 | 0xffffff8000000000;
      in_stack_fffffffffffffd10 = uVar25;
      if ((uVar31 & 0x80000000000000) == 0) {
        in_stack_fffffffffffffd10 = uVar31 & 0x7ffffffffff;
      }
      if (((in_stack_fffffffffffffd10 < DAT_fffffff007c6a360 &&
            DAT_fffffff007c6a358 <= in_stack_fffffffffffffd10) ||
          (DAT_fffffff007c6a378 <= in_stack_fffffffffffffd10 &&
           in_stack_fffffffffffffd10 < DAT_fffffff007c6a380)) ||
         ((DAT_fffffff007c6a3a0 <= in_stack_fffffffffffffd10 &&
          (in_stack_fffffffffffffd10 < DAT_fffffff007c6a3a8)))) {
        in_stack_fffffffffffffd10 = FUN_fffffff00a396010(in_stack_fffffffffffffd10);
      }
      else if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
              (uVar25 < 0xfffffffc00000000)) {
        in_stack_fffffffffffffd10 = FUN_fffffff00a1d12d4();
      }
      in_stack_fffffffffffffd20 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      if (local_210._1_1_ == '\x02') {
        lVar32 = 4;
        uVar26 = 2;
LAB_fffffff00a4f0648:
        FUN_fffffff00a8dd3c8(uVar26,(long)&local_210 + lVar32,&local_f0,0x40);
        auVar5[1] = -((char)(local_f0 >> 8) == '\0');
        auVar5[0] = -((char)local_f0 == '\0');
        auVar5[2] = -((char)(local_f0 >> 0x10) == '\0');
        auVar5[3] = -((char)(local_f0 >> 0x18) == '\0');
        auVar5[4] = -((char)(local_f0 >> 0x20) == '\0');
        auVar5[5] = -((char)(local_f0 >> 0x28) == '\0');
        auVar5[6] = -((char)(local_f0 >> 0x30) == '\0');
        auVar5[7] = -((char)(local_f0 >> 0x38) == '\0');
        auVar5[8] = -((char)uStack_e8 == '\0');
        auVar5[9] = -((char)((ulong)uStack_e8 >> 8) == '\0');
        auVar5[10] = -((char)((ulong)uStack_e8 >> 0x10) == '\0');
        auVar5[0xb] = -((char)((ulong)uStack_e8 >> 0x18) == '\0');
        auVar5[0xc] = -((char)((ulong)uStack_e8 >> 0x20) == '\0');
        auVar5[0xd] = -((char)((ulong)uStack_e8 >> 0x28) == '\0');
        auVar5[0xe] = -((char)((ulong)uStack_e8 >> 0x30) == '\0');
        auVar5[0xf] = -((char)((ulong)uStack_e8 >> 0x38) == '\0');
        bVar34 = NEON_umaxv(auVar5,1);
        if ((((bVar34 & 1) == 0) &&
            (auVar6[1] = -((char)((ulong)local_e0 >> 8) == '\0'),
            auVar6[0] = -((char)local_e0 == '\0'),
            auVar6[2] = -((char)((ulong)local_e0 >> 0x10) == '\0'),
            auVar6[3] = -((char)((ulong)local_e0 >> 0x18) == '\0'),
            auVar6[4] = -((char)((ulong)local_e0 >> 0x20) == '\0'),
            auVar6[5] = -((char)((ulong)local_e0 >> 0x28) == '\0'),
            auVar6[6] = -((char)((ulong)local_e0 >> 0x30) == '\0'),
            auVar6[7] = -((char)((ulong)local_e0 >> 0x38) == '\0'),
            auVar6[8] = -((char)uStack_d8 == '\0'),
            auVar6[9] = -((char)((ulong)uStack_d8 >> 8) == '\0'),
            auVar6[10] = -((char)((ulong)uStack_d8 >> 0x10) == '\0'),
            auVar6[0xb] = -((char)((ulong)uStack_d8 >> 0x18) == '\0'),
            auVar6[0xc] = -((char)((ulong)uStack_d8 >> 0x20) == '\0'),
            auVar6[0xd] = -((char)((ulong)uStack_d8 >> 0x28) == '\0'),
            auVar6[0xe] = -((char)((ulong)uStack_d8 >> 0x30) == '\0'),
            auVar6[0xf] = -((char)((ulong)uStack_d8 >> 0x38) == '\0'), bVar34 = NEON_umaxv(auVar6,1)
            , (bVar34 & 1) == 0)) &&
           ((auVar7[1] = -((char)((ulong)local_d0 >> 8) == '\0'),
            auVar7[0] = -((char)local_d0 == '\0'),
            auVar7[2] = -((char)((ulong)local_d0 >> 0x10) == '\0'),
            auVar7[3] = -((char)((ulong)local_d0 >> 0x18) == '\0'),
            auVar7[4] = -((char)((ulong)local_d0 >> 0x20) == '\0'),
            auVar7[5] = -((char)((ulong)local_d0 >> 0x28) == '\0'),
            auVar7[6] = -((char)((ulong)local_d0 >> 0x30) == '\0'),
            auVar7[7] = -((char)((ulong)local_d0 >> 0x38) == '\0'),
            auVar7[8] = -((char)uStack_c8 == '\0'),
            auVar7[9] = -((char)((ulong)uStack_c8 >> 8) == '\0'),
            auVar7[10] = -((char)((ulong)uStack_c8 >> 0x10) == '\0'),
            auVar7[0xb] = -((char)((ulong)uStack_c8 >> 0x18) == '\0'),
            auVar7[0xc] = -((char)((ulong)uStack_c8 >> 0x20) == '\0'),
            auVar7[0xd] = -((char)((ulong)uStack_c8 >> 0x28) == '\0'),
            auVar7[0xe] = -((char)((ulong)uStack_c8 >> 0x30) == '\0'),
            auVar7[0xf] = -((char)((ulong)uStack_c8 >> 0x38) == '\0'), bVar34 = NEON_umaxv(auVar7,1)
            , (bVar34 & 1) == 0 &&
            (auVar8[1] = -((char)((ulong)local_c0 >> 8) == '\0'),
            auVar8[0] = -((char)local_c0 == '\0'),
            auVar8[2] = -((char)((ulong)local_c0 >> 0x10) == '\0'),
            auVar8[3] = -((char)((ulong)local_c0 >> 0x18) == '\0'),
            auVar8[4] = -((char)((ulong)local_c0 >> 0x20) == '\0'),
            auVar8[5] = -((char)((ulong)local_c0 >> 0x28) == '\0'),
            auVar8[6] = -((char)((ulong)local_c0 >> 0x30) == '\0'),
            auVar8[7] = -((char)((ulong)local_c0 >> 0x38) == '\0'),
            auVar8[8] = -((char)uStack_b8 == '\0'),
            auVar8[9] = -((char)((ulong)uStack_b8 >> 8) == '\0'),
            auVar8[10] = -((char)((ulong)uStack_b8 >> 0x10) == '\0'),
            auVar8[0xb] = -((char)((ulong)uStack_b8 >> 0x18) == '\0'),
            auVar8[0xc] = -((char)((ulong)uStack_b8 >> 0x20) == '\0'),
            auVar8[0xd] = -((char)((ulong)uStack_b8 >> 0x28) == '\0'),
            auVar8[0xe] = -((char)((ulong)uStack_b8 >> 0x30) == '\0'),
            auVar8[0xf] = -((char)((ulong)uStack_b8 >> 0x38) == '\0'), bVar34 = NEON_umaxv(auVar8,1)
            , (bVar34 & 1) == 0)))) goto LAB_fffffff00a4f1e6c;
      }
      else if (local_210._1_1_ == '\x1e') {
        uVar26 = 0x1e;
        lVar32 = 8;
        goto LAB_fffffff00a4f0648;
      }
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      if (uStack_1f8._5_1_ == '\x02') {
        lVar32 = 4;
LAB_fffffff00a4f06e0:
        FUN_fffffff00a8dd3c8(uStack_1f8._5_1_,(long)&uStack_1f8 + lVar32 + 4,&local_130,0x40);
        auVar9[1] = -((char)((ulong)local_130 >> 8) == '\0');
        auVar9[0] = -((char)local_130 == '\0');
        auVar9[2] = -((char)((ulong)local_130 >> 0x10) == '\0');
        auVar9[3] = -((char)((ulong)local_130 >> 0x18) == '\0');
        auVar9[4] = -((char)((ulong)local_130 >> 0x20) == '\0');
        auVar9[5] = -((char)((ulong)local_130 >> 0x28) == '\0');
        auVar9[6] = -((char)((ulong)local_130 >> 0x30) == '\0');
        auVar9[7] = -((char)((ulong)local_130 >> 0x38) == '\0');
        auVar9[8] = -((char)uStack_128 == '\0');
        auVar9[9] = -((char)((ulong)uStack_128 >> 8) == '\0');
        auVar9[10] = -((char)((ulong)uStack_128 >> 0x10) == '\0');
        auVar9[0xb] = -((char)((ulong)uStack_128 >> 0x18) == '\0');
        auVar9[0xc] = -((char)((ulong)uStack_128 >> 0x20) == '\0');
        auVar9[0xd] = -((char)((ulong)uStack_128 >> 0x28) == '\0');
        auVar9[0xe] = -((char)((ulong)uStack_128 >> 0x30) == '\0');
        auVar9[0xf] = -((char)((ulong)uStack_128 >> 0x38) == '\0');
        bVar34 = NEON_umaxv(auVar9,1);
        if ((((bVar34 & 1) == 0) &&
            (auVar10[1] = -((char)((ulong)local_120 >> 8) == '\0'),
            auVar10[0] = -((char)local_120 == '\0'),
            auVar10[2] = -((char)((ulong)local_120 >> 0x10) == '\0'),
            auVar10[3] = -((char)((ulong)local_120 >> 0x18) == '\0'),
            auVar10[4] = -((char)((ulong)local_120 >> 0x20) == '\0'),
            auVar10[5] = -((char)((ulong)local_120 >> 0x28) == '\0'),
            auVar10[6] = -((char)((ulong)local_120 >> 0x30) == '\0'),
            auVar10[7] = -((char)((ulong)local_120 >> 0x38) == '\0'),
            auVar10[8] = -((char)uStack_118 == '\0'),
            auVar10[9] = -((char)((ulong)uStack_118 >> 8) == '\0'),
            auVar10[10] = -((char)((ulong)uStack_118 >> 0x10) == '\0'),
            auVar10[0xb] = -((char)((ulong)uStack_118 >> 0x18) == '\0'),
            auVar10[0xc] = -((char)((ulong)uStack_118 >> 0x20) == '\0'),
            auVar10[0xd] = -((char)((ulong)uStack_118 >> 0x28) == '\0'),
            auVar10[0xe] = -((char)((ulong)uStack_118 >> 0x30) == '\0'),
            auVar10[0xf] = -((char)((ulong)uStack_118 >> 0x38) == '\0'),
            bVar34 = NEON_umaxv(auVar10,1), (bVar34 & 1) == 0)) &&
           ((auVar11[1] = -((char)((ulong)local_110 >> 8) == '\0'),
            auVar11[0] = -((char)local_110 == '\0'),
            auVar11[2] = -((char)((ulong)local_110 >> 0x10) == '\0'),
            auVar11[3] = -((char)((ulong)local_110 >> 0x18) == '\0'),
            auVar11[4] = -((char)((ulong)local_110 >> 0x20) == '\0'),
            auVar11[5] = -((char)((ulong)local_110 >> 0x28) == '\0'),
            auVar11[6] = -((char)((ulong)local_110 >> 0x30) == '\0'),
            auVar11[7] = -((char)((ulong)local_110 >> 0x38) == '\0'),
            auVar11[8] = -((char)uStack_108 == '\0'),
            auVar11[9] = -((char)((ulong)uStack_108 >> 8) == '\0'),
            auVar11[10] = -((char)((ulong)uStack_108 >> 0x10) == '\0'),
            auVar11[0xb] = -((char)((ulong)uStack_108 >> 0x18) == '\0'),
            auVar11[0xc] = -((char)((ulong)uStack_108 >> 0x20) == '\0'),
            auVar11[0xd] = -((char)((ulong)uStack_108 >> 0x28) == '\0'),
            auVar11[0xe] = -((char)((ulong)uStack_108 >> 0x30) == '\0'),
            auVar11[0xf] = -((char)((ulong)uStack_108 >> 0x38) == '\0'),
            bVar34 = NEON_umaxv(auVar11,1), (bVar34 & 1) == 0 &&
            (auVar12[1] = -((char)((ulong)local_100 >> 8) == '\0'),
            auVar12[0] = -((char)local_100 == '\0'),
            auVar12[2] = -((char)((ulong)local_100 >> 0x10) == '\0'),
            auVar12[3] = -((char)((ulong)local_100 >> 0x18) == '\0'),
            auVar12[4] = -((char)((ulong)local_100 >> 0x20) == '\0'),
            auVar12[5] = -((char)((ulong)local_100 >> 0x28) == '\0'),
            auVar12[6] = -((char)((ulong)local_100 >> 0x30) == '\0'),
            auVar12[7] = -((char)((ulong)local_100 >> 0x38) == '\0'),
            auVar12[8] = -((char)uStack_f8 == '\0'),
            auVar12[9] = -((char)((ulong)uStack_f8 >> 8) == '\0'),
            auVar12[10] = -((char)((ulong)uStack_f8 >> 0x10) == '\0'),
            auVar12[0xb] = -((char)((ulong)uStack_f8 >> 0x18) == '\0'),
            auVar12[0xc] = -((char)((ulong)uStack_f8 >> 0x20) == '\0'),
            auVar12[0xd] = -((char)((ulong)uStack_f8 >> 0x28) == '\0'),
            auVar12[0xe] = -((char)((ulong)uStack_f8 >> 0x30) == '\0'),
            auVar12[0xf] = -((char)((ulong)uStack_f8 >> 0x38) == '\0'),
            bVar34 = NEON_umaxv(auVar12,1), (bVar34 & 1) == 0)))) goto LAB_fffffff00a4f1e6c;
      }
      else if (uStack_1f8._5_1_ == '\x1e') {
        lVar32 = 8;
        goto LAB_fffffff00a4f06e0;
      }
      uVar33 = (undefined4)((ulong)&local_130 >> 0x20);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar14,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                );
      bVar13 = true;
    }
    else {
LAB_fffffff00a4f062c:
      bVar13 = false;
      iVar20 = 0;
    }
  }
  iVar22 = (*_DAT_fffffff00ad19dc8)(&local_220,0x98,DAT_fffffff00adcda90);
  lVar32 = local_188;
  puVar2 = (undefined8 *)(param_1 + 0x1a4);
  if (((*(int *)(param_1 + 0x1a4) != 0) && (*(int *)(param_1 + 0x1ac) == DAT_fffffff00adcda90)) &&
     (*(int *)(param_1 + 0x1b0) == iVar22)) {
    if (local_198 != 0) {
      FUN_fffffff00a7d8ee8();
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    if (local_188 != 0) {
      FUN_fffffff00a724838();
    }
    if ((1 < iVar20) || (1 < DAT_fffffff00ad7ce48)) {
      FUN_fffffff00a8df19c
                (&MACH_HEADER,DAT_fffffff00ad7ce40,0,
                 "%s: DATA-TRACE: Socket Policy - INP UPDATE - RESULT - CACHED <MATCHED>: %p (BoundInterface %d Proto %d) Policy %d Result %d Parameter %d\n"
                );
    }
    uVar14 = DAT_fffffff00ad7ce10;
    if (bVar13) {
      uStack_c8 = 0;
      local_d0 = 0;
      uStack_b8 = 0;
      local_c0 = 0;
      uStack_e8 = 0;
      local_f0 = 0;
      uStack_d8 = 0;
      local_e0 = 0;
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      iVar20 = FUN_fffffff00a4ecdf8(uVar31);
      uVar25 = uVar31 | 0xffffff8000000000;
      if (iVar20 == 0) {
        if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
           (uVar25 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar28 = uVar31 & 0x7ffffffffff;
        if ((uVar31 & 0x80000000000000) != 0) {
          uVar28 = uVar25;
        }
        FUN_fffffff00a396010(uVar28);
      }
      FUN_fffffff00a4eb1ec(&local_210,&local_f0);
      FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_130);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar14,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                );
    }
    uVar24 = *(undefined4 *)puVar2;
    goto LAB_fffffff00a4f0f68;
  }
  uVar15 = (uint)local_1c0;
  *(uint *)(param_1 + 0x1a0) = (uint)local_1c0;
  local_228 = 0;
  uStack_c8 = 0;
  local_d0 = 0;
  uStack_b8 = 0;
  local_c0 = 0;
  uStack_e8 = 0;
  local_f0 = 0;
  uStack_d8 = 0;
  local_e0 = 0;
  local_230 = 0;
  lVar27 = local_188;
  if (local_188 == 0) {
    lVar27 = FUN_fffffff00a29b24c();
    lVar27 = *(long *)(lVar27 + 0x18);
    if (lVar27 == 0) {
      lVar27 = DAT_fffffff007c6b250;
    }
  }
  uVar4 = 0;
  if (uVar15 != 0) {
    uVar4 = (uVar15 & 3) + 1;
  }
  puVar1 = &DAT_fffffff00adcda98 + (ulong)uVar4 * 2;
  if ((((undefined8 *)((long)&DAT_fffffff00adcdae0 + 7) < puVar1) ||
      (puVar1 < &DAT_fffffff00adcda98)) || (uVar31 + 0x3c0 <= uVar31)) goto LAB_fffffff00a4f1e6c;
  uVar25 = FUN_fffffff00a4e8d7c
                     (*puVar1,(&DAT_fffffff00adcdaa0)[(ulong)uVar4 * 2],&local_220,
                      (long)&local_178 + 4,&local_f0,&local_230,&local_b0,0,0,0,
                      in_stack_fffffffffffffd10 & 0xffffffff00000000,lVar27,
                      in_stack_fffffffffffffd20 & 0xffffffffffff0000,&local_228,
                      *(undefined8 *)(param_1 + 0xe8),&local_178,&local_17c,&local_224,uVar31,
                      CONCAT44(uVar33,iVar20));
  if (((iVar21 == 2) && (_DAT_fffffff00ad11f40 == 2)) &&
     ((uVar25 == 0 || (*(int *)(uVar25 + 0x170) != 4)))) {
    if ((*(int *)(param_1 + 0x1b8) == 0xc) && ((*(byte *)(param_1 + 0x95) >> 5 & 1) != 0)) {
      *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
      *(undefined8 *)(param_1 + 0xb0) = 0;
    }
    uVar14 = _DAT_fffffff00700f5c0;
    *(undefined8 *)(param_1 + 0x1a8) = _UNK_fffffff00700f5c8;
    *(undefined8 *)(param_1 + 0x1a0) = uVar14;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = local_178._4_4_;
    *(undefined4 *)(param_1 + 0x1c4) = local_224;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 1;
    if (local_198 != 0) {
      *(undefined4 *)(local_198 + 0xa8) = local_178._4_4_;
      *(undefined4 *)(local_198 + 0xac) = 0;
      *(undefined8 *)(local_198 + 0xb8) = 0;
      FUN_fffffff00a7d8ee8();
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    if (lVar32 != 0) {
      FUN_fffffff00a724838(lVar32);
    }
    uVar14 = DAT_fffffff00ad7ce10;
    if (bVar13) {
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_148 = 0;
      local_150 = 0;
      uStack_138 = 0;
      uStack_140 = 0;
      uStack_168 = 0;
      local_170 = 0;
      uStack_158 = 0;
      uStack_160 = 0;
      iVar20 = FUN_fffffff00a4ecdf8(uVar31);
      uVar25 = uVar31 | 0xffffff8000000000;
      if (iVar20 == 0) {
        if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
           (uVar25 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar28 = uVar31 & 0x7ffffffffff;
        if ((uVar31 & 0x80000000000000) != 0) {
          uVar28 = uVar25;
        }
        FUN_fffffff00a396010(uVar28);
      }
      FUN_fffffff00a4eb1ec(&local_210,&local_130);
      FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar14,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                );
      uVar24 = 0;
      goto LAB_fffffff00a4f0f68;
    }
  }
  else {
    uVar28 = FUN_fffffff00a4f2c9c(&local_b0,iVar20,uVar31);
    uVar14 = DAT_fffffff00ad7ce40;
    if ((uVar28 & 1) != 0) {
      if (local_230 == 0) {
        uVar28 = 0;
      }
      else if (local_230 == 1) {
        uVar28 = local_f0 & 0xffffffff;
      }
      else {
        uVar28 = FUN_fffffff00a4f2e5c(&local_f0);
      }
      uVar33 = (undefined4)uVar28;
      if (uVar25 == 0) {
        bVar17 = DAT_fffffff00ad7cdf8 == 0;
        bVar19 = uStack_1b8._4_4_ == 0;
        bVar18 = (int)local_178 != 3;
        if (((!bVar17 || !bVar19) || !bVar18) && (local_17c == 0)) {
          local_17c = FUN_fffffff00a4eb270(lVar27);
        }
        iVar21 = local_17c;
        iVar23 = FUN_fffffff00a4ebb84(0,&local_b0,uVar28,&local_224);
        if (iVar23 == 0) {
          if (iVar21 != 2 || (bVar17 && bVar19) && bVar18) {
            if ((*(int *)(param_1 + 0x1b8) == 0xc) && ((*(byte *)(param_1 + 0x95) >> 5 & 1) != 0)) {
              *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
              *(undefined8 *)(param_1 + 0xb0) = 0;
            }
            if ((((((byte)local_1b0 >> 3 & 1) != 0) || (((ushort)local_190 >> 8 & 1) != 0)) &&
                (*(int *)(param_1 + 0x1b8) == 6)) && (*(long *)(param_1 + 0xb0) != 0)) {
              *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
              *(undefined8 *)(param_1 + 0xb0) = 0;
            }
            uVar14 = DAT_fffffff00ad7ce10;
            bVar17 = false;
            if (1 < iVar20 || 1 < DAT_fffffff00ad7ce48) {
              bVar17 = bVar13;
            }
            if (bVar17) {
              uStack_108 = 0;
              local_110 = 0;
              uStack_f8 = 0;
              local_100 = 0;
              uStack_128 = 0;
              local_130 = 0;
              uStack_118 = 0;
              local_120 = 0;
              uStack_148 = 0;
              local_150 = 0;
              uStack_138 = 0;
              uStack_140 = 0;
              uStack_168 = 0;
              local_170 = 0;
              uStack_158 = 0;
              uStack_160 = 0;
              iVar21 = FUN_fffffff00a4ecdf8(uVar31);
              uVar25 = uVar31 | 0xffffff8000000000;
              if (iVar21 == 0) {
                if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
                   (uVar25 < 0xfffffffc00000000)) {
                  FUN_fffffff00a1d12d4();
                }
              }
              else {
                uVar28 = uVar31 & 0x7ffffffffff;
                if ((uVar31 & 0x80000000000000) != 0) {
                  uVar28 = uVar25;
                }
                FUN_fffffff00a396010(uVar28);
              }
              FUN_fffffff00a4eb1ec(&local_210,&local_130);
              FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
              FUN_fffffff00a8df19c
                        (&MACH_HEADER,uVar14,0x10,
                         "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                        );
            }
            *(undefined4 *)(param_1 + 0x1a4) = 1;
            *(undefined4 *)(param_1 + 0x1a8) = local_228;
            *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
            *(int *)(param_1 + 0x1b0) = iVar22;
            *(undefined4 *)(param_1 + 0x1c0) = local_178._4_4_;
            *(undefined4 *)(param_1 + 0x1c4) = local_224;
            *(undefined4 *)(param_1 + 0x1c8) = uVar33;
            *(undefined4 *)(param_1 + 0x1b8) = 0;
            if (local_198 != 0) {
              *(undefined4 *)(local_198 + 0xa8) = local_178._4_4_;
              *(int *)(local_198 + 0xac) = DAT_fffffff00adcda90;
              *(undefined8 *)(local_198 + 0xb8) = 0;
            }
            uVar14 = DAT_fffffff00ad7ce10;
            if (!bVar13) goto joined_r0xfffffff00a4f1b18;
            uStack_108 = 0;
            local_110 = 0;
            uStack_f8 = 0;
            local_100 = 0;
            uStack_128 = 0;
            local_130 = 0;
            uStack_118 = 0;
            local_120 = 0;
            uStack_148 = 0;
            local_150 = 0;
            uStack_138 = 0;
            uStack_140 = 0;
            uStack_168 = 0;
            local_170 = 0;
            uStack_158 = 0;
            uStack_160 = 0;
            iVar21 = FUN_fffffff00a4ecdf8(uVar31);
            uVar25 = uVar31 | 0xffffff8000000000;
            if (iVar21 == 0) {
              if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
                 (uVar25 < 0xfffffffc00000000)) {
                FUN_fffffff00a1d12d4();
              }
            }
            else {
              uVar28 = uVar31 & 0x7ffffffffff;
              if ((uVar31 & 0x80000000000000) != 0) {
                uVar28 = uVar25;
              }
              FUN_fffffff00a396010(uVar28);
            }
            FUN_fffffff00a4eb1ec(&local_210,&local_130);
            FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar14,0x10,
                       "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                      );
            bVar17 = false;
            uVar24 = 0;
            goto joined_r0xfffffff00a4f1c38;
          }
          *puVar2 = 0x100000001;
          *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
          *(int *)(param_1 + 0x1b0) = iVar22;
          *(undefined8 *)(param_1 + 0x1c0) = 0;
          *(undefined4 *)(param_1 + 0x1c8) = 0;
          *(undefined4 *)(param_1 + 0x1b8) = 3;
          uVar14 = DAT_fffffff00ad7ce10;
          if (bVar13) {
            uStack_108 = 0;
            local_110 = 0;
            uStack_f8 = 0;
            local_100 = 0;
            uStack_128 = 0;
            local_130 = 0;
            uStack_118 = 0;
            local_120 = 0;
            uStack_148 = 0;
            local_150 = 0;
            uStack_138 = 0;
            uStack_140 = 0;
            uStack_168 = 0;
            local_170 = 0;
            uStack_158 = 0;
            uStack_160 = 0;
            iVar21 = FUN_fffffff00a4ecdf8(uVar31);
            uVar25 = uVar31 | 0xffffff8000000000;
            if (iVar21 == 0) {
              if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
                 (uVar25 < 0xfffffffc00000000)) {
                FUN_fffffff00a1d12d4();
              }
            }
            else {
              uVar28 = uVar31 & 0x7ffffffffff;
              if ((uVar31 & 0x80000000000000) != 0) {
                uVar28 = uVar25;
              }
              FUN_fffffff00a396010(uVar28);
            }
            FUN_fffffff00a4eb1ec(&local_210,&local_130);
            FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar14,0x10,
                       "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                      );
          }
          iVar21 = DAT_fffffff00adcda90;
          if (local_198 == 0) goto joined_r0xfffffff00a4f1b18;
          bVar19 = false;
          bVar17 = false;
          *(undefined4 *)(local_198 + 0xa8) = 0;
          *(int *)(local_198 + 0xac) = iVar21;
          *(undefined8 *)(local_198 + 0xb8) = 0;
          uVar24 = 0;
          goto joined_r0xfffffff00a4f1c38;
        }
        *puVar2 = 0x100000001;
        *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
        *(int *)(param_1 + 0x1b0) = iVar22;
        *(undefined4 *)(param_1 + 0x1c0) = local_178._4_4_;
        *(undefined4 *)(param_1 + 0x1c4) = local_224;
        *(undefined4 *)(param_1 + 0x1c8) = uVar33;
        *(undefined4 *)(param_1 + 0x1b8) = 4;
        *(int *)(param_1 + 0x1bc) = iVar23;
        if (local_198 != 0) {
          *(undefined4 *)(local_198 + 0xa8) = local_178._4_4_;
          *(int *)(local_198 + 0xac) = DAT_fffffff00adcda90;
          *(undefined8 *)(local_198 + 0xb8) = 0;
        }
        uVar14 = DAT_fffffff00ad7ce10;
        if (bVar13) {
          uStack_108 = 0;
          local_110 = 0;
          uStack_f8 = 0;
          local_100 = 0;
          uStack_128 = 0;
          local_130 = 0;
          uStack_118 = 0;
          local_120 = 0;
          uStack_148 = 0;
          local_150 = 0;
          uStack_138 = 0;
          uStack_140 = 0;
          uStack_168 = 0;
          local_170 = 0;
          uStack_158 = 0;
          uStack_160 = 0;
          iVar21 = FUN_fffffff00a4ecdf8(uVar31);
          uVar25 = uVar31 | 0xffffff8000000000;
          if (iVar21 == 0) {
            if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
               (uVar25 < 0xfffffffc00000000)) {
              FUN_fffffff00a1d12d4();
            }
          }
          else {
            uVar28 = uVar31 & 0x7ffffffffff;
            if ((uVar31 & 0x80000000000000) != 0) {
              uVar28 = uVar25;
            }
            FUN_fffffff00a396010(uVar28);
          }
          FUN_fffffff00a4eb1ec(&local_210,&local_130);
          FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar14,0x10,
                     "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                    );
        }
joined_r0xfffffff00a4f1b18:
        uVar24 = 0;
        bVar17 = false;
        bVar19 = false;
        if (lVar27 != 0) goto LAB_fffffff00a4f1770;
LAB_fffffff00a4f1744:
        lVar29 = FUN_fffffff00a29b24c();
        lVar32 = *(long *)(lVar29 + 0x18);
        if (*(long *)(lVar29 + 0x18) == 0) {
          lVar32 = DAT_fffffff007c6b250;
        }
        else {
LAB_fffffff00a4f1790:
        }
        if ((((((ushort)local_190 >> 1 & 1) != 0) || ((*(uint *)(lVar32 + 0x448) >> 1 & 1) == 0)) ||
            (lVar32 + 0x768 == 0)) ||
           ((iVar21 = FUN_fffffff00a9dee48
                                (lVar32 + 0x768,"com.apple.developer.on-demand-install-capable"),
            iVar21 == 0 || (((ushort)local_190 >> 6 & 1) != 0)))) goto LAB_fffffff00a4f1c48;
        lVar32 = *(long *)(param_1 + 0x40);
        if (((lVar32 != 0) &&
            (((*(byte *)(lVar32 + 0x233) >> 4 & 1) != 0 && (*(int *)(lVar32 + 0x21c) != 0)))) &&
           (lVar32 = FUN_fffffff00a72456c(), lVar32 != 0)) {
          if ((lVar32 == DAT_fffffff007c6b250) ||
             ((iVar21 = FUN_fffffff00a6ec3c0(lVar32), iVar21 != 0 &&
              (uVar25 = FUN_fffffff00a7266f8(lVar32), (uVar25 & 1) != 0)))) {
            FUN_fffffff00a724838(lVar32);
            goto LAB_fffffff00a4f1c48;
          }
          FUN_fffffff00a724838(lVar32);
        }
LAB_fffffff00a4f1c5c:
        *(undefined8 *)(param_1 + 0x1a4) = 0x100000001;
        *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
        *(int *)(param_1 + 0x1b0) = iVar22;
        *(undefined8 *)(param_1 + 0x1c0) = 0;
        *(undefined4 *)(param_1 + 0x1c8) = 0;
        *(undefined4 *)(param_1 + 0x1b8) = 3;
        iVar21 = DAT_fffffff00adcda90;
        if (local_198 != 0) {
          *(undefined4 *)(local_198 + 0xa8) = 0;
          *(int *)(local_198 + 0xac) = iVar21;
          *(undefined8 *)(local_198 + 0xb8) = 0;
        }
        uVar14 = DAT_fffffff00ad7ce10;
        bVar18 = false;
        if (1 < iVar20 || 1 < DAT_fffffff00ad7ce48) {
          bVar18 = bVar13;
        }
        if (bVar18) {
          uStack_108 = 0;
          local_110 = 0;
          uStack_f8 = 0;
          local_100 = 0;
          uStack_128 = 0;
          local_130 = 0;
          uStack_118 = 0;
          local_120 = 0;
          uStack_148 = 0;
          local_150 = 0;
          uStack_138 = 0;
          uStack_140 = 0;
          uStack_168 = 0;
          local_170 = 0;
          uStack_158 = 0;
          uStack_160 = 0;
          iVar20 = FUN_fffffff00a4ecdf8(uVar31);
          uVar25 = uVar31 | 0xffffff8000000000;
          if (iVar20 == 0) {
            if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
               (uVar25 < 0xfffffffc00000000)) {
              FUN_fffffff00a1d12d4();
            }
          }
          else {
            uVar28 = uVar31 & 0x7ffffffffff;
            if ((uVar31 & 0x80000000000000) != 0) {
              uVar28 = uVar25;
            }
            FUN_fffffff00a396010(uVar28);
          }
          FUN_fffffff00a4eb1ec(&local_210,&local_130);
          FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar14,0x10,
                     "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                    );
        }
      }
      else {
        if ((*(int *)(uVar25 + 0x170) == 1) &&
           ((((byte)local_1b0 >> 3 & 1) != 0 || (((ushort)local_190 >> 8 & 1) != 0)))) {
          if (*(int *)(param_1 + 0x1b8) == 0xc) {
            if ((*(byte *)(param_1 + 0x95) >> 5 & 1) != 0) {
LAB_fffffff00a4f10b4:
              *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) & 0xffffbfff;
              *(undefined8 *)(param_1 + 0xb0) = 0;
            }
          }
          else if ((*(int *)(param_1 + 0x1b8) == 6) && (*(long *)(param_1 + 0xb0) != 0))
          goto LAB_fffffff00a4f10b4;
          uVar14 = DAT_fffffff00ad7ce10;
          bVar17 = false;
          if (1 < iVar20 || 1 < DAT_fffffff00ad7ce48) {
            bVar17 = bVar13;
          }
          if (bVar17) {
            uStack_108 = 0;
            local_110 = 0;
            uStack_f8 = 0;
            local_100 = 0;
            uStack_128 = 0;
            local_130 = 0;
            uStack_118 = 0;
            local_120 = 0;
            uStack_148 = 0;
            local_150 = 0;
            uStack_138 = 0;
            uStack_140 = 0;
            uStack_168 = 0;
            local_170 = 0;
            uStack_158 = 0;
            uStack_160 = 0;
            iVar21 = FUN_fffffff00a4ecdf8(uVar31);
            uVar28 = uVar31 | 0xffffff8000000000;
            if (iVar21 == 0) {
              if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar28)) &&
                 (uVar28 < 0xfffffffc00000000)) {
                FUN_fffffff00a1d12d4();
              }
            }
            else {
              uVar3 = uVar31 & 0x7ffffffffff;
              if ((uVar31 & 0x80000000000000) != 0) {
                uVar3 = uVar28;
              }
              FUN_fffffff00a396010(uVar3);
            }
            FUN_fffffff00a4eb1ec(&local_210,&local_130);
            FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,uVar14,0x10,
                       "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                      );
          }
        }
        uVar24 = *(undefined4 *)(uVar25 + 0x10);
        *(undefined4 *)(param_1 + 0x1a4) = uVar24;
        *(undefined4 *)(param_1 + 0x1a8) = local_228;
        *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
        *(int *)(param_1 + 0x1b0) = iVar22;
        *(undefined4 *)(param_1 + 0x1c0) = local_178._4_4_;
        *(undefined4 *)(param_1 + 0x1c4) = local_224;
        *(undefined4 *)(param_1 + 0x1c8) = uVar33;
        *(undefined4 *)(param_1 + 0x1b8) = *(undefined4 *)(uVar25 + 0x170);
        if (uVar25 + 0x178 <= uVar25) goto LAB_fffffff00a4f1e6c;
        *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(uVar25 + 0x174);
        if (local_198 != 0) {
          *(undefined4 *)(local_198 + 0xa8) = local_178._4_4_;
          *(int *)(local_198 + 0xac) = DAT_fffffff00adcda90;
          *(undefined4 *)(local_198 + 0xb8) = *(undefined4 *)(uVar25 + 0x170);
          *(undefined4 *)(local_198 + 0xbc) = *(undefined4 *)(uVar25 + 0x174);
        }
        if ((((ushort)local_190 >> 4 & 1) != 0) && ((*(byte *)(uVar25 + 0x21) >> 2 & 1) != 0)) {
          *(undefined4 *)(param_1 + 0x1a0) = local_1c0._4_4_;
        }
        if ((*(ushort *)(*(long *)(param_1 + 0x40) + 0x16) & 0xe) == 0) {
joined_r0xfffffff00a4f1658:
          bVar17 = false;
          if (1 < iVar20) goto LAB_fffffff00a4f166c;
LAB_fffffff00a4f165c:
          if (1 < DAT_fffffff00ad7ce48) goto LAB_fffffff00a4f166c;
        }
        else {
          iVar21 = *(int *)(uVar25 + 0x170);
          if (iVar21 == 3) {
LAB_fffffff00a4f1600:
            FUN_fffffff00a8df19c
                      (&MACH_HEADER,DAT_fffffff00ad7ce40,0x10,
                       "%s: Marking socket in state %d as defunct\n");
            lVar29 = FUN_fffffff00a29b24c();
            lVar32 = *(long *)(lVar29 + 0x18);
            if (*(long *)(lVar29 + 0x18) == 0) {
              lVar32 = DAT_fffffff007c6b250;
            }
            FUN_fffffff00a79dca0(lVar32,uVar31);
            goto joined_r0xfffffff00a4f1658;
          }
          if (iVar21 == 6) {
            uVar28 = FUN_fffffff00a4f3018(param_1,*(undefined4 *)(uVar25 + 0x174));
            if ((uVar28 & 1) == 0) goto LAB_fffffff00a4f1600;
            if ((*(ushort *)(*(long *)(param_1 + 0x40) + 0x16) & 0xe) == 0)
            goto joined_r0xfffffff00a4f1658;
            iVar21 = *(int *)(uVar25 + 0x170);
          }
          bVar17 = iVar21 == 6 && uStack_1c8._4_2_ == 6;
          if (iVar20 < 2) goto LAB_fffffff00a4f165c;
LAB_fffffff00a4f166c:
          uVar14 = DAT_fffffff00ad7ce40;
          iVar21 = FUN_fffffff00a4ecdf8(uVar31);
          uVar28 = uVar31 | 0xffffff8000000000;
          if (iVar21 == 0) {
            if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar28)) &&
               (uVar28 < 0xfffffffc00000000)) {
              FUN_fffffff00a1d12d4();
            }
          }
          else {
            uVar3 = uVar31 & 0x7ffffffffff;
            if ((uVar31 & 0x80000000000000) != 0) {
              uVar3 = uVar28;
            }
            FUN_fffffff00a396010(uVar3);
          }
          FUN_fffffff00a8df19c
                    (&MACH_HEADER,uVar14,0,
                     "%s: DATA-TRACE: Socket Policy: <so %llx> (BoundInterface %d Proto %d) Policy %d Skip %d Result %d Parameter %d Filter %d\n"
                    );
        }
        if (*(int *)(uVar25 + 0x170) == 3) {
          bVar19 = (*(uint *)(uVar25 + 0x174) & 3) == 1;
        }
        else {
joined_r0xfffffff00a4f1c38:
          bVar19 = false;
        }
joined_r0xfffffff00a4f1c38:
        if (lVar27 == 0) goto LAB_fffffff00a4f1744;
LAB_fffffff00a4f1770:
        iVar21 = FUN_fffffff00a6ec3c0(lVar27);
        lVar32 = lVar27;
        if ((iVar21 == 0) || (uVar25 = FUN_fffffff00a7266f8(lVar27), (uVar25 & 1) == 0))
        goto LAB_fffffff00a4f1790;
LAB_fffffff00a4f1c48:
        iVar21 = FUN_fffffff00a4eb308(lVar27,&local_220,0);
        if (iVar21 != 0) goto LAB_fffffff00a4f1c5c;
      }
      if (local_198 != 0) {
        FUN_fffffff00a7d8ee8();
      }
      FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
      if (bVar17) {
        FUN_fffffff00a5e438c(param_1);
        FUN_fffffff00a4f3184(param_1);
      }
      if ((bVar19) && (*(int *)(param_1 + 0x1b4) == 0)) {
        *(undefined4 *)(param_1 + 0x1b4) = 1;
        lVar32 = uVar31 + 0x354;
        lVar27 = uVar31 + 0x364;
        if ((*(uint *)(uVar31 + 0x230) & 0x10000000) != 0) {
          lVar32 = uVar31 + 0x364;
          lVar27 = uVar31 + 0x374;
        }
        if ((ulong)(lVar27 - lVar32) < 0x10) {
LAB_fffffff00a4f1e6c:
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x5519,0xfffffff00a4f1e70);
          (*pcVar16)();
        }
        lVar27 = 0x21c;
        if ((*(uint *)(uVar31 + 0x230) & 0x10000000) != 0) {
          lVar27 = 0x344;
        }
        FUN_fffffff00a4eb480(*(undefined4 *)(uVar31 + lVar27),lVar32,1);
      }
      if (local_188 != 0) {
        FUN_fffffff00a724838();
      }
      goto LAB_fffffff00a4f0f68;
    }
    if ((1 < iVar20) || (1 < DAT_fffffff00ad7ce48)) {
      iVar20 = FUN_fffffff00a4ecdf8(uVar31);
      uVar25 = uVar31 | 0xffffff8000000000;
      if (iVar20 == 0) {
        if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
           (uVar25 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar28 = uVar31 & 0x7ffffffffff;
        if ((uVar31 & 0x80000000000000) != 0) {
          uVar28 = uVar25;
        }
        FUN_fffffff00a396010(uVar28);
      }
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar14,0x10,
                 "%s: DATA-TRACE: Socket Policy: <so %llx> (BoundInterface %d Proto %d) Dropping packet because agent is not active\n"
                );
    }
    *puVar2 = 0x100000001;
    *(int *)(param_1 + 0x1ac) = DAT_fffffff00adcda90;
    *(int *)(param_1 + 0x1b0) = iVar22;
    *(undefined8 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 3;
    iVar20 = DAT_fffffff00adcda90;
    if (local_198 != 0) {
      *(undefined4 *)(local_198 + 0xa8) = 0;
      *(int *)(local_198 + 0xac) = iVar20;
      *(undefined8 *)(local_198 + 0xb8) = 0;
      FUN_fffffff00a7d8ee8();
    }
    FUN_fffffff00a228d30(&DAT_fffffff00adcd940);
    if (lVar32 != 0) {
      FUN_fffffff00a724838(lVar32);
    }
    uVar14 = DAT_fffffff00ad7ce10;
    if (bVar13) {
      uStack_108 = 0;
      local_110 = 0;
      uStack_f8 = 0;
      local_100 = 0;
      uStack_128 = 0;
      local_130 = 0;
      uStack_118 = 0;
      local_120 = 0;
      uStack_148 = 0;
      local_150 = 0;
      uStack_138 = 0;
      uStack_140 = 0;
      uStack_168 = 0;
      local_170 = 0;
      uStack_158 = 0;
      uStack_160 = 0;
      iVar20 = FUN_fffffff00a4ecdf8(uVar31);
      uVar25 = uVar31 | 0xffffff8000000000;
      if (iVar20 == 0) {
        if ((((uVar31 >> 0x37 & 1) != 0) && (0xffffffdbffffffff < uVar25)) &&
           (uVar25 < 0xfffffffc00000000)) {
          FUN_fffffff00a1d12d4();
        }
      }
      else {
        uVar28 = uVar31 & 0x7ffffffffff;
        if ((uVar31 & 0x80000000000000) != 0) {
          uVar28 = uVar25;
        }
        FUN_fffffff00a396010(uVar28);
      }
      FUN_fffffff00a4eb1ec(&local_210,&local_130);
      FUN_fffffff00a4eb1ec((long)&uStack_1f8 + 4,&local_170);
      FUN_fffffff00a8df19c
                (&MACH_HEADER,uVar14,0x10,
                 "%s: DATA-TRACE <%s %llx>: %s - fam %d proto %d port <local %d/%d remote %d/%d> <local %s remote %s> <drop-all order %d> <pid=%d Application %d Real Application %d BoundInterface %d> <policy_id %d skip_policy_id %d result %d>\n"
                );
      uVar24 = 0;
      goto LAB_fffffff00a4f0f68;
    }
  }
LAB_fffffff00a4f0f64:
  uVar24 = 0;
LAB_fffffff00a4f0f68:
  if (DAT_fffffff00ad30000 == local_70) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff00aa4c590(uVar24);
}

