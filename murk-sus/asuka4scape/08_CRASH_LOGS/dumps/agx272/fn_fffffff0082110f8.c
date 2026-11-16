// FUN_fffffff0082110f8 @ fffffff0082110f8 size=1028

long FUN_fffffff0082110f8(long param_1)

{
  undefined *puVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  bool bVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  
  puVar10 = (undefined8 *)(param_1 + 0x30);
  lVar3 = thunk_EXT_FUN_8011000003977d8c(*puVar10,0);
  lVar4 = thunk_EXT_FUN_8011000003977d8c(*(undefined8 *)(param_1 + 0x70),0);
  puVar1 = PTR_DAT_fffffff007ca5f88;
  lVar7 = 0;
  lVar11 = 0;
  lVar12 = 0;
  bVar2 = true;
  do {
    bVar8 = bVar2;
    if (*(long *)puVar10[lVar7 * 8 + 2] != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)puVar10[lVar7 * 8 + 2],0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)puVar10[lVar7 * 8 + 5] + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 8) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 8),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 8) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x10) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x10),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x10) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x18) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x18),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x18) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x20) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x20),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x20) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x28) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x28),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x28) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x30) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x30),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x30) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    if (*(long *)(puVar10[lVar7 * 8 + 2] + 0x38) != 0) {
      lVar5 = thunk_EXT_FUN_8011000003977d8c(*(long *)(puVar10[lVar7 * 8 + 2] + 0x38),0);
      lVar12 = lVar5 + lVar12;
      uVar6 = *(uint *)puVar1;
      if (2 < uVar6) {
        uVar9 = 0;
        uVar13 = 1;
        do {
          lVar5 = *(long *)(*(long *)(puVar10[lVar7 * 8 + 5] + 0x38) + uVar9 * 8);
          if (lVar5 != 0) {
            lVar5 = thunk_EXT_FUN_8011000003977d8c(lVar5,0);
            lVar11 = lVar5 + lVar11;
            uVar6 = *(uint *)puVar1;
          }
          bVar2 = uVar13 < (ulong)(long)(1 << (ulong)(uVar6 & 0x1f)) >> 3;
          uVar9 = uVar13;
          uVar13 = (ulong)((int)uVar13 + 1);
        } while (bVar2);
      }
    }
    lVar7 = 1;
    bVar2 = false;
  } while (bVar8);
  return lVar4 + lVar3 + lVar12 + lVar11;
}

