// FUN_fffffff009c2a76c @ fffffff009c2a76c

/* WARNING: Removing unreachable block (ram,0xfffffff009c2a868) */

undefined8
FUN_fffffff009c2a76c
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long param_7,ulong param_8,
          ulong *param_9,undefined8 *param_10,undefined *param_11)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined8 *extraout_x0;
  ulong *puVar11;
  undefined8 *puVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 uVar15;
  undefined1 auVar16 [16];
  undefined4 uVar17;
  undefined1 auVar18 [12];
  undefined4 uVar19;
  undefined1 auVar20 [12];
  
  uVar19 = param_4._0_4_;
  auVar20 = param_4._4_12_;
  uVar17 = param_3._0_4_;
  auVar18 = param_3._4_12_;
  uVar15 = 0xe00002c2;
  if (((param_8 < 6) && (param_9 < (ulong *)0x401)) &&
     ((param_9 == (ulong *)0x0 || (param_10 != (undefined8 *)0x0)))) {
    puVar11 = param_9;
    puVar12 = param_10;
    auVar16 = thunk_FUN_fffffff00a2262a8(*(ulong *)(param_7 + 0x50));
    uVar13 = param_7 + 0x1b0;
    uVar14 = (param_7 + 0x210U) - uVar13;
    if ((param_7 + 0x210U < uVar13) || (uVar14 >> 0x20 != 0)) {
      auVar3._4_12_ = auVar18;
      auVar3._0_4_ = uVar17;
      auVar7._4_12_ = auVar20;
      auVar7._0_4_ = uVar19;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f64(auVar16,param_2,auVar3,auVar7,param_5,param_6);
    }
    uVar2 = (uint)param_8 * 0x10;
    if ((uint)uVar14 < uVar2 + 0x10) {
      auVar4._4_12_ = auVar18;
      auVar4._0_4_ = uVar17;
      auVar8._4_12_ = auVar20;
      auVar8._0_4_ = uVar19;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f28(auVar16,param_2,auVar4,auVar8,param_5,param_6);
    }
    puVar1 = (undefined8 *)(uVar13 + uVar2);
    uVar14 = (ulong)CARRY8(uVar13,(ulong)uVar2);
    uVar13 = -uVar14;
    if ((uVar13 != uVar14) || ((long)uVar13 < 0)) {
      auVar5._4_12_ = auVar18;
      auVar5._0_4_ = uVar17;
      auVar9._4_12_ = auVar20;
      auVar9._0_4_ = uVar19;
                    /* WARNING: Subroutine does not return */
      FUN_fffffff009c48f50(auVar16,param_2,auVar5,auVar9,param_5,param_6);
    }
    if (((undefined **)*puVar1 != (undefined **)0x0) && ((undefined *)puVar1[1] != (undefined *)0x0)
       ) {
      auVar16 = thunk_FUN_fffffff00a9026b0
                          (auVar16,param_2,uVar17,uVar19,param_5,param_6,(undefined **)*puVar1,
                           (undefined *)puVar1[1],puVar11,puVar12,param_11);
      *puVar1 = 0;
      puVar1[1] = 0;
    }
    if (param_9 == (ulong *)0x0) {
      uVar15 = 0;
    }
    else {
      auVar6._4_12_ = auVar18;
      auVar6._0_4_ = uVar17;
      auVar10._4_12_ = auVar20;
      auVar10._0_4_ = uVar19;
      thunk_FUN_fffffff00a902580(auVar16,param_2,auVar6,auVar10,param_5,param_6,param_9);
      *puVar1 = extraout_x0;
      if (extraout_x0 == (undefined8 *)0x0) {
        uVar15 = 0xe00002bd;
      }
      else {
        puVar1[1] = param_9;
        thunk_FUN_fffffff00aa65b10(extraout_x0,param_10,(ulong)param_9);
        uVar15 = 0;
        *(byte *)(*(long *)(param_7 + 0x178) + 0x2f) =
             *(byte *)(*(long *)(param_7 + 0x178) + 0x2f) |
             (byte)(1 << (ulong)((uint)param_8 & 0x1f));
      }
    }
    thunk_FUN_fffffff00a226de0(*(ulong *)(param_7 + 0x50));
  }
  return uVar15;
}

