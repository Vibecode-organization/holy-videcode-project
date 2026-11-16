// FUN_fffffff0099640c0 @ fffffff0099640c0 size=880

undefined8 FUN_fffffff0099640c0(long param_1,uint param_2,long *param_3)

{
  undefined *puVar1;
  long lVar2;
  long *plVar3;
  undefined *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 *puVar9;
  
  thunk_EXT_FUN_80110000032222a8(*(undefined8 *)(param_1 + 0x48));
  puVar1 = PTR_DAT_fffffff007ff2838;
  puVar4 = PTR_DAT_fffffff007ff2830;
  puVar6 = (undefined8 *)(param_1 + 0x20);
  puVar9 = (undefined8 *)0x0;
  do {
    uVar8 = param_2;
    puVar6 = (undefined8 *)*puVar6;
    if (puVar6 == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)thunk_EXT_FUN_80110000038fe074(&DAT_fffffff007ff07a8);
      if (puVar6 == (undefined8 *)0x0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                   "IOMallocType failed to alloc client_shared\n");
        uVar7 = 0;
      }
      else {
        uVar5 = (ulong)(uint)~(-1 << (ulong)(*(uint *)PTR_DAT_fffffff007ff2740 & 0x1f));
        lVar2 = (**(code **)(**(long **)(param_1 + 0x10) + 0x5d8))
                          (*(long **)(param_1 + 0x10),*(undefined8 *)puVar4,0x10003,
                           uVar5 + *(long *)(param_1 + 0x28) * *(long *)(param_1 + 0x30) &
                           (uVar5 ^ 0xffffffffffffffff),*(undefined8 *)puVar1);
        if ((long *)puVar6[1] != (long *)0x0) {
          (**(code **)(*(long *)puVar6[1] + 0x28))();
        }
        puVar6[1] = lVar2;
        if (lVar2 == 0) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ff2808,0x11,
                     "IOBufferMemoryDescriptor::inTaskWithOptions failed to allocate a client_shared block.\n"
                    );
          puVar4 = &DAT_fffffff007ff07e8;
        }
        else {
          thunk_EXT_FUN_8011000003977af0(lVar2,*(undefined8 *)(param_1 + 0x18),4,0);
          plVar3 = (long *)thunk_EXT_FUN_801100000396cb64
                                     (puVar6[1],*(undefined8 *)(param_1 + 0x18),0,
                                      *(uint *)(param_1 + 0x58) | 1,0,0);
          if ((long *)puVar6[2] != (long *)0x0) {
            (**(code **)(*(long *)puVar6[2] + 0x28))();
          }
          puVar6[2] = plVar3;
          if (plVar3 == (long *)0x0) {
            if ((long *)puVar6[1] != (long *)0x0) {
              (**(code **)(*(long *)puVar6[1] + 0x28))();
            }
            puVar6[1] = 0;
            puVar4 = &DAT_fffffff007ff0828;
          }
          else {
            uVar7 = (**(code **)(*plVar3 + 0x78))(plVar3);
            puVar6[5] = uVar7;
            plVar3 = (long *)(**(code **)(*(long *)puVar6[1] + 0xe8))((long *)puVar6[1],1);
            if ((long *)puVar6[3] != (long *)0x0) {
              (**(code **)(*(long *)puVar6[3] + 0x28))();
            }
            puVar6[3] = plVar3;
            if (plVar3 != (long *)0x0) {
              uVar7 = (**(code **)(*plVar3 + 0x78))(plVar3);
              puVar6[4] = uVar7;
              *puVar6 = 0;
              uVar5 = *(ulong *)(param_1 + 0x30);
              puVar6[6] = uVar5;
              if (puVar9 == (undefined8 *)0x0) {
                *(undefined8 *)(param_1 + 0x20) = puVar6;
              }
              else {
                *puVar9 = puVar6;
              }
              goto LAB_fffffff0099642ec;
            }
            if ((long *)puVar6[2] != (long *)0x0) {
              (**(code **)(*(long *)puVar6[2] + 0x28))();
            }
            puVar6[2] = 0;
            if ((long *)puVar6[1] != (long *)0x0) {
              (**(code **)(*(long *)puVar6[1] + 0x28))();
            }
            puVar6[1] = 0;
            puVar4 = &DAT_fffffff007ff0868;
          }
        }
        thunk_EXT_FUN_80110000038fe270(puVar4,puVar6);
        uVar7 = 0;
      }
      goto LAB_fffffff009964404;
    }
    uVar5 = puVar6[6];
LAB_fffffff0099642ec:
    puVar9 = puVar6;
    param_2 = uVar8 - (int)uVar5;
  } while (uVar5 <= uVar8);
  *param_3 = puVar6[4] + *(long *)(param_1 + 0x28) * (ulong)uVar8;
  uVar7 = 1;
LAB_fffffff009964404:
  thunk_EXT_FUN_8011000003222de0(*(undefined8 *)(param_1 + 0x48));
  return uVar7;
}

