// FUN_fffffff0081901b0 @ fffffff0081901b0 size=1728

void FUN_fffffff0081901b0(long param_1,ulong param_2,ulong param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  ushort uVar7;
  undefined1 uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  long *plVar13;
  uint uVar14;
  ulong uVar15;
  undefined8 *puVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  undefined *local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  ulong local_e0;
  ulong uStack_d8;
  ulong local_d0;
  undefined *local_c8;
  undefined8 local_c0;
  ulong local_b8;
  undefined4 local_b0;
  undefined8 uStack_ac;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined4 local_70;
  undefined4 local_6c [3];
  
  uStack_d8 = param_3;
  local_d0 = param_2;
  if (param_3 < param_2) {
    uStack_d8 = 0;
    local_d0 = 0;
  }
  local_f8 = &DAT_fffffff007c9c650;
  local_e8 = 0;
  local_f0 = 0;
  local_e0 = local_d0;
  uVar10 = FUN_fffffff0081e15ac(&local_f8,&local_f8,&local_e0);
  if ((uVar10 & 1) == 0) {
    local_a4 = local_f0._4_4_;
    goto LAB_fffffff008190754;
  }
  if ((local_f0 & 1) == 0) goto LAB_fffffff008190828;
  if ((int)local_e8 < 0xb) {
    if ((int)local_e8 != 3) {
      if ((((int)local_e8 == 4) && ((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a71) & 1) != 0)) &&
         ((*(byte *)(param_1 + 0x7f7) & 1) != 0)) {
        local_b0 = 0x7c9f0f0;
        uStack_ac._0_4_ = 0xfffffff0;
        uStack_ac._4_4_ = 0;
        local_a0 = 0;
        uStack_98 = 0;
        local_a4 = 0;
        iVar9 = FUN_fffffff0082022bc(&local_b0,&local_b0,&local_e0);
        if (iVar9 == 0) goto LAB_fffffff008190754;
        if ((uStack_ac._4_4_ & 1) == 0) goto LAB_fffffff008190828;
        if (local_a0._4_4_ == -1) {
          uVar14 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c) * 1000 - 1000;
          if (3999 < uVar14) {
            uVar14 = 4000;
          }
        }
        else {
          uVar14 = local_a0._4_4_ * 1000;
          uVar6 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c) * 1000 - 1000;
          if (3999 < uVar6) {
            uVar6 = 4000;
          }
          if (uVar6 < uVar14) goto LAB_fffffff0081907b4;
        }
        FUN_fffffff008190870(param_1,local_a0 & 0xffffffff,uStack_98,uVar14,0);
        return;
      }
      goto LAB_fffffff0081907b4;
    }
  }
  else if ((int)local_e8 != 0xb) {
    if ((int)local_e8 == 0x10004) {
      local_b0 = 0x7c9f0f0;
      uStack_ac._0_4_ = 0xfffffff0;
      uStack_ac._4_4_ = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_a4 = 0;
      iVar9 = FUN_fffffff0082022bc(&local_b0,&local_b0,&local_e0);
      if (iVar9 == 0) goto LAB_fffffff008190754;
      if ((uStack_ac._4_4_ & 1) != 0) {
        plVar13 = (long *)thunk_EXT_FUN_8011000002961cc4
                                    (*(undefined8 *)(param_1 + 0x488),local_a0 & 0xffffffff);
        if (plVar13 == (long *)0x0) {
          local_a4 = 10;
          goto LAB_fffffff008190754;
        }
        (**(code **)(*plVar13 + 0x20))();
        (**(code **)(*plVar13 + 0x28))(plVar13);
        if ((uStack_ac._4_4_ & 1) != 0) {
          uVar14 = *(int *)(*(long *)(param_1 + 0x530) + 0x23c) * 1000 - 1000;
          if (3999 < uVar14) {
            uVar14 = 4000;
          }
          FUN_fffffff00818b3a0(param_1,plVar13,uStack_98,uVar14,0,0);
          (**(code **)(*plVar13 + 0x28))(plVar13);
          return;
        }
      }
      goto LAB_fffffff008190828;
    }
    if ((int)local_e8 != 0x10002) goto LAB_fffffff0081907b4;
    local_c0 = 0;
    local_c8 = &DAT_fffffff007c94d28;
    local_b8 = 0x100;
    iVar9 = FUN_fffffff00819fbc4(&local_c8,&local_e0);
    if (iVar9 != 0) {
      if ((local_c0 & 1) != 0) {
        lVar19 = *(long *)(param_1 + 0x488);
        if (*(long *)(lVar19 + 0x178) == 0) {
          return;
        }
        lVar20 = *(long *)(lVar19 + 0x48);
        if (*(int *)(lVar20 + 0x10934) == 0) {
          return;
        }
        uVar7 = (ushort)local_b8;
        uVar10 = local_b8 & 0xffff;
        pbVar1 = (byte *)(*(long *)(lVar19 + 0x178) + uVar10 * 2);
        if ((pbVar1[1] & 1) == 0) {
          return;
        }
        bVar5 = *pbVar1;
        uVar17 = (ulong)bVar5;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar20 + 0x11f30));
        iVar9 = *(int *)(lVar20 + 0x17fb0) + 0x100;
        *(int *)(lVar20 + 0x17fb0) = iVar9;
        puVar2 = (undefined4 *)(lVar20 + 0x11f70 + uVar17 * 0x60);
        puVar2[0x12] = iVar9;
        lVar18 = *(long *)(lVar20 + 0x11f38);
        lVar11 = (**(code **)(**(long **)(*(long *)(lVar18 + 0x183b8) + 0x50) + 0x98))();
        uVar14 = *(uint *)(lVar18 + 0x4a8);
        uVar3 = puVar2[0x12];
        uVar4 = *puVar2;
        lVar18 = *(long *)(lVar20 + 0x11f38);
        if ((*(byte *)(lVar18 + 0x1ac44) >> 3 & 1) != 0) {
          thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar18 + 0x1ac48));
          thunk_EXT_FUN_80110000036da494(0x85930c9c,uVar17,uVar3,uVar4,0,0);
          thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar18 + 0x1ac48));
        }
        uVar15 = (ulong)(bVar5 >> 3) & 0x18;
        *(ulong *)(lVar20 + 0x17f90 + uVar15) =
             *(ulong *)(lVar20 + 0x17f90 + uVar15) | 1L << (uVar17 & 0x3f);
        *puVar2 = 0;
        *(undefined8 *)(puVar2 + 0x14) = 0;
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar20 + 0x11f30));
        if ((uVar7 < 0x100) && (*(int *)(*(long *)(lVar19 + 0x48) + 0x10934) != 0)) {
          *(undefined2 *)(*(long *)(lVar19 + 0x178) + uVar10 * 2) = 0;
        }
        uStack_88 = 0;
        local_90 = 0;
        uStack_78 = 0;
        uStack_80 = 0;
        uStack_98 = 0;
        local_b0 = 0xe;
        local_a0 = (ulong)CONCAT14(bVar5,uVar4);
        lVar19 = *(long *)(*(long *)(param_1 + 0x530) + 0x4b0);
        local_6c[0] = 4;
        if ((*(byte *)(*(long *)(param_1 + 0x530) + 0x57a) & 1) != 0) {
          local_6c[0] = 1;
        }
        local_a4 = uVar3;
        uStack_ac = lVar11 + uVar17 * 4 + (ulong)uVar14;
        uVar12 = (**(code **)(*(long *)(lVar19 + 0x848) + 0x30))(lVar19 + 0x848);
        local_70 = 0;
        plVar13 = *(long **)(*(long *)(lVar19 + 0x280) + 0x310);
        puVar16 = (undefined8 *)(*plVar13 + 0xe8);
        iVar9 = (*(code *)*puVar16)(puVar16,plVar13,FUN_fffffff00817ea94,&local_b0,local_6c,
                                    &local_70,0);
        lVar20 = uStack_ac;
        if ((iVar9 == 0) && (((byte)local_6c[0] >> 1 & 1) != 0)) {
          FUN_fffffff0081a43cc(lVar19,uVar12,local_70);
          lVar20 = uStack_ac;
        }
        uVar3 = local_a4;
        lVar19 = *(long *)(param_1 + 0x530);
        if ((*(byte *)(lVar19 + 0x1ac44) >> 3 & 1) == 0) {
          return;
        }
        uVar8 = local_a0._4_1_;
        uVar10 = local_a0 & 0xffffffff;
        uStack_ac = lVar20;
        thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar19 + 0x1ac48));
        thunk_EXT_FUN_80110000036da494(0x85930cd4,uVar8,uVar10,lVar20,uVar3,0);
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar19 + 0x1ac48));
        return;
      }
      goto LAB_fffffff008190828;
    }
    local_a4 = local_c0._4_4_;
    goto LAB_fffffff008190754;
  }
  if (((*(byte *)(*(long *)(param_1 + 0x530) + 0x10a71) & 1) != 0) &&
     (uVar10 = thunk_EXT_FUN_80110000029479f8
                         (*(undefined8 *)(*(long *)(param_1 + 0x530) + 0x148),param_1 + 0x498),
     (uVar10 & 1) == 0)) {
    if ((local_f0 & 1) == 0) {
LAB_fffffff008190828:
      thunk_EXT_FUN_8011000003a49114
                ("AGXk: %s:%d:%s: !!! Assertion failed: %s: stream validator is invalid!\n");
      return;
    }
    if ((int)local_e8 == 3) {
      local_b0 = 0x7c9f0f0;
      uStack_ac._0_4_ = 0xfffffff0;
      uStack_ac._4_4_ = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_a4 = 0;
      iVar9 = FUN_fffffff0082022bc(&local_b0,&local_b0,&local_e0);
      if (iVar9 == 0) {
LAB_fffffff008190754:
        *(undefined4 *)(param_1 + 0x520) = local_a4;
        return;
      }
      if ((uStack_ac._4_4_ & 1) == 0) goto LAB_fffffff008190828;
      uVar12 = 0;
    }
    else {
      local_b0 = 0x7c9f110;
      uStack_ac._0_4_ = 0xfffffff0;
      uStack_ac._4_4_ = 0;
      local_a4 = 0;
      uStack_98 = 0;
      local_90 = 0;
      local_a0 = 0;
      iVar9 = FUN_fffffff008202310(&local_b0,&local_b0,&local_e0);
      if (iVar9 == 0) goto LAB_fffffff008190754;
      if ((uStack_ac._4_4_ & 1) == 0) goto LAB_fffffff008190828;
      uVar12 = local_90;
    }
    uVar10 = FUN_fffffff0081909e8(param_1,(undefined4)local_a0,uStack_98,uVar12,0);
    if ((uVar10 & 1) != 0) {
      return;
    }
  }
LAB_fffffff0081907b4:
  (**(code **)(PTR_DAT_fffffff007ca6130 + 0xe0))(param_1,param_2,param_3);
  return;
}

