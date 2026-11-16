// FUN_fffffff008184e7c @ fffffff008184e7c size=312

void FUN_fffffff008184e7c(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined8 *puVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  long lVar10;
  
  piVar9 = *(int **)(param_1 + 0x68);
  uVar3 = piVar9[0x14];
  do {
    uVar6 = 0;
    if (uVar3 != 0) {
      uVar6 = (piVar9[0x10] + 1U) / uVar3;
    }
  } while ((piVar9[0x10] + 1U) - uVar6 * uVar3 == *piVar9);
  uVar3 = piVar9[0x10];
  if (uVar3 < *(uint *)(param_1 + 0x5c)) {
    lVar10 = (ulong)uVar3 * 8;
    puVar1 = (undefined8 *)(*(long *)(param_1 + 0x70) + (long)(int)lVar10);
    if (lVar10 - (int)lVar10 != 0) {
      puVar1 = (undefined8 *)
               (*(long *)(param_1 + 0x70) + lVar10 & 0xffffffffffffU | 0x2bad000000000000);
    }
    *puVar1 = param_2;
    DataMemoryBarrier(2,3);
    if (param_4 != 0) {
      uVar6 = *(uint *)(param_1 + 0x108);
      uVar4 = *(uint *)(param_1 + 0x104);
      uVar5 = *(uint *)(param_1 + 0x100);
      uVar7 = 0;
      if (uVar5 != 0) {
        uVar7 = uVar6 / uVar5;
      }
      uVar7 = uVar6 - uVar7 * uVar5;
      if (uVar6 != uVar4) {
        uVar8 = 0;
        if (uVar5 != 0) {
          uVar8 = uVar4 / uVar5;
        }
        if (uVar7 == uVar4 - uVar8 * uVar5) {
          thunk_EXT_FUN_8011000003a49114
                    ("AGXk: %s:%d:%s: !!! Host Kick trace buffer is full (w=%u, r=%u, s=%u)\n");
          return;
        }
      }
      lVar10 = (ulong)uVar7 * 8;
      plVar2 = (long *)(*(long *)(param_1 + 0xf8) + (long)(int)lVar10);
      if (lVar10 != (int)lVar10) {
        plVar2 = (long *)(*(long *)(param_1 + 0xf8) + lVar10 & 0xffffffffffffU | 0x2bad000000000000)
        ;
      }
      *plVar2 = param_4;
      *(uint *)(param_1 + 0x108) = uVar6 + 1;
    }
    uVar6 = *(uint *)(*(long *)(param_1 + 0x68) + 0x50);
    uVar4 = 0;
    if (uVar6 != 0) {
      uVar4 = (uVar3 + 1) / uVar6;
    }
    *(uint *)(*(long *)(param_1 + 0x68) + 0x40) = (uVar3 + 1) - uVar4 * uVar6;
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! fLast3DCommandIndex out-of-bounds\n");
  return;
}

