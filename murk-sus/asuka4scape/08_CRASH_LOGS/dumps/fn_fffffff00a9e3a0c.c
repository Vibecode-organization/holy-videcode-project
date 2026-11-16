// FUN_fffffff00a9e3a0c @ fffffff00a9e3a0c size=244
// CALLERS:
//   fffffff00afbfaec no-fn
//   fffffff007c66a70 no-fn
// CALLEES:
//   fffffff00a2212a8 FUN_fffffff00a2212a8
//   fffffff00a8962c0 FUN_fffffff00a8962c0
//   fffffff00a225fdc FUN_fffffff00a225fdc
//   fffffff00a29762c FUN_fffffff00a29762c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_fffffff00a9e3a0c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
               undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined *param_11)

{
  undefined *puVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined *puVar6;
  undefined8 uVar7;
  int *piVar8;
  long lVar9;
  undefined **ppuVar10;
  undefined8 *puVar11;
  undefined8 extraout_d0;
  undefined8 extraout_var;
  undefined4 uVar12;
  undefined1 auVar13 [12];
  undefined4 uVar14;
  undefined1 auVar15 [12];
  
  uVar14 = param_4._0_4_;
  auVar15 = param_4._4_12_;
  uVar12 = param_3._0_4_;
  auVar13 = param_3._4_12_;
  ppuVar10 = (undefined **)param_7[3];
  if (ppuVar10 != (undefined **)0x0) {
    param_7[3] = 0;
    puVar6 = (undefined *)(param_7[4] * 0x38);
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_7[4];
    puVar1 = (undefined *)0x8000000000000000;
    if (SUB168(auVar2 * ZEXT816(0x38),8) == 0 && -1 < (long)puVar6) {
      puVar1 = puVar6;
    }
    FUN_fffffff00a2212a8
              (param_1,param_2,uVar12,uVar14,param_5,param_6,(long *)&DAT_fffffff007c88591,ppuVar10,
               puVar1,param_10,param_11);
  }
  piVar8 = DAT_fffffff00ad966d0;
  uVar7 = _DAT_fffffff00700eff0;
  puVar11 = (undefined8 *)param_7[6];
  if (puVar11 != (undefined8 *)0x0) {
    puVar11[1] = _UNK_fffffff00700eff8;
    *puVar11 = uVar7;
    if (piVar8 != (int *)0x0) {
      FUN_fffffff00a225fdc(piVar8,piVar8 + 2);
    }
    FUN_fffffff00a29762c((undefined8 *)&DAT_fffffff007c6e790,puVar11);
  }
  lVar9 = (**(code **)(*param_7 + 0x38))(param_7);
  if (lVar9 != 0) {
    auVar3._8_8_ = extraout_var;
    auVar3._0_8_ = extraout_d0;
    auVar4._4_12_ = auVar13;
    auVar4._0_4_ = uVar12;
    auVar5._4_12_ = auVar15;
    auVar5._0_4_ = uVar14;
    FUN_fffffff00a8962c0(auVar3,param_2,auVar4,auVar5,param_5,param_6,lVar9);
  }
                    /* WARNING: Could not recover jumptable at 0xfffffff00a9e3afc. Too many branches
                        */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_7 + 8))(param_7,(undefined8 *)(*param_7 + 8));
  return;
}

