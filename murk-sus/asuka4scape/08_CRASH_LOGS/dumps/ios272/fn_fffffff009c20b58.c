// FUN_fffffff009c20b58 @ fffffff009c20b58 size=940

/* WARNING: Removing unreachable block (ram,0xfffffff009c20d14) */

void FUN_fffffff009c20b58(long param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  undefined1 *puVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  ulong uVar13;
  undefined1 **ppuVar14;
  uint uVar15;
  long *plVar16;
  undefined1 *local_170 [5];
  undefined1 *puStack_148;
  undefined1 *puStack_140;
  undefined1 *puStack_138;
  undefined1 *local_130;
  undefined1 *puStack_128;
  undefined1 *puStack_120;
  undefined1 *puStack_118;
  undefined1 *local_110;
  undefined1 *puStack_108;
  undefined1 *puStack_100;
  undefined1 *puStack_f8;
  undefined1 *local_f0;
  undefined1 *puStack_e8;
  undefined1 *puStack_e0;
  undefined1 *puStack_d8;
  undefined1 *local_d0;
  undefined1 *puStack_c8;
  undefined1 *puStack_c0;
  undefined1 *puStack_b8;
  undefined1 *local_b0;
  undefined1 *puStack_a8;
  undefined1 *puStack_a0;
  undefined1 *puStack_98;
  undefined1 *local_90;
  undefined1 *puStack_88;
  undefined1 *puStack_80;
  undefined1 *local_78;
  long local_70 [2];
  
  lVar4 = 0;
  local_70[0] = *(long *)PTR_DAT_fffffff00806ca40;
  puStack_88 = &DAT_aaaaaaaaaaaaaaaa;
  local_90 = &DAT_aaaaaaaaaaaaaaaa;
  local_78 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_80 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a8 = &DAT_aaaaaaaaaaaaaaaa;
  local_b0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_98 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_a0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_c8 = &DAT_aaaaaaaaaaaaaaaa;
  local_d0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_b8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_c0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_e8 = &DAT_aaaaaaaaaaaaaaaa;
  local_f0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_d8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_e0 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_108 = &DAT_aaaaaaaaaaaaaaaa;
  local_110 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_f8 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_100 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_128 = &DAT_aaaaaaaaaaaaaaaa;
  local_130 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_118 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_120 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_148 = &DAT_aaaaaaaaaaaaaaaa;
  local_170[4] = &DAT_aaaaaaaaaaaaaaaa;
  puStack_138 = &DAT_aaaaaaaaaaaaaaaa;
  puStack_140 = &DAT_aaaaaaaaaaaaaaaa;
  lVar6 = 0x20;
  local_170[1] = &DAT_aaaaaaaaaaaaaaaa;
  local_170[0] = &DAT_aaaaaaaaaaaaaaaa;
  local_170[3] = &DAT_aaaaaaaaaaaaaaaa;
  local_170[2] = &DAT_aaaaaaaaaaaaaaaa;
  do {
    local_170[lVar4] = (undefined1 *)0x0;
    local_170[lVar4 + 1] = (undefined1 *)0x0;
    lVar4 = lVar4 + 2;
    lVar6 = lVar6 + -2;
  } while (lVar6 != 0);
  if (*(int *)(param_1 + 0x220) != 0) {
    iVar1 = *(int *)(param_1 + 0x224) + 1;
    do {
      *(int *)(param_1 + 0x224) = iVar1;
      thunk_EXT_FUN_80110000038ff064(*(undefined8 *)(param_1 + 0x50),param_1,0);
      iVar1 = *(int *)(param_1 + 0x224);
      *(int *)(param_1 + 0x224) = iVar1 + -1;
    } while (*(int *)(param_1 + 0x220) != 0);
  }
  plVar16 = *(long **)(param_1 + 0x38);
  if ((plVar16 == (long *)0x0) ||
     (((int)plVar16[9] == param_2 && (*(int *)((long)plVar16 + 0x54) == param_3)))) {
    if ((param_4 != 0) && (uVar13 = *(ulong *)(param_1 + 0x40), uVar13 != 0)) {
      lVar6 = 0;
      lVar4 = 0;
      uVar3 = 0xffffffff;
      uVar7 = uVar13;
      do {
        uVar7 = *(ulong *)(uVar7 + 0x30);
        uVar3 = uVar3 + 1;
        lVar4 = lVar4 + 1;
        lVar6 = lVar6 + 8;
      } while (uVar7 != 0);
      if (uVar3 < 0x20) {
        puVar12 = (undefined1 *)0x0;
        lVar4 = 0x20;
        ppuVar14 = local_170;
LAB_fffffff009c20d58:
        puVar5 = (undefined1 *)((long)ppuVar14 + lVar4 * 8);
        if ((((ulong)ppuVar14 ^ (ulong)puVar5) & 0xffc0000000000000) != 0) {
          puVar5 = (undefined1 *)((ulong)puVar5 & 0xffffffffffff | 0xc8a2000000000000);
        }
        if ((puVar5 < ppuVar14) || ((ulong)((long)puVar5 - (long)ppuVar14) >> 0x20 != 0)) {
          FUN_fffffff009c48f64();
          goto LAB_fffffff009c20f00;
        }
        uVar7 = 0;
        uVar9 = 1;
        do {
          uVar8 = uVar9;
          if ((uVar7 & 0x1fffffff) >> 0x1c != 0) {
LAB_fffffff009c20ee8:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          uVar3 = (int)uVar7 * 8;
          uVar15 = (uint)((long)puVar5 - (long)ppuVar14);
          if (uVar15 < uVar3 + 8) goto LAB_fffffff009c20ee8;
          uVar9 = (ulong)CARRY8((ulong)ppuVar14,(ulong)uVar3);
          uVar7 = -uVar9;
          if ((uVar7 != uVar9) || ((long)uVar7 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50((undefined1 *)((long)ppuVar14 + (ulong)uVar3));
          }
          FUN_fffffff009c16670((undefined1 *)((long)ppuVar14 + (ulong)uVar3),uVar13);
          uVar13 = *(ulong *)(uVar13 + 0x30);
          if (uVar13 == 0) goto LAB_fffffff009c20ddc;
          uVar7 = uVar8;
          uVar9 = uVar8 + 1;
        } while (uVar8 != 0x10000000);
        FUN_fffffff009c48f3c();
LAB_fffffff009c20ddc:
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
        lVar4 = 0x10000000;
        uVar7 = uVar8;
        do {
          if (lVar4 == 0) {
            FUN_fffffff009c48f3c();
LAB_fffffff009c20ef4:
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f28();
          }
          if (((long)uVar13 < 0) || (uVar15 < (int)(uVar13 >> 0x20) + 8U))
          goto LAB_fffffff009c20ef4;
          puVar11 = (undefined8 *)((long)ppuVar14 + (uVar13 >> 0x20));
          uVar10 = (ulong)CARRY8((ulong)ppuVar14,uVar13 >> 0x20);
          uVar9 = -uVar10;
          if ((uVar9 != uVar10) || ((long)uVar9 < 0)) {
                    /* WARNING: Subroutine does not return */
            FUN_fffffff009c48f50();
          }
          FUN_fffffff009c2d99c(*puVar11);
          uVar2 = *puVar11;
          *puVar11 = 0;
          FUN_fffffff009c2da10(uVar2);
          lVar4 = lVar4 + -1;
          uVar13 = uVar13 + 0x800000000;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
        lVar4 = (uVar8 & 0xffffffff) << 3;
      }
      else {
        puVar12 = (undefined1 *)thunk_EXT_FUN_80110000038fe750(&DAT_fffffff00806bd40,lVar6);
        uVar13 = *(ulong *)(param_1 + 0x40);
        ppuVar14 = (undefined1 **)puVar12;
        if (uVar13 != 0) goto LAB_fffffff009c20d58;
        thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
        lVar4 = 0;
      }
      thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
      if (puVar12 != (undefined1 *)0x0) {
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff00806bd90,puVar12,lVar4);
      }
    }
  }
  else {
    (**(code **)(*plVar16 + 0x20))(plVar16);
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + 1;
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x50));
    FUN_fffffff009c2d964(plVar16);
    FUN_fffffff009c2d9d4(plVar16,param_4 ^ 1);
    FUN_fffffff009c2da10(plVar16);
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x50));
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + -1;
    if (*(long *)(param_1 + 0x38) == 0) {
      puVar11 = *(undefined8 **)(param_1 + 0x178);
      *(undefined2 *)(puVar11 + 1) = 0;
      *puVar11 = 0;
    }
    if (*(int *)(param_1 + 0x224) != 0) {
      thunk_EXT_FUN_80110000038ff08c(*(undefined8 *)(param_1 + 0x50),param_1,0);
    }
  }
  plVar16 = local_70;
  do {
    plVar16 = plVar16 + -1;
    if ((long *)*plVar16 != (long *)0x0) {
      (**(code **)(*(long *)*plVar16 + 0x28))();
    }
    *plVar16 = 0;
  } while ((undefined1 **)plVar16 != local_170);
  if (*(long *)PTR_DAT_fffffff00806ca40 == local_70[0]) {
    return;
  }
LAB_fffffff009c20f00:
  thunk_EXT_FUN_8011000003a48590();
  return;
}

