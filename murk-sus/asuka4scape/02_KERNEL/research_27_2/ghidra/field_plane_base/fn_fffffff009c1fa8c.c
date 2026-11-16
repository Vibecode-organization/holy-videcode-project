// FUN_fffffff009c1fa8c @ fffffff009c1fa8c

/* WARNING: Removing unreachable block (ram,0xfffffff009c1fb24) */

void FUN_fffffff009c1fa8c
               (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
               undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,
               undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined *param_11)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined4 uVar9;
  undefined1 auVar10 [12];
  undefined4 uVar11;
  undefined1 auVar12 [12];
  
  uVar11 = param_4._0_4_;
  auVar12 = param_4._4_12_;
  uVar9 = param_3._0_4_;
  auVar10 = param_3._4_12_;
  uVar3 = param_7 + 0x1b0;
  if ((param_7 + 0x210U < uVar3) || ((param_7 + 0x210U) - uVar3 >> 0x20 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff009c48f64(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  uVar8 = 0;
  do {
    puVar1 = (undefined8 *)(uVar3 + uVar8);
    uVar6 = -(ulong)CARRY8(uVar3,uVar8);
    if ((uVar6 != CARRY8(uVar3,uVar8)) || ((long)uVar6 < 0)) {
      auVar4._4_12_ = auVar10;
      auVar4._0_4_ = uVar9;
      auVar5._4_12_ = auVar12;
      auVar5._0_4_ = uVar11;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(param_1,param_2,auVar4,auVar5,param_5,param_6);
    }
    if (((undefined **)*puVar1 != (undefined **)0x0) && ((undefined *)puVar1[1] != (undefined *)0x0)
       ) {
      param_1 = thunk_FUN_fffffff00a9026b0
                          (param_1,param_2,uVar9,uVar11,param_5,param_6,(undefined **)*puVar1,
                           (undefined *)puVar1[1],param_9,param_10,param_11);
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    uVar2 = (int)uVar8 + 0x10;
    uVar8 = (ulong)uVar2;
  } while (uVar2 != 0x60);
  lVar7 = *(long *)(param_7 + 0x178);
  if ((lVar7 != 0) && (lVar7 != 0)) {
    *(undefined1 *)(lVar7 + 0x2f) = 0;
  }
  return;
}

