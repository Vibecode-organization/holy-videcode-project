// FUN_fffffff009940bb8 @ fffffff009940bb8 size=1532

undefined8
FUN_fffffff009940bb8
          (long param_1,long *param_2,ulong param_3,ulong param_4,undefined1 param_5,ulong param_6,
          ulong param_7,undefined8 param_8)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  
  uVar1 = (*DAT_fffffff007fe9090)();
  if ((((int)uVar1 != 0) && (uVar1 = 0, param_3 != 0)) && (uVar7 = (uint)param_4, uVar7 != 0)) {
    if ((uVar7 & uVar7 - 1) == 0) {
      if ((*(int *)(*(long *)(param_1 + 0x10) + 0x274) - 1U & uVar7) == 0) {
        if (((uVar7 == 0x4000) || (uVar7 == 0x10000)) || (uVar7 == 0x40000)) {
          uVar5 = (param_3 + (param_4 & 0xffffffff)) - 1 & -(param_4 & 0xffffffff);
          *(ulong *)(param_1 + 0x88) = uVar5;
          if (uVar5 < param_3) {
            thunk_EXT_FUN_80110000038db19c
                      (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                       "%s: Overflow aligning virtual length\n");
            uVar1 = 0;
          }
          else {
            *(uint *)(param_1 + 0x90) = uVar7;
            uVar6 = (param_4 & 0xaaaaaaaa) >> 1 | (param_4 & 0x55555555) << 1;
            uVar6 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
            uVar6 = (uVar6 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar6 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
            uVar5 = uVar5 >> (LZCOUNT((uVar6 >> 0x10 | (uVar6 & 0xffff0000ffff) << 0x10) << 0x20) &
                             0x3fU);
            *(int *)(param_1 + 0xa0) = (int)uVar5;
            lVar2 = thunk_EXT_FUN_80110000038fe750(&DAT_fffffff007ff0fa8,(uVar5 & 0xffffffff) << 3);
            *(long *)(param_1 + 0x98) = lVar2;
            if (lVar2 == 0) {
              thunk_EXT_FUN_80110000038db19c
                        (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                         "%s: Failed to allocate array of descriptors\n");
              uVar1 = 0;
            }
            else {
              *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_1 + 0x88);
              lVar2 = FUN_fffffff0099411b4(*(undefined4 *)(param_1 + 0xa0));
              *(long *)(param_1 + 0xa8) = lVar2;
              if (lVar2 == 0) {
                thunk_EXT_FUN_80110000038db19c
                          (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                           "%s: Failed to allocate descriptor bitmap\n");
                uVar1 = 0;
              }
              else {
                if (param_6 != 0) {
                  if (((param_6 + *(long *)PTR_DAT_fffffff007ff2838) - 1 &
                      -*(long *)PTR_DAT_fffffff007ff2838) < param_6) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Overflow aligning metadata length\n");
                    return 0;
                  }
                  lVar2 = (**(code **)(*param_2 + 0x5d8))(param_2,param_8,0x110063);
                  *(long *)(param_1 + 0xb0) = lVar2;
                  if (lVar2 == 0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Failed to allocate metadata memory descriptor\n");
                    return 0;
                  }
                  thunk_EXT_FUN_8011000003977b2c(lVar2,param_8,4,0);
                  uVar5 = (**(code **)(**(long **)(param_1 + 0xb0) + 0xb0))();
                  uVar6 = *(ulong *)(param_1 + 0x38);
                  *(ulong *)(param_1 + 0x38) = uVar6 + uVar5;
                  if (CARRY8(uVar6,uVar5)) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Overflow adding metadata length to byte count\n");
                    return 0;
                  }
                }
                if (param_7 != 0) {
                  uVar5 = (param_7 + *(long *)PTR_DAT_fffffff007ff2838) - 1 &
                          -*(long *)PTR_DAT_fffffff007ff2838;
                  if (uVar5 < param_7) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Overflow aligning residency data length\n");
                    return 0;
                  }
                  uVar6 = 0;
                  if ((ulong)*(uint *)(param_1 + 0x90) != 0) {
                    uVar6 = *(ulong *)(param_1 + 0x88) / (ulong)*(uint *)(param_1 + 0x90);
                  }
                  if (uVar5 < uVar6) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Residency data length(%llu) less than required minimum size(%llu)\n"
                              );
                    return 0;
                  }
                  uVar1 = 0;
                  if ((*(uint *)((long)param_2 + 0x1fc) & 0x80) != 0) {
                    uVar1 = param_8;
                  }
                  lVar2 = (**(code **)(*param_2 + 0x5d8))(param_2,uVar1,0x100063);
                  *(long *)(param_1 + 0xb8) = lVar2;
                  if (lVar2 == 0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Failed to allocate residency data memory descriptor\n");
                    return 0;
                  }
                  thunk_EXT_FUN_8011000003977b2c(lVar2,param_8,4,0);
                  plVar3 = (long *)(**(code **)(**(long **)(param_1 + 0xb8) + 0xe8))
                                             (*(long **)(param_1 + 0xb8),1);
                  *(long **)(param_1 + 0xc0) = plVar3;
                  if (plVar3 == (long *)0x0) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Failed to allocate residency data kernel map\n");
                    return 0;
                  }
                  uVar1 = (**(code **)(*plVar3 + 0x78))();
                  *(undefined8 *)(param_1 + 200) = uVar1;
                  uVar4 = (**(code **)(**(long **)(param_1 + 0xb8) + 0xb0))();
                  thunk_EXT_FUN_8011000003a61cc0(uVar1,uVar4);
                  uVar5 = (**(code **)(**(long **)(param_1 + 0xb8) + 0xb0))();
                  uVar6 = *(ulong *)(param_1 + 0x38);
                  *(ulong *)(param_1 + 0x38) = uVar6 + uVar5;
                  if (CARRY8(uVar6,uVar5)) {
                    thunk_EXT_FUN_80110000038db19c
                              (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                               "%s: Overflow adding residency data length to byte count\n");
                    return 0;
                  }
                }
                *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x20;
                *(undefined1 *)(param_1 + 0xd0) = param_5;
                uVar1 = 1;
              }
            }
          }
        }
        else {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "%s: Invalid virtual_page_size(%u)\n");
          uVar1 = 0;
        }
      }
      else {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "%s: virtual_page_size(%u) is not minimum VirtualPageSize(%u) aligned\n");
        uVar1 = 0;
      }
    }
    else {
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                 "%s: virtual_page_size(%u) is not a power of 2\n");
      uVar1 = 0;
    }
  }
  return uVar1;
}

