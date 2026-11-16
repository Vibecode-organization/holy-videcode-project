// FUN_fffffff009980d58 @ fffffff009980d58 size=1140

/* WARNING: Removing unreachable block (ram,0xfffffff0099810dc) */

long FUN_fffffff009980d58
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,uint param_5,
               ulong param_6,long param_7,undefined8 param_8)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  bool bVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  ulong uVar12;
  int local_64;
  
  puVar3 = PTR_DAT_fffffff007ff2838;
  lVar7 = *(long *)PTR_DAT_fffffff007ff2838;
  if ((-lVar7 & (param_1[0x23] * (ulong)*(uint *)((long)param_1 + 0x2ec)) / 100) < param_6) {
    return 0;
  }
  param_5 = param_5 | 0x100000;
  if (param_6 < 0xc0000001) {
    local_64 = 0;
    uVar11 = 0;
    if ((param_7 == 0) || (param_6 <= (ulong)(lVar7 * 2))) {
LAB_fffffff00998106c:
      plVar6 = (long *)(**(code **)(*param_1 + 0x5d8))(param_1,param_8,param_5,param_6,lVar7);
    }
    else {
      plVar6 = (long *)thunk_EXT_FUN_8011000002c333ec
                                 (param_1[0x1f],param_6,param_5,param_7,param_2,1,&local_64);
      bVar4 = plVar6 != (long *)0x0 && local_64 == 0;
      uVar11 = (uint)bVar4;
      if (local_64 == -0x1ffffd1e) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: failed to create memory descriptor from IOSurfaceMemoryPool\n");
      }
      else if (plVar6 == (long *)0x0) {
        lVar7 = *(long *)puVar3;
        uVar11 = (uint)bVar4;
        goto LAB_fffffff00998106c;
      }
    }
  }
  else {
    uVar10 = (param_6 - 1) / 0x18000000 & 0xffffffff8;
    lVar7 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff1ea8,uVar10 + 8);
    if (lVar7 == 0) goto LAB_fffffff009981128;
    uVar12 = 0;
    uVar8 = param_6;
    do {
      uVar1 = uVar8;
      if (0xbfffffff < uVar8) {
        uVar1 = 0xc0000000;
      }
      lVar5 = (**(code **)(*param_1 + 0x5d8))(param_1,param_8,param_5,uVar1,1);
      lVar9 = uVar12 * 8;
      plVar6 = (long *)(lVar7 + (int)lVar9);
      if (lVar9 != (int)lVar9) {
        plVar6 = (long *)(lVar7 + lVar9 & 0xffffffffffffU | 0x2bad000000000000);
      }
      *plVar6 = lVar5;
      if (lVar5 == 0) {
        if ((int)uVar12 != 0) {
          lVar9 = 0;
          do {
            lVar5 = lVar9 * 8;
            puVar2 = (undefined8 *)(lVar7 + (int)lVar5);
            if (lVar5 - (int)lVar5 != 0) {
              puVar2 = (undefined8 *)(lVar7 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
            }
            (**(code **)(*(long *)*puVar2 + 0x28))();
            *puVar2 = 0;
            lVar9 = lVar9 + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1ef8,lVar7,uVar10 + 8);
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: Failed to create BufferMemoryDescriptor for partial backing\n");
        return 0;
      }
      uVar11 = (int)uVar12 + 1;
      uVar12 = (ulong)uVar11;
      uVar8 = uVar8 - uVar1;
    } while (uVar8 != 0);
    plVar6 = (long *)FUN_fffffff009946144(lVar7,uVar12,0x100003,0);
    if (plVar6 != (long *)0x0) {
      thunk_EXT_FUN_8011000003977ae0(plVar6,0,100);
    }
    if (uVar11 != 0) {
      lVar9 = 0;
      do {
        lVar5 = lVar9 * 8;
        puVar2 = (undefined8 *)(lVar7 + (int)lVar5);
        if (lVar5 - (int)lVar5 != 0) {
          puVar2 = (undefined8 *)(lVar7 + lVar5 & 0xffffffffffffU | 0x2bad000000000000);
        }
        (**(code **)(*(long *)*puVar2 + 0x28))();
        *puVar2 = 0;
        lVar9 = lVar9 + 1;
        uVar12 = uVar12 - 1;
      } while (uVar12 != 0);
    }
    thunk_EXT_FUN_80110000038fe768(&DAT_fffffff007ff1f48,lVar7,uVar10 + 8);
    uVar11 = 0;
  }
  if (plVar6 != (long *)0x0) {
    thunk_EXT_FUN_8011000003977b2c(plVar6,param_2,4,0);
    lVar7 = (**(code **)(*param_1 + 0x590))(*param_1 + 0x590,param_1);
    if (lVar7 != 0) {
      *(long **)(lVar7 + 0x90) = plVar6;
      *(ulong *)(lVar7 + 0x38) = param_6;
      *(uint *)(lVar7 + 0x80) = *(uint *)(lVar7 + 0x80) & 0xfffffffe | uVar11;
      *(undefined4 *)(lVar7 + 0x84) = 0;
      *(uint *)(lVar7 + 0x98) = param_5;
      *(undefined8 *)(lVar7 + 0xa0) = param_2;
      param_1[0x22] = param_1[0x22] + param_6;
      return lVar7;
    }
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
               "%s: allocIOGPUResource failed to alloc texture object\n");
    (**(code **)(*plVar6 + 0x28))(plVar6);
    return 0;
  }
LAB_fffffff009981128:
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
             "%s: fAccelerator->createBufferMemoryDescriptorInTaskWithOptions failed\n");
  return 0;
}

