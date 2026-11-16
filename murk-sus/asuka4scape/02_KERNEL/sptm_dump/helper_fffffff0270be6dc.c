// FUN_fffffff0270be6dc @ fffffff0270be6dc size=784
// caller fffffff0270abc94 FUN_fffffff0270abc74
// caller fffffff0270ac2b8 FUN_fffffff0270ac298
// caller fffffff0270ac634 FUN_fffffff0270ac614
// caller fffffff0270ad2c8 FUN_fffffff0270ad28c
// caller fffffff0270ad5d0 FUN_fffffff0270ad5a4
// caller fffffff0270ad8dc FUN_fffffff0270ad8a4
// caller fffffff0270ada6c FUN_fffffff0270ada40
// caller fffffff0270ae24c FUN_fffffff0270ae210
// caller fffffff0270ae560 FUN_fffffff0270ae534
// caller fffffff0270ae860 FUN_fffffff0270ae830
// caller fffffff0270aeb38 FUN_fffffff0270aeb0c
// caller fffffff0270aef04 FUN_fffffff0270aeed4

void FUN_fffffff0270be6dc(ulong param_1,uint param_2,byte param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 extraout_x1;
  undefined8 uVar3;
  undefined8 extraout_x1_00;
  undefined2 *puVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong uVar9;
  undefined1 auVar10 [16];
  
  lVar6 = *(long *)(DAT_fffffff0270921b8 + 0x10);
  if (lVar6 == 0) {
    auVar10 = FUN_fffffff0270d2f50(*(undefined8 *)(DAT_fffffff0270921b8 + 0x18));
    uVar3 = auVar10._8_8_;
    if (param_1 == auVar10._0_8_) goto LAB_fffffff0270be7d0;
    lVar6 = *(long *)(DAT_fffffff0270921b8 + 0x10);
  }
  if (lVar6 == 1) {
    auVar10 = FUN_fffffff0270d2f50(*(undefined8 *)(DAT_fffffff0270921b8 + 0x18));
    uVar3 = auVar10._8_8_;
    if (param_1 == auVar10._0_8_) goto LAB_fffffff0270be7d0;
  }
  FUN_fffffff0270dfa18(param_1,0x18);
  uVar9 = param_1 & 0x3fff;
  uVar7 = *(ulong *)(DAT_fffffff0270921b8 + 0x1c0);
  uVar5 = 0;
  if (uVar7 != 0) {
    uVar5 = uVar9 / uVar7;
  }
  if ((uVar9 != uVar5 * uVar7) || (0x4000 < uVar7 + uVar9)) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000005,extraout_x1,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
  }
  if ((param_1 < DAT_fffffff0270921c8) || (DAT_fffffff0270921d0 <= param_1)) {
    auVar10 = FUN_fffffff0270de884(param_1);
    uVar3 = auVar10._8_8_;
    puVar4 = &DAT_fffffff0270fdec0;
    if (auVar10._0_8_ != (undefined2 *)0x0) {
      puVar4 = auVar10._0_8_;
    }
  }
  else {
    uVar3 = extraout_x1;
    puVar4 = (undefined2 *)
             (DAT_fffffff0270914f0 + (param_1 - DAT_fffffff0270921c8 >> 0xe & 0xffffffff) * 0x10);
  }
  if (*(int *)(puVar4 + 4) != 0) {
    FUN_fffffff0270be9ec(param_1);
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000000,extraout_x1_00,"%s(%s:%d) - %s(%#llx)\n");
  }
LAB_fffffff0270be7d0:
  if (((uint)DAT_fffffff027102040 >> 8 & 1) == 0) {
    auVar10._8_8_ = uVar3;
    auVar10._0_8_ = (param_1 - DAT_fffffff0270921c8) + DAT_fffffff027090ff0;
  }
  else {
    uVar5 = (ulong)DAT_fffffff0270fd9f8;
    if (DAT_fffffff0270fd9f8 != 0) {
      lVar6 = 0;
      do {
        puVar8 = &DAT_fffffff0270fda00 + lVar6 * 3;
        if ((((ulong)puVar8 ^ 0xfffffff0270fda00) & 0xffc0000000000000) != 0) {
          puVar8 = (ulong *)((ulong)puVar8 & 0xffffffffffff | 0xc8a2000000000000);
        }
        uVar9 = *puVar8;
        if ((uVar9 <= param_1) && (param_1 < uVar9 + (ulong)(uint)puVar8[2] * 0x4000)) {
          auVar10._8_8_ = uVar3;
          auVar10._0_8_ = (param_1 - uVar9) + puVar8[1];
          goto LAB_fffffff0270be850;
        }
        lVar6 = lVar6 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
    auVar10 = FUN_fffffff0270debdc(param_1);
  }
LAB_fffffff0270be850:
  if ((*auVar10._0_8_ & param_3) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_fffffff0270f353c(0x4000002,auVar10._8_8_,"%s(%s:%d) - %s(%#llx), %s(%#llx)\n");
  }
  pbVar1 = auVar10._0_8_ + 0x1a;
  bVar2 = *pbVar1;
  if (bVar2 == (byte)param_2) {
    *pbVar1 = 1;
  }
  if (bVar2 == param_2) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_fffffff0270f353c(0x4000004,auVar10._8_8_,"%s(%s:%d) - %s(%#llx), %s(%#llx), %s(%#llx)\n");
}

