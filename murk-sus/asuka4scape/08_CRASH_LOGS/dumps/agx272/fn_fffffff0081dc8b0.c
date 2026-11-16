// FUN_fffffff0081dc8b0 @ fffffff0081dc8b0 size=740

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff0081dc8b0(long param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  double dVar3;
  long lVar4;
  long lVar5;
  ulong uVar7;
  undefined1 auVar6 [16];
  undefined1 auVar8 [16];
  float fVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  
  param_2[5] = 0xffff0000ffff;
  param_2[4] = 0xffff0000ffff;
  param_2[7] = 0xffff0000ffff;
  param_2[6] = 0xffff0000ffff;
  *(undefined4 *)(param_2 + 8) = 0xffff;
  *(undefined8 *)((long)param_2 + 0x4c) = 0xfc70fc70fc70fc7;
  *(undefined8 *)((long)param_2 + 0x44) = 0xfc70fc70fc70fc7;
  *(undefined8 *)((long)param_2 + 0x5c) = 0xfc70fc70fc70fc7;
  *(undefined8 *)((long)param_2 + 0x54) = 0xfc70fc70fc70fc7;
  *(undefined4 *)((long)param_2 + 0x8c) = 0x1ffffff;
  *(undefined4 *)(param_2 + 0x12) = 0x1ffffff;
  *(undefined8 *)((long)param_2 + 0x84) = 0x1ffffff01ffffff;
  *(undefined4 *)((long)param_2 + 0x9c) = 0x1ffffff;
  *(undefined4 *)(param_2 + 0x14) = 0x1ffffff;
  *(undefined8 *)((long)param_2 + 0x94) = 0x1ffffff01ffffff;
  *(undefined8 *)((long)param_2 + 0x6c) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 100) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0x7c) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0x74) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xe4) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xdc) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xfc) = 0xffffffffffffffff;
  *(undefined8 *)((long)param_2 + 0xf4) = 0xffffffffffffffff;
  uVar2 = _DAT_fffffff007113ad0;
  param_2[1] = _UNK_fffffff007113ad8;
  *param_2 = uVar2;
  param_2[3] = 0xffff0000ffff;
  param_2[2] = 0xffff0000ffff;
  *(ulong *)((long)param_2 + 0x5d4) =
       *(ulong *)((long)param_2 + 0x5d4) & 0xffffffffffffffef | 0xc0000f;
  uVar2 = _DAT_fffffff007113bc0;
  puVar1 = (undefined8 *)(param_1 + 0x19448);
  *(undefined8 *)((long)param_2 + 0xd4) = _UNK_fffffff007113bc8;
  *(undefined8 *)((long)param_2 + 0xcc) = uVar2;
  dVar3 = DAT_fffffff007113ff8;
  if (((long)param_2 + 4U < param_1 + 0x1984cU) && (puVar1 < (undefined8 *)((long)param_2 + 0x44)))
  {
    lVar4 = 0;
    lVar5 = 0x10;
    do {
      fVar9 = (float)NEON_ucvtf(*(undefined4 *)(param_1 + 0x19488 + lVar4 * 0x40));
      *(int *)((long)param_2 + 4U + lVar4 * 4) =
           (int)(10000000.0 /
                ((double)(fVar9 * (float)((ulong)*(uint *)((long)puVar1 + lVar4 * 4) / 1000000)) *
                dVar3));
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
    return;
  }
  auVar8._0_4_ = *(undefined4 *)(param_1 + 0x19488);
  auVar8._4_4_ = *(undefined4 *)(param_1 + 0x194c8);
  auVar8._8_4_ = *(undefined4 *)(param_1 + 0x19508);
  auVar8._12_4_ = *(undefined4 *)(param_1 + 0x19548);
  auVar8 = NEON_ucvtf(auVar8,4);
  auVar10._8_4_ = 0x431bde83;
  auVar10._0_8_ = 0x431bde83431bde83;
  auVar10._12_4_ = 0x431bde83;
  uVar7 = auVar10._8_8_;
  auVar10 = NEON_umull(*puVar1,0x431bde83431bde83,4);
  auVar11._0_4_ = auVar10._4_4_ >> 0x12;
  auVar11._4_4_ = auVar10._12_4_ >> 0x12;
  auVar11._8_4_ =
       (uint)((*(ulong *)(param_1 + 0x19450) & 0xffffffff) * (uVar7 & 0xffffffff) >> 0x32);
  auVar11._12_4_ = (uint)((*(ulong *)(param_1 + 0x19450) >> 0x20) * (uVar7 >> 0x20) >> 0x32);
  auVar10 = NEON_ucvtf(auVar11,4);
  auVar14._0_4_ = *(undefined4 *)(param_1 + 0x19588);
  auVar14._4_4_ = *(undefined4 *)(param_1 + 0x195c8);
  auVar14._8_4_ = *(undefined4 *)(param_1 + 0x19608);
  auVar14._12_4_ = *(undefined4 *)(param_1 + 0x19648);
  *(int *)((long)param_2 + 0xc) = (int)(long)(1e+07 / (auVar8._8_4_ * auVar10._8_4_ * 0.003));
  *(int *)(param_2 + 2) = (int)(long)(1e+07 / (auVar8._12_4_ * auVar10._12_4_ * 0.003));
  *(int *)((long)param_2 + 4) = (int)(long)(1e+07 / (auVar8._0_4_ * auVar10._0_4_ * 0.003));
  *(int *)(param_2 + 1) = (int)(long)(1e+07 / (auVar8._4_4_ * auVar10._4_4_ * 0.003));
  auVar8 = NEON_ucvtf(auVar14,4);
  auVar10 = NEON_umull(*(undefined8 *)(param_1 + 0x19458),0x431bde83431bde83,4);
  auVar15._0_4_ = auVar10._4_4_ >> 0x12;
  auVar15._4_4_ = auVar10._12_4_ >> 0x12;
  auVar15._8_4_ =
       (uint)((*(ulong *)(param_1 + 0x19460) & 0xffffffff) * (uVar7 & 0xffffffff) >> 0x32);
  auVar15._12_4_ = (uint)((*(ulong *)(param_1 + 0x19460) >> 0x20) * (uVar7 >> 0x20) >> 0x32);
  auVar10 = NEON_ucvtf(auVar15,4);
  *(int *)((long)param_2 + 0x1c) = (int)(long)(1e+07 / (auVar8._8_4_ * auVar10._8_4_ * 0.003));
  *(int *)(param_2 + 4) = (int)(long)(1e+07 / (auVar8._12_4_ * auVar10._12_4_ * 0.003));
  *(int *)((long)param_2 + 0x14) = (int)(long)(1e+07 / (auVar8._0_4_ * auVar10._0_4_ * 0.003));
  *(int *)(param_2 + 3) = (int)(long)(1e+07 / (auVar8._4_4_ * auVar10._4_4_ * 0.003));
  auVar12._0_4_ = *(undefined4 *)(param_1 + 0x19688);
  auVar12._4_4_ = *(undefined4 *)(param_1 + 0x196c8);
  auVar12._8_4_ = *(undefined4 *)(param_1 + 0x19708);
  auVar12._12_4_ = *(undefined4 *)(param_1 + 0x19748);
  auVar8 = NEON_ucvtf(auVar12,4);
  auVar10 = NEON_umull(*(undefined8 *)(param_1 + 0x19468),0x431bde83431bde83,4);
  auVar16._0_4_ = auVar10._4_4_ >> 0x12;
  auVar16._4_4_ = auVar10._12_4_ >> 0x12;
  auVar16._8_4_ =
       (uint)((*(ulong *)(param_1 + 0x19470) & 0xffffffff) * (uVar7 & 0xffffffff) >> 0x32);
  auVar16._12_4_ = (uint)((*(ulong *)(param_1 + 0x19470) >> 0x20) * (uVar7 >> 0x20) >> 0x32);
  auVar10 = NEON_ucvtf(auVar16,4);
  *(int *)((long)param_2 + 0x2c) = (int)(long)(1e+07 / (auVar8._8_4_ * auVar10._8_4_ * 0.003));
  *(int *)(param_2 + 6) = (int)(long)(1e+07 / (auVar8._12_4_ * auVar10._12_4_ * 0.003));
  *(int *)((long)param_2 + 0x24) = (int)(long)(1e+07 / (auVar8._0_4_ * auVar10._0_4_ * 0.003));
  *(int *)(param_2 + 5) = (int)(long)(1e+07 / (auVar8._4_4_ * auVar10._4_4_ * 0.003));
  auVar13._0_4_ = *(undefined4 *)(param_1 + 0x19788);
  auVar13._4_4_ = *(undefined4 *)(param_1 + 0x197c8);
  auVar13._8_4_ = *(undefined4 *)(param_1 + 0x19808);
  auVar13._12_4_ = *(undefined4 *)(param_1 + 0x19848);
  auVar10 = NEON_ucvtf(auVar13,4);
  auVar8 = NEON_umull(*(undefined8 *)(param_1 + 0x19478),0x431bde83431bde83,4);
  auVar6._0_4_ = auVar8._4_4_ >> 0x12;
  auVar6._4_4_ = auVar8._12_4_ >> 0x12;
  auVar6._8_4_ = (uint)((*(ulong *)(param_1 + 0x19480) & 0xffffffff) * (uVar7 & 0xffffffff) >> 0x32)
  ;
  auVar6._12_4_ = (uint)((*(ulong *)(param_1 + 0x19480) >> 0x20) * (uVar7 >> 0x20) >> 0x32);
  auVar8 = NEON_ucvtf(auVar6,4);
  *(int *)((long)param_2 + 0x3c) = (int)(long)(1e+07 / (auVar10._8_4_ * auVar8._8_4_ * 0.003));
  *(int *)(param_2 + 8) = (int)(long)(1e+07 / (auVar10._12_4_ * auVar8._12_4_ * 0.003));
  *(int *)((long)param_2 + 0x34) = (int)(long)(1e+07 / (auVar10._0_4_ * auVar8._0_4_ * 0.003));
  *(int *)(param_2 + 7) = (int)(long)(1e+07 / (auVar10._4_4_ * auVar8._4_4_ * 0.003));
  return;
}

