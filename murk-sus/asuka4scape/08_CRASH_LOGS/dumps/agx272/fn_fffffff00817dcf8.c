// FUN_fffffff00817dcf8 @ fffffff00817dcf8 size=752

bool FUN_fffffff00817dcf8(long param_1,ulong param_2,undefined8 param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined1 (*pauVar3) [16];
  undefined8 *puVar4;
  undefined8 *puVar5;
  long *plVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  long *plVar10;
  ulong uVar11;
  long *plVar12;
  undefined8 uVar13;
  int iVar14;
  ulong uVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  ulong uVar21;
  long lVar22;
  undefined1 auVar23 [16];
  
  lVar22 = (param_2 & 0xffffffff) * 0x438;
  lVar16 = lVar22 + 0x218;
  puVar2 = (uint *)(param_1 + 0x678 + (long)(int)lVar16);
  if (lVar16 != (int)lVar16) {
    puVar2 = (uint *)(param_1 + 0x678 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
  }
  uVar7 = puVar2[1];
  uVar21 = (ulong)uVar7;
  if (uVar7 == 0) {
    return false;
  }
  if (uVar7 == 1) {
    iVar14 = 1 << (ulong)(*(uint *)PTR_DAT_fffffff007ca5f88 & 0x1f);
    uVar21 = *(ulong *)(puVar2 + 2) & (long)-iVar14;
    plVar10 = (long *)thunk_EXT_FUN_8011000003976f54
                                (uVar21,((*(ulong *)(puVar2 + 2) + (ulong)puVar2[0x82] +
                                         (long)iVar14) - 1 & -(long)iVar14) - uVar21,*puVar2 & 2 | 1
                                );
    goto joined_r0xfffffff00817df08;
  }
  lVar16 = uVar21 * 0x10;
  uVar11 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ca2ac8,lVar16);
  if (uVar11 == 0) {
    return false;
  }
  puVar1 = puVar2 + 2;
  uVar15 = CONCAT44(0,puVar2[0x82]);
  if ((uVar7 < 10) ||
     (uVar11 < param_1 + lVar22 + uVar21 * 8 + 0x898 && puVar1 < (uint *)(uVar11 + lVar16))) {
    uVar17 = 0;
LAB_fffffff00817de8c:
    lVar22 = uVar21 - uVar17;
    do {
      iVar14 = (int)(uVar17 * 8);
      puVar4 = (undefined8 *)((long)puVar1 + (long)iVar14);
      if (uVar17 * 8 - (long)iVar14 != 0) {
        puVar4 = (undefined8 *)((ulong)(puVar1 + uVar17 * 2) & 0xffffffffffff | 0x2bad000000000000);
      }
      lVar19 = uVar17 * 0x10;
      puVar5 = (undefined8 *)(uVar11 + (long)(int)lVar19);
      if (lVar19 - (int)lVar19 != 0) {
        puVar5 = (undefined8 *)(uVar11 + lVar19 & 0xffffffffffff | 0x2bad000000000000);
      }
      *puVar5 = *puVar4;
      puVar5[1] = uVar15;
      uVar17 = uVar17 + 1;
      lVar22 = lVar22 + -1;
    } while (lVar22 != 0);
  }
  else {
    lVar22 = 0;
    uVar17 = uVar21 & 0xfffffffc;
    uVar18 = uVar17;
    do {
      iVar14 = (int)(lVar22 * 8);
      pauVar3 = (undefined1 (*) [16])((long)puVar1 + (long)iVar14);
      if (lVar22 * 8 - (long)iVar14 != 0) {
        pauVar3 = (undefined1 (*) [16])
                  ((ulong)(puVar1 + lVar22 * 2) & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar20 = lVar22 * 0x10;
      puVar4 = (undefined8 *)(uVar11 + (long)(int)uVar20);
      if (uVar20 - (long)(int)uVar20 != 0) {
        puVar4 = (undefined8 *)(uVar11 + uVar20 & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar20 = uVar20 | 0x20;
      puVar5 = (undefined8 *)(uVar11 + (long)(int)uVar20);
      if (uVar20 != (long)(int)uVar20) {
        puVar5 = (undefined8 *)(uVar11 + uVar20 & 0xffffffffffff | 0x2bad000000000000);
      }
      auVar8 = *pauVar3;
      auVar9 = pauVar3[1];
      auVar23._8_8_ = 0;
      auVar23._0_8_ = uVar15;
      auVar23 = NEON_ext(auVar8,auVar23,8,1);
      puVar4[1] = uVar15;
      *puVar4 = auVar8._0_8_;
      puVar4[3] = auVar23._8_8_;
      puVar4[2] = auVar23._0_8_;
      auVar8._8_8_ = 0;
      auVar8._0_8_ = uVar15;
      auVar23 = NEON_ext(auVar9,auVar8,8,1);
      puVar5[1] = uVar15;
      *puVar5 = auVar9._0_8_;
      puVar5[3] = auVar23._8_8_;
      puVar5[2] = auVar23._0_8_;
      lVar22 = lVar22 + 4;
      uVar18 = uVar18 - 4;
    } while (uVar18 != 0);
    if (uVar17 != uVar21) goto LAB_fffffff00817de8c;
  }
  plVar10 = (long *)thunk_EXT_FUN_8011000003977010(uVar11,uVar21,*puVar2 & 2 | 1,0);
  thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ca2b18,uVar11,lVar16);
joined_r0xfffffff00817df08:
  if (plVar10 == (long *)0x0) {
    return false;
  }
  plVar12 = (long *)(**(code **)(*plVar10 + 0xe8))(plVar10,param_3);
  if (plVar12 != (long *)0x0) {
    uVar13 = (**(code **)(*plVar12 + 0x78))();
    lVar16 = (param_2 & 0xffffffff) * 8;
    iVar14 = (int)lVar16;
    puVar4 = (undefined8 *)(param_1 + 0x113d0 + (long)iVar14);
    if (lVar16 - iVar14 != 0) {
      puVar4 = (undefined8 *)(param_1 + 0x113d0 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar4 = uVar13;
    plVar6 = (long *)(param_1 + 0x111f0 + (long)iVar14);
    if (lVar16 - iVar14 != 0) {
      plVar6 = (long *)(param_1 + 0x111f0 + lVar16 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *plVar6 = (long)plVar12;
  }
  (**(code **)(*plVar10 + 0x28))(plVar10);
  return plVar12 != (long *)0x0;
}

