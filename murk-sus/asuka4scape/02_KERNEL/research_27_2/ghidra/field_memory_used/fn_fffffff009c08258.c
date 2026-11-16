// FUN_fffffff009c08258 @ fffffff009c08258

/* WARNING: Removing unreachable block (ram,0xfffffff009c08588) */
/* WARNING: Removing unreachable block (ram,0xfffffff009c0864c) */

ulong FUN_fffffff009c08258
                (undefined1 param_1 [16],undefined1 param_2 [16],undefined1 param_3 [16],
                undefined1 param_4 [16],undefined4 param_5,undefined4 param_6,long *param_7,
                long *param_8,ulong param_9,undefined8 param_10,ulong param_11)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined *puVar16;
  uint uVar17;
  undefined4 uVar18;
  int iVar19;
  long lVar21;
  long lVar22;
  undefined **extraout_x0;
  long *plVar23;
  byte *pbVar24;
  byte *pbVar25;
  undefined8 uVar26;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  ulong uVar27;
  ushort uVar28;
  uint uVar29;
  uint uVar30;
  ulong uVar31;
  ulong uVar32;
  uint uVar33;
  undefined4 **ppuVar34;
  long lVar35;
  long lVar36;
  undefined8 extraout_d0;
  undefined8 extraout_d0_00;
  undefined8 extraout_d0_01;
  undefined8 extraout_d0_02;
  undefined8 extraout_d0_03;
  undefined8 extraout_d0_04;
  undefined8 extraout_d0_05;
  undefined8 uVar37;
  undefined8 extraout_var;
  undefined8 extraout_var_00;
  undefined8 extraout_var_01;
  undefined8 extraout_var_02;
  undefined8 extraout_var_03;
  undefined8 extraout_var_04;
  undefined8 extraout_var_05;
  undefined8 uVar38;
  undefined4 uVar39;
  undefined1 auVar40 [12];
  undefined4 uVar41;
  undefined1 auVar42 [12];
  undefined1 auVar43 [16];
  undefined8 local_78;
  uint local_70;
  long local_68;
  undefined8 *puVar20;
  
  iVar19 = DAT_fffffff00af47e00;
  uVar41 = param_4._0_4_;
  auVar42 = param_4._4_12_;
  uVar39 = param_3._0_4_;
  auVar40 = param_3._4_12_;
  local_68 = *(long *)PTR_DAT_fffffff008064be8;
  if (*param_7 != 0) {
    uVar33 = *(uint *)(param_7 + 1);
    uVar32 = (ulong)uVar33;
    if (uVar33 == 0) {
      uVar31 = 0;
LAB_fffffff009c082f4:
      uVar32 = uVar31;
      if ((uint)uVar32 == uVar33) goto LAB_fffffff009c082fc;
LAB_fffffff009c0833c:
      lVar21 = thunk_FUN_fffffff00a1d1550(0xfffffff0078994d4);
      uVar33 = (uint)param_9;
      if (9 < uVar33) {
        do {
          lVar21 = lVar21 + 1;
          uVar29 = (uint)param_9;
          param_9 = (param_9 & 0xffffffff) / 10;
        } while (99 < uVar29);
      }
      lVar22 = thunk_FUN_fffffff00a1d1550(param_11);
      lVar21 = lVar21 + lVar22;
      auVar43._8_8_ = extraout_var;
      auVar43._0_8_ = extraout_d0;
      auVar6._4_12_ = auVar40;
      auVar6._0_4_ = uVar39;
      auVar11._4_12_ = auVar42;
      auVar11._0_4_ = uVar41;
      thunk_FUN_fffffff00a902580
                (auVar43,param_2,auVar6,auVar11,param_5,param_6,(ulong *)(lVar21 + 1));
      puVar16 = PTR_DAT_fffffff008064c08;
      lVar22 = 0;
      local_70 = 0x1a0;
      local_78 = 0x500000000;
      lVar35 = *(long *)PTR_PTR_fffffff008064ba0;
      lVar36 = 3;
      do {
        plVar23 = (long *)(**(code **)(*param_8 + 0x130))
                                    (param_8,(&PTR_s_owner_uid_fffffff008063048)[lVar22],
                                     *(undefined8 *)puVar16,3);
        plVar23 = thunk_FUN_fffffff00a894f30(plVar23,lVar35);
        uVar26 = extraout_d0_00;
        uVar37 = extraout_var_00;
        if (plVar23 != (long *)0x0) {
          uVar18 = (**(code **)(*plVar23 + 0xa8))();
          *(undefined4 *)((long)&local_78 + lVar22 * 4) = uVar18;
          uVar26 = extraout_d0_01;
          uVar37 = extraout_var_01;
        }
        lVar22 = lVar22 + 1;
        lVar36 = lVar36 + -1;
      } while (lVar36 != 0);
      uVar30 = (uint)uVar32;
      uVar29 = uVar30 | iVar19 << 0x18;
      uVar18 = (undefined4)local_78;
      uVar31 = local_78 & 0xffffffff;
      uVar17 = local_78._4_4_;
      uVar27 = (ulong)local_78._4_4_;
      ppuVar34 = (undefined4 **)(ulong)local_70;
      uVar28 = (ushort)local_70;
      auVar1._8_8_ = uVar37;
      auVar1._0_8_ = uVar26;
      auVar7._4_12_ = auVar40;
      auVar7._0_4_ = uVar39;
      auVar12._4_12_ = auVar42;
      auVar12._0_4_ = uVar41;
      pbVar24 = thunk_FUN_fffffff00a432290
                          (auVar1,param_2,auVar7,auVar12,param_5,param_6,uVar29,1,
                           (undefined4)local_78,local_78._4_4_,uVar28,(byte *)"disk%d%s");
      auVar2._8_8_ = extraout_var_02;
      auVar2._0_8_ = extraout_d0_02;
      auVar8._4_12_ = auVar40;
      auVar8._0_4_ = uVar39;
      auVar13._4_12_ = auVar42;
      auVar13._0_4_ = uVar41;
      pbVar25 = thunk_FUN_fffffff00a432290
                          (auVar2,param_2,auVar8,auVar13,param_5,param_6,uVar29,0,uVar18,uVar17,
                           uVar28,(byte *)"rdisk%d%s");
      if (((extraout_x0 != (undefined **)0x0) && (pbVar24 != (byte *)0x0)) &&
         (pbVar25 != (byte *)0x0)) {
        thunk_FUN_fffffff00a76d3ec((undefined1 *)extraout_x0,lVar21 + 1,(byte *)"disk%d%s");
        uVar29 = uVar30 >> 6;
        uVar31 = (ulong)(uVar30 & 0x3f);
        puVar20 = (undefined8 *)(*(long *)(*param_7 + (ulong)uVar29 * 8) + uVar31 * 0x50);
        lVar22 = uVar31 * 0x50;
        puVar20[7] = 0;
        puVar20[6] = 0;
        puVar20[9] = 0;
        puVar20[8] = 0;
        puVar20[3] = 0;
        puVar20[2] = 0;
        puVar20[5] = 0;
        puVar20[4] = 0;
        puVar20[1] = 0;
        *puVar20 = 0;
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8);
        *(byte *)(lVar21 + lVar22) = *(byte *)(lVar21 + lVar22) | 1;
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8);
        *(byte *)(lVar21 + lVar22) = *(byte *)(lVar21 + lVar22) & 0xfd;
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8);
        *(byte *)(lVar21 + lVar22) = *(byte *)(lVar21 + lVar22) & 0xfb;
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8) + uVar31 * 0x50;
        *(uint *)(lVar21 + 4) = uVar33;
        *(undefined8 *)(lVar21 + 8) = param_10;
        *(long **)(lVar21 + 0x10) = param_8;
        *(undefined ***)(lVar21 + 0x18) = extraout_x0;
        uVar26 = (**(code **)(*param_8 + 0x5a0))(*param_8 + 0x5a0,param_8);
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8) + uVar31 * 0x50;
        *(undefined8 *)(lVar21 + 0x20) = uVar26;
        *(byte **)(lVar21 + 0x28) = pbVar24;
        *(undefined8 *)(lVar21 + 0x30) = 0;
        *(byte **)(lVar21 + 0x38) = pbVar25;
        *(undefined8 *)(lVar21 + 0x40) = 0;
        *(undefined2 *)(lVar21 + 0x48) = 0;
        (**(code **)(**(long **)(lVar21 + 8) + 0x20))();
        (**(code **)(**(long **)(*(long *)(*param_7 + (ulong)uVar29 * 8) + uVar31 * 0x50 + 0x10) +
                    0x20))();
        plVar23 = *(long **)(*(long *)(*param_7 + (ulong)uVar29 * 8) + uVar31 * 0x50 + 0x10);
        lVar21 = *plVar23;
        plVar23 = (long *)(**(code **)(lVar21 + 0x130))
                                    (lVar21 + 0x130,plVar23,"Protocol Characteristics",
                                     *(undefined8 *)puVar16,3);
        plVar23 = thunk_FUN_fffffff00a894f30(plVar23,*(long *)PTR_PTR_fffffff008064b78);
        lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8);
        *(byte *)(lVar21 + lVar22) = *(byte *)(lVar21 + lVar22) & 0xf7;
        if (plVar23 != (long *)0x0) {
          plVar23 = (long *)(**(code **)(*plVar23 + 0x138))(plVar23,"Physical Interconnect");
          plVar23 = thunk_FUN_fffffff00a894f30(plVar23,*(long *)PTR_PTR_fffffff008064ba8);
          if ((plVar23 != (long *)0x0) &&
             (iVar19 = (**(code **)(*plVar23 + 0xb8))(plVar23,"Virtual Interface"), iVar19 != 0)) {
            lVar21 = *(long *)(*param_7 + (ulong)uVar29 * 8);
            *(byte *)(lVar21 + uVar31 * 0x50) = *(byte *)(lVar21 + uVar31 * 0x50) | 8;
          }
        }
        goto LAB_fffffff009c08754;
      }
      uVar26 = extraout_x1;
      uVar37 = extraout_d0_03;
      uVar38 = extraout_var_03;
      if (pbVar25 != (byte *)0x0) {
        auVar3._8_8_ = extraout_var_03;
        auVar3._0_8_ = extraout_d0_03;
        auVar9._4_12_ = auVar40;
        auVar9._0_4_ = uVar39;
        auVar14._4_12_ = auVar42;
        auVar14._0_4_ = uVar41;
        thunk_FUN_fffffff00a43087c
                  (auVar3,param_2,auVar9,auVar14,param_5,param_6,(long)pbVar25,extraout_x1,uVar31,
                   uVar27,ppuVar34);
        uVar26 = extraout_x1_00;
        uVar37 = extraout_d0_04;
        uVar38 = extraout_var_04;
      }
      if (pbVar24 != (byte *)0x0) {
        auVar4._8_8_ = uVar38;
        auVar4._0_8_ = uVar37;
        auVar10._4_12_ = auVar40;
        auVar10._0_4_ = uVar39;
        auVar15._4_12_ = auVar42;
        auVar15._0_4_ = uVar41;
        thunk_FUN_fffffff00a43087c
                  (auVar4,param_2,auVar10,auVar15,param_5,param_6,(long)pbVar24,uVar26,uVar31,uVar27
                   ,ppuVar34);
        uVar37 = extraout_d0_05;
        uVar38 = extraout_var_05;
      }
      if (extraout_x0 != (undefined **)0x0) {
        auVar5._8_8_ = uVar38;
        auVar5._0_8_ = uVar37;
        thunk_FUN_fffffff00a9026b0
                  (auVar5,param_2,uVar39,uVar41,param_5,param_6,extraout_x0,
                   (undefined *)(lVar21 + 1),uVar31,uVar27,(undefined *)ppuVar34);
      }
    }
    else {
      uVar31 = 0;
      do {
        if ((*(byte *)(*(long *)(*param_7 + (uVar31 >> 6) * 8) + (ulong)((uint)uVar31 & 0x3f) * 0x50
                      ) & 1) == 0) goto LAB_fffffff009c082f4;
        uVar29 = (uint)uVar31 + 1;
        uVar31 = (ulong)uVar29;
      } while (uVar33 != uVar29);
LAB_fffffff009c082fc:
      if (uVar33 >> 0x10 == 0) {
        auVar43 = thunk_FUN_fffffff00a902750
                            (param_1,param_2,param_3,param_4,param_5,param_6,0xfffffff0080646e8,
                             (ulong *)0x1400);
        puVar20 = auVar43._0_8_;
        *(undefined8 **)(*param_7 + ((ulong)(uVar33 >> 3) & 0x1ffffff8)) = puVar20;
        if (puVar20 != (undefined8 *)0x0) {
          thunk_FUN_fffffff00aa65cc0(puVar20,0x1400);
          *(int *)(param_7 + 1) = (int)param_7[1] + 0x40;
          goto LAB_fffffff009c0833c;
        }
      }
    }
  }
  uVar32 = 0xffffffff;
LAB_fffffff009c08754:
  if (*(long *)PTR_DAT_fffffff008064be8 != local_68) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_fffffff00aa4c590();
  }
  return uVar32;
}

