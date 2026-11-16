// FUN_fffffff0081c9990 @ fffffff0081c9990 size=356

void FUN_fffffff0081c9990(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  long lVar6;
  ulong unaff_x30;
  undefined8 uVar7;
  undefined8 uVar8;
  
  thunk_EXT_FUN_80110000038ff214(*(undefined8 *)(param_1 + 0x14d0));
  puVar5 = *(uint **)(param_1 + 0x14b0);
  uVar3 = puVar5[4];
  if (0xff < uVar3) {
    thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! FW MemDesc write_index out-of-bounds\n");
    return;
  }
  if (*puVar5 < 0x100) {
    if (((uVar3 - *puVar5 ^ 0xffffffff) & 0xc0) == 0) {
      (**(code **)(**(long **)(param_1 + 0x1460) + 0x568))
                (*(long **)(param_1 + 0x1460),0x85000000000000,0);
      puVar5 = *(uint **)(param_1 + 0x14b0);
    }
    uVar1 = uVar3 + 1 & 0xff;
    while (uVar1 == *puVar5) {
      thunk_EXT_FUN_80110000038fe988(10);
      puVar5 = *(uint **)(param_1 + 0x14b0);
    }
    lVar6 = (ulong)uVar3 * 0x18;
    puVar2 = (undefined8 *)(*(long *)(param_1 + 0x14b8) + (long)(int)lVar6);
    if (lVar6 - (int)lVar6 != 0) {
      puVar2 = (undefined8 *)
               (*(long *)(param_1 + 0x14b8) + lVar6 & 0xffffffffffffU | 0x2bad000000000000);
    }
    uVar8 = param_2[1];
    uVar7 = *param_2;
    puVar2[2] = param_2[2];
    puVar2[1] = uVar8;
    *puVar2 = uVar7;
    DataMemoryBarrier(2,3);
    *(uint *)(*(long *)(param_1 + 0x14b0) + 0x10) = uVar1;
    if (((unaff_x30 ^ unaff_x30 << 1) >> 0x3e & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0xc471,0xfffffff0081c9aa0);
      (*pcVar4)();
    }
    thunk_EXT_FUN_80110000038ff2e0(*(undefined8 *)(param_1 + 0x14d0));
    return;
  }
  thunk_EXT_FUN_8011000003a49114("AGXk: %s:%d:%s: !!! FW MemDesc read_index out-of-bounds\n");
  return;
}

