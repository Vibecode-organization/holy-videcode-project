// FUN_fffffff00a9e3610 @ fffffff00a9e3610 size=952
// CALLERS:
//   fffffff00afbfae2 no-fn
//   fffffff007c66a78 no-fn
//   fffffff00a9e4a38 FUN_fffffff00a9e4958@fffffff00a9e4958
// CALLEES:
//   fffffff00a2260c4 FUN_fffffff00a2260c4
//   fffffff00a2261c0 FUN_fffffff00a2261c0
//   fffffff00a2212a8 FUN_fffffff00a2212a8
//   fffffff00a2216c4 FUN_fffffff00a2216c4
//   fffffff00a225fdc FUN_fffffff00a225fdc
//   fffffff00a29762c FUN_fffffff00a29762c
//   fffffff00a220c30 FUN_fffffff00a220c30
//   fffffff00a38ea04 FUN_fffffff00a38ea04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
FUN_fffffff00a9e3610
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
          undefined8 param_8,ulong param_9,undefined8 param_10,undefined *param_11)

{
  ulong uVar1;
  undefined *puVar2;
  char cVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined *puVar7;
  uint *puVar8;
  char *pcVar9;
  long lVar10;
  undefined1 *puVar11;
  long *plVar12;
  ulong uVar13;
  char *pcVar14;
  undefined **ppuVar15;
  undefined8 uVar16;
  undefined8 *puVar17;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined4 uVar18;
  undefined1 auVar19 [12];
  undefined4 uVar20;
  undefined1 auVar21 [12];
  undefined1 auVar22 [16];
  
  pcVar14 = DAT_fffffff00add76f8;
  uVar20 = param_4._0_4_;
  auVar21 = param_4._4_12_;
  uVar18 = param_3._0_4_;
  auVar19 = param_3._4_12_;
  uVar1 = param_9;
  if (0x3ff < param_9) {
    uVar1 = 0x400;
  }
  *(char **)(param_7 + 0x10) = DAT_fffffff00add76f8;
  if (pcVar14 == (char *)0x0) {
    puVar11 = (undefined1 *)FUN_fffffff00a2216c4((undefined8 *)&DAT_fffffff007c7f510,0);
    *(undefined1 **)(param_7 + 0x10) = puVar11;
    if (puVar11 == (undefined1 *)0x0) {
      return 0;
    }
    *puVar11 = 0;
    lVar10 = *(long *)(param_7 + 0x10);
    *(undefined8 *)(lVar10 + 8) = 0;
    *(code **)(lVar10 + 0x10) = FUN_fffffff00a9e3a00;
    *(code **)(lVar10 + 0x18) = FUN_fffffff00a9e39f4;
    *(code **)(lVar10 + 0x20) = FUN_fffffff00a9e39e8;
    *(code **)(lVar10 + 0x28) = FUN_fffffff00a9e39e0;
    *(code **)(lVar10 + 0x30) = FUN_fffffff00a9e39d8;
    *(code **)(lVar10 + 0x38) = FUN_fffffff00a9e39d0;
    *(code **)(lVar10 + 0x40) = FUN_fffffff00a9e39c8;
    *(undefined8 *)(lVar10 + 0x48) = 0;
    *(undefined8 *)(lVar10 + 0x50) = 0;
    *(undefined8 *)(lVar10 + 0x58) = 0;
    uVar16 = FUN_fffffff00a2260c4(DAT_fffffff00ad966d0);
    *(undefined8 *)(*(long *)(param_7 + 0x10) + 0x60) = uVar16;
    pcVar14 = *(char **)(param_7 + 0x10);
    if (*(long *)(pcVar14 + 0x60) == 0) {
LAB_fffffff00a9e3970:
      if (*(long **)(pcVar14 + 0x68) != (long *)0x0) {
        (**(code **)(**(long **)(pcVar14 + 0x68) + 0x28))();
        pcVar14 = *(char **)(param_7 + 0x10);
      }
      *(undefined8 *)(param_7 + 0x10) = 0;
      FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c7f590,(undefined8 *)pcVar14);
      *(undefined8 *)(param_7 + 0x10) = 0;
      return 0;
    }
    plVar12 = (long *)(**(code **)(DAT_fffffff00ad95e68 + 0x68))();
    param_1._8_8_ = extraout_var_00;
    param_1._0_8_ = extraout_d0_00;
    if (plVar12 != (long *)0x0) {
      uVar13 = (**(code **)(*plVar12 + 0xd0))(plVar12,4);
      param_1._8_8_ = extraout_var_01;
      param_1._0_8_ = extraout_d0_01;
      if ((uVar13 & 1) == 0) {
        param_1 = (**(code **)(*plVar12 + 0x28))(plVar12);
        plVar12 = (long *)0x0;
      }
    }
    *(long **)(*(long *)(param_7 + 0x10) + 0x68) = plVar12;
    pcVar9 = DAT_fffffff00add76f8;
    pcVar14 = *(char **)(param_7 + 0x10);
    if (*(long *)(pcVar14 + 0x68) == 0) {
      puVar17 = *(undefined8 **)(pcVar14 + 0x60);
      if (puVar17 != (undefined8 *)0x0) {
        FUN_fffffff00a2261c0((undefined4 *)puVar17,(int *)DAT_fffffff00ad966d0);
        FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c6cfd0,puVar17);
        pcVar14 = *(char **)(param_7 + 0x10);
      }
      goto LAB_fffffff00a9e3970;
    }
    if (DAT_fffffff00add76f8 == (char *)0x0) {
      DAT_fffffff00add76f8 = pcVar14;
    }
    pcVar14 = *(char **)(param_7 + 0x10);
    if (pcVar9 != (char *)0x0) {
      puVar17 = *(undefined8 **)(*(char **)(param_7 + 0x10) + 0x60);
      FUN_fffffff00a2261c0((undefined4 *)puVar17,(int *)DAT_fffffff00ad966d0);
      FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c6cfd0,puVar17);
      (**(code **)(**(long **)(*(long *)(param_7 + 0x10) + 0x68) + 0x28))();
      puVar17 = *(undefined8 **)(param_7 + 0x10);
      *(undefined8 *)(param_7 + 0x10) = 0;
      param_1 = FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c7f550,puVar17);
      *(char **)(param_7 + 0x10) = pcVar9;
      pcVar14 = pcVar9;
    }
  }
  *(undefined8 *)(param_7 + 0x18) = 0;
  *(undefined8 *)(param_7 + 0x30) = 0;
  cVar3 = *pcVar14;
  *pcVar14 = cVar3 + '\x01';
  *(char *)(param_7 + 0xd) = cVar3 + '\x01';
  *(ulong *)(param_7 + 0x20) = uVar1 + 1;
  if (param_9 == 0) {
LAB_fffffff00a9e36b8:
    *(undefined8 *)(param_7 + 0x68) = 0;
    *(undefined8 *)(param_7 + 0x60) = 0;
    *(undefined8 *)(param_7 + 0x58) = 0;
    *(undefined8 *)(param_7 + 0x50) = 0;
    *(undefined8 *)(param_7 + 0x48) = 0;
    *(undefined8 *)(param_7 + 0x40) = 0;
    *(undefined8 *)(param_7 + 0x38) = 0;
    uVar16 = 1;
  }
  else {
    uVar16 = 0;
    auVar22._4_12_ = auVar19;
    auVar22._0_4_ = uVar18;
    auVar6._4_12_ = auVar21;
    auVar6._0_4_ = uVar20;
    auVar22 = FUN_fffffff00a220c30
                        (param_1,param_2,auVar22,auVar6,param_5,param_6,
                         (long *)&DAT_fffffff007c884f1,(ulong *)((uVar1 + 1) * 0x38),
                         (ulong *)&DAT_00000004,(undefined ********)0x0);
    *(long *)(param_7 + 0x18) = auVar22._0_8_;
    if (auVar22._0_8_ == 0) {
LAB_fffffff00a9e38fc:
      puVar8 = DAT_fffffff00ad966d0;
      uVar16 = _DAT_fffffff00700eff0;
      puVar17 = *(undefined8 **)(param_7 + 0x30);
      if (puVar17 != (undefined8 *)0x0) {
        puVar17[1] = _UNK_fffffff00700eff8;
        *puVar17 = uVar16;
        if (puVar8 != (uint *)0x0) {
          FUN_fffffff00a225fdc((int *)puVar8,(int *)(puVar8 + 2));
        }
        FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c6e790,puVar17);
        *(undefined8 *)(param_7 + 0x30) = 0;
        return 0;
      }
    }
    else {
      *(undefined8 *)(param_7 + 0x28) = 1;
      lVar10 = FUN_fffffff00a38ea04(DAT_fffffff00ad966d0);
      *(long *)(param_7 + 0x30) = lVar10;
      if (lVar10 != 0) goto LAB_fffffff00a9e36b8;
      ppuVar15 = *(undefined ***)(param_7 + 0x18);
      if (ppuVar15 != (undefined **)0x0) {
        *(undefined8 *)(param_7 + 0x18) = 0;
        puVar7 = (undefined *)(*(ulong *)(param_7 + 0x20) * 0x38);
        auVar4._8_8_ = 0;
        auVar4._0_8_ = *(ulong *)(param_7 + 0x20);
        puVar2 = (undefined *)0x8000000000000000;
        if (SUB168(auVar4 * ZEXT816(0x38),8) == 0 && -1 < (long)puVar7) {
          puVar2 = puVar7;
        }
        auVar5._8_8_ = extraout_var;
        auVar5._0_8_ = extraout_d0;
        FUN_fffffff00a2212a8
                  (auVar5,param_2,uVar18,uVar20,param_5,param_6,(long *)&DAT_fffffff007c88541,
                   ppuVar15,puVar2,uVar16,param_11);
        *(undefined8 *)(param_7 + 0x18) = 0;
        goto LAB_fffffff00a9e38fc;
      }
    }
    uVar16 = 0;
  }
  return uVar16;
}

