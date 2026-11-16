// FUN_fffffff009c8c3a8 @ fffffff009c8c3a8

/* WARNING: Removing unreachable block (ram,0xfffffff009c8c71c) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c8c4b0) */

undefined8
FUN_fffffff009c8c3a8
          (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
          undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
          undefined8 param_8,long param_9,long param_10,undefined *param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  bool bVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  undefined8 uVar9;
  undefined **ppuVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined8 *puVar15;
  long lVar16;
  uint uVar17;
  undefined *puVar18;
  long lVar19;
  undefined8 extraout_d0;
  undefined8 uVar20;
  undefined8 extraout_var;
  undefined1 auVar21 [16];
  undefined8 uVar22;
  undefined8 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined8 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined8 uVar29;
  long *local_78;
  code *pcStack_70;
  undefined8 *local_68;
  
  uVar23 = param_2._8_8_;
  uVar22 = param_2._0_8_;
  uVar27 = param_4._0_4_;
  uVar28 = param_4._4_4_;
  uVar20 = param_4._8_8_;
  uVar24 = param_3._0_4_;
  uVar25 = param_3._4_4_;
  uVar26 = param_3._8_8_;
  uVar13 = 0xe00002c2;
  if (*(long *)(param_9 + 8) == 0) {
    return 0xe00002c7;
  }
  if (param_7 == (long *)0x0) {
    return 0xe00002c2;
  }
  if (*(uint *)(param_9 + 0x28) < 5) {
    return 0xe00002c2;
  }
  lVar16 = param_7[0x1e];
  if (lVar16 == 0) {
    return 0xe00002cd;
  }
  local_78 = (long *)&DAT_aaaaaaaaaaaaaaaa;
  pcStack_70 = (code *)&DAT_aaaaaaaaaaaaaaaa;
  local_68 = (undefined8 *)&DAT_aaaaaaaaaaaaaaaa;
  uVar14 = **(ulong **)(param_9 + 0x20);
  if (uVar14 >> 0x20 != 0) {
    return 0xe00002c2;
  }
  thunk_FUN_fffffff00a2262a8(param_7[0x20]);
  plVar6 = (long *)(**(code **)(*(long *)param_7[0x1f] + 0x118))((long *)param_7[0x1f],uVar14);
  plVar6 = thunk_FUN_fffffff00a894f30(plVar6,(long)PTR_DAT_fffffff00807c5a8);
  if (plVar6 == (long *)0x0) {
    thunk_FUN_fffffff00a226de0(param_7[0x20]);
    return 0xe00002c2;
  }
  (**(code **)(*plVar6 + 0x20))();
  thunk_FUN_fffffff00a226de0(param_7[0x20]);
  plVar7 = (long *)(**(code **)(*param_7 + 0x6a0))
                             (*param_7 + 0x6a0,param_7,
                              *(undefined8 *)(*(long *)(param_9 + 0x20) + 8));
  if (plVar7 == (long *)0x0) {
    bVar5 = false;
    plVar7 = (long *)0x0;
    plVar8 = (long *)0x0;
    puVar15 = (undefined8 *)0x0;
  }
  else {
    plVar8 = (long *)(**(code **)(*plVar7 + 0x98))(plVar7);
    if (plVar8 == (long *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
      puVar15 = (undefined8 *)0x0;
      bVar5 = false;
      plVar7 = (long *)0x0;
      uVar13 = 0xe00002bd;
    }
    else {
      (**(code **)(*plVar8 + 0x20))(plVar8);
      (**(code **)(*plVar7 + 0x28))(plVar7);
      bVar5 = false;
      puVar15 = (undefined8 *)0x0;
      lVar11 = *(long *)(param_9 + 0x20);
      puVar18 = *(undefined **)(lVar11 + 0x18);
      uVar17 = (uint)puVar18;
      if ((uVar17 < 0x41) && (*(ulong *)(lVar11 + 0x10) < 0x4001)) {
        lVar19 = *(long *)(lVar11 + 0x20);
        plVar7 = thunk_FUN_fffffff00a97ae84
                           (lVar19 + *(ulong *)(lVar11 + 0x10) * 0x18,(ulong)(uVar17 * 0x18),3,
                            lVar16);
        uVar13 = 0xe00002bd;
        if (plVar7 == (long *)0x0) {
          puVar15 = (undefined8 *)0x0;
          bVar5 = false;
          param_10 = lVar16;
        }
        else {
          uVar9 = (**(code **)(*plVar7 + 0xd8))(plVar7,0);
          if ((int)uVar9 == 0) {
            puVar15 = (undefined8 *)thunk_FUN_fffffff00a902074((long *)&DAT_fffffff00807f0b8);
            puVar15[8] = plVar8;
            puVar15[9] = plVar7;
            puVar15[10] = lVar19;
            *(uint *)(puVar15 + 0xb) = uVar17;
            puVar15[0xc] = plVar6;
            auVar21._8_8_ = extraout_var;
            auVar21._0_8_ = extraout_d0;
            auVar1._8_8_ = uVar23;
            auVar1._0_8_ = uVar22;
            auVar3._4_4_ = uVar25;
            auVar3._0_4_ = uVar24;
            auVar3._8_8_ = uVar26;
            auVar4._4_4_ = uVar28;
            auVar4._0_4_ = uVar27;
            auVar4._8_8_ = uVar20;
            auVar21 = thunk_FUN_fffffff00a902750
                                (auVar21,auVar1,auVar3,auVar4,param_5,param_6,0xfffffff00807f538,
                                 (ulong *)(((ulong)puVar18 & 0x7f) * 0x18));
            lVar11 = auVar21._0_8_;
            puVar15[0xd] = lVar11;
            if (lVar11 != 0) {
              puVar12 = *(undefined8 **)(param_9 + 0x10);
              if (puVar12 != (undefined8 *)0x0) {
                uVar9 = puVar12[1];
                uVar20 = *puVar12;
                uVar23 = puVar12[3];
                uVar22 = puVar12[2];
                uVar13 = puVar12[4];
                uVar24 = (undefined4)uVar13;
                uVar29 = puVar12[7];
                uVar26 = puVar12[6];
                uVar27 = (undefined4)uVar26;
                puVar15[5] = puVar12[5];
                puVar15[4] = uVar13;
                puVar15[7] = uVar29;
                puVar15[6] = uVar26;
                puVar15[1] = uVar9;
                *puVar15 = uVar20;
                puVar15[3] = uVar23;
                puVar15[2] = uVar22;
              }
              (**(code **)(*plVar7 + 200))(plVar7,0,lVar11,(ulong)(uVar17 * 0x18));
              pcStack_70 = FUN_fffffff009c8f330;
              lVar16 = 0;
              local_78 = param_7;
              local_68 = puVar15;
              uVar13 = (**(code **)(*param_7 + 0x650))
                                 (*param_7 + 0x650,param_7,plVar6,plVar8,0,puVar18,puVar15[0xd],
                                  &local_78);
              param_11 = puVar18;
              if ((int)uVar13 == 0) {
                return uVar13;
              }
            }
            bVar5 = true;
            param_10 = lVar16;
          }
          else {
            puVar15 = (undefined8 *)0x0;
            bVar5 = false;
            param_10 = lVar16;
            uVar13 = uVar9;
          }
        }
      }
      else {
        plVar7 = (long *)0x0;
      }
    }
  }
  auVar21 = (**(code **)(*plVar6 + 0x28))(plVar6);
  if (plVar8 == (long *)0x0) {
    if (bVar5) goto LAB_fffffff009c8c7a0;
LAB_fffffff009c8c7d4:
    if (plVar7 == (long *)0x0) goto LAB_fffffff009c8c7f8;
  }
  else {
    auVar21 = (**(code **)(*plVar8 + 0x28))(plVar8);
    if (!bVar5) goto LAB_fffffff009c8c7d4;
LAB_fffffff009c8c7a0:
    (**(code **)(*plVar7 + 0xe0))(plVar7,0);
  }
  auVar21 = (**(code **)(*plVar7 + 0x28))(plVar7);
LAB_fffffff009c8c7f8:
  if (puVar15 != (undefined8 *)0x0) {
    ppuVar10 = (undefined **)puVar15[0xd];
    if (ppuVar10 != (undefined **)0x0) {
      puVar15[0xd] = 0;
      auVar2._8_8_ = uVar23;
      auVar2._0_8_ = uVar22;
      thunk_FUN_fffffff00a902768
                (auVar21,auVar2,uVar24,uVar27,param_5,param_6,0xfffffff00807f588,ppuVar10,
                 (undefined *)((ulong)*(uint *)(puVar15 + 0xb) * 0x18),param_10,param_11);
      puVar15[0xd] = 0;
    }
    thunk_FUN_fffffff00a22170c((long *)&DAT_fffffff00807f0f8,puVar15);
  }
  return uVar13;
}

