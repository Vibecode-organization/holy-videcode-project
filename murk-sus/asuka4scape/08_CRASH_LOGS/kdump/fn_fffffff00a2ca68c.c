// FUN_fffffff00a2ca68c @ fffffff00a2ca68c size=664
// CALLERS:
//   fffffff00afb931a ?
//   fffffff00a2c09a0 FUN_fffffff00a2c0888@fffffff00a2c0888
// CALLS:
//   fffffff00a3ec1d8 FUN_fffffff00a3ec1d8
//   fffffff00a3e8aa8 FUN_fffffff00a3e8aa8
//   fffffff00a2c7e48 FUN_fffffff00a2c7e48
//   fffffff00a2262d4 FUN_fffffff00a2262d4
//   fffffff00a226e08 FUN_fffffff00a226e08
//   fffffff00a7e0f00 FUN_fffffff00a7e0f00
//   fffffff00a28c5d4 FUN_fffffff00a28c5d4

undefined4 FUN_fffffff00a2ca68c(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  uint *puVar3;
  undefined8 extraout_x1;
  undefined **ppuVar4;
  undefined4 **ppuVar5;
  ulong uVar6;
  long lVar7;
  uint *puVar8;
  ulong uVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  undefined4 in_wzr;
  undefined1 auVar12 [16];
  undefined1 in_q1 [16];
  undefined4 in_s2;
  undefined4 in_s3;
  undefined4 in_s4;
  undefined4 in_s5;
  
  lVar1 = tpidr_el1;
  uVar6 = (ulong)*(uint *)(lVar1 + 0x4e8);
  if (DAT_fffffff00ad8a2e8 != 0) {
    FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar1,(undefined **)0x0);
    uVar6 = DAT_fffffff00ad8a2e8;
  }
  DAT_fffffff00ad8a2e8 = uVar6;
  puVar11 = &DAT_fffffff00ad44380;
  do {
    puVar11 = (undefined8 *)*puVar11;
    if (puVar11 == &DAT_fffffff00ad44380) goto LAB_fffffff00a2ca850;
  } while (*(uint *)((long)puVar11 + 0x3c) != (uint)(param_2 >> 0x21));
  if ((puVar11 == (undefined8 *)0x0) || (puVar8 = (uint *)(puVar11 + 8), (*puVar8 & 3) == 0)) {
LAB_fffffff00a2ca850:
    *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar1 + 0x1b0) * 0x4000) =
         *(long *)(PTR_DAT_fffffff00ad0e3a0 + (ulong)*(ushort *)(lVar1 + 0x1b0) * 0x4000) + 1;
    uVar10 = 5;
    goto LAB_fffffff00a2ca86c;
  }
  *(int *)(puVar11 + 9) = *(int *)(puVar11 + 9) + 1;
  if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar1 + 0x4e8)) {
    DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
  }
  else {
    FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar1,(uint)DAT_fffffff00ad8a2e8);
  }
  iVar2 = FUN_fffffff00a3ec1d8(puVar11[3]);
  if (iVar2 == 0) {
    ppuVar4 = *(undefined ***)(param_1 + 0x70);
    uVar9 = param_3 >> 0xe;
    ppuVar5 = (undefined4 **)0x1;
    uVar6 = uVar9;
    iVar2 = FUN_fffffff00a7e0f00
                      ((undefined8 *)puVar11[3],(undefined4 *****)(param_2 & 0x1ffffffff),ppuVar4,
                       (int)uVar9,1,(undefined4 ****)0x0);
    FUN_fffffff00a3e8aa8((undefined8 *)puVar11[3],extraout_x1,ppuVar4,uVar6,ppuVar5);
    if (iVar2 != 0) goto LAB_fffffff00a2ca76c;
    ppuVar4 = &PTR_DAT_fffffff00ad18900;
    uVar10 = 0;
  }
  else {
LAB_fffffff00a2ca76c:
    uVar10 = 5;
    ppuVar4 = &PTR_DAT_fffffff00ad0e3a0;
    uVar9 = 1;
  }
  *(ulong *)(*ppuVar4 + (ulong)*(ushort *)(lVar1 + 0x1b0) * 0x4000) =
       *(long *)(*ppuVar4 + (ulong)*(ushort *)(lVar1 + 0x1b0) * 0x4000) + uVar9;
  auVar12 = FUN_fffffff00a2c7e48(param_2);
  uVar6 = (ulong)*(uint *)(lVar1 + 0x4e8);
  if (DAT_fffffff00ad8a2e8 != 0) {
    auVar12 = FUN_fffffff00a2262d4(0xfffffff00ad8a2e0,lVar1,(undefined **)0x0);
    uVar6 = DAT_fffffff00ad8a2e8;
  }
  DAT_fffffff00ad8a2e8 = uVar6;
  iVar2 = *(int *)(puVar11 + 9);
  *(int *)(puVar11 + 9) = iVar2 + -1;
  if (((*(uint *)(puVar11 + 8) >> 2 & 1) != 0) && (iVar2 + -1 == 0)) {
    *puVar8 = *(uint *)(puVar11 + 8) & 0xfffffffb;
    uVar6 = ((ulong)puVar8 ^ (ulong)puVar8 >> 0x1f) * 0x7fb5d329728ea185;
    lVar7 = (uVar6 ^ uVar6 >> 0x1b) * -0x7e25210b43d22bb3;
    puVar3 = (uint *)(PTR_DAT_fffffff007bc7040 +
                     (ulong)(DAT_fffffff007bc7048 - 1U &
                            ((uint)((ulong)lVar7 >> 0x21) ^ (uint)lVar7)) * 0x18);
    if ((((ulong)PTR_DAT_fffffff007bc7040 ^ (ulong)puVar3) & 0xffc0000000000000) != 0) {
      puVar3 = (uint *)((ulong)puVar3 & 0xffffffffffff | 0xc8a2000000000000);
    }
    FUN_fffffff00a28c5d4(auVar12,in_q1,in_s2,in_s3,in_s4,in_s5,puVar3,(long)puVar8,0,0,0xffffffff);
  }
LAB_fffffff00a2ca86c:
  if ((uint)DAT_fffffff00ad8a2e8 == *(uint *)(lVar1 + 0x4e8)) {
    DAT_fffffff00ad8a2e8 = CONCAT44(DAT_fffffff00ad8a2e8._4_4_,in_wzr);
  }
  else {
    FUN_fffffff00a226e08(0xfffffff00ad8a2e0,lVar1,(uint)DAT_fffffff00ad8a2e8);
  }
  return uVar10;
}

