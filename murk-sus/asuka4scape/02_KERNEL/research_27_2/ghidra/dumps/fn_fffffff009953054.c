// FUN_fffffff009953054 @ fffffff009953054 size=1320
// CALLERS:
//   fffffff00afb839c no-fn
//   fffffff00996707c FUN_fffffff0099669e0@fffffff0099669e0
//   fffffff009953044 FUN_fffffff00995300c@fffffff00995300c
// CALLEES:
//   fffffff009980d58 FUN_fffffff009980d58
//   fffffff00998466c thunk_EXT_FUN_8011000002c2d4f8
//   fffffff009984d2c thunk_EXT_FUN_80110000036da494
//   fffffff009984f9c thunk_EXT_FUN_80110000032db760
//   fffffff009984c2c thunk_EXT_FUN_80110000038db19c
//   fffffff009943f9c FUN_fffffff009943f9c
//   fffffff00996647c FUN_fffffff00996647c
//   fffffff0099529c0 FUN_fffffff0099529c0
//   fffffff00998477c thunk_EXT_FUN_801100000396cb64
//   fffffff009981d00 FUN_fffffff009981d00

long * FUN_fffffff009953054
                 (long *param_1,long param_2,ulong param_3,ulong param_4,ulong param_5,
                 undefined8 param_6,long *param_7,long param_8,ulong *param_9,ulong *param_10)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined *puVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  long local_78;
  undefined8 local_68;
  
  if (((param_2 == 0) || (param_4 == 0)) || ((*(byte *)(param_2 + 0x40) >> 1 & 1) != 0)) {
    if (0xf < param_4) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Unsupported protecton options (%016llx) bytes\n");
      return (long *)0x0;
    }
    uVar4 = thunk_EXT_FUN_8011000002c2d4f8(param_4);
    puVar3 = PTR_DAT_fffffff007ff2838;
    if (param_5 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: invalid arguments\n");
      return (long *)0x0;
    }
    if (uVar4 >> 0x20 != 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: Cannot store 64-bit protection options\n");
      return (long *)0x0;
    }
    puVar1 = (undefined8 *)(param_2 + 0x50);
    if (param_2 == 0) {
      puVar1 = (undefined8 *)PTR_DAT_fffffff007ff2830;
    }
    uVar11 = *puVar1;
    if (((param_8 == 0) || (uVar10 = *param_9, uVar10 == 0)) || (*param_10 == 0)) {
      local_78 = 0;
    }
    else {
      lVar12 = *(long *)PTR_DAT_fffffff007ff2838;
      uVar13 = -lVar12;
      uVar14 = uVar10 & uVar13;
      local_78 = uVar10 - uVar14;
      param_5 = local_78 + *param_10;
      *param_10 = param_5;
      *param_9 = uVar14;
      *param_10 = (lVar12 + *param_10) - 1 & uVar13;
    }
    lVar12 = *(long *)puVar3;
    plVar5 = (long *)(**(code **)(*param_1 + 0x5b0))(param_1,param_2,param_3);
    if (plVar5 == (long *)0x0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: createResource failed\n");
      return (long *)0x0;
    }
    if (param_2 == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = 1;
      if ((*(byte *)((long)param_1 + 0x1fc) & 0x80) == 0) {
        uVar15 = (uint)(uVar4 == 0) & (uint)param_6 >> 0x10;
      }
    }
    uVar10 = (param_5 + lVar12) - 1 & -lVar12;
    if ((param_8 == 0) || ((*(byte *)(param_8 + 0x16) >> 4 & 1) == 0)) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined8 *)(param_8 + 0x50);
    }
    uVar2 = uVar11;
    if (uVar15 == 0) {
      uVar2 = 0;
    }
    lVar12 = FUN_fffffff009980d58(param_1,uVar11,param_2,0,param_6,uVar10,uVar7,uVar2);
    if (lVar12 == 0) {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: IOGPUSysMemory::withOptions failed\n");
    }
    else {
      uVar7 = FUN_fffffff009981d00();
      plVar5[5] = lVar12;
      if (uVar15 == 0) {
        lVar6 = 0;
LAB_fffffff009953384:
        *(int *)((long)plVar5 + 0x14) = (int)uVar4;
        FUN_fffffff009943f9c(lVar12,uVar4);
        plVar5[9] = local_78;
        plVar5[0x12] = lVar6;
        plVar5[0xf] = uVar10;
        if (param_8 == 0) {
          uVar15 = *(uint *)(plVar5 + 2) | 0x400000;
        }
        else {
          uVar15 = *(uint *)(plVar5 + 2) & 0xff800000 |
                   *(uint *)(plVar5 + 2) & 0x3fffff | (*(uint *)(param_8 + 0x14) >> 0xe & 1) << 0x16
          ;
        }
        if (param_2 == 0) {
          *(uint *)(plVar5 + 2) = uVar15 | 0x400;
        }
        else {
          uVar9 = uVar15 | 0x200;
          *(uint *)(plVar5 + 2) = uVar9;
          plVar8 = plVar5;
          if ((uVar15 >> 0x16 & 1) == 0) {
            while ((uVar9 & 0xff) == 0x82) {
              uVar9 = *(uint *)((long *)plVar8[6] + 2);
              plVar8 = (long *)plVar8[6];
            }
            if (((uVar9 & 0xff) == 0x40) || ((uVar9 & 0xf) != 0)) {
              lVar12 = 0;
            }
            else {
              lVar12 = plVar8[0xf];
            }
            FUN_fffffff00996647c(param_2,lVar12);
          }
        }
        if (param_7 != (long *)0x0) {
          if ((long *)plVar5[0x12] == (long *)0x0) {
            lVar12 = 0;
          }
          else {
            lVar12 = (**(code **)(*(long *)plVar5[0x12] + 0x78))();
            if ((*(byte *)(plVar5 + 2) & 0x7f) == 0) {
              uVar4 = plVar5[9];
            }
            else if (*(byte *)(plVar5 + 2) == 0x82) {
              uVar4 = (ulong)*(uint *)((long)plVar5 + 0x4c);
            }
            else {
              uVar4 = 0;
            }
            lVar12 = uVar4 + lVar12;
          }
          *param_7 = lVar12;
        }
        if (param_2 == 0) {
          thunk_EXT_FUN_80110000036da494
                    (0x8509001c,0,plVar5[0xe],param_3 & 0xffffffff,plVar5[0xf],0);
          uVar11 = 0;
        }
        else {
          thunk_EXT_FUN_80110000036da494
                    (0x8509001c,*(undefined8 *)(param_2 + 0x38),plVar5[0xe],param_3 & 0xffffffff,
                     plVar5[0xf],0);
          uVar11 = *(undefined8 *)(param_2 + 0x38);
        }
        lVar12 = plVar5[0xe];
        uVar7 = FUN_fffffff0099529c0(plVar5);
        local_68 = 0;
        thunk_EXT_FUN_80110000032db760(uVar7,&local_68);
        thunk_EXT_FUN_80110000036da494(0x85090020,uVar11,lVar12,param_3 & 0xffffffff,local_68,0);
        return plVar5;
      }
      if ((param_8 == 0) || (-1 < *(char *)(param_8 + 0x15))) {
        lVar6 = thunk_EXT_FUN_801100000396cb64(uVar7,uVar11,0,1,0,0);
      }
      else {
        lVar6 = (**(code **)(*param_1 + 0x5e0))(param_1,param_2,uVar7,param_8);
      }
      if (lVar6 != 0) {
        lVar12 = plVar5[5];
        goto LAB_fffffff009953384;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,"%s: failed to create client map\n");
    }
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return (long *)0x0;
}

