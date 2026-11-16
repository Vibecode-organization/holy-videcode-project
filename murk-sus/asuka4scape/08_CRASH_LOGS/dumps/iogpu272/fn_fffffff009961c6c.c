// FUN_fffffff009961c6c @ fffffff009961c6c size=96

void FUN_fffffff009961c6c(long param_1)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  bool bVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 uStack_a0;
  undefined8 uStack_98;
  undefined8 uStack_90;
  undefined8 uStack_88;
  
  iVar7 = *(int *)(param_1 + 0x94);
  *(int *)(param_1 + 0x94) = iVar7 + 1;
  if (iVar7 != -1) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0,
               "IOGPUScheduler: increment_gart_collector_disable_count -> %d");
    return;
  }
  lVar9 = FUN_fffffff009983be4();
  iVar7 = *(int *)(lVar9 + 0x94);
  *(int *)(lVar9 + 0x94) = iVar7 + -1;
  if (iVar7 != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0,
               "IOGPUScheduler: decrement_gart_collector_disable_count -> %d");
    return;
  }
  lVar9 = FUN_fffffff009983c14();
  uVar2 = *(ulong *)(lVar9 + 0xa8);
  if (DAT_fffffff00af227b8 != 0) {
    uVar2 = (ulong)DAT_fffffff00af227b8 << 0x14;
  }
  lVar11 = *(long *)(lVar9 + 0x60);
  if (lVar11 == 0) {
    uVar12 = 0xffffffffffffffff;
  }
  else {
    uVar5 = *(uint *)(lVar9 + 0x6c);
    uVar14 = (ulong)uVar5;
    do {
      uVar15 = uVar14 << 4 | 8;
      puVar3 = (uint *)(lVar11 + (int)uVar15);
      if (uVar15 != (long)(int)uVar15) {
        puVar3 = (uint *)(lVar11 + uVar15 & 0xffffffffffff | 0x2bad000000000000);
      }
      uVar15 = uVar14;
    } while (((uint)(*(int *)(lVar9 + 0x70) - *(int *)(lVar9 + 0x74)) < *puVar3) &&
            (uVar1 = *(int *)(lVar9 + 0x68) - 1U & (int)uVar14 - 1U, uVar14 = (ulong)uVar1,
            uVar15 = (ulong)uVar5, uVar1 != uVar5));
    lVar13 = uVar15 * 0x10;
    puVar4 = (undefined8 *)(lVar11 + (int)lVar13);
    if (lVar13 - (int)lVar13 != 0) {
      puVar4 = (undefined8 *)(lVar11 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar12 = *puVar4;
  }
  *(undefined8 *)(lVar9 + 0xa0) = uVar12;
  uStack_98 = 0;
  uStack_90 = 0;
  uStack_88 = 0;
  FUN_fffffff00997dff4(&uStack_98,lVar9 + 0x1b8);
  iVar7 = 0;
  bVar6 = false;
  do {
    do {
      bVar10 = bVar6;
      lVar11 = FUN_fffffff00997e0b0(&uStack_98);
      if (lVar11 == 0) goto LAB_fffffff009961e7c;
      iVar8 = FUN_fffffff009942bf8();
      bVar6 = bVar10;
    } while ((iVar8 != 0) || (bVar6 = true, 0 < *(int *)(lVar11 + 0x18) - *(int *)(lVar9 + 0xa0)));
    iVar8 = FUN_fffffff009942c08(lVar11);
    iVar7 = iVar7 + iVar8;
    lVar11 = FUN_fffffff009974f6c(*(undefined8 *)(lVar9 + 0x1a8),0);
    lVar13 = FUN_fffffff009974f6c(*(undefined8 *)(lVar9 + 0x1a8),1);
    bVar6 = bVar10;
  } while (uVar2 < (ulong)(lVar13 + lVar11));
LAB_fffffff009961e7c:
  if (((bVar10) &&
      ((*(uint *)(*(long *)(lVar9 + 0x1a8) + 0x1fc) & 0x40) == 0 && DAT_fffffff00af227cc == 0)) &&
     (*(int *)(lVar9 + 0x94) == 0)) {
    thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(lVar9 + 0xc0));
    if (*(int *)(lVar9 + 0x88) == 0) {
      uStack_a0 = 0;
      *(undefined4 *)(lVar9 + 0x88) = 1;
      thunk_EXT_FUN_8011000003204ed8(*(undefined4 *)(lVar9 + 0x90),1000000,&uStack_a0);
      thunk_EXT_FUN_8011000003277924(*(undefined8 *)(lVar9 + 0xb8),uStack_a0);
    }
    thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(lVar9 + 0xc0));
  }
  if (iVar7 != 0) {
    *(long *)(lVar9 + 0x120) = *(long *)(lVar9 + 0x120) + (long)iVar7;
  }
  FUN_fffffff00997e060(&uStack_98);
  return;
}

