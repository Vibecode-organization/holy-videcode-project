// FUN_fffffff0099547ec @ fffffff0099547ec size=980

long * FUN_fffffff0099547ec(long *param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  uint uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  
  uVar9 = *(uint *)(param_3 + 0x50);
  lVar5 = *(long *)(param_3 + 0x38);
  uVar6 = *(undefined8 *)(param_3 + 0x40);
  uVar12 = *(undefined8 *)(param_3 + 0x48);
  puVar1 = (undefined8 *)(param_2 + 0x50);
  if (param_2 == 0) {
    puVar1 = (undefined8 *)PTR_DAT_fffffff007ff2830;
  }
  uVar10 = *puVar1;
  if (((param_2 == 0) || (*(ulong *)(param_3 + 0x18) == 0)) ||
     ((*(byte *)(param_2 + 0x40) >> 1 & 1) != 0)) {
    if (0xf < *(ulong *)(param_3 + 0x18)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Unsupported protecton options (%016llx) bytes\n");
      return (long *)0x0;
    }
    uVar3 = thunk_EXT_FUN_8011000002c2d4f8();
    if (uVar3 >> 0x20 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Cannot store 64-bit protection options\n");
      return (long *)0x0;
    }
    if ((lVar5 == 0) || (uVar9 == 0)) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: Invalid Arguments\n");
      return (long *)0x0;
    }
    if ((*(int *)((long)param_1 + 0x274) - 1U & uVar9) != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: virtual_page_size(%u) is not minimum VirtualPageSize(%u) aligned\n");
      return (long *)0x0;
    }
    plVar4 = (long *)(**(code **)(*param_1 + 0x5b0))(param_1,param_2,0x40);
    if (plVar4 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to allocate resource object\n");
      return (long *)0x0;
    }
    lVar5 = FUN_fffffff009940ab0(param_1,lVar5,uVar9,0,uVar6,uVar12,uVar10);
    plVar4[5] = lVar5;
    if (lVar5 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Failed to allocate IOGPUVirtualMemory object\n");
    }
    else {
      lVar11 = 0;
      if (((*(uint *)(param_3 + 0x14) >> 0xd & 1) != 0) ||
         (lVar7 = *(long *)(lVar5 + 0xb0), lVar7 == 0)) {
LAB_fffffff009954ab8:
        *(int *)((long)plVar4 + 0x14) = (int)uVar3;
        FUN_fffffff009943f9c(lVar5,uVar3);
        plVar4[0x12] = lVar11;
        plVar4[0xf] = 0;
        uVar2 = *(uint *)(param_3 + 0x14);
        uVar9 = *(uint *)(plVar4 + 2) & 0xff800000 |
                *(uint *)(plVar4 + 2) & 0x3fffff | (uVar2 >> 0xe & 1) << 0x16;
        if (param_2 == 0) {
          lVar5 = 0;
          uVar6 = 0;
          *(uint *)(plVar4 + 2) = uVar9 | 0x400;
        }
        else {
          uVar9 = uVar9 | 0x200;
          *(uint *)(plVar4 + 2) = uVar9;
          plVar8 = plVar4;
          if (((uVar2 & 0xffffff) >> 0xe & 1) == 0) {
            while ((uVar9 & 0xff) == 0x82) {
              uVar9 = *(uint *)((long *)plVar8[6] + 2);
              plVar8 = (long *)plVar8[6];
            }
            if (((uVar9 & 0xff) == 0x40) || ((uVar9 & 0xf) != 0)) {
              lVar5 = 0;
            }
            else {
              lVar5 = plVar8[0xf];
            }
            FUN_fffffff00996647c(param_2,lVar5);
            lVar5 = plVar4[0xf];
          }
          else {
            lVar5 = 0;
          }
          uVar6 = *(undefined8 *)(param_2 + 0x38);
        }
        thunk_EXT_FUN_80110000036da494(0x8509001c,uVar6,plVar4[0xe],0x40,lVar5,0);
        return plVar4;
      }
      if ((*(uint *)(param_3 + 0x14) >> 0xf & 1) == 0) {
        lVar11 = thunk_EXT_FUN_801100000396cb64(lVar7,uVar10,0,1,0,0);
      }
      else {
        lVar11 = (**(code **)(*param_1 + 0x5e0))(param_1,param_2,lVar7,param_3);
      }
      if (lVar11 != 0) {
        lVar5 = plVar4[5];
        goto LAB_fffffff009954ab8;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: failed to create client map for meta data\n");
    }
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return (long *)0x0;
}

