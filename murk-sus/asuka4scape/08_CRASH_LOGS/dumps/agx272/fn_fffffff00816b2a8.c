// FUN_fffffff00816b2a8 @ fffffff00816b2a8 size=556

void FUN_fffffff00816b2a8(long param_1)

{
  ulong *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long local_270 [66];
  
  local_270[0x40] = *(long *)PTR_DAT_fffffff007ca61a0;
  puVar1 = (ulong *)(param_1 + 0x1ac68);
  local_270[0x3d] = 0;
  local_270[0x3c] = 0;
  local_270[0x3f] = 0;
  local_270[0x3e] = 0;
  plVar6 = local_270 + 0x40;
  local_270[0x39] = 0;
  local_270[0x38] = 0;
  local_270[0x3b] = 0;
  local_270[0x3a] = 0;
  local_270[0x35] = 0;
  local_270[0x34] = 0;
  local_270[0x37] = 0;
  local_270[0x36] = 0;
  local_270[0x31] = 0;
  local_270[0x30] = 0;
  local_270[0x33] = 0;
  local_270[0x32] = 0;
  local_270[0x2d] = 0;
  local_270[0x2c] = 0;
  local_270[0x2f] = 0;
  local_270[0x2e] = 0;
  local_270[0x29] = 0;
  local_270[0x28] = 0;
  local_270[0x2b] = 0;
  local_270[0x2a] = 0;
  local_270[0x25] = 0;
  local_270[0x24] = 0;
  local_270[0x27] = 0;
  local_270[0x26] = 0;
  local_270[0x21] = 0;
  local_270[0x20] = 0;
  local_270[0x23] = 0;
  local_270[0x22] = 0;
  local_270[0x1d] = 0;
  local_270[0x1c] = 0;
  local_270[0x1f] = 0;
  local_270[0x1e] = 0;
  local_270[0x19] = 0;
  local_270[0x18] = 0;
  local_270[0x1b] = 0;
  local_270[0x1a] = 0;
  local_270[0x15] = 0;
  local_270[0x14] = 0;
  local_270[0x17] = 0;
  local_270[0x16] = 0;
  local_270[0x11] = 0;
  local_270[0x10] = 0;
  local_270[0x13] = 0;
  local_270[0x12] = 0;
  local_270[0xd] = 0;
  local_270[0xc] = 0;
  local_270[0xf] = 0;
  local_270[0xe] = 0;
  local_270[9] = 0;
  local_270[8] = 0;
  local_270[0xb] = 0;
  local_270[10] = 0;
  local_270[5] = 0;
  local_270[4] = 0;
  local_270[7] = 0;
  local_270[6] = 0;
  local_270[1] = 0;
  local_270[0] = 0;
  local_270[3] = 0;
  local_270[2] = 0;
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x1ac70));
  uVar7 = *puVar1;
  if (uVar7 != 0) {
    lVar8 = 0;
    puVar2 = (undefined8 *)(param_1 + 0x11df8);
    do {
      uVar3 = (uVar7 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar7 & 0x5555555555555555) << 1;
      uVar3 = (uVar3 & 0xcccccccccccccccc) >> 2 | (uVar3 & 0x3333333333333333) << 2;
      uVar3 = (uVar3 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar3 & 0xf0f0f0f0f0f0f0f) << 4;
      uVar3 = (uVar3 & 0xff00ff00ff00ff00) >> 8 | (uVar3 & 0xff00ff00ff00ff) << 8;
      uVar3 = (uVar3 & 0xffff0000ffff0000) >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10;
      uVar3 = LZCOUNT(uVar3 >> 0x20 | uVar3 << 0x20);
      uVar9 = 1L << (uVar3 & 0x3f);
      LOAcquire();
      *puVar1 = *puVar1 & ~uVar9;
      LORelease();
      if ((int)uVar3 < *(int *)(param_1 + 0x11e00)) {
        thunk_EXT_FUN_80110000032222a8(*puVar2);
        if ((int)uVar3 < *(int *)(param_1 + 0x11e00)) {
          plVar4 = *(long **)(*(long *)(param_1 + 0x11e20) + uVar3 * 8);
          if ((plVar4 != (long *)0x0) &&
             (uVar3 = thunk_EXT_FUN_801100000294991c(plVar4), (uVar3 & 1) != 0)) {
            thunk_EXT_FUN_8011000003222de0(*puVar2);
            (**(code **)(*plVar4 + 0x130))(plVar4);
            plVar5 = (long *)local_270[lVar8];
            local_270[lVar8] = (long)plVar4;
            (**(code **)(*plVar4 + 0x20))(plVar4);
            if (plVar5 != (long *)0x0) {
              (**(code **)(*plVar5 + 0x28))(plVar5);
            }
            lVar8 = lVar8 + 1;
            (**(code **)(*plVar4 + 0x28))(plVar4);
            goto LAB_fffffff00816b364;
          }
        }
        thunk_EXT_FUN_8011000003222de0(*puVar2);
      }
LAB_fffffff00816b364:
      uVar7 = uVar7 & (uVar9 ^ 0xffffffffffffffff);
    } while (uVar7 != 0);
  }
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x1ac70));
  do {
    plVar6 = plVar6 + -1;
    if ((long *)*plVar6 != (long *)0x0) {
      (**(code **)(*(long *)*plVar6 + 0x28))();
    }
    *plVar6 = 0;
  } while (plVar6 != local_270);
  if (*(long *)PTR_DAT_fffffff007ca61a0 == local_270[0x40]) {
    return;
  }
  thunk_EXT_FUN_8011000003a48590();
  return;
}

