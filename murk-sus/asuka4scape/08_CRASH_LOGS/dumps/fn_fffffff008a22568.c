// FUN_fffffff008a22568 @ fffffff008a22568 size=1132
// CALLERS:
//   fffffff00afb919e no-fn
//   fffffff008a28740 no-fn
// CALLEES:
//   fffffff008a22078 FUN_fffffff008a22078
//   fffffff008a820d4 thunk_EXT_FUN_8011000003397c88
//   fffffff008a81ee4 thunk_EXT_FUN_8011000003398228
//   fffffff008a81ed4 thunk_EXT_FUN_80110000038db19c

undefined8 FUN_fffffff008a22568(long param_1,ulong param_2,ulong param_3)

{
  short sVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  ulong local_58;
  
  if ((DAT_fffffff00ae430b0 >> 2 & 1) != 0) {
    thunk_EXT_FUN_80110000038db19c
              (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
               "%s: %s: messageANEAddress: %p, messageSize: 0x%llx\n");
  }
  lVar3 = thunk_EXT_FUN_8011000003397c88();
  if ((param_3 != 0) && (param_2 < *(ulong *)(param_1 + 0x6d0))) {
    if ((7 < param_3) &&
       ((param_2 + param_3 <= *(ulong *)(param_1 + 0x6d0) && (!CARRY8(param_2,param_3))))) {
      lVar4 = *(long *)(*(long *)(param_1 + 0x6e0) + 0x38) + param_2;
      sVar1 = *(short *)(lVar4 + 4);
      if (sVar1 == 0x502) {
        if (param_3 < 0x20) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                     "[ERROR] %s: %s: Shared memory remap message too small: offset:0x%llx, size:0x%llx\n"
                    );
          return 0xe00002c2;
        }
        uVar5 = *(undefined8 *)(lVar4 + 0x10);
        uVar6 = *(undefined4 *)(lVar4 + 0x18);
        uVar7 = *(undefined4 *)(lVar4 + 8);
      }
      else if (sVar1 == 0x501) {
        if (param_3 < 0x10) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                     "[ERROR] %s: %s: Shared memory free message too small: offset:0x%llx, size:0x%llx\n"
                    );
          return 0xe00002c2;
        }
        uVar6 = 0;
        uVar7 = 0;
        uVar5 = *(undefined8 *)(lVar4 + 8);
      }
      else if (sVar1 == 0x500) {
        if (param_3 < 0x20) {
          thunk_EXT_FUN_80110000038db19c
                    (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
                     "[ERROR] %s: %s: Shared memory alloc message too small: offset:0x%llx, size:0x%llx\n"
                    );
          return 0xe00002c2;
        }
        uVar5 = 0;
        uVar6 = *(undefined4 *)(lVar4 + 8);
        uVar7 = *(undefined4 *)(lVar4 + 0xc);
      }
      else {
        uVar6 = 0;
        uVar7 = 0;
        uVar5 = 0;
      }
      uVar5 = FUN_fffffff008a22078(param_1,sVar1,uVar5,uVar6,uVar7,param_2,param_3);
      lVar4 = thunk_EXT_FUN_8011000003397c88();
      local_58 = 0;
      thunk_EXT_FUN_8011000003398228(lVar4 - lVar3,&local_58);
      uVar2 = local_58;
      if ((DAT_fffffff00ae430b0 >> 2 & 1) != 0) {
        thunk_EXT_FUN_80110000038db19c
                  (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                   "%s: %s: ANE SharedMallocRequest took %llu us\n");
      }
      if (uVar2 < 0x596832e8) {
        return uVar5;
      }
      thunk_EXT_FUN_80110000038db19c
                (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0,
                 "%s: %s: INFO: ANE SharedMallocRequest took %llu us for offset: %p, size: 0x%llx\n"
                );
      return uVar5;
    }
  }
  thunk_EXT_FUN_80110000038db19c
            (&MACH_HEADER,PTR_DAT_fffffff007ddeaa8,0x10,
             "[ERROR] %s: %s: Shared memory message too small for command header: offset:0x%llx, size:0x%llx\n"
            );
  return 0xe00002c2;
}

