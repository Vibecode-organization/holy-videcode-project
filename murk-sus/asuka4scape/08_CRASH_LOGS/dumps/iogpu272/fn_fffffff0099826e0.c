// FUN_fffffff0099826e0 @ fffffff0099826e0 size=820

long FUN_fffffff0099826e0(long param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  long lVar1;
  long *plVar2;
  undefined8 *puVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  
  if (param_2 == 0x4000) {
    lVar14 = 0;
  }
  else if (param_2 == 0x40000) {
    lVar14 = 2;
  }
  else {
    if (param_2 != 0x10000) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid virtualPageSize(%u)\n");
      return 0;
    }
    lVar14 = 1;
  }
  if ((*(ulong *)(param_1 + 0x38) & (ulong)(param_2 - 1)) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: ByteCount is not virtualPageSize(%u) aligned\n");
    return 0;
  }
  if ((*(byte *)(param_1 + 0x80) & 1) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Unsupported for memory from IOSurfaceMemoryPool\n");
    return 0;
  }
  lVar1 = param_1 + 0xb0;
  lVar5 = *(long *)(lVar1 + lVar14 * 8);
  if (lVar5 != 0) {
    *param_4 = *(undefined4 *)(param_1 + 200 + lVar14 * 4);
    return lVar5;
  }
  FUN_fffffff009942d70(param_1);
  if (*(long *)(lVar1 + lVar14 * 8) != 0) goto LAB_fffffff0099829dc;
  uVar12 = (ulong)param_2;
  uVar11 = 0;
  if (uVar12 != 0) {
    uVar11 = *(ulong *)(param_1 + 0x38) / uVar12;
  }
  lVar5 = (uVar11 & 0xffffffff) << 3;
  lVar6 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1f98,lVar5);
  if (lVar6 == 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: Failed to allocate array of sub memory descriptors\n");
    FUN_fffffff009942d7c(param_1);
    return 0;
  }
  uVar4 = (**(code **)(**(long **)(param_1 + 0x90) + 0xa8))();
  iVar9 = (int)uVar11;
  if (iVar9 == 0) {
LAB_fffffff0099829c8:
    iVar9 = 0;
  }
  else {
    uVar10 = 0;
    lVar13 = 0;
    do {
      lVar7 = FUN_fffffff009946700
                        (*(undefined8 *)(param_1 + 0x90),lVar13,uVar12,uVar4 | param_3 & 0xfffffffc)
      ;
      lVar8 = uVar10 * 8;
      plVar2 = (long *)(lVar6 + (int)lVar8);
      if (lVar8 - (int)lVar8 != 0) {
        plVar2 = (long *)(lVar6 + lVar8 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar2 = lVar7;
      if (lVar7 == 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to allocate sub memory descriptors at index %u\n");
        break;
      }
      lVar13 = lVar13 + uVar12;
      uVar10 = uVar10 + 1;
    } while (uVar10 < (uVar11 & 0xffffffff));
    if ((int)uVar10 != iVar9) {
      if (0 < (int)uVar10) {
        uVar10 = uVar10 & 0xffffffff;
        uVar11 = uVar10 + 1;
        do {
          uVar10 = uVar10 - 1;
          lVar13 = uVar10 * 8;
          puVar3 = (undefined8 *)(lVar6 + (int)lVar13);
          if (lVar13 - (int)lVar13 != 0) {
            puVar3 = (undefined8 *)(lVar6 + lVar13 & 0xffffffffffffU | 0x2bad000000000000);
          }
          (**(code **)(*(long *)*puVar3 + 0x28))();
          *puVar3 = 0;
          uVar11 = uVar11 - 1;
        } while (1 < uVar11);
      }
      thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1fe8,lVar6,lVar5);
      lVar6 = 0;
      goto LAB_fffffff0099829c8;
    }
  }
  *(int *)(param_1 + 200 + lVar14 * 4) = iVar9;
  DataMemoryBarrier(2,3);
  *(long *)(lVar1 + lVar14 * 8) = lVar6;
LAB_fffffff0099829dc:
  FUN_fffffff009942d7c(param_1);
  *param_4 = *(undefined4 *)(param_1 + 200 + lVar14 * 4);
  return *(long *)(lVar1 + lVar14 * 8);
}

